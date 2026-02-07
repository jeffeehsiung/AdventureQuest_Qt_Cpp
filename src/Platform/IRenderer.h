#ifndef AQ_PLATFORM_IRENDERER_H
#define AQ_PLATFORM_IRENDERER_H

#include "Core/Types.h"
#include "Game/GameWorld.h"

namespace AQ {

// Abstract renderer interface. Allows swapping Qt rendering for
// Metal/OpenGL ES on iOS or any other backend without touching game logic.

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual void initialize(const GameWorld& world, int levelIndex) = 0;
    virtual void updateView() = 0;
    virtual void setLevel(const GameWorld& world, int levelIndex) = 0;
    virtual void cleanup() = 0;
};

} // namespace AQ

#endif // AQ_PLATFORM_IRENDERER_H
