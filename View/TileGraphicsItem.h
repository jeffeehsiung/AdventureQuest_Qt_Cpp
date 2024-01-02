#ifndef TILEGRAPHICSITEM_H
#define TILEGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QDebug>
#include <QDir>
#include "EntityGraphicsItem.h"
#include "Model/TileModel.h"

// the naming should be changed to TileGraphicsItem

class TileGraphicsItem : public EntityGraphicsItem, public TileObserver {
public:
    TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent = nullptr);

    // Implement any Tile-specific functionality or behavior here, if needed
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void nextFrame() override;

    // Implement the tile observer
    void onTileChanged() override;

private:
    const TileModel& tileModel;
    QString baseFramesDir;
    QPixmap backgroundImage;
    void loadAnimationFrames();
    void loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames);
};

#endif // TILEGRAPHICSITEM_H

