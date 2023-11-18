#include "Game2DView.h"

// Constructor and other member functions...

void Game2DView::addEntity(std::unique_ptr<EntityGraphicsItem> item) {
    QGraphicsItem* rawPtr = item.get();  // Get the raw pointer to add to the scene
    scene->addItem(rawPtr);  // Add the raw pointer to the scene
    entityGraphicsItems.push_back(std::move(item));  // Store the unique pointer
}

void Game2DView::updateView() {
    // Update the view as necessary
}

void Game2DView::drawWorld() {
    // Draw the world as necessary
}

void Game2DView::zoomIn() {
    scale(1.2, 1.2); // Example factor
}

void Game2DView::zoomOut() {
    scale(0.8, 0.8); // Example factor
}

void Game2DView::animateEntityAction(const QString& action) {
    // Implementation for graphical animation of an entity action
}

