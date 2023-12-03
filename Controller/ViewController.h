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
    static ViewController& getInstance() {
        static ViewController instance;
        return instance;
    }

    ViewController(ViewController const&) = delete;
    void operator=(ViewController const&) = delete;

public slots:
    void switchTo2DView();
    void switchToTextView();
    void handleUpdateScene();

signals:
    void viewSwitched(GameView* currentView);

private:
    ViewController(QObject *parent = nullptr);
    ~ViewController();

    void initializeViews();
    void syncState();

    std::unique_ptr<Game2DView> game2DView;
    std::unique_ptr<GameTextView> gameTextView;
    GameView* currentView;

};

#endif // VIEWCONTROLLER_H
