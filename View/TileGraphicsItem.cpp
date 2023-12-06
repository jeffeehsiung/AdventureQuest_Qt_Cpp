#include "TileGraphicsItem.h"
#include <QDir>

// the naming should be changed to TileGraphicsItem

TileGraphicsItem::TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent)
    : EntityGraphicsItem(tileModel, parent), baseFramesDir(baseFramesDir)  {
}

QRectF TileGraphicsItem::boundingRect() const {
    return QRectF(0, 0, tileWidth, tileHeight);
}


void TileGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    // Call the base class paint method to draw the base image if needed.
    // If the tiles are meant to be transparent, showing only the shades of green, then the base image paint call can be omitted.
    // EntityGraphicsItem::paint(painter, option, widget);

    // Handle TileModel specific painting for the overlay
    const TileModel* tileModel = dynamic_cast<const TileModel*>(&getEntity());
    if (tileModel) {
        int value = tileModel->getValue();

        // Assuming value is between 0 and some maximum value, map it to an alpha value between 0 and 255.
        // The maximum value here should be the maximum possible value of your tiles.
        const int maxValue = 255 * 1; // Replace with your maximum tile value if different
        int alpha = static_cast<int>((static_cast<double>(value) / maxValue) * 255);

        // Create a green color with the calculated alpha for transparency
        QColor overlayColor(0, 255, 0, alpha); // Semi-transparent green based on 'value'

        // Set the brush to the overlay color with transparency and no pen for border
        painter->setBrush(overlayColor);
        painter->setPen(Qt::NoPen);

        // Draw a rectangle over the base image using the overlay color
        painter->drawRect(boundingRect());

    } else {
        qDebug() << "TileGraphicsItem::paint dynamic cast failed. Not a TileModel type.";
    }
}





