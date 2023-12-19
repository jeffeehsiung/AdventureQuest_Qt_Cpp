#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "Model/structs.h"
//#include "Model/ProtagonistModel.h"
//#include "Model/EnemyModel.h"
//#include "Model/TileModel.h"
#include "Model/WorldModel.h"
#include "pathfinder.h"

#include <iostream>
#include <map>
#include <QObject>
#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
#include <random>

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

        void playerReachedExit();

        /**
         * healthpack functions
         */
        void removeHealthpack(coordinate);

        /**
         * start and exit position functions
         */
        coordinate getStart();
        coordinate getExit();

        std::vector<std::shared_ptr<WorldModel>> getWorlds();
        std::shared_ptr<WorldModel> getCurrentWorld();

        void onUpArrowPressed();
        void onDownArrowPressed();
        void onLeftArrowPressed();
        void onRightArrowPressed();
        void autoplay();

        void onEncounterEnemy();
        void onEncounterHealthPack();
        void onEncounterPEnemy();

signals:
        void updateprotagonistPosition(int protagonistIndex);
        void updateLevel();

    private:
        WorldController();
        std::vector<std::unique_ptr<WorldModel>> worlds;
        std::unique_ptr<WorldModel> currentWorld;
        int difficultyIdx;
        coordinate exit = coordinate(5,5);
        coordinate start = coordinate(0,0);
        std::vector<std::unique_ptr<TileModel>> healthPacks;
        std::vector<std::unique_ptr<EnemyModel>> enemies;
        std::vector<std::unique_ptr<PEnemyModel>> penemies;
//        std::vector<std::unique_ptr<XEnemyModel>> xenemies;
        std::vector<std::unique_ptr<ProtagonistModel>> protagonists;

        // current (p)enemy, protagonist, hp

};

#endif // WORLDCONTROLLER_H
