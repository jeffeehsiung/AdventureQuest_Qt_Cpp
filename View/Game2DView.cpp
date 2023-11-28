#include "Game2DView.h"

Game2DView::Game2DView(QWidget* parent)
    : QGraphicsScene(parent), currentBackgroundNumber(1), zoomLevel(1.0) {
    // Load background images
    defaultBackground.load(":/images/world_images/worldmap4.png");
    easyBackground.load(":/images/world_images/maze1.png");
    mediumBackground.load(":/images/world_images/maze2.png");
    hardBackground.load(":/images/world_images/maze3.png");
    // Set default background or based on initial game state
    setBackgroundBrush(QBrush(defaultBackground));
}

// member functions...
void Game2DView::addEntity(std::unique_ptr<Entity> entity) {
    if (entity) {
        std::unique_ptr<EntityGraphicsItem> entityGraphicsItem = std::make_unique<EntityGraphicsItem>(std::move(entity));;
        addItem(entityGraphicsItem.get());  // Add the item to the QGraphicsScene
        entityGraphicsItems.push_back(std::move(entityGraphicsItem));  // Store the item in the vector
    }
}

void Game2DView::animateEntityAction(const QString& entity) {
    // Implementation for graphical animation of an entity action
}


void Game2DView::updateView() {
    // Clear any existing items in the scene, if necessary
    clear();
    setBackground(currentBackgroundNumber);

    // Iterate through the collection of entity graphics items
    for (const auto& entityGraphicsItem : entityGraphicsItems) {
        if (entityGraphicsItem) {
            entityGraphicsItem->updatePosition();

            EntityGraphicsItem* typedEntityItem = dynamic_cast<EntityGraphicsItem*>(entityGraphicsItem.get());
            if (typedEntityItem) {
                // It's a valid EntityGraphicsItem
                addItem(typedEntityItem);
            }
            // Add more conditions for other derived classes as needed
        }
    }

    // Additional drawing code here, if needed
    // For example, drawing UI elements, score, etc.
    // Update the scene to reflect the changes
    emit updateSceneSignal(); // Emit the signal to indicate that the scene needs updating
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


void Game2DView::updateZoom() {
    qreal scaleFactor = qPow(2.0, zoomLevel);

    // Iterate through the collection of entity graphics items
    for (const auto& entityGraphicsItem : entityGraphicsItems) {
        if (entityGraphicsItem) {
            entityGraphicsItem->setScale(scaleFactor);
        }
    }
}

void Game2DView::zoomIn() {
    zoomLevel += 0.1; // Increase the zoom level
    updateZoom();
}

void Game2DView::zoomOut() {
    zoomLevel -= 0.1; // Decrease the zoom level
    updateZoom();
}



