# BUILDING.md
> [Return to README.md](../README.md)

## 1. Makefile targets
This project has different Make targets for various tasks; you can see a list of them below:

- Build targets:
	1) **`all`** - Uses all targets that build binaries
	2) **`build`** - It simply builds kernel with the `.elf` extension
	3) **`iso`** - It uses the `build` target, then packages the result into an ISO file with GRUB pre-installed

- GitHub Actions targets:
	1) `webkernel` - It uses the `iso` target to build x32 kernel with preinstalled grub, then copies the result to the folder required for the website
	2) `release` - It uses the `all` target, then copies all the generated binaries to a separate folder and names them according to their role so that the `.yml` script can simply load all the binaries and create a release draft on GitHub

## 2. Build options
To make it possible to compile the kernel as flexibly as possible, various compilation options will be added on an ongoing basis to help you manage the build process conveniently:
- `ARCH=*` - Specifies the architecture for which the kernel should be compiled. Possible values: `X32`, `X64`

## 3. Nix package manager
You can use the `scripts/nix_build.sh` script to compile everything within the Nix package manager environment, which automatically installs all dependencies. However, if you want to compile the project using non-standard options, you'll have to edit the script manually. You can find `shell.nix` here, if needed: `scripts/assets/shell.nix`.

## 4. Cross development tools
Standard tools will usually work, but it is recommended that you install cross-dev tools. If, for some reason, you are unable to do so using your package manager, you can use this scripts located in the `scripts` directory at the root of the project:
- `scripts/crossdev-tools-i686.sh`
- `scripts/crossdev-tools-x86_64.sh`
This script installs and unpacks everything you need, and the build system is able to automatically detect the tools installed using these scripts.
