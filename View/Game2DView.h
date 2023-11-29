#ifndef GAME2DVIEW_H
#define GAME2DVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include "GameView.h"
#include "EntityGraphicsItem.h"
#include "TileGraphicsItem.h"
#include "ProtagonistGraphicsItem.h"
#include "EnemyGraphicsItem.h"

class Game2DView : public QGraphicsView, public GameView {
    Q_OBJECT
public:
    Game2DView(QWidget* parent, int difficulty) : QGraphicsView(parent), scene(nullptr), currentBackgroundNumber(difficulty), zoomLevel(1.0) {
        defaultBackground.load(":/images/world_images/worldmap4.png");
        easyBackground.load(":/images/world_images/maze1.png");
        mediumBackground.load(":/images/world_images/maze2.png");
        hardBackground.load(":/images/world_images/maze3.png");
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
    void initializeView(const WorldController& worldController) override;
    void setBackground(int backgroundNumber) override;
    void zoomIn() override;
    void zoomOut() override;
    void updateView() override;

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
    int currentBackgroundNumber;
    qreal zoomLevel;

    std::vector<std::unique_ptr<EntityGraphicsItem>> entityGraphicsItems;
    void updateZoom();

};

#endif // GAME2DVIEW_H
