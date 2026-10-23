submodules:
	git -C "$(ROOT_DIR)" submodule update --init --recursive --remote

	@mkdir -p $(CUR_BIN_DIR)/bin

    # Shell
	$(MAKE) -C "$(ROOT_DIR)/submodules/shell"
	@cp "$(ROOT_DIR)/submodules/shell/build/$(ARCH)/bin/shell.elf" \
		"$(CUR_BIN_DIR)/bin/shell.elf"

