#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "WorldController.h"
// ... Other includes ...

class GameController : public QObject {
    Q_OBJECT
    // ... Other members ...

public:
    explicit GameController(QObject *parent = nullptr) : QObject(parent) {
        // Initialize the game world and entities
    }

    // Methods that interact with World, Protagonist, and Enemies
};

#endif // GAMECONTROLLER_H
