SDKSRC_DIR ?= $(realpath $(CURDIR)/../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

.DEFAULT_GOAL := default

MAKE := make

CROSS_COMPILE := $(CROSS_COMPILE_2)
BIN := tee.bin

.PHONY: default
default: all

KCONFIG_CONFIG ?= $(OPTEE_PATH)/.config
export KCONFIG_CONFIG
include kconfig.mk

-include $(KCONFIG_CONFIG)

# REE TA list
ifeq ("$(CONFIG_REE_TA_AVB)","y")
REE_TA_LIST += avb
endif
ifeq ("$(CONFIG_REE_TA_REMOTEPROC)","y")
REE_TA_LIST += remoteproc
endif
ifeq ("$(CONFIG_REE_TA_PKCS11)","y")
REE_TA_LIST += pkcs11
endif
ifeq ("$(CONFIG_REE_TA_TRUSTED_KEY)","y")
REE_TA_LIST += trusted_keys
endif
$(info REE_TA_LIST = $(REE_TA_LIST))

# EARLY TA list
ifeq ("$(CONFIG_EARLY_TA_AVB)","y")
EARLY_TA_LIST += avb
endif
ifeq ("$(CONFIG_EARLY_TA_REMOTEPROC)","y")
EARLY_TA_LIST += remoteproc
endif
ifeq ("$(CONFIG_EARLY_TA_PKCS11)","y")
EARLY_TA_LIST += pkcs11
endif
ifeq ("$(CONFIG_EARLY_TA_TRUSTED_KEY)","y")
EARLY_TA_LIST += trusted_keys
endif
$(info EARLY_TA_LIST = $(EARLY_TA_LIST))

# Assets files
ASSETS_PATH := $(OPTEE_PATH)/assets
ASSETS := $(wildcard $(ASSETS_PATH)/*)
ASSETS_FILES := $(notdir $(wildcard $(ASSETS_PATH)/*))
INSTALL_ASSETS_PATH := $(SYSROOT)/etc/ssl/
INSTALLED_ASSETS_FILES := $(patsubst %, $(INSTALL_ASSETS_PATH)%, $(ASSETS_FILES))

ETA_FILES := $(wildcard $(OPTEE_PATH)/early_ta/*)

.PHONY: optee optee-prepare optee-clean optee-install optee-uninstall optee-ta-install optee-ta-uninstall optee-distclean 

ifeq ($(CONFIG_OPTEE), y)
CFG_CUSTOM_SETTING := $(shell \
  grep -E '^CONFIG_.*=' .config | \
  sed 's/^CONFIG_/CFG_/g' \
)
CFG_CUSTOM_SETTING += $(shell \
  grep -E '^\# CONFIG_.* is not set' .config | \
  sed -e 's/^\# CONFIG_/CFG_/; s/ is not set/=n/' \
)

optee:
	$(MAKE) -C $(OPTEE_PATH)/src CROSS_COMPILE_core=$(CROSS_COMPILE) \
	CROSS_COMPILE_ta_arm32=$(CROSS_COMPILE) PLATFORM=augentix O=$(OPTEE_PATH)/output \
	EARLY_TA_PATHS="$(ETA_FILES)" $(CFG_CUSTOM_SETTING) \
	CFG_PROTECTED_BLOCK_NUM=$(PROTECTED_BLOCK_NUM) CFG_NUMBER_OF_CNTS=$(NUMBER_OF_CNTS)

optee-prepare:
	$(Q)$(MAKE) -C $(OPTEE_PATH)/src CROSS_COMPILE_core=$(CROSS_COMPILE) \
	CROSS_COMPILE_ta_arm32=$(CROSS_COMPILE) PLATFORM=augentix \
	O=$(OPTEE_PATH)/output ta_dev_kit \
	$(CFG_CUSTOM_SETTING)
	@mkdir -p $(OPTEE_PATH)/early_ta
	@for ta in $(EARLY_TA_LIST); do \
		cp $(OPTEE_PATH)/output/ta/$$ta/*.stripped.elf $(OPTEE_PATH)/early_ta/ || exit 1; \
	done

optee-clean:
	$(Q)rm -rf $(OPTEE_PATH)/output
	$(Q)rm -rf $(OPTEE_PATH)/early_ta

optee-install:
	@tail -c +29 $(OPTEE_PATH)/output/core/$(BIN) > $(OPTEE_PATH)/output/core/$(BIN).no_header
	$(Q)$(SECURE_UTILS)/optee_os_sign.sh $(OPTEE_PATH)/output/core/$(BIN).no_header $(OPTEE_PATH)/output/core/$(BIN).sig $(CUSTOM_UBOOT_KEY)
	$(Q)$(SECURE_UTILS)/verify_sign.sh SHA256 $(OPTEE_PATH)/output/core/$(BIN).no_header $(OPTEE_PATH)/output/core/$(BIN).sig $(UBOOT_PUB_KEY)
	$(Q)$(SECURE_UTILS)/convert_img_size.sh $(OPTEE_PATH)/output/core/$(BIN).no_header $(OPTEE_PATH)/output/core/$(BIN).size
	@cat $(OPTEE_PATH)/output/core/$(BIN).sig $(OPTEE_PATH)/output/core/$(BIN).size $(OPTEE_PATH)/output/core/$(BIN).no_header > $(BINPKG_DIR)/$(BIN)

optee-uninstall:
	@echo $(CONFIG_OPTEE)
	@rm -f $(BINPKG_DIR)/$(BIN)

optee-ta-install:
	@mkdir -p $(SYSROOT_DBG)/lib/optee_armtz
	@for ta in $(REE_TA_LIST); do \
		cp $(OPTEE_PATH)/output/ta/$$ta/*.ta $(SYSROOT_DBG)/lib/optee_armtz || exit 1; \
	done
ifeq ("$(CONFIG_EARLY_TA_PKCS11)$(CONFIG_REE_TA_PKCS11)","y")
	cp -r $(ASSETS) $(INSTALLED_ASSETS_FILES)
endif

optee-ta-uninstall:
	@rm -rf $(SYSROOT_DBG)/lib/optee_armtz
ifeq ("$(CONFIG_EARLY_TA_PKCS11)$(CONFIG_REE_TA_PKCS11)","y")
	rm -rf $(INSTALLED_ASSETS_FILES)
endif
else
optee:
optee-prepare:
optee-clean:
optee-install:
optee-uninstall:
optee-ta-install:
optee-ta-uninstall:
endif

optee-distclean: optee-clean
	$(Q)rm -rf $(KCONFIG_CONFIG)
	$(Q)rm -rf $(KCONFIG_CONFIG).old
	@echo 'Remote config `$(notdir $(KCONFIG_CONFIG))` has been removed.'

.PHONY: all clean distclean install uninstall distclean
all: optee
clean: optee-clean
install: optee-install optee-ta-install
uninstall: optee-uninstall optee-ta-uninstall

# To avoid any implicit rule to kick in, define an empty command
$(KCONFIG_CONFIG): ;

.PHONY: help
help:
	@echo 'Cleaning targets:'
	@echo '  clean                  - delete all files created by build'
	@echo '  distclean              - delete all non-source files (including .config)'
	@echo ''
	@echo 'Configuration targets:'
	@echo '  config                 - Update current config utilising a line-oriented program'
	@echo '  nconfig                - Update current config utilising a ncurses menu based'
	@echo '                           program'
	@echo '  menuconfig             - Update current config utilising a menu based program'
	@echo '  oldconfig              - Update current config utilising a provided .config as base'
	@echo '  defconfig              - New config with default defconfig'
	@echo '  <%_defconfig>          - New config with specified defconfig'
	@echo '  savedefconfig          - Save current config as default defconfig'
	@echo '  savedefconfig DEFCONFIG=<path_to_target_defconfig>'
	@echo '                         - Save current config as specified defconfig'
	@echo ''
	@echo 'Generic targets:'
	@echo '  all                    - build specified modules depending on configuration'
	@echo '  install                - install modules to rootfs'
	@echo '  uninstall              - uninstall modules to rootfs'
	@echo '  defconfig-list         - list all defconfigs'
	@echo ''
	@echo '  make V=0|1 [targets]   - 0 => quiet build (default), 1 => verbose build'
	@echo ''
	@echo 'Execute "make" or "make all" to build all targets marked with [*]'
