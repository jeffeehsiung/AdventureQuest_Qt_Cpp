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
    // Move the protagonist up
    currentWorld->protagonists[0]->move(0, -1); // Assuming the first protagonist in the vector
    emit protagonistPositionChanged(0);
    playerReachedExit();
}

void WorldController::onDownArrowPressed() {
    // Move the protagonist down
    currentWorld->protagonists[0]->move(0, 1);
    emit protagonistPositionChanged(0);
    playerReachedExit();
}

void WorldController::onLeftArrowPressed() {
    // Move the protagonist left
    currentWorld->protagonists[0]->move(-1, 0);
    emit protagonistPositionChanged(0);
    playerReachedExit();
}

void WorldController::onRightArrowPressed() {
    // Move the protagonist right
    currentWorld->protagonists[0]->move(1, 0);
    emit protagonistPositionChanged(0);
    playerReachedExit();
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








