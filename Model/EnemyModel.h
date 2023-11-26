#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H

#include "Entity.h"
#include "world.h"  // Assuming Enemy.h is the header where Enemy is defined

class EnemyModel : public Entity {
private:
    Enemy* enemy; // Raw pointer to Enemy managed by World

public:
    EnemyModel(Enemy* enemy); // Constructor declaration

    void attack() override;
    void takeDamage(int damage) override;
    coordinate getPosition() const override;
    void setPosition(coordinate position) override;
    void move(int deltaX, int deltaY) override;
};

#endif // ENEMYMODEL_H