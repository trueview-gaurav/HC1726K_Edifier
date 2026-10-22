SDKSRC_DIR ?= $(realpath $(CURDIR)/..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

MAKE := make
TAR := tar

TOOLCHAIN := $(CROSS_COMPILE:-=)
TOOLCHAIN_SUFFIX := $(lastword $(subst -, ,$(TOOLCHAIN)))

ifeq ($(TOOLCHAIN), arm-linux-gnueabihf)
TOOLCHAIN_NAME = gcc-linaro-4.9-2016.02-x86_64_arm-linux-gnueabihf
XTOOL_LOCAL_TARBALL := $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME).tar.xz
TAR_OPT := xJf
else ifeq ($(TOOLCHAIN), aarch64-none-linux-gnu)
TOOLCHAIN_NAME = gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu
XTOOL_LOCAL_TARBALL := $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME).tar.xz
TAR_OPT := xJf
else ifeq ($(TOOLCHAIN), arm-linux-gnueabi)
TOOLCHAIN_NAME = gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi
XTOOL_LOCAL_TARBALL := $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME).tar.xz
TAR_OPT := xJf
else ifeq ($(TOOLCHAIN), arm-augentix-linux-uclibcgnueabihf)
TOOLCHAIN_NAME = arm-augentix-linux-uclibcgnueabihf
XTOOL_LOCAL_TARBALL := $(TOOLCHAIN_PATH)/yocto-$(TOOLCHAIN_NAME).tar.xz
TAR_OPT := xJf
else ifeq ($(TOOLCHAIN), arm-augentix-linux-uclibcgnueabi)
TOOLCHAIN_NAME = arm-augentix-linux-uclibcgnueabi
XTOOL_LOCAL_TARBALL := $(TOOLCHAIN_PATH)/yocto-$(TOOLCHAIN_NAME).tar.xz
TAR_OPT := xJf
else ifeq ($(TOOLCHAIN), arm-none-eabi)
TOOLCHAIN_NAME = arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi
XTOOL_LOCAL_TARBALL := $(TOOLCHAIN_PATH)/arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.xz
TAR_OPT := xJf
endif

XTOOL_LOCAL_PATH := $(TOOLCHAIN_PATH)/$(TOOLCHAIN_NAME)

.PHONY: all
all:
	$(Q)if [ ! -d "$(XTOOL_PATH)" ] && [ ! -d "$(XTOOL_LOCAL_PATH)" ]; then \
		$(MAKE) unpack; \
	fi

.PHONY: update
update: distclean pull unpack

.PHONY: clean
clean:
	$(Q)echo "Cleaning $(TOOLCHAIN_NAME)"
	$(Q)[ -d "$(XTOOL_LOCAL_PATH)" ] && chmod a+w -R $(XTOOL_LOCAL_PATH) || :
	$(Q)rm -rf $(XTOOL_LOCAL_PATH)

.PHONY: distclean
distclean: clean

.PHONY: pull
ifneq ($(CONFIG_RELEASE), y)
pull:
	$(Q)printf "  %-8s  $(TOOLCHAIN_NAME).tgz\n" "PULL"
	$(Q)git lfs fetch
	$(Q)git lfs checkout $(TOOLCHAIN_NAME).tgz
else
pull:
endif

.PHONY: unpack
unpack:
	$(Q)printf "  %-8s  $(XTOOL_LOCAL_TARBALL)\n" "UNPACK"
	$(Q)$(TAR) $(TAR_OPT) $(XTOOL_LOCAL_TARBALL) -C $(TOOLCHAIN_PATH)
	$(Q)chmod a+w -R $(XTOOL_LOCAL_PATH) || :
	$(Q)if [ -f "$(XTOOL_LOCAL_PATH)/install.sh" ]; then \
		printf "  %-8s  %s\n" "INSTALL" "$(XTOOL_LOCAL_PATH)/install.sh"; \
		chmod +x "$(XTOOL_LOCAL_PATH)/install.sh" || :; \
		cd "$(XTOOL_LOCAL_PATH)" && ./install.sh; \
	fi

ZEPHYR_SDK_NAME = zephyr-sdk-0.17.4
ZEPHYR_SDK_TARBALL = $(TOOLCHAIN_PATH)/$(ZEPHYR_SDK_NAME)_linux-x86_64_minimal.tar.xz
ZEPHYR_SDK_PATH = $(TOOLCHAIN_PATH)/$(ZEPHYR_SDK_NAME)

.PHONY: unpack-zephyr-sdk
unpack-zephyr-sdk:
	$(Q)printf "  %-8s  $(ZEPHYR_SDK_TARBALL)\n" "UNPACK"
	$(Q)$(TAR) xJf $(ZEPHYR_SDK_TARBALL) -C $(TOOLCHAIN_PATH)
	$(Q)chmod a+w -R $(ZEPHYR_SDK_PATH) || :

.PHONY: clean-zephyr-sdk
clean-zephyr-sdk:
	$(Q)echo "Cleaning $(ZEPHYR_SDK_NAME)"
	$(Q)[ -d "$(ZEPHYR_SDK_PATH)" ] && chmod a+w -R $(ZEPHYR_SDK_PATH) || :
	$(Q)rm -rf $(ZEPHYR_SDK_PATH)
