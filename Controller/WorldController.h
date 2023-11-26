#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "model/world.h"
#include "model/structs.h"
#include "model/ProtagonistModel.h"
#include "model/EnemyModel.h"


#include <iostream>
#include <QObject>
#include <QMainWindow>

class WorldController : public QObject
{
    Q_OBJECT

    public:
        WorldController(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio);

        int getHeight() const;
        int getWidth() const;

        std::unique_ptr<ProtagonistModel> getProtagonist(char id) const;
        void addProtagonist(ProtagonistModel*);
        void removeProtagonist(ProtagonistModel*);
        char getActiveProtagonistAmount() const;

        bool isHealthPack(int x, int y, bool kill);
        bool isPoisined(int x, int y);
        std::unique_ptr<Tile> getHealthPack(int x, int y);

        std::unique_ptr<Tile> getTile(int x, int y);
        std::unique_ptr<Enemy> isEnemy(int x, int y, bool kill, bool fast);
        std::unique_ptr<Enemy> getEnemy(int x, int y);
        const std::vector<std::unique_ptr<Tile> > &getWalkedOnTiles() const;

        void setWalkedOnTiles(std::unique_ptr<Tile> newWalkedOnTiles);

        void poisonTilesAround(int x , int y, int spread, std::unique_ptr<PEnemy> parent);

        void deleteEnemy(int x, int y);

        void deletePsnTile(int x, int y);

        coordinate getStart();
        coordinate getExit();
private:
        std::unique_ptr<World> world;
        int height;
        int width;
        coordinate exit = coordinate(1,1);
        coordinate start = coordinate(0,0);
        std::vector<std::unique_ptr<Tile>> tiles;
        std::vector<std::unique_ptr<Tile>> healthPacks;
        std::vector<std::unique_ptr<EnemyModel>> enemies;
        std::vector<std::unique_ptr<Tile>> walkedOnTiles;


        std::array<std::unique_ptr<ProtagonistModel>,2> protagonists;

        
public slots:
        void handleKeyPress(QKeyEvent* event);
        void resetWorld();

private slots:
        void handleGameOver();
        void handlePoisonLevelUpdated(float poisonLevel);

};

#endif // WORLDCONTROLLER_H
