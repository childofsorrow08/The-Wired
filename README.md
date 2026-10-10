# The Wired

Developed as a hobby, as well as an opportunity to learn low-level programming and understand how everything works at the low level - **TheWired kernel**.

A monolithic kernel that will contain everything necessary for a minimal operating system. I’m not promising much, but I’ll keep adding features as long as I can and want to.

# How to build:
> Note: If you want to test this kernel, you can do this online [here](https://childofsorrow08.github.io/The-Wired/)!

## Dependencies:

### Default dependencies:
- GCC and AS compilers
- Makefiles
> Note: Standard compilers will usually work, but it is recommended that you install cross-compilers. If, for some reason, you are unable to do so using your package manager, you can use the scripts located in the `scripts` directory at the root of the project

### ISO image dependencies:
- Grub
- Xorriso

### Testing dependencies:
- QEMU
> Note: If you want to use `runiso32` target to test kernel, you also need ISO image dependencies

## Build process:

1) Clone the repository and navigate to the project directory:
```bash
git clone https://github.com/childofsorrow08/The-Wired
cd The-Wired
```

2. Run Make:
```bash
cd src
make all
```

> Note: Instead of `all`, you can specify the target you need. You can see all targets [here](docs/BUILDING.md#1-makefile-targets).

> Note: Also, if you're using NixOS or Nix package manager, [you can use the script to build in the nix-shell](docs/BUILDING.md#2-nix-package-manager).

# Docs:

## For developers:
- [CONTRIBUTING.md](docs/CONTRIBUTING.md)

## User-related:
- [BUILDING.md](docs/BUILDING.md)

## Other:
- [THANKS.md](docs/THANKS.md)
