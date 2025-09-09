# Copilot Instructions for Tarea2 (Prog2)

## Project Overview
This is a C++ project for Laboratorio de Programación 2 (InCo-FIng-UDELAR). The codebase models a library system with components for books, members (socios), loans (prestamos), and related data structures. The architecture is modular, with each major entity implemented as a separate TAD (Tipo Abstracto de Datos) in its own header/source pair.

## Directory Structure
- `src/` — C++ source files for each TAD (e.g., `libro.cpp`, `socio.cpp`, `abbLibros.cpp`, etc.)
- `include/` — Header files for each TAD
- `obj/` — Compiled object files
- `test/` — Input/output files for automated test cases
- `Makefile` — Defines build, test, and clean workflows

## Build & Test Workflow
- **Build:** Run `make` or `make all` to compile all modules and link the main executable (`principal`).
- **Test:** Run `make testing` to execute all public and private test cases. Test cases use input files from `test/*.in` and compare output against `test/*.out` using diff. Valgrind is used for memory checks except for time tests (`*-tiempo.in`).
- **Individual Test:** Use `make t-<caso>` or `make tt-<caso>` to run a single test with or without valgrind (e.g., `make t-socio1-crear-imprimir-liberar`).
- **Clean:** Use `make clean`, `make clean_bin`, or `make clean_test` to remove build artifacts and test outputs.

## Coding Patterns & Conventions
- Each TAD (e.g., Socio, Libro, Prestamo) is split into a header (`include/*.h`) and implementation (`src/*.cpp`).
- TADs use opaque pointers for encapsulation (e.g., `struct rep_socio; typedef rep_socio* TSocio;`).
- Functions for accessing private fields (e.g., `diaTFecha`, `mesTFecha`, `anioTFecha`) must be implemented in the module where the struct is defined (not in other modules).
- Memory management is explicit; freeing resources (e.g., `liberarTFecha`) is required after copying or creating objects.
- Test cases are named and organized by feature and scenario (see `Makefile` variables `IDS_PUBLICOS`, `CASOS`).

## Integration Points
- No external libraries are used except for standard C++ and Valgrind (for testing).
- All module interactions are via function calls and shared headers; no dynamic linking or IPC.

## Example: Adding a Field to a TAD
1. Update the struct in the corresponding `src/*.cpp` file.
2. Add accessor/mutator functions in the same module.
3. Update the header in `include/*.h`.
4. Update related test cases in `test/`.

## Key Files
- `Makefile` — authoritative for build/test/clean commands and test case naming
- `src/` and `include/` — all core logic, one TAD per file pair
- `test/` — input/output for regression tests

---
If any section is unclear or missing details, please provide feedback or specify which workflow or pattern needs more explanation.
