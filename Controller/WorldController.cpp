#include "Controller/WorldController.h"
#include <QKeyEvent>

WorldController::WorldController()
    : world(std::make_unique<World>()) {
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
        tiles.push_back(std::move(tileModel));
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

const std::vector<std::unique_ptr<TileModel> > &WorldController::getTiles() const
{
    return tiles;
}

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

bool WorldController::isPoisonedTiles(coordinate coord)
{
    for ( auto &tile : tiles )
    {
        if ( tile->getPosition() == coord )
        {
            return true;
        }
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

void WorldController::setAffectedTiles(coordinate coord, int spread, std::unique_ptr<PEnemyModel> pEnemy)
{
    /**
     * set the affected tiles of the penemy
     * */
    for ( auto &tile : tiles )
    {
        if ( tile->getPosition() == coord )
        {
            // tile->setPoisoned(true); /** TODO: implement */
            tile->setValue(pEnemy->getPoisonLevel());
            // tile->setPoisonSpread(spread); /** TODO: implement */
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

void WorldController::deletePsnTile(coordinate coord)
{
    /**
     * delete poisoned tile from vector
     * */
    for ( auto &tile : tiles )
    {
        if ( tile->getPosition() == coord )
        {
            tiles.erase(std::remove_if(tiles.begin(), tiles.end(), [&](std::unique_ptr<TileModel> &tile)
            {
                return tile->getPosition() == coord;
            }), tiles.end());
        }
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
    // Move the protagonist up
    protagonists[0]->move(0, -1);
    if (isEnemy(protagonists[0]->getPosition())) {
        onEncounterEnemy();
    }
    emit protagonistPositionChanged(0);
}

void WorldController::onDownArrowPressed() {
    // Move the protagonist down
    protagonists[0]->move(0, 1);
    if (isEnemy(protagonists[0]->getPosition())) {
        onEncounterEnemy();
    }
    emit protagonistPositionChanged(0);
}

void WorldController::onLeftArrowPressed() {
    // Move the protagonist left
    protagonists[0]->move(-1, 0);
    if (isEnemy(protagonists[0]->getPosition())) {
        onEncounterEnemy();
    }
    emit protagonistPositionChanged(0);
}

void WorldController::onRightArrowPressed() {
    // Move the protagonist right
    protagonists[0]->move(1, 0);
    if (isEnemy(protagonists[0]->getPosition())) {
        onEncounterEnemy();
    }
    emit protagonistPositionChanged(0);
}

void WorldController::onEncounterEnemy() {
    qDebug() << "Encountered an enemy!" << "\n";
    protagonists[0]->setHealth(protagonists[0]->getHealth() - 1);
    qDebug() << "Health: " << protagonists[0]->getHealth() << "\n";
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








