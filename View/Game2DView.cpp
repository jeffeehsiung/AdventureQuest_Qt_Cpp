#include "Game2DView.h"

void Game2DView::addEntity(const Entity& entity) {
    std::unique_ptr<EntityGraphicsItem> entityGraphicsItem = std::make_unique<EntityGraphicsItem>(entity);
    scene->addItem(entityGraphicsItem.get());
    entityGraphicsItems.push_back(std::move(entityGraphicsItem));
}

void Game2DView::animateEntityAction(const QString& entity) {
    // Implementation for graphical animation of an entity action
}

void Game2DView::initializeView() {
    if (!scene) {
        scene = new QGraphicsScene(this);
        setScene(scene);
    }

    // Get the singleton instance of WorldController
    auto& worldController = WorldController::getInstance();

    setBackground(worldController.getDifficultyIdx());

    qDebug() << "backgroundImage width: " << backgroundImage.width() << "backgroundImage heght" << backgroundImage.height() << "\n";
    qDebug() << "worldController cols: " << worldController.getCols() << "worldController height" << worldController.getRows() << "\n";
    qDebug() << "view width: " << this->width() << "view height" << this->height() << "\n";
    qDebug() << "scene width: " << scene->width() << "scene height" << scene->height() << "\n";


    // Calculate the size of each tile based on the scene size and the number of tiles
    qreal tileWidth = scene->width() / worldController.getCols();
    qreal tileHeight = scene->height() / worldController.getRows();
    qDebug() << "tilewidth: " << tileWidth << " tileheight: " << tileHeight << "\n";

    EntityGraphicsItem::setCommonDimensions(tileWidth, tileHeight);

    // Extract entities from the WorldController
    const std::vector<std::unique_ptr<TileModel>>& tiles = worldController.getTiles();
    const std::vector<std::unique_ptr<TileModel>>& healthPacks = worldController.getHealthPacks();
    const std::vector<std::unique_ptr<EnemyModel>>& enemies = worldController.getEnemies();
    const std::vector<std::unique_ptr<PEnemyModel>>& penemies = worldController.getPEnemies();
    const std::vector<std::unique_ptr<ProtagonistModel>>& protagonists = worldController.getProtagonists();

    /** baseFramesDir for tile is constant */
    QString tileBase = ":/images/tiles/Idle/";
    for (const auto& tile : tiles) {
        std::unique_ptr<EntityGraphicsItem> tileGraphicsItem = std::make_unique<TileGraphicsItem>(*tile, tileBase);
        // Center the background item in the scene
//        tileGraphicsItem->setPos(tile->getPosition().xCoordinate, tile->getPosition().yCoordinate); // Set the graphic rect item position
        scene->addItem(tileGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(tileGraphicsItem));

    }

    /** baseFramesDir for healthpack is constant */
    QString healthpackBase = ":/images/healthpack/";
    for (const auto& healthPack : healthPacks) {
        std::unique_ptr<EntityGraphicsItem> healthPackGraphicsItem = std::make_unique<TileGraphicsItem>(*healthPack, healthpackBase);
//        healthPackGraphicsItem->setPos(healthPack->getPosition().xCoordinate, healthPack->getPosition().yCoordinate);
        scene->addItem(healthPackGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(healthPackGraphicsItem));
    }

    /** baseFramesDir for enemy is constant */
    QString enemyBase = ":/images/enemy_golem/PNG Sequences/";
    for (const auto& enemy : enemies) {
        std::unique_ptr<EnemyGraphicsItem> enemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*enemy, enemyBase);
//        enemyGraphicsItem->setPos(enemy->getPosition().xCoordinate, enemy->getPosition().yCoordinate);
        scene->addItem(enemyGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(enemyGraphicsItem));
    }

    /** baseFramesDir for penemy is constant */
    QString penemyBase = ":/images/penemy_wraith/PNG Sequences/";
    for (const auto& penemy : penemies) {
        std::unique_ptr<EnemyGraphicsItem> penemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*penemy, penemyBase);
//        penemyGraphicsItem->setPos(penemy->getPosition().xCoordinate, penemy->getPosition().yCoordinate);
        scene->addItem(penemyGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(penemyGraphicsItem));
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
//        protagonistGraphicsItem->setPos(protagonists[i]->getPosition().xCoordinate, protagonists[i]->getPosition().yCoordinate);
        scene->addItem(protagonistGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(protagonistGraphicsItem));

    }

    qDebug() << "Number of protagonist in entityGraphicsItems:" << entityGraphicsItems.size();

    // After adding all items to the scene
    scene->setSceneRect(scene->itemsBoundingRect()); // Set the scene rect to contain all items
    fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    qDebug() << "items added scene width: " << scene->width() << "items added scene height" << scene->height() << "\n";
    qDebug() << "items added view width: " << this->width() << "items added view height" << this->height() << "\n";
    update();

}


void Game2DView::setBackground(int backgroundNumber) {
    /**
     * should be dependent on game state passed into the view controller
     * then the controller based on game state assign the correspodning number to Game2DView
     * game2DViewInstance->setBackground(2); // Switch to the second background
     * */

    switch(backgroundNumber) {
    case 1: /*setBackgroundBrush(QBrush(defaultBackground)); */backgroundImage.load(":/images/world_images/maze1.png"); break;
    case 2: /*setBackgroundBrush(QBrush(easyBackground));*/ backgroundImage.load(":/images/world_images/maze1.png"); break;
    case 3: /*setBackgroundBrush(QBrush(mediumBackground)); */backgroundImage.load(":/images/world_images/maze2.png");break;
    case 4: /*setBackgroundBrush(QBrush(hardBackground)); */backgroundImage.load(":/images/world_images/worldmap4.png"); break;
    default: /*setBackgroundBrush(QBrush(defaultBackground));*/
        break;
    }
    // Add the background image as a pixmap item to the scene
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(backgroundImage);
    backgroundItem->setZValue(-1); // Ensure it's drawn below all other items
    scene->setSceneRect(0, 0, backgroundImage.width() * 20, backgroundImage.height() * 20);
    // Center the background item in the scene
    backgroundItem->setPos(10,10);
    // Add the background item to the scene
    scene->addItem(backgroundItem);
    this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

    currentBackgroundNumber = backgroundNumber;
    this->update();

}

void Game2DView::updateView() {
    for (const auto& entityGraphicsItem : entityGraphicsItems) {
        if (entityGraphicsItem) {
            entityGraphicsItem->updatePosition();
        }
    }
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
    update();
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

//void Game2DView::fitSceneToView() {
//    // Get the bounding rectangle of all items
//    QRectF itemsRect = scene->itemsBoundingRect();

//    // Calculate the desired scale factor based on the items' bounding rectangle
//    qreal scaleFactor = calculateScaleFactor(itemsRect);

//    // Set a minimum scale factor to prevent excessive zooming
//    qreal minScaleFactor = 0.5; // Example value, adjust as needed
//    scaleFactor = qMax(scaleFactor, minScaleFactor);

//    // Set the transformation for the view with the calculated scale factor
//    setTransform(QTransform::fromScale(scaleFactor, scaleFactor));
//    }

//qreal Game2DView::calculateScaleFactor(const QRectF& itemsRect) {
//    QRectF viewRect = this->viewport()->rect(); // The viewport rectangle
//    qreal scaleX = viewRect.width() / itemsRect.width();
//    qreal scaleY = viewRect.height() / itemsRect.height();
//    return qMin(scaleX, scaleY); // Choose the smaller scale to fit the entire content
//}




