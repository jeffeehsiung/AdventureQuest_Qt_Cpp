# iOS Toolchain for CMake
# Usage: cmake -DCMAKE_TOOLCHAIN_FILE=cmake/ios.toolchain.cmake ..

set(CMAKE_SYSTEM_NAME iOS)
set(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "Build architectures for iOS")
set(CMAKE_OSX_DEPLOYMENT_TARGET "15.0" CACHE STRING "Minimum iOS deployment target")

# Use the iPhone SDK
set(CMAKE_OSX_SYSROOT "iphoneos" CACHE STRING "iOS SDK")

# Skip compiler checks for cross-compilation
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Standard settings
set(CMAKE_XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH NO)
set(CMAKE_IOS_INSTALL_COMBINED YES)

# Bitcode is deprecated in Xcode 14+
set(CMAKE_XCODE_ATTRIBUTE_ENABLE_BITCODE NO)

# ARC
set(CMAKE_XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES)

set(IOS_PLATFORM TRUE)
