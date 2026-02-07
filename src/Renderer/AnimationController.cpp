#include "Renderer/AnimationController.h"
#include "Renderer/SpriteCache.h"

namespace AQ {

QPixmap AnimationController::nullPixmap_;

AnimationController::AnimationController(const AnimSet& paths) {
    auto& cache = SpriteCache::instance();

    if (!paths.idlePath.isEmpty())   idle_   = &cache.getFrames(paths.idlePath);
    if (!paths.movePath.isEmpty())   move_   = &cache.getFrames(paths.movePath);
    if (!paths.attackPath.isEmpty()) attack_ = &cache.getFrames(paths.attackPath);
    if (!paths.hurtPath.isEmpty())   hurt_   = &cache.getFrames(paths.hurtPath);
    if (!paths.dyingPath.isEmpty())  dying_  = &cache.getFrames(paths.dyingPath);
    if (!paths.healPath.isEmpty())   heal_   = &cache.getFrames(paths.healPath);
}

const std::vector<QPixmap>* AnimationController::framesForState(EntityState state) const {
    switch (state) {
        case EntityState::Idle:      return idle_;
        case EntityState::Moving:    return move_;
        case EntityState::Attacking: return attack_;
        case EntityState::Hurt:      return hurt_;
        case EntityState::Dying:     return dying_;
        case EntityState::Healing:   return heal_;
    }
    return idle_;
}

const QPixmap& AnimationController::advance(EntityState state) {
    // State changed - reset frame
    if (state != currentState_) {
        currentState_ = state;
        frameIndex_ = 0;
        dyingComplete_ = false;
    }

    const auto* frames = framesForState(state);
    if (!frames || frames->empty()) return nullPixmap_;

    if (frameIndex_ >= frames->size()) {
        // Animation cycle complete
        if (state == EntityState::Dying) {
            dyingComplete_ = true;
            return frames->back(); // hold last frame
        }
        frameIndex_ = 0; // loop
    }

    return (*frames)[frameIndex_++];
}

const QPixmap& AnimationController::currentFrame() const {
    const auto* frames = framesForState(currentState_);
    if (!frames || frames->empty()) return nullPixmap_;
    size_t idx = (frameIndex_ > 0) ? frameIndex_ - 1 : 0;
    if (idx >= frames->size()) idx = frames->size() - 1;
    return (*frames)[idx];
}

void AnimationController::reset() {
    frameIndex_ = 0;
    currentState_ = EntityState::Idle;
    dyingComplete_ = false;
}

} // namespace AQ
