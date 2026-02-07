#ifndef AQ_PLATFORM_IINPUT_HANDLER_H
#define AQ_PLATFORM_IINPUT_HANDLER_H

#include "Core/Types.h"
#include <functional>

namespace AQ {

// Abstract input handler. Maps platform-specific input (keyboard, touch, gamepad)
// to game actions. Desktop uses keyboard; iOS uses touch overlay + swipe gestures.

class IInputHandler {
public:
    virtual ~IInputHandler() = default;

    using ActionCallback = std::function<void(InputAction)>;
    using PositionCallback = std::function<void(Vec2i)>;

    virtual void setActionCallback(ActionCallback cb) = 0;
    virtual void setTapCallback(PositionCallback cb) = 0;
    virtual bool isTouch() const = 0;
};

} // namespace AQ

#endif // AQ_PLATFORM_IINPUT_HANDLER_H
