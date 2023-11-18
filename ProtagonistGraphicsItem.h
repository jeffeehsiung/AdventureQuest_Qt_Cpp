#ifndef PROTAGONISTGRAPHICSITEM_H
#define PROTAGONISTGRAPHICSITEM_H

#include "EntityGraphicsItem.h"
#include "ProtagonistModel.h"

class ProtagonistGraphicsItem : public EntityGraphicsItem {
public:
    ProtagonistGraphicsItem(ProtagonistModel* protagonistModel, QGraphicsItem* parent = nullptr);
};

#endif // PROTAGONISTGRAPHICSITEM_H
