#include "Entity.h"
#include "world.h"

class TileModel : public Entity {
public:
    /** TileModel is a model wrapper for Tile and HealthPack
     *  to be used in TileGraphicsItem
    **/
    TileModel(std::unique_ptr<Tile> tile) : tile(std::move(tile)) {}

    inline coordinate getPosition() const override{
        return coordinate(tile->getXPos(), tile->getYPos());
    }

private:
    std::unique_ptr<Tile> tile;
};
