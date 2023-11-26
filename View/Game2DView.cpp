#include "Game2DView.h"

// Constructor and other member functions...

void Game2DView::addEntity(std::unique_ptr<EntityGraphicsItem> item) {
    QGraphicsItem* rawPtr = item.get();  // Get the raw pointer to add to the scene
    scene->addItem(rawPtr);  // Add the raw pointer to the scene
    entityGraphicsItems.push_back(std::move(item));  // Store the unique pointer
}

void Game2DView::updateView() {
    // Iterate through the entityGraphicsItems vector and update their positions
    for (size_t i = 0; i < entityGraphicsItems.size(); ++i) {
        // Get the current position of the entity
        coordinate currentPosition = entityPositions[i];

        // Update the position (this is just a hypothetical example)
        // Move the entity to the right by 1 unit and down by 1 unit
        currentPosition.xCoordinate += 1;
        currentPosition.yCoordinate += 1;

        // Update the position in the entityPositions vector
        entityPositions[i] = currentPosition;

        // Now, you can use currentPosition to update the position of the EntityGraphicsItem
        // For example:
        // entityGraphicsItems[i]->setPos(currentPosition.xCoordinate, currentPosition.yCoordinate);
    }

    // You can add more logic here to update other aspects of the view
    // For example, you might update the game state, handle collisions,
    // or perform other view-related updates
}

void Game2DView::drawWorld() {
    // Create a QGraphicsPixmapItem to represent the background image
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(backgroundPixmap);

    // Set the position of the background image to (0, 0)
    backgroundItem->setPos(0, 0);

    // Add the background image to the scene
    scene->addItem(backgroundItem);

    // You can add more game elements (e.g., entities, obstacles, etc.) to the scene
}

void Game2DView::zoomIn() {
    // Get the current transformation matrix
    QTransform currentTransform = transform();

    // Scale the current transformation matrix to zoom in (e.g., by a factor of 1.2)
    currentTransform.scale(1.2, 1.2); // You can adjust the scaling factor as needed

    // Apply the updated transformation matrix to the view
    setTransform(currentTransform);
}

void Game2DView::zoomOut() {
    // Get the current transformation matrix
    QTransform currentTransform = transform();

    // Scale the current transformation matrix to zoom out (e.g., by a factor of 0.8)
    currentTransform.scale(0.8, 0.8); // You can adjust the scaling factor as needed

    // Apply the updated transformation matrix to the view
    setTransform(currentTransform);
}

void Game2DView::animateEntityAction(const QString& entity) {
    // Implementation for graphical animation of an entity action
}

