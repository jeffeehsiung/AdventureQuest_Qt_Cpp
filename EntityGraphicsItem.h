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

    // Default implementation of boundingRect() based on the image size
    QRectF boundingRect() const override {
        return QRectF(0, 0, image.width(), image.height());
    }

    // Default implementation of paint() that draws the image
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(option)
        Q_UNUSED(widget)
        painter->drawPixmap(0, 0, image);
    }
};

#endif // ENTITYGRAPHICSITEM_H
