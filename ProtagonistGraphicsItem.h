#ifndef PROTAGONISTGRAPHICSITEM_H
#define PROTAGONISTGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "ProtagonistModel.h"

class ProtagonistGraphicsItem : public EntityGraphicsItem {
public:
    ProtagonistGraphicsItem(ProtagonistModel* protagonistModel, QGraphicsItem* parent = nullptr);
    // You can add more functionality specific to the protagonist here if needed
};

#endif // PROTAGONISTGRAPHICSITEM_H
