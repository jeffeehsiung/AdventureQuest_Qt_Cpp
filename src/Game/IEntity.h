#ifndef AQ_GAME_IENTITY_H
#define AQ_GAME_IENTITY_H

#include "Core/Types.h"

namespace AQ {

// Abstract entity interface - base contract for all game entities.
// Separates identity (id) from behavior (attack/damage/move).
// IDs are assigned by the World and used by the EventBus for communication.

class IEntity {
public:
    virtual ~IEntity() = default;

    virtual int id() const = 0;
    virtual Vec2i position() const = 0;
    virtual void setPosition(Vec2i pos) = 0;
    virtual EntityState state() const = 0;
    virtual void setState(EntityState s) = 0;

    virtual void attack() = 0;
    virtual void takeDamage(float damage) = 0;
};

} // namespace AQ

#endif // AQ_GAME_IENTITY_H
