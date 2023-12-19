#include "GameTextView.h"


constexpr int MAX_VIEW_WIDTH = 300;
constexpr int MAX_VIEW_HEIGHT = 300;

void GameTextView::initializeView() {
    clear();

    auto& worldController = WorldController::getInstance();
    setBackground(worldController.getDifficultyIdx(), 1);
    this->setPlainText(backgroundString);

    // Extract entities from the WorldController and add them if within bounds
    const auto& tileMap = worldController.getTileMap();
    const auto& healthPacks = worldController.getHealthPacks();
    const auto& enemies = worldController.getEnemies();
    const auto& penemies = worldController.getPEnemies();
    const auto& protagonists = worldController.getProtagonists();


    for (const auto& [coord, tileModel] : tileMap) {
        addEntity(*tileModel);
    }

    for (const auto& healthPack : healthPacks) {
        addEntity(*healthPack);
    }
    for (const auto& enemy : enemies) {
        addEntity(*enemy);
    }
    for (const auto& penemy : penemies) {
        addEntity(*penemy);
    }
    for (const auto& protagonist : protagonists) {
        addEntity(*protagonist);
    }

    updateView();
}


void GameTextView::setBackground(int /*backgroundNumber*/, int levels) {
    // Clear any existing content
    backgroundString.clear();
    // Generate a QString representing the text-based background
    for (int i = 0; i < MAX_VIEW_HEIGHT; ++i) {
        for (int j = 0; j < MAX_VIEW_WIDTH; ++j) {
            backgroundString.append('.'); // Append a dot for each position
        }
        backgroundString.append('\n'); // Append a newline at the end of each row
    }
}


void GameTextView::updateView() {
    for (const auto& entityTextItem : entityTextItems) {
        sceneString = backgroundString;
        if (entityTextItem) {
            // Append entity representation at the correct position
            const auto position = entityTextItem->getPosition();
            int index = (position.yCoordinate * (MAX_VIEW_WIDTH + 1)) + position.xCoordinate;
            sceneString.replace(index, entityTextItem->getTextRepresentation().length(), entityTextItem->getTextRepresentation());
        }
    }
    // Display only the necessary part of the scene
    displayScene(sceneString);
}


void GameTextView::displayScene(const QString& sceneString) {
    this->setPlainText(sceneString);
}


void GameTextView::zoomIn(int delta) {
    // No zooming functionality in the text view
}

void GameTextView::zoomOut(int delta) {
    // No zooming functionality in the text view
}


