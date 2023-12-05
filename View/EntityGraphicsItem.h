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

    static qreal commonWidth;
    static qreal commonHeight;

public:

    // Static method to set common dimensions
    static void setCommonDimensions(qreal width, qreal height);

    explicit EntityGraphicsItem(const Entity& entity, QGraphicsRectItem* parent = nullptr);

    virtual ~EntityGraphicsItem();

    // Changes the current animation state and restarts the animation
    void changeAnimationState(AnimationState newState);

    // Advances to the next frame in the current animation
    void nextFrame();

    const Entity& getEntity() const;

    void updatePosition();

    // Graphics item methods
    QRectF boundingRect() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

protected:
    // Starts or continues the animation timer
    void startAnimation();

    // Handles the end of an animation sequence
    void handleAnimationEnd();
};

#endif // ENTITYGRAPHICSITEM_H
