#!/bin/bash
set -euo pipefail

# ============================================================================
# build-ios.sh - Generate Xcode project for iOS Device or Simulator
# ============================================================================
# Usage:
#   ./scripts/build-ios.sh sim          # iOS Simulator
#   ./scripts/build-ios.sh simulator    # iOS Simulator (alias)
#   ./scripts/build-ios.sh device       # Real iPhone/iPad
#   ./scripts/build-ios.sh              # defaults to simulator
# ============================================================================

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

TARGET="${1:-sim}"

echo "=== AdventureQuest - iOS Build ==="

# --- Determine target ---
case "$TARGET" in
    sim|simulator)
        BUILD_DIR="$PROJECT_DIR/build-ios-sim"
        TOOLCHAIN="$PROJECT_DIR/cmake/ios-simulator.toolchain.cmake"
        TARGET_LABEL="iOS Simulator"
        ;;
    device|iphone|ipad)
        BUILD_DIR="$PROJECT_DIR/build-ios-device"
        TOOLCHAIN="$PROJECT_DIR/cmake/ios.toolchain.cmake"
        TARGET_LABEL="iOS Device"
        ;;
    *)
        echo "Usage: $0 [sim|device]"
        exit 1
        ;;
esac

echo "Target: $TARGET_LABEL"

# --- Find Qt6 for iOS ---
QT_IOS_PREFIX=""

# Qt Online Installer (most common for iOS)
for qtdir in "$HOME/Qt"/6.*/ios; do
    if [ -d "$qtdir/lib/cmake/Qt6" ]; then
        QT_IOS_PREFIX="$qtdir"
        break
    fi
done

# Try QT_IOS_DIR env var
if [ -z "$QT_IOS_PREFIX" ] && [ -n "${QT_IOS_DIR:-}" ]; then
    if [ -d "$QT_IOS_DIR/lib/cmake/Qt6" ]; then
        QT_IOS_PREFIX="$QT_IOS_DIR"
    fi
fi

if [ -z "$QT_IOS_PREFIX" ]; then
    echo ""
    echo "[ERROR] Qt6 for iOS not found!"
    echo ""
    echo "Qt6 for iOS is NOT available via Homebrew."
    echo "You need to install it via the Qt Online Installer:"
    echo ""
    echo "  1. Download: https://www.qt.io/download-qt-installer"
    echo "  2. Run the installer"
    echo "  3. Select: Qt > Qt 6.x > iOS"
    echo "  4. After install, re-run this script"
    echo ""
    echo "Or set QT_IOS_DIR manually:"
    echo "  export QT_IOS_DIR=~/Qt/6.7.0/ios"
    echo "  $0 $TARGET"
    exit 1
fi

echo "Qt6 iOS at: $QT_IOS_PREFIX"

# --- Verify Xcode ---
if ! xcodebuild -version &>/dev/null; then
    echo "[ERROR] Xcode not found. Install Xcode from the App Store."
    exit 1
fi
echo "Xcode: $(xcodebuild -version | head -1)"

# --- Find QT_HOST_PATH (macOS Qt needed for cross-compilation tools) ---
QT_HOST=""
# Try Homebrew first
if command -v brew &>/dev/null; then
    for formula in qt@6 qt; do
        QT_HOST_TRY=$(brew --prefix "$formula" 2>/dev/null || true)
        if [ -n "$QT_HOST_TRY" ] && [ -d "$QT_HOST_TRY/lib/cmake/Qt6" ]; then
            QT_HOST="$QT_HOST_TRY"
            break
        fi
    done
fi
# Try Qt Online Installer macOS path
if [ -z "$QT_HOST" ]; then
    for qtdir in "$HOME/Qt"/6.*/macos "$HOME/Qt"/6.*/clang_64; do
        if [ -d "$qtdir/lib/cmake/Qt6" ]; then
            QT_HOST="$qtdir"
            break
        fi
    done
fi
if [ -z "$QT_HOST" ]; then
    echo "[ERROR] Cannot find Qt6 for macOS (needed as host tools for cross-compilation)."
    echo "        Install with: brew install qt@6"
    exit 1
fi
echo "Qt6 host (macOS): $QT_HOST"

# --- Generate ---
echo ""
echo "Generating Xcode project for $TARGET_LABEL..."
cmake -S "$PROJECT_DIR" -B "$BUILD_DIR" \
    -G Xcode \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" \
    -DCMAKE_PREFIX_PATH="$QT_IOS_PREFIX" \
    -DQT_HOST_PATH="$QT_HOST"

echo ""
echo "[OK] Xcode project generated at:"
echo "     $BUILD_DIR/AdventureQuest.xcodeproj"
echo ""
echo "Opening Xcode..."
open "$BUILD_DIR/AdventureQuest.xcodeproj"
echo ""

case "$TARGET" in
    sim|simulator)
        echo "In Xcode:"
        echo "  1. Select 'AdventureQuest' scheme"
        echo "  2. Select an iPhone simulator (e.g. 'iPhone 15 Pro')"
        echo "  3. Press Cmd+R to build & run"
        ;;
    device|iphone|ipad)
        echo "In Xcode:"
        echo "  1. Select 'AdventureQuest' scheme"
        echo "  2. Connect your iPhone/iPad via USB"
        echo "  3. Select your device in the destination picker"
        echo "  4. Set your Development Team:"
        echo "     - Click the AdventureQuest target"
        echo "     - Signing & Capabilities tab"
        echo "     - Select your Apple ID / Team"
        echo "  5. Press Cmd+R to build & deploy"
        echo ""
        echo "  Note: First time deploying to a device requires:"
        echo "  - An Apple Developer account (free works for personal testing)"
        echo "  - Trust the developer cert on the iPhone:"
        echo "    Settings > General > VPN & Device Management"
        ;;
esac
