#ifndef WORLDMODEL_H
#define WORLDMODEL_H
#include "world.h"
#include "Model/structs.h"
#include "Model/TileModel.h"
#include "Model/EnemyModel.h"
#include "Model/ProtagonistModel.h"
#include <memory>
#include <QString>

class WorldModel{
public:
    WorldModel(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio, bool firstWorld);
    int getRows() const;
    int getCols() const;

    void addProtagonist(std::vector<std::unique_ptr<ProtagonistModel>>);
    std::vector<std::unique_ptr<ProtagonistModel>> removeProtagonists();

    /**
         * get single entity functions
        */
    std::unique_ptr<TileModel>& getTileModelAt(int x, int y);
    /**
         * get vector of entities functions
         */
    const std::map<coordinate, std::unique_ptr<TileModel>>& getTileMap() const;
    const std::vector<std::unique_ptr<TileModel>>& getHealthPacks() const;
    const std::vector<std::unique_ptr<EnemyModel>>& getEnemies() const;
    const std::vector<std::unique_ptr<PEnemyModel>>& getPEnemies() const;
    //      const std::vector<std::unique_ptr<XEnemyModel>> getXEnemies() const;
    const std::vector<std::unique_ptr<ProtagonistModel>>& getProtagonists() const;

    /**
         * type of tiles check
         */
    bool isHealthPack(coordinate);
    bool isPoisonedTiles(coordinate);
    /**
         * type of enemy check
         */
    bool isEnemy(coordinate);
    bool isPEnemy(coordinate);
    bool isXEnemy(coordinate);

    int getNumOfProtagonists() const;
    int getDifficultyIdx() const;

    /**
         * PEnemy poisened tiles
         */
    void setAffectedTiles(coordinate coord, float poisonLevel);

    /**
         * defeated functions
         */

    void deleteEnemy(coordinate);
    void deletePsnTile(coordinate);

    /**
         * healthpack functions
         */
    void removeHealthpack(coordinate);

    /**
         * start and exit position functions
         */

    coordinate getStart();
    coordinate getExit();
    coordinate* getStartValue();
    coordinate* getExitValue();
    std::vector<std::unique_ptr<ProtagonistModel>> protagonists;
    std::vector<node> nodes;
    ProtagonistModel* currentProtagonist;
    EnemyModel* currentEnemy;
    PEnemyModel* currentPEnemy;
    //        XEnemyModel* currentXEnemy;
    TileModel* currentHealthpack;


private:

    std::unique_ptr<World> world;
    int rows;
    int cols;
    int difficultyIdx;
    coordinate exit = coordinate(2,2);
    coordinate start = coordinate(0,0);
    std::map<coordinate, std::unique_ptr<TileModel>> tileMap;
    std::vector<std::unique_ptr<TileModel>> healthPacks;
    std::vector<std::unique_ptr<EnemyModel>> enemies;
    std::vector<std::unique_ptr<PEnemyModel>> penemies;
    //std::vector<std::unique_ptr<XEnemyModel>> xenemies;



};

#endif // WORLDMODEL_H