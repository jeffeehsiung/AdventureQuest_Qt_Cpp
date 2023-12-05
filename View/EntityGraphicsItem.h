#ifndef ENTITYGRAPHICSITEM_H
#define ENTITYGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include "Model/Entity.h"
#include <vector>

/** Animation State Handling: The class manages different animation states and cycles through frames based on the current state.
 *  Frame Advancement: The nextFrame method advances the animation frame, handling looping and one-time animations.
 *  Start Animation: The startAnimation method ensures the timer is running to continuously update frames.
 *  Handle Animation End: The handleAnimationEnd method determines what to do when an animation sequence finishes,
 *      like looping back to the start or stopping the animation.
 *  Frame Loading: Frame loading is not included in this class, as it is expected to be handled by the derived classes
 *      (ProtagonistGraphicsItem, EnemyGraphicsItem, etc.),
 *      which will populate the frame vectors (idleFrames, moveFrames, etc.) with their specific frames.
**/

class EntityGraphicsItem : public QObject, public QGraphicsRectItem{
    Q_OBJECT
protected:
    const Entity& entity;   // Raw pointer to entity model (abstract)
    QPixmap image;          // Image representing the entity

    // Animation properties
    enum AnimationState { IDLE, MOVING, ATTACK, HURT, DYING, HEAL };
    AnimationState animationState;
    QTimer* animationTimer;
    std::vector<QPixmap> idleFrames;
    std::vector<QPixmap> moveFrames;
    std::vector<QPixmap> hurtFrames;
    std::vector<QPixmap> dyingFrames;
    std::vector<QPixmap> attackFrames;
    std::vector<QPixmap> healFrames;
    std::vector<QPixmap>::size_type currentFrameIndex;

    static constexpr int commonWidth = 30; // Set your desired width
    static constexpr int commonHeight = 30; // Set your desired height

public:
    explicit EntityGraphicsItem(const Entity& entity, QGraphicsRectItem* parent = nullptr)
        : QGraphicsRectItem(parent), entity(entity), animationState(IDLE), currentFrameIndex(0) {
        animationTimer = new QTimer(this);
        connect(animationTimer, &QTimer::timeout, this, &EntityGraphicsItem::nextFrame);
        // Set a common size for all EntityGraphicsItems
        setRect(0, 0, commonWidth, commonHeight);
        updatePosition();
        startAnimation();
    }

    virtual ~EntityGraphicsItem() {
        delete animationTimer;
    }

    // Changes the current animation state and restarts the animation
    inline void changeAnimationState(AnimationState newState) {
        if (animationState != newState) {
            animationState = newState;
            currentFrameIndex = 0; // Reset frame index for the new animation
            startAnimation(); // Start or continue the animation timer
        }
    }

    // Advances to the next frame in the current animation
    inline void nextFrame() {
        std::vector<QPixmap>* currentFrames = nullptr;
        switch (animationState) {
        case IDLE: currentFrames = &idleFrames; break;
        case MOVING: currentFrames = &moveFrames; break;
        case ATTACK: currentFrames = &attackFrames; break;
        case HURT: currentFrames = &hurtFrames; break;
        case DYING: currentFrames = &dyingFrames; break;
        case HEAL: currentFrames = &healFrames; break;
        }

        if (!currentFrames || currentFrames->empty()) return; // No frames to animate

        // Check if we reached the end of the animation
        if (currentFrameIndex >= currentFrames->size()) {
            handleAnimationEnd();
            return; // Early exit to avoid updating the image below
        }

        // Set the current frame to the next frame in the animation sequence
        image = (*currentFrames)[currentFrameIndex++];
        update(); // Trigger a repaint of the graphics item
    }

    inline const Entity& getEntity() const{
        return entity;
    }

    inline void updatePosition() {
        coordinate pos = entity.getPosition();
        setPos(pos.xCoordinate, pos.yCoordinate);
    }


    // Graphics item methods
    QRectF boundingRect() const override {
        return QRectF(0, 0, commonWidth, commonHeight);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);

        // Calculate the top-left position to center the image within the bounding rectangle
        int x = (commonWidth - image.width()) / 2;
        int y = (commonHeight - image.height()) / 2;

        painter->drawPixmap(x, y, image);
    }

protected:
    // Starts or continues the animation timer
    inline void startAnimation() {
        if (!animationTimer->isActive()) {
            animationTimer->start(100); // Adjust the interval as needed
        }
    }

    // Handles the end of an animation sequence
    inline void handleAnimationEnd() {
        switch (animationState) {
        case IDLE:
        case MOVING:
        case HEAL:
            currentFrameIndex = 0; // Looping animations: reset to the first frame
            break;
        case ATTACK:
        case HURT:
        case DYING:
            animationTimer->stop(); // One-time animations: stop the animation
            animationState = IDLE; // Switch to idle or another appropriate state
            break;
        }
    }
};

#endif // ENTITYGRAPHICSITEM_H
