#include "Game/GameWorld.h"
#include "Model/world.h"
#include <random>
#include <algorithm>
#include <cmath>
#include <QDebug>

namespace AQ {

GameWorld::GameWorld(const QString& mapPath, int enemyCount, int healthPackCount,
                     float poisonRatio, bool createProtagonist, int startId)
    : nextId_(startId)
{
    // Use the original World library for map generation
    World worldGen;
    worldGen.createWorld(mapPath, enemyCount, healthPackCount, poisonRatio);

    rows_ = worldGen.getRows();
    cols_ = worldGen.getCols();

    // Convert tiles
    auto rawTiles = worldGen.getTiles();
    tiles_.reserve(rawTiles.size());
    pathNodes_.reserve(rawTiles.size());

    for (auto& t : rawTiles) {
        TileData td;
        td.pos = {t->getXPos(), t->getYPos()};
        td.value = t->getValue();
        tiles_.push_back(td);

        PathNode pn;
        pn.value = t->getValue();
        pn.pos = td.pos;
        pathNodes_.push_back(pn);
    }

    // Track occupied cells
    std::vector<bool> used(rows_ * cols_, false);

    // Convert health packs
    auto rawHP = worldGen.getHealthPacks();
    for (auto& hp : rawHP) {
        used[hp->getYPos() * cols_ + hp->getXPos()] = true;
        HealthPackData hpd;
        hpd.pos = {hp->getXPos(), hp->getYPos()};
        healthPacks_.push_back(hpd);
    }

    // Convert enemies
    auto rawEnemies = worldGen.getEnemies();
    for (auto& e : rawEnemies) {
        used[e->getYPos() * cols_ + e->getXPos()] = true;

        EnemyData ed;
        ed.id = nextId_++;
        ed.pos = {e->getXPos(), e->getYPos()};
        ed.strength = e->getValue();

        if (dynamic_cast<PEnemy*>(e.get())) {
            ed.type = EnemyType::Poison;
            ed.specialLevel = static_cast<PEnemy*>(e.get())->getPoisonLevel();
        } else {
            ed.type = EnemyType::Regular;
        }
        enemies_.push_back(ed);
    }

    // Generate XEnemies (thunder)
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<int> distX(8, cols_ - 8);
    std::uniform_int_distribution<int> distY(8, rows_ - 8);
    std::uniform_int_distribution<int> distStr(0, 100);

    float xRatio = poisonRatio * 0.8f;
    int targetXCount = std::max(1, static_cast<int>(enemyCount * xRatio));
    int xCount = 0;

    while (xCount < targetXCount) {
        int xp = distX(rng);
        int yp = distY(rng);
        if (xp == 0 && yp == 0) continue;
        int idx = yp * cols_ + xp;
        if (idx < static_cast<int>(used.size()) && !used[idx]) {
            EnemyData ed;
            ed.id = nextId_++;
            ed.type = EnemyType::Thunder;
            ed.pos = {xp, yp};
            ed.strength = static_cast<float>(distStr(rng));
            ed.specialLevel = ed.strength;
            enemies_.push_back(ed);
            used[idx] = true;
            xCount++;
        }
    }

    // Create protagonist
    if (createProtagonist) {
        player_.id = nextId_++;
        player_.pos = start_;
        player_.health = Constants::MaxHealth;
        player_.energy = Constants::MaxEnergy;
    }
}

GameWorld::~GameWorld() = default;

bool GameWorld::inBounds(Vec2i pos) const {
    return pos.x >= 0 && pos.x < cols_ && pos.y >= 0 && pos.y < rows_;
}

float GameWorld::tileValue(Vec2i pos) const {
    if (!inBounds(pos)) return 0.0f;
    return tiles_[pos.toIndex(cols_)].value;
}

void GameWorld::setTileAffected(Vec2i pos, bool isThunder, float /*level*/) {
    if (!inBounds(pos)) return;
    auto& tile = tiles_[pos.toIndex(cols_)];
    if (isThunder) {
        tile.thundered = true;
    } else {
        tile.poisoned = true;
    }
}

void GameWorld::applyAffectedArea(Vec2i center, bool isThunder, float level) {
    int maxVal = 32;
    int minRadius = 1;
    int maxRadius = 8;
    int radius = minRadius + static_cast<int>((maxRadius - minRadius) * (1.0f - level / maxVal));
    int rSq = radius * radius;

    int startX = std::max(0, center.x - radius);
    int endX = std::min(cols_ - 1, center.x + radius);
    int startY = std::max(0, center.y - radius);
    int endY = std::min(rows_ - 1, center.y + radius);

    for (int x = startX; x <= endX; ++x) {
        for (int y = startY; y <= endY; ++y) {
            int dx = x - center.x;
            int dy = y - center.y;
            if (dx * dx + dy * dy <= rSq) {
                auto& tile = tiles_[y * cols_ + x];
                if (isThunder) tile.thundered = true;
                else tile.poisoned = true;
                tile.animState = EntityState::Hurt;
            }
        }
    }
}

EnemyData* GameWorld::enemyAt(Vec2i pos) {
    for (auto& e : enemies_) {
        if (!e.defeated && e.pos == pos) return &e;
    }
    return nullptr;
}

EnemyData* GameWorld::nearestEnemy(Vec2i from, EnemyType type) {
    EnemyData* nearest = nullptr;
    float minDist = 99999.0f;
    for (auto& e : enemies_) {
        if (e.defeated || e.type != type) continue;
        float d = from.distanceTo(e.pos);
        if (d < minDist) {
            minDist = d;
            nearest = &e;
        }
    }
    return nearest;
}

EnemyData* GameWorld::nearestEnemyAny(Vec2i from) {
    EnemyData* nearest = nullptr;
    float minDist = 99999.0f;
    for (auto& e : enemies_) {
        if (e.defeated) continue;
        float d = from.distanceTo(e.pos);
        if (d < minDist) {
            minDist = d;
            nearest = &e;
        }
    }
    return nearest;
}

int GameWorld::aliveCount(EnemyType type) const {
    int count = 0;
    for (auto& e : enemies_) {
        if (!e.defeated && e.type == type) count++;
    }
    return count;
}

HealthPackData* GameWorld::healthPackAt(Vec2i pos) {
    for (auto& hp : healthPacks_) {
        if (hp.pos == pos) return &hp;
    }
    return nullptr;
}

HealthPackData* GameWorld::nearestHealthPack(Vec2i from) {
    HealthPackData* nearest = nullptr;
    float minDist = 99999.0f;
    for (auto& hp : healthPacks_) {
        float d = from.distanceTo(hp.pos);
        if (d < minDist) {
            minDist = d;
            nearest = &hp;
        }
    }
    return nearest;
}

void GameWorld::relocateHealthPack(Vec2i oldPos) {
    for (auto& hp : healthPacks_) {
        if (hp.pos == oldPos) {
            std::random_device rd;
            std::mt19937 rng(rd());
            std::uniform_int_distribution<int> dist(-3, 3);

            int nx = std::clamp(hp.pos.x + dist(rng), 0, cols_ - 1);
            int ny = std::clamp(hp.pos.y + dist(rng), 0, rows_ - 1);
            hp.pos = {nx, ny};
            return;
        }
    }
}

} // namespace AQ
