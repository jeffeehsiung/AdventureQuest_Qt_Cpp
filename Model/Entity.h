#ifndef ENTITY_H
#define ENTITY_H

#include "Model/structs.h"

class Entity{
public:
    virtual ~Entity() {}

    // Pure virtual functions that must be implemented by any subclass
    virtual void attack() = 0;
    virtual void takeDamage(float damage) = 0;
    virtual coordinate getPosition() const = 0;
    virtual void setPosition(coordinate position) = 0;
    virtual void move(int deltaX, int deltaY) = 0;
};

#endif // ENTITY_H
