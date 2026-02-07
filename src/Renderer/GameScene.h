#ifndef AQ_RENDERER_GAME_SCENE_H
#define AQ_RENDERER_GAME_SCENE_H

#include "Core/Types.h"
#include "Game/GameWorld.h"
#include "Platform/IRenderer.h"
#include "Platform/PlatformConfig.h"
#include "Renderer/AnimationController.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QWheelEvent>
#include <QPainter>
#include <vector>
#include <memory>

namespace AQ {

// Lightweight graphics item that draws a single animated entity.
// Uses AnimationController for frame management.

class SpriteItem : public QGraphicsPixmapItem {
public:
    SpriteItem(AnimationController anim, qreal tileW, qreal tileH, QGraphicsItem* parent = nullptr);

    void updateFrame(EntityState state);
    void setGridPos(Vec2i pos);

    AnimationController& animator() { return anim_; }

private:
    AnimationController anim_;
    qreal tileW_, tileH_;
};

// ---------- GameScene: main Qt rendering widget ----------
// Implements IRenderer using QGraphicsView/QGraphicsScene.
// Manages all sprite items, background, and viewport.

class GameScene : public QGraphicsView, public IRenderer {
    Q_OBJECT

public:
    explicit GameScene(QWidget* parent = nullptr);
    ~GameScene() override;

    // IRenderer
    void initialize(const GameWorld& world, int levelIndex) override;
    void updateView() override;
    void setLevel(const GameWorld& world, int levelIndex) override;
    void cleanup() override;

protected:
    void wheelEvent(QWheelEvent* event) override;

private:
    void buildScene(const GameWorld& world, int levelIndex);
    void clearScene();
    AnimationController::AnimSet protagonistAnimSet(int index);
    AnimationController::AnimSet enemyAnimSet(EnemyType type);
    AnimationController::AnimSet tileAnimSet();
    AnimationController::AnimSet healthPackAnimSet();
    AnimationController::AnimSet portalAnimSet();

    QGraphicsScene* scene_ = nullptr;
    const GameWorld* world_ = nullptr;

    // Sprite items (non-owning ptrs; scene owns the QGraphicsItems)
    std::vector<SpriteItem*> tileSprites_;
    std::vector<SpriteItem*> healthPackSprites_;
    std::vector<SpriteItem*> enemySprites_;
    SpriteItem* playerSprite_ = nullptr;
    SpriteItem* startPortal_ = nullptr;
    SpriteItem* exitPortal_ = nullptr;

    QGraphicsPixmapItem* background_ = nullptr;

    QTimer animTimer_;
    qreal tileW_ = Constants::TileSize;
    qreal tileH_ = Constants::TileSize;
    qreal zoomLevel_ = PlatformConfig::defaultZoomLevel;

    QPixmap backgrounds_[Constants::WorldCount];
};

} // namespace AQ

#endif // AQ_RENDERER_GAME_SCENE_H
