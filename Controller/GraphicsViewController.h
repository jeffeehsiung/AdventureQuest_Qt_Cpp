// GraphicsViewController.h

#ifndef GRAPHICSVIEWCONTROLLER_H
#define GRAPHICSVIEWCONTROLLER_H

#include "ViewController.h"
#include "Game2DView.h"
#include "EntityGraphicsItem.h"

class GraphicsViewController : public ViewController<Game2DView, EntityGraphicsItem> {
public:
    using ViewController::ViewController;  // Inherit constructors

    void complexAnimation() {
        // Complex animation logic specific to the Game2DView
    }
    // ...other specialized methods for graphics...
};

#endif // GRAPHICSVIEWCONTROLLER_H
