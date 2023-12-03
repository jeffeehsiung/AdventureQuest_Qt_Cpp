#ifndef TILEMODEL_H
#define TILEMODEL_H

#include "Entity.h"
#include "world.h"
#include <memory>

class TileModel : public Entity {
public:
    /** TileModel is a model wrapper for Tile and HealthPack
     *  to be used in TileGraphicsItem
    **/
    TileModel(std::unique_ptr<Tile> tile) : tile(std::move(tile)) {}
    
    // Functions to expose Tile functionality
    void setPosition(coordinate position) override;
    coordinate getPosition() const override;
    float getValue() const;
    void setValue(float value);
    std::string serialize() const;

    // Functions unused by TileModel
    void attack() override{}
    void takeDamage(float damage) override{}
    void move(int deltaX, int deltaY) override{}

private:
    std::unique_ptr<Tile> tile;
};

#endif // TILEMODEL_H
