// WorldModel.cpp
#include "WorldModel.h"

WorldModel::WorldModel(QObject *parent) : QObject(parent) {
    // Initialize your World model here.
}

WorldModel::~WorldModel() {
    // Clean up your World model here if needed.
}

void WorldModel::createWorld(const QString& filename, unsigned int nrOfEnemies, unsigned int nrOfHealthpacks, float pRatio) {
    myWorld.createWorld(filename, nrOfEnemies, nrOfHealthpacks, pRatio);

    // Load the image
    QPixmap pixmap(filename);

    // Create a QGraphicsPixmapItem with the QPixmap
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

    // Add the QGraphicsPixmapItem to the QGraphicsScene
    scene->addItem(item);


}
