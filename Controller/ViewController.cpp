#include "Controller/ViewController.h"

ViewController::ViewController(QObject *parent) : QObject(parent), currentView(nullptr) {
    
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
    emit viewUpdated(currentView);

    auto& worldController = WorldController::getInstance();
    connect(&worldController, &WorldController::updateprotagonistPosition, this, &ViewController::onUpdateProtagonistPosition);
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

void ViewController::onUpdatedScene() {
    if (currentView){
        currentView->update();
    }
    emit viewUpdated(currentView);
}

void ViewController::onUpdateProtagonistPosition(int protagonistIndex) {
    if (currentView == game2DView.get()) {
        game2DView->animateEntityAction(protagonistIndex);
        game2DView->updateView();
    }
    else if (currentView == gameTextView.get()) {
        gameTextView->updateView();
    }
    else {
        // Do nothing
    }
    emit viewUpdated(currentView);
}


void ViewController::syncState() {
    // This method should transfer the state from one view to the other.
    // Depending on how your state is represented, this could be a direct data copy,
    // or more complex logic to ensure both views are equivalent in terms of game state.
}
