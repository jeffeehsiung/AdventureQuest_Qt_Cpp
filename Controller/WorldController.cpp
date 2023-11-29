#include "WorldController.h"
#include <QKeyEvent>


WorldController::WorldController(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio)
    : world(std::make_unique<World>())
{
    world -> createWorld(map, nrOfEnemies, nrOfHealthpacks, pRatio);
    height = world->getRows() - 1;
    width = world->getCols() - 1;
    exit = coordinate(5,5);
    start = coordinate(0,0);

    // tiles = world -> getTiles();
    // healthPacks = world ->getHealthPacks();

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

    //only on first world
    auto protagonist = world ->getProtagonist();
    protagonists[0] = std::make_unique<ProtagonistModel>(protagonist.get());
}

int WorldController::getHeight() const
{
    return height;
}

int WorldController::getWidth() const
{
    return width;
}

void WorldController::addProtagonist(ProtagonistModel* model)
{
    if (model == nullptr)
    {
        std::cerr << "Error: Null protagonist model provided." << std::endl;
        return;
    }

    for (auto& protagonistModel : protagonists)
    {
        if (!protagonistModel)
        {
            protagonistModel = std::unique_ptr<ProtagonistModel>(model);
            return;
        }
    }
}

void WorldController::removeProtagonist(ProtagonistModel* model)
{
    if (model == nullptr)
    {
        std::cerr << "Error: Null protagonist model provided." << std::endl;
        return;
    }

    for (auto& protagonistModel : protagonists)
    {
        if (protagonistModel.get() == model)
        {
            protagonistModel.reset(); // Reset the unique_ptr to remove the model
            return;
        }
    }
    // If the model is not found, print an error
    std::cerr << "Error: Protagonist model not found in the array." << std::endl;
}

char WorldController::getActiveProtagonistAmount() const
{
    // Implement logic to get the number of active protagonists
    return 0;  // Replace with actual implementation
}

// Implement the rest of the member functions...

void WorldController::handleKeyPress(QKeyEvent* /*event*/)
{
    // Implement key press handling logic
}

void WorldController::resetWorld()
{
    // Implement world reset logic
}

void WorldController::handleGameOver()
{
    // Implement game over handling logic
}

void WorldController::handlePoisonLevelUpdated(float /*poisonLevel*/)
{
    // Implement poison level update handling logic
}

std::unique_ptr<ProtagonistModel> WorldController::getProtagonist(char id) const
{
    return std::unique_ptr<ProtagonistModel>();
}

std::unique_ptr<TileModel> WorldController::getTile(int x, int y)
{
    return std::unique_ptr<TileModel>();
}

std::unique_ptr<EnemyModel> WorldController::getEnemy(int x, int y)
{
    return std::unique_ptr<EnemyModel>();
}

std::unique_ptr<TileModel> WorldController::getHealthPack(int x, int y)
{
    return std::unique_ptr<TileModel>();
}


