#include "WorldModel.h"

// Constructor definition
WorldModel::WorldModel(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio) :{
    // Additional initialization code if needed
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
