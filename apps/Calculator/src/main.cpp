// ============================================================
// main.cpp
//
// Entry point for the DevUtils Calculator utility.
//
// Responsibilities:
//   - Start the application
//   - Run the calculation loop until the user exits
//   - Exit cleanly
//
// All calculation logic is in calculator.cpp.
// This file should remain as thin as possible.
// ============================================================

#include "calculator.hpp"

#include <iostream>

int main() {
    std::cout << "\n  Welcome to DevUtils Calculator\n";
    std::cout << "  --------------------------------\n";

    // Keep running calculations until the user chooses to quit.
    // runCalculation() returns false when the user selects [q].
    while (Calculator::runCalculation()) {
        // Nothing to do here — runCalculation handles everything
    }

    std::cout << "\n  Goodbye.\n\n";
    return 0;
}
