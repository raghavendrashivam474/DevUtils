# DevUtils — Architecture

## Overview

DevUtils follows a monorepo layout where each utility lives as an
independent application under apps/, while shared functionality
is centralised in the core/ library.

---

## Directory Responsibilities

| Directory  | Purpose                                      |
|------------|----------------------------------------------|
| apps/      | One subdirectory per utility application     |
| core/      | Shared headers and implementation            |
| tests/     | Unit and integration tests                   |
| cmake/     | Reusable CMake helper modules                |
| scripts/   | Build, format, and automation scripts        |
| docs/      | Project-level documentation                  |
| docs/reports/ | Sprint completion reports               |

---

## Build System

- CMake (minimum 3.25) with Ninja as the generator
- Each apps/<Utility> defines its own CMakeLists.txt
- The root CMakeLists.txt aggregates all subdirectories
- The core library is linked by utilities that require it

---

## Established Conventions

These conventions were defined in Sprint 1 and apply to every
utility in the repository from this point forward.

### Project Layout Per Utility

    apps/<UtilityName>/
    ├── include/
    │   └── <utility>.hpp      — declarations only
    ├── src/
    │   ├── <utility>.cpp      — implementations
    │   └── main.cpp           — thin entry point
    ├── tests/
    │   └── .gitkeep           — reserved for tests
    ├── CMakeLists.txt         — utility build target
    └── README.md              — utility documentation

### Architecture Rules

    Thin main()
    main() contains no business logic.
    It starts the application, drives the main loop, and exits.
    All real work is delegated to the utility module.

    Header / Source Separation
    All declarations live in include/<utility>.hpp.
    All implementations live in src/<utility>.cpp.
    This separation makes logic independently testable and readable.

    Namespace Per Utility
    Every utility wraps its symbols in a dedicated namespace.
    This prevents collisions as the repository grows to 13 utilities.

    Exception-Based Error Handling
    Risky operations throw typed exceptions.
    Callers catch and handle them without crashing.

    Input Validation
    All console input is validated in a loop before use.
    The application never crashes on unexpected user input.

    Utility-Specific CMakeLists.txt
    Each utility defines its own build target independently.
    The root CMakeLists.txt activates utilities via add_subdirectory.

    README Per Utility
    Every utility is independently documented with:
      - What it does
      - How to build it
      - How to run it
      - What concepts it introduces

---

## Coding Standards

- Language: C++20
- Formatting: LLVM style, 4-space indent, 100-column limit
- Warnings: -Wall -Wextra -Wpedantic treated seriously
- Naming: PascalCase for types, camelCase for variables,
  UPPER_SNAKE_CASE for constants

---

## Sprint Reports

Each sprint produces a formal completion report stored in docs/reports/.

    docs/reports/sprint-1-report.md
    docs/reports/sprint-2-report.md
    ...

Reports document objectives, metrics, lessons learned, and architecture
decisions made during that sprint.

---

## Metrics Tooling

    scripts/metrics.ps1

Automatically calculates per-utility and repository-wide metrics:
  - Source file count
  - Header file count
  - Lines of C++
  - Executable count
  - CMake file count
  - Documentation file count
  - Git statistics

Run before closing any sprint to populate the sprint report metrics table.

---

## Dependency Policy

- No external libraries unless specifically justified
- Prefer the C++ Standard Library and platform APIs
- All dependencies must be documented in the relevant sprint notes
