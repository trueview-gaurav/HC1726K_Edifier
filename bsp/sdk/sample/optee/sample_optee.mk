PHONY :=

root := $(SAMPLE_OPTEE_PATH)

subdir := $(root)/optee_client
-include $(subdir)/optee_client.mk

subdir := $(root)/optee_examples
-include $(subdir)/optee_examples.mk

subdir := $(root)/monotonic_counter
-include $(subdir)/monotonic_counter.mk

subdir := $(root)/efuse
-include $(subdir)/efuse.mk

subdir := $(root)/se_sim
-include $(subdir)/se_sim.mk

subdir := $(root)/tee_trng
-include $(subdir)/tee_trng.mk

PHONY += sample-optee-check
sample-optee-check:
ifeq ("$(wildcard $(KCONFIG_CONFIG))","")
	$(error Core sample config not found)
endif

PHONY += sample-optee sample-optee-clean sample-optee-distclean sample-optee-install sample-optee-uninstall
sample-optee: sample-optee-check $(SAMPLE_OPTEE_BUILD_DEPS)

sample-optee-clean: $(SAMPLE_OPTEE_CLEAN_DEPS)
	$(Q)find . -type f \( -name '*.sig' -o -name '*.dig' \) -delete
	@echo 'Removed all signature (*.sig) and digest (*.dig) files.'

sample-optee-distclean: $(SAMPLE_OPTEE_DISTCLEAN_DEPS)
	$(Q)rm -f $(KCONFIG_CONFIG)
	$(Q)rm -f $(KCONFIG_CONFIG).old
	@echo 'Core sample config `$(notdir $(KCONFIG_CONFIG))` has been removed.'
	$(Q)find . -type f \( -name '*.sig' -o -name '*.dig' \) -delete
	@echo 'Removed all signature (*.sig) and digest (*.dig) files.'

sample-optee-install: $(SAMPLE_OPTEE_INTALL_DEPS)

sample-optee-uninstall: $(SAMPLE_OPTEE_UNINTALL_DEPS)

.PHONY: $(PHONY)
