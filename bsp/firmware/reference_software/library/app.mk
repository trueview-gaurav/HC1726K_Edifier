mod := $(notdir $(subdir))

app-$(CONFIG_FOO) += libfoo
PHONY += libfoo libfoo-clean libfoo-distclean
PHONY += libfoo-install libfoo-uninstall
libfoo:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build all

libfoo-clean:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build clean

libfoo-distclean:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build distclean

libfoo-install:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build install

libfoo-uninstall:
	$(Q)$(MAKE) -C $(LIBFOO_PATH)/build uninstall

app-$(CONFIG_LIBGPIO) += libgpio
PHONY += libgpio libgpio-clean libgpio-distclean
PHONY += libgpio-install libgpio-uninstall
libgpio:
	$(Q)$(MAKE) -C $(LIBGPIO_PATH) all

libgpio-clean:
	$(Q)$(MAKE) -C $(LIBGPIO_PATH) clean

libgpio-distclean:
	$(Q)$(MAKE) -C $(LIBGPIO_PATH) distclean

libgpio-install:
	$(Q)$(MAKE) -C $(LIBGPIO_PATH) install

libgpio-uninstall:
	$(Q)$(MAKE) -C $(LIBGPIO_PATH) uninstall

app-$(CONFIG_LIBUTILS) += libutils
PHONY += libutils libutils-clean libutils-distclean
PHONY += libutils-install libutils-uninstall
libutils:
	$(Q)$(MAKE) -C $(LIBUTILS_PATH)/build all

libutils-clean:
	$(Q)$(MAKE) -C $(LIBUTILS_PATH)/build clean

libutils-distclean:
	$(Q)$(MAKE) -C $(LIBUTILS_PATH)/build clean

libutils-install:
	$(Q)$(MAKE) -C $(LIBUTILS_PATH)/build install

libutils-uninstall:
	$(Q)$(MAKE) -C $(LIBUTILS_PATH)/build uninstall

PHONY += libpwm libpwm-clean libpwm-distclean
PHONY += libpwm-install libpwm-uninstall
app-$(CONFIG_LIBPWM) += libpwm
libpwm:
	$(Q)$(MAKE) -C $(LIBPWM_PATH) all

libpwm-clean:
	$(Q)$(MAKE) -C $(LIBPWM_PATH) clean

libpwm-distclean:
	$(Q)$(MAKE) -C $(LIBPWM_PATH) distclean

libpwm-install:
	$(Q)$(MAKE) -C $(LIBPWM_PATH) install

libpwm-uninstall:
	$(Q)$(MAKE) -C $(LIBPWM_PATH) uninstall

app-$(CONFIG_LIBSQL) += libsql
PHONY += libsql libsql-clean libsql-distclean
PHONY += libsql-install libsql-uninstall
libsql:
	$(Q)$(MAKE) -C $(LIBSQL_PATH) all

libsql-clean:
	$(Q)$(MAKE) -C $(LIBSQL_PATH) clean

libsql-distclean:
	$(Q)$(MAKE) -C $(LIBSQL_PATH) distclean

libsql-install:
	$(Q)$(MAKE) -C $(LIBSQL_PATH) install

libsql-uninstall:
	$(Q)$(MAKE) -C $(LIBSQL_PATH) uninstall

app-$(CONFIG_LIBTZ) += libtz
PHONY += libtz libtz-clean libtz-distclean
PHONY += libtz-install libtz-uninstall
libtz:
	$(Q)$(MAKE) -C $(LIBTZ_PATH) all

libtz-clean:
	$(Q)$(MAKE) -C $(LIBTZ_PATH) clean

libtz-distclean:
	$(Q)$(MAKE) -C $(LIBTZ_PATH) distclean

libtz-install:
	$(Q)$(MAKE) -C $(LIBTZ_PATH) install

libtz-uninstall:
	$(Q)$(MAKE) -C $(LIBTZ_PATH) uninstall

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
