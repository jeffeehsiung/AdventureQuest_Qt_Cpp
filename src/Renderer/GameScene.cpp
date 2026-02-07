#include "Renderer/GameScene.h"
#include "Renderer/SpriteCache.h"
#include <QtMath>
#include <QScrollBar>
#include <QDebug>

namespace AQ {

// ---------- SpriteItem ----------

SpriteItem::SpriteItem(AnimationController anim, qreal tileW, qreal tileH, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent)
    , anim_(std::move(anim))
    , tileW_(tileW)
    , tileH_(tileH)
{
}

void SpriteItem::updateFrame(EntityState state) {
    const QPixmap& frame = anim_.advance(state);
    if (!frame.isNull()) {
        setPixmap(frame.scaled(static_cast<int>(tileW_), static_cast<int>(tileH_),
                               Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void SpriteItem::setGridPos(Vec2i pos) {
    setPos(pos.x * tileW_, pos.y * tileH_);
}

// ---------- GameScene ----------

GameScene::GameScene(QWidget* parent)
    : QGraphicsView(parent)
    , scene_(new QGraphicsScene(this))
{
    setScene(scene_);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setRenderHint(QPainter::SmoothPixmapTransform);
    setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);
    setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

    // Preload backgrounds
    backgrounds_[0].load(":/images/world_images/worldmap.png");
    backgrounds_[1].load(":/images/world_images/worldmap2.png");
    backgrounds_[2].load(":/images/world_images/worldmap3.png");
    backgrounds_[3].load(":/images/world_images/worldmap4.png");
    backgrounds_[4].load(":/images/world_images/worldmap5.png");

    // Animation tick
    connect(&animTimer_, &QTimer::timeout, this, [this]() { updateView(); });
    animTimer_.setInterval(Constants::AnimFrameMs);
}

GameScene::~GameScene() {
    animTimer_.stop();
}

void GameScene::initialize(const GameWorld& world, int levelIndex) {
    world_ = &world;
    tileW_ = PlatformConfig::defaultTileSize;
    tileH_ = PlatformConfig::defaultTileSize;
    buildScene(world, levelIndex);
    animTimer_.start();
}

void GameScene::setLevel(const GameWorld& world, int levelIndex) {
    world_ = &world;
    clearScene();
    buildScene(world, levelIndex);
}

void GameScene::cleanup() {
    animTimer_.stop();
    clearScene();
    world_ = nullptr;
}

void GameScene::clearScene() {
    tileSprites_.clear();
    healthPackSprites_.clear();
    enemySprites_.clear();
    playerSprite_ = nullptr;
    startPortal_ = nullptr;
    exitPortal_ = nullptr;
    background_ = nullptr;
    scene_->clear();
}

void GameScene::buildScene(const GameWorld& world, int levelIndex) {
    // Background
    int bgIdx = std::clamp(levelIndex, 0, Constants::WorldCount - 1);
    QPixmap bg = backgrounds_[bgIdx].scaled(
        static_cast<int>(tileW_ * world.cols()),
        static_cast<int>(tileH_ * world.rows()),
        Qt::KeepAspectRatioByExpanding);

    background_ = scene_->addPixmap(bg);
    background_->setZValue(-10);

    // Tiles
    auto tileAnim = tileAnimSet();
    for (const auto& tile : world.tiles()) {
        auto* sprite = new SpriteItem(AnimationController(tileAnim), tileW_, tileH_);
        sprite->setGridPos(tile.pos);
        sprite->setZValue(0);
        sprite->setOpacity(0.5); // semi-transparent tiles over background
        scene_->addItem(sprite);
        tileSprites_.push_back(sprite);
    }

    // Portals
    auto portalAnim = portalAnimSet();
    {
        auto* portal = new SpriteItem(AnimationController(portalAnim), tileW_, tileH_);
        portal->setGridPos(world.startPos());
        portal->setZValue(2);
        scene_->addItem(portal);
        startPortal_ = portal;
    }
    {
        auto* portal = new SpriteItem(AnimationController(portalAnim), tileW_, tileH_);
        portal->setGridPos(world.exitPos());
        portal->setZValue(2);
        scene_->addItem(portal);
        exitPortal_ = portal;
    }

    // Health packs
    auto hpAnim = healthPackAnimSet();
    for (const auto& hp : world.healthPacks()) {
        auto* sprite = new SpriteItem(AnimationController(hpAnim), tileW_, tileH_);
        sprite->setGridPos(hp.pos);
        sprite->setZValue(3);
        scene_->addItem(sprite);
        healthPackSprites_.push_back(sprite);
    }

    // Enemies
    for (const auto& enemy : world.enemies()) {
        auto eAnim = enemyAnimSet(enemy.type);
        auto* sprite = new SpriteItem(AnimationController(eAnim), tileW_, tileH_);
        sprite->setGridPos(enemy.pos);
        sprite->setZValue(4);
        scene_->addItem(sprite);
        enemySprites_.push_back(sprite);
    }

    // Player
    auto pAnim = protagonistAnimSet(0);
    playerSprite_ = new SpriteItem(AnimationController(pAnim), tileW_, tileH_);
    playerSprite_->setGridPos(world.player().pos);
    playerSprite_->setZValue(10);
    scene_->addItem(playerSprite_);

    // Fit view
    scene_->setSceneRect(0, 0, bg.width() + tileW_, bg.height() + tileH_);
    fitInView(scene_->sceneRect(), Qt::KeepAspectRatio);
}

void GameScene::updateView() {
    if (!world_) return;

    // Update tile animations (for poisoned/thundered tiles)
    for (size_t i = 0; i < tileSprites_.size() && i < world_->tiles().size(); ++i) {
        tileSprites_[i]->updateFrame(world_->tiles()[i].animState);
    }

    // Update health pack positions
    for (size_t i = 0; i < healthPackSprites_.size() && i < world_->healthPacks().size(); ++i) {
        healthPackSprites_[i]->setGridPos(world_->healthPacks()[i].pos);
        healthPackSprites_[i]->updateFrame(world_->healthPacks()[i].animState);
    }

    // Update enemies
    for (size_t i = 0; i < enemySprites_.size() && i < world_->enemies().size(); ++i) {
        const auto& enemy = world_->enemies()[i];
        enemySprites_[i]->setGridPos(enemy.pos);
        enemySprites_[i]->updateFrame(enemy.animState);
        enemySprites_[i]->setVisible(!enemy.defeated);
    }

    // Update player
    if (playerSprite_) {
        playerSprite_->setGridPos(world_->player().pos);
        playerSprite_->updateFrame(world_->player().animState);
    }

    // Update portals
    if (startPortal_) startPortal_->updateFrame(EntityState::Idle);
    if (exitPortal_) exitPortal_->updateFrame(EntityState::Idle);

    scene_->update();
}

void GameScene::wheelEvent(QWheelEvent* event) {
    int delta = event->angleDelta().y();
    qreal factor = (delta > 0) ? 1.1 : 0.9;

    zoomLevel_ *= factor;
    zoomLevel_ = std::clamp(zoomLevel_, 0.2, 4.0);

    setTransform(QTransform::fromScale(zoomLevel_, zoomLevel_));
    if (playerSprite_) {
        centerOn(playerSprite_);
    }
}

// ---------- Animation set builders ----------

AnimationController::AnimSet GameScene::protagonistAnimSet(int index) {
    QString bases[] = {
        ":/images/protagonist_fighter/",
        ":/images/protagonist_samurai/",
        ":/images/protagonist_shinobi/"
    };
    int idx = std::clamp(index, 0, 2);
    QString base = bases[idx];
    return {
        base + "Idle",
        base + "Moving",
        base + "Attack",
        base + "Hurt",
        base + "Dying",
        base + "Heal"
    };
}

AnimationController::AnimSet GameScene::enemyAnimSet(EnemyType type) {
    switch (type) {
        case EnemyType::Regular:
            return {
                ":/images/enemy_golem/PNG Sequences/Idle",
                ":/images/enemy_golem/PNG Sequences/Walking",
                ":/images/enemy_golem/PNG Sequences/Attacking",
                ":/images/enemy_golem/PNG Sequences/Hurt",
                ":/images/enemy_golem/PNG Sequences/Dying",
                ":/images/enemy_golem/PNG Sequences/Heal"
            };
        case EnemyType::Poison:
            return {
                ":/images/penemy_wraith/PNG Sequences/Idle",
                ":/images/penemy_wraith/PNG Sequences/Walking",
                ":/images/penemy_wraith/PNG Sequences/Attacking",
                ":/images/penemy_wraith/PNG Sequences/Hurt",
                ":/images/penemy_wraith/PNG Sequences/Dying",
                ":/images/penemy_wraith/PNG Sequences/Casting Spells"
            };
        case EnemyType::Thunder:
            return {
                ":/images/xenemy_wraith/PNG Sequences/Idle",
                ":/images/xenemy_wraith/PNG Sequences/Walking",
                ":/images/xenemy_wraith/PNG Sequences/Attacking",
                ":/images/xenemy_wraith/PNG Sequences/Hurt",
                ":/images/xenemy_wraith/PNG Sequences/Dying",
                ":/images/xenemy_wraith/PNG Sequences/Casting Spells"
            };
    }
    return {};
}

AnimationController::AnimSet GameScene::tileAnimSet() {
    return {
        ":/images/tiles/Idle",
        ":/images/tiles/Moving",
        ":/images/tiles/Attack",
        "",
        "",
        ""
    };
}

AnimationController::AnimSet GameScene::healthPackAnimSet() {
    return {":/images/healthpack/Idle", "", "", "", "", ""};
}

AnimationController::AnimSet GameScene::portalAnimSet() {
    return {":/images/portal/Idle", "", "", "", "", ""};
}

} // namespace AQ
