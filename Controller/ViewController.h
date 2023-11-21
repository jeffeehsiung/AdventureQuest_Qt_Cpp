#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <memory>
#include "View/GameView.h"

template <typename View, typename EntityItem>
class ViewController {
private:
    std::unique_ptr<View> view;

public:
    // Constructor that takes ownership of a view
    ViewController(std::unique_ptr<View> view) : view(std::move(view)) {}

    // Method to add an entity to the view
    void addEntity(std::unique_ptr<EntityItem> item) {
        view->addEntity(std::move(item));
    }

    void switchView() {
        view->switchView();
    }

    void zoomIn() {
        view->zoomIn();
    }

    void zoomOut() {
        view->zoomOut();
    }

    void animateEntityAction(const QString& action) {
        view->animateEntityAction(action);
    }

    // ...other methods as needed to interact with the view
};

#endif // VIEWCONTROLLER_H
