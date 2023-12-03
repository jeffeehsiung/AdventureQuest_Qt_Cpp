#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H

#include "Entity.h"
#include "world.h"  // Assuming Enemy.h is the header where Enemy is defined
#include <memory>

class EnemyModel : public Entity {
public:
    EnemyModel(std::unique_ptr<Enemy> enemy); // Constructor declaration
    void attack() override;
    void takeDamage(float damage) override;
    coordinate getPosition() const override;
    void setPosition(coordinate position) override;
    void move(int deltaX, int deltaY) override;

    // Enemy specific functions
    bool isDefeated() const;
    void setDefeated(bool defeated);
    std::string serialize() const;
protected:
    std::unique_ptr<Enemy> enemy;
    float health;
};

class PEnemyModel : public EnemyModel {
public:
    explicit PEnemyModel(std::unique_ptr<PEnemy> penemy);

    // Override Enemy's functions if necessary and add PEnemy specific functions
    void attack() override;
    void takeDamage(float damage) override;

    // PEnemy specific functions
    bool poison();
    float getPoisonLevel() const;
    void setPoisonLevel(float poisonLevel);
    std::string serialize() const;

private:
    std::unique_ptr<PEnemy> penemy;
};


#endif // ENEMYMODEL_H
