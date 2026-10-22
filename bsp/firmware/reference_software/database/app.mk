mod := $(notdir $(subdir))

app-$(CONFIG_APP_CENTCTRL) += centctrl
PHONY += centctrl centctrl-clean centctrl-distclean
PHONY += centctrl-install centctrl-uninstall
centctrl: libsql
	$(Q)$(MAKE) -C $(CENTCTRL_PATH) all

centctrl-clean: libsql-clean
	$(Q)$(MAKE) -C $(CENTCTRL_PATH) clean

centctrl-distclean: libsql-distclean
	$(Q)$(MAKE) -C $(CENTCTRL_PATH) distclean

centctrl-install: libsql-install
	$(Q)$(MAKE) -C $(CENTCTRL_PATH) install

centctrl-uninstall: libsql-uninstall
	$(Q)$(MAKE) -C $(CENTCTRL_PATH) uninstall

app-$(CONFIG_APP_DBMONITOR) += dbmonitor
PHONY += dbmonitor dbmonitor-clean dbmonitor-distclean
PHONY += dbmonitor-install dbmonitor-uninstall
dbmonitor:
	$(Q)$(MAKE) -C $(DBMONITOR_PATH) all

dbmonitor-clean:
	$(Q)$(MAKE) -C $(DBMONITOR_PATH) clean

dbmonitor-distclean:
	$(Q)$(MAKE) -C $(DBMONITOR_PATH) distclean

dbmonitor-install:
	$(Q)$(MAKE) -C $(DBMONITOR_PATH) install

dbmonitor-uninstall:
	$(Q)$(MAKE) -C $(DBMONITOR_PATH) uninstall

app-$(CONFIG_APP_SQLAPP) += sqlapp
PHONY += sqlapp sqlapp-clean sqlapp-distclean
PHONY += sqlapp-install sqlapp-uninstall
sqlapp: libsql
	@echo - Building sql app
	$(Q)$(MAKE) -C $(SQLAPP_PATH) all

sqlapp-clean: libsql-clean
	$(Q)$(MAKE) -C $(SQLAPP_PATH) clean

sqlapp-distclean: libsql-distclean
	$(Q)$(MAKE) -C $(SQLAPP_PATH) distclean

sqlapp-install: libsql-install
	$(Q)$(MAKE) -C $(SQLAPP_PATH) install

sqlapp-uninstall: libsql-uninstall
	$(Q)$(MAKE) -C $(SQLAPP_PATH) uninstall

app-y += case_config
PHONY += case_config case_config-clean case_config-distclean
PHONY += case_config-install case_config-uninstall

case_config:
	@echo - Building case_config
	$(Q)$(MAKE) -C $(CASE_CONFIG_PATH) all

case_config-install:
	$(Q)$(MAKE) -C $(CASE_CONFIG_PATH) install

case_config-uninstall:
	$(Q)$(MAKE) -C $(CASE_CONFIG_PATH) uninstall

case_config-clean:
	$(Q)$(MAKE) -C $(CASE_CONFIG_PATH) clean

case_config-distclean:
	$(Q)$(MAKE) -C $(CASE_CONFIG_PATH) distclean

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
