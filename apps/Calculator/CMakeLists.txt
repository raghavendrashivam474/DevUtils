# ============================================================
# apps/Calculator/CMakeLists.txt
#
# Build definition for the Calculator utility.
#
# This file defines:
#   - The Calculator executable target
#   - Its source files
#   - Its include directories
#   - Compiler warning settings
# ============================================================

cmake_minimum_required(VERSION 3.25)

# ──────────────────────────────────────────────
# Executable target
#
# We list every .cpp file that must be compiled.
# CMake will compile each one and link them
# together into a single executable.
# ──────────────────────────────────────────────
add_executable(Calculator
    src/main.cpp
    src/calculator.cpp
)

# ──────────────────────────────────────────────
# Include directories
#
# This tells the compiler where to find header
# files when source files use #include "...".
#
# PRIVATE means this setting applies only to
# the Calculator target, not to anything that
# links against it.
# ──────────────────────────────────────────────
target_include_directories(Calculator
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ──────────────────────────────────────────────
# C++ Standard
#
# Enforce C++20 for this target explicitly,
# even though the root also sets it globally.
# ──────────────────────────────────────────────
target_compile_features(Calculator
    PRIVATE
        cxx_std_20
)

# ──────────────────────────────────────────────
# Compiler warnings
#
# Treat the code seriously from the start.
# Warnings are errors of intent — they should
# not be ignored.
# ──────────────────────────────────────────────
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(Calculator
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wshadow
            -Wconversion
            -Wsign-conversion
    )
endif()

message(STATUS "Configuring utility : Calculator")
