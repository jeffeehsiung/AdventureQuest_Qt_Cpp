#ifndef ENEMYGRAPHICSITEM_H
#define ENEMYGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "EnemyModel.h"

class EnemyGraphicsItem : public EntityGraphicsItem {
public:
    EnemyGraphicsItem(EnemyModel* enemyModel, QGraphicsItem* parent = nullptr);
    // You can add more functionality specific to the enemy here if needed
};

#endif // ENEMYGRAPHICSITEM_H
