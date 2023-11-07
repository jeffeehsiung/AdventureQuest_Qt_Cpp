// GameView.cpp
#include "../headers/GameView.h"
#include "../headers/GameModel.h"

GameView::GameView(GameModel *model, QWidget *parent)
    : QGraphicsView(parent), gameModel(model) {
    // Set up the scene
    QGraphicsScene *scene = new QGraphicsScene(this);
    setScene(scene);
    
    // Connect the model's update signal to the view's update slot
    connect(gameModel, &GameModel::modelUpdated, this, &GameView::updateView);
    
    // You may want to add tiles and other items to the scene here
    // This is just an example. You will have to adapt it to your model structure.
    // auto tiles = gameModel->getTiles();
    // for (auto &tile : tiles) {
    //     scene->addItem(new TileGraphicsItem(tile->getXPos(), tile->getYPos(), tile->getValue()));
    // }
}

void GameView::updateView() {
    // Update the view with the new state of the model
    scene()->update();
}
