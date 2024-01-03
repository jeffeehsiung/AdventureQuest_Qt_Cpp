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


class Game2DView : public QGraphicsView, public GameView {
    Q_OBJECT
public:
    explicit Game2DView(QWidget* parent = nullptr)
        : QGraphicsView(parent){
        easyBackground.load(":/images/world_images/worldmap.png");
//        mediumBackground.load(":/images/world_images/maze1.png");
//        hardBackground.load(":/images/world_images/maze2.png");
        zoomSpeed = 0.001; // Example value, adjust based on testing
        zoomLevel = 1.0;
        initZoomLevel = 1.0;
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scene = new QGraphicsScene(this);
        setScene(scene);
    }

    virtual ~Game2DView(){
        delete scene;
    }

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
    void checkItems();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QGraphicsScene* scene;
    QPixmap easyBackground;
//    QPixmap mediumBackground;
//    QPixmap hardBackground;
    QPixmap backgroundImage;
    int currentBackgroundNumber;
    qreal zoomSpeed; // Zoom sensitivity factor
    qreal zoomLevel;
    qreal initZoomLevel;

    qreal tileWidth;
    qreal tileHeight;

    std::vector<std::unique_ptr<TileGraphicsItem>> healthpackGraphicsItems;
    std::vector<std::unique_ptr<TileGraphicsItem>> tileGraphicsItems;
    std::vector<std::unique_ptr<EnemyGraphicsItem>> enemyGraphicsItems;
    std::vector<std::unique_ptr<PEnemyGraphicsItem>> penemyGraphicsItems;
    std::vector<std::unique_ptr<XEnemyGraphicsItem>> xenemyGraphicsItems;
    std::vector<std::unique_ptr<ProtagonistGraphicsItem>> protagonistGraphicsItems;

    std::unique_ptr<TileGraphicsItem> portalGraphicsItem;

    void scaleEntitiesToFitView();


};

#endif // GAME2DVIEW_H
