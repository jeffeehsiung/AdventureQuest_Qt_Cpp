#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "Entity.h"
#include "world.h"

class ProtagonistModel : public Entity {
private:
    Protagonist* protagonist; // Raw pointer to Protagonist managed by World

public:
    ProtagonistModel(Protagonist* protagonist); // Constructor declaration

    void attack() override;
    void takeDamage(int damage) override;
    coordinate getPosition() const override;
    void setPosition(coordinate position) override;
    void move(int deltaX, int deltaY) override;
};

#endif // PROTAGONISTMODEL_H
