#include "ProtagonistGraphicsItem.h"

ProtagonistGraphicsItem::ProtagonistGraphicsItem(ProtagonistModel* protagonistModel, QGraphicsItem* parent)
    : EntityGraphicsItem(protagonistModel, ":/images/protagonist.png", parent) {
    // Initialization specific to the protagonist can be added here
}
