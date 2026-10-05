BUILD_TIME = $(shell date '+%Y-%m-%d %H:%M:%S')
CC32_VERSION = $(shell $(CC32) --version | head -n 1)
AS32_VERSION = $(shell $(AS32) --version | head -n 1)
CC64_VERSION = $(shell $(CC64) --version | head -n 1)
AS64_VERSION = $(shell $(AS64) --version | head -n 1)
ARCH ?= x86_64

METADATA_FLAGS_C := \
    -DBUILD_TIME="\"$(BUILD_TIME)\"" \
    -DCC32_VERSION="\"$(CC32_VERSION)\"" \
    -DAS32_VERSION="\"$(AS32_VERSION)\"" \
    -DCC64_VERSION="\"$(CC64_VERSION)\"" \
    -DAS64_VERSION="\"$(AS64_VERSION)\"" \
    -DARCH="\"$(ARCH)\""

info:
	@echo "Build Time: $(BUILD_TIME)"
	@echo "CC32 Version: $(CC32_VERSION)"
	@echo "AS32 Version: $(AS32_VERSION)"
	@echo "CC64 Version: $(CC64_VERSION)"
	@echo "AS64 Version: $(AS64_VERSION)"
	@echo "Architecture: $(ARCH)"
