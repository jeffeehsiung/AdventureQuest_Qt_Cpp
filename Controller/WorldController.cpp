#include "worldcontroller.h"
#include <QKeyEvent>


WorldController::WorldController(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio)
    : world(std::make_unique<World>())
{
    world -> createWorld(map, nrOfEnemies, nrOfHealthpacks, pRatio);
    height = world->getRows() - 1;
    width = world->getCols() - 1;
    exit = coordinate(5,5);
    start = coordinate(0,0);
}

int WorldController::getHeight() const
{
    return height;
}

int WorldController::getWidth() const
{
    return width;
}

std::unique_ptr<Protagonist> WorldController::getProtagonist(char id) const
{
    // Implement logic to get a protagonist by ID
    return nullptr;  // Replace with actual implementation
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
