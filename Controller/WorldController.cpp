#include "Controller/WorldController.h"

WorldController::WorldController(){
    // Basic initializations, if any
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
    worlds.push_back(std::make_shared<WorldModel>(map, nrOfEnemies, nrOfHealthpacks, pRatio, true));
    worlds.push_back(std::make_shared<WorldModel>(map, nrOfEnemies + 3, nrOfHealthpacks, pRatio, false));
    currentWorld = worlds[0];
}

/**
 * size of world
 */
int WorldController::getRows() const
{
    return currentWorld->getRows();
}

int WorldController::getCols() const
{
    return currentWorld->getCols();
}

/**
 * getter and setters
 * */

// New method to access the map of tiles
const std::map<coordinate, std::unique_ptr<TileModel>>& WorldController::getTileMap() const {
    return currentWorld->getTileMap();
}

//const std::vector<std::unique_ptr<TileModel> > &WorldController::getTiles() const
//{
//    return tiles;
//}

const std::vector<std::unique_ptr<TileModel> > &WorldController::getHealthPacks() const
{
    return currentWorld->getHealthPacks();
}

const std::vector<std::unique_ptr<EnemyModel> > &WorldController::getEnemies() const
{
    return currentWorld->getEnemies();
}

const std::vector<std::unique_ptr<PEnemyModel> > &WorldController::getPEnemies() const
{
    return currentWorld->getPEnemies();
}

// const std::vector<std::unique_ptr<XEnemyModel> > &WorldController::getXEnemies() const
// {3
//     return xenemies;
// }

const std::vector<std::unique_ptr<ProtagonistModel> > &WorldController::getProtagonists() const
{
    return currentWorld->getProtagonists();
}

/**
 * type of tiles check
 */

bool WorldController::isHealthPack(coordinate coord)
{
    return currentWorld->isHealthPack(coord);
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
    return currentWorld->isPoisonedTiles(coord);
}


/**
 * type of enemy check
 */

bool WorldController::isEnemy(coordinate coord)
{
    return currentWorld->isEnemy(coord);
}

bool WorldController::isPEnemy(coordinate coord)
{
    return currentWorld->isPEnemy(coord);
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
    return currentWorld->protagonists.size();
}

int WorldController::getDifficultyIdx() const
{
    return difficultyIdx;
}

/**
 * PEnemy poisened tiles
 */
void WorldController::setAffectedTiles(coordinate coord, float poisonLevel) {
    currentWorld->setAffectedTiles(coord, poisonLevel);
}


/**
 * defeated functions
 */

void WorldController::deleteEnemy(coordinate coord)
{
    currentWorld->deleteEnemy(coord);
}

void WorldController::deletePsnTile(coordinate coord)
{
    currentWorld->deletePsnTile(coord);
}



