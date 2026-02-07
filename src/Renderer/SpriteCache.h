#ifndef AQ_RENDERER_SPRITE_CACHE_H
#define AQ_RENDERER_SPRITE_CACHE_H

#include <QPixmap>
#include <QString>
#include <QHash>
#include <vector>
#include <mutex>

namespace AQ {

// SpriteCache provides centralized, thread-safe sprite loading with deduplication.
// Sprites are loaded once and shared across all entity renderers.
// This replaces the per-class static shared frame vectors in the original code.

class SpriteCache {
public:
    static SpriteCache& instance();

    // Load animation frames from a directory. Returns cached frames if already loaded.
    const std::vector<QPixmap>& getFrames(const QString& dirPath);

    // Load a single pixmap
    const QPixmap& getPixmap(const QString& path);

    // Preload commonly used sprite sets
    void preloadAll();

    // Clear all cached sprites
    void clear();

    // Memory stats
    size_t cacheSize() const;

private:
    SpriteCache() = default;

    std::vector<QPixmap> loadFramesFromDir(const QString& dirPath);

    QHash<QString, std::vector<QPixmap>> frameCache_;
    QHash<QString, QPixmap> pixmapCache_;
    mutable std::mutex mutex_;
};

} // namespace AQ

#endif // AQ_RENDERER_SPRITE_CACHE_H
