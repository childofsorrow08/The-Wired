# Thanks to lordmilko for this possibility

set -e
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$ROOT_DIR/build"
TOOLCHAIN_DIR="$BUILD_DIR/x86_64-elf-tools"

mkdir -p "$TOOLCHAIN_DIR"
curl -L -o "$TOOLCHAIN_DIR/tools.zip" https://github.com/lordmilko/i686-elf-tools/releases/latest/download/x86_64-elf-tools-linux.zip
unzip -q "$TOOLCHAIN_DIR/tools.zip" -d "$TOOLCHAIN_DIR"
rm -f "$TOOLCHAIN_DIR/tools.zip"
