## Tooling and Compiler

## Table of Contents
- [Tooling and Compiler](#tooling-and-compiler)
- [Table of Contents](#table-of-contents)
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
- [Doxygen](#doxygen)
  - [Purpose](#purpose)
  - [Doxyfile Configuration](#doxyfile-configuration)
  - [Doxywizard](#doxywizard)
  - [Writing Doxygen Comments](#writing-doxygen-comments)
    - [File Header Example](#file-header-example)
    - [Function Documentation Example](#function-documentation-example)
    - [Struct Example](#struct-example)
  - [Generating Documentation](#generating-documentation)
    - [Using Terminal](#using-terminal)
  - [Summary](#summary)

## Tooling

### Core

| Tool | Purpose |
|------|----------|
| **gcc** | GNU Compiler Collection — compiles C source code into executables. |
| **make** | Automates builds and handles dependency tracking and incremental compilation. |
| **clang-format** | Formats all C source files according to a consistent style guide. |
| **gdb** | GNU Debugger — allows step-through debugging, breakpoints, and variable inspection. |

### Testing

| Tool | Purpose |
|------|----------|
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
**gcovr** reads `.gcno` and `.gcda` files created during compilation and execution, and then generates detailed reports in multiple formats, such as **HTML**, **XML**, or **text summaries**.

Example usage:

```bash
gcovr -r . --html --html-details -o coverage.html
```

These reports can be automatically published via **GitHub Pages**, ensuring easy access to coverage metrics for every commit or pull request.

> An example pipeline for automated testing and coverage generation is provided at: [tests/.github/actions/on_push.yaml](./example/.github/actions/on_push.yaml)

## Make

**Make** is a build automation tool used to compile and manage projects efficiently.  
It reads a file called a **Makefile**, which defines _targets_, _dependencies_, and _commands_ that describe how to build or clean project files.

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
|--------|----------|
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

In short, **Make** simplifies project building, testing, and maintenance by automating compilation and linking based on file changes.

## Doxygen

**Doxygen** is a documentation generation tool for **C**, **C++**, and other languages.  
It parses source code and specially formatted comments to create structured documentation in **HTML**, **LaTeX**, or **man** formats.

Doxygen helps maintain **up-to-date technical documentation** directly alongside your codebase, ensuring consistency between implementation and documentation.

---

### Purpose

In this project, Doxygen is used to:

- Automatically generate documentation for functions, structs, and macros from annotated comments.  
- Create browsable **HTML** documentation for developers.  
- Visualize dependencies and call relationships.  
- Enforce a unified documentation style across the team.  
- Integrate documentation generation into CI/CD pipelines.

---

### Doxyfile Configuration

Doxygen is controlled through a configuration file named `Doxyfile`, located in the project root.

To create a new one (if not already present), run:

```bash
doxygen -g
```

Then edit the generated file to match the project’s layout.  
A minimal configuration might look like this:

```bash
PROJECT_NAME           = "LaEracing C Project"
OUTPUT_DIRECTORY       = docs/doxygen
INPUT                  = src include
RECURSIVE              = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES
GENERATE_HTML          = YES
GENERATE_LATEX         = NO
WARN_IF_UNDOCUMENTED   = YES
```

This setup will generate HTML documentation under `docs/doxygen/`.

---

### Doxywizard

**Doxywizard** is a graphical interface for Doxygen that allows editing and running documentation generation without manually modifying the `Doxyfile`.  
It is installed alongside Doxygen and provides an intuitive way to configure and visualize output.  
You can find official Doxywizard documentation here:  
👉 [https://www.doxygen.nl/manual/doxywizard_usage.html](https://www.doxygen.nl/manual/doxywizard_usage.html)

---

### Writing Doxygen Comments

Doxygen supports several comment styles.  
Common patterns include:

#### File Header Example

```c
/**
 * @file motor_controller.c
 * @brief Implements motor control logic and safety mechanisms.
 * @date 2025-11-09
 * @version 1.0
 */
```

#### Function Documentation Example

```c
/**
 * @brief Initializes the motor controller.
 *
 * Sets up PWM channels and performs a self-check.
 *
 * @param[in] config Pointer to the configuration structure.
 * @return `0` on success, non-zero error code otherwise.
 */
int motor_init(const MotorConfig* config);
```

#### Struct Example

```c
/**
 * @struct MotorConfig
 * @brief Holds configuration parameters for the motor controller.
 */
typedef struct MotorConfig{
    int max_speed;
    int min_speed;
} MotorConfig;
```

---

### Generating Documentation

You can generate documentation either from the terminal or via Doxywizard.

#### Using Terminal

```bash
doxygen Doxyfile
```

Output will be located at:

```bash
docs/doxygen/html/index.html
```

---

### Summary

- **Doxygen** converts annotated code comments into readable documentation.  
- **Doxywizard** provides a GUI for easier configuration and generation.  
- Documentation is generated under `docs/doxygen/` and can be published automatically via **GitHub Pages** or **CI/CD**.
