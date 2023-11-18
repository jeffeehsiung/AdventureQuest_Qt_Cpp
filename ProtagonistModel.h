#ifndef PROTAGONISTMODEL_H
#define PROTAGONISTMODEL_H

#include "Entity.h"
#include "world.h"

class ProtagonistModel : public Entity {
private:
    Protagonist* protagonist;  // Raw pointer is used because ProtagonistModel doesn't own this object

public:
    // Constructor that accepts an existing Protagonist pointer
    ProtagonistModel(Protagonist* protagonist) : protagonist(protagonist) {}

    void attack() override {
        // Implement attack logic using the Protagonist instance
    }

    void takeDamage(int damage) override {
        // Implement take damage logic using the Protagonist instance
    }

    coordinate getPosition() const override {
        // Assuming coordinate is a struct with xCoordinate and yCoordinate
        return {protagonist->getXPos(), protagonist->getYPos()};
    }

    void setPosition(coordinate position) override {
        protagonist->setXPos(position.xCoordinate);
        protagonist->setYPos(position.yCoordinate);
    }

    void move(int deltaX, int deltaY) override {
        // Move the Protagonist instance
        protagonist->setXPos(protagonist->getXPos() + deltaX);
        protagonist->setYPos(protagonist->getYPos() + deltaY);
    }

    // ... Additional methods and logic ...
};

#endif // PROTAGONISTMODEL_H
