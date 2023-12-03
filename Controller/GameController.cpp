#include "GameController.h"

GameController::GameController(QObject *parent)
    : QObject(parent),
      isGameStarted(false),
      isGamePaused(false),
      isGameAutoplayed(false),
      gameNumberOfPlayers("1"),
      gameDifficultyLevel("Easy"),
      gameDifficultyIdx(1),
      gamePRatio(1.0),
      worldController(std::make_unique<WorldController>()),
      viewController(std::make_unique<ViewController>()) {

}

GameController::~GameController() {
    // Destructor for clean-up if necessary
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

void GameController::decideGameParameters() {
    switch (gameDifficultyLevel) {
    case "Easy":
        gameMap = "worldmap.png";
        gameDifficultyIdx = 1;
        gamePRatio = gameNumberOfPlayers == 1 ? 1.0 : 2.0;
        break;
    case "Medium":
        gameMap = "worldmap.png";
        gameDifficultyIdx = 2;
        gamePRatio = gameNumberOfPlayers == 1 ? 2.0 : 4.0;
        break;
    case "Hard":
        gameMap = "worldmap4.png";
        gameDifficultyIdx = 3;
        gamePRatio = gameNumberOfPlayers == 1 ? 3.0 : 6.0;
        break;
    default:
        break;
    }
}

void GameController::initializeWorld() {
    decideGameParameters(); // Ensure parameters are decided before initialization
    worldController->createWorld(gameMap, gameNumberOfPlayers.toInt(), gameDifficultyIdx, gamePRatio);
    viewController->setWorldController(worldController.get());
    // If the game should start immediately, you can call switchTo2DView or switchToTextView here
}

// Methods to switch between views

void GameController::switchTo2DView() {
    viewController->switchTo2DView();
}

void GameController::switchToTextView() {
    viewController->switchToTextView();
}

