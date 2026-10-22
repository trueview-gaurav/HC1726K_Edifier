mod_bm := $(notdir $(subdir))

BAREMETAL_BUILD_PATH = $(REMOTE_PATH)/baremetal

mod_bm-$(CONFIG_BAREMETAL_CM0_CM4) := baremetal_aug

PHONY += baremetal_aug baremetal_aug-clean baremetal_aug-distclean
PHONY += baremetal_aug-install baremetal_aug-uninstall

baremetal_aug:
	@echo "Building baremetal firmware..."
	$(Q)$(MAKE) -C $(BAREMETAL_BUILD_PATH) all

baremetal_aug-clean:
	@echo "Cleaning baremetal firmware..."
	$(Q)$(MAKE) -C $(BAREMETAL_BUILD_PATH) clean

baremetal_aug-distclean:
	@echo "Dist-cleaning baremetal firmware..."
	$(Q)$(MAKE) -C $(BAREMETAL_BUILD_PATH) clean

baremetal_aug-install:
	@echo "Installing baremetal firmware..."
	@if [ -f "$(BAREMETAL_BUILD_PATH)/output/baremetal.bin" ]; then \
		mkdir -p $(BINPKG_DIR); \
		cp $(BAREMETAL_BUILD_PATH)/output/baremetal.bin $(BINPKG_DIR)/; \
		echo "Baremetal firmware installed to $(BINPKG_DIR)/baremetal.bin"; \
	else \
		echo "Warning: baremetal.bin not found at $(BAREMETAL_BUILD_PATH)/output/baremetal.bin"; \
	fi

baremetal_aug-uninstall:
	@echo "Uninstalling baremetal firmware..."
	$(Q)rm -f $(BINPKG_DIR)/baremetal.bin

PHONY += $(mod_bm) $(mod_bm)-clean $(mod_bm)-distclean
PHONY += $(mod_bm)-install $(mod_bm)-uninstall
$(mod_bm): $(mod_bm-y)
$(mod_bm)-clean: $(addsuffix -clean,$(mod_bm-y))
$(mod_bm)-distclean: $(addsuffix -distclean,$(mod_bm-y))
$(mod_bm)-install: $(addsuffix -install,$(mod_bm-y))
$(mod_bm)-uninstall: $(addsuffix -uninstall,$(mod_bm-y))

REMOTE_BUILD_DEPS += $(mod_bm)
REMOTE_CLEAN_DEPS += $(mod_bm)-clean
REMOTE_DISTCLEAN_DEPS += $(mod_bm)-distclean
REMOTE_INSTALL_DEPS += $(mod_bm)-install
REMOTE_UNINSTALL_DEPS += $(mod_bm)-uninstall