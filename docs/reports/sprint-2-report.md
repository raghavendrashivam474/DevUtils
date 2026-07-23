# Sprint 2 Report - Password Generator

**Project:** DevUtils
**Sprint:** 2
**Version:** v0.3.0
**Status:** Complete

---

## Objective

Implement a secure, configurable command-line password generator as the
second utility in the DevUtils repository, reinforcing the architectural
patterns established during Sprint 1.

---

## Deliverables

| Deliverable                             | Status  |
|-----------------------------------------|---------|
| password_generator.hpp                  | Done    |
| password_generator.cpp                  | Done    |
| main.cpp                                | Done    |
| apps/PasswordGenerator/CMakeLists.txt   | Done    |
| Root CMakeLists.txt updated             | Done    |
| apps/PasswordGenerator/README.md        | Done    |
| CHANGELOG.md updated                    | Done    |
| ROADMAP.md updated                      | Done    |
| Metrics generated                       | Done    |
| Sprint report written                   | Done    |
| Repository tagged v0.3.0               | Pending |

---

## Architecture

The utility follows the same conventions as the Calculator:

- Thin entry point — main.cpp contains only greeting, delegation, exit
- Module — all logic in password_generator.cpp
- Header — public interface only, no implementations
- Namespace — PasswordGenerator:: isolates all symbols

---

## Concepts Introduced

| Concept                           | Application                          |
|-----------------------------------|--------------------------------------|
| std::random_device                | Hardware entropy seed                |
| std::mt19937                      | Mersenne Twister random engine       |
| std::uniform_int_distribution     | Unbiased index selection             |
| struct configuration              | PasswordOptions parameter grouping   |
| Character pool construction       | std::string concatenation            |
| std::string_view constants        | Zero-cost character pool references  |
| Input validation loops            | Length and yes/no guards             |
| Namespace encapsulation           | PasswordGenerator:: isolation        |

---

## Validation

- Builds with zero warnings (GCC -Wall -Wextra -Wpedantic -Werror)
- Length below minimum rejected
- Length above maximum rejected
- Non-numeric input at length prompt rejected safely
- Non-Y/N input at boolean prompts rejected safely
- All categories disabled caught and re-prompted
- rand() and srand() not used anywhere
- Passwords contain only enabled character categories
- Password length matches requested length exactly
- Repeat generation loop works correctly
- Clean exit on user request

---

## Metrics

| Metric                  | Value |
|-------------------------|-------|
| .cpp files              | 4     |
| .hpp files              | 2     |
| Total source files      | 6     |
| Implementation lines    | 467   |
| Header lines            | 146   |
| Total C++ lines         | 613   |
| CMakeLists.txt files    | 2     |
| Executables built       | 2     |
| Markdown files          | 2     |
| Total commits           | 13    |
| Current tag             | v0.2.0 (v0.3.0 pending) |

---

## Notes

Password Generator serves as the second reference implementation in
DevUtils. It reinforces Sprint 1 architecture while introducing Modern
C++ random number facilities and structured configuration patterns.
All validation paths were tested manually and behaved correctly.