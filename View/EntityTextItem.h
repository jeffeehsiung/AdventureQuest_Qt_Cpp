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
    EntityTextItem(const Entity& entity) : entity(entity)/*, defaultTextRepresentation("?")*/ {
        // Default representation for a generic entity
        textRepresentation = "?";
//        updateTextRepresentation();
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

//    void updateTextRepresentation() {
//        // Assuming Entity has a method getStatus to get the entity's current status
//        const state entityState = entity.getState();
//        QString color;
//        switch (entityState) {
//            case IDLE: color = "black"; break;
//            case ATTACK: color = "blue"; break;
//            case HURT: color = "red"; break;
//            case MOVING: color = "purple"; break;
//            case DYING: color = "grey"; break;
//        }
//        textRepresentation = QString("<font color='%1'>%2</font>").arg(color, defaultTextRepresentation);
//    }

protected:
    const Entity& entity; // Presuming Entity has position and other relevant attributes
//    QString defaultTextRepresentation;
    QString textRepresentation;

private:
    int index; // Stores the index position within the grid
};


class TileTextItem : public EntityTextItem {
public:
    TileTextItem(const TileModel& tile) : EntityTextItem(tile)/*, status(IDLE)*/ {
        // Set a text representation specific to tiles
//        defaultTextRepresentation = "°";
        updateTextRepresentation();
    }

    void updateTextRepresentation() {
        const state entityState = entity.getState();
        switch (entityState) {
        case IDLE:
        case DYING:
        case HEAL:
            textRepresentation = "°";  // Normal tile
            break;
        case ATTACK:
            textRepresentation = "Ω";  // Poisoned tile
            break;
        case HURT:
            textRepresentation = "V";  // Thundered tile
            break;
        case MOVING:
            textRepresentation = "*";  // Thundered tile
            break;
        }
    }

};


class HPTextItem : public EntityTextItem {
public:
    HPTextItem(const TileModel& hp) : EntityTextItem(hp) {
        // Set a text representation specific to tiles
        textRepresentation = "H";
//        defaultTextRepresentation = "H";
    }

};

class EnemyTextItem : public EntityTextItem {
public:
    EnemyTextItem(const EnemyModel& enemy) : EntityTextItem(enemy) {
        // Set a text representation specific to enemies
        textRepresentation = "E";
//        defaultTextRepresentation = "E";
    }
};

class PEnemyTextItem : public EntityTextItem {
public:
    PEnemyTextItem(const PEnemyModel& penemy) : EntityTextItem(penemy) {
        // Set a text representation specific to enemies
        textRepresentation = "θ";
//        defaultTextRepresentation = "θ";
    }
};

class XEnemyTextItem : public EntityTextItem {
public:
    XEnemyTextItem(const XEnemyModel& xenemy) : EntityTextItem(xenemy) {
        // Set a text representation specific to enemies
        textRepresentation = "X";
//        defaultTextRepresentation = "X";
    }
};


class ProtagonistTextItem : public EntityTextItem {
public:
    ProtagonistTextItem(const ProtagonistModel& protagonist) : EntityTextItem(protagonist) {
        // Set a text representation specific to protagonists
        textRepresentation = "P";
//        defaultTextRepresentation = "P";
    }
};

#endif // ENTITYTEXTITEM_H
