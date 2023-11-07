// GameModel.cpp
#include "GameModel.h"

GameModel::GameModel(QObject *parent) : QObject(parent) {
    // Initialize your game model here.
}

GameModel::~GameModel() {
    // Clean up your game model here if needed.
}

void GameModel::createWorld(const QString& filename, unsigned int nrOfEnemies, unsigned int nrOfHealthpacks, float pRatio) {
    myWorld.createWorld(filename, nrOfEnemies, nrOfHealthpacks, pRatio);

    // Load the image
    QPixmap pixmap(filename);

    // Create a QGraphicsPixmapItem with the QPixmap
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

    // Add the QGraphicsPixmapItem to the QGraphicsScene
    scene->addItem(item);


}
