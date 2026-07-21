#pragma once

// ============================================================
// calculator.hpp
//
// Declarations for the Calculator utility.
//
// This header defines the public interface of the calculator
// module. Any file that needs to perform calculations includes
// this header.
//
// The implementation of these functions lives in calculator.cpp
// ============================================================

namespace Calculator {

// ------------------------------------------------------------
// Core arithmetic operations
//
// Each function takes two doubles and returns a double.
// All four functions are pure — they have no side effects.
// ------------------------------------------------------------

// Returns the sum of a and b
double add(double a, double b);

// Returns the difference of a and b
double subtract(double a, double b);

// Returns the product of a and b
double multiply(double a, double b);

// Divides a by b.
// Throws std::invalid_argument if b is zero.
double divide(double a, double b);

// ------------------------------------------------------------
// User interface helpers
//
// These functions handle the menu display and input collection.
// They are declared here so main.cpp can call them cleanly.
// ------------------------------------------------------------

// Displays the operation menu to the console
void displayMenu();

// Reads and validates a double from standard input.
// Keeps prompting until the user enters a valid number.
double getValidNumber(const char* prompt);

// Reads and validates the user's menu choice.
// Returns a char representing the selected operation.
char getValidChoice();

// Runs one complete calculation cycle:
//   1. Show menu
//   2. Get choice
//   3. Get numbers
//   4. Compute and display result
// Returns true if the user wants to continue, false to exit.
bool runCalculation();

} // namespace Calculator
