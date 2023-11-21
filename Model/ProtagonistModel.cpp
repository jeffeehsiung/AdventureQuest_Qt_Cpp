#include "ProtagonistModel.h"

ProtagonistModel::ProtagonistModel(Protagonist* protagonist) : protagonist(protagonist) {}

void ProtagonistModel::attack() {
    // Protagonist's attack implementation
}

void ProtagonistModel::takeDamage(int damage) {
    // Protagonist's take damage implementation
}

coordinate ProtagonistModel::getPosition() const {
    return {protagonist->getXPos(), protagonist->getYPos()};
}

void ProtagonistModel::setPosition(coordinate position) {
    protagonist->setXPos(position.xCoordinate);
    protagonist->setYPos(position.yCoordinate);
}

void ProtagonistModel::move(int deltaX, int deltaY) {
    protagonist->setXPos(protagonist->getXPos() + deltaX);
    protagonist->setYPos(protagonist->getYPos() + deltaY);
}
