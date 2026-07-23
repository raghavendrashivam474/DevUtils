/**
 * @file    password_generator.cpp
 * @brief   Implementation of the Password Generator utility.
 *
 * Implements all logic declared in password_generator.hpp including:
 *   - Character pool construction
 *   - Random password generation via Modern C++ <random> facilities
 *   - Input collection and validation
 *   - Interactive session management
 */

#include "password_generator.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <random>

namespace PasswordGenerator
{
    // ----------------------------------------------------------------
    // Character Pool Constants
    // ----------------------------------------------------------------

    /// All uppercase letters.
    constexpr std::string_view POOL_UPPERCASE { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

    /// All lowercase letters.
    constexpr std::string_view POOL_LOWERCASE { "abcdefghijklmnopqrstuvwxyz" };

    /// All digit characters.
    constexpr std::string_view POOL_DIGITS    { "0123456789" };

    /// All supported symbol characters.
    constexpr std::string_view POOL_SYMBOLS   { "!@#$%^&*()-_=+[]{};:,.<>?" };


    // ----------------------------------------------------------------
    // Internal Helpers
    // ----------------------------------------------------------------

    /**
     * @brief   Builds the combined character pool from enabled categories.
     *
     * Concatenates only the pools whose corresponding flag is set in
     * the provided PasswordOptions struct.
     *
     * @param   options     User-selected generation options.
     * @return  A std::string containing every valid character.
     */
    static std::string buildCharacterPool(const PasswordOptions& options)
    {
        std::string pool {};

        if (options.uppercase) { pool += POOL_UPPERCASE; }
        if (options.lowercase) { pool += POOL_LOWERCASE; }
        if (options.digits)    { pool += POOL_DIGITS;    }
        if (options.symbols)   { pool += POOL_SYMBOLS;   }

        return pool;
    }


    /**
     * @brief   Prompts the user for a yes/no answer.
     *
     * Accepts only 'Y', 'y', 'N', or 'n'. Rejects all other input
     * and re-prompts until a valid response is received.
     *
     * @param   prompt      The question to display.
     * @return  true if the user answered yes, false otherwise.
     */
    static bool askYesNo(const std::string& prompt)
    {
        while (true)
        {
            std::cout << prompt;

            std::string input {};
            std::cin >> input;

            if (input == "Y" || input == "y") { return true;  }
            if (input == "N" || input == "n") { return false; }

            std::cout << "  Invalid input. Please enter Y or N.\n\n";
        }
    }


    /**
     * @brief   Prompts the user for a valid password length.
     *
     * Accepts only integers in the range [MIN_LENGTH, MAX_LENGTH].
     * Clears and ignores malformed input. Re-prompts until valid.
     *
     * @return  A validated password length as std::size_t.
     */
    static std::size_t askLength()
    {
        while (true)
        {
            std::cout << "Password length (" << MIN_LENGTH
                      << " - " << MAX_LENGTH << "): ";

            int input {};

            if (std::cin >> input)
            {
                if (input >= static_cast<int>(MIN_LENGTH) &&
                    input <= static_cast<int>(MAX_LENGTH))
                {
                    return static_cast<std::size_t>(input);
                }

                std::cout << "  Length must be between "
                          << MIN_LENGTH << " and "
                          << MAX_LENGTH << ".\n\n";
            }
            else
            {
                std::cout << "  Invalid input. Please enter a whole number.\n\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }


    /**
     * @brief   Collects and validates all PasswordOptions from the user.
     *
     * Prompts for length and each character category. Ensures at least
     * one category remains enabled. Re-prompts the category section if
     * all categories are disabled.
     *
     * @return  A fully validated PasswordOptions struct.
     */
    static PasswordOptions collectOptions()
    {
        PasswordOptions options {};

        // -- Length --
        options.length = askLength();
        std::cout << '\n';

        // -- Character categories --
        while (true)
        {
            options.uppercase = askYesNo("Include uppercase letters? (Y/N): ");
            options.lowercase = askYesNo("Include lowercase letters? (Y/N): ");
            options.digits    = askYesNo("Include digits?            (Y/N): ");
            options.symbols   = askYesNo("Include symbols?           (Y/N): ");

            if (options.uppercase ||
                options.lowercase ||
                options.digits    ||
                options.symbols)
            {
                break;
            }

            std::cout << "\n  At least one character category must be enabled.\n"
                      << "  Please reconfigure your options.\n\n";
        }

        return options;
    }


    /**
     * @brief   Prints a formatted section separator to standard output.
     * @param   title   The label to display inside the separator.
     */
    static void printSeparator(const std::string& title)
    {
        std::cout << "\n-----------------------------\n"
                  << title
                  << "\n-----------------------------\n";
    }


    // ----------------------------------------------------------------
    // Public Implementation
    // ----------------------------------------------------------------

    std::string generatePassword(const PasswordOptions& options)
    {
        const std::string pool { buildCharacterPool(options) };

        if (pool.empty())
        {
            throw std::invalid_argument(
                "Character pool is empty. Enable at least one category."
            );
        }

        // Seed the Mersenne Twister engine with a hardware random device.
        std::random_device              rd  {};
        std::mt19937                    engine { rd() };
        std::uniform_int_distribution<std::size_t>
                                        distribution { 0, pool.size() - 1 };

        std::string password {};
        password.reserve(options.length);

        for (std::size_t i { 0 }; i < options.length; ++i)
        {
            password += pool[distribution(engine)];
        }

        return password;
    }


    void runGenerator()
    {
        while (true)
        {
            // -- Collect configuration --
            printSeparator("Configuration");
            std::cout << '\n';

            const PasswordOptions options { collectOptions() };

            // -- Generate and display --
            printSeparator("Generated Password");

            const std::string password { generatePassword(options) };

            std::cout << '\n' << password << '\n';

            // -- Repeat prompt --
            printSeparator("Continue");
            std::cout << '\n';

            const bool again { askYesNo("Generate another password? (Y/N): ") };

            if (!again) { break; }

            std::cout << '\n';
        }
    }

} // namespace PasswordGenerator