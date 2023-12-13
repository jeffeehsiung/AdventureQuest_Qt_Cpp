#include "Controller/WorldController.h"

WorldController::WorldController()
    : world(std::make_unique<World>()) {
    currentProtagonist = nullptr;
    currentEnemy = nullptr;
    currentPEnemy = nullptr;
    //currentXEnemy = nullptr;
    currentHealthpack = nullptr;
}
void WorldController::createWorld(QString map, int gameNumberOfPlayers, int gameDifficultyIdx, float pRatio) {

    /**
     * given gameDifficultyIdx assign the number of healthpacks
    */
    int nrOfHealthpacks = 0;
    int nrOfEnemies = 0;
    switch (gameDifficultyIdx)
    {
    case 1:
        nrOfHealthpacks = 5;
        nrOfEnemies = 8;
        break;
    case 2:
        nrOfHealthpacks = 3;
        nrOfEnemies = 15;
        break;
    case 3:
        nrOfHealthpacks = 1;
        nrOfEnemies = 30;
        break;
    default:
        break;
    }
    difficultyIdx = gameDifficultyIdx;

    /**
     * createworld
     * */
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
//        tiles.push_back(std::move(tileModel));
    }

    for ( auto &healthPack : world->getHealthPacks() ){
        std::unique_ptr<TileModel> healthPackModel = std::make_unique<TileModel>(std::move(healthPack));
        healthPacks.push_back(std::move(healthPackModel));
    }

    for (auto &enemy : world->getEnemies()) {
        // Check if the enemy is a PEnemy
        if (auto pEnemyRaw = dynamic_cast<PEnemy*>(enemy.get())) {
            // Create a PEnemyModel and add it to penemies
            std::unique_ptr<PEnemyModel> pEnemyModel = std::make_unique<PEnemyModel>(std::unique_ptr<PEnemy>(pEnemyRaw));
            penemies.push_back(std::move(pEnemyModel));
            enemy.release(); // Prevent double deletion
        } else {
            // If it's not a PEnemy, treat it as a regular enemy
            enemies.push_back(std::make_unique<EnemyModel>(std::move(enemy)));
        }
    }

    /**
     * first and invidivual protagonist player
     */
    std::unique_ptr<ProtagonistModel> protagonist = std::make_unique<ProtagonistModel>(world->getProtagonist());
    protagonists.push_back(std::move(protagonist));
}

/**
 * size of world
 */
int WorldController::getRows() const
{
    return rows;
}

int WorldController::getCols() const
{
    return cols;
}

/**
 * getter and setters
 * */

std::unique_ptr<TileModel>& WorldController::getTileModelAt(int x, int y) {
    coordinate coord{x, y};
    if (tileMap.find(coord) != tileMap.end()) {
        return tileMap[coord];
    } else {
        throw std::out_of_range("TileModel at the specified coordinates does not exist.");
    }
}

// New method to access the map of tiles
const std::map<coordinate, std::unique_ptr<TileModel>>& WorldController::getTileMap() const {
    return tileMap;
}

//const std::vector<std::unique_ptr<TileModel> > &WorldController::getTiles() const
//{
//    return tiles;
//}

const std::vector<std::unique_ptr<TileModel> > &WorldController::getHealthPacks() const
{
    return healthPacks;
}

const std::vector<std::unique_ptr<EnemyModel> > &WorldController::getEnemies() const
{
    return enemies;
}

const std::vector<std::unique_ptr<PEnemyModel> > &WorldController::getPEnemies() const
{
    return penemies;
}

// const std::vector<std::unique_ptr<XEnemyModel> > &WorldController::getXEnemies() const
// {
//     return xenemies;
// }

const std::vector<std::unique_ptr<ProtagonistModel> > &WorldController::getProtagonists() const
{
    return protagonists;
}

/**
 * type of tiles check
 */

bool WorldController::isHealthPack(coordinate coord)
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

//bool WorldController::isPoisonedTiles(coordinate coord)
//{
//    for ( auto &tile : tiles )
//    {
//        if ( tile->getPosition() == coord && tile->getState() == HURT)
//        {
//            // let's say HURT means tile is poisoned
//            return true;
//        }
//    }
//}

bool WorldController::isPoisonedTiles(coordinate coord)
{
    // Check if the coordinate exists in the map
    if (tileMap.find(coord) != tileMap.end()) {
        // Directly access the tile and check if it's poisoned
        return tileMap[coord]->isPoisoned();
    }
    return false;
}


/**
 * type of enemy check
 */

bool WorldController::isEnemy(coordinate coord)
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

bool WorldController::isPEnemy(coordinate coord)
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

// bool WorldController::isXEnemy(coordinate coord)
// {
//     for ( auto &xenemy : xenemies )
//     {
//         if ( xenemy->getPosition() == coord )
//         {
//             currentXEnemy = xenemy;
//             return true;
//         }
//     }
//     return false;
// }

int WorldController::getNumOfProtagonists() const
{
    /** return the size of protagonist vector */
    return protagonists.size();
}

