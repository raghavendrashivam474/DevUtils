# DevUtils — Sprint 1 Completion Report

**To:** Senior Developer
**From:** Raghavendra Shivam
**Date:** June 2025
**Project:** DevUtils
**Sprint:** 1 — Calculator
**Repository Version:** v0.2.0
**Utilities Complete:** 1 / 13

---

## Repository Progression
v0.1.0 v0.2.0 v0.3.0
Project Foundation → First Utility → Random Generation
(Sprint 0) (Sprint 1) (Sprint 2)

---

## Executive Summary

Sprint 1 has been completed successfully. The first utility in the DevUtils
repository — a console-based arithmetic calculator — has been implemented,
tested, documented, and published to GitHub as release v0.2.0.

The Calculator serves as the reference implementation and establishes the
engineering patterns, project conventions, and development workflow that all
subsequent utilities in this repository will follow.

---

## Sprint Objectives — Status

| Objective                                          | Status      |
|----------------------------------------------------|-------------|
| Create the first independent utility under apps/   | Complete    |
| Establish multi-file C++ project structure         | Complete    |
| Separate declarations and implementations          | Complete    |
| Integrate with root CMake build system             | Complete    |
| Build a clean command-line interface               | Complete    |
| Implement input validation and error handling      | Complete    |
| Produce the first executable in the repository     | Complete    |
| Establish reusable patterns for future utilities   | Complete    |

---

## Sprint Metrics

| Metric                        | Value                              |
|-------------------------------|------------------------------------|
| Source files written          | 2 (calculator.cpp, main.cpp)       |
| Header files written          | 1 (calculator.hpp)                 |
| Lines of C++                  | ~190                               |
| CMake files added             | 1 (apps/Calculator/CMakeLists.txt) |
| CMake files modified          | 1 (root CMakeLists.txt)            |
| Documentation files created   | 1 (apps/Calculator/README.md)      |
| Documentation files updated   | 2 (CHANGELOG.md, ROADMAP.md)       |
| Executables produced          | 1 (Calculator.exe)                 |
| Compiler warnings             | 0                                  |
| Compiler errors               | 0                                  |
| Test cases verified           | 8                                  |

---

## Functional Requirements — Verification

| Requirement        | Test Input | Result                    | Status |
|--------------------|------------|---------------------------|--------|
| Addition           | 10 + 3     | 13                        | Pass   |
| Subtraction        | 10 - 3     | 7                         | Pass   |
| Multiplication     | 5 x 4      | 20                        | Pass   |
| Division           | 10 / 2     | 5                         | Pass   |
| Division by zero   | 9 / 0      | Error message, no crash   | Pass   |
| Invalid input      | abc        | Re-prompt, no crash       | Pass   |
| Clean exit         | q          | Goodbye message, exit     | Pass   |
| Continuous loop    | Multiple   | Loop behaves correctly    | Pass   |

All eight functional requirements verified manually.
Zero crashes observed across all test cases.

---

## Deliverables

### Source Code

    apps/Calculator/
    ├── include/
    │   └── calculator.hpp     — Public interface and function declarations
    ├── src/
    │   ├── calculator.cpp     — All arithmetic logic and UI implementation
    │   └── main.cpp           — Thin entry point, orchestration only
    ├── tests/
    │   └── .gitkeep           — Reserved for future test integration
    ├── CMakeLists.txt         — Calculator-specific build target
    └── README.md              — Utility documentation

### Build System Integration

The root CMakeLists.txt was updated from v0.1.0 to v0.2.0 and now includes:

    add_subdirectory(apps/Calculator)

The Calculator target builds cleanly with zero warnings under:

    GCC 16.1.0   -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion

### Documentation Updated

| Document                    | Change                                      |
|-----------------------------|---------------------------------------------|
| apps/Calculator/README.md   | Created — utility usage, structure, concepts|
| docs/CHANGELOG.md           | Updated — v0.2.0 entry added               |
| docs/ROADMAP.md             | Updated — Sprint 1 marked complete          |

