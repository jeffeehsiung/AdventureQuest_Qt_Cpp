#ifndef GAME2DVIEW_H
#define GAME2DVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDebug>
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
        defaultBackground.load(":/images/background/road.png");
        easyBackground.load(":/images/background/road.png");
        mediumBackground.load(":/images/background/residence.png");
        hardBackground.load(":/images/background/houses.png");
        zoomLevel = 1.0;
        scene = new QGraphicsScene(this);
        setScene(scene);
    }

    virtual ~Game2DView(){
        delete scene;
    }

    void addEntity(const Entity& entity) override;
    void animateEntityAction(const QString& entity) override;
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
    void zoomIn() override;
    void zoomOut() override;
    void updateView() override;

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

private:
    QGraphicsScene* scene;
    QPixmap defaultBackground;
    QPixmap easyBackground;
    QPixmap mediumBackground;
    QPixmap hardBackground;
    QPixmap backgroundImage;
    int currentBackgroundNumber;
    qreal zoomLevel;

    void updateZoom();
//    void fitSceneToView();
//    qreal calculateScaleFactor(const QRectF& itemsRect);

    std::vector<std::unique_ptr<EntityGraphicsItem>> entityGraphicsItems;

};

#endif // GAME2DVIEW_H
