#ifndef AQ_GAME_GAMEWORLD_H
#define AQ_GAME_GAMEWORLD_H

#include "Core/Types.h"
#include "Core/Event.h"
#include <QObject>
#include <QString>
#include <vector>
#include <memory>
#include <optional>

// Forward declarations from the original world library
class World;
class Tile;
class Enemy;
class PEnemy;
class Protagonist;

namespace AQ {

// ---------- Tile Data ----------

struct TileData {
    Vec2i pos;
    float value = 0.0f;  // terrain weight (0=impassable, 1=easy)
    bool poisoned = false;
    bool thundered = false;
    EntityState animState = EntityState::Idle;
};

// ---------- Enemy Data ----------

struct EnemyData {
    int id = 0;
    EnemyType type = EnemyType::Regular;
    Vec2i pos;
    float strength = 0.0f;
    float specialLevel = 0.0f;  // poison or thunder level
    bool defeated = false;
    EntityState animState = EntityState::Idle;
};

// ---------- Player Data ----------

struct PlayerData {
    int id = 0;
    Vec2i pos;
    int health = Constants::MaxHealth;
    float energy = Constants::MaxEnergy;
    EntityState animState = EntityState::Idle;
};

// ---------- Health Pack Data ----------

struct HealthPackData {
    Vec2i pos;
    EntityState animState = EntityState::Idle;
};

// ---------- A* Node ----------

struct PathNode {
    float f = 0, g = 0, h = 0;
    bool visited = false;
    float value = 0;
    Vec2i pos;
    PathNode* prev = nullptr;

    float getValue() const { return value; }
    int getXPos() const { return pos.x; }
    int getYPos() const { return pos.y; }
};

// ---------- Game World ----------
// Owns all entity data for a single level.
// Wraps the original World library for world generation
// while exposing a clean data-oriented interface.

class GameWorld : public QObject {
    Q_OBJECT

public:
    GameWorld(const QString& mapPath, int enemyCount, int healthPackCount,
              float poisonRatio, bool createProtagonist, int startId = 0);
    ~GameWorld();

    // Grid
    int rows() const { return rows_; }
    int cols() const { return cols_; }
    bool inBounds(Vec2i pos) const;
    float tileValue(Vec2i pos) const;

    // Tiles
    const std::vector<TileData>& tiles() const { return tiles_; }
    std::vector<TileData>& tilesRef() { return tiles_; }
    void setTileAffected(Vec2i pos, bool isThunder, float level);
    void applyAffectedArea(Vec2i center, bool isThunder, float level);

    // Enemies
    const std::vector<EnemyData>& enemies() const { return enemies_; }
    std::vector<EnemyData>& enemiesRef() { return enemies_; }
    EnemyData* enemyAt(Vec2i pos);
    EnemyData* nearestEnemy(Vec2i from, EnemyType type);
    EnemyData* nearestEnemyAny(Vec2i from);
    int aliveCount(EnemyType type) const;

    // Health packs
    const std::vector<HealthPackData>& healthPacks() const { return healthPacks_; }
    std::vector<HealthPackData>& healthPacksRef() { return healthPacks_; }
    HealthPackData* healthPackAt(Vec2i pos);
    HealthPackData* nearestHealthPack(Vec2i from);
    void relocateHealthPack(Vec2i oldPos);

    // Player
    PlayerData& player() { return player_; }
    const PlayerData& player() const { return player_; }
    void setPlayer(PlayerData p) { player_ = std::move(p); }

    // Portals
    Vec2i startPos() const { return start_; }
    Vec2i exitPos() const { return exit_; }

    // Pathfinding
    std::vector<PathNode>& pathNodes() { return pathNodes_; }

signals:
    void playerDied();
    void healthChanged();
    void energyChanged();

private:
    int rows_ = 0;
    int cols_ = 0;
    Vec2i start_{0, 0};
    Vec2i exit_{29, 29};

    std::vector<TileData> tiles_;
    std::vector<EnemyData> enemies_;
    std::vector<HealthPackData> healthPacks_;
    PlayerData player_;
    std::vector<PathNode> pathNodes_;

    int nextId_ = 0;
};

} // namespace AQ

#endif // AQ_GAME_GAMEWORLD_H
