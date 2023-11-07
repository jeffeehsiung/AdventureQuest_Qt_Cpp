// ../headers/Tile.h
#ifndef TILE_H
#define TILE_H

#include "world_global.h"
#include <QGraphicsItem>

class WORLDSHARED_EXPORT TileGraphicsItem : public QGraphicsItem {
public:
    explicit TileGraphicsItem(int x, int y, float value, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int xPos;
    int yPos;
    float value;
};

#endif // TILE_H
