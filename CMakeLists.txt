cmake_minimum_required(VERSION 3.21)

# ============================================================================
# AdventureQuest - Cross-platform 2D RPG (Desktop + iOS)
# ============================================================================
# Desktop build:
#   mkdir build && cd build && cmake .. && cmake --build .
#
# iOS build (requires macOS + Xcode + Qt6 for iOS):
#   mkdir build-ios && cd build-ios
#   cmake .. -G Xcode -DCMAKE_TOOLCHAIN_FILE=../cmake/ios.toolchain.cmake \
#     -DCMAKE_PREFIX_PATH=<path-to-qt6-ios>
#   cmake --build . --config Release
# ============================================================================

project(AdventureQuest VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ---------- Qt6 ----------
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

# ---------- Source files ----------

# Original world library (kept as-is for backward compatibility)
set(WORLD_LIB_SOURCES
    Model/world.cpp
    Model/world.h
    Model/world_global.h
)

# New architecture sources
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

# Legacy sources (kept for reference and fallback builds)
set(LEGACY_SOURCES
    Model/structs.h
    Model/Entity.h
    Model/TileModel.h
    Model/TileModel.cpp
    Model/EnemyModel.h
    Model/EnemyModel.cpp
    Model/ProtagonistModel.h
    Model/ProtagonistModel.cpp
    Model/WorldModel.h
    Model/WorldModel.cpp
    Model/TileObserver.h
    Controller/GameController.h
    Controller/GameController.cpp
    Controller/WorldController.h
    Controller/WorldController.cpp
    Controller/ViewController.h
    Controller/ViewController.cpp
    Controller/InputType.h
    Controller/ViewType.h
    View/GameView.h
    View/Game2DView.h
    View/Game2DView.cpp
    View/GameTextView.h
    View/GameTextView.cpp
    View/EntityGraphicsItem.h
    View/EntityGraphicsItem.cpp
    View/ProtagonistGraphicsItem.h
    View/ProtagonistGraphicsItem.cpp
    View/EnemyGraphicsItem.h
    View/EnemyGraphicsItem.cpp
    View/TileGraphicsItem.h
    View/TileGraphicsItem.cpp
    View/EntityTextItem.h
    pathfinder.h
)

# ---------- Resources ----------
set(RESOURCES images.qrc)

# ---------- All sources ----------
set(ALL_SOURCES
    ${WORLD_LIB_SOURCES}
    ${CORE_SOURCES}
    ${GAME_SOURCES}
    ${PLATFORM_SOURCES}
    ${RENDERER_SOURCES}
    ${APP_SOURCES}
    ${RESOURCES}
)

# ---------- Platform-specific configuration ----------
if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
    # iOS app bundle
    set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.adventurequest.game")
    set(MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION})
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION})

    set(IOS_RESOURCES
        ios/LaunchScreen.storyboard
    )

    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${ALL_SOURCES} ${IOS_RESOURCES})

    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/ios/Info.plist"
        XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2"  # iPhone + iPad
        XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "15.0"
        XCODE_ATTRIBUTE_ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon"
        XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.adventurequest.game"
        RESOURCE "${IOS_RESOURCES}"
    )

    # Define iOS platform macro
    target_compile_definitions(${PROJECT_NAME} PRIVATE IOS_PLATFORM=1 WORLD_LIBRARY)

else()
    # Desktop executable
    add_executable(${PROJECT_NAME} ${ALL_SOURCES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE WORLD_LIBRARY)
endif()

# ---------- Include directories ----------
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}           # For Model/, Controller/, View/ legacy paths
    ${CMAKE_SOURCE_DIR}/src       # For new src/Core/, src/Game/, etc.
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

# ---------- Post-build (desktop) ----------
if(NOT CMAKE_SYSTEM_NAME STREQUAL "iOS")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/images" "${CMAKE_BINARY_DIR}/images"
        COMMENT "Copying image assets to build directory"
    )
endif()

# ---------- Install ----------
install(TARGETS ${PROJECT_NAME}
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
