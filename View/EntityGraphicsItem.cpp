#include "EntityGraphicsItem.h"

// Initialize static members
qreal EntityGraphicsItem::commonWidth = 0;
qreal EntityGraphicsItem::commonHeight = 0;

EntityGraphicsItem::EntityGraphicsItem(const Entity& entity, QGraphicsRectItem* parent)
    : QGraphicsRectItem(0, 0, commonWidth, commonHeight, parent),
    entity(entity),
    animationState(IDLE),
    currentFrameIndex(0) {
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &EntityGraphicsItem::nextFrame);
    updatePosition();
    startAnimation();
}

EntityGraphicsItem::~EntityGraphicsItem() {
    delete animationTimer;
}

void EntityGraphicsItem::changeAnimationState(AnimationState newState) {
    if (animationState != newState) {
        animationState = newState;
        currentFrameIndex = 0;
        startAnimation();
    }
}

void EntityGraphicsItem::nextFrame() {
    std::vector<QPixmap>* currentFrames = nullptr;
    switch (animationState) {
    case IDLE: currentFrames = &idleFrames; break;
    case MOVING: currentFrames = &moveFrames; break;
    case ATTACK: currentFrames = &attackFrames; break;
    case HURT: currentFrames = &hurtFrames; break;
    case DYING: currentFrames = &dyingFrames; break;
    case HEAL: currentFrames = &healFrames; break;
    }

    if (!currentFrames || currentFrames->empty()) return;

    // Check if we reached the end of the animation
    if (currentFrameIndex >= currentFrames->size()) {
        handleAnimationEnd();
        return;
    }

    image = (*currentFrames)[currentFrameIndex++];
    update();
}

const Entity& EntityGraphicsItem::getEntity() const {
    return entity;
}

void EntityGraphicsItem::updatePosition() {
    coordinate pos = entity.getPosition();
//    qDebug() << "original position:" << pos.xCoordinate << "," << pos.yCoordinate;
    this->setPos(pos.xCoordinate * commonWidth, pos.yCoordinate * commonHeight);
//    qDebug() << "scaled position:" << this->pos();
}

QRectF EntityGraphicsItem::boundingRect() const {
    return QRectF(0, 0, commonWidth, commonHeight);
}

void EntityGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(0, 0, image);
}

void EntityGraphicsItem::startAnimation() {
    if (!animationTimer->isActive()) {
        animationTimer->start(100);
    }
}

void EntityGraphicsItem::handleAnimationEnd() {
    switch (animationState) {
    case IDLE:
    case HEAL:
        currentFrameIndex = 0;
        break;
    case MOVING:
    case ATTACK:
    case HURT:
    case DYING:
        animationTimer->stop();
        animationState = IDLE;
        break;
    }
}

// Static method implementation
void EntityGraphicsItem::setCommonDimensions(qreal width, qreal height) {
    commonWidth = width;
    commonHeight = height;
}
