#include "EnemyGraphicsItem.h"

EnemyGraphicsItem::EnemyGraphicsItem(EnemyModel* enemyModel, QGraphicsItem* parent)
    : EntityGraphicsItem(enemyModel, ":/images/enemy_golem/idle/Golem_01_Idle_000.png", parent) {
    // Initialization specific to the enemy can be added here
}
