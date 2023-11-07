// GameModel.h
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include "../headers/world.h"

class GameModel : public QObject {
    Q_OBJECT

public:
    explicit GameModel(QObject *parent = nullptr);
    ~GameModel();

    // Add methods to interact with the World, Tiles, and Characters.
    void createWorld(const QString& filename, unsigned int nrOfEnemies, unsigned int nrOfHealthpacks, float pRatio);

    // Further methods ...

signals:
    void modelUpdated();

private:
    World myWorld;
};

#endif // GAMEMODEL_H
