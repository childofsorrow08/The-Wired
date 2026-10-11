ifeq ($(ARCH),X32)

build: $(X32_ELF)
	@echo "[INFO] x32 kernel built: $(X32_ELF)"

endif
