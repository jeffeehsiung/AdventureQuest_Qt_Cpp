#include "TileGraphicsItem.h"

const float maxValue = 0.95;
// the naming should be changed to TileGraphicsItem

TileGraphicsItem::TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir,bool spritesLoaded , QGraphicsRectItem* parent)
    : EntityGraphicsItem(tileModel, parent), tileModel(tileModel), baseFramesDir(baseFramesDir){
    this->animationTimer->stop();
    tileModel.addObserver(this);
    if (!spritesLoaded) {
        loadAnimationFrames();
    }
}

void TileGraphicsItem::loadAnimationFrames() {
    // Load the frames for each animation state
    loadFramesFromDirectory(baseFramesDir + "Idle/", idleFrames);
    loadFramesFromDirectory(baseFramesDir + "Moving/", moveFrames);
    loadFramesFromDirectory(baseFramesDir + "Attack/", attackFrames);
    loadFramesFromDirectory(baseFramesDir + "Hurt/", hurtFrames);
}

void TileGraphicsItem::loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames) {
    QDir dir(dirPath);
    if(!dir.exists()){
        return;
    }
    QStringList fileNames = dir.entryList(QStringList() << "*.png", QDir::Files, QDir::Name);
    for (const QString& fileName : fileNames) {
        QPixmap frame(dirPath + fileName);
        if (!frame.isNull()) {
            // Pre-scale the image here
            QPixmap scaledFrame = frame.scaled(EntityGraphicsItem::tileWidth, EntityGraphicsItem::tileHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            frames.push_back(scaledFrame);
        } else {
            qDebug() << "Failed to load frame:" << dirPath + fileName;
        }
    }
}

QRectF TileGraphicsItem::boundingRect() const {
    return QRectF(0, 0, tileWidth, tileHeight);
}


void TileGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    // Calculate the backgorund index and draw the background image
    int backgroundIndex = static_cast<int>(this->tileModel.getValue() * (idleFrames.size()-1) / maxValue) % (idleFrames.size()-1);
    backgroundImage = idleFrames[backgroundIndex];

    painter->drawPixmap(0, 0, backgroundImage);

    // draw the animation frame if not null
    if(!image.isNull()){
        painter->drawPixmap(0, 0, image);
    }
}

void TileGraphicsItem::onTileChanged(){
    // re-activate timer
    if (!this->animationTimer->isActive()) {
        this->animationTimer->start(100);
    }
}

void TileGraphicsItem::nextFrame() {
    const state entityState = entity.getState();
    switch (entityState) {
        Q_UNUSED(HEAL);
    case MOVING:
        if(!moveFrames.empty()){
            currentFrameIndex = (currentFrameIndex + 1) % moveFrames.size();
            image = moveFrames[currentFrameIndex];
        }
        break;
    case ATTACK:
        if(!attackFrames.empty()){
            currentFrameIndex = (currentFrameIndex + 1) % attackFrames.size();
            image = attackFrames[currentFrameIndex];
        }
        break;
    case HURT:
        if(!hurtFrames.empty()){
            currentFrameIndex = (currentFrameIndex + 1) % hurtFrames.size();
            image = hurtFrames[currentFrameIndex];
        }
        break;
    case DYING:
        this->animationTimer->stop();
        break;
    }
    update();
}
