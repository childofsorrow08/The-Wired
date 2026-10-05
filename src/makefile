# Copyright (C) 2026 Child of Sorrow
#
# This file is part of TheWired kernel.
# TheWired kernel is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

SRC_DIR := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
include $(SRC_DIR)/../makefiles/directories.mk
include $(MAKECFG_DIR)/sources.mk
include $(MAKECFG_DIR)/toolchain.mk
include $(MAKECFG_DIR)/flags.mk
include $(MAKECFG_DIR)/rules.mk
include $(MAKECFG_DIR)/prerequisites.mk
include $(MAKECFG_DIR)/targets.mk

# Ignore this, only needed for GitHub Actions
include $(ROOT_DIR)/.github/pages.mk
