#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <memory>
#include "View/GameView.h"
#include "GraphicsViewController.h" // Include your GraphicsViewController header
#include "TextualViewController.h"   // Include your TextualViewController header

template <typename View, typename EntityItem>
class ViewController {
private:
    std::unique_ptr<View> view;
    std::unique_ptr<GraphicsViewController> graphicsViewController;
    std::unique_ptr<TextualViewController> textualViewController;
    bool isGraphicsViewActive; // Flag to track the active view

public:
    // Constructor that takes ownership of a view
    ViewController(std::unique_ptr<View> view)
        : view(std::move(view)), isGraphicsViewActive(true) {
        // Initialize GraphicsViewController and TextualViewController
        graphicsViewController = std::make_unique<GraphicsViewController>(view.get());
        textualViewController = std::make_unique<TextualViewController>(/* Any necessary parameters */);
    }

    // Method to add an entity to the view
    void addEntity(std::unique_ptr<EntityItem> item) {
        view->addEntity(std::move(item));
    }

    // Method to switch between graphical and textual views
    void switchView() {
        if (isGraphicsViewActive) {
            textualViewController->displayTextualView();
        } else {
            graphicsViewController->displayGraphicsView();
        }
        isGraphicsViewActive = !isGraphicsViewActive;
    }

    // ...other methods as needed to interact with the view
};

#endif // VIEWCONTROLLER_H
