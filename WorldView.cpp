// WorldView.cpp
#include "WorldView.h"
#include "WorldModel.h"

WorldView::WorldView(WorldModel *model, QWidget *parent)
    : QGraphicsView(parent){
    // Set up the scene
    QGraphicsScene *scene = new QGraphicsScene(this);
    setScene(scene);
}

void WorldView::updateView() {
    // Update the view with the new state of the model
    scene()->update();
}
