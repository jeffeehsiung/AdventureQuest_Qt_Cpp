#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "WorldController.h"
#include <QObject>
#include <QKeyEvent>

class GameController : public QObject
{
    Q_OBJECT

public:
    GameController();

    void startGame(const QString &map);

private:
    WorldController worldController;

public slots:
    void handleKeyPress(QKeyEvent *event);

private slots:
    void handleGameOver();
    void handlePoisonLevelUpdated(float poisonLevel);
};

#endif // GAMECONTROLLER_H
