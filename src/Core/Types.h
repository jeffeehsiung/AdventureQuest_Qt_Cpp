#ifndef AQ_CORE_TYPES_H
#define AQ_CORE_TYPES_H

#include <cmath>
#include <cstdint>
#include <compare>
#include <string>
#include <functional>

namespace AQ {

// ---------- Geometry ----------

struct Vec2i {
    int x = 0;
    int y = 0;

    constexpr Vec2i() = default;
    constexpr Vec2i(int x, int y) : x(x), y(y) {}

    auto operator<=>(const Vec2i&) const = default;

    constexpr Vec2i operator+(const Vec2i& o) const { return {x + o.x, y + o.y}; }
    constexpr Vec2i operator-(const Vec2i& o) const { return {x - o.x, y - o.y}; }

    int manhattanTo(const Vec2i& o) const {
        return std::abs(x - o.x) + std::abs(y - o.y);
    }

    float distanceTo(const Vec2i& o) const {
        float dx = static_cast<float>(x - o.x);
        float dy = static_cast<float>(y - o.y);
        return std::sqrt(dx * dx + dy * dy);
    }

    int toIndex(int cols) const { return y * cols + x; }
    static Vec2i fromIndex(int index, int cols) { return {index % cols, index / cols}; }
};

// ---------- Enumerations ----------

enum class EntityState : uint8_t {
    Idle,
    Moving,
    Attacking,
    Hurt,
    Dying,
    Healing
};

enum class Direction : uint8_t {
    Up,
    Down,
    Left,
    Right
};

enum class EnemyType : uint8_t {
    Regular,
    Poison,
    Thunder
};

enum class Difficulty : uint8_t {
    Easy,
    Medium,
    Hard
};

enum class InputAction : uint8_t {
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight,
    Attack,
    TakeItem,
    AutoPlay,
    Pause,
    Quit
};

// ---------- Direction helpers ----------

inline Vec2i directionDelta(Direction d) {
    switch (d) {
        case Direction::Up:    return { 0, -1};
        case Direction::Down:  return { 0,  1};
        case Direction::Left:  return {-1,  0};
        case Direction::Right: return { 1,  0};
    }
    return {0, 0};
}

// ---------- Game parameters ----------

struct DifficultyParams {
    int enemyCount     = 8;
    int healthPackCount = 5;
    float poisonRatio  = 0.1f;

    static DifficultyParams fromLevel(Difficulty d, int playerCount) {
        DifficultyParams p;
        switch (d) {
            case Difficulty::Easy:
                p.enemyCount = 8;
                p.healthPackCount = 5;
                p.poisonRatio = (playerCount == 1) ? 0.1f : 0.2f;
                break;
            case Difficulty::Medium:
                p.enemyCount = 15;
                p.healthPackCount = 3;
                p.poisonRatio = (playerCount == 1) ? 0.2f : 0.4f;
                break;
            case Difficulty::Hard:
                p.enemyCount = 30;
                p.healthPackCount = 1;
                p.poisonRatio = (playerCount == 1) ? 0.3f : 0.6f;
                break;
        }
        return p;
    }
};

// ---------- Constants ----------

namespace Constants {
    constexpr int   MaxHealth       = 5;
    constexpr float MaxEnergy       = 100.0f;
    constexpr int   TileSize        = 30;
    constexpr int   GridSize        = 30;  // 30x30 grid per world
    constexpr int   WorldCount      = 5;
    constexpr float EnemyDamage     = 50.0f;
    constexpr float PlayerAttack    = 1.0f;
    constexpr float PoisonDamage    = 0.2f;
    constexpr float ThunderDamage   = 10.0f;
    constexpr int   EnergyRewardEnemy  = 10;
    constexpr int   EnergyRewardPoison = 30;
    constexpr int   EnergyRewardThunder = 50;
    constexpr int   AnimFrameMs     = 100;
}

} // namespace AQ

#endif // AQ_CORE_TYPES_H
