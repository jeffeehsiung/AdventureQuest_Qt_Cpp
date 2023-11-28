#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QString>
#include "Model/structs.h"

class GameView {
public:
    virtual ~GameView() {}
    virtual void updateView() = 0;
    virtual void drawWorld() = 0;
    virtual void zoomIn() = 0;
    virtual void zoomOut() = 0;
    virtual void updateScene() = 0;
    virtual void animateEntityAction(const QString& action) = 0;
};

#endif // GAMEVIEW_H
