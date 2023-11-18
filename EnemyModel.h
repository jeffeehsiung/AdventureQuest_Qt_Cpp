#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H

#include "Entity.h"
#include "world.h" // Assuming Enemy.h is the header where Enemy is defined

class EnemyModel : public Entity {
private:
    Enemy* enemy; // Raw pointer to Enemy managed by World

public:
    // Constructor takes a raw pointer to an existing Enemy
    EnemyModel(Enemy* enemy) : enemy(enemy) {}

    void attack() override {
        // Enemy's attack implementation
    }

    void takeDamage(int damage) override {
        // Enemy's take damage implementation
    }

    coordinate getPosition() const override {
        return {enemy->getXPos(), enemy->getYPos()};
    }

    void setPosition(coordinate position) override {
        enemy->setXPos(position.xCoordinate);
        enemy->setYPos(position.yCoordinate);
    }

    void move(int deltaX, int deltaY) override {
        // Move the enemy
        enemy->setXPos(enemy->getXPos() + deltaX);
        enemy->setYPos(enemy->getYPos() + deltaY);
    }

    // ... Additional methods and logic ...
};

#endif // ENEMYMODEL_H
