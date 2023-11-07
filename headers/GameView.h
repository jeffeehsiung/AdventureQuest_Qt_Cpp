// ../headers/GameView.h
#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "world_global.h"
#include <QGraphicsView>
class GameModel;

class WORLDSHARED_EXPORT GameView : public QGraphicsView {
    Q_OBJECT

public:
    explicit GameView(GameModel *model, QWidget *parent = nullptr);

public slots:
    void updateView();

private:
    GameModel *gameModel;
};

#endif // GAMEVIEW_H
