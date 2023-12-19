#include "EnemyModel.h"

/** Enemy Class */
EnemyModel::EnemyModel(std::unique_ptr<Enemy> enemy) : enemy(std::move(enemy)){
    strength = this->enemy->getValue();
    connect(this->enemy.get(), &Enemy::dead, this, &EnemyModel::onDead);
}

void EnemyModel::attack() {
    status = ATTACK;
    qDebug() << "enemy attack: start timer";
    float damage = 50.0f;
    QTimer::singleShot(100, this, [this, damage]() {takeDamage(damage);});
}

void EnemyModel::takeDamage(float damage) {
    strength -= damage;
    status = HURT;
    if (strength <= 0.0f) {
        QTimer::singleShot(100, this, [this]() {strength = 0.0f; enemy->setDefeated(true);});
        qDebug() << "enemy dead strength: " << strength;
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

std::string EnemyModel::serialize() const {
    return enemy->serialize();
}

void EnemyModel::onDead(){
    status = DYING;
}


/** PEnemy Class */

PEnemyModel::PEnemyModel(std::unique_ptr<PEnemy> penemy)
    :penemy(std::move(penemy)) {
    connect(this->penemy.get(), &Enemy::dead, this, &PEnemyModel::onDead);
    connect(this->penemy.get(), &PEnemy::poisonLevelUpdated, this, &PEnemyModel::onPoisonLevelUpdated);
}

void PEnemyModel::attack() {
    status = ATTACK;
    QTimer::singleShot(100, this, [this]() {
        penemy->poison();
    });
}

void PEnemyModel::takeDamage(float newPoisonLevel) {
    status = HURT;
    QTimer::singleShot(100, this, [this]() {
        status = IDLE;
    });
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
    QTimer::singleShot(100, this, [this]() {
        status = IDLE;
    });
}

// PEnemy specific functions
bool PEnemyModel::isDefeated() const {
    return penemy->getDefeated();
}

float PEnemyModel::getPoisonLevel() const {
    return penemy->getPoisonLevel();
}

std::string PEnemyModel::serialize() const {
    return penemy->serialize();
}

void PEnemyModel::onDead(){
    status = DYING;
}

void PEnemyModel::onPoisonLevelUpdated(float poisonLevel){
    takeDamage(poisonLevel);
}


