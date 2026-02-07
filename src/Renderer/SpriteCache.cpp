#include "Renderer/SpriteCache.h"
#include <QDir>
#include <QDebug>
#include <algorithm>

namespace AQ {

SpriteCache& SpriteCache::instance() {
    static SpriteCache cache;
    return cache;
}

const std::vector<QPixmap>& SpriteCache::getFrames(const QString& dirPath) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = frameCache_.find(dirPath);
    if (it != frameCache_.end()) {
        return it.value();
    }

    auto frames = loadFramesFromDir(dirPath);
    auto [inserted, _] = frameCache_.insert(dirPath, std::move(frames));
    Q_UNUSED(_);
    return inserted.value();
}

const QPixmap& SpriteCache::getPixmap(const QString& path) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = pixmapCache_.find(path);
    if (it != pixmapCache_.end()) {
        return it.value();
    }

    QPixmap pm(path);
    auto inserted = pixmapCache_.insert(path, std::move(pm));
    return inserted.value();
}

std::vector<QPixmap> SpriteCache::loadFramesFromDir(const QString& dirPath) {
    std::vector<QPixmap> frames;
    QDir dir(dirPath);

    if (!dir.exists()) {
        qWarning() << "Sprite directory not found:" << dirPath;
        return frames;
    }

    QStringList filters = {"*.png", "*.jpg"};
    QStringList files = dir.entryList(filters, QDir::Files, QDir::Name);

    frames.reserve(files.size());
    for (const auto& file : files) {
        QPixmap pm(dir.filePath(file));
        if (!pm.isNull()) {
            frames.push_back(std::move(pm));
        }
    }
    return frames;
}

void SpriteCache::preloadAll() {
    // Preload all sprite directories for fast switching
    static const QStringList dirs = {
        // Protagonist
        ":/images/protagonist_fighter/Idle",
        ":/images/protagonist_fighter/Moving",
        ":/images/protagonist_fighter/Attack",
        ":/images/protagonist_fighter/Hurt",
        ":/images/protagonist_fighter/Dying",
        ":/images/protagonist_fighter/Heal",
        // Golem enemy
        ":/images/enemy_golem/PNG Sequences/Idle",
        ":/images/enemy_golem/PNG Sequences/Walking",
        ":/images/enemy_golem/PNG Sequences/Attacking",
        ":/images/enemy_golem/PNG Sequences/Hurt",
        ":/images/enemy_golem/PNG Sequences/Dying",
        ":/images/enemy_golem/PNG Sequences/Heal",
        // Poison wraith
        ":/images/penemy_wraith/PNG Sequences/Idle",
        ":/images/penemy_wraith/PNG Sequences/Walking",
        ":/images/penemy_wraith/PNG Sequences/Attacking",
        ":/images/penemy_wraith/PNG Sequences/Hurt",
        ":/images/penemy_wraith/PNG Sequences/Dying",
        ":/images/penemy_wraith/PNG Sequences/Casting Spells",
        // Thunder wraith
        ":/images/xenemy_wraith/PNG Sequences/Idle",
        ":/images/xenemy_wraith/PNG Sequences/Walking",
        ":/images/xenemy_wraith/PNG Sequences/Attacking",
        ":/images/xenemy_wraith/PNG Sequences/Hurt",
        ":/images/xenemy_wraith/PNG Sequences/Dying",
        ":/images/xenemy_wraith/PNG Sequences/Casting Spells",
        // Tiles
        ":/images/tiles/Idle",
        ":/images/tiles/Attack",
        ":/images/tiles/Moving",
        // Health pack
        ":/images/healthpack/Idle",
        // Portal
        ":/images/portal/Idle",
    };

    for (const auto& dir : dirs) {
        getFrames(dir);
    }
}

void SpriteCache::clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    frameCache_.clear();
    pixmapCache_.clear();
}

size_t SpriteCache::cacheSize() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return frameCache_.size() + pixmapCache_.size();
}

} // namespace AQ
