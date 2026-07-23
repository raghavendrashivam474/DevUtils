/**
 * @file    main.cpp
 * @brief   Entry point for the Password Generator utility.
 *
 * Responsibilities are intentionally minimal:
 *   - Display the application greeting
 *   - Delegate all logic to PasswordGenerator::runGenerator()
 *   - Display the exit message
 *
 * All business logic lives in password_generator.cpp.
 */

#include "password_generator.hpp"

#include <iostream>

int main()
{
    std::cout << "=============================\n"
              << "      Password Generator     \n"
              << "=============================\n\n";

    PasswordGenerator::runGenerator();

    std::cout << "\nThank you for using Password Generator.\n"
              << "Stay secure.\n\n";

    return 0;
}