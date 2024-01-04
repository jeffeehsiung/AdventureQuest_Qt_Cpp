#include "WorldModel.h"

// Constructor definition
WorldModel::WorldModel(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio, bool firstWorld) : world(std::make_unique<World>()){
    // Additional initialization code if needed
    world -> createWorld(map, nrOfEnemies, nrOfHealthpacks, pRatio);
    rows = world->getRows();
    cols = world->getCols();

    // for avoding placing xenemy on the used cell
    std::vector<bool> used;
    used.reserve(rows * cols);

    /**
     * create tilemodels, enemymodels, penemymodels, xenemymodels, and protagonistmodels based on created world
     * */
    for (auto &tile : world->getTiles()) {
        std::unique_ptr<TileModel> tileModel = std::make_unique<TileModel>(std::move(tile));
        tiles.push_back(std::move(tileModel));
    }

    for ( auto &healthPack : world->getHealthPacks() ){
        used[healthPack->getYPos() * cols + healthPack->getXPos()] = true;
        std::unique_ptr<TileModel> healthPackModel = std::make_unique<TileModel>(std::move(healthPack));
        healthPacks.push_back(std::move(healthPackModel));
    }

    for (auto &enemy : world->getEnemies()) {
        if (auto pEnemyRaw = dynamic_cast<PEnemy*>(enemy.get())) {
            used[pEnemyRaw->getYPos() * cols + pEnemyRaw->getXPos()] = true;
            penemies.push_back(std::make_unique<PEnemyModel>(std::unique_ptr<PEnemy>(pEnemyRaw)));
            enemy.release(); // Important to prevent double free
        } else {
            used[enemy->getYPos() * cols + enemy->getXPos()] = true;
            enemies.push_back(std::make_unique<EnemyModel>(std::move(enemy)));
        }
    }

    // Choose a random distribution for x, y and strength for Xenemy
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_x(8, cols - 8);
    std::uniform_int_distribution<int> uniform_y(8, rows - 8);
    std::uniform_int_distribution<int> uniform_perc(0, 100);
    float xRatio = pRatio * 0.8;
    int XEnemyCounter = 0;
    while (xenemies.size() < (nrOfEnemies * xRatio) || XEnemyCounter == 0) {
        int xPos = uniform_x(e1);
        int yPos = uniform_y(e1);
        if (xPos != 0 || yPos != 0) {
            if (used[yPos * cols + xPos] == false)
            {
                xenemies.push_back(std::make_unique<XEnemyModel>(xPos, yPos, uniform_perc(e1)));
                used[yPos * cols + xPos] = true;
                XEnemyCounter++;
            }
        }
    }

    if(firstWorld){
        std::unique_ptr<ProtagonistModel> protagonist = std::make_unique<ProtagonistModel>(world->getProtagonist());
        protagonists.push_back(std::move(protagonist));
    }

    currentProtagonist = nullptr;
    currentEnemy = nullptr;
    currentPEnemy = nullptr;
    currentXEnemy = nullptr;
    currentHealthpack = nullptr;
}

/**
 * size of world
 */
int WorldModel::getRows() const
{
    return rows;
}

int WorldModel::getCols() const
{
    return cols;
}

/**
 * getter and setters
 * */

//const std::map<coordinate, std::unique_ptr<TileModel>>& WorldModel::getTileMap() const {
//    return tileMap;
//}

const std::vector<std::unique_ptr<TileModel> >& WorldModel::getTiles() const
{
    return tiles;
}


const std::vector<std::unique_ptr<TileModel> > &WorldModel::getHealthPacks() const
{
    return healthPacks;
}

const std::vector<std::unique_ptr<EnemyModel> > &WorldModel::getEnemies() const
{
    return enemies;
}

const std::vector<std::unique_ptr<PEnemyModel> > &WorldModel::getPEnemies() const
{
    return penemies;
}

const std::vector<std::unique_ptr<XEnemyModel> > &WorldModel::getXEnemies() const
{
    return xenemies;
}

const std::vector<std::unique_ptr<ProtagonistModel> > &WorldModel::getProtagonists() const
{
    return protagonists;
}

/**
 * type of tiles check
 */


bool WorldModel::isHealthPack(coordinate coord)
{
    for ( auto &healthPack : healthPacks )
    {
        if ( healthPack->getPosition() == coord )
        {
            currentHealthpack = healthPack.get();
            return true;
        }
    }
    return false;
}

bool WorldModel::isAffectedTiles(coordinate coord)
{
    if(auto& tileModel = this->tiles.at(coord.getYPos()*this->getRows()+coord.getXPos())){
        bool affected = tileModel->isPoisoned() || tileModel->isThundered();
        bool active = !(tileModel->getState() == DYING);
        return (affected && active);
    }
    return false;
}

/**
 * type of enemy check
 */

bool WorldModel::isEnemy(coordinate coord)
{
    for ( auto &enemy : enemies )
    {
        if ( enemy->getPosition() == coord )
        {
            currentEnemy = enemy.get();
            return !currentEnemy->isDefeated();
        }
    }
    return false;
}

