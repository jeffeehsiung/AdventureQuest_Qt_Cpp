#include "Game2DView.h"

void Game2DView::addEntity(const Entity& entity) {
    // Attempt to cast to each specific type and add to the vector if within bounds
    if (const auto* tileModel = dynamic_cast<const TileModel*>(&entity)) {
    QString tileBase = ":/images/tiles/";
        auto tileGraphicsItem = std::make_unique<TileGraphicsItem>(*tileModel, tileBase);
        tileGraphicsItems.push_back(std::move(tileGraphicsItem));
    } else if (const auto* enemyModel = dynamic_cast<const EnemyModel*>(&entity)) {
        QString enemyBase = ":/images/enemy_golem/PNG Sequences/";
        auto enemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*enemyModel, enemyBase);
        enemyGraphicsItems.push_back(std::move(enemyGraphicsItem));
    } else if (const auto* penemyModel = dynamic_cast<const PEnemyModel*>(&entity)) {
        QString penemyBase = ":/images/penemy_wraith/PNG Sequences/";
        auto enemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*penemyModel, penemyBase);
        enemyGraphicsItems.push_back(std::move(enemyGraphicsItem));
    }else if (const auto* protagonistModel = dynamic_cast<const ProtagonistModel*>(&entity)) {
        QString protagonistBase = ":/images/protagonist_samurai/";
        auto protagonistGraphicsItem = std::make_unique<ProtagonistGraphicsItem>(*protagonistModel, protagonistBase);
        protagonistGraphicsItems.push_back(std::move(protagonistGraphicsItem));
    } else {
        // Log an error for an unknown entity type
        qWarning() << "Unknown entity type encountered in GameTextView::addEntity";
    }
}

void Game2DView::animateEntityAction(int index, AnimationState newState) {
    // Implementation for graphical animation of an entity action
    protagonistGraphicsItems[index]->changeAnimationState(newState);
}

void Game2DView::initializeView() {
    if (!scene) {
        scene = new QGraphicsScene(this);
        setScene(scene);
    }

    // Get the singleton instance of WorldController
    auto& worldController = WorldController::getInstance();

    setBackground(worldController.getDifficultyIdx());

    qDebug() << "backgroundImage width: " << backgroundImage.width() << "backgroundImage heght" << backgroundImage.height();
    qDebug() << "worldController cols: " << worldController.getCols() << "worldController height" << worldController.getRows();
    qDebug() << "view width: " << this->width() << "view height" << this->height();
    qDebug() << "scene width: " << scene->width() << "scene height" << scene->height();

    // Calculate the size of each tile based on the scene size and the number of tiles
    qDebug() << "tilewidth: " << tileWidth << " tileheight: " << tileHeight;

    EntityGraphicsItem::setCommonDimensions(tileWidth, tileHeight);

    // Extract entities from the WorldController
    const std::vector<std::unique_ptr<TileModel>>& tiles = worldController.getTiles();
    const std::vector<std::unique_ptr<TileModel>>& healthPacks = worldController.getHealthPacks();
    const std::vector<std::unique_ptr<EnemyModel>>& enemies = worldController.getEnemies();
    const std::vector<std::unique_ptr<PEnemyModel>>& penemies = worldController.getPEnemies();
    const std::vector<std::unique_ptr<ProtagonistModel>>& protagonists = worldController.getProtagonists();

    /** baseFramesDir for tile is constant */
    QString tileBase = ":/images/tiles/";
    for (const auto& tile : tiles) {
        std::unique_ptr<TileGraphicsItem> tileGraphicsItem = std::make_unique<TileGraphicsItem>(*tile, tileBase);
        scene->addItem(tileGraphicsItem.get());
        tileGraphicsItems.push_back(std::move(tileGraphicsItem));
    }

    /** baseFramesDir for healthpack is constant */
    QString healthpackBase = ":/images/healthpack/";
    for (const auto& healthPack : healthPacks) {
        std::unique_ptr<TileGraphicsItem> healthPackGraphicsItem = std::make_unique<TileGraphicsItem>(*healthPack, healthpackBase);
        scene->addItem(healthPackGraphicsItem.get());
        tileGraphicsItems.push_back(std::move(healthPackGraphicsItem));
    }

    /** baseFramesDir for enemy is constant */
    QString enemyBase = ":/images/enemy_golem/PNG Sequences/";
    for (const auto& enemy : enemies) {
        std::unique_ptr<EnemyGraphicsItem> enemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*enemy, enemyBase);
        scene->addItem(enemyGraphicsItem.get());
        enemyGraphicsItems.push_back(std::move(enemyGraphicsItem));
    }

    /** baseFramesDir for penemy is constant */
    QString penemyBase = ":/images/penemy_wraith/PNG Sequences/";
    for (const auto& penemy : penemies) {
        std::unique_ptr<EnemyGraphicsItem> penemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*penemy, penemyBase);
        scene->addItem(penemyGraphicsItem.get());
        enemyGraphicsItems.push_back(std::move(penemyGraphicsItem));
    }

    /** baseFramesDir for protagonist depends on numbers of protagonist*/
    QString pro1Base = ":/images/protagonist_fighter/";
    QString pro2Base = ":/images/protagonist_samurai/";
    QString pro3Base = ":/images/protagonist_shinobi/";
    for (size_t i = 0; i < protagonists.size(); ++i) {
        QString protagonistBase; // Variable to hold the base frame directory
        if (i == 0) {
            protagonistBase = pro1Base;
        } else if (i == 1) {
            protagonistBase = pro1Base;
        } else if (i == 2){
            protagonistBase = pro2Base;
        } else if (i == 3){
            protagonistBase = pro3Base;
        } else {
            protagonistBase = pro1Base;
        }
        std::unique_ptr<ProtagonistGraphicsItem> protagonistGraphicsItem = std::make_unique<ProtagonistGraphicsItem>(*protagonists[i], protagonistBase);
        scene->addItem(protagonistGraphicsItem.get());
        protagonistGraphicsItems.push_back(std::move(protagonistGraphicsItem));

    }

    qDebug() << "Number of protagonist in entityGraphicsItems:" << entityGraphicsItems.size();

    // After adding all items to the scene
    scene->setSceneRect(scene->itemsBoundingRect()); // Set the scene rect to contain all items
    this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    qDebug() << "items added scene width: " << scene->width() << "items added scene height" << scene->height();
    qDebug() << "items added view width: " << this->width() << "items added view height" << this->height();
    this->update();

}

