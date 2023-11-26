#ifndef GAME2DVIEW_H
#define GAME2DVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include <memory>  // For std::unique_ptr
#include "GameView.h"
#include "EntityGraphicsItem.h"

class Game2DView : public QGraphicsView, public GameView {
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QPixmap backgroundPixmap;
    std::vector<std::unique_ptr<EntityGraphicsItem>> entityGraphicsItems; // Vector to hold unique pointers to entity graphics items
     std::vector<coordinate> entityPositions; // Vector to store entity positions

public:
    Game2DView(QWidget* parent = nullptr) : QGraphicsView(parent) {
        scene = new QGraphicsScene(this);
        this->setScene(scene);

        // Load the background image
        backgroundPixmap = QPixmap(":images/world_images/worldmap.png");
        setBackgroundBrush(QBrush(backgroundPixmap));

        // Configure the scene and view as necessary
    }

    // Implement GameView interface methods here, if any
    void addEntity(std::unique_ptr<EntityGraphicsItem> item);
    void updateView() override;
    void drawWorld() override;
    void switchView() override;
    void zoomIn() override;
    void zoomOut() override;
    void animateEntityAction(const QString& entity) override;


};

#endif // GAME2DVIEW_H
