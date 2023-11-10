// GameModel.h
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "../headers/world.h"

class GameModel : public QObject {
    Q_OBJECT

public:
    explicit GameModel(QObject *parent = nullptr);
    ~GameModel();

    // Add methods to interact with the World, Tiles, and Characters.
    void createWorld(const QString& filename, unsigned int nrOfEnemies, unsigned int nrOfHealthpacks, float pRatio);

    // Further methods ...
    QGraphicsScene* getScene() {
        return scene;
    }

signals:
    void modelUpdated();

private:
    World myWorld;
    QGraphicsScene* scene;  // Added QGraphicsScene member
};

#endif // GAMEMODEL_H
