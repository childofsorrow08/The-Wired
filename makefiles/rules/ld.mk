ifeq ($(ARCH),X32)

$(X32_ELF): $(OBJS) $(LD_SCRIPT)
	@mkdir -p $(dir $@)
	@echo "[LD] Linking 32-bit kernel..."
	@$(CC32) $(LDFLAGS_32) -o $@ $(OBJS)

endif
