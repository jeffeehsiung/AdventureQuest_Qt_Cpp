#include "Controller/ViewController.h"

ViewController::ViewController(QObject *parent) : QObject(parent), currentView(nullptr) {
    initializeViews();
}

ViewController::~ViewController() {
    // Clean up if necessary
}

void ViewController::initializeViews() {
    game2DView = std::make_unique<Game2DView>();
    gameTextView = std::make_unique<GameTextView>();

    // Initialize the views
    game2DView->initializeView();
    gameTextView->initializeView();

    // Optionally set the initial view
    currentView = game2DView.get();
}

void ViewController::switchTo2DView() {
    if (currentView != game2DView.get()) {
        syncState(); // Sync state from the current view to the 2D view
        currentView = game2DView.get();
        emit viewSwitched(currentView);
    }
}

void ViewController::switchToTextView() {
    if (currentView != gameTextView.get()) {
        syncState(); // Sync state from the current view to the text view
        currentView = gameTextView.get();
        emit viewSwitched(currentView);
    }
}

QWidget* ViewController::getCurrentView() const {
    return currentView;
}

void ViewController::handleUpdateScene() {
//    if (currentView) {
//        currentView->updateView();
//    }
}

void ViewController::syncState() {
    // This method should transfer the state from one view to the other.
    // Depending on how your state is represented, this could be a direct data copy,
    // or more complex logic to ensure both views are equivalent in terms of game state.
}



// Additional methods implementation...
