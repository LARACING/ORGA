# MacOS

## Table of Contents

- [MacOS](#macos)
  - [Table of Contents](#table-of-contents)
  - [Installing brew](#installing-brew)
  - [Installing tools](#installing-tools)

## Installing brew

```sh
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

- Follow post-install actions (add brew to path etc.)

## Installing tools

```sh
brew install gcc gdb
brew install clang-format
brew install doxygen
brew install make cmake
```

After installation, confirm everything works:

```bash
gcc --version
make --version
```
