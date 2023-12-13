#include "TileModel.h"

// Get the position of the tile
coordinate TileModel::getPosition() const {
    return coordinate(tile->getXPos(), tile->getYPos());
}

// Set the position of the tile
void TileModel::setPosition(coordinate position) {
    tile->setXPos(position.xCoordinate);
    tile->setYPos(position.yCoordinate);
}

// Get the value of the tile
float TileModel::getValue() const {
    return tile->getValue();
}

// Set the value of the tile
void TileModel::setValue(float value) {
    tile->setValue(value);
}

// Serialize the tile data
std::string TileModel::serialize() const {
    return tile->serialize();
}

void TileModel::attack() {
    // tile is affected by penemy hence is poisoned
    status = ATTACK;
}
void TileModel::takeDamage(float strength) {
    poisoned = true;
    // set the poison strength
    poisonStrength = strength;
    attack();
}
