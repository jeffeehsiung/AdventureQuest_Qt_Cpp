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

# --- Generate ---
echo ""
echo "Generating Xcode project for $TARGET_LABEL..."
cmake -S "$PROJECT_DIR" -B "$BUILD_DIR" \
    -G Xcode \
    -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN" \
    -DCMAKE_PREFIX_PATH="$QT_IOS_PREFIX" \
    -DQT_HOST_PATH="$(brew --prefix qt@6 2>/dev/null || echo "$HOME/Qt/$(ls "$HOME/Qt" 2>/dev/null | grep '^6\.' | sort -V | tail -1)/macos")"

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
