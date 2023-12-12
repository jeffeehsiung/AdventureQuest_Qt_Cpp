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
#include <QDebug>

class WorldController : public QObject
{
    Q_OBJECT

    public:
        static WorldController& getInstance() {
            static WorldController instance;
            return instance;
        }

        WorldController(WorldController const&) = delete;
        void operator=(WorldController const&) = delete;

        void createWorld(QString map, int gameNumberOfPlayers, int gameDifficultyIdx, float pRatio);

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
        const std::vector<std::unique_ptr<TileModel>>& getTiles() const;
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
        void setAffectedTiles(coordinate, int spread, std::unique_ptr<PEnemyModel> pEnemy);

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

        void onUpArrowPressed();
        void onDownArrowPressed();
        void onLeftArrowPressed();
        void onRightArrowPressed();

        void onEncounterEnemy();
        void onEncounterHealthPack();
        void onEncounterPEnemy();

signals:
        void protagonistPositionChanged(int protagonistIndex);

private:
        WorldController();
        std::unique_ptr<World> world;
        int rows;
        int cols;
        int difficultyIdx;
        coordinate exit = coordinate(1,1);
        coordinate start = coordinate(0,0);
        std::vector<std::unique_ptr<TileModel>> tiles;
        std::vector<std::unique_ptr<TileModel>> healthPacks;
        std::vector<std::unique_ptr<TileModel>> walkedOnTiles;
        std::vector<std::unique_ptr<EnemyModel>> enemies;
        std::vector<std::unique_ptr<PEnemyModel>> penemies;
//        std::vector<std::unique_ptr<XEnemyModel>> xenemies;
        std::vector<std::unique_ptr<ProtagonistModel>> protagonists;

        // current (p)enemy, protagonist, hp
        ProtagonistModel* currentProtagonist;
        EnemyModel* currentEnemy;
        PEnemyModel* currentPEnemy;
//        XEnemyModel* currentXEnemy;
        TileModel* currentHealthpack;

};

#endif // WORLDCONTROLLER_H
