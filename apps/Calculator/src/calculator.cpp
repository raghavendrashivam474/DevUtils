// ============================================================
// calculator.cpp
//
// Implementation of all Calculator functions declared in
// calculator.hpp.
//
// This file contains:
//   - The four arithmetic operations
//   - Input validation and reading
//   - Menu display
//   - The main calculation loop
// ============================================================

#include "calculator.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace Calculator {

// ------------------------------------------------------------
// Arithmetic operations
// ------------------------------------------------------------

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    // Guard against division by zero before performing the operation.
    // Throwing an exception allows the caller to decide how to respond
    // rather than crashing or producing undefined behaviour.
    if (b == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}

// ------------------------------------------------------------
// User interface helpers
// ------------------------------------------------------------

void displayMenu() {
    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "       DevUtils Calculator    \n";
    std::cout << "==============================\n";
    std::cout << "  [+]  Addition              \n";
    std::cout << "  [-]  Subtraction           \n";
    std::cout << "  [*]  Multiplication        \n";
    std::cout << "  [/]  Division              \n";
    std::cout << "  [q]  Quit                  \n";
    std::cout << "==============================\n";
    std::cout << "  Select operation: ";
}

double getValidNumber(const char* prompt) {
    double value{};

    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.good()) {
            // Input was a valid number — clear any leftover characters
            // on the line and return the value
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }

        // Input was not a valid number.
        // Clear the error state and discard the bad input,
        // then prompt the user again.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [!] Invalid input. Please enter a number.\n";
    }
}

char getValidChoice() {
    while (true) {
        std::string input{};
        std::getline(std::cin, input);

        // We only care about the first character of the input
        if (!input.empty()) {
            char choice = input[0];

            // Accept only the valid operation characters
            if (choice == '+' || choice == '-' ||
                choice == '*' || choice == '/' ||
                choice == 'q' || choice == 'Q') {
                return choice;
            }
        }

        std::cout << "  [!] Invalid choice. Enter +, -, *, / or q: ";
    }
}

bool runCalculation() {
    displayMenu();

    char choice = getValidChoice();

    // User chose to exit
    if (choice == 'q' || choice == 'Q') {
        return false;
    }

    // Collect the two operands
    double a = getValidNumber("  Enter first number  : ");
    double b = getValidNumber("  Enter second number : ");

    // Perform the selected operation and display the result.
    // Division is wrapped in a try/catch to handle division by zero
    // without crashing the application.
    std::cout << "\n  Result: ";

    try {
        double result{};

        switch (choice) {
        case '+':
            result = add(a, b);
            std::cout << a << " + " << b << " = " << result << "\n";
            break;
        case '-':
            result = subtract(a, b);
            std::cout << a << " - " << b << " = " << result << "\n";
            break;
        case '*':
            result = multiply(a, b);
            std::cout << a << " * " << b << " = " << result << "\n";
            break;
        case '/':
            result = divide(a, b);
            std::cout << a << " / " << b << " = " << result << "\n";
            break;
        default:
            std::cout << "Unknown operation.\n";
            break;
        }
    } catch (const std::invalid_argument& e) {
        // Division by zero was attempted — report it cleanly
        std::cout << "\n  [!] Error: " << e.what() << "\n";
    }

    return true; // Signal that the application should continue
}

} // namespace Calculator
