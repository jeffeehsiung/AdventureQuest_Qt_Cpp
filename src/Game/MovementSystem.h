#ifndef AQ_GAME_MOVEMENT_SYSTEM_H
#define AQ_GAME_MOVEMENT_SYSTEM_H

#include "Core/Types.h"
#include "Game/GameWorld.h"
#include <vector>

namespace AQ {

// MovementSystem handles player movement, energy consumption,
// and pathfinding. Extracted from WorldController for clean separation.

class MovementSystem {
public:
    // Move player in a direction. Returns true if move succeeded.
    static bool movePlayer(GameWorld& world, Direction dir);

    // Move player to absolute position (for pathfinding results).
    static bool movePlayerTo(GameWorld& world, Vec2i target);

    // A* pathfinding from player to destination.
    // Returns list of direction moves (0-7 encoding: 7=NW, 0=N, 1=NE, etc.)
    static std::vector<int> findPath(GameWorld& world, Vec2i destination, float heuristicWeight);

    // Convert a path of direction codes into a sequence of Direction enums.
    // Each 8-way code may produce 1 or 2 cardinal moves.
    static std::vector<Direction> pathToDirections(const std::vector<int>& path);

private:
    // Consume energy for tile movement
    static void consumeMovementEnergy(GameWorld& world);
};

} // namespace AQ

#endif // AQ_GAME_MOVEMENT_SYSTEM_H
