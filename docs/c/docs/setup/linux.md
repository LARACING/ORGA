
# Linux

All major Linux distributions already include **GCC** and **Make** in their repositories.

## Debian/Ubuntu

```bash
sudo apt update
sudo apt install build-essential git -y
```

## Fedora/RHEL

```bash
sudo dnf install gcc make git
```

## Arch Linux

```bash
sudo pacman -S base-devel git
```

After installation, confirm everything works:

```bash
gcc --version
make --version
```
