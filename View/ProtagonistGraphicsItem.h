#ifndef PROTAGONISTGRAPHICSITEM_H
#define PROTAGONISTGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "Model/ProtagonistModel.h"

class ProtagonistGraphicsItem : public EntityGraphicsItem {
public:
    ProtagonistGraphicsItem(ProtagonistModel* protagonistModel, const QString& imagePath, const QString& idleFramesDir = "images/protagonist_fighter/Idle",
                            const QString& hurtFramesDir = "images/protagonist_fighter/Hurt", const QString& dyingFramesDir = "images/protagonist_fighter/Dying",
                            const QString& attackFramesDir = "images/protagonist_fighter/Attack", const QString& healFramesDir = "images/protagonist_fighter/Heal",
                            QGraphicsItem* parent= nullptr)
        : EntityGraphicsItem(protagonistModel, imagePath, idleFramesDir, hurtFramesDir, dyingFramesDir, attackFramesDir, healFramesDir, parent) {
        // Implement derived class specific methods that should override base class.
    }
};

#endif // PROTAGONISTGRAPHICSITEM_H
