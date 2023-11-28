#include "EnemyModel.h"

EnemyModel::EnemyModel(Enemy* enemy) : enemy(enemy), health(100.0f) {
    // Assuming each enemy starts with a health of 100.0f
}

void EnemyModel::attack() {
    // Enemy's attack implementation
}

void EnemyModel::takeDamage(float damage) {
    // Reduce health by the damage amount
    health -= damage;

    // Check if health falls below 0
    if (health <= 0.0f) {
        // If health is depleted, consider the enemy as defeated
        enemy->setDefeated(true);
        health = 0.0f; // Ensure health does not go below 0
    }
}

coordinate EnemyModel::getPosition() const {
    return {enemy->getXPos(), enemy->getYPos()};
}

void EnemyModel::setPosition(coordinate position) {
    enemy->setXPos(position.xCoordinate);
    enemy->setYPos(position.yCoordinate);
}

void EnemyModel::move(int deltaX, int deltaY) {
    enemy->setXPos(enemy->getXPos() + deltaX);
    enemy->setYPos(enemy->getYPos() + deltaY);
}

float EnemyModel::getHealth() const {
    return health;
}

void EnemyModel::setHealth(float newHealth) {
    health = std::max(0.0f, newHealth); // Ensure health does not go below 0
}
