#include "GameController.h"

GameController::GameController(QObject *parent)
    : QObject(parent) {

}

void GameController::readGameStarted(bool isStarted) {
    isGameStarted = isStarted;
}

void GameController::readGamePaused(bool isPaused) {
    isGamePaused = isPaused;
}

void GameController::readGameAutoplayed(bool isAutoPlayed) {
    isGameAutoplayed = isAutoPlayed;
}

void GameController::readGameNumberOfPlayers(const QString &numberOfPlayers) {
    gameNumberOfPlayers = numberOfPlayers;
}

void GameController::readGameDifficultyLevel(const QString &difficultyLevel) {
    gameDifficultyLevel = difficultyLevel;
}

void GameController::printAllGameInfo() {
    qDebug() << "Game Info: "
            << "\nGame Started? " << isGameStarted
            << "\nGame Paused? " << isGamePaused
            << "\nGame Autoplayed? " << isGameAutoplayed
            << "\nNumber of Players: " << gameNumberOfPlayers
            << "\nDifficulty Level: " << gameDifficultyLevel << "\n";
}

/**
 * 1. pass worldcontroller to viewcontroller
 * 2. tell viewcontroller to draw the world
 * 3. tell viewcontorller to update the scene 
 * 4. give difficulty level to view controller
 * 5. in world controller, let it be able to identify poisoned tiles
 * 6. in world contorller, have a get methods of Penemy
 * 7. in world contoller, have a method to get xenemy
 * 8. auto play ... (path finder)
 * */
