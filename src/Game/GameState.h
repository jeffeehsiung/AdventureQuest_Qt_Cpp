#ifndef AQ_GAME_GAMESTATE_H
#define AQ_GAME_GAMESTATE_H

#include "Core/Types.h"
#include "Core/Event.h"
#include "Game/GameWorld.h"
#include "Game/CombatSystem.h"
#include "Game/MovementSystem.h"
#include <QObject>
#include <QTimer>
#include <vector>
#include <memory>

namespace AQ {

// GameState manages the entire game session: world stack, player progression,
// game flow (start/pause/autoplay). This replaces the old WorldController singleton.
// It owns all GameWorlds and coordinates systems (Combat, Movement).

class GameState : public QObject {
    Q_OBJECT

public:
    explicit GameState(QObject* parent = nullptr);
    ~GameState();

    // Session lifecycle
    void startGame(Difficulty difficulty, int playerCount);
    void pauseGame();
    void resumeGame();
    void quitGame();

    // Player actions
    void movePlayer(Direction dir);
    void movePlayerTo(Vec2i target);
    void autoPlay();
    void attackNearest();
    void takeNearest();

    // State queries
    bool isRunning() const { return running_; }
    bool isPaused() const { return paused_; }
    bool isGameOver() const { return gameOver_; }
    int currentLevel() const { return static_cast<int>(currentWorldIdx_); }

    GameWorld* currentWorld();
    const GameWorld* currentWorld() const;

    float heuristicWeight() const { return heuristicWeight_; }
    void setHeuristicWeight(float w) { heuristicWeight_ = w; }

signals:
    void worldInitialized();
    void viewNeedsUpdate();
    void levelChanged(int newLevel);
    void gameWon();
    void gameLost();
    void statusChanged(int health, float energy);
    void autoPlayFinished();
    void textMessage(const QString& msg);

private:
    void createWorlds(Difficulty difficulty, int playerCount);
    void checkLevelTransition();
    void processMove();

    std::vector<std::unique_ptr<GameWorld>> worlds_;
    size_t currentWorldIdx_ = 0;

    bool running_ = false;
    bool paused_ = false;
    bool gameOver_ = false;

    float heuristicWeight_ = 1.0f;
    Difficulty difficulty_ = Difficulty::Easy;
    int playerCount_ = 1;

    // Track enemy kill counts for energy rewards
    int prevEnemyDefeated_ = 0;
    int prevPoisonDefeated_ = 0;
    int prevThunderDefeated_ = 0;
};

} // namespace AQ

#endif // AQ_GAME_GAMESTATE_H