---

## Architecture Established

Sprint 1 defines the conventions that every future utility will inherit.

| Convention                        | Detail                                         |
|-----------------------------------|------------------------------------------------|
| Thin main()                       | Entry point contains no business logic         |
| Business logic separated          | All logic lives in calculator.cpp              |
| Namespace per utility             | namespace Calculator encapsulates all symbols  |
| include/src layout                | Declarations and implementations separated     |
| Utility-specific CMakeLists.txt   | Each utility owns its build definition         |
| README.md per utility             | Every utility is independently documented      |
| Exception-based error handling    | Errors are caught, reported, recovered from    |
| Input validation loop             | All console input validated before use         |

Future utilities simply inherit this architecture.
The patterns do not need to be reinvented.

---

## Engineering Standards Applied

### Coding Standards

| Standard                          | Applied          |
|-----------------------------------|------------------|
| C++20                             | Yes              |
| LLVM formatting, 4-space indent   | Yes              |
| -Wall -Wextra -Wpedantic          | Yes, zero warns  |
| Meaningful commit messages        | Yes              |
| LF line endings via .gitattributes| Yes              |

---

## Build Environment

| Tool       | Version              |
|------------|----------------------|
| GCC        | 16.1.0 (MSYS2 UCRT64)|
| CMake      | 4.4.0                |
| Ninja      | 1.13.2               |
| Git        | 2.54.0               |
| C++ Standard | C++20              |
| Platform   | Windows 11, MSYS2    |

### Build Output

    cmake -S . -B build -G "Ninja"

    -- Project  : DevUtils v0.2.0
    -- Compiler : GNU 16.1.0
    -- Standard : C++20
    -- Build    : Debug
    -- Configuring utility : Calculator
    -- Configuring done
    -- Generating done

    cmake --build build

    [1/3] Building CXX object ...calculator.cpp.obj
    [2/3] Building CXX object ...main.cpp.obj
    [3/3] Linking CXX executable Calculator.exe

    Result: Zero errors. Zero warnings.

---

## C++ Concepts Introduced

| Concept                       | Application                                    |
|-------------------------------|------------------------------------------------|
| Header files .hpp             | calculator.hpp — declarations only             |
| Source files .cpp             | calculator.cpp — implementations               |
| Namespaces                    | namespace Calculator encapsulates all symbols  |
| Pure functions                | Arithmetic functions have no side effects      |
| std::cin validation           | getValidNumber() handles malformed input       |
| std::getline                  | getValidChoice() reads full input lines safely |
| std::numeric_limits           | Flushes the input buffer reliably              |
| Exception handling            | throw / try / catch for division by zero       |
| Switch statements             | Clean operation dispatch                       |
| While loops                   | Application continues until user exits         |
| CMake add_executable          | Defines the Calculator build target            |
| CMake target_include_dirs     | Makes include/ visible to source files         |
| CMake target_compile_features | Enforces cxx_std_20 per target                 |
| CMake add_subdirectory        | Integrates Calculator into root build          |

---

## Lessons Learned

### Why header and source separation matters
Keeping declarations in .hpp and implementations in .cpp means that any
file needing the Calculator functionality only needs to read the header.
The internal logic can change without affecting anything that depends on
the interface. This is the foundation of maintainable C++ design.

### Why namespaces prevent symbol collisions
As the repository grows to 13 utilities, function names like add, divide,
or run will appear in many places. Wrapping each utility in its own namespace
means there is never ambiguity. Calculator::add and PasswordGenerator::generate
will coexist without conflict.

### How CMake manages targets
CMake does not build files — it builds targets. Defining add_executable tells
CMake what to produce and from which sources. Per-target properties via
target_include_directories and target_compile_features scale cleanly across
13 utilities without interference.

### Why input validation cannot be optional
A console application that crashes on unexpected input is not a tool — it is
a prototype. Wrapping every read from std::cin in a validation loop and every
risky operation in a try/catch block is what separates a program that works
in a demo from one that works in practice.

