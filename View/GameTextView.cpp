#include "GameTextView.h"


constexpr int MAX_VIEW_WIDTH = 30;
constexpr int MAX_VIEW_HEIGHT = 30;


void GameTextView::addEntity(const Entity& entity) {
    // Attempt to cast to each specific type
    if (const auto* tileModel = dynamic_cast<const TileModel*>(&entity)) {
        auto textItem = std::make_unique<TileTextItem>(*tileModel);
        entityTextItems.push_back(std::move(textItem));
    } else if (const auto* enemyModel = dynamic_cast<const EnemyModel*>(&entity)) {
        auto textItem = std::make_unique<EnemyTextItem>(*enemyModel);
        entityTextItems.push_back(std::move(textItem));
    } else if (const auto* protagonistModel = dynamic_cast<const ProtagonistModel*>(&entity)) {
        auto textItem = std::make_unique<ProtagonistTextItem>(*protagonistModel);
        entityTextItems.push_back(std::move(textItem));
    } else {
        // Log an error for an unknown entity type
        qWarning() << "Unknown entity type encountered in GameTextView::addEntity";
    }
}


void GameTextView::animateEntityAction(QString const&){}

QString GameTextView::generateTextBackground() {
    // Generate and return a QString representing the text-based background
    QString background(MAX_VIEW_HEIGHT, '\n'); // Initialize with newlines
    for (int i = 0; i < MAX_VIEW_HEIGHT; ++i) {
        for (int j = 0; j < MAX_VIEW_WIDTH; ++j) {
            background[(i * (MAX_VIEW_WIDTH + 1)) + j] = '.'; // +1 for the newline character
        }
    }
    return background;
}

void GameTextView::initializeView() {
    clear();
//    QString textBackground = generateTextBackground();
//    this->setPlainText(textBackground);

    // Get the singleton instance of WorldController
    auto& worldController = WorldController::getInstance();

    // Extract entities from the WorldController
    const std::vector<std::unique_ptr<TileModel>>& tiles = worldController.getTiles();
    const std::vector<std::unique_ptr<TileModel>>& healthPacks = worldController.getHealthPacks();
    const std::vector<std::unique_ptr<EnemyModel>>& enemies = worldController.getEnemies();
    const std::vector<std::unique_ptr<PEnemyModel>>& penemies = worldController.getPEnemies();
    const std::vector<std::unique_ptr<ProtagonistModel>>& protagonists = worldController.getProtagonists();

    // Create text representations for entities and store them
    for (const auto& tile : tiles) {
        auto tileTextItem = std::make_unique<TileTextItem>(*tile);
        entityTextItems.push_back(std::move(tileTextItem));
    }

    for (const auto& healthPack : healthPacks) {
        auto hpTextItem = std::make_unique<TileTextItem>(*healthPack);
        entityTextItems.push_back(std::move(hpTextItem));
    }

    for (const auto& enemy : enemies) {
        auto enemyTextItem = std::make_unique<EnemyTextItem>(*enemy);
        entityTextItems.push_back(std::move(enemyTextItem));
    }

    for (const auto& penemy : penemies) {
        auto penemyTextItem = std::make_unique<EnemyTextItem>(*penemy);
        entityTextItems.push_back(std::move(penemyTextItem));
    }

    for (const auto& protagonist : protagonists) {
        auto entityTextItem = std::make_unique<ProtagonistTextItem>(*protagonist);
        entityTextItems.push_back(std::move(entityTextItem));
    }

    updateView();
}

void GameTextView::setBackground(int /*backgroundNumber*/) {
    // Text view doesn't have a background to set
}

void GameTextView::updateView() {
    // Rebuild the text representation of the scene
    QString sceneString = generateTextBackground();
    for (const auto& entityTextItem : entityTextItems) {
        if (entityTextItem) {
            // Append entity representation at the correct position
            const auto position = entityTextItem->getPosition();
            int index = (position.yCoordinate * (MAX_VIEW_WIDTH + 1)) + position.xCoordinate;
            sceneString.replace(index, entityTextItem->getTextRepresentation().length(), entityTextItem->getTextRepresentation());
        }
    }
    // Display only the necessary part of the scene
    displayScene(sceneString);

    emit updateSceneSignal();
}


void GameTextView::displayScene(const QString& sceneString) {
    this->setPlainText(sceneString);
}


void GameTextView::zoomIn() {
    // No zooming functionality in the text view
}

void GameTextView::zoomOut() {
    // No zooming functionality in the text view
}


