#include "EnemyModel.h"

/** Enemy Class */
EnemyModel::EnemyModel(std::unique_ptr<Enemy> enemy) : enemy(std::move(enemy)), health(100.0f) {
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

// Enemy specific functions
bool EnemyModel::isDefeated() const {
    return enemy->getDefeated();
}

void EnemyModel::setDefeated(bool defeated) {
    enemy->setDefeated(defeated);
}

std::string EnemyModel::serialize() const {
    return enemy->serialize();
}

/** PEnemy Class */

PEnemyModel::PEnemyModel(std::unique_ptr<PEnemy> penemy)
    : EnemyModel(std::move(penemy)), penemy(dynamic_cast<PEnemy*>(enemy.get())) {}

void PEnemyModel::attack() {
    // Implementation of how a poisoned enemy attacks
}

void PEnemyModel::takeDamage(float damage) {
    // penemy->reduceHealth(damage); // Assuming PEnemy class has reduceHealth method
    // Consider poison effects if relevant
}

bool PEnemyModel::poison() {
    return penemy->poison();
}

float PEnemyModel::getPoisonLevel() const {
    return penemy->getPoisonLevel();
}

void PEnemyModel::setPoisonLevel(float poisonLevel) {
    penemy->setPoisonLevel(poisonLevel);
}

std::string PEnemyModel::serialize() const {
    return penemy->serialize();
}


