#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include "GameView.h"

class ViewController : public GameView {
public:
    ViewController() {}
    virtual ~ViewController() {}

    void updateView() override {
        // Base implementation, can be overridden by derived classes
    }
};

#endif // VIEWCONTROLLER_H
