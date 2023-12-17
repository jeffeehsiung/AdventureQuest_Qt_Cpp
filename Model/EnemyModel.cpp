#include "EnemyModel.h"

/** Enemy Class */
EnemyModel::EnemyModel(std::unique_ptr<Enemy> enemy) : enemy(std::move(enemy)){
    strength = this->enemy->getValue();
    qDebug() << "enemy strength: " << strength;
    connect(this->enemy.get(), &Enemy::dead, this, &EnemyModel::onDead);
}

void EnemyModel::attack() {
    status = ATTACK;
    qDebug() << "enemy attack: start timer";
    float damage = 50.0f;
    QTimer::singleShot(200, this, [this, damage]() {takeDamage(damage);});
}

void EnemyModel::takeDamage(float damage) {
    strength -= damage;
    if (strength <= 0.0f) {
        QTimer::singleShot(200, this, [this]() {strength = 0.0f; setDefeated(true);});
    }
    status = HURT;
    qDebug() << "enemy take damage strength: " << strength;
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
    enemy->setDefeated(defeated); // will emit dead() in world.
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
    poisonLevel = this->penemy->getPoisonLevel();
    isAlive = this->penemy->getDefeated();
    connect(this->penemy.get(), &Enemy::dead, this, &PEnemyModel::onDead);
//    connect(this->penemy.get(), &PEnemy::poisonLevelUpdated, this, &PEnemyModel::onPoisonLevelUpdated);
}

void PEnemyModel::attack() {
    status = ATTACK;
    isAlive = releasePoison();
}

void PEnemyModel::takeDamage(float newPoisonLevel) {
    poisonLevel = newPoisonLevel;
    status = HURT;
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
    QTimer::singleShot(100, this, [this]() {
        status = IDLE;
    });
}

// PEnemy specific functions
bool PEnemyModel::isDefeated() const {
    return penemy->getDefeated();
}

void PEnemyModel::setDefeated(bool defeated) {
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

void PEnemyModel::onDead(){
    status = DYING;
}

void PEnemyModel::onPoisonLevelUpdated(float poisonLevel){
    status = ATTACK;
    takeDamage(poisonLevel);
    QTimer::singleShot(500, this, [this]() {
        status = IDLE;
    });
}


