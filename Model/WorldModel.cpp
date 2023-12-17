#include "WorldModel.h"

// Constructor definition
WorldModel::WorldModel(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio, bool firstWorld) : world(std::make_unique<World>()){
    // Additional initialization code if needed
    world -> createWorld(map, nrOfEnemies, nrOfHealthpacks, pRatio);
    rows = world->getRows();
    cols = world->getCols();

    /**
     * create tilemodels, enemymodels, penemymodels, xenemymodels, and protagonistmodels based on created world
     * */
    for (auto &tile : world->getTiles()) {
        std::unique_ptr<TileModel> tileModel = std::make_unique<TileModel>(std::move(tile));
        // After creating TileModel objects, add them to the map for direct access
        coordinate pos = tileModel->getPosition();
        tileMap[pos] = std::move(tileModel);
    }

    for ( auto &healthPack : world->getHealthPacks() ){
        std::unique_ptr<TileModel> healthPackModel = std::make_unique<TileModel>(std::move(healthPack));
        healthPacks.push_back(std::move(healthPackModel));
    }

    for (auto &enemy : world->getEnemies()) {
        if (auto pEnemyRaw = dynamic_cast<PEnemy*>(enemy.get())) {
            penemies.push_back(std::make_unique<PEnemyModel>(std::unique_ptr<PEnemy>(pEnemyRaw)));
            enemy.release(); // Important to prevent double free
        } else {
            enemies.push_back(std::make_unique<EnemyModel>(std::move(enemy)));
        }
    }

    if(firstWorld){
        std::unique_ptr<ProtagonistModel> protagonist = std::make_unique<ProtagonistModel>(world->getProtagonist());
        protagonists.push_back(std::move(protagonist));
    }

    currentProtagonist = nullptr;
    currentEnemy = nullptr;
    currentPEnemy = nullptr;
    //currentXEnemy = nullptr;
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

const std::map<coordinate, std::unique_ptr<TileModel>>& WorldModel::getTileMap() const {
    return tileMap;
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

// const std::vector<std::unique_ptr<XEnemyModel> > &WorldController::getXEnemies() const
// {
//     return xenemies;
// }

const std::vector<std::unique_ptr<ProtagonistModel> > &WorldModel::getProtagonists() const
{
    return protagonists;
}

/**
 * type of tiles check
 */

std::unique_ptr<TileModel>& WorldModel::getTileModelAt(int x, int y) {
    coordinate coord{x, y};
    if (tileMap.find(coord) != tileMap.end()) {
        return tileMap[coord];
    } else {
        throw std::out_of_range("TileModel at the specified coordinates does not exist.");
    }
}

bool WorldModel::isHealthPack(coordinate coord)
{
    for ( auto &healthPack : healthPacks )
    {
        if ( healthPack->getPosition() == coord )
        {
            return true;
        }
    }
    return false;
}

bool WorldModel::isPoisonedTiles(coordinate coord)
{
    if (tileMap.find(coord) != tileMap.end()) {
        // Directly access the tile and check if it's poisoned
        return tileMap[coord]->isPoisoned();
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
            return true;
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
            return true;
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

void WorldModel::setAffectedTiles(coordinate coord, float poisonLevel) {
    // Determine the range of the poison effect based on the poison level
    int range = static_cast<int>(poisonLevel) / 15; // or any other formula you see fit

    // Apply poison to tiles within the range
    for (int dx = -range; dx <= range; ++dx) {
        for (int dy = -range; dy <= range; ++dy) {
            int affectedX = coord.xCoordinate + dx;
            int affectedY = coord.yCoordinate + dy;

            // Check if the tile is within the world boundaries
            if (affectedX >= 0 && affectedX < cols && affectedY >= 0 && affectedY < rows) {
                // Here you need to get the actual TileModel and update its poisoned state
                auto& tileModel = getTileModelAt(affectedX, affectedY);
                if (tileModel) {
                    tileModel->takeDamage(poisonLevel - (std::abs(dx) + std::abs(dy))); // Decrease strength with distance
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
    auto it = tileMap.find(coord);
    if (it != tileMap.end()) {
        tileMap.erase(it);
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
    for ( auto &healthPack : healthPacks )
    {
        if ( healthPack->getPosition() == coord )
        {
            healthPacks.erase(std::remove_if(healthPacks.begin(), healthPacks.end(), [&](std::unique_ptr<TileModel> &healthPack)
            {
                return healthPack->getPosition() == coord;
            }), healthPacks.end());
        }
    }
}

coordinate WorldModel::getStart()
{
    return start;
}

coordinate WorldModel::getExit()
{
    return exit;
}

coordinate* WorldModel::getStartValue()
{
    return &start;
}

coordinate* WorldModel::getExitValue()
{
    return &exit;
}

void WorldModel::addProtagonist(std::vector<std::unique_ptr<ProtagonistModel>> incoming){
    protagonists.reserve(protagonists.size() + incoming.size());
    std::move(incoming.begin(), incoming.end(), std::back_inserter(protagonists));
}

std::vector<std::unique_ptr<ProtagonistModel>> WorldModel::removeProtagonists(){
    return std::move(protagonists);
}

