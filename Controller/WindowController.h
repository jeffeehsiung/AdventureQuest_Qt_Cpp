#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QPointer>
#include <QMainWindow>
#include <QLabel>
#include <vector>
#include "ViewControllerFactory.h"
#include "InputType.h"

class SignalButton; // Forward declaration as it appears to be a custom QObject based class

class WindowController {
public:
    explicit WindowController(ViewControllerFactory* factory);
    ~WindowController();

    void setup();
    QMainWindow* getMainWindow() const;
    QString getDifficulty() const;
    float getZoomRatio() const;

    void setRoomRatio(float ratio);
    void setDifficulty(const QString& difficulty);
    void handleInput(InputType input);
    void updateUserInterface();

private:
    QPointer<QMainWindow> mainWindow;
    std::unique_ptr<ViewControllerFactory> viewControllerFactory;
    QPointer<QObject> gameController;
    std::vector<QPointer<SignalButton>> signalButtons;

    QPointer<QLabel> difficultyLabel;
    QPointer<SignalButton> easyButton;
    QPointer<SignalButton> mediumButton;
    QPointer<SignalButton> hardButton;
    QPointer<SignalButton> multiplayerButton;
    QPointer<SignalButton> zoominButton;
    QPointer<SignalButton> zoomoutButton;

    float zoomRatio;
};

#endif // WINDOWCONTROLLER_H
