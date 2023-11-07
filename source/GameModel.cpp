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
    // You may emit signals or perform additional initialization here.
}
