#include "TileGraphicsItem.h"

// the naming should be changed to TileGraphicsItem

TileGraphicsItem::TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent)
    : EntityGraphicsItem(tileModel, parent), baseFramesDir(baseFramesDir)  {
    loadAnimationFrames();
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
    // Call the base class paint method to draw the base image if needed.
    // If the tiles are meant to be transparent, showing only the shades of green, then the base image paint call can be omitted.
    // Draw the base image first

    // Now handle TileModel specific painting for the overlay
    const TileModel* tileModel = dynamic_cast<const TileModel*>(&getEntity());
    if (tileModel) {

        if(!image.isNull()){
            painter->drawPixmap(0, 0, image);
        }

        int value = tileModel->getValue();

        // Assuming value is between 0 and some maximum value, map it to an alpha value between 0 and 255.
        // The maximum value here should be the maximum possible value of your tiles.
        const int maxValue = 255 * 0.5; // Replace with your maximum tile value if different
        int alpha = static_cast<int>((static_cast<double>(value) / maxValue) * 255);

        // Create a green color with the calculated alpha for transparency
        QColor overlayColor(0, 255, 0, alpha); // Semi-transparent green based on 'value'

        // Set the brush to the determined color with transparency and draw the overlay
        painter->setBrush(overlayColor);
        painter->setPen(Qt::NoPen); // No border for the overlay
        painter->drawRect(boundingRect());
    }else{
        qDebug() << "TileGraphicsItem::paint() - tileModel is null";
    }

}



