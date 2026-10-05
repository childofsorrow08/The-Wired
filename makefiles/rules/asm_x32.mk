$(X32_OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(dir $@)
	@$(AS32) $(ASFLAGS_32) $< -o $@
