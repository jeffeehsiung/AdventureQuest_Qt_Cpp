#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include <QObject>
#include <memory>
#include <QPointer> // Include QPointer
#include "Controller/WorldController.h"
#include "View/Game2DView.h"
#include "View/GameTextView.h"

class ViewController : public QObject {
    Q_OBJECT

public:
    static ViewController& getInstance() {
        static ViewController instance;
        return instance;
    }

    ViewController(ViewController const&) = delete;
    void operator=(ViewController const&) = delete;
    void initializeViews();

    QWidget* getCurrentView() const; // Function to get the current view

    void switchTo2DView();
    void switchToTextView();

public slots:
    void onUpdateProtagonistPosition(int protagonistIndex);
    void updateLevel();

signals:
    void viewUpdated(QWidget* currentView); // Modified signal

private:
    ViewController(QObject *parent = nullptr);
    WorldController& worldController;
    QPointer<Game2DView> game2DView; // Changed to QPointer
    QPointer<GameTextView> gameTextView; // Changed to QPointer
    QPointer<QWidget> currentView; // Changed to QPointer

};

#endif // VIEWCONTROLLER_H
