#include "Game/MovementSystem.h"
#include "Core/Event.h"
#include <queue>
#include <functional>
#include <cmath>
#include <limits>
#include <algorithm>

namespace AQ {

bool MovementSystem::movePlayer(GameWorld& world, Direction dir) {
    auto& player = world.player();
    Vec2i delta = directionDelta(dir);
    Vec2i newPos = player.pos + delta;

    if (!world.inBounds(newPos)) return false;

    Vec2i oldPos = player.pos;
    player.pos = newPos;
    player.animState = EntityState::Moving;

    consumeMovementEnergy(world);

    EventBus::instance().publish(EntityMovedEvent{player.id, oldPos, newPos});
    return true;
}

bool MovementSystem::movePlayerTo(GameWorld& world, Vec2i target) {
    if (!world.inBounds(target)) return false;

    auto& player = world.player();
    Vec2i oldPos = player.pos;
    player.pos = target;
    player.animState = EntityState::Moving;

    EventBus::instance().publish(EntityMovedEvent{player.id, oldPos, target});
    return true;
}

void MovementSystem::consumeMovementEnergy(GameWorld& world) {
    auto& player = world.player();
    float tileVal = world.tileValue(player.pos);
    if (tileVal != std::numeric_limits<float>::infinity()) {
        player.energy -= (1.0f - tileVal);
        if (player.energy < 0) player.energy = 0;
    }
    EventBus::instance().publish(HealthChangedEvent{player.health, player.energy});
}

std::vector<int> MovementSystem::findPath(GameWorld& world, Vec2i destination, float heuristicWeight) {
    auto& nodes = world.pathNodes();
    int width = world.cols();
    int height = world.rows();

    // Reset nodes
    for (auto& n : nodes) {
        n.f = 0;
        n.g = 0;
        n.h = 0;
        n.visited = false;
        n.prev = nullptr;
    }

    Vec2i start = world.player().pos;

    using NodeRef = std::reference_wrapper<PathNode>;
    auto comparator = [](const NodeRef& a, const NodeRef& b) {
        return a.get().h > b.get().h;
    };
    std::priority_queue<NodeRef, std::vector<NodeRef>, decltype(comparator)> openList(comparator);

    int startIdx = start.toIndex(width);
    PathNode* parent = &nodes[startIdx];
    parent->visited = true;

    PathNode current = nodes[startIdx];

    while (current.pos != destination) {
        int cx = current.pos.x;
        int cy = current.pos.y;

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dx == 0 && dy == 0) continue;
                int nx = cx + dx;
                int ny = cy + dy;
                if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;

                int nIdx = ny * width + nx;
                PathNode& nextNode = nodes[nIdx];

                if (nextNode.value == std::numeric_limits<float>::infinity()) continue;

                int manhDist = std::abs(destination.x - nx) + std::abs(destination.y - ny);
                float moveCost = std::fabs(nodes[cy * width + cx].value - nextNode.value) + 0.01f;

                float newF = parent->f + moveCost;
                float newH = newF + heuristicWeight * manhDist;

                if (!nextNode.visited) {
                    nextNode.f = newF;
                    nextNode.h = newH;
                    nextNode.prev = parent;
                    nextNode.visited = true;
                    openList.push(std::ref(nextNode));
                } else if (newH < nextNode.h - 0.1f) {
                    nextNode.f = newF;
                    nextNode.h = newH;
                    nextNode.prev = parent;
                    openList.push(std::ref(nextNode));
                }
            }
        }

        if (openList.empty()) return {};

        current = openList.top().get();
        parent = &nodes[current.pos.toIndex(width)];
        openList.pop();
    }

    // Trace back path
    std::vector<int> path;
    PathNode* dest = parent;
    while (dest->prev != nullptr) {
        int deltaX = dest->prev->pos.x - dest->pos.x;
        int deltaY = dest->prev->pos.y - dest->pos.y;
        int encoded = deltaX + 10 * deltaY;
        switch (encoded) {
            case -10: path.push_back(4); break;  // S
            case -9:  path.push_back(5); break;  // SW
            case  1:  path.push_back(6); break;  // W
            case  11: path.push_back(7); break;  // NW
            case  10: path.push_back(0); break;  // N
            case  9:  path.push_back(1); break;  // NE
            case -1:  path.push_back(2); break;  // E
            case -11: path.push_back(3); break;  // SE
            default: break;
        }
        dest = dest->prev;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Direction> MovementSystem::pathToDirections(const std::vector<int>& path) {
    std::vector<Direction> dirs;
    dirs.reserve(path.size() * 2);

    for (int move : path) {
        switch (move) {
            case 0: dirs.push_back(Direction::Up); break;
            case 1: dirs.push_back(Direction::Right); dirs.push_back(Direction::Up); break;
            case 2: dirs.push_back(Direction::Right); break;
            case 3: dirs.push_back(Direction::Right); dirs.push_back(Direction::Down); break;
            case 4: dirs.push_back(Direction::Down); break;
            case 5: dirs.push_back(Direction::Down); dirs.push_back(Direction::Left); break;
            case 6: dirs.push_back(Direction::Left); break;
            case 7: dirs.push_back(Direction::Left); dirs.push_back(Direction::Up); break;
            default: break;
        }
    }
    return dirs;
}

} // namespace AQ
