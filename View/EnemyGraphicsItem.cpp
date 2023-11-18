#include "EnemyGraphicsItem.h"

EnemyGraphicsItem::EnemyGraphicsItem(EnemyModel* enemyModel, QGraphicsItem* parent)
    : EntityGraphicsItem(enemyModel, ":/images/enemy.png", parent) {
    // Initialization specific to the enemy can be added here
}
