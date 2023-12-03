#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "Model/world.h"
#include "Model/structs.h"
#include "Model/Entity.h"
#include "Model/ProtagonistModel.h"
#include "Model/EnemyModel.h"
#include "Model/TileModel.h"


#include <iostream>
#include <QObject>
#include <QMainWindow>

class WorldController : public QObject
{
    Q_OBJECT

    public:
        WorldController(QString map, int nrOfEnemies, int gameDifficultyIdx, float pRatio);

        int getRows() const;
        int getCols() const;

        void addProtagonist(ProtagonistModel&);
        void removeProtagonist(ProtagonistModel&);

        /**
         * get single entity functions
        */

        /**
         * get vector of entities functions
         */
        std::vector<std::unique_ptr<TileModel>> getTiles() const;
        std::vector<std::unique_ptr<TileModel>> getHealthPacks() const;
        std::vector<std::unique_ptr<EnemyModel>> getEnemies() const;
        std::vector<std::unique_ptr<PEnemyModel>> getPEnemies() const;
        std::vector<std::unique_ptr<XEnemyModel>> getXEnemies() const;
        std::array<std::unique_ptr<ProtagonistModel>,2> getProtagonists() const;

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

        /**
         * PEnemy poisened tiles
         */
        void setAffectedTiles(coordinate, int spread, std::unique_ptr<PEnemy> pEnemy);

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

        /**
         * Path: walked path getter and setter
         * TODO: missing setter
         */
        const std::vector<std::unique_ptr<TileModel> > &getWalkedOnTiles() const;
private:
        std::unique_ptr<World> world;
        const int rows;
        const int cols;
        const int gameDifficultyIdx;
        coordinate exit = coordinate(1,1);
        coordinate start = coordinate(0,0);
        std::vector<std::unique_ptr<TileModel>> tiles;
        std::vector<std::unique_ptr<TileModel>> healthPacks;
        std::vector<std::unique_ptr<TileModel>> walkedOnTiles;
        std::vector<std::unique_ptr<EnemyModel>> enemies;
        std::vector<std::unique_ptr<PEnemyModel>> penemies;
        std::vector<std::unique_ptr<XEnemyModel>> xenemies;
        std::array<std::unique_ptr<ProtagonistModel>,2> protagonists;

};

#endif // WORLDCONTROLLER_H
