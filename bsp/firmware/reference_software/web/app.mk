mod := $(notdir $(subdir))

app-$(CONFIG_APP_WEBCGI) += webcgi
PHONY += webcgi webcgi-clean webcgi-distclean
PHONY += webcgi-install webcgi-uninstall
webcgi:
	$(Q)$(MAKE) -C $(WEBCGI_PATH) all

webcgi-clean:
	$(Q)$(MAKE) -C $(WEBCGI_PATH) clean

webcgi-distclean:
	$(Q)$(MAKE) -C $(WEBCGI_PATH) distclean

webcgi-install:
	$(Q)$(MAKE) -C $(WEBCGI_PATH) install

webcgi-uninstall:
	$(Q)$(MAKE) -C $(WEBCGI_PATH) uninstall

PHONY += $(mod) $(mod)-clean $(mod)-distclean
PHONY += $(mod)-install $(mod)-uninstall
$(mod): $(app-y)
$(mod)-clean: $(addsuffix -clean,$(app-y))
$(mod)-distclean: $(addsuffix -distclean,$(app-y))
$(mod)-install: $(addsuffix -install,$(app-y))
$(mod)-uninstall: $(addsuffix -uninstall,$(app-y))

APP_BUILD_DEPS += $(mod)
APP_CLEAN_DEPS += $(mod)-clean
APP_DISTCLEAN_DEPS += $(mod)-distclean
APP_INTALL_DEPS += $(mod)-install
APP_UNINTALL_DEPS += $(mod)-uninstall
