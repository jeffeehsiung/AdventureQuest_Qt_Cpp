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
    connect(&worldController, &WorldController::protagonistPositionChanged, this, &ViewController::updateProtagonistPosition);
    connect(&worldController, &WorldController::updateLevel, this, &ViewController::updateLevel);
    connect(game2DView.get(), &Game2DView::updateSceneSignal, this, &ViewController::onUpdatedScene);
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

void ViewController::updateProtagonistPosition(int protagonistIndex) {
    if (currentView == game2DView.get()) {
        AnimationState newState = MOVING;         //hardcoded. need to embed state of the entity in world and model
        game2DView->animateEntityAction(protagonistIndex, newState);
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

void ViewController::updateLevel() {
    game2DView->levelChange();
    emit viewUpdated(currentView);
}


void ViewController::syncState() {
    // This method should transfer the state from one view to the other.
    // Depending on how your state is represented, this could be a direct data copy,
    // or more complex logic to ensure both views are equivalent in terms of game state.
}
