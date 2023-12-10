#ifndef TILEGRAPHICSITEM_H
#define TILEGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include "EntityGraphicsItem.h"
#include "Model/TileModel.h"

// the naming should be changed to TileGraphicsItem

class TileGraphicsItem : public EntityGraphicsItem {
public:
    TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent = nullptr);

    // Implement any Tile-specific functionality or behavior here, if needed
    // Override the paint method
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
private:
    QString baseFramesDir;
};

#endif // TILEGRAPHICSITEM_H
