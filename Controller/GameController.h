#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QRegularExpression>
#include <functional>
#include <map>
#include <QStringList>
#include "Controller/WorldController.h"
#include "Controller/ViewController.h"

class GameController : public QObject {
    Q_OBJECT

public:
    explicit GameController(QObject *parent = nullptr);
    ~GameController();

    // Interface for MainWindow to notify about user actions
    void readGameStarted(bool isStarted);
    void readGamePaused(bool isPaused);
    void readGameAutoplayed(bool isAutoPlayed);
    void readGameNumberOfPlayers(const QString &numberOfPlayers);
    void readGameDifficultyLevel(const QString &difficultyLevel);
    void printAllGameInfo();
    void decideGameParameters();

    void initializeWorld();

    void switchTo2DView();
    void switchToTextView();

    void onUpArrowPressed();
    void onDownArrowPressed();
    void onLeftArrowPressed();
    void onRightArrowPressed();

//    void processCommand(const QString& command);
    void displayHelp() const;

    int getHealth1();
    int getEnergy1();

    bool isGameOver();
    void setGameOver();

public slots:
    void onViewUpdated(QWidget* currentView);
    void processCommand(const QString& command);

signals:
    void viewUpdateRequested(QWidget* currentView);
    void sendTextToGUI(const QString& text) const;

private:
    WorldController& worldController;
    ViewController& viewController;

    bool isGameStarted;
    bool isGamePaused;
    bool isGameAutoplayed;
    QString gameNumberOfPlayers;
    QString gameDifficultyLevel;
    QString gameMap;
    int gameDifficultyIdx;
    float gamePRatio;
    int gameHealth1;
    int gameEnergy1;

    std::map<QString, std::function<void(const QStringList&)>> commandMap;

    void updateHealthAndEnergy();
};

#endif // GAMECONTROLLER_H
