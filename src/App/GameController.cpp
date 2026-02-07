#include "App/GameController.h"
#include "Renderer/SpriteCache.h"
#include <QDebug>

namespace AQ {

GameController::GameController(QObject* parent)
    : QObject(parent)
{
    // Wire up GameState signals
    connect(&state_, &GameState::statusChanged, this, &GameController::statusUpdated);
    connect(&state_, &GameState::gameWon, this, &GameController::gameWon);
    connect(&state_, &GameState::gameLost, this, &GameController::gameLost);
    connect(&state_, &GameState::autoPlayFinished, this, &GameController::autoPlayDone);
    connect(&state_, &GameState::textMessage, this, &GameController::textMessage);

    connect(&state_, &GameState::levelChanged, this, [this](int level) {
        if (scene_ && state_.currentWorld()) {
            scene_->setLevel(*state_.currentWorld(), level);
        }
        emit levelChanged(level);
    });

    connect(&state_, &GameState::viewNeedsUpdate, this, [this]() {
        if (scene_) scene_->updateView();
    });

    setupCommandMap();
}

GameController::~GameController() = default;

void GameController::initializeScene(QWidget* parent) {
    scene_ = std::make_unique<GameScene>(parent);
}

void GameController::startGame(Difficulty difficulty, int playerCount) {
    // Preload sprites for fast rendering
    SpriteCache::instance().preloadAll();

    state_.startGame(difficulty, playerCount);

    if (scene_ && state_.currentWorld()) {
        scene_->initialize(*state_.currentWorld(), 0);
        emit viewReady(scene_.get());
    }
}

void GameController::pauseGame() {
    state_.pauseGame();
}

void GameController::resumeGame() {
    state_.resumeGame();
}

void GameController::autoPlay() {
    state_.autoPlay();
}

void GameController::quitGame() {
    if (scene_) scene_->cleanup();
    state_.quitGame();
}

void GameController::handleAction(InputAction action) {
    if (state_.isGameOver() || !state_.isRunning()) return;

    switch (action) {
        case InputAction::MoveUp:    state_.movePlayer(Direction::Up); break;
        case InputAction::MoveDown:  state_.movePlayer(Direction::Down); break;
        case InputAction::MoveLeft:  state_.movePlayer(Direction::Left); break;
        case InputAction::MoveRight: state_.movePlayer(Direction::Right); break;
        case InputAction::Attack:    state_.attackNearest(); break;
        case InputAction::TakeItem:  state_.takeNearest(); break;
        case InputAction::AutoPlay:  state_.autoPlay(); break;
        case InputAction::Pause:     state_.pauseGame(); break;
        case InputAction::Quit:      quitGame(); break;
    }
}

void GameController::setupCommandMap() {
    commandMap_["up"]    = [this](const QStringList&) { handleAction(InputAction::MoveUp); };
    commandMap_["down"]  = [this](const QStringList&) { handleAction(InputAction::MoveDown); };
    commandMap_["left"]  = [this](const QStringList&) { handleAction(InputAction::MoveLeft); };
    commandMap_["right"] = [this](const QStringList&) { handleAction(InputAction::MoveRight); };
    commandMap_["attack"] = [this](const QStringList&) { handleAction(InputAction::Attack); };
    commandMap_["take"]  = [this](const QStringList&) { handleAction(InputAction::TakeItem); };
    commandMap_["help"]  = [this](const QStringList&) { displayHelp(); };

    commandMap_["goto"]  = [this](const QStringList& args) {
        if (args.size() >= 3) {
            int x = args[1].toInt();
            int y = args[2].toInt();
            state_.movePlayerTo({x, y});
        }
    };
}

void GameController::processCommand(const QString& command) {
    static QRegularExpression regex("\\s+");
    QStringList args = command.split(regex, Qt::SkipEmptyParts);
    if (args.isEmpty()) return;

    QString action = args.first().toLower();
    auto it = commandMap_.find(action);
    if (it != commandMap_.end()) {
        it->second(args);
    } else {
        displayHelp();
    }
}

void GameController::displayHelp() {
    QString helpText =
        "Available commands:\n"
        "  up/down/left/right - Move the hero\n"
        "  goto x y           - Move to coordinates\n"
        "  attack              - Attack nearest enemy\n"
        "  take                - Take nearest health pack\n"
        "  help                - Show this help\n";

    emit textMessage(helpText);
}

} // namespace AQ
