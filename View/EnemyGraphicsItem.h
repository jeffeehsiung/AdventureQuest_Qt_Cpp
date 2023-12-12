#ifndef ENEMYGRAPHICSITEM_H
#define ENEMYGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "Model/EnemyModel.h"

class EnemyGraphicsItem : public EntityGraphicsItem {
public:
    EnemyGraphicsItem(const EnemyModel& enemyModel, const QString& baseFramesDir, QGraphicsRectItem* parent = nullptr);

private:
    QString baseFramesDir;
    void loadAnimationFrames();
    void loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames);

};

class PEnemyGraphicsItem : public EntityGraphicsItem {
public:
    PEnemyGraphicsItem(const PEnemyModel& penemyModel, const QString& baseFramesDir, QGraphicsRectItem* parent = nullptr);

private:
    QString baseFramesDir;
    void loadAnimationFrames();
    void loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames);

};

#endif // ENEMYGRAPHICSITEM_H
