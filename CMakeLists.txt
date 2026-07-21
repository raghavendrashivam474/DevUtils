cmake_minimum_required(VERSION 3.25)

project(
    DevUtils
    VERSION 0.1.0
    DESCRIPTION "A collection of developer utility tools"
    LANGUAGES CXX
)

# ----------------------------------------------
# C++ Standard
# ----------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ----------------------------------------------
# Compiler Warnings
# ----------------------------------------------
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

# ----------------------------------------------
# Build Type
# ----------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Project  : ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Compiler : ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Standard : C++${CMAKE_CXX_STANDARD}")
message(STATUS "Build    : ${CMAKE_BUILD_TYPE}")

# ----------------------------------------------
# Subdirectories (enabled as sprints progress)
# ----------------------------------------------
# add_subdirectory(core)
# add_subdirectory(apps)
