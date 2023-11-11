// WorldController.cpp
#include "WorldController.h"
#include "WorldModel.h"
#include "WorldView.h"

WorldController::WorldController(WorldModel *model, WorldView *view, QObject *parent)
    : QObject(parent) {
    // Connect the view's interaction signals to the corresponding slots for handling in the controller
    // Example: connect(WorldView, &WorldView::someSignal, this, &WorldController::someSlot);
}
