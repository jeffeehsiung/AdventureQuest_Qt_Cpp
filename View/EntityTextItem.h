// EntityTextItem.h
#ifndef ENTITYTEXTITEM_H
#define ENTITYTEXTITEM_H

#include <QString>
#include "Model/Entity.h"
#include "Model/TileModel.h"
#include "Model/ProtagonistModel.h"
#include "Model/EnemyModel.h"

class EntityTextItem {
public:
    EntityTextItem(const Entity& entity) : entity(entity) {
        // Default representation for a generic entity
        textRepresentation = "?";
    }

    virtual ~EntityTextItem() {}

    virtual QString getTextRepresentation() const {
        return textRepresentation;
    }

    coordinate getPosition() const {
        return entity.getPosition();
    }

    void setIndex(int newIndex) {
        index = newIndex;
    }

    int getIndex() const {
        return index;
    }

protected:
    const Entity& entity; // Presuming Entity has position and other relevant attributes
    QString textRepresentation;

private:
    int index; // Stores the index position within the grid
};

#endif // ENTITYTEXTITEM_H

// TileTextItem.h
#ifndef TILETEXTITEM_H
#define TILETEXTITEM_H

#include "EntityTextItem.h"
#include "Model/TileModel.h" // Include your TileModel class definition

class TileTextItem : public EntityTextItem {
public:
    TileTextItem(const TileModel& tile) : EntityTextItem(tile), status(IDLE) {
        // Set a text representation specific to tiles
        updateTextRepresentation();
    }
    void setState(state newState) {
        status = newState;
        updateTextRepresentation();
    }

    state getState() const {
        return status;
    }

    void updateTextRepresentation() {
        switch (status) {
        case IDLE:
            textRepresentation = " ";  // Normal tile
            break;
        case ATTACK:
            textRepresentation = "Ω";  // Poisoned tile
            break;
        case HURT:
            textRepresentation = "∫";  // Thundered tile
            break;
        }
    }

private:
    state status;
};

#endif // TILETEXTITEM_H

// TileTextItem.h
#ifndef HEALTHPACKTEXTITEM_H
#define HEALTHPACKTEXTITEM_H

#include "EntityTextItem.h"
#include "Model/TileModel.h" // Include your TileModel class definition

class HPTextItem : public EntityTextItem {
public:
    HPTextItem(const TileModel& hp) : EntityTextItem(hp) {
        // Set a text representation specific to tiles
        textRepresentation = "H";
    }

    QString getTextRepresentation() const {
        return textRepresentation;
    }
};

#endif // HEALTHPACKTEXTITEM_H

// EnemyTextItem.h
#ifndef ENEMYTEXTITEM_H
#define ENEMYTEXTITEM_H

#include "EntityTextItem.h"
#include "Model/EnemyModel.h" // Include your EnemyModel class definition

class EnemyTextItem : public EntityTextItem {
public:
    EnemyTextItem(const EnemyModel& enemy) : EntityTextItem(enemy) {
        // Set a text representation specific to enemies
        textRepresentation = "E";
    }
    QString getTextRepresentation() const {
        return textRepresentation;
    }
};

class PEnemyTextItem : public EntityTextItem {
public:
    PEnemyTextItem(const PEnemyModel& penemy) : EntityTextItem(penemy) {
        // Set a text representation specific to enemies
        textRepresentation = "@";
    }
    QString getTextRepresentation() const {
        return textRepresentation;
    }
};

class XEnemyTextItem : public EntityTextItem {
public:
    XEnemyTextItem(const XEnemyModel& xenemy) : EntityTextItem(xenemy) {
        // Set a text representation specific to enemies
        textRepresentation = "X";
    }
    QString getTextRepresentation() const {
        return textRepresentation;
    }
};

#endif // ENEMYTEXTITEM_H

// ProtagonistTextItem.h
#ifndef PROTAGONISTTEXTITEM_H
#define PROTAGONISTTEXTITEM_H

#include "EntityTextItem.h"
#include "Model/ProtagonistModel.h" // Include your ProtagonistModel class definition

class ProtagonistTextItem : public EntityTextItem {
public:
    ProtagonistTextItem(const ProtagonistModel& protagonist) : EntityTextItem(protagonist) {
        // Set a text representation specific to protagonists
        textRepresentation = "P";
    }
    QString getTextRepresentation() const {
        return textRepresentation;
    }
};

#endif // PROTAGONISTTEXTITEM_H
