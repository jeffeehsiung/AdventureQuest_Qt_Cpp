cmake_minimum_required(VERSION 3.21)

# ============================================================================
# AdventureQuest - Cross-platform 2D RPG
# ============================================================================
#
# macOS Desktop (Xcode):
#   ./scripts/build-macos.sh
#   -- or manually --
#   cmake -S . -B build-macos -G Xcode
#   open build-macos/AdventureQuest.xcodeproj
#
# macOS Desktop (Makefiles):
#   cmake -S . -B build && cmake --build build
#
# iOS Device:
#   ./scripts/build-ios.sh device
#   open build-ios-device/AdventureQuest.xcodeproj
#
# iOS Simulator:
#   ./scripts/build-ios.sh simulator
#   open build-ios-sim/AdventureQuest.xcodeproj
#
# ============================================================================

project(AdventureQuest VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ---------- Qt6 ----------
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)
message(STATUS "Qt6 found at: ${Qt6_DIR}")

# ---------- Source files ----------

set(WORLD_LIB_SOURCES
    Model/world.cpp
    Model/world.h
    Model/world_global.h
)

set(CORE_SOURCES
    src/Core/Types.h
    src/Core/Event.h
    src/Core/ServiceLocator.h
)

set(GAME_SOURCES
    src/Game/IEntity.h
    src/Game/GameWorld.h
    src/Game/GameWorld.cpp
    src/Game/CombatSystem.h
    src/Game/CombatSystem.cpp
    src/Game/MovementSystem.h
    src/Game/MovementSystem.cpp
    src/Game/GameState.h
    src/Game/GameState.cpp
)

set(PLATFORM_SOURCES
    src/Platform/IRenderer.h
    src/Platform/IInputHandler.h
    src/Platform/PlatformConfig.h
)

set(RENDERER_SOURCES
    src/Renderer/SpriteCache.h
    src/Renderer/SpriteCache.cpp
    src/Renderer/AnimationController.h
    src/Renderer/AnimationController.cpp
    src/Renderer/GameScene.h
    src/Renderer/GameScene.cpp
    src/Renderer/TouchOverlay.h
    src/Renderer/TouchOverlay.cpp
    src/Renderer/HUD.h
    src/Renderer/HUD.cpp
)

set(APP_SOURCES
    src/App/GameController.h
    src/App/GameController.cpp
    src/App/MainWindow.h
    src/App/MainWindow.cpp
    src/App/main.cpp
)

set(RESOURCES images.qrc)

set(ALL_SOURCES
    ${WORLD_LIB_SOURCES}
    ${CORE_SOURCES}
    ${GAME_SOURCES}
    ${PLATFORM_SOURCES}
    ${RENDERER_SOURCES}
    ${APP_SOURCES}
    ${RESOURCES}
)

# ---------- Platform targets ----------
if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
    # ===== iOS APP BUNDLE =====
    set(IOS_RESOURCES
        ios/LaunchScreen.storyboard
    )

    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${ALL_SOURCES} ${IOS_RESOURCES})

    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.adventurequest.game"
        MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/ios/Info.plist"
        XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2"
        XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "15.0"
        XCODE_ATTRIBUTE_ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon"
        XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.adventurequest.game"
        XCODE_ATTRIBUTE_DEVELOPMENT_TEAM ""
        RESOURCE "${IOS_RESOURCES}"
    )

    target_compile_definitions(${PROJECT_NAME} PRIVATE IOS_PLATFORM=1 WORLD_LIBRARY)

elseif(APPLE)
    # ===== macOS APP BUNDLE =====
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${ALL_SOURCES})

    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.adventurequest.game"
        MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
        MACOSX_BUNDLE_BUNDLE_NAME "AdventureQuest"
        XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.adventurequest.game"
        # Ad-hoc code signing for local development (no Apple Developer account needed)
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "-"
        XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED "NO"
        XCODE_ATTRIBUTE_CODE_SIGNING_ALLOWED "NO"
    )

    # Copy images into the app bundle Resources
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/images"
            "$<TARGET_BUNDLE_DIR:${PROJECT_NAME}>/Contents/Resources/images"
        COMMENT "Copying images into macOS app bundle"
    )

    target_compile_definitions(${PROJECT_NAME} PRIVATE WORLD_LIBRARY)

else()
    # ===== Linux / Windows =====
    add_executable(${PROJECT_NAME} ${ALL_SOURCES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE WORLD_LIBRARY)

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/images" "${CMAKE_BINARY_DIR}/images"
        COMMENT "Copying image assets to build directory"
    )
endif()

# ---------- Include directories ----------
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# ---------- Link Qt ----------
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Gui
)

# ---------- Compiler options ----------
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -O2>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -O2>
    $<$<CXX_COMPILER_ID:AppleClang>:-Wall -Wextra -O2>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /O2>
)

# ---------- Organize Xcode source groups ----------
if(CMAKE_GENERATOR MATCHES "Xcode")
    source_group("Core"       FILES ${CORE_SOURCES})
    source_group("Game"       FILES ${GAME_SOURCES})
    source_group("Platform"   FILES ${PLATFORM_SOURCES})
    source_group("Renderer"   FILES ${RENDERER_SOURCES})
    source_group("App"        FILES ${APP_SOURCES})
    source_group("WorldLib"   FILES ${WORLD_LIB_SOURCES})
    source_group("Resources"  FILES ${RESOURCES})
endif()

# ---------- Install ----------
install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
