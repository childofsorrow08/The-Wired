# The Wired

Developed as a hobby, as well as an opportunity to learn low-level programming and understand how everything works at the low level - **TheWired kernel**.

A monolithic kernel that will contain everything necessary for a minimal operating system. I’m not promising much, but I’ll keep adding features as long as I can and want to.

# How to build:
> Note: If you want to test this kernel, you can do this online [here](https://childofsorrow08.github.io/The-Wired/)!

## Dependencies:

### Default dependencies:
- GCC and AS compilers
- Makefiles
> Note: Please, use [cross-compilers](docs/BUILDING.md#4-cross-development-tools).

### ISO image dependencies:
- Grub
- Xorriso

### Testing dependencies:
- QEMU
> Note: If you want to use `runiso` target to test kernel, you also need ISO image dependencies

## Build process:

```bash
git clone https://github.com/childofsorrow08/The-Wired
cd The-Wired/src
make build ARCH=*
```

> Note: Instead of * specify arch you want. For example, ARCH=X32 or ARCH=X64. Also you can see full list of compile options [here](docs/BUILDING.md#2-build-options).

> Note: Instead of `build`, you can specify another target you need. You can see all targets [here](docs/BUILDING.md#1-makefile-targets).

> Note: Also, if you're using NixOS or Nix package manager, [you can use the script to build in the nix-shell](docs/BUILDING.md#3-nix-package-manager).

# Docs:

## For developers:
- [CONTRIBUTING.md](docs/CONTRIBUTING.md)

## User-related:
- [BUILDING.md](docs/BUILDING.md)

## Other:
- [THANKS.md](docs/THANKS.md)