### Why main() should stay thin
When main() contains business logic, that logic cannot be tested, reused, or
reasoned about independently. When main() simply starts a loop and delegates
to well-named functions, the program intent is immediately legible to any reader.

---

## Version Control

### Sprint 1 Commits

    d0e5c4b  (tag: v0.2.0)  docs: update CHANGELOG and ROADMAP for Sprint 1
    6a086f2                  feat: implement Calculator utility

### Full Repository History at Sprint Close

    d0e5c4b  (tag: v0.2.0)  docs: update CHANGELOG and ROADMAP for Sprint 1
    6a086f2                  feat: implement Calculator utility
    7e2c0d5  (tag: v0.1.0)  fix: add README and normalize line endings
    d15f85d                  build: verify project configuration
    9571ffa                  chore: scaffold utility workspace
    a0b6d7d                  chore: initialize core library structure
    96ca276                  style: add repository coding standards
    e807190                  chore: initialize repository structure

### Release

| Field       | Value                                          |
|-------------|------------------------------------------------|
| Tag         | v0.2.0                                         |
| Title       | Sprint 1 — Calculator                          |
| Repository  | github.com/raghavendrashivam474/DevUtils        |
| Branch      | main                                           |
| State       | Published                                      |

---

## Known Limitations

| Limitation            | Notes                                              |
|-----------------------|----------------------------------------------------|
| No expression parsing | Two operands only. Parsing planned for future sprint|
| No automated tests    | Scaffolded. Testing framework to be integrated later|
| Console only          | No file output or clipboard integration this sprint |

These limitations are intentional for Sprint 1 scope.
They do not affect correctness or stability.

---

## Sprint Acceptance Criteria — Final Check

| Criterion                                        | Status   |
|--------------------------------------------------|----------|
| Calculator builds successfully through CMake     | Pass     |
| All four arithmetic operations work correctly    | Pass     |
| Invalid inputs are handled safely                | Pass     |
| Division by zero is prevented                    | Pass     |
| Application follows DevUtils project standards   | Pass     |
| Utility is documented                            | Pass     |
| Committed through meaningful Git milestones      | Pass     |
| Repository is ready for Sprint 2                 | Pass     |

---

## The Bigger Picture

This repository is not a collection of isolated programs.
It is a documented engineering journey.

    v0.1.0   Project Foundation       — Environment, standards, structure
    v0.2.0   Calculator               — Functions, headers, input handling
    v0.3.0   Password Generator       — Randomness, structs, CLI arguments
    v0.4.0   JSON Formatter           — Parsing, recursion, tree structures
    v0.5.0   Base64 Encoder           — Bitwise operations, encoding schemes
    v0.6.0   File Renamer             — Filesystem API, regex, dry-run design
    v0.7.0   Duplicate Finder         — Hashing, traversal, performance
    v0.8.0   Folder Size Analyzer     — Recursive traversal, formatting
    v0.9.0   Log Viewer               — File I/O, filtering, ANSI colour
    v0.10.0  Clipboard History        — Platform APIs, background state
    v0.11.0  HTTP Downloader          — Networking, sockets, progress display
    v0.12.0  Port Scanner             — Concurrency, timeout handling
    v0.13.0  Mini Git Helper          — Process execution, output parsing
    v1.0.0   Process Viewer           — OS APIs, memory, tabular display

Each sprint builds on the last. Every concept introduced in Sprint 1
reappears and deepens in later sprints. By v1.0.0, the repository will
demonstrate not just that the developer can write C++ — but that they can
architect, document, and ship a coherent engineering project from first
principles.

---

## Next Sprint

Sprint 2 — Password Generator  v0.3.0

Introduces command-line argument parsing, the C++ random library,
struct-based configuration, and string pool construction.
Follows the architectural conventions established by the Calculator.

---

Report prepared at sprint close.
All claims verified against live build output and repository state.
