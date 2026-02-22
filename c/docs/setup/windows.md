# Windows

## Table of Contents

- [Windows](#windows)
  - [Table of Contents](#table-of-contents)
  - [MSYS](#msys)
    - [Installing MSYS](#installing-msys)
    - [Adding to PATH](#adding-to-path)
    - [Installing the Tooling](#installing-the-tooling)
  - [WSL (Windows Subsystem for Linux)](#wsl-windows-subsystem-for-linux)

For **gcovr** to work, you have to have installed **Python** on your system. To see the installation process, please refer to [requirements.md](../python/requirements.md).

## MSYS

### Installing MSYS

If you do not have **MSYS** installed yet, download it from [msys2.org](https://www.msys2.org/).  
After installation, you will have several bash environments available. You can use those directly, but we recommend **adding the environment to your PATH**, so you can run `gcc`, `make`, or `pacman` directly from your regular **Windows Terminal** or **PowerShell**.

We use the **`UCRT64`** environment because it works best with **Windows 10 and newer**, thanks to Microsoft’s modern **Universal C Runtime (UCRT)** toolchain.  
This environment offers better compatibility, stability, and Unicode support than the older **MSVCRT**-based ones.

---

### Adding to PATH

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

### Installing the Tooling

Once **MSYS2** is installed, you’ll need to install the essential build tools.  
In an **MSYS2 UCRT64** terminal or your normal terminal if added to PATH, run:

```bash
pacman -S --needed --noconfirm mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-clang-tools-extra mingw-w64-ucrt-x86_64-clang
```

---

## WSL (Windows Subsystem for Linux)

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
