#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "world.h"
#include "structs.h"


#include <iostream>
#include <QObject>
#include <QMainWindow>
#include <tuple>
#include "ProtagnistModel.h"

class WorldController : public QObject
{
    Q_OBJECT

    public:
        WorldController(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio);

        int getHeight() const;
        int getWidth() const;

        std::unique_ptr<Protagonist> getProt(char id) const;
        void addProtagonist(ProtagonistModel*);
        void removeProtagonist(ProtagonistModel*);
        char getActiveProtagonistAmount() const;

        bool isHealthPack(int x, int y, bool kill);
        bool isPoisined(int x, int y);
        unique_ptr<Tile> getHealthPack(int x, int y);
        unique_ptr<poisonedTile> getPoisonedTile(int x, int y);
        vector<unique_ptr<Tile>>  getTiles() const;
        const vector<unique_ptr<Enemy> > &getEnemies() const;
        const vector<unique_ptr<Tile> > &getHealthpacks() const;

        std::unique_ptr<Tile> getTile(int x, int y);
        std::unique_ptr<Enemy> isEnemy(int x, int y, bool kill, bool fast);
        std::unique_ptr<Enemy> getEnemy(int x, int y);
        const std::vector<std::unique_ptr<Tile> > &getWalkedOnTiles() const;

        void setWalkedOnTiles(std::unique_ptr<Tile> newWalkedOnTiles);

        void poisonTilesAround(int x , int y, int spread, std::unique_ptr<PEnemy> parent);

        const std::vector<std::unique_ptr<poisonedTile> > &getPoisonedTiles() const;

        void deleteEnemy(int x, int y);

        void deletePsnTile(int x, int y);

        coordinate getStart();
        coordinate getExit();
private:
        std::unique_ptr<World> world;
        std::vector<std::unique_ptr<Tile>> tiles;       
        std::vector<std::unique_ptr<Tile>> walkedOnTiles;
        int height;
        int width;
        coordinate exit;
        coordinate start;
        std::array<std::unique_ptr<ProtagonistModel>,4> protagonists;
        std::vector<std::unique_ptr<EnemyModel>> enemies;
        std::vector<std::unique_ptr<poisonedTile>> poisonedTiles;
        
public slots:
        void handleKeyPress(QKeyEvent* event);
        void resetWorld();

private slots:
        void handleGameOver();
        void handlePoisonLevelUpdated(float poisonLevel);

};

#endif // WORLDCONTROLLER_H
