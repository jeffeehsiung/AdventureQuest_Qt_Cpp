#include "Game2DView.h"

void Game2DView::setCurrentWorld(const WorldModel& world){
    this->world = &world;
}

void Game2DView::initializeView() {
    if (!scene) {
        scene = new QGraphicsScene(this);
        setScene(scene);
    }

    /** avoid duplicated observers */
    this->clearTileObservers();

    /** clear all vectors */
    tileGraphicsItems.clear();
    healthpackGraphicsItems.clear();
    enemyGraphicsItems.clear();
    penemyGraphicsItems.clear();
    xenemyGraphicsItems.clear();
    portalGraphicsItems.clear();
    protagonistGraphicsItems.clear();
    scene->clear();

    setBackground(backgroundNumber);
    scaleEntitiesToFitView();

    // Extract entities from the WorldController
    const std::vector<std::unique_ptr<TileModel>>& tiles = world->getTiles();
    const std::vector<std::unique_ptr<TileModel>>& healthPacks = world->getHealthPacks();
    const std::vector<std::unique_ptr<EnemyModel>>& enemies = world->getEnemies();
    const std::vector<std::unique_ptr<PEnemyModel>>& penemies = world->getPEnemies();
    const std::vector<std::unique_ptr<XEnemyModel>>& xenemies = world->getXEnemies();
    const std::vector<std::unique_ptr<ProtagonistModel>>& protagonists = world->getProtagonists();

    /** baseFramesDir for tile is constant */
    QString tileBase = ":/images/tiles/";
    for (const auto& tile : tiles) {

        std::unique_ptr<TileGraphicsItem> tileGraphicsItem = std::make_unique<TileGraphicsItem>(*tile, tileBase);
        scene->addItem(tileGraphicsItem.get());
        tileGraphicsItems.push_back(std::move(tileGraphicsItem));

    }

    /** baseFramesDir for portal is constant */
    QString portalBase = ":/images/portal/";
    // compute the exit tile index and set the picture
    const std::unique_ptr<TileModel>& exit = world->getTiles().at((world->getExit().yCoordinate) * world->getCols() + (world->getExit().xCoordinate));
    const std::unique_ptr<TileModel>& start = world->getTiles().at((world->getStart().yCoordinate) * world->getCols() + (world->getStart().xCoordinate));
    std::unique_ptr<PortalGraphicsItem> exitGraphicsItem = std::make_unique<PortalGraphicsItem>(*exit, portalBase);
    std::unique_ptr<PortalGraphicsItem> startGraphicsItem = std::make_unique<PortalGraphicsItem>(*start, portalBase);
    scene->addItem(exitGraphicsItem.get());
    scene->addItem(startGraphicsItem.get());
    portalGraphicsItems.push_back(std::move(exitGraphicsItem));
    portalGraphicsItems.push_back(std::move(startGraphicsItem));

    /** baseFramesDir for healthpack is constant */
    QString healthpackBase = ":/images/healthpack/";
    for (const auto& healthPack : healthPacks) {
        std::unique_ptr<HPGraphicsItem> healthPackGraphicsItem = std::make_unique<HPGraphicsItem>(*healthPack, healthpackBase);
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

    /** baseFramesDir for xenemy is constant */
    QString xenemyBase = ":/images/xenemy_wraith/PNG Sequences/";
    for (const auto& xenemy : xenemies) {
        std::unique_ptr<XEnemyGraphicsItem> xenemyGraphicsItem = std::make_unique<XEnemyGraphicsItem>(*xenemy, xenemyBase);
        scene->addItem(xenemyGraphicsItem.get());
        xenemyGraphicsItems.push_back(std::move(xenemyGraphicsItem));
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
    for (const auto& xenemyGraphicsItem : xenemyGraphicsItems) {
        if (xenemyGraphicsItem) {
            xenemyGraphicsItem->updatePosition();
        }
    }
    scene->setSceneRect(scene->itemsBoundingRect());
    this->update();
}


void Game2DView::setBackgroundNumber(int backgroundNumber){
    this->backgroundNumber = backgroundNumber;
}


void Game2DView::wheelEvent(QWheelEvent* event) {
    int delta = event->angleDelta().y() / 12 ;
    if (delta > 0) {
        zoomIn(std::abs(delta));  // Zoom in when the wheel is scrolled up
    }else{
        zoomOut(std::abs(delta)); // Zoom out when the wheel is scrolled down
    }
}


void Game2DView::setBackground(int backgroundNumber) {
    // Load the background image based on the difficulty level
    switch(backgroundNumber) {
    /** current tilewidth and height are set to 30 regardless case, yet for future ocassions if larger map it can be set to smaller */
    case 1: backgroundImage = Background1; tileWidth = 30; tileHeight = 30; break;
    case 2: backgroundImage = Background2; tileWidth = 30; tileHeight = 30; break;
    case 3: backgroundImage = Background3; tileWidth = 30; tileHeight = 30; break;
    case 4: backgroundImage = Background4; tileWidth = 30; tileHeight = 30; break;
    case 5: backgroundImage = Background5; tileWidth = 30; tileHeight = 30; break;
    default: backgroundImage= Background1; tileWidth = 30; tileHeight = 30; break;
    }

    backgroundImage = backgroundImage.scaled(tileWidth * world->getCols(),
                                             tileHeight * world->getRows(),
                                             Qt::KeepAspectRatioByExpanding);

    // Add the background image as a pixmap item to the scene
    QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(backgroundImage);
    backgroundItem->setZValue(-1); // Ensure it's drawn below all other items
    scene->addItem(backgroundItem);

    // Set the scene's rectangle to the size of the resized background image
    scene->setSceneRect(0, 0, backgroundImage.width(), backgroundImage.height());
    this->update();
}

void Game2DView::clearTileObservers() {
    for (const auto& tileGraphicsItem : tileGraphicsItems) {
        tileGraphicsItem->getTileModel().clearObservers();
    }
}

// This function should be called after setting the background and calculating tileWidth and tileHeight.
void Game2DView::scaleEntitiesToFitView() {
    qreal sceneWidth = scene->width();
    qreal sceneHeight = scene->height();
    qreal someFactor;
    switch(backgroundNumber){
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




