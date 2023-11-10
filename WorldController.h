// ../headers/GameController.h
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "world_global.h"
#include <QObject>

class GameModel;
class GameView;

class WORLDSHARED_EXPORT GameController : public QObject {
    Q_OBJECT

public:
    GameController(GameModel *model, GameView *view, QObject *parent = nullptr);

    // Methods to handle user input, such as keypresses for moving the protagonist

private:
    GameModel *gameModel;
    GameView *gameView;
};

#endif // GAMECONTROLLER_H
