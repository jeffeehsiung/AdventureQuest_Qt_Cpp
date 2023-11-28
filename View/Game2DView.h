// Game2DView.h

#ifndef GAME2DVIEW_H
#define GAME2DVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include <memory> // Include memory header for std::unique_ptr
#include "GameView.h"
#include "EntityGraphicsItem.h"

class Game2DView : public QGraphicsScene, public GameView {
    Q_OBJECT

private:
    QPixmap defaultBackground;
    QPixmap easyBackground;
    QPixmap mediumBackground;
    QPixmap hardBackground;
    int currentBackgroundNumber;

    qreal zoomLevel;

    std::vector<std::unique_ptr<EntityGraphicsItem>> entityGraphicsItems;

    void updateZoom();
    void setBackground(int backgroundNumber);

public:
    Game2DView(QWidget* parent = nullptr);

    void addEntity(std::unique_ptr<Entity> entity);
    void animateEntityAction(const QString& entity) override;
    void updateView() override;
    void zoomIn() override;
    void zoomOut() override;

signals:
    // Signal to indicate that the scene needs updating
    void updateSceneSignal();

};

#endif // GAME2DVIEW_H
