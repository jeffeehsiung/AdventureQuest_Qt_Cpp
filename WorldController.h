//WorldController.h
#ifndef WorldCONTROLLER_H
#define WorldCONTROLLER_H

#include "world_global.h"
#include <QObject>

class WorldModel;
class WorldView;

class WORLDSHARED_EXPORT WorldController : public QObject {
    Q_OBJECT

public:
    WorldController(WorldModel *model, WorldView *view, QObject *parent = nullptr);

    // Methods to handle user input, such as keypresses for moving the protagonist

private:
    WorldModel *worldModel;
    WorldView *worldView;
};

#endif // WorldCONTROLLER_H
