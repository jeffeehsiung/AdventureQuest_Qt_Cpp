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
        scene->addItem(tileGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(tileGraphicsItem));
    }

    /** baseFramesDir for healthpack is constant */
    QString healthpackBase = ":/images/healthpack/";
    for (const auto& healthPack : healthPacks) {
        std::unique_ptr<EntityGraphicsItem> healthPackGraphicsItem = std::make_unique<TileGraphicsItem>(*healthPack, healthpackBase);
        scene->addItem(healthPackGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(healthPackGraphicsItem));
    }

    /** baseFramesDir for enemy is constant */
    QString enemyBase = ":/images/enemy_golem/PNG Sequences/";
    for (const auto& enemy : enemies) {
        std::unique_ptr<EnemyGraphicsItem> enemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*enemy, enemyBase);
        scene->addItem(enemyGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(enemyGraphicsItem));
    }

    /** baseFramesDir for penemy is constant */
    QString penemyBase = ":/images/penemy_wraith/PNG Sequences/";
    for (const auto& penemy : penemies) {
        std::unique_ptr<EnemyGraphicsItem> penemyGraphicsItem = std::make_unique<EnemyGraphicsItem>(*penemy, penemyBase);
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
        scene->addItem(protagonistGraphicsItem.get());
        entityGraphicsItems.push_back(std::move(protagonistGraphicsItem));
    }
    updateView();
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
    scene->clear();
    setBackground(currentBackgroundNumber);
    for (const auto& entityGraphicsItem : entityGraphicsItems) {
        if (entityGraphicsItem) {
            entityGraphicsItem->updatePosition();
            EntityGraphicsItem* typedEntityItem = dynamic_cast<EntityGraphicsItem*>(entityGraphicsItem.get());
            if (typedEntityItem) {
                scene->addItem(typedEntityItem);
            }
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
    updateView();
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



