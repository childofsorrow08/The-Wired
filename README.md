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

> Note:
> If you want to test this kernel, you can do this [online here](https://childofsorrow08.github.io/The-Wired/)!

## Dependencies

### Default dependencies

- GCC and GNU Assembler (AS)
- Makefiles

> Note:
> Please, use [cross-compilers](docs/BUILDING.md#4-cross-development-tools).

### ISO image dependencies

- Grub
- Xorriso

### Testing dependencies

- QEMU

> Note:
> If you want to use `runiso` target to test kernel, you also need ISO image dependencies

## Build process

```bash
git clone https://github.com/childofsorrow08/The-Wired
cd The-Wired
make build ARCH=*
```

> Note:
> Instead of * specify arch you want. For example, ARCH=X32 or ARCH=X64. Also you can see [full list of compile options here](docs/BUILDING.md#2-build-options).
> Instead of `build`, you can specify another target you need. You can see [all targets here](docs/BUILDING.md#1-makefile-targets).
> Also, if you're using NixOS or Nix package manager, [you can use the script to build in the nix-shell](docs/BUILDING.md#3-nix-package-manager).

# Release Roadmap

I’d also like to share my plans for each release, starting with version 0.4 and ending with version 1.0. These are just plans, not estimated release dates, since I don’t set deadlines for myself and work at my own pace.

| Version | Plan | Already done? |
| :---: | :--- | :---: |
| 0.4 | Basic support for keyboard input, for the subsequent creation of a basic shell. | ✅ |
| 0.5 | A basic shell capable of performing minimal functions, temporarily embedded in the kernel | ✅ |
| 0.6 | Basic file system operations, functions for creating and searching for files for testing purposes | ➖ |
| 0.7 | The ability to run binary applications separately from the kernel | ➖ |
| 0.8 | An API for interacting with the kernel, so that programs do not access kernel functions or low-level hardware directly, perhaps a minimal libc, perhaps expanding the number of kernel functions so that most of libc's functionality is available, and adding a directory where the header files required by the system will be copied | ➖ |
| 0.9 | Creating several minimal shell commands that are separate from the kernel, and teaching the shell to look for them in the correct directories | ➖ |
| 1.0 | Cosmetic code improvements, adding more useful comments, a final review of the documentation and project guidelines, refactoring poorly written sections of code, and celebrating the project’s first full-fledged release. | ➖ |

# Docs

## For developers

- [CONTRIBUTING.md](docs/CONTRIBUTING.md)

## User-related

- [BUILDING.md](docs/BUILDING.md)

## Other

- [THANKS.md](docs/THANKS.md)
