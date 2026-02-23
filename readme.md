# Organisation

This repository contains coding guidelines, installation documentation,
and example projects.

The documentation is built with [**Zensical**](https://zensical.org/) and uses [**uv**](https://docs.astral.sh/uv/) for
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
