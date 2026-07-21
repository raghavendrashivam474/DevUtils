# Calculator

**Sprint 1 — DevUtils**

A console-based arithmetic calculator. The first utility in the DevUtils
repository and the reference implementation for all future applications.

---

## What It Does

Evaluates basic arithmetic expressions entered interactively via a menu.

Supported operations:

    [+]  Addition
    [-]  Subtraction
    [*]  Multiplication
    [/]  Division  (division by zero is handled gracefully)

---

## How To Build

From the repository root:

    cmake -S . -B build -G "Ninja"
    cmake --build build

The executable will be located at:

    build/apps/Calculator/Calculator.exe

---

## How To Run

    ./build/apps/Calculator/Calculator.exe

---

## Project Structure

    Calculator/
    ├── include/
    │   └── calculator.hpp   - Function declarations (the interface)
    ├── src/
    │   ├── calculator.cpp   - Function implementations (the logic)
    │   └── main.cpp         - Entry point (starts the program)
    ├── tests/
    │   └── .gitkeep         - Reserved for future tests
    ├── CMakeLists.txt       - Build definition for this utility
    └── README.md            - This file

---

## Concepts Introduced

- Header files and source file separation
- Namespaces
- Input validation with cin
- Exception handling for division by zero
- Switch statements
- Loops
- CMake executable targets
- Multi-file C++ project structure

---

## Notes

This utility intentionally uses a simple menu-driven design rather than
expression parsing. Expression parsing (e.g. evaluating "2 + 3 * 4") will
be explored in a future sprint.
