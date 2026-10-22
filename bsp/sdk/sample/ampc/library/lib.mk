mod := $(notdir $(subdir))

ampc-$(CONFIG_LIBMETAL) += libmetal
PHONY += libmetal libmetal-clean libmetal-distclean
PHONY += libmetal-install libmetal-uninstall
libmetal:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) all

libmetal-clean:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) clean

libmetal-distclean:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) distclean

libmetal-install:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) install

libmetal-uninstall:
	$(MAKE) -C $(LIBMETAL_BUILD_PATH) uninstall

ampc-$(CONFIG_LIBAMPC) += libopen_amp
PHONY += libopen_amp libopen_amp-clean libopen_amp-distclean
PHONY += libopen_amp-install libopen_amp-uninstall
libopen_amp:
	$(MAKE) -C $(LIBOPENAMP_BUILD_PATH) all

libopen_amp-clean:
	$(MAKE) -C $(LIBOPENAMP_BUILD_PATH) clean

libopen_amp-distclean:
	$(MAKE) -C $(LIBOPENAMP_BUILD_PATH) distclean

libopen_amp-install:
	$(MAKE) -C $(LIBOPENAMP_BUILD_PATH) install

libopen_amp-uninstall:
	$(MAKE) -C $(LIBOPENAMP_BUILD_PATH) uninstall

ampc-$(CONFIG_LIBAMPC) += libampc
PHONY += libampc libampc-clean libampc-distclean
PHONY += libampc-install libampc-uninstall
libampc:
	$(MAKE) -C $(LIBAMPC_BUILD_PATH) all

libampc-clean:
	$(MAKE) -C $(LIBAMPC_BUILD_PATH) clean

libampc-distclean:
	$(MAKE) -C $(LIBAMPC_BUILD_PATH) distclean

libampc-install:
	$(MAKE) -C $(LIBAMPC_BUILD_PATH) install

libampc-uninstall:
	$(MAKE) -C $(LIBAMPC_BUILD_PATH) uninstall


PHONY += $(mod) $(mod)-clean $(mod)-distclean
PHONY += $(mod)-install $(mod)-uninstall
$(mod): $(ampc-y)
$(mod)-clean: $(addsuffix -clean,$(ampc-y))
$(mod)-distclean: $(addsuffix -distclean,$(ampc-y))
$(mod)-install: $(addsuffix -install,$(ampc-y))
$(mod)-uninstall: $(addsuffix -uninstall,$(ampc-y))

AMPC_BUILD_DEPS += $(mod)
AMPC_CLEAN_DEPS += $(mod)-clean
AMPC_DISTCLEAN_DEPS += $(mod)-distclean
AMPC_INTALL_DEPS += $(mod)-install
AMPC_UNINTALL_DEPS += $(mod)-uninstall
