#include "worldcontroller.h"
#include <QKeyEvent>

WorldController::WorldController(QString map)
    : QObject(),
      world(std::make_unique<World>()),
      height(0),
      width(0)
{
    // Initialize the world based on the provided map
    try
    {
        world->createWorld(map, /* Add appropriate parameters for nrOfEnemies, nrOfHealthpacks, pRatio */);
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Error creating world: " << e.what() << std::endl;
        // Handle the error as needed
    }
}