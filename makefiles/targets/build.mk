x32: ARCH = X32
x32: $(X32_SOURCES)
x32: $(X32_OBJS)
x32: $(X32_ELF)
	@echo "[INFO] x32 kernel built: $(X32_ELF)"
