#ifndef GRAPHICSVIEWCONTROLLER_H
#define GRAPHICSVIEWCONTROLLER_H

#include "ViewController.h"
#include <QGraphicsView>

class GraphicsViewController : public ViewController {
private:
    QGraphicsView* graphicsView;

public:
    GraphicsViewController(QGraphicsView* view) : graphicsView(view) {}

    void updateView() override {
        // Implement how the graphical elements are updated and rendered
        graphicsView->viewport()->update();
    }
};

#endif // GRAPHICSVIEWCONTROLLER_H
