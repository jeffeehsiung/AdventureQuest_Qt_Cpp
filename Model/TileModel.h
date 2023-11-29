#ifndef TILEMODEL_H
#define TILEMODEL_H

#include "Entity.h"
#include "world.h"

class TileModel : public Entity {
public:
    /** TileModel is a model wrapper for Tile and HealthPack
     *  to be used in TileGraphicsItem
    **/
    TileModel(std::unique_ptr<Tile> tile) : tile(std::move(tile)) {}
    void attack() override;
    void takeDamage(float damage) override{}
    void setPosition(coordinate position) override{}
    void move(int deltaX, int deltaY) override{}
    float getHealth() const{}
    void setHealth(float newHealth){}
    inline coordinate getPosition() const override{
        return coordinate(tile->getXPos(), tile->getYPos());
    }

private:
    std::unique_ptr<Tile> tile;
};

#endif // TILEMODEL_H
