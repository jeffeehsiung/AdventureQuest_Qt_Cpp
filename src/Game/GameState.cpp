#include "Game/GameState.h"
#include <QDebug>
#include <QEventLoop>

namespace AQ {

static const QStringList worldMaps = {
    ":/images/world_images/worldmap.png",
    ":/images/world_images/worldmap2.png",
    ":/images/world_images/worldmap3.png",
    ":/images/world_images/worldmap4.png",
    ":/images/world_images/worldmap5.png"
};

GameState::GameState(QObject* parent)
    : QObject(parent)
{
}

GameState::~GameState() = default;

void GameState::startGame(Difficulty difficulty, int playerCount) {
    difficulty_ = difficulty;
    playerCount_ = playerCount;
    running_ = true;
    paused_ = false;
    gameOver_ = false;

    createWorlds(difficulty, playerCount);

    prevEnemyDefeated_ = 0;
    prevPoisonDefeated_ = 0;
    prevThunderDefeated_ = 0;

    emit worldInitialized();
    emit statusChanged(currentWorld()->player().health,
                       currentWorld()->player().energy);
}

void GameState::createWorlds(Difficulty difficulty, int playerCount) {
    worlds_.clear();
    auto params = DifficultyParams::fromLevel(difficulty, playerCount);

    int idCounter = 0;
    for (int i = 0; i < Constants::WorldCount; ++i) {
        bool firstWorld = (i == 0);
        int enemies = (i == 0) ? params.enemyCount : params.enemyCount + 3;
        auto world = std::make_unique<GameWorld>(
            worldMaps[i], enemies, params.healthPackCount,
            params.poisonRatio, firstWorld, idCounter);
        idCounter += static_cast<int>(world->enemies().size()) + 10;
        worlds_.push_back(std::move(world));
    }

    currentWorldIdx_ = 0;

    // Transfer player data to first world
    auto& player = worlds_[0]->player();
    player.health = Constants::MaxHealth;
    player.energy = Constants::MaxEnergy;
}

void GameState::pauseGame() {
    paused_ = true;
}

void GameState::resumeGame() {
    paused_ = false;
}

void GameState::quitGame() {
    running_ = false;
    gameOver_ = true;
}

GameWorld* GameState::currentWorld() {
    if (worlds_.empty() || currentWorldIdx_ >= worlds_.size()) return nullptr;
    return worlds_[currentWorldIdx_].get();
}

const GameWorld* GameState::currentWorld() const {
    if (worlds_.empty() || currentWorldIdx_ >= worlds_.size()) return nullptr;
    return worlds_[currentWorldIdx_].get();
}

void GameState::movePlayer(Direction dir) {
    if (!running_ || paused_ || gameOver_) return;

    auto* world = currentWorld();
    if (!world) return;

    if (MovementSystem::movePlayer(*world, dir)) {
        processMove();
    }
}

void GameState::movePlayerTo(Vec2i target) {
    if (!running_ || paused_ || gameOver_) return;

    auto* world = currentWorld();
    if (!world) return;

    auto path = MovementSystem::findPath(*world, target, heuristicWeight_);
    auto dirs = MovementSystem::pathToDirections(path);

    for (auto d : dirs) {
        if (gameOver_) break;
        MovementSystem::movePlayer(*world, d);
        processMove();

        // Small delay for visual feedback
        QTimer timer;
        timer.setSingleShot(true);
        timer.start(100);
        QEventLoop loop;
        QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
        loop.exec();
    }
}

void GameState::autoPlay() {
    if (!running_ || paused_ || gameOver_) return;

    auto* world = currentWorld();
    if (!world) return;

    auto path = MovementSystem::findPath(*world, world->exitPos(), heuristicWeight_);
    auto dirs = MovementSystem::pathToDirections(path);

    for (auto d : dirs) {
        if (gameOver_ || paused_) break;
        MovementSystem::movePlayer(*world, d);
        processMove();

        // Animated delay
        QTimer timer;
        timer.setSingleShot(true);
        timer.start(100);
        QEventLoop loop;
        QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
        loop.exec();
    }

    emit autoPlayFinished();
}

void GameState::attackNearest() {
    if (!running_ || paused_ || gameOver_) return;

    auto* world = currentWorld();
    if (!world) return;

    auto* nearest = world->nearestEnemyAny(world->player().pos);
    if (nearest) {
        movePlayerTo(nearest->pos);
    }
}

void GameState::takeNearest() {
    if (!running_ || paused_ || gameOver_) return;

    auto* world = currentWorld();
    if (!world) return;

    auto* nearest = world->nearestHealthPack(world->player().pos);
    if (nearest) {
        movePlayerTo(nearest->pos);
    }
}

void GameState::processMove() {
    auto* world = currentWorld();
    if (!world) return;

    // Handle combat/encounters
    CombatSystem::handleEncounters(*world);

    // Track enemy defeats for energy rewards
    int curEnemy = static_cast<int>(world->enemies().size()) -
                   world->aliveCount(EnemyType::Regular);
    int curPoison = static_cast<int>(world->enemies().size()) -
                    world->aliveCount(EnemyType::Poison);
    int curThunder = static_cast<int>(world->enemies().size()) -
                     world->aliveCount(EnemyType::Thunder);

    if (curEnemy != prevEnemyDefeated_) {
        prevEnemyDefeated_ = curEnemy;
    }
    if (curPoison != prevPoisonDefeated_) {
        prevPoisonDefeated_ = curPoison;
    }
    if (curThunder != prevThunderDefeated_) {
        prevThunderDefeated_ = curThunder;
    }

    // Emit status
    emit statusChanged(world->player().health, world->player().energy);

    // Check death
    if (CombatSystem::isPlayerDead(*world)) {
        gameOver_ = true;
        running_ = false;
        emit gameLost();
        return;
    }

    // Check level transition
    checkLevelTransition();

    emit viewNeedsUpdate();
}

void GameState::checkLevelTransition() {
    auto* world = currentWorld();
    if (!world) return;

    Vec2i playerPos = world->player().pos;

    // Reached exit portal -> next level
    if (playerPos == world->exitPos()) {
        if (currentWorldIdx_ == worlds_.size() - 1) {
            gameOver_ = true;
            running_ = false;
            emit gameWon();
            return;
        }

        // Transfer player to next world
        PlayerData playerData = world->player();
        currentWorldIdx_++;
        auto* nextWorld = currentWorld();
        playerData.pos = nextWorld->startPos();
        nextWorld->setPlayer(playerData);

        prevEnemyDefeated_ = 0;
        prevPoisonDefeated_ = 0;
        prevThunderDefeated_ = 0;

        emit levelChanged(static_cast<int>(currentWorldIdx_));
    }
    // Reached start portal -> previous level
    else if (playerPos == world->startPos() && currentWorldIdx_ > 0) {
        PlayerData playerData = world->player();
        currentWorldIdx_--;
        auto* prevWorld = currentWorld();
        playerData.pos = prevWorld->exitPos();
        prevWorld->setPlayer(playerData);

        prevEnemyDefeated_ = 0;
        prevPoisonDefeated_ = 0;
        prevThunderDefeated_ = 0;

        emit levelChanged(static_cast<int>(currentWorldIdx_));
    }
}

} // namespace AQ
