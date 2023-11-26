// EnemyGraphicsItem.cpp

#include "EnemyGraphicsItem.h"

// Initialize static members
QString EntityGraphicsItem::baseFramesDir = "images/enemy_golem/PNG Sequences/";
QString EntityGraphicsItem::idleDir = baseFramesDir + "Idle";
QString EntityGraphicsItem::moveDir = baseFramesDir + "Moving";
QString EntityGraphicsItem::hurtDir = baseFramesDir + "Hurt";
QString EntityGraphicsItem::dyingDir = baseFramesDir + "Dying";
QString EntityGraphicsItem::attackDir = baseFramesDir + "Attack";
QString EntityGraphicsItem::healDir = baseFramesDir + "Heal";

EnemyGraphicsItem::EnemyGraphicsItem(EnemyModel* enemyModel, QGraphicsItem* parent)
    : EntityGraphicsItem(enemyModel, baseFramesDir, idleDir, moveDir, hurtDir, dyingDir, attackDir, healDir, parent) {
    // Constructor implementation...
}
