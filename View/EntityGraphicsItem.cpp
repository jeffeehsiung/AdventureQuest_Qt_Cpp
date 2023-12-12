#include "EntityGraphicsItem.h"

// Initialize static members
qreal EntityGraphicsItem::commonWidth = 0;
qreal EntityGraphicsItem::commonHeight = 0;
qreal EntityGraphicsItem::tileWidth = 0;
qreal EntityGraphicsItem::tileHeight = 0;


EntityGraphicsItem::EntityGraphicsItem(const Entity& entity, QGraphicsRectItem* parent)
    : QGraphicsRectItem(0, 0, tileWidth, tileHeight, parent),
    entity(entity),
//    status(IDLE),
    currentFrameIndex(0) {
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &EntityGraphicsItem::nextFrame);
    updatePosition();
    startAnimation();
}

EntityGraphicsItem::~EntityGraphicsItem() {
    delete animationTimer;
}

void EntityGraphicsItem::changeAnimationState(state newState) {
//    if (status != newState) {
//        status = newState;
//        currentFrameIndex = 0;
//        startAnimation();
//    }
    currentFrameIndex = 0;
    startAnimation();
}

void EntityGraphicsItem::nextFrame() {
    const state entityState = entity.getState();
    std::vector<QPixmap>* currentFrames = nullptr;
    switch (entityState) {
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
    this->setPos(pos.xCoordinate * tileWidth, pos.yCoordinate * tileHeight);
}

QRectF EntityGraphicsItem::boundingRect() const {
    // Use the larger of the actual tile size or the minimum visual size for the bounding rectangle
    qreal width = qMax(tileWidth, commonWidth);
    qreal height = qMax(tileHeight, commonHeight);
    return QRectF(0, 0, width, height);
}

void EntityGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // Calculate the offset to ensure the image is centered on the tile
    qreal xOffset = (tileWidth - commonWidth) / 2;
    qreal yOffset = (tileHeight - commonHeight) / 2;

    // Draw the pixmap centered within the tile
    painter->drawPixmap(xOffset, yOffset, image);
}


void EntityGraphicsItem::startAnimation() {
    if (!animationTimer->isActive()) {
        animationTimer->start(100);
    }
}

void EntityGraphicsItem::handleAnimationEnd() {
//    switch (status)
    switch (entity.getState()) {
    case IDLE:
    case HEAL:
        currentFrameIndex = 0;
        break;
    case MOVING:
    case ATTACK:
    case HURT:
    case DYING:
        animationTimer->stop();
//        status = IDLE;
        break;
    }
}

// Static method implementation
void EntityGraphicsItem::setCommonDimensions(qreal width, qreal height) {
    commonWidth = width;
    commonHeight = height;
}

void EntityGraphicsItem::setTileDimensions(qreal width, qreal height){
    tileWidth = width;
    tileHeight = height;
}
