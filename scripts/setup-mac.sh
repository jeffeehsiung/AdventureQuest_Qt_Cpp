#!/bin/bash
set -euo pipefail

# ============================================================================
# setup-mac.sh - Install all dependencies on macOS for AdventureQuest
# ============================================================================
# Usage:  ./scripts/setup-mac.sh
# ============================================================================

echo "=== AdventureQuest macOS Setup ==="
echo ""

# 1. Check Xcode
if ! xcode-select -p &>/dev/null; then
    echo "[!] Xcode Command Line Tools not found. Installing..."
    xcode-select --install
    echo "    Please complete the Xcode install dialog, then re-run this script."
    exit 1
fi
echo "[OK] Xcode CLT: $(xcode-select -p)"

# 2. Check Xcode.app (needed for iOS builds)
if [ -d "/Applications/Xcode.app" ]; then
    echo "[OK] Xcode.app found"
    XCODE_VER=$(xcodebuild -version | head -1)
    echo "     $XCODE_VER"
else
    echo "[!] Xcode.app not found in /Applications"
    echo "    Download from the App Store for iOS builds."
    echo "    Desktop-only builds will still work."
fi

# 3. Install Homebrew if missing
if ! command -v brew &>/dev/null; then
    echo "[!] Homebrew not found. Installing..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi
echo "[OK] Homebrew: $(brew --version | head -1)"

# 4. Install CMake
if ! command -v cmake &>/dev/null; then
    echo "[ ] Installing CMake..."
    brew install cmake
fi
echo "[OK] CMake: $(cmake --version | head -1)"

# 5. Install Qt6
if brew list qt@6 &>/dev/null; then
    echo "[OK] Qt6 already installed via Homebrew"
else
    echo "[ ] Installing Qt6 (this may take a few minutes)..."
    brew install qt@6
fi

QT_PREFIX=$(brew --prefix qt@6)
echo "[OK] Qt6 at: $QT_PREFIX"

# 6. Show Qt path for reference
echo ""
echo "=== Setup Complete ==="
echo ""
echo "Qt6 CMAKE_PREFIX_PATH:"
echo "  $QT_PREFIX"
echo ""
echo "Quick start:"
echo "  ./scripts/build-macos.sh        # build + open in Xcode"
echo "  ./scripts/build-ios.sh sim      # iOS Simulator Xcode project"
echo "  ./scripts/build-ios.sh device   # iOS Device Xcode project"
echo ""

# 7. Check for Qt6 iOS (optional)
QT_IOS_PATH="$HOME/Qt/6.*/ios"
if ls -d $QT_IOS_PATH &>/dev/null 2>&1; then
    echo "[OK] Qt6 for iOS found at: $(ls -d $QT_IOS_PATH | head -1)"
else
    echo "[i] Qt6 for iOS NOT found."
    echo "    For iOS builds, install Qt6 iOS via the Qt Online Installer:"
    echo "    https://www.qt.io/download-qt-installer"
    echo "    Select: Qt > Qt 6.x > iOS"
    echo ""
    echo "    Typical path after install: ~/Qt/6.7.0/ios"
fi
