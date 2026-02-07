#!/bin/bash
set -euo pipefail

# ============================================================================
# setup-mac.sh - Install all dependencies on macOS for AdventureQuest
# ============================================================================
# Usage:  ./scripts/setup-mac.sh
# ============================================================================

echo "=== AdventureQuest macOS Setup ==="
echo ""

# 1. Check / install Xcode Command Line Tools
if ! xcode-select -p &>/dev/null; then
    echo "[!] Xcode Command Line Tools not found. Installing..."
    xcode-select --install
    echo "    Please complete the Xcode install dialog, then re-run this script."
    exit 1
fi
echo "[OK] Xcode CLT: $(xcode-select -p)"

# 2. Check Xcode.app + point xcode-select to it
if [ -d "/Applications/Xcode.app" ]; then
    XCODE_VER=$(xcodebuild -version 2>/dev/null | head -1 || echo "unknown")
    echo "[OK] Xcode.app: $XCODE_VER"

    # Ensure xcode-select points to Xcode.app (not standalone CLT)
    CURRENT_PATH=$(xcode-select -p)
    if [ "$CURRENT_PATH" != "/Applications/Xcode.app/Contents/Developer" ]; then
        echo "    Switching xcode-select to Xcode.app..."
        sudo xcode-select -s /Applications/Xcode.app/Contents/Developer
        echo "    [OK] Now using: /Applications/Xcode.app/Contents/Developer"
    fi

    # Accept Xcode license
    if ! xcodebuild -license check &>/dev/null 2>&1; then
        echo "    Accepting Xcode license..."
        sudo xcodebuild -license accept
        echo "    [OK] License accepted"
    fi
else
    echo "[!] Xcode.app not found in /Applications"
    echo "    Download from the App Store for Xcode builds."
    echo "    Desktop command-line builds will still work."
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
QT_PREFIX=""
for formula in qt@6 qt; do
    if brew list "$formula" &>/dev/null 2>&1; then
        QT_PREFIX=$(brew --prefix "$formula")
        echo "[OK] Qt6 already installed ($formula)"
        break
    fi
done

if [ -z "$QT_PREFIX" ]; then
    echo "[ ] Installing Qt6 (this may take a few minutes)..."
    brew install qt
    QT_PREFIX=$(brew --prefix qt)
fi

echo "[OK] Qt6 at: $QT_PREFIX"

# 6. Verify the C++ compiler is accessible
echo ""
echo "Verifying compiler..."
if xcrun --find clang++ &>/dev/null 2>&1; then
    echo "[OK] C++ compiler: $(xcrun --find clang++)"
else
    echo "[!] clang++ not found via xcrun."
    echo "    Try: sudo xcode-select -s /Applications/Xcode.app/Contents/Developer"
    echo "    Then re-run this script."
    exit 1
fi

# 7. Summary
echo ""
echo "=== Setup Complete ==="
echo ""
echo "Qt6 CMAKE_PREFIX_PATH:"
echo "  $QT_PREFIX"
echo ""
echo "Quick start:"
echo "  ./scripts/build-macos.sh          # Xcode project for macOS"
echo "  ./scripts/build-macos.sh --build  # Command-line build"
echo "  ./scripts/build-ios.sh sim        # Xcode project for iOS Simulator"
echo "  ./scripts/build-ios.sh device     # Xcode project for iPhone"
echo ""

# 8. Check for Qt6 iOS (optional)
QT_IOS_PATH="$HOME/Qt/6.*/ios"
if ls -d $QT_IOS_PATH &>/dev/null 2>&1; then
    echo "[OK] Qt6 for iOS found at: $(ls -d $QT_IOS_PATH | head -1)"
else
    echo "[i] Qt6 for iOS NOT found."
    echo "    For iOS builds, install Qt6 iOS via the Qt Online Installer:"
    echo "    https://www.qt.io/download-qt-installer-oss"
    echo "    Select: Qt > Qt 6.x > iOS"
    echo ""
    echo "    Typical path after install: ~/Qt/6.8.0/ios"
fi
