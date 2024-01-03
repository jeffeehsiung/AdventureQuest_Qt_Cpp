#include "GameTextView.h"



void GameTextView::addEntity(const Entity& entity) {
    const WorldModel& world = worldController.getCurrentWorld();
    // Assuming the grid cell is 3 characters wide and 1 character tall, plus borders
    int evenCellWidth = 4; // 3 characters for the cell + 1 for the right border
    int oddCellWidth = 7; // 5 characters for the cell + 1 for the right border

    int rows = world.getRows();
    int cols = world.getCols();

    int evengridWidth = cols * evenCellWidth + 1 + 1; // 3 spaces for each cell and 1 for the left border and 1 for new line at the end
    int oddgridWidth = cols * oddCellWidth + 2 + 1; // 5 spaces for each cell and 2 for the left border and 1 for new line at the end


    // Check if the entity's position is within bounds
    if (entity.getPosition().xCoordinate >= 0 && entity.getPosition().xCoordinate < cols &&
        entity.getPosition().yCoordinate >= 0 && entity.getPosition().yCoordinate < rows) {

        // Calculate the index for the entity's position in the backgroundString
        int index = evengridWidth + entity.getPosition().yCoordinate * oddgridWidth + entity.getPosition().yCoordinate * evengridWidth;
        index += ( 1 + entity.getPosition().xCoordinate * oddCellWidth + (oddCellWidth - 1) / 2);

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

//void GameTextView::addEntity(const Entity& entity) {
//    const WorldModel& world = worldController.getCurrentWorld();

//    // Get rows and columns from the world model
//    int rows = world.getRows();
//    int cols = world.getCols();

//    // Calculate the actual width of a single cell in the HTML representation
//    // including spaces and the HTML tags added for a single character.
//    int cellWidthInHtml = QString("   ").length() + QString("<font color='black'> </font>").length();

//    // Calculate the width of a single row in the HTML representation
//    // including the borders and newlines.
//    int rowWidthInHtml = (cols * cellWidthInHtml) + QString("+\n").length();

//    // Check if the entity's position is within bounds
//    if (entity.getPosition().xCoordinate >= 0 && entity.getPosition().xCoordinate < cols &&
//        entity.getPosition().yCoordinate >= 0 && entity.getPosition().yCoordinate < rows) {

//        // Calculate the starting index of the row in the HTML representation
//        int rowIndexInHtml = entity.getPosition().yCoordinate * rowWidthInHtml;

//        // Calculate the index for the entity's position within its row in the HTML representation
//        int columnIndexInHtml = 1 + entity.getPosition().xCoordinate * cellWidthInHtml; // +1 for the left border

//        // The total index in the HTML representation
//        int indexInHtml = rowIndexInHtml + columnIndexInHtml;

//        // Create and store the appropriate EntityTextItem based on the type of entity
//        // ...

//        // Assign the index for the text item
//        entityTextItems.back()->setIndex(indexInHtml);
//    }
//    else {
//        // Log an error for an out-of-bounds entity position
//        qWarning() << "Entity position out of bounds in GameTextView::addEntity";
//    }
//}

void GameTextView::initializeView() {
    clear();

    // Access WorldModel via WorldController
//    auto& worldController = WorldController::getInstance();
    const WorldModel& world = worldController.getCurrentWorld();

    // Use 'world' as needed...
    setBackground(worldController.getDifficultyIdx());

    this->setPlainText(backgroundString);
//    this->setHtml(backgroundString);

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
    QString topBorder = "+" + QString("---+").repeated(cols) + '\n';
    backgroundString += topBorder;

    // Construct the ASCII representation of the grid
    for (int row = 0; row < rows; ++row) {
        QString middle = " |" + QString("      |").repeated(cols) + '\n';
        middle += "+" + QString("---+").repeated(cols) + '\n';
        backgroundString += middle;
    }
}

//void GameTextView::setBackground(int backgroundNumber) {
//    Q_UNUSED(backgroundNumber);
//    backgroundString.clear();

//    const WorldModel& world = worldController.getCurrentWorld();
//    int rows = world.getRows();
//    int cols = world.getCols();

//    // Start the HTML for the background string
//    backgroundString += "<html><body><pre>"; // Use pre tag to preserve whitespace

//    // Build the top border of the grid
//    QString topBorder = "+" + QString("---+").repeated(cols) + '\n';
//    backgroundString += topBorder;

//    // Construct the ASCII representation of the grid, converting it to HTML
//    for (int row = 0; row < rows; ++row) {
//        QString middle = "|" + QString("   |").repeated(cols) + '\n';
//        middle += "+" + QString("---+").repeated(cols) + '\n';
//        backgroundString += middle;
//    }

//    // Close the HTML tags
//    backgroundString += "</pre></body></html>";
//}




void GameTextView::updateView() {
    sceneString = backgroundString; // Start with the base grid
    const WorldModel& world = worldController.getCurrentWorld();
    // Assuming the grid cell is 3 characters wide and 1 character tall, plus borders
    int evenCellWidth = 4; // 3 characters for the cell + 1 for the right border
    int oddCellWidth = 7; // 5 characters for the cell + 1 for the right border

    int rows = world.getRows();
    int cols = world.getCols();

    int evengridWidth = cols * evenCellWidth + 1 + 1; // 3 spaces for each cell and 1 for the left border and 1 for new line at the end
    int oddgridWidth = cols * oddCellWidth + 2 + 1; // 5 spaces for each cell and 2 for the left border and 1 for new line at the end


    for (const auto& entityTextItem : entityTextItems) {
        if (entityTextItem) {
            // Calculate the index for the entity's position in the backgroundString
            int index = evengridWidth + entityTextItem->getEntity().getPosition().yCoordinate * oddgridWidth + entityTextItem->getEntity().getPosition().yCoordinate * evengridWidth;
            index += ( 1 + entityTextItem->getEntity().getPosition().xCoordinate * oddCellWidth + (oddCellWidth - 1) / 2);
            // Assign the index for the text item
            entityTextItems.back()->setIndex(index);
            sceneString.replace(index, 1, entityTextItem->getTextRepresentation());
        }
    }

    // Display the updated scene
    displayScene(sceneString);

}

//void GameTextView::updateView() {
//    // Since setBackground already wraps the background with HTML tags, we don't add them here
//    QString htmlScene = backgroundString; // Start with the base grid, already in HTML format

//    // Remove the old entity representations if there are any
//    QRegularExpression entityRegex("<font color='[^']+'>(.)</font>");
//    htmlScene.remove(entityRegex);

//    // Calculate the correct position and insert the entity representations
//    for (const auto& entityTextItem : entityTextItems) {
//        if (entityTextItem) {
//            // Use the index calculated in addEntity to place the text representation in the correct grid position
//            int index = entityTextItem->getIndex() * 3; // Each cell has 3 characters width in the grid
//            QString entityRepresentation = entityTextItem->getTextRepresentation();
//            // Use QString::replace to insert the entity representation in the correct position within the grid
//            htmlScene.replace(index, 1, entityRepresentation); // Replace the character at the index with the entity representation
//        }
//    }

//    // Display the updated scene
//    displayScene(htmlScene);
//}


void GameTextView::displayScene(const QString& sceneString) {
    this->setPlainText(sceneString);
}

//void GameTextView::displayScene(const QString& htmlScene) {
//    this->setHtml(htmlScene); // Set the HTML content to the QTextEdit
//}


void GameTextView::zoomIn(int delta) {
    // No zooming functionality in the text view
    Q_UNUSED(delta);
}

void GameTextView::zoomOut(int delta) {
    // No zooming functionality in the text view
    Q_UNUSED(delta);
}


