# DevUtils — Architecture

## Overview

DevUtils follows a monorepo layout where each utility lives as an
independent application under `apps/`, while shared functionality
is centralised in the `core/` library.

---

## Directory Responsibilities

| Directory  | Purpose                                      |
|------------|----------------------------------------------|
| `apps/`    | One subdirectory per utility application     |
| `core/`    | Shared headers and implementation            |
| `tests/`   | Unit and integration tests                   |
| `cmake/`   | Reusable CMake helper modules                |
| `scripts/` | Build, format, and automation scripts        |
| `docs/`    | Project-level documentation                  |

---

## Build System

- **CMake** (minimum 3.25) with **Ninja** as the generator
- Each `apps/<Utility>` defines its own `CMakeLists.txt`
- The root `CMakeLists.txt` aggregates all subdirectories
- The `core` library is linked by utilities that require it

---

## Coding Standards

- Language: **C++20**
- Formatting: **LLVM style**, 4-space indent, 100-column limit
- Warnings: `-Wall -Wextra -Wpedantic` treated seriously
- Naming: `PascalCase` for types, `camelCase` for variables,
  `UPPER_SNAKE_CASE` for constants

---

## Dependency Policy

- **No external libraries** unless specifically justified
- Prefer the C++ Standard Library and platform APIs
- All dependencies must be documented in the relevant sprint notes
