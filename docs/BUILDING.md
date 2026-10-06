# BUILDING.md
> [Return to README.md](../README.md)

## 1. Makefile targets
This project has different Make targets for various tasks; you can see a list of them below:

- Build targets:
	1) `all` - Uses all targets that build binaries
	2) `x32` - It simply builds a 32-bit version of the kernel with the `.elf` extension
	3) `iso32` - It uses the `x32` target, then packages the result into an ISO file with GRUB pre-installed

- GitHub Actions targets:
	1) `webkernel` - It uses the `iso32` target, then copies the result to the folder required for the website
	2) `release` - It uses the `all` target, then copies all the generated binaries to a separate folder and names them according to their role so that the `.yml` script can simply load all the binaries and create a release draft on GitHub

## 2. Nix package manager
1) You can use the `scripts/nix_build.sh` script to compile everything within the Nix package manager environment, which automatically installs all dependencies. However, if you want to compile the project using non-standard options, you'll have to edit the script manually.
