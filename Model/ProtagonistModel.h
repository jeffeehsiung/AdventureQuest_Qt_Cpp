#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "Entity.h"
#include "world.h"
#include <memory>

class ProtagonistModel : public Entity {

private:
    std::unique_ptr<Protagonist> protagonist;
    int health;
    int energy;

public:
    explicit ProtagonistModel(std::unique_ptr<Protagonist> protagonist); // Constructor declaration

    void attack() override;
    void takeDamage(float damage) override;
    coordinate getPosition() const override;
    void setPosition(coordinate position) override;
    void move(int deltaX, int deltaY) override;

    // Additional functionalities specific to ProtagonistModel
    int getHealth() const;
    void setHealth(float health);
    int getEnergy() const;
    void setEnergy(float energy);
    std::string serialize() const;
};

#endif // PROTAGONISTMODEL_H
