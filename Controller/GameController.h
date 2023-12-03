#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QString>
#include <QDebug>

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
    
    // Methods to switch views
    void switchTo2DView();
    void switchToTextView();

private:
    bool isGameStarted;
    bool isGamePaused;
    bool isGameAutoplayed;
    QString gameNumberOfPlayers;
    QString gameDifficultyLevel;
    QString gameMap;
    int gameDifficultyIdx;
    float gamePRatio;
};

#endif // GAMECONTROLLER_H
