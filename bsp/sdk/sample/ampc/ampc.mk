PHONY :=

root := $(AMPC_PATH)

subdir := $(root)/library
-include $(subdir)/lib.mk


PHONY += ampc-check
ampc-check:
ifeq ("$(wildcard $(KCONFIG_CONFIG))","")
	$(error Core sample config not found)
endif

PHONY += ampc ampc-clean ampc-distclean ampc-install ampc-uninstall
ampc: ampc-check $(AMPC_BUILD_DEPS)

ampc-clean: $(AMPC_CLEAN_DEPS)

ampc-distclean: $(AMPC_DISTCLEAN_DEPS)
	$(Q)rm -f $(KCONFIG_CONFIG)
	$(Q)rm -f $(KCONFIG_CONFIG).old
	$(Q)rm -rf $(AMPC_LIB)
	@echo 'AMPC config `$(notdir $(KCONFIG_CONFIG))` has been removed.'

ampc-install: $(AMPC_INTALL_DEPS)

ampc-uninstall: $(AMPC_UNINTALL_DEPS)

.PHONY: $(PHONY)
