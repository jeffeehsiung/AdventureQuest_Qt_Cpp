#!/bin/bash
set -euo pipefail

# ============================================================================
# build-macos.sh - Build AdventureQuest for macOS Desktop
# ============================================================================
# Usage:
#   ./scripts/build-macos.sh                # Xcode project + open
#   ./scripts/build-macos.sh --build        # Xcode project + command-line build
#   ./scripts/build-macos.sh --ninja        # Ninja build (no Xcode needed)
#   ./scripts/build-macos.sh --clean        # wipe build dir first
#   ./scripts/build-macos.sh --clean --ninja
# ============================================================================

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

# --- Parse flags ---
CLEAN=false
USE_NINJA=false
DO_BUILD=false

for arg in "$@"; do
    case "$arg" in
        --clean) CLEAN=true ;;
        --ninja) USE_NINJA=true ;;
        --build) DO_BUILD=true ;;
    esac
done

if $USE_NINJA; then
    BUILD_DIR="$PROJECT_DIR/build-macos-ninja"
    GENERATOR="Ninja"
else
    BUILD_DIR="$PROJECT_DIR/build-macos"
    GENERATOR="Xcode"
fi

echo "=== AdventureQuest - macOS Desktop Build ==="
echo "    Generator: $GENERATOR"

# --- Handle --clean flag ---
if $CLEAN; then
    echo "Cleaning build directory..."
    rm -rf "$BUILD_DIR"
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

# Run first-launch setup (installs required system packages/plugins)
echo "    Running first-launch setup (may take a moment)..."
xcodebuild -runFirstLaunch 2>/dev/null || sudo xcodebuild -runFirstLaunch 2>/dev/null || true

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
    if [ -n "$CACHED_GEN" ] && [ "$CACHED_GEN" != "$GENERATOR" ]; then
        echo "[!] Build dir has a different generator ($CACHED_GEN). Cleaning..."
        rm -rf "$BUILD_DIR"
    fi
fi

# --- Locate compilers explicitly ---
CC=$(xcrun --find clang 2>/dev/null || echo "")
CXX=$(xcrun --find clang++ 2>/dev/null || echo "")
if [ -z "$CC" ] || [ -z "$CXX" ]; then
    echo "[ERROR] Cannot find clang/clang++ via xcrun."
    echo "        Run: sudo xcode-select -s /Applications/Xcode.app/Contents/Developer"
    exit 1
fi
echo "[OK] CC:  $CC"
echo "[OK] CXX: $CXX"

# --- Check Ninja availability (for --ninja mode) ---
if $USE_NINJA; then
    if ! command -v ninja &>/dev/null; then
        echo "[ ] Ninja not found. Installing via Homebrew..."
        brew install ninja
    fi
    echo "[OK] Ninja: $(ninja --version)"
fi

# --- Generate ---
echo ""
echo "Generating with $GENERATOR..."
cmake -S "$PROJECT_DIR" -B "$BUILD_DIR" \
    -G "$GENERATOR" \
    $QT_ARG \
    -DCMAKE_C_COMPILER="$CC" \
    -DCMAKE_CXX_COMPILER="$CXX" \
    -DCMAKE_OSX_DEPLOYMENT_TARGET=14.0

echo ""
echo "[OK] Build system generated at: $BUILD_DIR"

# --- Build or open ---
if $USE_NINJA; then
    echo ""
    echo "Building with Ninja..."
    cmake --build "$BUILD_DIR" --config Debug -j "$(sysctl -n hw.logicalcpu 2>/dev/null || echo 4)"
    echo ""
    echo "[OK] Build complete!"
    # Find the .app bundle or binary
    if [ -d "$BUILD_DIR/AdventureQuest.app" ]; then
        echo "     Run: open $BUILD_DIR/AdventureQuest.app"
    else
        echo "     Run: $BUILD_DIR/AdventureQuest"
    fi
elif $DO_BUILD; then
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
