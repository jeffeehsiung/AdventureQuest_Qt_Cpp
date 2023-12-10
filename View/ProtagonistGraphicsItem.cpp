#include "ProtagonistGraphicsItem.h"
#include <QDir>

//QString EntityGraphicsItem::baseFramesDir = "images/protagonist_fighter/";

ProtagonistGraphicsItem::ProtagonistGraphicsItem(const ProtagonistModel& protagonistModel, const QString& baseFramesDir, QGraphicsRectItem* parent)
    : EntityGraphicsItem(protagonistModel, parent), baseFramesDir(baseFramesDir) {
    loadAnimationFrames();
}

void ProtagonistGraphicsItem::nextFrame() {
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


void ProtagonistGraphicsItem::loadAnimationFrames() {
    // Load the frames for each animation state
    loadFramesFromDirectory(baseFramesDir + "Idle/", idleFrames);
    loadFramesFromDirectory(baseFramesDir + "Moving/", moveFrames);
    loadFramesFromDirectory(baseFramesDir + "Hurt/", hurtFrames);
    loadFramesFromDirectory(baseFramesDir + "Dying/", dyingFrames);
    loadFramesFromDirectory(baseFramesDir + "Attack/", attackFrames);
    loadFramesFromDirectory(baseFramesDir + "Heal/", healFrames);
}

void ProtagonistGraphicsItem::loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames) {
    QDir dir(dirPath);
    QStringList fileNames = dir.entryList(QStringList() << "*.png", QDir::Files, QDir::Name);
    for (const QString& fileName : fileNames) {
        QPixmap spritesheet(dirPath + fileName);
        if (!spritesheet.isNull()) {
            // Assuming that each row in the sprite sheet is a separate animation
            const int frameDim = 128;
            const int numberOfFramesInAnimation = spritesheet.width()/frameDim;
            for (int i = 0; i < numberOfFramesInAnimation; ++i) {
                QPixmap frame = spritesheet.copy(i * frameDim, 0, frameDim, frameDim);
                frame = frame.scaled(EntityGraphicsItem::commonWidth, EntityGraphicsItem::commonHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                frames.push_back(frame);
            }
        } else {
            qDebug() << "Failed to load frame:" << dirPath + fileName;
        }
    }
}
