#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H

#include <memory>
#include "Entity.h"

class EnemyModel : public Entity {
    Q_OBJECT
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

    public slots:
        void onDead();

    protected:
        std::unique_ptr<Enemy> enemy;
        float strength;
};

class PEnemyModel : public Entity {
    Q_OBJECT
    public:
        explicit PEnemyModel(std::unique_ptr<PEnemy> penemy);

        // Override Enemy's functions if necessary and add PEnemy specific functions
        void attack() override;
        void takeDamage(float newPoisonLevel) override;
        coordinate getPosition() const override;
        void setPosition(coordinate position) override;
        void move(int deltaX, int deltaY) override;

        // PEnemy specific functions
        bool isDefeated() const;
        float getPoisonLevel() const;
        std::string serialize() const;

    public slots:
        void onDead();
        void onPoisonLevelUpdated(float poisonLevel);

    signals:
        void psnTilesUpdated(float newPoisonLevel);

    private:
        std::unique_ptr<PEnemy> penemy;
};

//class XEnemyModel : public Entity {
    //public:
    //    explicit XEnemyModel(std::unique_ptr<XPEnemy> xenemy);

    //    void attack() override;
    //    void takeDamage(float damage) override;
    //    coordinate getPosition() const override;
    //    void setPosition(coordinate position) override;
    //    void move(int deltaX, int deltaY) override;

    //    // PEnemy specific functions
    //    bool isDefeated() const;
    //    void setDefeated(bool defeated);
    //    bool releasePoison();
    //    float getPoisonLevel() const;
    //    void setPoisonLevel(float poisonLevel);
    //    std::string serialize() const;

    //private:
    //    std::unique_ptr<XEnemy> xenemy;
    //    float health;
//};

#endif // ENEMYMODEL_H
