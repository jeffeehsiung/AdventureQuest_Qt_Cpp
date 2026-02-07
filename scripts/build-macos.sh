#!/bin/bash
set -euo pipefail

# ============================================================================
# build-macos.sh - Generate and open Xcode project for macOS Desktop
# ============================================================================
# Usage:
#   ./scripts/build-macos.sh          # generate + open Xcode
#   ./scripts/build-macos.sh --build  # generate + build (no Xcode GUI)
#   ./scripts/build-macos.sh --clean  # wipe build dir and regenerate
# ============================================================================

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_DIR/build-macos"

echo "=== AdventureQuest - macOS Desktop Build ==="

# --- Handle --clean flag ---
if [ "${1:-}" = "--clean" ]; then
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
    shift
fi

# --- Verify Xcode toolchain ---
echo ""
echo "Checking Xcode toolchain..."

# Make sure xcode-select points to Xcode.app (not just CLT)
XCODE_PATH=$(xcode-select -p 2>/dev/null || true)
if [ "$XCODE_PATH" != "/Applications/Xcode.app/Contents/Developer" ]; then
    if [ -d "/Applications/Xcode.app" ]; then
        echo "[!] xcode-select not pointing to Xcode.app. Fixing..."
        echo "    (may ask for your password)"
        sudo xcode-select -s /Applications/Xcode.app/Contents/Developer
    else
        echo "[!] Xcode.app not found. Using command line tools."
    fi
fi

# Accept Xcode license (silently check, prompt if needed)
if ! xcodebuild -license check &>/dev/null 2>&1; then
    echo "[!] Xcode license not accepted. Accepting..."
    echo "    (may ask for your password)"
    sudo xcodebuild -license accept
fi

echo "[OK] Xcode: $(xcodebuild -version 2>/dev/null | head -1)"

# --- Find Qt6 ---
QT_PREFIX=""

# Try Homebrew (handles both qt@6 and qt formula names)
if command -v brew &>/dev/null; then
    for formula in qt@6 qt; do
        QT_BREW=$(brew --prefix "$formula" 2>/dev/null || true)
        if [ -n "$QT_BREW" ] && [ -d "$QT_BREW/lib/cmake/Qt6" ]; then
            QT_PREFIX="$QT_BREW"
            break
        fi
    done
fi

# Try Qt Online Installer paths
if [ -z "$QT_PREFIX" ]; then
    for qtdir in "$HOME/Qt"/6.*/macos "$HOME/Qt"/6.*/clang_64; do
        if [ -d "$qtdir/lib/cmake/Qt6" ]; then
            QT_PREFIX="$qtdir"
            break
        fi
    done
fi

if [ -n "$QT_PREFIX" ]; then
    echo "[OK] Qt6 at: $QT_PREFIX"
    QT_ARG="-DCMAKE_PREFIX_PATH=$QT_PREFIX"
else
    echo "[!] Qt6 not found. Install with: brew install qt@6"
    exit 1
fi

# --- Clean stale cache if generator changed ---
if [ -f "$BUILD_DIR/CMakeCache.txt" ]; then
    CACHED_GEN=$(grep "CMAKE_GENERATOR:" "$BUILD_DIR/CMakeCache.txt" 2>/dev/null | cut -d= -f2 || true)
    if [ -n "$CACHED_GEN" ] && [ "$CACHED_GEN" != "Xcode" ]; then
        echo "[!] Build dir has a different generator ($CACHED_GEN). Cleaning..."
        rm -rf "$BUILD_DIR"
    fi
fi

# --- Generate Xcode project ---
echo ""
echo "Generating Xcode project..."
cmake -S "$PROJECT_DIR" -B "$BUILD_DIR" \
    -G Xcode \
    $QT_ARG \
    -DCMAKE_OSX_DEPLOYMENT_TARGET=12.0

echo ""
echo "[OK] Xcode project generated at:"
echo "     $BUILD_DIR/AdventureQuest.xcodeproj"

# --- Build or open ---
if [ "${1:-}" = "--build" ]; then
    echo ""
    echo "Building..."
    cmake --build "$BUILD_DIR" --config Debug
    echo ""
    echo "[OK] Build complete!"
    echo "     Run: open $BUILD_DIR/Debug/AdventureQuest.app"
else
    echo ""
    echo "Opening Xcode..."
    open "$BUILD_DIR/AdventureQuest.xcodeproj"
    echo ""
    echo "In Xcode:"
    echo "  1. Select 'AdventureQuest' scheme (top bar)"
    echo "  2. Select 'My Mac' as destination"
    echo "  3. Press Cmd+R to build & run"
fi
