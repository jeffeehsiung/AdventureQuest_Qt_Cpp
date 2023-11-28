#include "Game2DView.h"

// Constructor and other member functions...
void Game2DView::addEntity(std::unique_ptr<EntityGraphicsItem> item) {
    if (item) {
        scene->addItem(item.get());  // Add the item to the QGraphicsScene
        entityGraphicsItems.push_back(std::move(item));  // Transfer ownership to the vector
    }
}

void Game2DView::animateEntityAction(const QString& entity) {
    // Implementation for graphical animation of an entity action
}


void Game2DView::drawWorld() {
    // Clear any existing items in the scene, if necessary
    scene->clear();
    setBackground(currentBackgroundNumber);

    // Add entities to the scene
    for (auto& entityGraphicsItem : entityGraphicsItems) {
        if (entityGraphicsItem) {
            entityGraphicsItem->updatePosition();
            scene->addItem(entityGraphicsItem.get());
        }
    }
    // Additional drawing code here, if needed
    // For example, drawing UI elements, score, etc.
    // Update the scene to reflect the changes
    scene->update();
}

void Game2DView::setBackground(int backgroundNumber) {
    /**
     * should be dependent on game state passed into the view controller
     * then the controller based on game state assign the correspodning number to Game2DView
     * game2DViewInstance->setBackground(2); // Switch to the second background
     * */
    switch(backgroundNumber) {
    case 1: setBackgroundBrush(QBrush(defaultBackground)); break;
    case 2: setBackgroundBrush(QBrush(easyBackground)); break;
    case 3: setBackgroundBrush(QBrush(mediumBackground)); break;
    case 4: setBackgroundBrush(QBrush(hardBackground)); break;
    default: setBackgroundBrush(QBrush(defaultBackground));
        break;
    }
    currentBackgroundNumber = backgroundNumber;
    update();  // Refresh the view
}


void Game2DView::updateView() {
    // Replace with game logic to update entity positions
    for (auto& entityGraphicsItem : entityGraphicsItems) {
        // Update entity positions based on game logic
        entityGraphicsItem->updatePosition();
    }
    scene->update();
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


