#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QString>
#include <QDebug>

class GameController : public QObject
{
    Q_OBJECT

public:
    explicit GameController(QObject *parent = nullptr);
    void readGameStarted(bool isStarted);
    void readGamePaused(bool isPaused);
    void readGameAutoplayed(bool isAutoPlayed);
    void readGameNumberOfPlayers(const QString &numberOfPlayers);
    void readGameDifficultyLevel(const QString &difficultyLevel);
    void printAllGameInfo();

private:
    bool isGameStarted;
    bool isGamePaused;
    bool isGameAutoplayed;
    QString gameNumberOfPlayers;
    QString gameDifficultyLevel;
};

#endif // GAMECONTROLLER_H
