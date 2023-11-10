// GameController.cpp
#include "../headers/GameController.h"
#include "../headers/GameModel.h"
#include "../headers/GameView.h"

GameController::GameController(GameModel *model, GameView *view, QObject *parent)
    : QObject(parent), gameModel(model), gameView(view) {
    // Connect the view's interaction signals to the corresponding slots for handling in the controller
    // Example: connect(gameView, &GameView::someSignal, this, &GameController::someSlot);
}
