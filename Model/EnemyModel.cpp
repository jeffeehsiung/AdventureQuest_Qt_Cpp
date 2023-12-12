#include "EnemyModel.h"

/** Enemy Class */
EnemyModel::EnemyModel(std::unique_ptr<Enemy> enemy) : enemy(std::move(enemy)), health(100.0f) {
    // Assuming each enemy starts with a health of 100.0f
//    status = IDLE;
}

void EnemyModel::attack() {
    status = ATTACK;
    float level = 1.0f;
    takeDamage(level);
}

void EnemyModel::takeDamage(float damage) {
    status = HURT;
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
    status = MOVING;
    enemy->setXPos(enemy->getXPos() + deltaX);
    enemy->setYPos(enemy->getYPos() + deltaY);
}

// Enemy specific functions
bool EnemyModel::isDefeated() const {
    return enemy->getDefeated();
}

void EnemyModel::setDefeated(bool defeated) {
    status = DYING;
    enemy->setDefeated(defeated); // will emit dead() in world.
}

std::string EnemyModel::serialize() const {
    return enemy->serialize();
}


/** PEnemy Class */

PEnemyModel::PEnemyModel(std::unique_ptr<PEnemy> penemy)
    :penemy(std::move(penemy)) {
}

void PEnemyModel::attack() {
    qDebug() << "penemy attacking";
    status = ATTACK;
    float level = 1.0f;
    takeDamage(level);
}

void PEnemyModel::takeDamage(float damage) {
    // Consider poison effects if relevant
    status = HURT;
    // Reduce health by the damage amount
    health -= damage;
    // release poison
    bool isAlive = releasePoison();
    if (isAlive == false){
        setDefeated(true);
    }
}

coordinate PEnemyModel::getPosition() const {
    return {penemy->getXPos(), penemy->getYPos()};
}

void PEnemyModel::setPosition(coordinate position) {
    penemy->setXPos(position.xCoordinate);
    penemy->setYPos(position.yCoordinate);
}

void PEnemyModel::move(int deltaX, int deltaY) {
    status = MOVING;
    penemy->setXPos(penemy->getXPos() + deltaX);
    penemy->setYPos(penemy->getYPos() + deltaY);
}

// Enemy specific functions
bool PEnemyModel::isDefeated() const {
    return penemy->getDefeated();
}

void PEnemyModel::setDefeated(bool defeated) {
    status = DYING;
    penemy->setDefeated(defeated); // will emit dead() in world.
}

bool PEnemyModel::releasePoison() {
    // return boolean: true -> not dead yet, false-> dead.
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


