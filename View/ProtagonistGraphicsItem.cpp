#include "ProtagonistGraphicsItem.h"
#include <QDir>

//QString EntityGraphicsItem::baseFramesDir = "images/protagonist_fighter/";

ProtagonistGraphicsItem::ProtagonistGraphicsItem(ProtagonistModel& protagonistModel, const QString& baseFramesDir, QGraphicsRectItem* parent)
    : EntityGraphicsItem(protagonistModel, parent), baseFramesDir(baseFramesDir) {
    loadAnimationFrames();
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
        QPixmap frame(dirPath + fileName);
        if (!frame.isNull()) {
            qDebug() << "Original frame size:" << frame.size(); // Output the size of the original frame
            // Pre-scale the image here
            QPixmap scaledFrame = frame.scaled(EntityGraphicsItem::commonWidth, EntityGraphicsItem::commonHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            qDebug() << "Scaled frame size:" << scaledFrame.size();
            frames.push_back(scaledFrame);
        } else {
            qDebug() << "Failed to load frame:" << dirPath + fileName;
        }
    }
}

