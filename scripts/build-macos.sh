#!/bin/bash
set -euo pipefail

# ============================================================================
# build-macos.sh - Generate and open Xcode project for macOS Desktop
# ============================================================================
# Usage:
#   ./scripts/build-macos.sh          # generate + open Xcode
#   ./scripts/build-macos.sh --build  # generate + build (no Xcode GUI)
# ============================================================================

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$PROJECT_DIR/build-macos"

echo "=== AdventureQuest - macOS Desktop Build ==="

# --- Find Qt6 ---
QT_PREFIX=""

# Try Homebrew first
if command -v brew &>/dev/null; then
    QT_BREW=$(brew --prefix qt@6 2>/dev/null || true)
    if [ -d "$QT_BREW/lib/cmake/Qt6" ]; then
        QT_PREFIX="$QT_BREW"
    fi
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

# Try system
if [ -z "$QT_PREFIX" ]; then
    if cmake --find-package -DNAME=Qt6 -DCOMPILER_ID=AppleClang -DLANGUAGE=CXX -DMODE=EXIST &>/dev/null 2>&1; then
        QT_PREFIX=""  # system default will work
    fi
fi

if [ -n "$QT_PREFIX" ]; then
    echo "Qt6 found at: $QT_PREFIX"
    QT_ARG="-DCMAKE_PREFIX_PATH=$QT_PREFIX"
else
    echo "Qt6 path: using system default"
    QT_ARG=""
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
