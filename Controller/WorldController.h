#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "Model/structs.h"
#include "Model/WorldModel.h"
//#include "pathfinder_class.h"

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

        int getNumOfProtagonists() const;
        int getDifficultyIdx() const;

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

        const std::vector<std::unique_ptr<WorldModel>>& getWorlds() const;
        const WorldModel& getCurrentWorld() const;

        void onUpArrowPressed();
        void onDownArrowPressed();
        void onLeftArrowPressed();
        void onRightArrowPressed();
//        void autoplay();

        void onEncounterHealthPack();
        void onEncounterEnemy();
        void onEncounterPEnemy();
        void onEncounterXEnemy();
        void onEncounterAffectedTiles();

    signals:
        void updateprotagonistPosition(int protagonistIndex);
        void updateLevel();

    private:
        WorldController();
        std::vector<std::unique_ptr<WorldModel>> worlds;
        std::unique_ptr<WorldModel> currentWorld; // Changed to unique_ptr
        int difficultyIdx;
        coordinate exit = coordinate(5,5);
        coordinate start = coordinate(0,0);

};

#endif // WORLDCONTROLLER_H
