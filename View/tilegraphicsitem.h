#ifndef TILEGRAPHICSITEM_H
#define TILEGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include "EntityGraphicsItem.h"
#include "Model/TileModel.h"

class TileGraphicsItem : public EntityGraphicsItem {
public:
    TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent = nullptr);

    // Implement any Tile-specific functionality or behavior here, if needed
private:
    QString baseFramesDir;
    void loadAnimationFrames();
    void loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames);
};

#endif // TILEGRAPHICSITEM_H
