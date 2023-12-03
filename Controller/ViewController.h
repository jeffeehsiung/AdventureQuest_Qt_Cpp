#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <memory>
#include "View/Game2DView.h"
#include "View/GameTextView.h"
#include "Controller/WorldController.h"

class ViewController : public QObject {
    Q_OBJECT

public:
    explicit ViewController(QObject *parent = nullptr);
    ~ViewController();

    void setWorldController(std::shared_ptr<WorldController> worldController);

public slots:
    void switchTo2DView();
    void switchToTextView();
    void handleUpdateScene();

signals:
    void viewSwitched(GameView* currentView);

private:
    std::shared_ptr<WorldController> worldController;
    std::unique_ptr<Game2DView> game2DView;
    std::unique_ptr<GameTextView> gameTextView;
    GameView* currentView;

    void syncState();
    void initializeViews();
};

#endif // VIEWCONTROLLER_H
