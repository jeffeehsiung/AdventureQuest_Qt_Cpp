#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "Model/structs.h"
#include "Model/WorldModel.h"
// #include "pathfinder.h"
#include <QEventLoop>
#include <QTimer>
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

    const std::vector<std::unique_ptr<WorldModel>>& getWorlds() const;
    const WorldModel& getCurrentWorld() const;


    void onUpArrowPressed();
    void onDownArrowPressed();
    void onLeftArrowPressed();
    void onRightArrowPressed();
    void autoplay();

    void moveProtagonist(Direction direction);
    void moveProtagonist(coordinate coord);
    void moveProtagonistWithDelay(Direction direction);

signals:
    void updateprotagonistPosition(int protagonistIndex);
    void updateLevel();

private:
    WorldController();

    std::vector<std::unique_ptr<WorldModel>> worlds;
//    std::shared_ptr<WorldModel> currentWorld; // Changed to std::shared_ptr
//    std::unique_ptr<WorldModel> currentWorld;
    WorldModel* currentWorld;
    int difficultyIdx;

    void handleEncounters(const coordinate& position);
    void onEncounterHealthPack();
    void onEncounterEnemy();
    void onEncounterPEnemy();
    void onEncounterXEnemy();
    void onEncounterAffectedTiles();

    int flagEnemy = 0;
    int flagPEnemy = 0;
    int flagXEnemy = 0;

    bool firstWorld = true;

};

#endif // WORLDCONTROLLER_H
