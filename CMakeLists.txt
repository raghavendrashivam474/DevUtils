cmake_minimum_required(VERSION 3.25)

project(
    DevUtils
    VERSION 0.2.0
    DESCRIPTION "A collection of developer utility tools"
    LANGUAGES CXX
)

# ──────────────────────────────────────────────
# C++ Standard
# ──────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ──────────────────────────────────────────────
# Compiler Warnings
# ──────────────────────────────────────────────
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Wsign-conversion
    )
elseif(MSVC)
    add_compile_options(/W4 /permissive-)
endif()

# ──────────────────────────────────────────────
# Build Type
# ──────────────────────────────────────────────
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Project  : ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Compiler : ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Standard : C++${CMAKE_CXX_STANDARD}")
message(STATUS "Build    : ${CMAKE_BUILD_TYPE}")

# ──────────────────────────────────────────────
# Utilities
# (uncomment each as its sprint is completed)
# ──────────────────────────────────────────────
add_subdirectory(apps/Calculator)
add_subdirectory(apps/PasswordGenerator)
# add_subdirectory(apps/JSONFormatter)
# add_subdirectory(apps/Base64Encoder)
# add_subdirectory(apps/FileRenamer)
# add_subdirectory(apps/DuplicateFinder)
# add_subdirectory(apps/FolderSizeAnalyzer)
# add_subdirectory(apps/LogViewer)
# add_subdirectory(apps/ClipboardHistory)
# add_subdirectory(apps/HTTPDownloader)
# add_subdirectory(apps/PortScanner)
# add_subdirectory(apps/MiniGitHelper)
# add_subdirectory(apps/ProcessViewer)
