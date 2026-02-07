#ifndef AQ_PLATFORM_CONFIG_H
#define AQ_PLATFORM_CONFIG_H

namespace AQ {

struct PlatformConfig {
#if defined(Q_OS_IOS) || defined(IOS_PLATFORM)
    static constexpr bool isMobile = true;
    static constexpr bool hasTouch = true;
    static constexpr bool hasKeyboard = false;
    static constexpr int  defaultTileSize = 20;  // smaller for mobile screens
    static constexpr float defaultZoomLevel = 1.5f;
#elif defined(Q_OS_ANDROID)
    static constexpr bool isMobile = true;
    static constexpr bool hasTouch = true;
    static constexpr bool hasKeyboard = false;
    static constexpr int  defaultTileSize = 20;
    static constexpr float defaultZoomLevel = 1.5f;
#else
    static constexpr bool isMobile = false;
    static constexpr bool hasTouch = false;
    static constexpr bool hasKeyboard = true;
    static constexpr int  defaultTileSize = 30;
    static constexpr float defaultZoomLevel = 1.0f;
#endif
};

} // namespace AQ

#endif // AQ_PLATFORM_CONFIG_H
