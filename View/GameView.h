#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QString>
#include <vector>
#include <memory>
#include "Controller/WorldController.h"
#include "Model/WorldModel.h"

class GameView {
public:
    virtual ~GameView(){}

    virtual void animateEntityAction(int index, AnimationState newState) = 0;
    virtual void addEntity(const Entity& entity) = 0;
    /**
     * @brief initializeView
     * @param worldController
     * the 2Dview/textview should instantiate the corresponding view/textedit,
     * create a scene, based on the given input worldController extracting the entities vector list and
     * based on which iteratively create grahpicsRectItems or entityTextItem(string) and
     * add it to the scene
     */
    virtual void initializeView(std::shared_ptr<WorldModel> world) = 0;
    virtual void setBackground(int backgroundNumber, std::shared_ptr<WorldModel> world) = 0;
    virtual void zoomIn(int delta) = 0;
    virtual void zoomOut(int delta) = 0;
    virtual void updateView() = 0;
signals:
    /**
     * @brief updateSceneSignal
     * In your user interface, create two buttons, one for selecting 2D view and another for selecting text view.
     * Connect the button signals (e.g., clicked() signals) to slots in your view controller or main application class.
     * In these slots, based on the button pressed, you can decide whether to create an instance of Game2DView or GameTextView.
     * When instantiating the selected view, you can connect its signals (such as updateSceneSignal()) to slots
     * in your view controller or main application class that handle updating the view.
     */
    virtual void updateSceneSignal() = 0;
};

#endif // GAMEVIEW_H
