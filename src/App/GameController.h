#ifndef AQ_APP_GAME_CONTROLLER_H
#define AQ_APP_GAME_CONTROLLER_H

#include "Core/Types.h"
#include "Game/GameState.h"
#include "Renderer/GameScene.h"
#include <QObject>
#include <QRegularExpression>
#include <map>
#include <functional>

namespace AQ {

// GameController bridges user input (keyboard, touch, text commands)
// to the GameState. It maps raw input to game actions and coordinates
// the renderer with game state updates.

class GameController : public QObject {
    Q_OBJECT

public:
    explicit GameController(QObject* parent = nullptr);
    ~GameController();

    // Game lifecycle
    void startGame(Difficulty difficulty, int playerCount);
    void pauseGame();
    void resumeGame();
    void autoPlay();
    void quitGame();

    // Input
    void handleAction(InputAction action);
    void processCommand(const QString& command);

    // State queries
    GameState& gameState() { return state_; }
    const GameState& gameState() const { return state_; }
    GameScene* gameScene() { return scene_.get(); }

    void initializeScene(QWidget* parent);

signals:
    void viewReady(QWidget* sceneWidget);
    void textMessage(const QString& text);
    void statusUpdated(int health, float energy);
    void gameWon();
    void gameLost();
    void autoPlayDone();
    void levelChanged(int level);

private:
    void setupCommandMap();
    void displayHelp();

    GameState state_;
    std::unique_ptr<GameScene> scene_;

    using CmdHandler = std::function<void(const QStringList&)>;
    std::map<QString, CmdHandler> commandMap_;
};

} // namespace AQ

#endif // AQ_APP_GAME_CONTROLLER_H
