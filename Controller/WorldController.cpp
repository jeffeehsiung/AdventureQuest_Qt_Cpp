#include "Controller/WorldController.h"
#include <QKeyEvent>

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
    worlds.push_back(std::make_shared<WorldModel>(":/images/world_images/maze1.png", nrOfEnemies + 3, nrOfHealthpacks, pRatio, false));
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

const std::vector<std::unique_ptr<TileModel> > &WorldController::getTiles() const
{
    return currentWorld->getTiles();
}

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
    coordinate currentPosition = protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate - 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (cols -1)) && (newY <= (rows -1)) && (newY >= 0) ){
        // Move the protagonist up
        protagonists[0]->move(0, -1);
        if (isEnemy(protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        emit protagonistPositionChanged(0);
    }
}

void WorldController::onDownArrowPressed() {
    // Get the current position of the protagonist
    coordinate currentPosition = protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate;
    int newY = currentPosition.yCoordinate + 1;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX <= (cols -1)) && (newY <= (rows -1)) && (newY >= 0)){
        // Move the protagonist down
        protagonists[0]->move(0, 1); // Assuming the first protagonist in the vector
        if (isEnemy(protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        emit protagonistPositionChanged(0);
    }
}

void WorldController::onLeftArrowPressed() {
    // Get the current position of the protagonist
    coordinate currentPosition = protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate - 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (cols -1)) && (newY <= (rows -1))){
        // Move the protagonist left
        protagonists[0]->move(-1, 0); // Assuming the first protagonist in the vector
        if (isEnemy(protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        emit protagonistPositionChanged(0);
    }
}

void WorldController::onRightArrowPressed() {
    // Get the current position of the protagonist
    coordinate currentPosition = protagonists[0]->getPosition();
    // Calculate the new position
    int newX = currentPosition.xCoordinate + 1;
    int newY = currentPosition.yCoordinate;
    // Clamp the new position to ensure it's within the world boundaries
    if ((newX >= 0) && (newX <= (cols -1)) && (newY <= (rows -1))){
        // Move the protagonist right
        protagonists[0]->move(1, 0); // Assuming the first protagonist in the vector
        if (isEnemy(protagonists[0]->getPosition())) {
            onEncounterEnemy();
        }
        if (isHealthPack(protagonists[0]->getPosition())) {
            onEncounterHealthPack();
        }
        emit protagonistPositionChanged(0);
    }
}

void WorldController::onEncounterEnemy() {
    qDebug() << "Encountered an enemy!" << "\n";
    if (protagonists[0]->getHealth() > 0) {
        protagonists[0]->setHealth(protagonists[0]->getHealth() - 1);
    }
    else {
        protagonists[0]->setHealth(0);
        qDebug() << "You died!" << "\n";
    }
    qDebug() << "Health: " << protagonists[0]->getHealth() << "\n";
}

void WorldController::onEncounterHealthPack() {
    qDebug() << "Encountered a health pack!" << "\n";
    if (protagonists[0]->getHealth() < 5) {
        protagonists[0]->setHealth(protagonists[0]->getHealth() + 1);
    }
    else {
        qDebug() << "Health is full!" << "\n";
    }
    qDebug() << "Health: " << protagonists[0]->getHealth() << "\n";
}

void WorldController::playerReachedExit(){
    if(currentWorld->protagonists[0]->getPosition() == currentWorld->getExit()){
        currentWorld->protagonists[0]->setPosition(worlds[1]->getStart());
        worlds[1]->addProtagonist(worlds[0]->removeProtagonists());
        currentWorld = worlds[1];
        emit protagonistPositionChanged(0);
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
    return currentWorld->getExit();
}


//void WorldController::autoplay(){
//    Comparator<node> comparator = [](const node& a, const node& b) {
//        return (a.f) > (b.f);  // Assuming you want the node with the lowest 'f' value on top
//    };
//    qDebug() << "start Pos: " << currentWorld->getStart().getXPos() << " "<< currentWorld->getStart().getYPos();
//    qDebug() << "exit Pos: " << currentWorld->getExit().getXPos() << " "<< currentWorld->getExit().getYPos();
//    PathFinder<node,coordinate> pathFinder(currentWorld->nodes, currentWorld->getStart(), currentWorld->getExit(), comparator, this->getRows(), 1);

//    std::vector<int> result = pathFinder.A_star();
//    qDebug() << "Path to destination:";
//    for (int move : result) {
//        qDebug() << move;
//    }
//}








