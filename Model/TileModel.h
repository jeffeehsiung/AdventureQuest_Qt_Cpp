#ifndef TILEMODEL_H
#define TILEMODEL_H

#include "Entity.h"
#include <memory>

class TileModel : public Entity {
public:
    /** TileModel is a model wrapper for Tile and HealthPack
     *  to be used in TileGraphicsItem
    **/
    TileModel(std::unique_ptr<Tile> tile) : tile(std::move(tile)) {
    }
    
    // Functions to expose Tile functionality
    void setPosition(coordinate position) override;
    coordinate getPosition() const override;
    float getValue() const;
    void setValue(float value);
    std::string serialize() const;
    void attack() override;
    void takeDamage(float strength) override;

    // Functions specific to tile
    inline bool isPoisoned() const { return poisoned; }
    inline float getPoisonStrength() const { return poisonStrength; }

    // Functions unused by TileModel
    void move(int deltaX, int deltaY) override{}

private:
    std::unique_ptr<Tile> tile;
    bool poisoned {false};
    float poisonStrength {0.0f};
};

#endif // TILEMODEL_H
