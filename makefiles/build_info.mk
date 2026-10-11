BUILD_TIME = $(shell date '+%Y-%m-%d %H:%M:%S')

ifeq ($(ARCH),X32)
CC32_VERSION = $(shell $(CC32) --version | head -n 1)
AS32_VERSION = $(shell $(AS32) --version | head -n 1)

METADATA_FLAGS_C := \
    -DBUILD_TIME="\"$(BUILD_TIME)\"" \
    -DCC_VERSION="\"$(CC32_VERSION)\"" \
    -DAS_VERSION="\"$(AS32_VERSION)\"" \
    -DARCH="\"$(ARCH)\""

info:
	@echo "Build Time: $(BUILD_TIME)"
	@echo "CC Version: $(CC32_VERSION)"
	@echo "AS Version: $(AS32_VERSION)"

endif

ifeq ($(ARCH),X64)
CC64_VERSION = $(shell $(CC64) --version | head -n 1)
AS64_VERSION = $(shell $(AS64) --version | head -n 1)

METADATA_FLAGS_C := \
    -DBUILD_TIME="\"$(BUILD_TIME)\"" \
    -DCC_VERSION="\"$(CC64_VERSION)\"" \
    -DAS_VERSION="\"$(AS64_VERSION)\"" \
    -DARCH="\"$(ARCH)\""

info:
	@echo "Build Time: $(BUILD_TIME)"
	@echo "CC Version: $(CC64_VERSION)"
	@echo "AS Version: $(AS64_VERSION)"

endif
