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
};

#endif // GAMEVIEW_H
