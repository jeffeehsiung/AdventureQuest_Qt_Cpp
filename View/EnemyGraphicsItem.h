#ifndef ENEMYGRAPHICSITEM_H
#define ENEMYGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "Model/EnemyModel.h"

class EnemyGraphicsItem : public EntityGraphicsItem {
public:
    // EnemyGraphicsItem(EnemyModel* enemyModel, const QString& imagePath, const QString& idleFramesDir = "images/enemy_golem/PNG Sequences/Idle", const QString& hurtFramesDir = "images/enemy_golem/PNG Sequences/Hurt",
    //                   const QString& dyingFramesDir = "images/enemy_golem/PNG Sequences/Dying", const QString& attackFramesDir = "images/enemy_golem/PNG Sequences/Attack",
    //                   const QString& healFramesDir = "images/enemy_golem/PNG Sequences/Idle Blink", QGraphicsItem* parent = nullptr)
    //     : EntityGraphicsItem(enemyModel, imagePath, idleFramesDir, hurtFramesDir, dyingFramesDir, attackFramesDir, healFramesDir, parent){

    // }
    EnemyGraphicsItem(EnemyModel* enemyModel, QGraphicsItem* parent = nullptr);
};

#endif // ENEMYGRAPHICSITEM_H
