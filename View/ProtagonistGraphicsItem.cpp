#include "ProtagonistGraphicsItem.h"

// Initialize static members for animation directories
QString EntityGraphicsItem::baseFramesDir = "images/protagonist_fighter/";
QString EntityGraphicsItem::idleDir = baseFramesDir + "Idle";
QString EntityGraphicsItem::moveDir = baseFramesDir + "Moving";
QString EntityGraphicsItem::hurtDir = baseFramesDir + "Hurt";
QString EntityGraphicsItem::dyingDir = baseFramesDir + "Dying";
QString EntityGraphicsItem::attackDir = baseFramesDir + "Attack";
QString EntityGraphicsItem::healDir = baseFramesDir + "Heal";

ProtagonistGraphicsItem::ProtagonistGraphicsItem(ProtagonistModel* protagonistModel, QGraphicsItem* parent)
    : EntityGraphicsItem(protagonistModel, baseFramesDir, idleDir, moveDir, hurtDir, dyingDir, attackDir, healDir, parent) {
    // Constructor implementation...
}
