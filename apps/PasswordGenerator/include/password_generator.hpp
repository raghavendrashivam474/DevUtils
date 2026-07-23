/**
 * @file    password_generator.hpp
 * @brief   Public interface for the Password Generator utility.
 *
 * Declares the PasswordOptions configuration structure and the
 * public functions exposed by the PasswordGenerator module.
 *
 * All declarations are encapsulated within the PasswordGenerator
 * namespace to prevent naming collisions with other DevUtils
 * utilities.
 */

#ifndef PASSWORD_GENERATOR_HPP
#define PASSWORD_GENERATOR_HPP

#include <string>
#include <cstddef>

namespace PasswordGenerator
{
    // ----------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------

    /// Minimum accepted password length.
    constexpr std::size_t MIN_LENGTH { 4 };

    /// Maximum accepted password length.
    constexpr std::size_t MAX_LENGTH { 128 };


    // ----------------------------------------------------------------
    // Configuration Structure
    // ----------------------------------------------------------------

    /**
     * @brief Holds all user-selected options for password generation.
     *
     * Each boolean field enables or disables a character category.
     * At least one category must be enabled before generation begins.
     */
    struct PasswordOptions
    {
        std::size_t length    { 16 };   ///< Desired password length.

        bool uppercase { true  };       ///< Include uppercase letters A-Z.
        bool lowercase { true  };       ///< Include lowercase letters a-z.
        bool digits    { true  };       ///< Include digits 0-9.
        bool symbols   { false };       ///< Include symbol characters.
    };


    // ----------------------------------------------------------------
    // Public Interface
    // ----------------------------------------------------------------

    /**
     * @brief   Generates a random password from the provided options.
     *
     * Builds a character pool from all enabled categories, then
     * selects characters at random using std::mt19937 seeded by
     * std::random_device.
     *
     * @param   options     A fully validated PasswordOptions struct.
     * @return  A std::string of exactly options.length characters.
     */
    std::string generatePassword(const PasswordOptions& options);

    /**
     * @brief   Runs the full interactive Password Generator session.
     *
     * Handles all user interaction including:
     *   - Collecting and validating configuration options
     *   - Generating and displaying passwords
     *   - Prompting for repeat generation
     *
     * Called once from main(). Returns when the user chooses to exit.
     */
    void runGenerator();

} // namespace PasswordGenerator

#endif // PASSWORD_GENERATOR_HPP