#ifndef AQ_RENDERER_ANIMATION_CONTROLLER_H
#define AQ_RENDERER_ANIMATION_CONTROLLER_H

#include "Core/Types.h"
#include <QPixmap>
#include <QString>
#include <vector>

namespace AQ {

// AnimationController manages frame-based sprite animation for a single entity.
// It references sprites from SpriteCache (no ownership) and cycles frames
// based on the entity's current state.

class AnimationController {
public:
    struct AnimSet {
        QString idlePath;
        QString movePath;
        QString attackPath;
        QString hurtPath;
        QString dyingPath;
        QString healPath;
    };

    AnimationController() = default;
    explicit AnimationController(const AnimSet& paths);

    // Advance animation by one frame. Returns the current frame pixmap.
    const QPixmap& advance(EntityState state);

    // Get current frame without advancing
    const QPixmap& currentFrame() const;

    // Reset to first frame
    void reset();

    // Check if the dying animation is complete
    bool isDyingComplete() const { return dyingComplete_; }

private:
    const std::vector<QPixmap>* framesForState(EntityState state) const;

    const std::vector<QPixmap>* idle_ = nullptr;
    const std::vector<QPixmap>* move_ = nullptr;
    const std::vector<QPixmap>* attack_ = nullptr;
    const std::vector<QPixmap>* hurt_ = nullptr;
    const std::vector<QPixmap>* dying_ = nullptr;
    const std::vector<QPixmap>* heal_ = nullptr;

    EntityState currentState_ = EntityState::Idle;
    size_t frameIndex_ = 0;
    bool dyingComplete_ = false;

    static QPixmap nullPixmap_;
};

} // namespace AQ

#endif // AQ_RENDERER_ANIMATION_CONTROLLER_H
