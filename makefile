# Copyright (C) 2026 Child of Sorrow
#
# This file is part of TheWired kernel.
# TheWired kernel is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

ROOT_DIR := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
include $(ROOT_DIR)/makefiles/directories.mk
include $(MAKECFG_DIR)/prerequisites.mk

include $(MAKECFG_DIR)/sources.mk
include $(MAKECFG_DIR)/toolchain.mk
include $(MAKECFG_DIR)/flags.mk
include $(MAKECFG_DIR)/rules.mk
include $(MAKECFG_DIR)/build_info.mk

.DEFAULT_GOAL := iso
include $(MAKECFG_DIR)/targets/build.mk
include $(MAKECFG_DIR)/targets/clean.mk
include $(MAKECFG_DIR)/targets/iso.mk
include $(MAKECFG_DIR)/targets/run.mk
all: build iso

# Ignore this, only needed for GitHub Actions
include $(MAKECFG_DIR)/actions/build.mk
include $(MAKECFG_DIR)/actions/clean.mk
