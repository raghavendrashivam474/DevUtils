# DevUtils

A structured collection of developer utility tools built in Modern C++.

---

## Vision

DevUtils is a personal engineering project designed to grow alongside the
developer. Each utility is self-contained, progressively more complex, and
built on a shared foundation — making the repository a living portfolio of
systems programming skills.

---

## Goals

- Practice Modern C++ (C++20) idioms and best practices
- Build real, usable command-line tools
- Develop familiarity with CMake, testing, and project architecture
- Produce a clean, professional repository suitable for portfolio use

---

## Repository Layout

    DevUtils/
    ├── apps/       - Individual utility applications
    ├── core/       - Shared library (utilities, helpers)
    ├── docs/       - Project documentation
    ├── scripts/    - Build and automation scripts
    ├── tests/      - Unit and integration tests
    ├── cmake/      - CMake helper modules
    └── .github/    - GitHub configuration

---

## Build Requirements

| Tool  | Minimum Version | Notes             |
|-------|-----------------|-------------------|
| GCC   | 13.0            | Via MSYS2 UCRT64  |
| CMake | 3.25            |                   |
| Ninja | 1.11            |                   |
| Git   | 2.40            |                   |
| C++   | C++20           | Required standard |

### Environment Setup (Windows)

1. Install MSYS2 from https://www.msys2.org/
2. Open the UCRT64 terminal and run:

    pacman -S mingw-w64-ucrt-x86_64-gcc
    pacman -S mingw-w64-ucrt-x86_64-cmake
    pacman -S mingw-w64-ucrt-x86_64-ninja

3. Add C:\msys64\ucrt64\bin to your system PATH

### Build

    cmake -S . -B build -G "Ninja"
    cmake --build build

---

## Learning Roadmap

See docs/ROADMAP.md for the full sprint plan.

---

## Architecture

See docs/ARCHITECTURE.md for design decisions.

---

## Changelog

See docs/CHANGELOG.md for version history.

---

## License

MIT — see LICENSE
