PHONY :=

root := $(REMOTE_PATH)

subdir := $(root)/baremetal
-include $(subdir)/mod.mk

subdir := $(root)/freertos
-include $(subdir)/mod.mk

subdir := $(root)/library
-include $(subdir)/mod.mk

PHONY += remote-check
remote-check:
ifeq ("$(wildcard $(KCONFIG_CONFIG))","")
	$(error Remote config not found)
endif

CROSS_COMPILE=$(CROSS_COMPILE_1)

PHONY += remote remote-clean remote-distclean remote-install remote-uninstall

remote: remote-check $(REMOTE_BUILD_DEPS)

remote-clean: $(REMOTE_CLEAN_DEPS)

remote-distclean: $(REMOTE_DISTCLEAN_DEPS)
	$(Q)rm -f $(KCONFIG_CONFIG)
	$(Q)rm -f $(KCONFIG_CONFIG).old
	@echo 'Remote config `$(notdir $(KCONFIG_CONFIG))` has been removed.'

remote-install: $(REMOTE_INSTALL_DEPS)

remote-uninstall: $(REMOTE_UNINSTALL_DEPS)

.PHONY: $(PHONY)