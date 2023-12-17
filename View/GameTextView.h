#ifndef GAMETEXTVIEW_H
#define GAMETEXTVIEW_H

#include <QTextEdit>
#include <QDebug>
#include <vector>
#include <memory>
#include "View/GameView.h"
#include "View/EntityTextItem.h"

class GameTextView : public QTextEdit, public GameView {
    Q_OBJECT

public:
    GameTextView(QWidget* parent = nullptr) : QTextEdit(parent) {
        setReadOnly(true);
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
    void initializeView(std::shared_ptr<WorldModel> world) override;
    void setBackground(int backgroundNumber, std::shared_ptr<WorldModel> world) override;
    void zoomIn(int delta) override;
    void zoomOut(int delta) override;
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
    void displayScene(const QString& sceneString);
    std::vector<std::unique_ptr<EntityTextItem>> entityTextItems;
    QString backgroundString;
    QString sceneString;
};

#endif // GAMETEXTVIEW_H
