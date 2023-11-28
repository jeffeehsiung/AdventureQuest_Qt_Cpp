#ifndef ENTITYTEXTITEM_H
#define ENTITYTEXTITEM_H

#include <QGraphicsTextItem>
#include <QString>
#include "Model/Entity.h"

class EntityTextItem : public QGraphicsTextItem {
protected:
    const Entity& entity;  // Pointer to the entity model

public:
    explicit EntityTextItem(const Entity& entity, QGraphicsItem* parent = nullptr)
        : QGraphicsTextItem(parent), entity(entity) {}

    // Virtual destructor for dynamic binding
    virtual ~EntityTextItem() {}

    /**
     * The follwing methods are virtual and will be dynamically bound at runtime
    */

    // These methods are virtual and will be dynamically bound at runtime
    QRectF boundingRect() const override {
        return QRectF(0, 0, 0, 0);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(painter);
        Q_UNUSED(option);
        Q_UNUSED(widget);
    }
};

#endif
