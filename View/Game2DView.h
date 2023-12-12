#ifndef GAME2DVIEW_H
#define GAME2DVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QtMath>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QWheelEvent>
#include "View/GameView.h"
#include "View/EntityGraphicsItem.h"
#include "View/TileGraphicsItem.h"
#include "View/ProtagonistGraphicsItem.h"
#include "View/EnemyGraphicsItem.h"
#include "Controller/WorldController.h"  // Include WorldController

class Game2DView : public QGraphicsView, public GameView {
    Q_OBJECT
public:
    explicit Game2DView(QWidget* parent = nullptr)
        : QGraphicsView(parent){
        easyBackground.load(":/images/world_images/worldmap.png");
        mediumBackground.load(":/images/world_images/maze1.png");
        hardBackground.load(":/images/world_images/maze2.png");
        zoomSpeed = 0.001; // Example value, adjust based on testing
        zoomLevel = 1.0;
        initZoomLevel = 1.0;
        scenes.push_back(new QGraphicsScene(this));
        scenes.push_back(new QGraphicsScene(this));
        scene = new QGraphicsScene(this);
        setScene(scenes[0]);
    }

    virtual ~Game2DView(){
        delete scene;
    }

    void addEntity(const Entity& entity) override;
    void animateEntityAction(int index, AnimationState newState) override;
    /**
     * @brief initializeView
     * @param worldController
     * the 2Dview/textview should instantiate the corresponding view/textedit,
     * create a scene, based on the given input worldController extracting the entities vector list and
     * based on which iteratively create grahpicsRectItems or entityTextItem(string) and
     * add it to the scene
     */
    void initializeView() override;
    void setBackground(int backgroundNumber) override;
    void zoomIn(int delta) override;
    void zoomOut(int delta) override;
    void updateView() override;
    void levelChange();

    void checkItems();

signals:
    /**
     * @brief updateSceneSignal
     * In your user interface, create two buttons, one for selecting 2D view and another for selecting text view.
     * Connect the button signals (e.g., clicked() signals) to slots in your view controller or main application class.
     * In these slots, based on the button pressed, you can decide whether to create an instance of Game2DView or GameTextView.
     * When instantiating the selected view, you can connect its signals (such as updateSceneSignal()) to slots
     * in your view controller or main application class that handle updating the view.
     */
    void updateSceneSignal() override;

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QGraphicsScene* scene;
    std::vector<QGraphicsScene*> scenes;
    QPixmap easyBackground;
    QPixmap mediumBackground;
    QPixmap hardBackground;
    QPixmap backgroundImage;
    int currentBackgroundNumber;
    qreal zoomSpeed; // Zoom sensitivity factor
    qreal zoomLevel;
    qreal initZoomLevel;

    qreal tileWidth;
    qreal tileHeight;

    std::vector<std::unique_ptr<EntityGraphicsItem>> entityGraphicsItems;
    std::vector<std::unique_ptr<TileGraphicsItem>> tileGraphicsItems;
    std::vector<std::unique_ptr<EnemyGraphicsItem>> enemyGraphicsItems;
    std::vector<std::unique_ptr<ProtagonistGraphicsItem>> protagonistGraphicsItems;

    void scaleEntitiesToFitView();

};

#endif // GAME2DVIEW_H
