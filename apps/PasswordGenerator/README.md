\# Password Generator



\## Purpose



Password Generator is the second utility in the DevUtils repository.

It produces configurable, cryptographically seeded random passwords

from the command line.



\---



\## Features



\- Configurable password length (4 to 128 characters)

\- Optional character categories:

&#x20; - Uppercase letters (A–Z)

&#x20; - Lowercase letters (a–z)

&#x20; - Digits (0–9)

&#x20; - Symbols (!@#$%^\&\*…)

\- Full input validation with safe error recovery

\- Repeat generation within a single session

\- Zero external dependencies



\---



\## Build Instructions



From the repository root:



```powershell

cmake -S . -B build

cmake --build build

.\\build\\apps\\PasswordGenerator\\PasswordGenerator.exe



Concepts Learned



Concept	Application

std::random\_device	Hardware entropy seed

std::mt19937	Mersenne Twister random engine

std::uniform\_int\_distribution	Unbiased index selection

struct configuration	PasswordOptions parameter grouping

Character pool construction	std::string concatenation

Input validation loops	Length and yes/no guards

std::string\_view constants	Zero-cost character pool references

Namespace encapsulation	PasswordGenerator:: isolation



Repository Position



DevUtils/

└── apps/

&#x20;   ├── Calculator/         ← Sprint 1

&#x20;   └── PasswordGenerator/  ← Sprint 2 (this utility)





Out of Scope



The following features are intentionally excluded from this sprint:



Clipboard integration

File export

Password strength estimation

Command-line flags

Unit tests

