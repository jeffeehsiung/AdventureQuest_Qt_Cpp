#ifndef ENTITYGRAPHICSITEM_H
#define ENTITYGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPixmap>
#include "Entity.h"

class EntityGraphicsItem : public QGraphicsItem {
protected:
    Entity* entity;  // Pointer to the entity model
    QPixmap image;   // Image representing the entity

public:
    explicit EntityGraphicsItem(Entity* entity, const QString& imagePath, QGraphicsItem* parent = nullptr)
        : QGraphicsItem(parent), entity(entity), image(imagePath) {}

    // Virtual destructor for dynamic binding
    virtual ~EntityGraphicsItem() {}

    /**
     * The follwing methods are virtual and will be dynamically bound at runtime
    */

    // These methods are virtual and will be dynamically bound at runtime
    QRectF boundingRect() const override {
        return QRectF(0, 0, image.width(), image.height());
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->drawPixmap(0, 0, image);
    }
};

#endif // ENTITYGRAPHICSITEM_H
