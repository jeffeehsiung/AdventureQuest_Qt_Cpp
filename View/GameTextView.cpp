#include "GameTextView.h"



void GameTextView::addEntity(const Entity& entity) {
    const WorldModel& world = worldController.getCurrentWorld();
    // Assuming the grid cell is 3 characters wide and 1 character tall, plus borders
    int cellWidth = 4; // 3 characters for the cell + 1 for the right border

    int rows = world.getRows();
    int cols = world.getCols();

    int gridWidth = cols * cellWidth + 1; // 3 spaces for each cell and 1 for the border


    // Check if the entity's position is within bounds
    if (entity.getPosition().xCoordinate >= 0 && entity.getPosition().xCoordinate < cols &&
        entity.getPosition().yCoordinate >= 0 && entity.getPosition().yCoordinate < rows) {

        // Calculate the index for the entity's position in the backgroundString
        int index = (entity.getPosition().yCoordinate * 2 + 1) * (gridWidth + 1) + 2; // +2 for the left border and newline
        index += (entity.getPosition().xCoordinate) * cellWidth; // Each cell is 4 characters wide

        // Attempt to cast to each specific type and add to the vector if within bounds
        if (const auto* tileModel = dynamic_cast<const TileModel*>(&entity)) {
            auto textItem = std::make_unique<TileTextItem>(*tileModel);
            entityTextItems.push_back(std::move(textItem));
        } else if (const auto* enemyModel = dynamic_cast<const EnemyModel*>(&entity)) {
            auto textItem = std::make_unique<EnemyTextItem>(*enemyModel);
            entityTextItems.push_back(std::move(textItem));
        } else if (const auto* penemyModel = dynamic_cast<const PEnemyModel*>(&entity)) {
            auto textItem = std::make_unique<PEnemyTextItem>(*penemyModel);
            entityTextItems.push_back(std::move(textItem));
        } else if (const auto* xenemyModel = dynamic_cast<const XEnemyModel*>(&entity)) {
            auto textItem = std::make_unique<XEnemyTextItem>(*xenemyModel);
            entityTextItems.push_back(std::move(textItem));
        } else if (const auto* protagonistModel = dynamic_cast<const ProtagonistModel*>(&entity)) {
            auto textItem = std::make_unique<ProtagonistTextItem>(*protagonistModel);
            entityTextItems.push_back(std::move(textItem));
        }
        // Assign the index for the text item
        entityTextItems.back()->setIndex(index);
    }
    else {
        // Log an error for an out-of-bounds entity position
        qWarning() << "Entity position out of bounds in GameTextView::addEntity";
    }
}

void GameTextView::initializeView() {
    clear();

    // Access WorldModel via WorldController
//    auto& worldController = WorldController::getInstance();
    const WorldModel& world = worldController.getCurrentWorld();

    // Use 'world' as needed...
    setBackground(worldController.getDifficultyIdx());

    this->setPlainText(backgroundString);

    // Extract entities from the WorldController and add them if within bounds
    const auto& tiles = world.getTiles();
    const auto& healthPacks = world.getHealthPacks();
    const auto& enemies = world.getEnemies();
    const auto& penemies = world.getPEnemies();
    const auto& xenemies = world.getXEnemies();
    const auto& protagonists = world.getProtagonists();

    for (const auto& tile : tiles) {
        addEntity((*tile));
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
    for (const auto& xenemy : xenemies) {
        addEntity(*xenemy);
    }
    for (const auto& protagonist : protagonists) {
        addEntity(*protagonist);
    }

    updateView();
}


void GameTextView::setBackground(int backgroundNumber) {
    Q_UNUSED(backgroundNumber);
    backgroundString.clear();

    const WorldModel& world = worldController.getCurrentWorld();
    int rows = world.getRows();
    int cols = world.getCols();

    // Build the top border of the grid
    QString topBorder = "+" + QString("---+").repeated(cols) + "\n";
    backgroundString += topBorder;

    // Construct the ASCII representation of the grid
    for (int row = 0; row < rows; ++row) {
        QString middle = "|";
        for (int col = 0; col < cols; ++col) {
            middle += "   |";
        }
        middle += "\n+" + QString("---+").repeated(cols) + "\n";
        backgroundString += middle;
    }
}



void GameTextView::updateView() {
    sceneString = backgroundString; // Start with the base grid

    for (const auto& entityTextItem : entityTextItems) {
        if (entityTextItem) {
            // Use the index calculated in addEntity to place the text representation in the correct grid position
            int index = entityTextItem->getIndex();
            sceneString.replace(index, 1, entityTextItem->getTextRepresentation());
        }
    }

    // Display the updated scene
    displayScene(sceneString);
}




void GameTextView::displayScene(const QString& sceneString) {
    this->setPlainText(sceneString);
}


void GameTextView::zoomIn(int delta) {
    // No zooming functionality in the text view
    Q_UNUSED(delta);
}

void GameTextView::zoomOut(int delta) {
    // No zooming functionality in the text view
    Q_UNUSED(delta);
}


