#include "GameController.h"

GameController::GameController(QObject *parent)
    : QObject(parent),
    isGameStarted(false),
    isGamePaused(false),
    isGameAutoplayed(false)
{
    /** set up connections: viewcontroller to gamecontroller */
    auto& viewController = ViewController::getInstance();
    connect(&viewController, &ViewController::viewUpdated, this, &GameController::onViewUpdated);
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
    if (gameDifficultyLevel == "Easy") {
        gameMap = ":/images/world_images/worldmap.png";
        gameDifficultyIdx = 1;
        gamePRatio = (gameNumberOfPlayers.toInt() == 1) ? 0.1 : 0.2;
    } else if (gameDifficultyLevel == "Medium") {
        gameMap = ":/images/world_images/maze1.png";
        gameDifficultyIdx = 2;
        gamePRatio = (gameNumberOfPlayers.toInt() == 1) ? 0.2 : 0.4;
    } else if (gameDifficultyLevel == "Hard") {
        gameMap = ":/images/world_images/maze2.png";
        gameDifficultyIdx = 3;
        gamePRatio = (gameNumberOfPlayers.toInt() == 1) ? 0.3 : 0.6;
    }

}

void GameController::initializeWorld() {
    decideGameParameters();

    auto& worldController = WorldController::getInstance();
    worldController.createWorld(gameMap, gameNumberOfPlayers.toInt(), gameDifficultyIdx, gamePRatio);

    auto& viewController = ViewController::getInstance();
    viewController.initializeViews(); // Optional: switch to initial view

}

// Methods to switch between views
void GameController::switchTo2DView() {
    auto& viewController = ViewController::getInstance();
    viewController.switchTo2DView();
}

void GameController::switchToTextView() {
    auto& viewController = ViewController::getInstance();
    viewController.switchToTextView();
}

void GameController::onViewUpdated(QWidget* currentView) {
    emit viewUpdateRequested(currentView);
}

void GameController::onUpArrowPressed() {
    auto& worldController = WorldController::getInstance();
    if (isGameStarted) {
        qDebug() << "UP!" << "\n";
        worldController.onUpArrowPressed();
    }
}

void GameController::onDownArrowPressed() {
    auto& worldController = WorldController::getInstance();
    if (isGameStarted) {
        qDebug() << "DOWN!" << "\n";
        worldController.onDownArrowPressed();
    }
}

void GameController::onLeftArrowPressed() {
    auto& worldController = WorldController::getInstance();
    if (isGameStarted) {
        qDebug() << "LEFT!" << "\n";
        worldController.onLeftArrowPressed();
    }
}

void GameController::onRightArrowPressed() {
    auto& worldController = WorldController::getInstance();
    if (isGameStarted) {
        qDebug() << "RIGHT!" << "\n";
        worldController.onRightArrowPressed();
    }
}
