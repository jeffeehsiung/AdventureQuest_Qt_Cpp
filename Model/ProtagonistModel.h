#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "Entity.h"
#include "world.h"
#include <memory>

class ProtagonistModel : public Entity {

private:
    std::unique_ptr<Protagonist> protagonist;

public:
    explicit ProtagonistModel(std::unique_ptr<Protagonist> protagonist); // Constructor declaration

    void attack() override;
    void takeDamage(float damage) override;
    coordinate getPosition() const override;
    void setPosition(coordinate position) override;
    void move(int deltaX, int deltaY) override;

    // Additional functionalities specific to ProtagonistModel
    float getHealth() const;
    float getEnergy() const;
    std::string serialize() const;
};

#endif // PROTAGONISTMODEL_H
