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
    QPixmap defaultBackground;
    QPixmap easyBackground;
    QPixmap mediumBackground;
    QPixmap hardBackground;
    int currentBackgroundNumber;
    std::vector<std::unique_ptr<EntityGraphicsItem>> entityGraphicsItems; // Vector to hold unique pointers to entity graphics items
    std::vector<coordinate> entityPositions; // Vector to store entity positions

public:
    Game2DView(QWidget* parent) : QGraphicsView(parent), currentBackgroundNumber(1) {
        scene = new QGraphicsScene(this);
        this->setScene(scene);

        // Load background images
        defaultBackground.load(":/images/world_images/worldmap4.png");
        easyBackground.load(":/images/world_images/maze1.png");
        mediumBackground.load(":/images/world_images/maze2.png");
        hardBackground.load(":/images/world_images/maze3.png");

        // Set default background or based on initial game state
        setBackgroundBrush(QBrush(defaultBackground));
    }


    // Implement GameView interface methods here, if any
    void addEntity(std::unique_ptr<EntityGraphicsItem> item);
    void animateEntityAction(const QString& entity) override;
    void drawWorld() override;
    void setBackground(int backgroundNumber);
    void updateView() override;
    void zoomIn() override;
    void zoomOut() override;


};

#endif // GAME2DVIEW_H
