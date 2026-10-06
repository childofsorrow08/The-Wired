#!/usr/bin/env bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
SHELL_NIX="$PROJECT_ROOT/shell.nix"

exec nix-shell "$SHELL_NIX" --run

cd "$PROJECT_ROOT/src"
make all
