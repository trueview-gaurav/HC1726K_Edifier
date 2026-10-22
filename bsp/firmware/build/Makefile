################################################################################
# Top-Level Makefile for Augentix Inc. SDK Source Package
################################################################################

SHELL := /bin/bash
MAKE := make
MAKEFLAGS += --no-print-directory

# Override THREAD_NUM and neglect CORE_NUM for customization
CORE_NUM = `cat /proc/cpuinfo | grep "processor" | wc -l`
THREAD_NUM := $$(( $(CORE_NUM) + 1 ))

.SUFFIX:

################################################################################
# Import global SDK rules
################################################################################

export SDKSRC_DIR := $(realpath $(CURDIR)/../..)
include sdksrc.mk
include versioning.mk

################################################################################
# Import Makefile rules
################################################################################

include build_utils/lib.mk
include build_utils/replace_with_link.mk

################################################################################
# Variable declarations
################################################################################

PRODUCT_RULE_DIR := rule.make/product
DEFCONFIG_LIST := $(notdir $(wildcard $(PRODUCT_RULE_DIR)/*_defconfig))

# Image names
UBOOT_NAME  = u-boot.bin
BR_NAME     = br0.bin
SPL_NAME    = u-boot-spl.bin
EMMC_NVSPC_NAME = emmc_nvspc.bin
ADV_NVSPC_NAME = adv_nvspc.bin
BOOTIMG_NAME = boot_flash.bin
UIMAGE_NAME = uImage
ZIMAGE_NAME = zImage

# Secure boot names
ifeq ($(CONFIG_SECURE_BOOT), y)
SPL_PUB_KEY_MOD = $(BINPKG_DIR)/pub_key/spl_pub_key_mod.bin
SPL_RSA = RSA-PKCS

ifeq ($(CONFIG_HC1703_1723_1753_1783S), y)
SPL_HASH_ALGO = SHA224
SPL_PUB_KEY_MOD_HEADER = $(UBOOT_SOC_DIR)/spl_pub_key_mod.h
else
SPL_HASH_ALGO = SHA256
ifeq ($(CONFIG_SAPPORO), y)
SPL_PUB_KEY_MOD_HEADER = $(UBOOT_SOC_DIR)/spl_pub_key_mod.h
endif
endif

UBOOT_PUB_KEY_MOD = $(BINPKG_DIR)/pub_key/uboot_pub_key_mod.bin
UBOOT_BR_NAME = br1.bin

FITIMAGE_NAME = fitImage
FITIMAGE_ITS = fitImage.its
VERITY_SCRIPT = verity_script

BOOTIMG_DIR = boot_flash
endif # CONFIG_SECURE_BOOT

# Increase if SPL bin size exceeds this limit
# If modifying truncate size, also update OFFSET_SPL_SIZE in spl.c of Uboot:
SPL_TRUNCATE_SIZE := $(if $(CONFIG_SECURE_BOOT),28K,22K)
SPL_TRUNCATE_PATH := $(if $(CONFIG_SECURE_BOOT),$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR),$(BINPKG_DIR)/boot)

# sysupd tool variables
SYSUPD_SW_DESC=
SYSUPD_SW_DESC_SIG=

# Version control and checking
SDKSRC_HASH := $(shell echo $(SDRSRC_DIR) | md5sum | awk '{ print $$1 }')

# SDK version
SDK_VER ?= "1.0.0"
SDK_VER_CODE = $(shell $(BUILD_UTILS_PATH)/convert_sdk_ver_code.sh $(SDK_VER)) # for anti-rollback protection checking

ifeq ($(CONFIG_OPTEE), y)
ROOTFS_VER ?= 0
TEE_VER ?= 0
export ROOTFS_VER
export TEE_VER
endif

ifeq ($(CONFIG_KERNEL_ARM64), y)
LINUX_BUILD_FLAG = ARCH=arm64 CROSS_COMPILE=$(CROSS_COMPILE_5)
UBOOT_BUILD_FLAG = ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE_5)
ARM_ARCH := arm64
IMAGE_NAME := Image
else
LINUX_BUILD_FLAG =
# v2026.07 refuses GCC below 10.0 at arch/arm/config.mk:76, and the two trees
# differ in prefix as well as version. Same switch as UBOOT_PATH, so tree and
# compiler cannot disagree. Reaches CPVS too, one line above U-Boot at :543.
ifeq ($(CONFIG_UBOOT_UPSTREAM),y)
UBOOT_BUILD_FLAG = ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE_2)
else
UBOOT_BUILD_FLAG =
endif
ARM_ARCH := arm
IMAGE_NAME := $(ZIMAGE_NAME)
endif

# The shared targets below state the compiler for the v2026.07 tree only.
# UBOOT_BUILD_FLAG is also non-empty on a CONFIG_KERNEL_ARM64 product, where
# those targets must keep their v2016.03 command line.
UBOOT_UPSTREAM_FLAG = $(if $(filter y,$(CONFIG_UBOOT_UPSTREAM)),$(UBOOT_BUILD_FLAG))

################################################################################
# Build targets start here
################################################################################

.PHONY: default
default: all

.PHONY: 0.SILENT
$(V).SILENT:

.PHONY: all
ifneq ($(CONFIG_RELEASE), y)
all: init-build
else
all: buildroot update
endif
	@echo "Make finished at `date`"

.PHONY: main-build
main-build: update

# User can specify project number by setting the value of $(SDK_VER)
# For example: $ make doc SDK_VER=jpl-r1.2.3-rc4
# If $(SDK_VER) is not set, default value will be parsed from sdk-verision.

ifeq ($(SDK_VER),"1.0.0")
doc: MANUAL_PROJECT_NUMBER =
else
doc: MANUAL_PROJECT_NUMBER = SDK_VER=$(SDK_VER)
endif

.PHONY: doc
doc: doc-clean | $(CURDIR)/doc
ifneq ($(CONFIG_RELEASE),y)
	@echo "- Generating Programming Reference Manual"
ifneq ($(MANUAL_PROJECT_NUMBER),)
	@echo "  PROJECT_NUMBER = $(SDK_VER)"
endif # ifneq ($(MANUAL_PROJECT_NUMBER),)
	@echo "- Generating MPP Programming Reference Manual"
	$(Q)$(MAKE) -C $(MPP_PATH)/build doc $(MANUAL_PROJECT_NUMBER)
	@echo "- Generating Video Feature Programming Reference Manual"
	$(Q)$(MAKE) -C $(FEATURE_VIDEO_PATH)/build doc $(MANUAL_PROJECT_NUMBER)
	@echo "- Generating Audio Feature Programming Reference Manual"
	$(Q)$(MAKE) -C $(FEATURE_AUDIO_PATH)/build doc $(MANUAL_PROJECT_NUMBER)
	@echo "- Generating zipped file"
	$(Q)tar -zcf manual.tar.gz \
		-C $(MPP_PATH)/mpi doc/libmpp_refmanual \
		-C $(FEATURE_VIDEO_PATH) doc/libvftr_refmanual \
		-C $(FEATURE_AUDIO_PATH) doc/libaftr_refmanual
else
	@true
endif # ifneq ($(CONFIG_RELEASE), y)


.PHONY: doc-clean
doc-clean:
	$(Q)rm -f manual.tar.gz

$(CURDIR)/doc:
	$(Q)mkdir $@

.PHONY: clean
clean: phase-two-clean phase-one-clean doc-clean

.PHONY: distclean
distclean: clean phase-two-distclean phase-one-distclean config-clean
	$(Q)$(MAKE) -C $(BUILD_UTILS_PATH)/scripts distclean


.PHONY: check
check: env-check defconfig-check

.PHONY: defconfig-check
defconfig-check:
ifeq ("$(wildcard .config)", "")
	$(error Product config not found)
endif

.PHONY: config-clean
config-clean:
	$(Q)rm -rf "$(UBOOT_PATH)/include/configs/augentix/generated"
	$(Q)rm -rf "$(GEN_INC)"
	$(Q)rm -f "$(ROOTFS_PATH)/fs/ubifs/rootfs_ubinize.cfg"
	$(Q)rm -f .config
	$(Q)rm -f nvsp_partiion_size.env

.PHONY: env-check
env-check:
ifeq ("$(ARCH)", "")
	$(error The ARCH environment variable is missing)
endif
ifeq ("$(CROSS_COMPILE)", "")
	$(error The CROSS_COMPILE environment variable is missing)
endif
ifneq ($(CONFIG_RELEASE), y)
ifeq ("$(XTOOL_PATH)", "")
	$(error The XTOOL_PATH environment variable is missing)
endif
endif
	@true

.PHONY: init-build
init-build: phase-one phase-two

.PHONY: prepare
prepare: buildroot rootfs-prepare kernel-modules-prepare

.PHONY: prepare-clean
prepare-clean: kernel-clean

.PHONY: prepare-distclean
prepare-distclean: kernel-distclean rootfs-distclean buildroot-distclean

.PHONY: secure-ota-prepare
secure-ota-prepare:
	@mkdir -p $(ROOTFS_OUTPUT_PATH)/target_debug/usr/share/misc
	@cp $(SYSUPD_PUB_KEY) $(ROOTFS_OUTPUT_PATH)/target_debug/usr/share/misc/sysupd_pub_key.pem

.PHONY: secure-app-prepare
secure-app-prepare:
	@mkdir -p $(ROOTFS_OUTPUT_PATH)/target_debug/usr/share/misc
	@cp $(APP_PUB_KEY) $(ROOTFS_OUTPUT_PATH)/target_debug/usr/share/misc/app_pub_key.pem

.PHONY: secure-ota
secure-ota:
	$(Q)$(SECURE_UTILS)/secure_ota_sign.sh $(SYSUPD_SW_DESC) \
		$(SYSUPD_SW_DESC_SIG) $(CUSTOM_SYSUPD_KEY)
	$(Q)$(SECURE_UTILS)/verify_sign.sh SHA256 $(SYSUPD_SW_DESC) \
		$(SYSUPD_SW_DESC_SIG) $(SYSUPD_PUB_KEY)

.PHONY: phase-one phase-one-clean phase-one-distclean
ifneq ($(CONFIG_RELEASE), y)
phase-one: check \
	prepare \
	cpvs cpvs-install \
	nrs nrs-install \
	mpp mpp-install \
	featurelib featurelib-install \
	host-utils host-utils-install \
	target-utils target-utils-install

else
phase-one: ;
endif
phase-one-clean: target-utils-clean \
	host-utils-clean \
	featurelib-uninstall featurelib-clean \
	mpp-uninstall mpp-clean \
	nrs-uninstall nrs-clean \
	cpvs-uninstall cpvs-clean \
	prepare-clean

phase-one-distclean: target-utils-clean \
	host-utils-clean \
	nrs-uninstall nrs-distclean \
	featurelib-uninstall featurelib-distclean \
	mpp-uninstall mpp-distclean \
	nrs-uninstall nrs-distclean \
	cpvs-uninstall cpvs-distclean \
	prepare-distclean

.PHONY: phase-two
ifneq ($(CONFIG_SECURE_BOOT), y)
phase-two: check release-info-install \
	optee-prepare kernel kernel-modules extdrv audio sensor \
	uboot tfa ampc sample-demo venc-setting sample-optee app optee remote \
	rootfs initramfs-pack calibfs usrdatafs package
else
phase-two: check release-info-install \
	optee-prepare kernel kernel-modules extdrv audio sensor \
	uboot ampc sample-demo venc-setting sample-optee app optee remote \
	rootfs initramfs-pack calibfs usrdatafs secure-package
endif

.PHONY: phase-two-clean
phase-two-clean: output-clean snapshot-clean \
	usrdatafs-clean calibfs-clean rootfs-clean \
	nvsprog-clean \
	dtb-uninstall remote-uninstall remote-clean \
	ampc-uninstall ampc-clean\
	sample-demo-uninstall sample-demo-clean\
	venc-setting-uninstall venc-setting-clean\
	sample-optee-uninstall sample-optee-clean\
	optee-ta-uninstall \
	app-uninstall app-clean \
	uboot-clean tfa-clean sensor-uninstall sensor-clean \
	audio-clean extdrv-clean kernel-clean \
	optee-uninstall optee-clean release-info-uninstall
	$(Q)rm -rf $(SYSTEMFS)/script

.PHONY: phase-two-distclean
phase-two-distclean: output-clean snapshot-clean \
	usrdatafs-distclean calibfs-distclean rootfs-distclean \
	nvsprog-clean \
	dtb-uninstall remote-uninstall remote-distclean \
	ampc-uninstall ampc-distclean\
	sample-demo-uninstall sample-demo-distclean\
	venc-setting-uninstall venc-setting-distclean\
	sample-optee-uninstall sample-optee-distclean\
	app-uninstall app-distclean \
	uboot-distclean tfa-distclean sensor-uninstall sensor-distclean \
	audio-distclean extdrv-clean kernel-distclean \
	optee-distclean release-info-uninstall
	$(Q)rm -rf $(SDKREL_DIR)

.PHONY: show-sdk-dir
show-sdk-dir:
	@echo "SDK source is located at $(SDKSRC_DIR)"

################################################################################
# CPVS build
################################################################################

.PHONY: cpvs
cpvs:
	@echo - Building CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j all $(UBOOT_UPSTREAM_FLAG)

.PHONY: cpvs-doc
cpvs-doc:
	@echo - Building CPVS documentation
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j doc

.PHONY: cpvs-clean
cpvs-clean:
	@echo - Clean CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j clean

.PHONY: cpvs-distclean
cpvs-distclean:
	@echo - Distclean CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j distclean

.PHONY: cpvs-install
cpvs-install:
	@echo - Installing CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j install

.PHONY: cpvs-uninstall
cpvs-uninstall:
	@echo - Uninstalling CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j uninstall

.PHONY: cpvs-update
cpvs-update: cpvs-distclean cpvs cpvs-install

################################################################################
# SDK generic build targets
################################################################################

.PHONY: update
update: check rootfs-prepare cpvs-update nrs-update \
	mpp-update featurelib-update host-utils-update \
	target-utils-update phase-two

.PHONY: update-configs
update-configs: check update-remote-conf update-app-conf update-sample-demo-conf \
	update-buildroot-conf update-kernel-conf update-uboot-conf update-ampc-conf \
	update-optee-conf update-sample-optee-conf

.PHONY: update-remote-conf
update-remote-conf:
	@echo - Override Remote configuration with $(REMOTE_CONFIG)
	$(Q)$(MAKE) -C $(REMOTE_PATH) uninstall
	$(Q)$(MAKE) -C $(REMOTE_PATH) $(REMOTE_CONFIG)

.PHONY: update-app-conf
update-app-conf:
	@echo - Override Applications configuration with $(APP_CONFIG)
	$(Q)$(MAKE) -C $(APP_PATH) uninstall
	$(Q)$(MAKE) -C $(APP_PATH) $(APP_CONFIG)

.PHONY: update-sample-demo-conf
update-sample-demo-conf:
	@echo - Override core sample configuration with $(SAMPLE_DEMO_CONFIG)
	$(Q)$(MAKE) -C $(SAMPLE_DEMO_PATH) uninstall
	$(Q)$(MAKE) -C $(SAMPLE_DEMO_PATH) $(SAMPLE_DEMO_CONFIG)

.PHONY: update-sample-optee-conf
update-sample-optee-conf:
	@echo - Override core sample optee configuration with $(SAMPLE_OPTEE_CONFIG)
	$(Q)$(MAKE) -C $(SAMPLE_OPTEE_PATH) uninstall
	$(Q)$(MAKE) -C $(SAMPLE_OPTEE_PATH) $(SAMPLE_OPTEE_CONFIG)

.PHONY: update-buildroot-conf
update-buildroot-conf:
	@echo - Override Buildroot configuration with $(BUILDROOT_DEFCONFIG)
	$(Q)$(MAKE) -C $(BUILDROOT_BUILD_PATH) $(BUILDROOT_DEFCONFIG)

.PHONY: update-kernel-conf
update-kernel-conf:
	@echo - Override Kernel configuration with $(KERNEL_CONFIG)
	$(Q)$(MAKE) -C $(KERNEL_PATH) $(KERNEL_CONFIG) $(LINUX_BUILD_FLAG)

.PHONY: update-optee-conf
update-optee-conf:
	@echo - Override optee_os configuration with $(OPTEE_CONFIG)
	$(Q)$(MAKE) -C $(OPTEE_PATH) $(OPTEE_CONFIG)

.PHONY: update-uboot-conf
update-uboot-conf:
	@echo - Override U-Boot configuration with $(UBOOT_CONFIG)
	$(Q)$(MAKE) -C $(UBOOT_PATH) $(UBOOT_CONFIG) $(UBOOT_BUILD_FLAG)
ifeq ($(CONFIG_UBOOT_UPSTREAM), y)
ifneq ($(CONFIG_NUMBER_OF_CNTS),)
# optee_os and the nvsp programmer read this from the product defconfig, so the
# SPL reads the same copy rather than a second one in the U-Boot Kconfig.
	$(Q)sed -i '/^CONFIG_NUMBER_OF_CNTS=/d' $(UBOOT_PATH)/.config
	$(Q)echo CONFIG_NUMBER_OF_CNTS=$(CONFIG_NUMBER_OF_CNTS) >> $(UBOOT_PATH)/.config
	$(Q)$(MAKE) -C $(UBOOT_PATH) olddefconfig $(UBOOT_BUILD_FLAG)
endif
endif
ifeq ($(CONFIG_UBOOT_UPSTREAM)$(CONFIG_SECURE_BOOT), yy)
# The product defconfig owns this, so no U-Boot defconfig carries a second copy.
	$(Q)sed -i '/^# CONFIG_SECURE_BOOT is not set$$/d' $(UBOOT_PATH)/.config
	$(Q)echo CONFIG_SECURE_BOOT=y >> $(UBOOT_PATH)/.config
# olddefconfig keeps a value already written, so symbols whose Kconfig default
# reads CONFIG_SECURE_BOOT must be dropped here to be resolved again.
	$(Q)sed -i '/^CONFIG_BOOTDELAY=/d' $(UBOOT_PATH)/.config
	$(Q)sed -i '/^CONFIG_SPL_MAX_SIZE=/d' $(UBOOT_PATH)/.config
	$(Q)$(MAKE) -C $(UBOOT_PATH) olddefconfig $(UBOOT_BUILD_FLAG)
endif

.PHONY: update-ampc-conf
update-ampc-conf:
	@echo - Override AMPC configuration with $(AMPC_CONFIG)
	$(Q)$(MAKE) -C $(AMPC_PATH) uninstall
	$(Q)$(MAKE) -C $(AMPC_PATH) $(AMPC_CONFIG)

.PHONY: update-with-conf
update-with-conf: update-configs buildroot update

.PHONY: update-without-conf
update-without-conf: update

.PHONY: toolchain
toolchain:
	$(Q)$(MAKE) -C $(TOOLCHAIN_PATH) all

.PHONY: toolchain-update
toolchain-update:
	$(Q)$(MAKE) -C $(TOOLCHAIN_PATH) update

.PHONY: toolchain-clean
toolchain-clean:
	$(Q)$(MAKE) -C $(TOOLCHAIN_PATH) clean

.PHONY: toolchain-distclean
toolchain-distclean:
	$(Q)$(MAKE) -C $(TOOLCHAIN_PATH) distclean

.PHONY: bootimg
bootimg: uboot-install tfa-install
	@echo - Building boot image
ifeq ($(CONFIG_TFA), y)
	@cat $(BINPKG_DIR)/boot/$(BR_NAME) $(BINPKG_DIR)/boot/bl2.bin > $(BINPKG_DIR)/$(BOOTIMG_NAME)
else
	@cat $(BINPKG_DIR)/boot/$(BR_NAME) $(BINPKG_DIR)/boot/$(SPL_NAME) $(BINPKG_DIR)/boot/$(UBOOT_NAME) > $(BINPKG_DIR)/$(BOOTIMG_NAME)
endif
	@rm -rf $(BINPKG_DIR)/boot

.PHONY: bootimg-clean
bootimg-clean:
	@rm -rf $(BINPKG_DIR)/boot $(BINPKG_DIR)/$(BOOTIMG_NAME)

.PHONY: buildroot
buildroot:
	$(Q)$(MAKE) -C $(BUILDROOT_BUILD_PATH) build

.PHONY: buildroot-clean
buildroot-clean:
	$(Q)$(MAKE) -C $(BUILDROOT_BUILD_PATH) clean

.PHONY: buildroot-distclean
buildroot-distclean:
	$(Q)$(MAKE) -C $(BUILDROOT_BUILD_PATH) distclean

ifeq ($(CONFIG_SECURE_BOOT), y)
.PHONY: secure-fitimage-prepare
secure-fitimage-prepare:
	$(Q)$(SECURE_DTC) -O dtb $(UBOOT_DTS_KEY).dts -o $(UBOOT_DTS_KEY).dtb
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s tools $(UBOOT_UPSTREAM_FLAG)
endif

.PHONY: pinctrl
pinctrl:
	ln -sf product/$(PINCTRL_HEADER) $(UBOOT_SOC_DIR)/pinctrl-machine.h

ifeq ($(CONFIG_SECURE_BOOT), y)
.PHONY: secure-gen-pub-key-mod
secure-gen-pub-key-mod:
	@mkdir -p $(BINPKG_DIR)/pub_key
	@echo - Generate SPL public key modulus
	$(Q)$(SECURE_UTILS)/gen_pub_key_mod.sh $(SPL_PUB_KEY) $(SPL_PUB_KEY_MOD)
	@echo - Generate Uboot public key modulus
	$(Q)$(SECURE_UTILS)/gen_pub_key_mod.sh $(UBOOT_PUB_KEY) $(UBOOT_PUB_KEY_MOD)
endif

.PHONY: tfa
ifeq ($(CONFIG_TFA), y)
tfa:
	$(Q)$(MAKE) -C $(TFA_PATH) PLAT=osaka BL33=$(UBOOT_PATH)/u-boot.bin CROSS_COMPILE=$(CROSS_COMPILE_5) bl2 bl31 fip
else
tfa:
endif

.PHONY: uboot
ifeq ($(CONFIG_SECURE_BOOT), y)
uboot: pinctrl secure-gen-pub-key-mod secure-fitimage-prepare
ifeq ($(CONFIG_UBOOT_UPSTREAM), y)
	$(Q)$(MAKE) host-utils GEN_BR_ONLY=y
endif
	@echo - Create header file of UBOOT public key modulus
	@rm -rf $(SPL_PUB_KEY_MOD_HEADER)
	$(Q)$(GEN_BR) -mod $(UBOOT_PUB_KEY_MOD) $(SPL_PUB_KEY_MOD_HEADER)

# Generate dtb public key
	$(Q)LD_LIBRARY_PATH=$(BUILDROOT_HOST_LIB) $(SECURE_MKIMAGE) -f $(UBOOT_PATH)/dummy.its \
		$(UBOOT_PATH)/dummyImg 1>/dev/null
ifeq ($(CONFIG_UBOOT_UPSTREAM), y)
# EXT_DTB replaces the built-in tree, which on v2026.07 holds the board.
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s all $(UBOOT_BUILD_FLAG)
	@cp $(UBOOT_PATH)/dts/dt.dtb $(UBOOT_DTS_KEY).dtb
endif
ifneq ($(strip $(CONFIG_CUSTOM_SIGN)),)
	$(Q)PKCS11_MODULE_PATH=$(OPENSC_PKCS11_PATH) $(SECURE_UTILS)/fit_sign.sh \
		$(SECURE_MKIMAGE) $(UBOOT_DTS_KEY).dtb \
		$(UBOOT_PATH)/dummyImg $(CUSTOM_FITIMG_KEY) 1>/dev/null
else
	$(Q)LD_LIBRARY_PATH=$(BUILDROOT_HOST_LIB) $(SECURE_UTILS)/fit_sign.sh \
		$(SECURE_MKIMAGE) $(UBOOT_DTS_KEY).dtb \
		$(UBOOT_PATH)/dummyImg $(CUSTOM_FITIMG_KEY) 1>/dev/null
endif

	@echo - Building U-Boot
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s $(UBOOT_ENV_TARGET) $(UBOOT_BUILD_FLAG)
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s all EXT_DTB=$(UBOOT_DTS_KEY).dtb $(UBOOT_BUILD_FLAG)
	$(Q)truncate -s %4 $(UBOOT_PATH)/$(UBOOT_NAME)

	@rm -rf $(BINPKG_DIR)/pub_key $(UBOOT_PATH)/dummyImg
else
uboot: pinctrl
	@echo - Building U-Boot
ifneq ($(CONFIG_KERNEL_ARM64), y)
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s all $(UBOOT_BUILD_FLAG)
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s $(UBOOT_ENV_TARGET) $(UBOOT_BUILD_FLAG)
else
	# Workaround for mixed 64-bit and 32-bit toolchain SDK build (#101300)
	@echo - Cleaning CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j clean
	@echo - Building CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j all $(UBOOT_BUILD_FLAG)
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s all $(UBOOT_BUILD_FLAG)
	$(Q)$(MAKE) -C $(UBOOT_PATH) -s $(UBOOT_ENV_TARGET) $(UBOOT_BUILD_FLAG)
endif
endif

.PHONY: uboot-clean
uboot-clean:
ifeq ($(CONFIG_SECURE_BOOT), y)
	@rm -rf $(UBOOT_DTS_KEY).dtb
endif
	$(Q)$(MAKE) -C $(UBOOT_PATH) clean $(UBOOT_UPSTREAM_FLAG)

.PHONY: uboot-distclean
uboot-distclean:
	$(Q)$(MAKE) -C $(UBOOT_PATH) distclean $(UBOOT_UPSTREAM_FLAG)

.PHONY: tfa-clean
tfa-clean:
ifeq ($(CONFIG_TFA), y)
	$(Q)$(MAKE) -C $(TFA_PATH) PLAT=osaka CROSS_COMPILE=$(CROSS_COMPILE_5) clean
endif

.PHONY: tfa-distclean
tfa-distclean:
ifeq ($(CONFIG_TFA), y)
	$(Q)$(MAKE) -C $(TFA_PATH) PLAT=osaka CROSS_COMPILE=$(CROSS_COMPILE_5) distclean
endif

###############################################################################
# Linux kernel, DTB and modules
###############################################################################

.PHONY: kernel
kernel: kernel-uimage

.PHONY: kernel-clean
kernel-clean:
ifeq ($(CONFIG_INITRAMFS), y)
	@rm -rf $(KERNEL_PATH)/usr/$(ROOTFS_CPIO_FILE)
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) clean-kernel-initramfs
endif
	$(Q)$(MAKE) -C $(KERNEL_PATH) clean $(LINUX_BUILD_FLAG)

.PHONY: kernel-distclean
kernel-distclean:
	$(Q)$(MAKE) -C $(KERNEL_PATH) distclean $(LINUX_BUILD_FLAG)

CONFIG_UIMAGE_COMPRESS ?= none
ifeq ($(CONFIG_UIMAGE_COMPRESS),none)
# Add 64bytes offset in UIMAGE_LOADADDR to skip kernel image relocation
UIMAGE_ENTRY_ADDR := $(shell printf "0x%x" $(shell expr $(shell printf "%d" $(CONFIG_UIMAGE_LOADADDR) ) + 64))
else
UIMAGE_ENTRY_ADDR := $(CONFIG_UIMAGE_DECOMPRESS_ADDR)
ifeq ($(CONFIG_UIMAGE_COMPRESS),gzip)
IMAGE_NAME := Image.gz
else ifeq ($(CONFIG_UIMAGE_COMPRESS),bzip2)
IMAGE_NAME := Image.bz2
else ifeq ($(CONFIG_UIMAGE_COMPRESS),lzma)
IMAGE_NAME := Image.lzma
else ifeq ($(CONFIG_UIMAGE_COMPRESS),lzo)
IMAGE_NAME := Image.lzo
else ifeq ($(CONFIG_UIMAGE_COMPRESS),lz4)
IMAGE_NAME := Image.lz4
endif
endif
.PHONY: kernel-uimage
kernel-uimage: kernel-dtbs kernel-image
ifneq ($(CONFIG_KERNEL_ARM64), y)
	@cat $(DTS_PATH)/$(DTB_NAME) >> $(KERNEL_PATH)/arch/arm/boot/$(ZIMAGE_NAME)
endif
	@echo - Building Kernel uImage
	@mkimage -A $(ARM_ARCH) -O linux -T kernel -C $(CONFIG_UIMAGE_COMPRESS) \
                -a $(UIMAGE_ENTRY_ADDR) \
                -e $(UIMAGE_ENTRY_ADDR) \
                -n "Linux $(DTB_NAME)" \
                -d $(KERNEL_PATH)/arch/$(ARM_ARCH)/boot/$(IMAGE_NAME) \
                $(KERNEL_PATH)/arch/$(ARM_ARCH)/boot/$(UIMAGE_NAME)
	$(Q)truncate -s %4 $(KERNEL_PATH)/arch/$(ARM_ARCH)/boot/$(UIMAGE_NAME)

.PHONY: kernel-archclean
kernel-archclean:
	@echo - kernel-archclean
	$(Q)$(MAKE) -C $(KERNEL_PATH) -s -j$(THREAD_NUM) archclean $(LINUX_BUILD_FLAG)

.PHONY: kernel-image
kernel-image: kernel-archclean
ifeq ($(CONFIG_INITRAMFS), y)
# Create fake rootfs.cpio to prevent kernel build fail
# The real rootfs.cpio will be generated at initramfs-pack stage
	@touch $(KERNEL_PATH)/usr/rootfs.cpio
endif
ifneq ($(CONFIG_KERNEL_ARM64), y)
	@echo - Building Kernel zImage
	$(Q)$(MAKE) -C $(KERNEL_PATH) -s -j$(THREAD_NUM) zImage $(LINUX_BUILD_FLAG)
else
	@echo - Building Kernel Image
	$(Q)$(MAKE) -C $(KERNEL_PATH) -s -j$(THREAD_NUM) $(LINUX_BUILD_FLAG)
endif

.PHONY: kernel-dtbs
kernel-dtbs: kernel-archclean
	@echo - Building Device Tree Blob
	$(Q)$(MAKE) -C $(KERNEL_PATH) -s -j$(THREAD_NUM) dtbs $(LINUX_BUILD_FLAG)
	$(Q)truncate -s %4 $(DTS_PATH)/$(DTB_NAME)

.PHONY: kernel-modules-prepare
kernel-modules-prepare:
	$(Q)$(MAKE) -C $(KERNEL_PATH) modules_prepare $(LINUX_BUILD_FLAG)

.PHONY: kernel-modules
kernel-modules:
	@echo - Building Loadable modules
	$(Q)$(MAKE) -C $(KERNEL_PATH) -s -j$(THREAD_NUM) modules $(LINUX_BUILD_FLAG)

.PHONY: kernel-modules-install
kernel-modules-install: kernel-modules
	$(Q)$(MAKE) -C $(KERNEL_PATH) -s -j$(THREAD_NUM) \
		INSTALL_MOD_PATH=$(SYSROOT_DBG) modules_install $(LINUX_BUILD_FLAG)

###############################################################################
# optee_os
###############################################################################

SIGN_ENC ?= $(OPTEE_PATH)/src/scripts/sign_with_hsm.sh
TA_PUBLIC_KEY ?= $(OPTEE_TA_PUB_KEY)

ifneq ($(strip $(CONFIG_CUSTOM_SIGN)),)
TA_PRIVATE_KEY ?= $(CUSTOM_OPTEE_TA_KEY)
else
TA_PRIVATE_KEY ?= $(SECURE_KEY_DIR)/prvkey7.pem
endif

export SIGN_ENC
export TA_PUBLIC_KEY
export TA_PRIVATE_KEY
export CONFIG_CUSTOM_SIGN

.PHONY: optee optee-clean optee-distclean optee-install optee-uninstall \
	optee-ta-install optee-ta-uninstall optee-prepare
optee optee-clean optee-distclean optee-install optee-uninstall optee-ta-install optee-ta-uninstall optee-prepare:
	$(Q)$(MAKE) -C $(OPTEE_PATH) CFG_TEE_VERSION=$(TEE_VER) PROTECTED_BLOCK_NUM=$(CONFIG_PROTECTED_BLOCK_NUM) \
	NUMBER_OF_CNTS=$(CONFIG_NUMBER_OF_CNTS) $@

###############################################################################
# MPP
###############################################################################

.PHONY: mpp
mpp:
ifeq ($(CONFIG_KERNEL_ARM64), y)
	# Workaround for mixed 64-bit and 32-bit toolchain SDK build (#101300)
	@echo - Cleaning CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j clean
	@echo - Building CPVS and libpid
	$(Q)$(MAKE) -C $(CPVS_PATH)/build -j all
endif
	@echo - Building MPP related library
	$(Q)$(MAKE) -C $(MPP_BUILD_PATH) all

.PHONY: mpp-test
mpp-test:
	@echo - Building MPP test
	$(Q)$(MAKE) -C $(MPP_BUILD_PATH) test

.PHONY: mpp-update
mpp-update: mpp-distclean mpp mpp-install

.PHONY: mpp-clean
mpp-clean:
	@echo - Clear MPP related library
	$(Q)$(MAKE) -C $(MPP_BUILD_PATH) clean

.PHONY: mpp-install
mpp-install: mpp
	@echo - Install MPP related library
	$(Q)$(MAKE) -C $(MPP_BUILD_PATH) install

.PHONY: mpp-uninstall
mpp-uninstall:
	@echo - Uninstall MPP related library
	$(Q)$(MAKE) -C $(MPP_BUILD_PATH) uninstall

.PHONY: mpp-distclean
mpp-distclean:
	@echo - Clear MPP related library
	$(Q)$(MAKE) -C $(MPP_BUILD_PATH) distclean

.PHONY: sensor
sensor:
	@echo - Building Sensor driver/library
	$(Q)$(MAKE) -C $(SENSOR_PATH) all

.PHONY: sensor-clean
sensor-clean:
	@echo - Clear Sensor driver/library
	$(Q)$(MAKE) -C $(SENSOR_PATH) clean

.PHONY: sensor-install
sensor-install: sensor
	@echo - Install Sensor driver/library
	$(Q)$(MAKE) -C $(SENSOR_PATH) install

.PHONY: sensor-uninstall
sensor-uninstall:
	@echo - Uninstall Sensor driver/library
	$(Q)$(MAKE) -C $(SENSOR_PATH) uninstall

.PHONY: sensor-distclean
sensor-distclean: sensor-clean

###############################################################################
# Audio
###############################################################################

.PHONY: audio
audio:
	@echo - Building audio related drivers
	$(Q)$(MAKE) -C $(AUDIO_BUILD_PATH) install $(LINUX_BUILD_FLAG)

.PHONY: audio-clean
audio-clean:
	@echo - Clear audio related drivers
	$(Q)$(MAKE) -C $(AUDIO_BUILD_PATH) clean

.PHONY: audio-distclean
audio-distclean:
	@echo - Clear audio related drivers
	$(Q)$(MAKE) -C $(AUDIO_BUILD_PATH) distclean

###############################################################################
# nrs
###############################################################################
.PHONY: nrs
nrs:
	@echo - Building nrs related drivers
	$(Q)$(MAKE) -C $(NRS_DRV_BUILD) all $(LINUX_BUILD_FLAG)

.PHONY: nrs-install
nrs-install:
	@echo - Installing nrs related drivers
	$(Q)$(MAKE) -C $(NRS_DRV_BUILD) install

.PHONY: nrs-install
nrs-uninstall:
	@echo - Uninstalling nrs related drivers
	$(Q)$(MAKE) -C $(NRS_DRV_BUILD) uninstall

.PHONY: nrs-update
nrs-update:
	$(Q)$(MAKE) -C $(NRS_DRV_BUILD) update

.PHONY: nrs-clean
nrs-clean:
	@echo - Clear nrs related drivers
	$(Q)$(MAKE) -C $(NRS_DRV_BUILD) clean

.PHONY: nrs-distclean
nrs-distclean:
	@echo - Clear nrs related drivers
	$(Q)$(MAKE) -C $(NRS_DRV_BUILD) distclean

###############################################################################
# Feature libraries
###############################################################################
.PHONY: featurelib
featurelib:
	@echo - Building featurelib
	$(Q):$(foreach d, $(FEATURE_BUILD_PATHS), \
		&& $(MAKE) -C $(d) \
	)

.PHONY: featurelib-clean
featurelib-clean:
	@echo - Cleaning featurelib
	$(Q)$(foreach d, $(FEATURE_BUILD_PATHS), \
		$(MAKE) -C $(d) clean; \
	)

.PHONY: featurelib-distclean
featurelib-distclean:
	@echo - Dist-cleaning featurelib
	$(Q)$(foreach d, $(FEATURE_BUILD_PATHS), \
		$(MAKE) -C $(d) distclean; \
	)

.PHONY: featurelib-install
featurelib-install:
	@echo - Installing featurelib
	$(Q):$(foreach d, $(FEATURE_BUILD_PATHS), \
		&& $(MAKE) -C $(d) install \
	)

.PHONY: featurelib-uninstall
featurelib-uninstall:
	@echo - Uninstalling featurelib
	$(Q)$(foreach d, $(FEATURE_BUILD_PATHS), \
		$(MAKE) -C $(d) uninstall; \
	)

.PHONY: featurelib-update
featurelib-update: featurelib-clean featurelib-install

###############################################################################
# External drivers
###############################################################################

.PHONY: extdrv
extdrv:
	$(Q)$(MAKE) -C $(EXTDRV_PATH)/build all

.PHONY: extdrv-install
extdrv-install:
	$(Q)$(MAKE) -C $(EXTDRV_PATH)/build install

.PHONY: extdrv-clean
extdrv-clean:
	$(Q)$(MAKE) -C $(EXTDRV_PATH)/build clean

###############################################################################
# Host utility targets
###############################################################################

.PHONY: host-utils
host-utils:
	@echo - Building utilities for host system
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) host

.PHONY: host-utils-install
host-utils-install:
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) host-install

.PHONY: host-utils-update
host-utils-update:
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) host-update

.PHONY: host-utils-clean
host-utils-clean:
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) host-clean

###############################################################################
# Target utility targets
###############################################################################

.PHONY: target-utils
target-utils:
	@echo - Building utilities for target system
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) target

.PHONY: target-utils-install
target-utils-install:
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) target-install

.PHONY: target-utils-uninstall
target-utils-uninstall:
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) target-uninstall

.PHONY: target-utils-update
target-utils-update:
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) target-update

.PHONY: target-utils-clean
target-utils-clean:
	$(Q)$(MAKE) -C $(UTILS_BUILD_PATH) target-clean

###############################################################################
# Remote
###############################################################################

.PHONY: remote remote-install
remote remote-install:
	$(Q)$(MAKE) -C $(REMOTE_PATH) $@

.PHONY: remote-clean remote-distclean remote-uninstall
remote-clean remote-distclean remote-uninstall:
	$(Q)$(MAKE) -C $(REMOTE_PATH) $@

###############################################################################
# AMPC
###############################################################################

.PHONY: ampc ampc-install
ifeq ($(CONFIG_AMP),y)
ampc ampc-install:
	$(Q)$(MAKE) -C $(AMPC_PATH) $@
else
ampc ampc-install: ;
endif

.PHONY: ampc-clean ampc-distclean ampc-uninstall
ampc-clean ampc-distclean ampc-uninstall:
	$(Q)$(MAKE) -C $(AMPC_PATH) $@


###############################################################################
# Core Sample
###############################################################################

.PHONY: sample-demo sample-demo-clean sample-demo-distclean sample-demo-install sample-demo-uninstall
sample-demo sample-demo-clean sample-demo-distclean sample-demo-install sample-demo-uninstall:
	$(Q)$(MAKE) -C $(SAMPLE_DEMO_PATH) $@

###############################################################################
# Venc setting
###############################################################################

.PHONY: venc-setting venc-setting-clean venc-setting-distclean venc-setting-install venc-setting-uninstall
venc-setting:
	$(Q)$(MAKE) -C $(VENC_PATH)/build all
venc-setting-clean:
	$(Q)$(MAKE) -C $(VENC_PATH)/build clean
venc-setting-distclean:
	$(Q)$(MAKE) -C $(VENC_PATH)/build distclean
venc-setting-install:
	$(Q)$(MAKE) -C $(VENC_PATH)/build install
venc-setting-uninstall:
	$(Q)$(MAKE) -C $(VENC_PATH)/build uninstall

###############################################################################
# OPTEE sample
###############################################################################

.PHONY: sample-optee sample-optee-clean sample-optee-distclean sample-optee-install sample-optee-uninstall
sample-optee sample-optee-clean sample-optee-distclean sample-optee-install sample-optee-uninstall:
	$(Q)$(MAKE) -C $(SAMPLE_OPTEE_PATH) $@

###############################################################################
# Applications
###############################################################################

.PHONY: app app-clean app-distclean app-install app-uninstall
app app-clean app-distclean app-install app-uninstall:
	$(Q)$(MAKE) -C $(APP_PATH) $@

###############################################################################
# Root File System
###############################################################################

.PHONY: rootfs
rootfs: kernel-modules-install \
	extdrv-install \
	ampc-install sample-demo-install \
	sensor-install venc-setting-install \
	sample-optee-install optee-ta-install \
	app-install remote-install \
	snapshot-install secure-ota-prepare secure-app-prepare
	@echo - Building rootfs
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) all

.PHONY: rootfs-prepare
rootfs-prepare:
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) prepare

.PHONY: rootfs-clean
rootfs-clean: target-utils-uninstall target-utils-clean
	@echo - Cleaning rootfs
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) clean

.PHONY: rootfs-distclean
rootfs-distclean:
	@echo - Cleaning rootfs
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) distclean

.PHONY: rootfs-test
rootfs-test:
	@echo - Testing rootfs tools
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) test

.PHONY: collect-data collect-data-clean
collect-data: collect-data-clean
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) collect-data
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) collect-data-install

collect-data-clean:
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) collect-data-uninstall
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) collect-data-clean

###############################################################################
# User Data Filesystem
###############################################################################

.PHONY: usrdatafs
usrdatafs:
	$(Q)$(MAKE) -C $(USRDATAFS_BUILD_PATH) rebuild

.PHONY: usrdatafs-install
usrdatafs-install:
	$(Q)$(MAKE) -C $(USRDATAFS_BUILD_PATH) install

.PHONY: usrdatafs-clean
usrdatafs-clean:
	$(Q)$(MAKE) -C $(USRDATAFS_BUILD_PATH) clean

.PHONY: usrdatafs-distclean
usrdatafs-distclean:
	$(Q)$(MAKE) -C $(USRDATAFS_BUILD_PATH) distclean

###############################################################################
# Calibration Data Filesystem
###############################################################################

.PHONY: calibfs
calibfs:
	$(Q)$(MAKE) -C $(CALIBFS_BUILD_PATH) rebuild

.PHONY: calibfs-install
calibfs-install:
	$(Q)$(MAKE) -C $(CALIBFS_BUILD_PATH) install

.PHONY: calibfs-clean
calibfs-clean:
	$(Q)$(MAKE) -C $(CALIBFS_BUILD_PATH) clean

.PHONY: calibfs-distclean
calibfs-distclean:
	$(Q)$(MAKE) -C $(CALIBFS_BUILD_PATH) distclean

.PHONY: nvsprog
nvsprog: cpvs
	@echo - Building NVS programmer
	$(Q)$(MAKE) -C $(NVSP_PATH)/build all $(UBOOT_BUILD_FLAG)

.PHONY: nvsprog-install
nvsprog-install: nvsprog
	@echo - Installing NVS programmer to PKG
	$(Q)$(MAKE) -C $(NVSP_PATH)/build install $(UBOOT_BUILD_FLAG)

.PHONY: nvsprog-clean
nvsprog-clean:
	$(Q)$(MAKE) -C $(NVSP_PATH)/build clean

# now we only parse rootfs
.PHONY: nvsp_partiion_size.env
nvsp_partiion_size.env:
	python3 $(BUILD_UTILS_PATH)/ini_parser.py $(NVSP_PATH)/product/$(CONFIG_NVSP_LAYOUT) nvsp_partiion_size.env

# Check SPL file size and compare with SPL_TRUNCATE_SIZE
check-spl-size:
	@SPL_SIZE=$$(stat -c%s $(SPL_TRUNCATE_PATH)/$(SPL_NAME)); \
	SPL_TRUNCATE_SIZE_KB=$$(echo $(SPL_TRUNCATE_SIZE) | sed 's/K//'); \
	if [ -z "$$SPL_TRUNCATE_SIZE_KB" ]; then \
		echo "Error: SPL_TRUNCATE_SIZE is not set correctly"; \
		exit 1; \
	fi; \
	SPL_TRUNCATE_SIZE_BYTE=$$(awk 'BEGIN {print '$$SPL_TRUNCATE_SIZE_KB' * 1024}'); \
	echo "SPL size: $$SPL_SIZE bytes"; \
	echo "SPL_TRUNCATE_SIZE: $$SPL_TRUNCATE_SIZE_BYTE bytes"; \
	if [ $$SPL_SIZE -gt $$SPL_TRUNCATE_SIZE_BYTE ]; then \
		echo "Error: SPL size ($$SPL_SIZE bytes) exceeds SPL_TRUNCATE_SIZE ($$SPL_TRUNCATE_SIZE_BYTE bytes)"; \
		exit 1; \
	fi

# Truncate SPL file to SPL_TRUNCATE_SIZE
truncate-spl: check-spl-size
	$(Q)truncate -s $(SPL_TRUNCATE_SIZE) $(SPL_TRUNCATE_PATH)/$(SPL_NAME)

ifneq ($(CONFIG_SECURE_BOOT), y)
.PHONY: uboot-install
uboot-install:
	@echo - Copy SPL and U-boot Binaries
	@mkdir -p $(BINPKG_DIR)/boot
	@cp $(UBOOT_PATH)/spl/$(SPL_NAME) $(BINPKG_DIR)/boot/$(SPL_NAME)
	@cp $(UBOOT_PATH)/$(UBOOT_NAME) $(BINPKG_DIR)/boot/$(UBOOT_NAME)
	$(Q)$(GEN_BR) -ori $(BINPKG_DIR)/boot/$(SPL_NAME) $(BINPKG_DIR)/boot/$(BR_NAME)
	$(Q)$(MAKE) truncate-spl
ifeq ($(CONFIG_EMMC), y)
	@cp $(UBOOT_PATH)/$(EMMC_NVSPC_NAME) $(BINPKG_DIR)/$(ADV_NVSPC_NAME)
endif
else
.PHONY: secure-uboot-install
secure-uboot-install:
	@echo - Copy secure SPL and U-boot Binaries
	@mkdir -p $(BINPKG_DIR)/$(BOOTIMG_DIR)
	@cp $(UBOOT_PATH)/spl/$(SPL_NAME) $(BINPKG_DIR)/$(BOOTIMG_DIR)/$(SPL_NAME)
	@cp $(UBOOT_PATH)/$(UBOOT_NAME) $(BINPKG_DIR)/$(BOOTIMG_DIR)/$(UBOOT_NAME)
	@cp $(UBOOT_ENV_PATH)/fw_printenv $(SYSROOT)/usr/sbin/fw_printenv
endif # CONFIG_SECURE_BOOT

.PHONY: tfa-install
ifeq ($(CONFIG_TFA), y)
tfa-install:
	@echo - Copy TF-A Binaries
	@cp $(TFA_PATH)/build/osaka/release/bl2.bin $(BINPKG_DIR)/boot/bl2.bin
	@cp $(TFA_PATH)/build/osaka/release/fip.bin $(BINPKG_DIR)/fip.bin
	$(Q)$(GEN_BR) -ori $(BINPKG_DIR)/boot/bl2.bin $(BINPKG_DIR)/boot/$(BR_NAME)
else
tfa-install:
endif

.PHONY: dtb-install
ifneq ($(CONFIG_KERNEL_ARM64), y)
dtb-install: ;
else
dtb-install:
	$(Q)cp $(DTS_PATH)/$(DTB_NAME) $(BINPKG_DIR)
endif

.PHONY: dtb-uninstall
dtb-uninstall: ;

.PHONY: uimage-install
uimage-install:
	@echo - Copy uImage
	@if [ -f $(KERNEL_PATH)/arch/$(ARM_ARCH)/boot/$(UIMAGE_NAME) ]; then \
		cp $(KERNEL_PATH)/arch/$(ARM_ARCH)/boot/$(UIMAGE_NAME) \
		   $(BINPKG_DIR)/$(UIMAGE_NAME).bin; \
	else \
		echo "Error: Failed to copy uImage !";  \
		exit 1; \
	fi

ifeq ($(CONFIG_SECURE_BOOT), y)
.PHONY: zimage-install
zimage-install:
	@echo - Copy zImage
	@if [ -f $(KERNEL_PATH)/arch/arm/boot/$(ZIMAGE_NAME) ]; then \
		cp $(KERNEL_PATH)/arch/arm/boot/$(ZIMAGE_NAME) \
		   $(BINPKG_DIR)/$(ZIMAGE_NAME).bin; \
	else \
		echo "Error: Failed to copy zImage !";  \
		exit 1; \
	fi
endif

.PHONY: rfs-install
rfs-install:
	@echo - Copy Filesystem to PKG
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) install

.PHONY: rfs-padding
rfs-padding:
ifneq ($(CONFIG_SECURE_BOOT), y)
	@echo - Padding Root FileSystem
	$(Q)truncate -s %4 $(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin
endif

.PHONY: rootfs_partition_size_check
rootfs_partition_size_check: nvsp_partiion_size.env
ifneq ($(CONFIG_SECURE_BOOT), y)
	@set -e; source nvsp_partiion_size.env;\
	echo Maxium partition size is $$CHECK_ROOTFS_MAXIMUM_SIZE!;\
	echo checking file "$(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin";\
	CURRENT_ROOTFS_BIN_SIZE=$$(stat -c %s "$(BINPKG_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin");\
	if [ $$CURRENT_ROOTFS_BIN_SIZE -ge $$CHECK_ROOTFS_MAXIMUM_SIZE ]; then\
		echo "Error - CURRENT_ROOTFS_BIN_SIZE too large, current $$CURRENT_ROOTFS_BIN_SIZE", Maxium $$CHECK_ROOTFS_MAXIMUM_SIZE;\
		exit 1;\
	fi
else
	@set -e; source nvsp_partiion_size.env;\
	echo Maxium partition size is $$CHECK_ROOTFS_MAXIMUM_SIZE!;\
	echo checking file "$(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin";\
	CURRENT_ROOTFS_BIN_SIZE=$$(stat -c %s "$(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin");\
	if [ $$CURRENT_ROOTFS_BIN_SIZE -ge $$CHECK_ROOTFS_MAXIMUM_SIZE ]; then\
		echo "Error - CURRENT_ROOTFS_BIN_SIZE too large, current $$CURRENT_ROOTFS_BIN_SIZE", Maxium $$CHECK_ROOTFS_MAXIMUM_SIZE;\
		exit 1;\
	fi
endif

ifneq ($(CONFIG_SECURE_BOOT), y)
.PHONY: package
package: output-prepare bootimg \
	dtb-install uimage-install optee-install \
	nvsprog-install \
	rfs-install rfs-padding rootfs_partition_size_check usrdatafs-install calibfs-install \
	genbin check-commit debug_ver

else
.PHONY: secure-package
secure-package: output-prepare secure-uboot-install \
	dtb-install zimage-install optee-install \
	nvsprog-install \
	rfs-install rfs-padding usrdatafs-install calibfs-install \
	genbin check-commit

endif # CONFIG_SECURE_BOOT

.PHONY: initramfs-pack
ifeq ($(CONFIG_INITRAMFS), y)
# Add 64bytes offset in UIMAGE_LOADADDR to skip kernel image relocation
UIMAGE_LOADADDR := $(shell printf "0x%x" $(shell expr \
        $(shell printf "%d" $(CONFIG_UIMAGE_LOADADDR) ) + 64))
initramfs-pack:
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) kernel-initramfs
	$(Q)$(MAKE) -C $(KERNEL_PATH) -s -j$(THREAD_NUM) zImage
	@cat $(DTS_PATH)/$(DTB_NAME) >> $(KERNEL_PATH)/arch/arm/boot/$(ZIMAGE_NAME)
	@echo - Building Kernel uimage
	@mkimage -A arm -O linux -T kernel -C none \
                -a $(UIMAGE_LOADADDR) \
                -e $(UIMAGE_LOADADDR) \
                -n "Linux $(DTB_NAME)" \
                -d $(KERNEL_PATH)/arch/arm/boot/$(ZIMAGE_NAME) \
                $(KERNEL_PATH)/arch/arm/boot/$(UIMAGE_NAME)
else
initramfs-pack: ;
endif

ifeq ($(CONFIG_SECURE_BOOT), y)
.PHONY: secure-rootfs-sign
secure-rootfs-sign:
	$(Q)$(MAKE) -C $(ROOTFS_BUILD_PATH) secure-sign
	@echo - Padding Root FileSystem
	$(Q)truncate -s %4 $(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE).bin
ifneq ($(CONFIG_RELEASE), y)
	$(Q)truncate -s %4 $(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE_DBG).bin
else
	@rm -rf $(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE_DBG).bin $(BINPKG_SIGN_DIR)/$(VERITY_SCRIPT)_dbg
endif

.PHONY: fitimage-sign-verify
fitimage-sign-verify:
	@echo - Building Kernel fitimage
# Create a temporary FIT image named tmp_fit_img.
# If private key management is supported (execute 'sudo $(SECURE_MKIMAGE)'), tmp_fit_img will be owned by root.
	$(Q)LD_LIBRARY_PATH=$(BUILDROOT_HOST_LIB) $(SECURE_MKIMAGE) -f $(BINPKG_SIGN_DIR)/$(FITIMAGE_ITS) \
		$(BINPKG_SIGN_DIR)/tmp_fit_img
ifneq ($(strip $(CONFIG_CUSTOM_SIGN)),)
	$(Q)PKCS11_MODULE_PATH=$(OPENSC_PKCS11_PATH) $(SECURE_UTILS)/fit_sign.sh \
		$(SECURE_MKIMAGE) $(UBOOT_DTS_KEY).dtb \
		$(BINPKG_SIGN_DIR)/tmp_fit_img $(CUSTOM_FITIMG_KEY)
else
	$(Q)LD_LIBRARY_PATH=$(BUILDROOT_HOST_LIB) $(SECURE_UTILS)/fit_sign.sh \
		$(SECURE_MKIMAGE) $(UBOOT_DTS_KEY).dtb \
		$(BINPKG_SIGN_DIR)/tmp_fit_img $(CUSTOM_FITIMG_KEY)
endif
	$(Q)LD_LIBRARY_PATH=$(BUILDROOT_HOST_LIB) $(SECURE_UTILS)/fit_verify.sh \
		$(SECURE_FIT_CHECK_SIGN) $(BINPKG_SIGN_DIR)/tmp_fit_img \
		$(UBOOT_DTS_KEY).dtb

# Copy tmp_fit_img to create a file named $(FITIMAGE_NAME) that is not owned by root,
# to avoid truncation errors (next step) when supporting private key management.
	@cp $(BINPKG_SIGN_DIR)/tmp_fit_img $(BINPKG_SIGN_DIR)/$(FITIMAGE_NAME)_tmp.bin
# Align the FIT image to prevent checksum errors
	$(Q)truncate -s %4 $(BINPKG_SIGN_DIR)/$(FITIMAGE_NAME)_tmp.bin

.PHONY: secure-fitimage-sign
secure-fitimage-sign: secure-fitimage-prepare
	@cp $(KERNEL_PATH)/arch/arm/boot/$(FITIMAGE_ITS) $(BINPKG_SIGN_DIR)

	@mv $(BINPKG_SIGN_DIR)/$(VERITY_SCRIPT)_rel $(BINPKG_SIGN_DIR)/$(VERITY_SCRIPT)
	@$(MAKE) fitimage-sign-verify
	@mv $(BINPKG_SIGN_DIR)/$(FITIMAGE_NAME)_tmp.bin $(BINPKG_SIGN_DIR)/$(FITIMAGE_NAME).bin

ifneq ($(CONFIG_RELEASE), y)
	@mv $(BINPKG_SIGN_DIR)/$(VERITY_SCRIPT)_dbg $(BINPKG_SIGN_DIR)/$(VERITY_SCRIPT)
	@$(MAKE) fitimage-sign-verify
	@mv $(BINPKG_SIGN_DIR)/$(FITIMAGE_NAME)_tmp.bin $(BINPKG_SIGN_DIR)/$(FITIMAGE_NAME)_dbg.bin
endif

	@rm -rf $(BINPKG_SIGN_DIR)/tmp_fit_img $(BINPKG_SIGN_DIR)/$(ZIMAGE_NAME).bin
	@rm -rf $(BINPKG_SIGN_DIR)/$(VERITY_SCRIPT) $(BINPKG_SIGN_DIR)/$(FITIMAGE_ITS)

.PHONY: secure-spl-pub-key-mod-hash
secure-spl-pub-key-mod-hash: secure-gen-pub-key-mod
	@echo - Create binary of SPL public key modulus $(SPL_HASH_ALGO) hash
	@openssl dgst -$(SPL_HASH_ALGO) -r -binary $(SPL_PUB_KEY_MOD) \
		> $(BINPKG_SIGN_DIR)/pub_key_mod_hash.bin

.PHONY: secure-bootimg-sign
secure-bootimg-sign: secure-spl-pub-key-mod-hash
	@mkdir -p $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot

	# SPL sign and verify
	$(Q)$(SECURE_UTILS)/spl_sign.sh $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/$(SPL_NAME) \
		$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/spl-sign.bin\
		$(SPL_HASH_ALGO) $(SPL_RSA) \
		$(CUSTOM_SPL_KEY)
	$(Q)$(SECURE_UTILS)/verify_sign.sh $(SPL_HASH_ALGO) \
		$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/$(SPL_NAME) $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/spl-sign.bin \
		$(SPL_PUB_KEY) $(SPL_RSA)
	$(Q)$(GEN_BR) -packspl $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/$(SPL_NAME) \
		$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/$(BR_NAME) $(SPL_PUB_KEY_MOD) \
		$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/spl-sign.bin

	# Uboot sign and verify
	$(Q)$(SECURE_UTILS)/uboot_sign.sh $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/$(UBOOT_NAME) \
		$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/$(UBOOT_BR_NAME) $(CUSTOM_UBOOT_KEY)
	$(Q)$(SECURE_UTILS)/verify_sign.sh SHA256 $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/$(UBOOT_NAME) \
		$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/$(UBOOT_BR_NAME) $(UBOOT_PUB_KEY)

	$(Q)$(MAKE) truncate-spl

	@echo - Building secure boot image
	@cat $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/$(BR_NAME) $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/$(SPL_NAME) \
		$(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/boot/$(UBOOT_BR_NAME) $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR)/$(UBOOT_NAME) \
		> $(BINPKG_SIGN_DIR)/$(BOOTIMG_NAME)

	@rm -rf $(BINPKG_SIGN_DIR)/$(BOOTIMG_DIR) $(BINPKG_DIR)/pub_key

.PHONY: secure-nvsprog-sign
secure-nvsprog-sign: secure-gen-pub-key-mod
	@mkdir -p $(BINPKG_SIGN_DIR)/nvsprog

	$(Q)$(SECURE_UTILS)/nvsp_sign.sh $(BINPKG_SIGN_DIR)/nvspc.bin \
		$(BINPKG_SIGN_DIR)/nvsprog/nvsp-sign.bin \
		$(SPL_HASH_ALGO) $(SPL_RSA) \
		$(CUSTOM_SPL_KEY)

	$(Q)$(SECURE_UTILS)/verify_sign.sh $(SPL_HASH_ALGO) \
		$(BINPKG_SIGN_DIR)/nvspc.bin $(BINPKG_SIGN_DIR)/nvsprog/nvsp-sign.bin \
		$(SPL_PUB_KEY) $(SPL_RSA)

	$(Q)$(GEN_BR) -packspl $(BINPKG_SIGN_DIR)/nvspc.bin \
		$(BINPKG_SIGN_DIR)/nvsprog/$(BR_NAME) $(SPL_PUB_KEY_MOD) \
		$(BINPKG_SIGN_DIR)/nvsprog/nvsp-sign.bin

	@cp $(BINPKG_SIGN_DIR)/nvsprog/$(BR_NAME) $(BINPKG_SIGN_DIR)/nvspc_br.bin

	@rm -rf $(BINPKG_SIGN_DIR)/nvsprog $(BINPKG_DIR)/pub_key

.PHONY: secure-freertos-sign
ifeq ($(CONFIG_AMP),y)
secure-freertos-sign:
	@if [ ! -f "$(BINPKG_SIGN_DIR)/freertos.bin" ]; then \
		echo "Error: $(BINPKG_SIGN_DIR)/freertos.bin not found!"; \
		exit 1; \
	fi
	$(Q)$(SECURE_UTILS)/uboot_sign.sh $(BINPKG_SIGN_DIR)/freertos.bin $(BINPKG_SIGN_DIR)/freertos_sign.bin $(CUSTOM_UBOOT_KEY)
	$(Q)$(SECURE_UTILS)/verify_sign.sh SHA256 $(BINPKG_SIGN_DIR)/freertos.bin $(BINPKG_SIGN_DIR)/freertos_sign.bin $(UBOOT_PUB_KEY)
	$(Q)$(SECURE_UTILS)/convert_img_size.sh $(BINPKG_SIGN_DIR)/freertos.bin $(BINPKG_SIGN_DIR)/freertos_size.tmp
	@cat $(BINPKG_SIGN_DIR)/freertos_sign.bin $(BINPKG_SIGN_DIR)/freertos_size.tmp $(BINPKG_SIGN_DIR)/freertos.bin > $(BINPKG_SIGN_DIR)/freertos.tmp && \
	mv $(BINPKG_SIGN_DIR)/freertos.tmp $(BINPKG_SIGN_DIR)/freertos.bin && \
	rm -f $(BINPKG_SIGN_DIR)/freertos_sign.bin $(BINPKG_SIGN_DIR)/freertos_size.tmp
else:
secure-freertos-sign:
endif

.PHONY: secure-app-sign
secure-app-sign:
	@if [ -d "$(BINPKG_SIGN_DIR)/$(SECURE_APP_DIR)" ]; then \
		$(MAKE) -C $(USRDATAFS_BUILD_PATH) secure-unpack; \
		$(MAKE) -C $(SAMPLE_DEMO_PATH)/video/mpi_stream/build app-sign; \
		$(MAKE) -C $(USRDATAFS_BUILD_PATH) secure-pack; \
	fi

SIGN_ENV = LD_LIBRARY_PATH=$(BUILDROOT_HOST_LIB):$$LD_LIBRARY_PATH
.PHONY: signature
signature: buildroot
	$(Q)$(MAKE) host-utils GEN_BR_ONLY=y
	@rm -rf $(BINPKG_SIGN_DIR)
	@cp -r $(BINPKG_DIR) $(BINPKG_SIGN_DIR)

	@echo - Creating Signed Firmware
	$(Q)$(SIGN_ENV) $(MAKE) secure-app-sign
	$(Q)$(SIGN_ENV) $(MAKE) secure-rootfs-sign
	$(Q)$(SIGN_ENV) $(MAKE) rootfs_partition_size_check
	$(Q)$(SIGN_ENV) $(MAKE) secure-bootimg-sign
	$(Q)$(SIGN_ENV) $(MAKE) secure-fitimage-sign
	$(Q)$(SIGN_ENV) $(MAKE) secure-nvsprog-sign
	$(Q)$(SIGN_ENV) $(MAKE) secure-freertos-sign
	$(Q)$(SIGN_ENV) $(MAKE) debug_ver

endif # CONFIG_SECURE_BOOT

.PHONY: output-prepare
output-prepare:
	@mkdir -p $(BINPKG_DIR)

.PHONY: output-clean
output-clean:
	@rm -rf $(BINPKG_DIR)
	@rm -rf $(BINPKG_DIR_DEBUG)
	@rm -rf $(BINPKG_SIGN_DIR)

.PHONY: genbin
genbin: ;

# update-builddate: save ABI version to $(ABIVER_FILE)
#
# After this make target is executed, the minor number in ABI version
# is updated to build date with format YYYYMMDD, and the patch number
# in ABI version increases 1
#
# See: ./release-sdk.sh
.PHONY: update-builddate
update-builddate:
	@echo "major: $(MAJOR)" > $(ABIVER_FILE)
	@echo "minor: $(shell date '+%Y%m%d')" >> $(ABIVER_FILE)
	@echo "patch: $(shell expr $(PATCH) + 1)" >> $(ABIVER_FILE)

.PHONY: sdk-info-install
sdk-info-install:
	$(Q)echo 'SDK version: '$(SDK_VER) > $(FIRMWARE_BUILD_PATH)/sdk-version
	$(Q)echo 'ABI version: '$(ABI_VER) >> $(FIRMWARE_BUILD_PATH)/sdk-version
	$(Q)echo 'SDK build time: '`date '+%Y-%m-%d %H:%M:%S'` >> $(FIRMWARE_BUILD_PATH)/sdk-version
	$(Q)echo 'Git branch: '`git branch | grep \* | cut -d ' ' -f2` >> $(FIRMWARE_BUILD_PATH)/sdk-version
	$(Q)mkdir -p $(SYSROOT)/etc
	$(Q)cp -f $(FIRMWARE_BUILD_PATH)/sdk-version $(SYSROOT)/etc/sdk-version
	$(Q)echo $(SDK_VER) > $(SYSROOT)/etc/sw-version
	@if echo "$(SDK_VER_CODE)" | grep -q "error"; then \
		echo "Warning: Cannot convert SDK version code. The version code will be set to 0."; \
		echo 0 >> $(SYSROOT)/etc/sw-version; \
	else \
		echo $(SDK_VER_CODE) >> $(SYSROOT)/etc/sw-version; \
	fi
ifeq ($(CONFIG_OPTEE), y)
	@if ! echo "$(ROOTFS_VER)" | grep -qE '^[0-9]+$$'; then \
		echo "[SYSUPD] Error: ROOTFS_VER is not a valid integer."; \
		exit 1; \
	fi
	@if ! echo "$(TEE_VER)" | grep -qE '^[0-9]+$$'; then \
		echo "[SYSUPD] Error: TEE_VER is not a valid integer."; \
		exit 1; \
	fi
	echo rootfs_ver:$(ROOTFS_VER) >> $(SYSROOT)/etc/sw-version
	echo tee_ver:$(TEE_VER) >> $(SYSROOT)/etc/sw-version
endif

.PHONY: sdk-info-uninstall
sdk-info-uninstall:
	$(Q)rm -f \
		$(SDK_DIR)/build/sdk-version \
		$(SYSROOT)/etc/sdk-version \
		$(SYSROOT)/etc/sw-version

.PHONY: release-info-install
release-info-install:
	$(Q)echo 'Firmware build time: '`date '+%Y-%m-%d %H:%M:%S'` > $(FIRMWARE_BUILD_PATH)/firmware-info
	$(Q)echo 'Git branch: '`(git branch 2> /dev/null || echo "") | grep \* | cut -d ' ' -f2` >>  $(FIRMWARE_BUILD_PATH)/firmware-info
	$(Q)mkdir -p $(SYSROOT)/etc
	$(Q)cp -f $(FIRMWARE_BUILD_PATH)/sdk-version $(SYSROOT)/etc/sdk-version
	$(Q)cp -f $(FIRMWARE_BUILD_PATH)/firmware-info $(SYSROOT)/etc/firmware-info
	$(Q)echo $(SDK_VER) > $(SYSROOT)/etc/sw-version
	# SDK_VER_CODE is for anti-rollback protection checking
	@if echo "$(SDK_VER_CODE)" | grep -q "error"; then \
		echo "Warning: Cannot convert SDK version code. The version code will be set to 0."; \
		echo 0 >> $(SYSROOT)/etc/sw-version; \
	else \
		echo $(SDK_VER_CODE) >> $(SYSROOT)/etc/sw-version; \
	fi
ifeq ($(CONFIG_OPTEE), y)
	@if ! echo "$(ROOTFS_VER)" | grep -qE '^[0-9]+$$'; then \
		echo "[SYSUPD] Error: ROOTFS_VER is not a valid integer."; \
		exit 1; \
	fi
	@if ! echo "$(TEE_VER)" | grep -qE '^[0-9]+$$'; then \
		echo "[SYSUPD] Error: TEE_VER is not a valid integer."; \
		exit 1; \
	fi
	echo rootfs_ver:$(ROOTFS_VER) >> $(SYSROOT)/etc/sw-version
	echo tee_ver:$(TEE_VER) >> $(SYSROOT)/etc/sw-version
endif

.PHONY: release-info-uninstall
release-info-uninstall:
	$(Q)rm -f \
		$(FIRMWARE_BUILD_PATH)/firmware-info \
		$(SYSROOT)/etc/firmware-info \
		$(SYSROOT)/etc/sdk-version \
		$(SYSROOT)/etc/sw-version

.PHONY: snapshot snapshot-install snapshot-clean check-commit debug_ver debug-install
ifneq ($(CONFIG_RELEASE), y)
################################################################################
# Take snapshot of build information
#
# This enable us to trace to correct version of source codes from image file.
# The .log and .xml files must be created outside current working directory,
# otherwise there will be untracked files reported by git status.
# The hash prevents collision when there are multiple builds on one machine.
################################################################################
BUILD_SNAPSHOT_DEST=$(SDKSRC_DIR)/tmp
snapshot:
	@mkdir -p $(BUILD_SNAPSHOT_DEST)
	@echo -n "Built by: " > \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@whoami >> $(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@echo -n "Built time: " >> \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@date >> $(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@echo "Source path: $(SDKSRC_DIR)" >> \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@echo "Git status:" >> \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@repo forall -pc "git status" >> \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@repo manifest -r > \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).xml
	@printf "  %-8s  build_snapshot.log\n" "GZIP"
	@gzip -f $(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log
	@printf "  %-8s  build_snapshot.xml\n" "GZIP"
	@gzip -f $(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).xml

snapshot-install: snapshot
	@printf "  %-8s  build_snapshot.log.gz\n" "INSTALL"
	@mkdir -p $(SYSTEMFS)/snapshot
	@install -m 444 \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log.gz \
		$(SYSTEMFS)/snapshot/build_snapshot.log.gz
	@printf "  %-8s  build_snapshot.log.gz\n" "INSTALL"
	@install -m 444 \
		$(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).xml.gz \
		$(SYSTEMFS)/snapshot/build_snapshot.xml.gz

snapshot-clean:
	@printf "  %-8s  build_snapshot.log.gz\n" "CLEAN"
	@rm -f $(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).log.gz
	@rm -f $(SYSTEMFS)/snapshot/build_snapshot.log.gz
	@printf "  %-8s  build_snapshot.xml.gz\n" "CLEAN"
	@rm -f $(BUILD_SNAPSHOT_DEST)/build_snapshot.$(SDKSRC_HASH).xml.gz
	@rm -f $(SYSTEMFS)/snapshot/build_snapshot.xml.gz

check-commit:
ifneq ($(strip $(shell repo forall -pc git status | grep "modified")),)
	$(show_error)
	@printf "==================================================================\n"
	@printf "  WARNING: Uncommited files in Git Repo!\n"
	@printf "==================================================================\n"
endif

debug-install:
	@rm -rf $(BINPKG_DIR_DEBUG)
	@mkdir -p $(BINPKG_DIR_DEBUG)
ifneq ($(CONFIG_SECURE_BOOT), y)
	@cp -rf $(BINPKG_DIR)/* $(BINPKG_DIR_DEBUG)
	@cp -f $(ROOTFS_IMAGE_PATH)/$(ROOTFS_CPIO_UBOOT_FILE_DBG) $(BINPKG_DIR_DEBUG)/$(ROOTFS_CPIO_UBOOT_FILE).bin
else
	@cp -rf $(BINPKG_SIGN_DIR)/* $(BINPKG_DIR_DEBUG)
	@rm -rf $(BINPKG_SIGN_DIR)/$(ROOTFS_CPIO_UBOOT_FILE_DBG).bin $(BINPKG_SIGN_DIR)/$(FITIMAGE_NAME)_dbg.bin
	@mv $(BINPKG_DIR_DEBUG)/$(ROOTFS_CPIO_UBOOT_FILE_DBG).bin $(BINPKG_DIR_DEBUG)/$(ROOTFS_CPIO_UBOOT_FILE).bin
	@mv $(BINPKG_DIR_DEBUG)/$(FITIMAGE_NAME)_dbg.bin $(BINPKG_DIR_DEBUG)/$(FITIMAGE_NAME).bin
endif # CONFIG_SECURE_BOOT

debug_ver: debug-install

else
snapshot snapshot-install snapshot-clean:
check-commit:
debug_ver:
endif

.PHONY: prod-list
prod-list:
	@echo "Supported Products:"
	@for m in $(sort $(patsubst %_defconfig, %, $(DEFCONFIG_LIST))); do \
		printf "\t%s\n" $$m; \
	done

.PHONY: config-list
config-list:
	@echo "Supported Configs:"
	@for m in $(sort $(DEFCONFIG_LIST)); do \
		printf "\t%s\n" $$m; \
	done

.PHONY: $(DEFCONFIG_LIST)
$(DEFCONFIG_LIST): toolchain
	@printf "  %-8s  %s\n" "CONFIG" $@
	@if [ -e $(PRODUCT_RULE_DIR)/$@ ]; then \
		cp $(PRODUCT_RULE_DIR)/$@ .config; \
		"$(BUILD_UTILS_PATH)/gen_rootfs_ubinize_cfg.sh" "$(ROOTFS_PATH)/fs/ubifs/rootfs_ubinize.cfg"; \
		printf "#\n# configuration written to .config\n#\n"; \
	else \
		printf "Error: The configuration file is not exist!\n"; \
	fi
	$(Q)$(MAKE) -C $(BUILD_UTILS_PATH)/scripts conf
	$(Q)$(MAKE) update-configs

################################################################################
# Unit-test targets
################################################################################

.PHONY: unit-test
unit-test:
	$(Q)$(MAKE) -C $(CUTEST_PATH) all

.PHONY: ut-clean
ut-clean:
	$(Q)$(MAKE) -C $(CUTEST_PATH) clean
