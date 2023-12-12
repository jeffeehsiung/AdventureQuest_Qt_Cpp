#ifndef ENTITY_H
#define ENTITY_H

#include <QDebug>
#include "Model/structs.h"
#include "world.h"

class Entity{
public:
    Entity() : status(IDLE) {}
    virtual ~Entity() {}

    // Pure virtual functions that must be implemented by any subclass
    virtual void attack() = 0;
    virtual void takeDamage(float damage) = 0;
    virtual coordinate getPosition() const = 0;
    virtual void setPosition(coordinate position) = 0;
    virtual void move(int deltaX, int deltaY) = 0;
    state getState() const {
        return status;
    }

    void setState(state newStatus) {
        status = newStatus;
    }
protected:
    state status;
};

#endif // ENTITY_H
