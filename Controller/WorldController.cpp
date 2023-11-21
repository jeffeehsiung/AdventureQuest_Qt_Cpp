#include "worldcontroller.h"
#include <QKeyEvent>


WorldController::WorldController(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio)
    : world(std::make_unique<World>(map, nrOfEnemies, nrOfHealthpacks, pRatio)),
      height(world->getRows()),
      width(world->getCols()),
      exit(world->getExit()),
      start(world->getStart())
{
    // Initialize other member variables if needed
}

int WorldController::getHeight() const
{
    return height;
}

int WorldController::getWidth() const
{
    return width;
}

std::unique_ptr<Protagonist> WorldController::getProt(char id) const
{
    // Implement logic to get a protagonist by ID
    return nullptr;  // Replace with actual implementation
}

void WorldController::addProtagonist(ProtagonistModel* /*model*/)
{
    // Implement logic to add a protagonist
}

void WorldController::removeProtagonist(ProtagonistModel* /*model*/)
{
    // Implement logic to remove a protagonist
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
