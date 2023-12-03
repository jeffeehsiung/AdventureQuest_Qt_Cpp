#include "Controller/WorldController.h"
#include <QKeyEvent>


WorldController::WorldController(QString map, int nrOfEnemies, int gameDifficultyIdx, float pRatio)
    : world(std::make_unique<World>())
{
    /**
     * given gameDifficultyIdx assign the number of healthpacks
    */
    int nrOfHealthpacks = 0;
    switch (gameDifficultyIdx)
    {
    case 1:
        nrOfHealthpacks = 5;
        break;
    case 2:
        nrOfHealthpacks = 3;
        break;
    case 3:
        nrOfHealthpacks = 1;
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
    for ( auto &tile : world->getTiles() )
    {
        std::unique_ptr<TileModel> tileModel = std::make_unique<TileModel>(tile.get());
        tiles.push_back(tileModel);
    }

    for ( auto &healthPack : world->getHealthPacks() )
    {
        std::unique_ptr<TileModel> healthPackModel = std::make_unique<TileModel>(healthPack.get());
        healthPacks.push_back(healthPackModel);
    }

    for ( auto &enemy : world->getEnemies() )
    {
        std::unique_ptr<EnemyModel> enemyModel = std::make_unique<EnemyModel>(enemy.get());
        enemies.push_back(enemyModel);
    }

    for ( auto &penemy : world->getPEnemies() )
    {
        std::unique_ptr<EnemyModel> penemyModel = std::make_unique<PEnemyModel>(penemy.get());
        penemies.push_back(penemyModel);
    }

    for ( auto &xenemy : world->getXEnemies() )
    {
        std::unique_ptr<EnemyModel> xenemyModel = std::make_unique<XEnemyModel>(xenemy.get());
        penemies.push_back(xenemyModel);
    }

    /**
     * first and invidivual protagonist player
     */
    for ( auto &protagonist : world->getProtagonist() )
    {
        std::unique_ptr<EnemyModel> protagonist = std::make_unique<ProtagonistModel>(protagonist.get());
        protagonists.push_back(protagonist);
    }
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

const std::vector<std::unique_ptr<XEnemyModel> > &WorldController::getXEnemies() const
{
    return xenemies;
}

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

bool WorldController::isXEnemy(coordinate coord)
{
    for ( auto &xenemy : xenemies )
    {
        if ( xenemy->getPosition() == coord )
        {
            return true;
        }
    }
    return false;
}

int WorldController::getNumOfProtagonists() const
{
    /** return the size of protagonist vector */
    return protagonists.size();
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
            tile->setPoisonLevel(pEnemy->getPoisonLevel());
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







