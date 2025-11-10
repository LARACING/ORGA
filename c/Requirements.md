# Formal C Developement

## Overview

This document defines the C toolchain, standards and workflows for formal Developement at LaEracing.
This ensures consistent building, testing, formatting and documentation across all developers and environments

## Table of Contents

- [Formal C Developement](#formal-c-developement)
  - [Overview](#overview)
  - [Table of Contents](#table-of-contents)
  - [Standards and Tools](#standards-and-tools)
    - [C-Standard](#c-standard)
  - [Tooling](#tooling)
    - [Core](#core)
    - [Testing](#testing)
  - [Compiler and Flags](#compiler-and-flags)
    - [Compiler](#compiler)
    - [Compiler Flags](#compiler-flags)
    - [Coverage and Testing Flags](#coverage-and-testing-flags)
  - [Testing and Coverage](#testing-and-coverage)
    - [Coverage](#coverage)
  - [Make](#make)
    - [How It Works](#how-it-works)
    - [Common Targets](#common-targets)
    - [Why Use Make](#why-use-make)
  - [Installation](#installation)
  - [Windows](#windows)
    - [MSYS](#msys)
    - [WSL](#wsl)
  - [Linux](#linux)

## Standards and Tools

### C-Standard

- **Standard** `C99`
- **Compatibility** [ANSI-C](https://www.geeksforgeeks.org/c/ansi-c-c89-standard/)
- **Compiler Flags** [See Compiler](#compiler-and-flags)

## Tooling

### Core

| Tool              | Purpose  |
|-------------------|----------|
| **gcc**           | GNU Compiler Collection — compiles C source code into executables. |
| **make**          | Automates builds and handles dependency tracking and incremental compilation. |
| **clang-format**  | Formats all C source files according to a consistent style guide. |
| **clang-tidy**    | Static analysis tool that detects potential bugs, style violations, and unsafe patterns. |
| **gdb**           | GNU Debugger — allows step-through debugging, breakpoints, and variable inspection. |

### Testing

| Tool      | Purpose |
|-----------|----------|
| **Unity** | Lightweight unit testing framework for C. Provides easy test creation and integration with Make and coverage tools. |
| **gcovr** | Collects and summarizes `gcov` output into clean console, HTML, or XML reports. |

## Compiler and Flags

### Compiler

We use **GCC** as our compiler since it is available across all major platforms and provides all the features required for this project.  
For installation and setup instructions, see the [Installation](#installation) section.

---

### Compiler Flags

To ensure consistent behavior, code quality, and compatibility, the following compiler flags are used:

| Flag | Purpose |
|------|----------|
| `-std=c99` | Enforces the C99 standard for consistent syntax and features. |
| `-pedantic` | Ensures strict adherence to the ANSI/ISO C standard. |
| `-Wall` | Enables common compiler warnings to catch potential issues. |
| `-Wextra` | Enables additional warnings for more thorough code analysis. |
| `-Werror` | Treats all warnings as errors to enforce clean builds. |

---

### Coverage and Testing Flags

For files that are subject to testing and coverage reporting, additional flags are required:

| Flag | Purpose |
|------|----------|
| `-fprofile-arcs` | Generates extra code to record execution paths for coverage analysis. |
| `-ftest-coverage` | Creates coverage data files (`.gcno`, `.gcda`) used by coverage tools. |
| `-lgcov` | Links against the **gcov** library to enable runtime profiling support. |

---

These flags ensure that builds are **standard-compliant**, **warning-free**, and **coverage-enabled** where applicable.

## Testing and Coverage

For testing, we use [Unity](https://www.throwtheswitch.org/unity) — a lightweight and portable unit testing framework designed for C projects, particularly embedded systems.  
> “ANSI-C compatible embedded software that just works.”

Unity is well-suited for this project because it:

- Requires **no external dependencies**
- Works on **bare-metal and hosted environments**
- Supports **custom test runners** and **integration with CI pipelines**

To integrate Unity into a project, simply include the following files:

- `unity.c`
- `unity.h`
- `unity_internals.h`

> An example implementation can be found in the [tests](./example) directory.

---

### Coverage

Code coverage reports are generated using the coverage data produced by **GCC** and processed with the Python tool [gcovr](https://pypi.org/project/gcovr/).  
Gcovr reads `.gcno` and `.gcda` files created during compilation and execution, and then generates detailed reports in multiple formats, such as **HTML**, **XML**, or **text summaries**.

Example usage:

```bash
gcovr -r . --html --html-details -o coverage.html
```

These reports can be automatically published via **GitHub Pages**, ensuring easy access to coverage metrics for every commit or pull request.

> An example pipeline for automated testing and coverage generation is provided at: [tests/.github/actions/on_push.yaml](./example/.github/actions/on_push.yaml)

## Make

**Make** is a build automation tool used to compile and manage projects efficiently.  
It reads a file called a **Makefile**, which defines *targets*, *dependencies*, and *commands* that describe how to build or clean project files.

---

### How It Works

A basic rule in a Makefile looks like this:

```makefile
target: dependencies
    command
```

When you run:

```bash
make target
```

Make checks if the **dependencies** have changed since the **target** was last built.  
If they have, it runs the **command** to rebuild the target.
> You will find an example `makefile` at [example/makefile](./example/makefile).

---

### Common Targets

Typical targets in C projects include:

| Target | Purpose |
|---------|----------|
| `all` | Builds the entire project. |
| `clean` | Removes all compiled files and build artifacts. |
| `test` | Builds and runs all unit tests. |
| `coverage` | Generates a code coverage report. |

Example usage:

```bash
make all      # Build the project
make clean    # Remove build artifacts
make test     # Run unit tests
make coverage # Generate coverage report
```

---

### Why Use Make

- **Automates repetitive build steps**
- **Only recompiles what changed**
- **Portable** — works across platforms with GCC or other compilers
- **Integrates easily** with CI/CD pipelines

In short, Make simplifies project building, testing, and maintenance by automating compilation and linking based on file changes.

## Installation

## Windows

### MSYS



### WSL

## Linux