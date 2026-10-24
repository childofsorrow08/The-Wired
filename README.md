<!-- --------------------------------------------------- -->
<!-- Only used if you use markdownlint VS Code extension -->

<!-- markdownlint-disable no-inline-html -->
<!-- --------------------------------------------------- -->

<h1 align="center">
    THE WIRED
</h1>

**TheWired kernel** is a non-commercial hobby project created to explore low-level bare-metal programming and the inner workings of computers, with the goal of building a minimally functional operating system kernel.

## AI / Machine Learning

I do not consent to this repository, its source code, documentation,
or other contents being used as training data for generative AI or
machine-learning models.

Please do not use this project for model training, fine-tuning,
dataset construction, or similar purposes.

# How to build

> [!NOTE]
> If you want to test this kernel, you can do this [online here](https://childofsorrow08.github.io/The-Wired/)!

## Dependencies

### Default dependencies

- Linux. I don't want to bear with Windows tools
- GCC and GNU Assembler (GAS)
- Makefiles

> [!TIP]
> Please, use [cross-compilers](docs/BUILDING.md#4-cross-development-tools).

### ISO image dependencies

- Grub
- Xorriso

### Testing dependencies

- QEMU

> [!IMPORTANT]
> If you want to use `runiso` target to test kernel, you also need ISO image dependencies

## Build process

```bash
git clone https://github.com/childofsorrow08/The-Wired
cd The-Wired
make build ARCH=X32
```

> [!TIP]
> Instead of X32 specify arch you want. Also you can see [full list of compile options here](docs/BUILDING.md#2-build-options).
>
> Instead of `build`, you can specify another target you need. You can see [all targets here](docs/BUILDING.md#1-makefile-targets).
>
> Also, if you're using NixOS or Nix package manager, [you can use the script to build in the nix-shell](docs/BUILDING.md#3-nix-package-manager).

# Current state

At this stage, the kernel's functionality is already quite extensive:

- TODO

# Release Roadmap

I’d also like to share my plans for each release, starting with version 1.0 and ending with version 1.2. These are just plans, not estimated release dates, since I don’t set deadlines for myself and work at my own pace.

| Version | Plan | Already done? |
| :---: | :--- | :---: |
| 1.0 | Full rewrite in Assembly, refactoring, documentation updates | ➖ |
| 1.1 | Full X64 architecture support | ➖ |
| 1.2 | Final ABI state, huge syscalls update | ➖ |

# Docs

## For developers

- [CONTRIBUTING.md](docs/CONTRIBUTING.md)
- [SYSCALLS.md](docs/SYSCALLS.md)

## User-related

- [BUILDING.md](docs/BUILDING.md)

## Other

- [THANKS.md](docs/THANKS.md)
