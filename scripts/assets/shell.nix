{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
	# Testing
    qemu

	# Build tools
    gnumake

	# Other tools
    grub2
    xorriso
    mtools

	# Compilers
    pkgsCross.i686-embedded.buildPackages.gcc
    pkgsCross.x86_64-embedded.buildPackages.gcc
    pkgsCross.i686-embedded.buildPackages.binutils
    pkgsCross.x86_64-embedded.buildPackages.binutils
  ];
}
