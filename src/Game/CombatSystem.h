#ifndef AQ_GAME_COMBAT_SYSTEM_H
#define AQ_GAME_COMBAT_SYSTEM_H

#include "Core/Types.h"
#include "Core/Event.h"
#include "Game/GameWorld.h"

namespace AQ {

// CombatSystem handles all combat logic extracted from WorldController.
// Stateless system operating on GameWorld data.
// Publishes events for the renderer/UI to react to.

class CombatSystem {
public:
    // Process encounters at the player's current position
    static void handleEncounters(GameWorld& world);

    // Individual encounter handlers
    static void encounterEnemy(GameWorld& world, EnemyData& enemy);
    static void encounterPoisonEnemy(GameWorld& world, EnemyData& enemy);
    static void encounterThunderEnemy(GameWorld& world, EnemyData& enemy);
    static void encounterHealthPack(GameWorld& world, HealthPackData& hp);
    static void encounterAffectedTile(GameWorld& world, Vec2i pos);

    // Apply energy rewards after defeating enemies
    static void applyEnemyDefeatReward(GameWorld& world, EnemyType type);

    // Check player death
    static bool isPlayerDead(const GameWorld& world);
};

} // namespace AQ

#endif // AQ_GAME_COMBAT_SYSTEM_H
