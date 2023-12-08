#include "TileGraphicsItem.h"
#include <QDir>

// the naming should be changed to TileGraphicsItem

TileGraphicsItem::TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent)
    : EntityGraphicsItem(tileModel, parent), baseFramesDir(baseFramesDir) {
    loadAnimationFrames();
//    updatePosition(); // Set the position based on tile's X and Y positions
//    startAnimation();

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
            // Pre-scale the image here
            QPixmap scaledFrame = frame.scaled(EntityGraphicsItem::commonWidth, EntityGraphicsItem::commonHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            frames.push_back(scaledFrame);
        }
    }
}

void TileGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    // First, draw the base image
    EntityGraphicsItem::paint(painter, option, widget);

    // Now handle TileModel specific painting for the overlay
    const TileModel* tileModel = dynamic_cast<const TileModel*>(&getEntity());
    if (tileModel) {
        int value = tileModel->getValue();

        // Assuming 'value' ranges from 0 to 100, map it to an alpha value between 0 and 255
        int alpha = static_cast<int>((value / 50.0) * 255);
        QColor color(0, 255, 0, alpha); // Semi-transparent green

        // Calculate the top-left position to center the image within the bounding rectangle
        int x = (commonWidth - image.width()) / 2;
        int y = (commonHeight - image.height()) / 2;


        // Set the brush to the determined color with transparency and draw the overlay
        painter->setBrush(color);
        painter->setPen(Qt::NoPen); // No border for the overlay
        painter->drawRect(boundingRect());
    }

    EntityGraphicsItem::paint(painter, option, widget);

}



