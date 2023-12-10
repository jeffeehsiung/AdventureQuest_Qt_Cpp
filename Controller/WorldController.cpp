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
    currentWorld = std::make_shared<WorldModel>(map, nrOfEnemies, nrOfHealthpacks, pRatio);
    worlds.push_back(currentWorld);

//    /**
//     * createworld
//     * */
//    world -> createWorld(map, nrOfEnemies, nrOfHealthpacks, pRatio);
//    rows = world->getRows();
//    cols = world->getCols();

//    /**
//     * create tilemodels, enemymodels, penemymodels, xenemymodels, and protagonistmodels based on created world
//     * */
//    for (auto &tile : world->getTiles()) {
//        std::unique_ptr<coordinate> pos = std::make_unique<coordinate>(tile->getXPos(), tile->getYPos());
//        nodes.push_back(node(tile->getValue(), *pos));
//        //qDebug() << "coordinate: " << pos->getXPos() << "\n";
//        std::unique_ptr<TileModel> tileModel = std::make_unique<TileModel>(std::move(tile));
//        tiles.push_back(std::move(tileModel));
//    }


//    for ( auto &healthPack : world->getHealthPacks() ){
//        std::unique_ptr<TileModel> healthPackModel = std::make_unique<TileModel>(std::move(healthPack));
//        healthPacks.push_back(std::move(healthPackModel));
//    }

//    for (auto &enemy : world->getEnemies()) {
//        if (auto pEnemyRaw = dynamic_cast<PEnemy*>(enemy.get())) {
//            penemies.push_back(std::make_unique<PEnemyModel>(std::unique_ptr<PEnemy>(pEnemyRaw)));
//            enemy.release(); // Important to prevent double free
//        } else {
//            enemies.push_back(std::make_unique<EnemyModel>(std::move(enemy)));
//        }
//    }

//    /**
//     * first and invidivual protagonist player
//     */
//    std::unique_ptr<ProtagonistModel> protagonist = std::make_unique<ProtagonistModel>(world->getProtagonist());
//    protagonists.push_back(std::move(protagonist));
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
// {
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
}

void WorldController::onDownArrowPressed() {
    // Move the protagonist down
    currentWorld->protagonists[0]->move(0, 1);
    emit protagonistPositionChanged(0);
}

void WorldController::onLeftArrowPressed() {
    // Move the protagonist left
    currentWorld->protagonists[0]->move(-1, 0);
    emit protagonistPositionChanged(0);
}

void WorldController::onRightArrowPressed() {
    // Move the protagonist right
    currentWorld->protagonists[0]->move(1, 0);
    emit protagonistPositionChanged(0);
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
//    qDebug() << "start Pos: " << start.getXPos() << " "<< start.getYPos();
//    qDebug() << "exit Pos: " << exit.getXPos() << " "<< exit.getYPos();
//    PathFinder<node,coordinate> pathFinder(nodes, &start, &exit, comparator, this->getRows(), 1);

//    std::vector<int> result = pathFinder.A_star();
//    qDebug() << "Path to destination:";
//    for (int move : result) {
//        qDebug() << move;
//    }
//}








