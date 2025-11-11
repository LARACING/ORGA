# Formal C Development

## Overview

This document defines the **C toolchain**, **standards**, and **workflows** for formal development at **LaEracing**.  
This ensures consistent building, testing, formatting, and documentation across all developers and environments.

## Table of Contents

- [Formal C Development](#formal-c-development)
  - [Overview](#overview)
  - [Table of Contents](#table-of-contents)
  - [Standards and Tools](#standards-and-tools)
    - [C Standard](#c-standard)
  - [Tooling](#tooling)
    - [Core](#core)
    - [Testing](#testing)
  - [Project Structure](#project-structure)
    - [Folder Structure](#folder-structure)
    - [Config Files](#config-files)
    - [Notes](#notes)
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
  - [Installation](#installation)
  - [Windows](#windows)
    - [MSYS](#msys)
      - [Installing MSYS](#installing-msys)
      - [Adding to PATH](#adding-to-path)
      - [Installing the Tooling](#installing-the-tooling)
    - [WSL (Windows Subsystem for Linux)](#wsl-windows-subsystem-for-linux)
  - [Linux](#linux)
    - [Debian/Ubuntu](#debianubuntu)
    - [Fedora/RHEL](#fedorarhel)
    - [Arch Linux](#arch-linux)

## Standards and Tools

### C Standard

- **Standard:** `C99`
- **Compatibility:** [ANSI-C](https://www.geeksforgeeks.org/c/ansi-c-c89-standard/)
- **Compiler Flags:** [See Compiler](#compiler-and-flags)

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

## Project Structure

A typical C project will consist of multiple directories and, in our case, some configuration files.

### Folder Structure

The structure looks like this:

```bash
root/
├── src/      # All source files and private headers
├── include/  # Public headers containing the external API
├── test/     # Unit tests and test runners
├── html/     # folder for compiled docs and coverage report
├── build/    # Build artifacts and temporary files
├── example/  # Reference implementations or examples
├── docs/     # Project documentation
```

### Config Files

| File | Purpose |
|------|----------|
| **makefile** | Defines build targets, compiler flags, and project dependencies. |
| **.clang-format** | Enforces a consistent code style across all contributors. |
| **.gitignore** | Specifies which files and directories should be ignored by Git (e.g., `build/`, `.gcda`, `.o`). |
| **Doxyfile** | Configuration file for [Doxygen](https://www.doxygen.nl/) — used to generate reference documentation from source code comments. |
| **README.md** | Describes the project, setup instructions, and usage overview. |

---

### Notes

- All internal logic and private headers reside in `src/`.
- All headers that form the public API should be placed under `include/`.
- Build artifacts (object files, coverage data, binaries) should always go into `build/` and not be committed.
- `html/` should also never be committed as it is beeing built dynamically in the pipeline.
- Documentation generated from **Doxygen** will usually be placed under `docs/` and can be auto-generated using a Makefile target like `make docs`.
- Example implementations and documentation should remain in their dedicated directories for clarity and consistency.

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
typedef struct {
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

## Installation

## Windows

For **gcovr** to work, you have to have installed **Python** on your system. To see the installation process, please refer to [requirements.md](../python/requirements.md).

### MSYS

#### Installing MSYS

If you do not have **MSYS** installed yet, download it from [msys2.org](https://www.msys2.org/).  
After installation, you will have several bash environments available. You can use those directly, but we recommend **adding the environment to your PATH**, so you can run `gcc`, `make`, or `pacman` directly from your regular **Windows Terminal** or **PowerShell**.

We use the **`UCRT64`** environment because it works best with **Windows 10 and newer**, thanks to Microsoft’s modern **Universal C Runtime (UCRT)** toolchain.  
This environment offers better compatibility, stability, and Unicode support than the older **MSVCRT**-based ones.

---

#### Adding to PATH

To add the **UCRT64** environment to your PATH permanently, open an **administrator PowerShell** window and run:

```powershell
[Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\msys64\ucrt64\bin;C:\msys64\usr\bin", "Machine")
```

After that, restart PowerShell or Command Prompt, and verify that **MSYS2** is correctly available by checking `pacman`:

```bash
pacman -V
```

You should see output similar to:

```bash
Pacman v6.1.0 - libalpm v14.1.0
```

If this works, your **MSYS** environment is set up correctly.  
If not, ensure your PATH variable is correct and that **MSYS2** is installed under `C:\msys64\`.

---

#### Installing the Tooling

Once **MSYS2** is installed, you’ll need to install the essential build tools.  
In an **MSYS2 UCRT64** terminal or your normal terminal if added to PATH, run:

```bash
pacman -S --needed --noconfirm mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-clang-tools-extra mingw-w64-ucrt-x86_64-clang
```

---

### WSL (Windows Subsystem for Linux)

If you prefer a fully native Linux environment on Windows, **WSL** is a great option.

**Installation steps:**

1. Enable **WSL (Windows Subsystem for Linux)** from Windows Features or run:

   ```powershell
   wsl --install
   ```

2. Install **Ubuntu** (recommended) or another Linux distribution from the Microsoft Store.
3. Open your **WSL** terminal and install the required build tools:

   ```bash
   sudo apt update
   sudo apt install build-essential git -y
   ```

4. Verify your setup:

   ```bash
   gcc --version
   make --version
   ```

---

## Linux

All major Linux distributions already include **GCC** and **Make** in their repositories.

### Debian/Ubuntu

```bash
sudo apt update
sudo apt install build-essential git -y
```

### Fedora/RHEL

```bash
sudo dnf install gcc make git
```

### Arch Linux

```bash
sudo pacman -S base-devel git
```

After installation, confirm everything works:

```bash
gcc --version
make --version
```
