#include "TileGraphicsItem.h"
#include <QDir>

TileGraphicsItem::TileGraphicsItem(TileModel* tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent)
    : EntityGraphicsItem(tileModel, parent), baseFramesDir(baseFramesDir) {
    loadAnimationFrames();
    updatePosition(); // Set the position based on tile's X and Y positions

}

void TileGraphicsItem::loadAnimationFrames() {
    // Load the frames for each animation state
    loadFramesFromDirectory(baseFramesDir + "Idle/", idleFrames);
}

void TileGraphicsItem::loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames) {
    QDir dir(dirPath);
    QStringList fileNames = dir.entryList(QStringList() << "*.png", QDir::Files, QDir::Name);
    for (const QString& fileName : fileNames) {
        QPixmap frame(dirPath + fileName);
        if (!frame.isNull()) {
            frames.push_back(frame);
        }
    }
}
