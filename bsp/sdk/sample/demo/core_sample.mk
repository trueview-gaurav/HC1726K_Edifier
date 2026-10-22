PHONY :=

root := $(SAMPLE_DEMO_PATH)

subdir := $(root)/ai
-include $(subdir)/ai.mk

subdir := $(root)/audio
-include $(subdir)/audio.mk

subdir := $(root)/display
-include $(subdir)/display.mk

subdir := $(root)/utils
-include $(subdir)/utils.mk

subdir := $(root)/video
-include $(subdir)/video.mk

PHONY += sample-demo-check
sample-demo-check:
ifeq ("$(wildcard $(KCONFIG_CONFIG))","")
	$(error Core sample config not found)
endif

PHONY += sample-demo sample-demo-clean sample-demo-distclean sample-demo-install sample-demo-uninstall
sample-demo: sample-demo-check $(SAMPLE_DEMO_BUILD_DEPS)

sample-demo-clean: $(SAMPLE_DEMO_CLEAN_DEPS)

sample-demo-distclean: $(SAMPLE_DEMO_DISTCLEAN_DEPS)
	$(Q)rm -f $(KCONFIG_CONFIG)
	$(Q)rm -f $(KCONFIG_CONFIG).old
	$(Q)rm -rf $(SAMPLE_DEMO_LIB)
	$(Q)rm -rf $(root)/library
	@echo 'Core sample config `$(notdir $(KCONFIG_CONFIG))` has been removed.'

sample-demo-install: $(SAMPLE_DEMO_INTALL_DEPS)

sample-demo-uninstall: $(SAMPLE_DEMO_UNINTALL_DEPS)

.PHONY: $(PHONY)
