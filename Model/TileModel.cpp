#include "TileModel.h"

// Constructor
TileModel::TileModel(std::unique_ptr<Tile> tile)
    : tile(std::move(tile)) {}

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
