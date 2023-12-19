#ifndef GAMETEXTVIEW_H
#define GAMETEXTVIEW_H

#include <QTextEdit>
#include <QDebug>
#include <vector>
#include <memory>
#include "View/GameView.h"
#include "View/EntityTextItem.h"
#include "Controller/WorldController.h"  // Include WorldController

class GameTextView : public QTextEdit, public GameView {
    Q_OBJECT

public:
    GameTextView(QWidget* parent = nullptr) : QTextEdit(parent) {
        setReadOnly(true);
    }

    void addEntity(const Entity& entity) override;

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

private:
    void displayScene(const QString& sceneString);
    std::vector<std::unique_ptr<EntityTextItem>> entityTextItems;
    QString backgroundString;
    QString sceneString;
};

#endif // GAMETEXTVIEW_H