int WorldController::getDifficultyIdx() const
{
    return difficultyIdx;
}

/**
 * PEnemy poisened tiles
 */
void WorldController::setAffectedTiles(coordinate coord, float poisonLevel) {
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

void WorldController::deleteEnemy(coordinate coord)
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

//void WorldController::deletePsnTile(coordinate coord)
//{
//    /**
//     * delete poisoned tile from vector
//     * */
//    for ( auto &tile : tiles )
//    {
//        if ( tile->getPosition() == coord )
//        {
//            tiles.erase(std::remove_if(tiles.begin(), tiles.end(), [&](std::unique_ptr<TileModel> &tile)
//            {
//                return tile->getPosition() == coord;
//            }), tiles.end());
//        }
//    }
//}

void WorldController::deletePsnTile(coordinate coord) {
    // Assuming tileMap is a std::map<coordinate, std::unique_ptr<TileModel>>
    auto it = tileMap.find(coord);
    if (it != tileMap.end()) {
        tileMap.erase(it);
    }
}


/**
 * healthpack functions
 */

void WorldController::removeHealthpack(coordinate coord)
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

void WorldController::onUpArrowPressed() {
    currentProtagonist = protagonists[0].get();
    // Get the current position of the protagonist
    coordinate currentPosition = currentProtagonist->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate - 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (cols -1)) && (newY <= (rows -1)) && (newY >= 0) ){
        // Move the protagonist up
        currentProtagonist->move(0, -1);
        if (isEnemy(currentProtagonist->getPosition())) {
            onEncounterEnemy();
        }
        else if (isHealthPack(currentProtagonist->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentProtagonist->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
}

void WorldController::onDownArrowPressed() {
    currentProtagonist = protagonists[0].get();
    // Get the current position of the protagonist
    coordinate currentPosition = currentProtagonist->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate + 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (cols -1)) && (newY <= (rows -1)) && (newY >= 0)){
        // Move the protagonist down
        currentProtagonist->move(0, 1); // Assuming the first protagonist in the vector
        if (isEnemy(currentProtagonist->getPosition())) {
            onEncounterEnemy();
        }
        else if (isHealthPack(currentProtagonist->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentProtagonist->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
}

void WorldController::onLeftArrowPressed() {
    currentProtagonist = protagonists[0].get();
    // Get the current position of the protagonist
    coordinate currentPosition = currentProtagonist->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate - 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (cols -1)) && (newY <= (rows -1))){
        // Move the protagonist left
        currentProtagonist->move(-1, 0); // Assuming the first protagonist in the vector
        if (isEnemy(currentProtagonist->getPosition())) {
            onEncounterEnemy();
        }
        else if (isHealthPack(currentProtagonist->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentProtagonist->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
}

void WorldController::onRightArrowPressed() {
    currentProtagonist = protagonists[0].get();
    // Get the current position of the protagonist
    coordinate currentPosition = currentProtagonist->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate + 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (cols -1)) && (newY <= (rows -1))){
        // Move the protagonist right
        currentProtagonist->move(1, 0); // Assuming the first protagonist in the vector
        if (isEnemy(currentProtagonist->getPosition())) {
            onEncounterEnemy();
        }
        else if (isHealthPack(currentProtagonist->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentProtagonist->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
}

void WorldController::onEncounterEnemy() {
    qDebug() << "Encountered an enemy!" << "\n";
    if (currentProtagonist->getHealth() > 0) {
        currentProtagonist->attack();
        currentEnemy->attack();
    }
    else {
        currentProtagonist->setHealth(0);
    }
    qDebug() << "Health: " << currentProtagonist->getHealth() << "\n";
}

void WorldController::onEncounterHealthPack() {
    qDebug() << "Encountered a health pack!" << "\n";
    if (currentProtagonist->getHealth() < 5) {
        currentProtagonist->setHealth(currentProtagonist->getHealth() + 1);
    }
    else {
        qDebug() << "Health is full!" << "\n";
    }
    qDebug() << "Health: " << currentProtagonist->getHealth() << "\n";
}

void WorldController::onEncounterPEnemy() {
    qDebug() << "Encountered an penemy!" << "\n";
    if (currentProtagonist->getHealth() > 0) {
        currentProtagonist->attack();
        currentPEnemy->attack();
        setAffectedTiles(currentPEnemy->getPosition(), currentPEnemy->getPoisonLevel());
    }
    else {
        currentProtagonist->setHealth(0);
    }
    qDebug() << "Health: " << currentProtagonist->getHealth() << "\n";
}

/**
 * start and exit position functions
 */

coordinate WorldController::getStart()
{
    return start;
}

coordinate WorldController::getExit()
{
    return exit;
}

/**
 * Path: walked path getter and setter
 * TODO: missing setter
 */

const std::vector<std::unique_ptr<TileModel> > &WorldController::getWalkedOnTiles() const
{
    return walkedOnTiles;
}








