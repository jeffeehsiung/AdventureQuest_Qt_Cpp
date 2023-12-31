#include "Game2DView.h"

void Game2DView::initializeView() {
    if (!scene) {
        scene = new QGraphicsScene(this);
        setScene(scene);
    }
    healthpackGraphicsItems.clear();
    tileGraphicsItems.clear();
    enemyGraphicsItems.clear();
    penemyGraphicsItems.clear();

    // Access WorldModel via WorldController
    auto& worldController = WorldController::getInstance();
    const WorldModel& world = worldController.getCurrentWorld();

    // Use 'world' as needed...
    setBackground(worldController.getDifficultyIdx());

    qDebug() << "backgroundImage width: " << backgroundImage.width() << "backgroundImage heght" << backgroundImage.height();
    qDebug() << "worldController cols: " << world.getCols() << "worldController height" << world.getRows();
    qDebug() << "view width: " << this->width() << "view height" << this->height();
    qDebug() << "scene width: " << scene->width() << "scene height" << scene->height();

    qDebug() << "tilewidth: " << tileWidth << " tileheight: " << tileHeight;

    scaleEntitiesToFitView();

    // Extract entities from the WorldController
    const auto& tileMap = world.getTileMap();
    const std::vector<std::unique_ptr<TileModel>>& healthPacks = world.getHealthPacks();
    const std::vector<std::unique_ptr<EnemyModel>>& enemies = world.getEnemies();
    const std::vector<std::unique_ptr<PEnemyModel>>& penemies = world.getPEnemies();
    const std::vector<std::unique_ptr<ProtagonistModel>>& protagonists = world.getProtagonists();

    /** baseFramesDir for tile is constant */
    QString tileBase = ":/images/tiles/";
    for (const auto& [coord, tileModel] : tileMap) {
        std::unique_ptr<TileGraphicsItem> tileGraphicsItem = std::make_unique<TileGraphicsItem>(*tileModel, tileBase);
        scene->addItem(tileGraphicsItem.get());
        tileGraphicsItems.push_back(std::move(tileGraphicsItem));
    }


    /** baseFramesDir for healthpack is constant */
    QString healthpackBase = ":/images/healthpack/";
    for (const auto& healthPack : healthPacks) {
        std::unique_ptr<TileGraphicsItem> healthPackGraphicsItem = std::make_unique<TileGraphicsItem>(*healthPack, healthpackBase);
        scene->addItem(healthPackGraphicsItem.get());
        healthpackGraphicsItems.push_back(std::move(healthPackGraphicsItem));
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
        std::unique_ptr<PEnemyGraphicsItem> penemyGraphicsItem = std::make_unique<PEnemyGraphicsItem>(*penemy, penemyBase);
        scene->addItem(penemyGraphicsItem.get());
        penemyGraphicsItems.push_back(std::move(penemyGraphicsItem));
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
    scene->setSceneRect(0, 0, backgroundImage.width() + tileWidth, backgroundImage.height() + tileHeight);
    this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    qDebug() << "items added scene width: " << scene->width() << "items added scene height" << scene->height();
    qDebug() << "items added view width: " << this->width() << "items added view height" << this->height();

    this->update();

}

void Game2DView::setBackground(int backgroundNumber) {
    // Load the background image based on the difficulty level
    switch(backgroundNumber) {
    case 1: backgroundImage = easyBackground; tileWidth = 30; tileHeight = 30; break;
    case 2: backgroundImage = mediumBackground; tileWidth = 30; tileHeight = 30; break;
    case 3: backgroundImage = hardBackground; tileWidth = 20; tileHeight = 20; break;
    default: backgroundImage= easyBackground; tileWidth = 30; tileHeight = 30; break;
    }


    // Resize the background image based on the number of tiles and their size
    auto& worldController = WorldController::getInstance();
    const WorldModel& world = worldController.getCurrentWorld();

    backgroundImage = backgroundImage.scaled(tileWidth * world.getCols(),
                                             tileHeight * world.getRows(),
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
    for(const auto& protagonistGraphicsItem : protagonistGraphicsItems) {
        if (protagonistGraphicsItem) {
            protagonistGraphicsItem->updatePosition();
        }
    }
    for (const auto& healthpackGraphicsItem : healthpackGraphicsItems) {
        if (healthpackGraphicsItem) {
            healthpackGraphicsItem->updatePosition();
        }
    }
    this->update();
}

void Game2DView::zoomIn(int delta) {
    qreal maxZoomLevel = initZoomLevel * 2;
    qreal targetZoomLevel = zoomLevel + delta * zoomSpeed;
    if (targetZoomLevel > maxZoomLevel) {  // If the target zoom level is greater than the max, clamp it
        targetZoomLevel = maxZoomLevel;
        this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }

    if (zoomLevel < targetZoomLevel) {  // Only zoom in if not already at the max zoom level
        qreal factor = qPow(2.0, targetZoomLevel);
        setTransform(QTransform::fromScale(factor, factor));
        if (!protagonistGraphicsItems.empty()) {
            centerOn(protagonistGraphicsItems.front().get());
        }
        zoomLevel = targetZoomLevel; // Update the current zoom level
    }
    this->update();
}

void Game2DView::zoomOut(int delta) {
    qreal scale = 0.001;
    qreal minZoomLevel = (initZoomLevel * scale);
    qreal targetZoomLevel = zoomLevel - delta * zoomSpeed;
    if (targetZoomLevel < minZoomLevel) {  // If the target zoom level is less than the min, clamp it
        targetZoomLevel = minZoomLevel;
        this->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }

    if (zoomLevel > targetZoomLevel) {  // Only zoom out if not already at the min zoom level
        qreal factor = qPow(2.0, targetZoomLevel);
        setTransform(QTransform::fromScale(factor, factor));
        if (!protagonistGraphicsItems.empty()) {
            centerOn(protagonistGraphicsItems.front().get());
        }
        zoomLevel = targetZoomLevel; // Update the current zoom level
    }
    this->update();
}

void Game2DView::wheelEvent(QWheelEvent* event) {
    int delta = event->angleDelta().y() / 12 ;
    if (delta > 0) {
        zoomIn(std::abs(delta));  // Zoom in when the wheel is scrolled up
    }else{
        zoomOut(std::abs(delta)); // Zoom out when the wheel is scrolled down
    }
}

// This function should be called after setting the background and calculating tileWidth and tileHeight.
void Game2DView::scaleEntitiesToFitView() {
    qreal sceneWidth = scene->width();
    qreal sceneHeight = scene->height();
    qreal someFactor;
    switch(currentBackgroundNumber){
    case 1: someFactor = 25; break;
    case 2: someFactor = 25; break;
    case 3: someFactor = 25; break;
    default: someFactor = 30; break;
    }
    qreal desiredItemWidth = sceneWidth / someFactor; // 'someFactor' is a value you choose based on how many items you want to fit across the width of the view.
    qreal desiredItemHeight = sceneHeight / someFactor; // Similarly for height.

    // Calculate scale factors
    qreal scaleFactorWidth = desiredItemWidth / tileWidth;
    qreal scaleFactorHeight = desiredItemHeight / tileHeight;

    // Use the smallest scaleFactor to ensure that the aspect ratio is maintained
    qreal scaleFactor = qMin(scaleFactorWidth, scaleFactorHeight);

    // Now set the common dimensions with the scale factor applied
    EntityGraphicsItem::setCommonDimensions(tileWidth * scaleFactor, tileHeight * scaleFactor);
    EntityGraphicsItem::setTileDimensions(tileWidth, tileHeight);
}



// Example function to check each item's position and bounding rectangle
void Game2DView::checkItems() {
    QRectF sceneBounds = scene->sceneRect();
    for (const auto& protagonistGraphicsItem : protagonistGraphicsItems) {
        if (protagonistGraphicsItem) {
            QRectF itemBounds = protagonistGraphicsItem->boundingRect();
            QRectF itemSceneBounds = protagonistGraphicsItem->mapToScene(itemBounds).boundingRect();
            // Check if the item's bounding rectangle in scene coordinates is within the scene's bounds
            if (sceneBounds.contains(itemSceneBounds)) {
            } else {
                qDebug() << "Entity is NOT within scene bounds.";
            }

            // Log the details for debugging
            qDebug() << "Entity position: " << protagonistGraphicsItem->pos();
            qDebug() << "Bounding rectangle (local): " << itemBounds;
        }
    }
    for (const auto& enemyGraphicsItem : enemyGraphicsItems) {
        if (enemyGraphicsItem) {
            QRectF itemBounds = enemyGraphicsItem->boundingRect();
            QRectF itemSceneBounds = enemyGraphicsItem->mapToScene(itemBounds).boundingRect();

            // Check if the item's bounding rectangle in scene coordinates is within the scene's bounds
            if (sceneBounds.contains(itemSceneBounds)) {
            } else {
                qDebug() << "Entity is NOT within scene bounds.";
            }

            // Log the details for debugging
            qDebug() << "Entity position: " << enemyGraphicsItem->pos();
            qDebug() << "Bounding rectangle (local): " << itemBounds;
        }
    }
    for (const auto& tileGraphicsItem : tileGraphicsItems) {
        if (tileGraphicsItem) {
            QRectF itemBounds = tileGraphicsItem->boundingRect();
            QRectF itemSceneBounds = tileGraphicsItem->mapToScene(itemBounds).boundingRect();

            // Check if the item's bounding rectangle in scene coordinates is within the scene's bounds
            if (sceneBounds.contains(itemSceneBounds)) {
            } else {
                qDebug() << "Entity is NOT within scene bounds.";
            }

            // Log the details for debugging
            qDebug() << "Entity position: " << tileGraphicsItem->pos();
            qDebug() << "Bounding rectangle (local): " << itemBounds;
        }
    }
    qDebug() << "Scene rectangle: " << sceneBounds;

}

