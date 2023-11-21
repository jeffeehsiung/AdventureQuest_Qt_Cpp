#ifndef ENEMYGRAPHICSITEM_H
#define ENEMYGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "Model/EnemyModel.h"

class EnemyGraphicsItem : public EntityGraphicsItem {
public:
    EnemyGraphicsItem(EnemyModel* enemyModel, QGraphicsItem* parent = nullptr);
};

#endif // ENEMYGRAPHICSITEM_H
