#include "GameController.h"

GameController::GameController(QObject *parent)
    : QObject(parent),
    worldController(WorldController::getInstance()),
    viewController(ViewController::getInstance()),
    isGameStarted(false),
    isGamePaused(false),
    isGameAutoplayed(false)
{
    /** set up connections: viewcontroller to gamecontroller */
    connect(&viewController, &ViewController::viewUpdated, this, &GameController::onViewUpdated);

    // Setup the command map
    commandMap["up"] = [this](const QStringList& args) { Q_UNUSED(args); worldController.moveProtagonist(UP); };
    commandMap["down"] = [this](const QStringList& args) { Q_UNUSED(args); worldController.moveProtagonist(DOWN); };
    commandMap["left"] = [this](const QStringList& args) { Q_UNUSED(args); worldController.moveProtagonist(LEFT); };
    commandMap["right"] = [this](const QStringList& args) { Q_UNUSED(args); worldController.moveProtagonist(RIGHT); };
    commandMap["goto"] = [this](const QStringList& args) {
        if(args.size() >= 3) {
            int x = args[1].toInt();
            int y = args[2].toInt();
            worldController.moveProtagonist(x, y);
        }
    };
    commandMap["help"] = [this](const QStringList& args) {
        Q_UNUSED(args); // This macro indicates that the args parameter is intentionally unused
        this->displayHelp();
    };
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
        gameMap = ":/images/world_images/worldmap2.png";
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

    worldController.createWorld(gameMap, gameNumberOfPlayers.toInt(), gameDifficultyIdx, gamePRatio);
    worldController.getCurrentWorld().getProtagonists()[0]->setHealth(5);
    worldController.getCurrentWorld().getProtagonists()[0]->setEnergy(100);
    gameHealth1 = worldController.getCurrentWorld().getProtagonists()[0]->getHealth();
    gameEnergy1 = worldController.getCurrentWorld().getProtagonists()[0]->getEnergy();

    viewController.initializeViews();
}

void GameController::reInitializeWorld() {
    worldController.getCurrentWorld().getProtagonists()[0]->setHealth(5);
    worldController.getCurrentWorld().getProtagonists()[0]->setEnergy(100);
    gameHealth1 = worldController.getCurrentWorld().getProtagonists()[0]->getHealth();
    gameEnergy1 = worldController.getCurrentWorld().getProtagonists()[0]->getEnergy();
}

// Methods to switch between views
void GameController::switchTo2DView() {
    viewController.switchTo2DView();
}

void GameController::switchToTextView() {
    viewController.switchToTextView();
}

void GameController::onViewUpdated(QWidget* currentView) {
    emit viewUpdateRequested(currentView);
}

void GameController::onUpArrowPressed() {
    if (isGameStarted) {
        worldController.moveProtagonist(UP);
        updateHealthAndEnergy();
    }
}

void GameController::onDownArrowPressed() {
    if (isGameStarted) {
        worldController.moveProtagonist(DOWN);
        updateHealthAndEnergy();
    }
}

void GameController::onLeftArrowPressed() {
    if (isGameStarted) {
        worldController.moveProtagonist(LEFT);
        updateHealthAndEnergy();
    }
}

void GameController::onRightArrowPressed() {
    if (isGameStarted) {
        worldController.moveProtagonist(RIGHT);
        updateHealthAndEnergy();
    }
}

void GameController::updateHealthAndEnergy() {
    gameHealth1 = worldController.getCurrentWorld().getProtagonists()[0]->getHealth();
    gameEnergy1 = worldController.getCurrentWorld().getProtagonists()[0]->getEnergy();
    qDebug() << "Health: " << gameHealth1 << "Energy: " << gameEnergy1;
}


int GameController::getHealth1() {
    return gameHealth1;
}

float GameController::getEnergy1() {
    return gameEnergy1;
}

bool GameController::isGameOver() {
    if (!isGameStarted) {
        return true;
    }
    else {
        return false;
    }
}

void GameController::setGameOver() {
    isGameStarted = false;
}

void GameController::processCommand(const QString& command) {
    QStringList args = command.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    QString action = args.first().toLower();

    auto cmdIter = commandMap.find(action);
    if (cmdIter != commandMap.end()) {
        cmdIter->second(args); // Execute the command
    } else {
        qDebug() << "Unknown command";
        displayHelp();
    }
}


void GameController::displayHelp() const {
    QString helpText =
        "Available commands:\n"
        "  - up: Move the protagonist up\n"
        "  - down: Move the protagonist down\n"
        "  - left: Move the protagonist left\n"
        "  - right: Move the protagonist right\n"
        "  - goto x y: Move to the specified coordinates (x, y)\n"
        "  - attack: Attack the nearest enemy\n"
        "  - take: Take the nearest health pack\n"
        "  - help: Display this help text\n";

    qDebug() << helpText;
    emit sendTextToGUI(helpText);
}


//void GameController::onUpArrowPressed() {
//    if (isGameStarted) {
//        worldController.onUpArrowPressed();
//        gameHealth1 = worldController.getCurrentWorld().getProtagonists()[0]->getHealth();
//    }
//}

//void GameController::onDownArrowPressed() {
//    if (isGameStarted) {
//        worldController.onDownArrowPressed();
//        gameHealth1 =worldController.getCurrentWorld().getProtagonists()[0]->getHealth();
//    }
//}

//void GameController::onLeftArrowPressed() {
//    if (isGameStarted) {
//        worldController.onLeftArrowPressed();
//        gameHealth1 = worldController.getCurrentWorld().getProtagonists()[0]->getHealth();
//    }
//}

//void GameController::onRightArrowPressed() {
//    if (isGameStarted) {
//        worldController.onRightArrowPressed();
//        gameHealth1 = worldController.getCurrentWorld().getProtagonists()[0]->getHealth();
//    }
//}
