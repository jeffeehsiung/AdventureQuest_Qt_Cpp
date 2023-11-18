#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H

#include "world.h" // include the world library

class EnemyModel : public Enemy {
    // Inherits all public and protected members from Enemy

public:
    explicit EnemyModel(int xPosition, int yPosition, float strength, QObject *parent = nullptr)
        : Enemy(xPosition, yPosition, strength, parent) {
        // Constructor code specific to EnemyModel
    }

    // Additional methods specific to the EnemyModel
};

#endif // ENEMYMODEL_H
