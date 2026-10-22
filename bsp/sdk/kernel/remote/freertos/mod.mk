SDKSRC_DIR ?= $(realpath $(CURDIR)/../..)
-include $(SDKSRC_DIR)/remote/.config

mod_fr := $(notdir $(subdir))

FREERTOS_BUILD_PATH = $(FREERTOS_PATH)/Demo/HC1703_1723_1753_1783S_GCC

FREERTOS_DEPS = libampc libmetal libopen_amp
ifeq ($(CONFIG_LIBNCNN),y)
FREERTOS_DEPS += libncnn
endif

ifeq ($(CONFIG_LIBROSA),y)
FREERTOS_DEPS += librosa
endif

ifeq ($(CONFIG_LIBTFLITE_MICRO),y)
FREERTOS_DEPS += libtflite_micro
endif

mod_fr-$(CONFIG_FREERTOS) := freertos_aug
PHONY += freertos_aug freertos_aug-clean freertos_aug-distclean
PHONY += freertos_aug-install freertos_aug-uninstall

freertos_aug: $(FREERTOS_DEPS)
	$(Q)$(MAKE) -C $(FREERTOS_BUILD_PATH) all

freertos_aug-clean:
	$(Q)$(MAKE) -C $(FREERTOS_BUILD_PATH) clean

freertos_aug-distclean:
	$(Q)$(MAKE) -C $(FREERTOS_BUILD_PATH) distclean

freertos_aug-install:
	$(Q)$(MAKE) -C $(FREERTOS_BUILD_PATH) install

freertos_aug-uninstall:
	$(Q)$(MAKE) -C $(FREERTOS_BUILD_PATH) uninstall


PHONY += $(mod_fr) $(mod_fr)-clean $(mod_fr)-distclean
PHONY += $(mod_fr)-install $(mod_fr)-uninstall

$(mod_fr): $(mod_fr-y)
$(mod_fr)-clean: $(addsuffix -clean,$(mod_fr-y))
$(mod_fr)-distclean: $(addsuffix -distclean,$(mod_fr-y))
$(mod_fr)-install: $(addsuffix -install,$(mod_fr-y))
$(mod_fr)-uninstall: $(addsuffix -uninstall,$(mod_fr-y))

REMOTE_BUILD_DEPS += $(mod_fr)
REMOTE_CLEAN_DEPS += $(mod_fr)-clean
REMOTE_DISTCLEAN_DEPS += $(mod_fr)-distclean
REMOTE_INSTALL_DEPS += $(mod_fr)-install
REMOTE_UNINSTALL_DEPS += $(mod_fr)-uninstall

