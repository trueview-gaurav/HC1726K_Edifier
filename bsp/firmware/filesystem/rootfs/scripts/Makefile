SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)
include $(SDKSRC_DIR)/firmware/build/build_utils/lib.mk
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

DEST := $(TARGET_INIT_SCRIPTS_DIR)

chip_type := $(call chip,$(CONFIG_CHIP))
wifi_init_script=S40wifi
fastboot_video_script=fastboot_video

# SDK developer binary package build
# Install listed product-specific init scripts
.PHONY: install
install: config-check wifi-install fstab-install fastboot-install aov-install
	$(Q)rm -rf $(DEST)
	$(Q)mkdir -p $(DEST)
	$(Q)$(SCRIPTS_PATH)/tool/script_installer \
		-l $(SCRIPTS_PATH)/$(chip_type)/$(CONFIG_MACH).list \
		-i $(SCRIPTS_PATH)/source \
		-o $(DEST)

.PHONY: fastboot-install
fastboot-install:
ifneq ($(wildcard $(SCRIPTS_PATH)/source/fastboot/fastboot_$(CONFIG_MACH)),)
	$(Q)cp -f $(SCRIPTS_PATH)/source/fastboot/fastboot_$(CONFIG_MACH) \
		$(SYSROOT_DBG)/etc/$(fastboot_video_script)
endif

.PHONY: wifi-install
wifi-install:
ifneq ($(wildcard $(SCRIPTS_PATH)/source/wifi/wifi-$(CONFIG_MACH)),)
	$(Q)cp -f $(SCRIPTS_PATH)/source/wifi/wifi-$(CONFIG_MACH) \
		$(SCRIPTS_PATH)/source/$(wifi_init_script)
endif

.PHONY: fstab-install
fstab-install:
ifneq ($(wildcard $(SCRIPTS_PATH)/source/fstab/fstab_$(CONFIG_MACH)),)
	$(Q)cp -f $(SCRIPTS_PATH)/source/fstab/fstab_$(CONFIG_MACH) \
		$(SYSROOT_DBG)/etc/fstab
endif

.PHONY: aov-install
aov-install:
ifneq ($(wildcard $(SCRIPTS_PATH)/source/aov/aov_$(CONFIG_MACH)),)
	$(Q)cp -f $(SCRIPTS_PATH)/source/aov/aov_$(CONFIG_MACH) \
		$(SYSROOT_DBG)/etc/aov
endif

.PHONY: clean
clean:
	$(Q)rm -rf $(DEST)/*
	$(Q)rm -f $(SCRIPTS_PATH)/source/$(wifi_init_script)

.PHONY: config-check
config-check:
	$(Q)[ $(CONFIG_MACH) ] || \
		(echo "Error: Target machine is not specified!" && exit 1)