bool WorldModel::isPEnemy(coordinate coord)
{
    for ( auto &penemy : penemies )
    {
        if ( penemy->getPosition() == coord )
        {
            currentPEnemy = penemy.get();
            connect(currentPEnemy, &PEnemyModel::psnTilesUpdated, this, &WorldModel::setAffectedTiles);
            return !currentPEnemy->isDefeated();
        }
    }
    return false;
}

bool WorldModel::isXEnemy(coordinate coord)
{
//    qDebug()<< "protagonist pos: " << coord.xCoordinate << "," << coord.yCoordinate;
    for ( auto &xenemy : xenemies )
    {
//        qDebug()<< "xenemy orignal pos: " << xenemy->getXPos() << "," << xenemy->getYPos();
        if ( xenemy->getPosition() == coord )
        {
            currentXEnemy = xenemy.get();
//            qDebug()<< "currentXEnemy pos: " << currentXEnemy->getXPos() << "," << currentXEnemy->getYPos();
            qDebug()<< "currentXEnemey dead: "<< currentXEnemy->isDefeated();
            connect(currentXEnemy, &XEnemyModel::thunderLevelUpdated, this, &WorldModel::setAffectedTiles);
            return !currentXEnemy->isDefeated();
        }
    }
    return false;
}

int WorldModel::getNumOfProtagonists() const
{
    /** return the size of protagonist vector */
    return protagonists.size();
}

/**
 * PEnemy poisened tiles
 */


void WorldModel::setAffectedTiles(bool xenemyType, float value) {
    int maxVal = 32; // Maximum poison level
    int minRadius = 1; // Minimum radius at max poison level
    int maxRadius = 8; // Maximum radius at zero poison level
    int radius = (minRadius + (maxRadius - minRadius) * (1 - value / maxVal));

    qDebug() << "new radius: "<< radius;

    int radiusSquared = radius * radius;
    coordinate coord = {0,0};

    if(xenemyType){
        coord = currentXEnemy->getPosition();
    }else{
        coord = currentPEnemy->getPosition();
    }

    // Determine the range of x and y coordinates to iterate over
    int startX = std::max(0, coord.xCoordinate - radius);
    int endX = std::min(cols - 1, coord.xCoordinate + radius);
    int startY = std::max(0, coord.yCoordinate - radius);
    int endY = std::min(rows - 1, coord.yCoordinate + radius);

    for (int x = startX; x <= endX; ++x) {
        for (int y = startY; y <= endY; ++y) {
            int dx = x - coord.xCoordinate;
            int dy = y - coord.yCoordinate;

            if (dx * dx + dy * dy <= radiusSquared) {
                auto& tileModel = tiles.at(y*(this->getRows())+x);
                if (tileModel) {
                    tileModel->setAffectedType(xenemyType);
                    tileModel->takeDamage(value);
                }
            }
        }
    }
}



/**
 * defeated functions
 */

void WorldModel::deleteEnemy(coordinate coord)
{
    /**
     * delete enemy from vector
     * */
    for ( auto &enemy : enemies )
    {
        if ( enemy->getPosition() == coord )
        {
            enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [&](std::unique_ptr<EnemyModel> &enemy)
                                         {
                                             return enemy->getPosition() == coord;
                                         }), enemies.end());
        }
    }
}

void WorldModel::deletePsnTile(coordinate coord) {
    // Assuming tileMap is a std::map<coordinate, std::unique_ptr<TileModel>>
//    auto it = tileMap.find(coord);
//    if (it != tileMap.end()) {
//        tileMap.erase(it);
//    }
    if(auto& tileModel = this->tiles.at(coord.getYPos()*this->getRows()+coord.getXPos())){
        // Remove the element at the specified index
        // This is a bit tricky with a vector, as it doesn't support direct removal by index without shifting elements
        int index = coord.getYPos()*this->getRows()+coord.getXPos();
        this->tiles.erase(tiles.begin() + index);
        // After erasing, you might want to fill the gap if necessary
        // For example, you could insert a nullptr or a default tile at the end of the vector
        this->tiles.push_back(std::unique_ptr<TileModel>(nullptr)); // Or however you represent an empty tile
    }
}


/**
 * healthpack functions
 */

void WorldModel::removeHealthpack(coordinate coord)
{
    /**
     * remove healthpack from vector
     * */
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(0, 20); // Define the range for coordinates
    auto it = std::find_if(healthPacks.begin(), healthPacks.end(),
                           [&](const std::unique_ptr<TileModel>& healthPack) {
                               return healthPack->getPosition() == coord;});
    if (it != healthPacks.end()) {
        coordinate newCoord = {distr(eng), distr(eng)};
        (*it)->setPosition(newCoord);
    }
}

coordinate WorldModel::getStart() const
{
    return start;
}

coordinate WorldModel::getExit() const
{
    return exit;
}

const coordinate& WorldModel::getStartValue() const
{
    return start;
}

const coordinate& WorldModel::getExitValue() const
{
    return exit;
}

void WorldModel::addProtagonist(std::vector<std::unique_ptr<ProtagonistModel>> incoming){
    protagonists.reserve(protagonists.size() + incoming.size());
    std::move(incoming.begin(), incoming.end(), std::back_inserter(protagonists));
}

std::vector<std::unique_ptr<ProtagonistModel>> WorldModel::removeProtagonists(){
    return std::move(protagonists);
}