void WorldController::onUpArrowPressed() {

    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate - 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1)) && (newY >= 0) ){
        // Move the protagonist up
        currentWorld->protagonists[0]->move(0, -1);
        if (isEnemy(currentWorld->protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(currentWorld->protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentWorld->protagonists[0]->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
    playerReachedExit();
}

void WorldController::onDownArrowPressed() {

    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate + 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1)) && (newY >= 0)){
        // Move the protagonist down
        currentWorld->protagonists[0]->move(0, 1); // Assuming the first protagonist in the vector
        if (isEnemy(currentWorld->protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(currentWorld->protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentWorld->protagonists[0]->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
    playerReachedExit();
}

void WorldController::onLeftArrowPressed() {
    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate - 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1))){
        // Move the protagonist left
        currentWorld->protagonists[0]->move(-1, 0); // Assuming the first protagonist in the vector
        if (isEnemy(currentWorld->protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(currentWorld->protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentWorld->protagonists[0]->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
    playerReachedExit();
}

void WorldController::onRightArrowPressed() {
    // Get the current position of the protagonist
    coordinate currentPosition = currentWorld->protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate + 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (currentWorld->getCols() -1)) && (newY <= (currentWorld->getRows() -1))){
        // Move the protagonist right
        currentWorld->protagonists[0]->move(1, 0); // Assuming the first protagonist in the vector
        if (isEnemy(currentWorld->protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(currentWorld->protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        else if (isPEnemy(currentWorld->protagonists[0]->getPosition())){
            onEncounterPEnemy();
        }
        emit updateprotagonistPosition(0);
    }
    playerReachedExit();
}

void WorldController::onEncounterEnemy() {
    qDebug() << "Encountered an enemy!" << "\n";
    if (currentWorld->protagonists[0]->getHealth() > 0) {
        currentWorld->protagonists[0]->setHealth(currentWorld->protagonists[0]->getHealth() - 1);
    }
    else {
        currentWorld->protagonists[0]->setHealth(0);
        qDebug() << "You died!" << "\n";
    }
    qDebug() << "Health: " << currentWorld->protagonists[0]->getHealth() << "\n";
}

void WorldController::onEncounterHealthPack() {
    qDebug() << "Encountered a health pack!" << "\n";
    if (currentWorld->protagonists[0]->getHealth() < 5) {
        currentWorld->protagonists[0]->setHealth(currentWorld->protagonists[0]->getHealth() + 1);
    }
    else {
        qDebug() << "Health is full!" << "\n";
    }
    qDebug() << "Health: " << currentWorld->protagonists[0]->getHealth() << "\n";
}

void WorldController::onEncounterPEnemy() {
    qDebug() << "Encountered an penemy!" << "\n";
    if (currentWorld->protagonists[0]->getHealth() > 0) {
        currentWorld->protagonists[0]->attack();
        currentWorld->currentPEnemy->attack();
        currentWorld->setAffectedTiles(currentWorld->currentPEnemy->getPosition(), currentWorld->currentPEnemy->getPoisonLevel());
    }
    else {
        currentWorld->protagonists[0]->setHealth(0);
    }
    qDebug() << "Health: " << currentWorld->protagonists[0]->getHealth() << "\n";
}


void WorldController::playerReachedExit(){
    qDebug() << "Current Pos x: " << currentWorld->protagonists[0]->getPosition().getXPos() << " y: " << currentWorld->protagonists[0]->getPosition().getYPos();
    qDebug() << "Exit: " << currentWorld->getExit().getXPos() << " y: " << currentWorld->getExit().getYPos();
    if(currentWorld->protagonists[0]->getPosition() == currentWorld->getExit()){
        currentWorld->protagonists[0]->setPosition(worlds[1]->getStart());
        worlds[1]->addProtagonist(worlds[0]->removeProtagonists());
        currentWorld = worlds[1];
        emit updateLevel();
        emit updateprotagonistPosition(0);
        qDebug() << "LevelSwitched!" << "\n";
    }
}
/**
 * start and exit position functions
 */

coordinate WorldController::getStart()
{
    return currentWorld->getStart();
}

coordinate WorldController::getExit()
{
    return currentWorld->getStart();
}

std::vector<std::shared_ptr<WorldModel>> WorldController::getWorlds(){
    return worlds;
}

std::shared_ptr<WorldModel> WorldController::getCurrentWorld(){
    return currentWorld;
}



// void WorldController::autoplay(){
//    Comparator<node> comparator = [](const node& a, const node& b) {
//         return (a.f) < (b.f);  // Assuming you want the node with the lowest 'f' value on top
//    };
//    qDebug() << "start Pos: " << currentWorld->getStart().getXPos() << " "<< currentWorld->getStart().getYPos();
//    qDebug() << "exit Pos: " << currentWorld->getExit().getXPos() << " "<< currentWorld->getExit().getYPos();
//    PathFinder<node,coordinate> pathFinder(currentWorld->nodes, currentWorld->getStartValue(), currentWorld->getExitValue(), comparator, this->getRows(), 0);

//    std::vector<int> result = pathFinder.A_star();
//    qDebug() << "Path to destination:";
//    for (int move : result) {
//        qDebug() << move;
//    }
// }








