ifeq ($(ARCH),X32)

$(X32_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC32) $(CFLAGS) $(METADATA_FLAGS_C) -c $< -o $@

endif
