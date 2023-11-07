// Tile.cpp
#include "../headers/Tile.h"
#include <QPainter>

TileGraphicsItem::TileGraphicsItem(int x, int y, float value, QGraphicsItem *parent)
    : QGraphicsItem(parent), xPos(x), yPos(y), value(value) {
}

QRectF TileGraphicsItem::boundingRect() const {
    return QRectF(0, 0, 50, 50); // Replace 50x50 with your actual tile size
}

void TileGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // Placeholder code: Replace with the actual logic for visualizing the tile.
    painter->setBrush(Qt::green); // Example color based on tile value
    painter->drawRect(boundingRect());
}
