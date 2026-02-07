#include "Game/CombatSystem.h"
#include <random>
#include <QDebug>

namespace AQ {

void CombatSystem::handleEncounters(GameWorld& world) {
    Vec2i pos = world.player().pos;

    // Check enemies
    if (auto* enemy = world.enemyAt(pos)) {
        switch (enemy->type) {
            case EnemyType::Regular: encounterEnemy(world, *enemy); break;
            case EnemyType::Poison:  encounterPoisonEnemy(world, *enemy); break;
            case EnemyType::Thunder: encounterThunderEnemy(world, *enemy); break;
        }
        return;
    }

    // Check health packs
    if (auto* hp = world.healthPackAt(pos)) {
        encounterHealthPack(world, *hp);
        return;
    }

    // Check affected tiles
    int idx = pos.toIndex(world.cols());
    if (idx >= 0 && idx < static_cast<int>(world.tiles().size())) {
        auto& tile = world.tiles()[idx];
        bool affected = tile.poisoned || tile.thundered;
        bool active = tile.animState != EntityState::Dying;
        if (affected && active) {
            encounterAffectedTile(world, pos);
        }
    }
}

void CombatSystem::encounterEnemy(GameWorld& world, EnemyData& enemy) {
    auto& player = world.player();
    if (player.health <= 0) return;

    player.animState = EntityState::Attacking;
    enemy.animState = EntityState::Attacking;

    // Player attacks enemy
    enemy.strength -= Constants::EnemyDamage;
    if (enemy.strength <= 0.0f) {
        enemy.strength = 0.0f;
        enemy.defeated = true;
        enemy.animState = EntityState::Dying;
        applyEnemyDefeatReward(world, EnemyType::Regular);

        EventBus::instance().publish(EntityDiedEvent{enemy.id, EnemyType::Regular});
    }

    // Enemy attacks player
    player.animState = EntityState::Hurt;
    player.health -= static_cast<int>(Constants::PlayerAttack);
    if (player.health <= 0) {
        player.health = 0;
        player.animState = EntityState::Dying;
    }

    EventBus::instance().publish(HealthChangedEvent{player.health, player.energy});
}

void CombatSystem::encounterPoisonEnemy(GameWorld& world, EnemyData& enemy) {
    auto& player = world.player();
    if (player.health <= 0) return;

    player.animState = EntityState::Attacking;
    enemy.animState = EntityState::Attacking;

    // Poison enemy emits poison
    world.applyAffectedArea(enemy.pos, false, enemy.specialLevel);

    enemy.specialLevel -= 10.0f;
    if (enemy.specialLevel <= 0.0f) {
        enemy.specialLevel = 0.0f;
        enemy.defeated = true;
        enemy.animState = EntityState::Dying;
        applyEnemyDefeatReward(world, EnemyType::Poison);

        EventBus::instance().publish(EntityDiedEvent{enemy.id, EnemyType::Poison});
    }

    EventBus::instance().publish(HealthChangedEvent{player.health, player.energy});
}

void CombatSystem::encounterThunderEnemy(GameWorld& world, EnemyData& enemy) {
    auto& player = world.player();
    if (player.health <= 0) return;

    player.animState = EntityState::Attacking;
    enemy.animState = EntityState::Attacking;

    // Player damages thunder enemy
    enemy.specialLevel -= Constants::ThunderDamage;

    // Thunder enemy teleports
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(-5, 5);
    int nx = std::clamp(enemy.pos.x + dist(rng), 0, world.cols() - 1);
    int ny = std::clamp(enemy.pos.y + dist(rng), 0, world.rows() - 1);
    enemy.pos = {nx, ny};

    // Thunder emits area effect
    world.applyAffectedArea(enemy.pos, true, enemy.specialLevel);

    if (enemy.specialLevel <= 0.0f) {
        enemy.specialLevel = 0.0f;
        enemy.defeated = true;
        enemy.animState = EntityState::Dying;
        applyEnemyDefeatReward(world, EnemyType::Thunder);

        EventBus::instance().publish(EntityDiedEvent{enemy.id, EnemyType::Thunder});
    }

    EventBus::instance().publish(HealthChangedEvent{player.health, player.energy});
}

void CombatSystem::encounterHealthPack(GameWorld& world, HealthPackData& hp) {
    auto& player = world.player();
    if (player.health < Constants::MaxHealth) {
        player.health++;
        world.relocateHealthPack(hp.pos);
        EventBus::instance().publish(HealthChangedEvent{player.health, player.energy});
    }
}

void CombatSystem::encounterAffectedTile(GameWorld& world, Vec2i /*pos*/) {
    auto& player = world.player();
    if (player.health > 0) {
        player.energy -= Constants::PoisonDamage;
        if (player.energy <= 0) {
            player.energy = 0;
            player.animState = EntityState::Dying;
        }
        EventBus::instance().publish(HealthChangedEvent{player.health, player.energy});
    }
}

void CombatSystem::applyEnemyDefeatReward(GameWorld& world, EnemyType type) {
    auto& player = world.player();
    int reward = 0;
    switch (type) {
        case EnemyType::Regular: reward = Constants::EnergyRewardEnemy; break;
        case EnemyType::Poison:  reward = Constants::EnergyRewardPoison; break;
        case EnemyType::Thunder:
            reward = Constants::EnergyRewardThunder;
            player.health = std::min(player.health + 5, Constants::MaxHealth);
            break;
    }
    player.energy = std::min(player.energy + reward, Constants::MaxEnergy);
}

bool CombatSystem::isPlayerDead(const GameWorld& world) {
    return world.player().health <= 0 || world.player().energy <= 0;
}

} // namespace AQ
