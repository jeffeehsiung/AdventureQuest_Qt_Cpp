#include "Controller/ViewController.h"

ViewController::ViewController(QObject *parent) : QObject(parent), currentView(nullptr) {
    // Initialize both views
    game2DView = std::make_unique<Game2DView>();
    gameTextView = std::make_unique<GameTextView>();
    initializeViews();
}

ViewController::~ViewController() {
    // Clean up if necessary
}

void ViewController::setWorldController(std::shared_ptr<WorldController> wc) {
    worldController = std::move(wc);
    // Initialize views with the world controller
    initializeViews();
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

void ViewController::handleUpdateScene() {
    if (currentView) {
        currentView->updateView();
    }
}

void ViewController::syncState() {
    // This method should transfer the state from one view to the other.
    // Depending on how your state is represented, this could be a direct data copy,
    // or more complex logic to ensure both views are equivalent in terms of game state.
}

void ViewController::initializeViews() {
    if (worldController) {
        game2DView->initializeView(*worldController);
        gameTextView->initializeView(*worldController);
        // Optionally set the initial view
        currentView = game2DView.get();
    }
}

// Additional methods implementation...
