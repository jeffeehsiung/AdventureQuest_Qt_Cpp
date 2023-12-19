#include "Controller/ViewController.h"

ViewController::ViewController(QObject *parent) : QObject(parent), currentView(nullptr) {
    
}

ViewController::~ViewController() {
    // Clean up if necessary
}

void ViewController::initializeViews() {
    auto& worldController = WorldController::getInstance();

    game2DView = std::make_unique<Game2DView>(nullptr);
    //gameTextView = std::make_unique<GameTextView>(nullptr);

    // Initialize the views
    game2DView->initializeView();
    //gameTextView->initializeView();

    // Optionally set the initial view
    currentView = game2DView.get();
    emit viewUpdated(currentView);


    connect(&worldController, &WorldController::updateprotagonistPosition, this, &ViewController::onUpdateProtagonistPosition);
    connect(&worldController, &WorldController::updateLevel, this, &ViewController::updateLevel);
}

void ViewController::switchTo2DView() {
    if (currentView != game2DView.get()) {
        syncState(); // Sync state from the current view to the 2D view
        currentView = game2DView.get();
        emit viewUpdated(currentView);
    }
}

void ViewController::switchToTextView() {
    if (currentView != gameTextView.get()) {
        syncState(); // Sync state from the current view to the text view
        currentView = gameTextView.get();
        emit viewUpdated(currentView);
    }
}

QWidget* ViewController::getCurrentView() const {
    return currentView;
}

void ViewController::onUpdateProtagonistPosition(int protagonistIndex) {
    if (currentView == game2DView.get()) {
        game2DView->updateView();
    }
    else if (currentView == gameTextView.get()) {
        gameTextView->updateView();
    }
    emit viewUpdated(currentView);
}

void ViewController::updateLevel() {
    game2DView->initializeView();
    currentView = game2DView.get();
    emit viewUpdated(currentView);
}


void ViewController::syncState() {
    // This method should transfer the state from one view to the other.
    // Depending on how your state is represented, this could be a direct data copy,
    // or more complex logic to ensure both views are equivalent in terms of game state.
}
