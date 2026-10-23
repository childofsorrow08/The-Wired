$(ELF): $(OBJS) $(LD_SCRIPT)
	@mkdir -p $(dir $@)
	@echo "[LD] Linking $(ARCH) kernel..."
	@$(CC) $(LDFLAGS) -o $@ $(OBJS)
