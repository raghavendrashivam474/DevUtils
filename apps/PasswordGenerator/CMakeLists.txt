# =============================================================================
# apps/PasswordGenerator/CMakeLists.txt
#
# Build configuration for the Password Generator utility.
# Follows the same conventions established by the Calculator utility.
# =============================================================================

cmake_minimum_required(VERSION 3.20)

# -----------------------------------------------------------------------------
# Executable Target
# -----------------------------------------------------------------------------

add_executable(PasswordGenerator
    src/main.cpp
    src/password_generator.cpp
)

# -----------------------------------------------------------------------------
# Include Directories
# -----------------------------------------------------------------------------

target_include_directories(PasswordGenerator
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# -----------------------------------------------------------------------------
# Language Standard
# -----------------------------------------------------------------------------

target_compile_features(PasswordGenerator
    PRIVATE
        cxx_std_20
)

# -----------------------------------------------------------------------------
# Compiler Warnings
# -----------------------------------------------------------------------------

if(MSVC)
    target_compile_options(PasswordGenerator PRIVATE /W4 /WX)
else()
    target_compile_options(PasswordGenerator PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()