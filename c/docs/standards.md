# General

## Table of Contents

- [General](#general)
  - [Table of Contents](#table-of-contents)
  - [C Standard](#c-standard)
  - [Project Structure](#project-structure)
    - [Folder Structure](#folder-structure)
    - [Config Files](#config-files)
    - [Notes](#notes)

## C Standard

- **Standard:** `C99`
- **Compatibility:** [ANSI-C](https://www.geeksforgeeks.org/c/ansi-c-c89-standard/)
- **Compiler Flags:** [See Compiler](./tooling_and_compiler.md#compiler-and-flags)

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
| ------ | ---------- |
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
