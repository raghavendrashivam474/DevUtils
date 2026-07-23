# Changelog

All notable changes to DevUtils are documented here.

---

## [v0.3.0] - Sprint 2

### Added
- Password Generator utility (apps/PasswordGenerator)
- PasswordOptions configuration structure
- generatePassword() - core generation engine
- runGenerator() - interactive session manager
- Character pool system with four selectable categories
- Full input validation for length and yes/no prompts
- Repeat generation loop
- apps/PasswordGenerator/README.md
- docs/reports/sprint-2-report.md

### Changed
- Root CMakeLists.txt updated to include PasswordGenerator

### Engineering
- Modern C++ random facilities (std::random_device, std::mt19937)
- std::uniform_int_distribution for unbiased index selection
- Zero warnings on GCC -Wall -Wextra -Wpedantic -Werror

---

## [v0.2.0] - Sprint 1

### Added
- Calculator utility (apps/Calculator)
- Four arithmetic operations: addition, subtraction, multiplication, division
- Division by zero protection
- Full input validation with safe error recovery
- Repeat calculation loop
- apps/Calculator/README.md
- docs/reports/sprint-1-report.md

### Engineering
- CMake build system established
- C++20 standard enforced across all targets
- Namespace encapsulation pattern established
- Thin entry point architecture established

---

## [v0.1.0] - Sprint 0

### Added
- Repository initialized
- Root CMakeLists.txt
- CHANGELOG.md
- ROADMAP.md
- .gitignore
- README.md
- scripts/metrics.ps1
- docs/ directory structure