// WorldModel.h
#ifndef WorldMODEL_H
#define WorldMODEL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "world.h"

class WorldModel : public QObject {
    Q_OBJECT

public:
    explicit WorldModel(QObject *parent = nullptr);
    ~WorldModel();

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

#endif // WorldMODEL_H