void Game2DView::setBackground(int backgroundNumber) {
    // Load the background image based on the difficulty level
    switch(backgroundNumber) {
    case 1: backgroundImage = easyBackground; tileWidth = 30; tileHeight = 30; break;
    case 2: backgroundImage = mediumBackground; tileWidth = 25; tileHeight = 25; break;
    case 3: backgroundImage = hardBackground; tileWidth = 20; tileHeight = 20; break;
    default: backgroundImage= easyBackground; tileWidth = 30; tileHeight = 30; break;
    }

    qDebug() << "computing view width: " << this->width() << "computing view height" << this->height();
    // Resize the background image based on the number of tiles and their size
    auto& worldController = WorldController::getInstance();
    backgroundImage = backgroundImage.scaled(tileWidth * worldController.getCols(),
                                             tileHeight * worldController.getRows(),
                                             Qt::KeepAspectRatioByExpanding);

    // Add the background image as a pixmap item to the scene
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(backgroundImage);
    backgroundItem->setZValue(-1); // Ensure it's drawn below all other items
    scene->addItem(backgroundItem);

    // Set the scene's rectangle to the size of the resized background image
    scene->setSceneRect(0, 0, backgroundImage.width(), backgroundImage.height());

    currentBackgroundNumber = backgroundNumber;
    this->update();
}


void Game2DView::updateView() {
//    for (const auto& tileGraphicsItem : tileGraphicsItems) {
//        if (tileGraphicsItem) {
//            tileGraphicsItem->updatePosition();
//        }
//    }
    for (const auto& enemyGraphicsItem : enemyGraphicsItems) {
        if (enemyGraphicsItem) {
            enemyGraphicsItem->updatePosition();
        }
    }
    for(const auto& protagonistGraphicsItem : protagonistGraphicsItems) {
        if (protagonistGraphicsItem) {
            protagonistGraphicsItem->updatePosition();
        }
    }
    this->update();
    emit updateSceneSignal();
}

void Game2DView::updateZoom() {
    qreal scaleFactor = qPow(2.0, zoomLevel);

    // Set the zoom level for the view
    setTransform(QTransform::fromScale(scaleFactor, scaleFactor));

    // Update the position of the graphics items to keep them in the center of the view
    for (const auto& entityGraphicsItem : entityGraphicsItems) {
        if (entityGraphicsItem) {
            entityGraphicsItem->updatePosition();
        }
    }
    this->update();
}

void Game2DView::zoomIn() {
    zoomLevel += 0.1; // Increase the zoom level

    // Limit the zoom level if needed
    if (zoomLevel > 2.0) {
        zoomLevel = 2.0;
    }

    updateZoom();
}

void Game2DView::zoomOut() {
    zoomLevel -= 0.1; // Decrease the zoom level

    // Limit the zoom level if needed
    if (zoomLevel < 0.5) {
        zoomLevel = 0.5;
    }

    updateZoom();
}


// Example function to check each item's position and bounding rectangle
void Game2DView::checkItems() {
    for (const auto& entityGraphicsItem : entityGraphicsItems) {
        if (entityGraphicsItem) {
            QPointF pos = entityGraphicsItem->pos();
            QRectF rect = entityGraphicsItem->boundingRect();
            qDebug() << "Entity position: " << pos << ", Bounding rectangle: " << rect;
        }
    }
}



