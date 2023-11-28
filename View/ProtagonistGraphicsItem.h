#ifndef PROTAGONISTGRAPHICSITEM_H
#define PROTAGONISTGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "Model/ProtagonistModel.h"
#include <QString>

class ProtagonistGraphicsItem : public EntityGraphicsItem {
public:
    ProtagonistGraphicsItem(ProtagonistModel* protagonistModel, const QString& baseFramesDir, QGraphicsItem* parent = nullptr);

private:
    QString baseFramesDir;
    void loadAnimationFrames();
    void loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames);

};

#endif // PROTAGONISTGRAPHICSITEM_H
