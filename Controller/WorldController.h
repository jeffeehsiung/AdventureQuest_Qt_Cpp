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
        WorldController(QString map, int nrOfEnemies, int nrOfHealthpacks, float pRatio);

        int getHeight() const;
        int getWidth() const;

        std::unique_ptr<ProtagonistModel> getProtagonist(char id) const;
        void addProtagonist(ProtagonistModel*);
        void removeProtagonist(ProtagonistModel*);
        char getActiveProtagonistAmount() const;

        bool isHealthPack(int x, int y, bool kill);
        bool isPoisoned(int x, int y);
        std::unique_ptr<TileModel> getHealthPack(int x, int y);

        std::unique_ptr<TileModel> getTile(int x, int y);
        std::unique_ptr<EnemyModel> isEnemy(int x, int y, bool kill, bool fast);
        std::unique_ptr<EnemyModel> getEnemy(int x, int y);
        const std::vector<std::unique_ptr<TileModel> > &getWalkedOnTiles() const;

        void setWalkedOnTiles(std::unique_ptr<TileModel> newWalkedOnTiles);

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
        std::vector<std::unique_ptr<TileModel>> tiles;
        std::vector<std::unique_ptr<TileModel>> healthPacks;
        std::vector<std::unique_ptr<EnemyModel>> enemies;
        std::vector<std::unique_ptr<TileModel>> walkedOnTiles;


        std::array<std::unique_ptr<ProtagonistModel>,2> protagonists;

        
public slots:
        void handleKeyPress(QKeyEvent* event);
        void resetWorld();

private slots:
        void handleGameOver();
        void handlePoisonLevelUpdated(float poisonLevel);

};

#endif // WORLDCONTROLLER_H
