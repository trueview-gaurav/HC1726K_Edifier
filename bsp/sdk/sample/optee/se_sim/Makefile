OUTPUT_DIR := $(CURDIR)/out
SE_SIM_SRC_DIR ?= $(CURDIR)/src

.PHONY: all
all: se-sim prepare-for-rootfs

.PHONY: clean
clean: se-sim-clean prepare-for-rootfs-clean

se-sim:
	$(MAKE) -C $(SE_SIM_SRC_DIR);

se-sim-clean:
	$(MAKE) -C $(SE_SIM_SRC_DIR) clean;

prepare-for-rootfs: se-sim
	@echo "Copying feature CA binaries to $(OUTPUT_DIR)..."
	@mkdir -p $(OUTPUT_DIR)
	@mkdir -p $(OUTPUT_DIR)/ca
	if [ -e $(SE_SIM_SRC_DIR)/host/se_sim ]; then \
		cp -p $(SE_SIM_SRC_DIR)/host/se_sim $(OUTPUT_DIR)/ca/; \
	fi;

prepare-for-rootfs-clean:
	@rm -rf $(OUTPUT_DIR)/ca
	@rmdir --ignore-fail-on-non-empty $(OUTPUT_DIR) || test ! -e $(OUTPUT_DIR)
