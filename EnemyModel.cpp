#include "EnemyModel.h"

EnemyModel::EnemyModel(Enemy* enemy) : enemy(enemy) {}

void EnemyModel::attack() {
    // Enemy's attack implementation
}

void EnemyModel::takeDamage(int damage) {
    // Enemy's take damage implementation
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
