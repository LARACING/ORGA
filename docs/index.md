# Organisation

This repository defines the development foundation of the project.  
It serves as a central reference for coding standards, documentation practices,
and workflow conventions that ensure consistency and quality across all contributions.

Its purpose is to align engineering practices, reduce ambiguity, and provide a
shared understanding of how software is developed, documented, and maintained.

---

## Structure of This Repository

The repository is organized into three main sections:

### C Coding Guidelines  

[Open C Coding Guidelines](./c/docs/home.md)

Defines mandatory rules and best practices for all C source code, including:

- File and project structure  
- Header and source separation  
- API declaration principles  
- Naming conventions and formatting  
- Error handling patterns  
- Testing expectations  
- Tooling and build requirements  

The goal is predictable, readable, and production-ready embedded code.

---

### Git Documentation  

[Open Git Documentation](./git/home.md)

Describes how version control is used in this project, including:

- Repository access and authentication  
- Branching strategy and naming conventions  
- Pull request workflow  
- Review and integration process  
- Quality gates and recovery procedures  

The goal is a clean history, stable integration, and reproducible development workflows.

---

### Writing Formal Documentation  

[Open Writing Guidelines](./writing/home.md)

Provides guidance for writing structured and verifiable embedded requirements and C API documentation, including:

- Functional and non-functional requirements  
- Hardware interface specifications  
- API documentation principles  
- Verification strategies  
- Normative wording conventions  

The goal is clear, measurable, and testable documentation.

---

## Overall Objective

This repository promotes:

- Consistent engineering standards  
- Clear and traceable requirements  
- High-quality, maintainable code  
- Structured documentation  
- Controlled and predictable development processes  

All contributors are expected to follow the guidelines defined in the respective sections to ensure technical consistency and long-term project stability.

## About

The documentation is built with [**zensical**](https://zensical.org/) and uses [**uv**](https://docs.astral.sh/uv/) for
reproducible dependency management and environment handling.

If your question is not addressed in this repository, please reach out
via Telegram or email.

------------------------------------------------------------------------

## Building the Documentation

### Prerequisites

- Python ≥ 3.12 installed
- `uv` installed (<https://docs.astral.sh/uv/>)

> You can install `uv` system-wide or inside a virtual environment if
> preferred.

------------------------------------------------------------------------

## Install Dependencies

From the repository root:

``` bash
uv sync
```

This creates a local virtual environment and installs all dependencies
defined in `pyproject.toml` and locked in `uv.lock`.

------------------------------------------------------------------------

## Development Server

Start the live development server:

``` bash
uv run dev
```

The documentation will be served locally (default:
`http://localhost:9000`).

------------------------------------------------------------------------

## Build Static Site

To generate the static documentation site:

``` bash
uv run build
```

The generated output will be placed in `./site`

------------------------------------------------------------------------

## Clean Reinstall

If the environment becomes inconsistent:

``` bash
uv sync --reinstall
```

This fully recreates the environment from the lockfile.

------------------------------------------------------------------------

## Notes

- Do **not** manually activate `.venv`
- Do **not** use `pip`
- Do **not** modify `uv.lock` manually
- Commit both `pyproject.toml` and `uv.lock` to ensure reproducibility

The setup is fully deterministic and CI-friendly.
