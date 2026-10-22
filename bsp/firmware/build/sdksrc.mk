###############################################################################
# Augentix SDK Makefile Boilerplate
###############################################################################

SERIES = HC18-SERIES
TOOLCHAIN = $(CROSS_COMPILE:-=)
TOOLCHAIN_SUFFIX = $(lastword $(subst -, ,$(TOOLCHAIN)))


# Firmware build direcotry
FIRMWARE_BUILD_PATH = $(SDKSRC_DIR)/firmware/build

include $(FIRMWARE_BUILD_PATH)/import_config.mk

# Buildroot directories
BUILDROOT_PATH = $(SDKSRC_DIR)/buildroot
BUILDROOT_BUILD_PATH = $(BUILDROOT_PATH)/build
BUILDROOT_SRC_PATH = $(BUILDROOT_PATH)/src
BUILDROOT_CONFIG_PATH = $(BUILDROOT_SRC_PATH)/configs
BUILDROOT_OUTPUT_PATH = $(BUILDROOT_PATH)/output
BUILDROOT_OUTPUT_BUILD_PATH=$(BUILDROOT_OUTPUT_PATH)/build
BUILDROOT_OUTPUT_STAGING_PATH=$(BUILDROOT_OUTPUT_PATH)/staging
BUILDROOT_HOST_SBIN = $(BUILDROOT_OUTPUT_PATH)/host/usr/sbin
BUILDROOT_HOST_BIN = $(BUILDROOT_OUTPUT_PATH)/host/usr/bin
BUILDROOT_HOST_LIB = $(BUILDROOT_OUTPUT_PATH)/host/lib
BUILDROOT_HOST_INC = $(BUILDROOT_OUTPUT_PATH)/host/usr/arm-buildroot-linux-$(TOOLCHAIN_SUFFIX)/sysroot/usr/include
BUILDROOT_TARGET_LIB = $(BUILDROOT_OUTPUT_PATH)/target/usr/lib
BUILDROOT_HOST_UBOOT_TOOLS_PATH = $(BUILDROOT_OUTPUT_BUILD_PATH)/host-uboot-tools-2024.10/tools

# Buildroot libraries
include $(FIRMWARE_BUILD_PATH)/buildroot.mk

TOOLCHAIN_PATH = $(SDKSRC_DIR)/toolchain
ifeq ($(TOOLCHAIN), arm-linux-gnueabihf)
TOOLCHAIN_LIBGCC_PATH = $(TOOLCHAIN_PATH)/gcc-linaro-4.9-2016.02-x86_64_arm-linux-gnueabihf/lib/gcc/arm-linux-gnueabihf/4.9.4 -lgcc
else ifeq ($(TOOLCHAIN), arm-linux-gnueabi)
TOOLCHAIN_LIBGCC_PATH = $(TOOLCHAIN_PATH)/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi/lib/gcc/arm-linux-gnueabi/4.9.4 -lgcc
else ifeq ($(TOOLCHAIN), arm-augentix-linux-gnueabi)
TOOLCHAIN_LIBGCC_PATH = $(TOOLCHAIN_PATH)/arm-augentix-linux-gnueabi/lib/gcc/arm-augentix-linux-gnueabi/4.9.3 -lgcc
endif

# CPVS header / libraries directories
CPVS_PATH = $(SDKSRC_DIR)/sdk/core/cpvs
CPVS_INC = $(CPVS_PATH)/include
CPVS_LIB = $(CPVS_PATH)/lib
CPVS_KO = $(CPVS_PATH)/ko
CPVS_CSR_INC = $(CPVS_INC)/csr
CPVS_SENIF_INC = $(CPVS_INC)/senif

ifeq ($(CONFIG_KERNEL_V6_1),y)
SDK_KERNEL_VERSION=6.1.166
KERNEL_PATH = $(SDKSRC_DIR)/sdk/kernel/linux_6.1.102
else
SDK_KERNEL_VERSION=3.18.31
KERNEL_PATH = $(SDKSRC_DIR)/sdk/kernel/linux_3.18.31
endif
# Per-product U-Boot tree. CONFIG_UBOOT_UPSTREAM is set in the product
# defconfig beside UBOOT_CONFIG; unset keeps v2016.03.
ifeq ($(CONFIG_UBOOT_UPSTREAM),y)
UBOOT_PATH = $(SDKSRC_DIR)/sdk/bootloader/uboot_upstream_sync
UBOOT_SOC_DIR = $(UBOOT_PATH)/arch/arm/mach-augentix/$(UBOOT_SOC)
else
UBOOT_PATH = $(SDKSRC_DIR)/sdk/bootloader/uboot
UBOOT_SOC_DIR = $(UBOOT_PATH)/arch/arm/cpu/$(UBOOT_ARCH)/$(UBOOT_SOC_LEGACY)
endif

# SoC directory name, which differs between the two trees.
ifeq ($(CONFIG_SAPPORO),y)
UBOOT_ARCH = armv7
UBOOT_SOC = sapporo
UBOOT_SOC_LEGACY = sapporo
else ifeq ($(CONFIG_HC1703_1723_1753_1783S),y)
UBOOT_ARCH = armv7
UBOOT_SOC = kyoto
UBOOT_SOC_LEGACY = hc1703_1723_1753_1783s
else ifeq ($(CONFIG_OSAKA),y)
UBOOT_ARCH = armv8
UBOOT_SOC = osaka
UBOOT_SOC_LEGACY = osaka
else ifeq ($(CONFIG_KAMO),y)
UBOOT_ARCH = armv7
UBOOT_SOC = kamo
UBOOT_SOC_LEGACY = kamo
endif
TFA_PATH = $(SDKSRC_DIR)/sdk/bootloader/trusted_firmware_a
UBOOT_ENV_PATH = $(UBOOT_PATH)/tools/env
# v2026.07 renamed env to envtools, and a missing target is silent under make.
UBOOT_ENV_TARGET = $(if $(CONFIG_UBOOT_UPSTREAM),envtools,env)
HOST_UTILS_PATH = $(SDKSRC_DIR)/sdk/utils/host/bin
FSBL_PATH = $(SDKSRC_DIR)/sdk/bootloader/fsbl
FSBL_BUILD_PATH = $(FSBL_PATH)/build
FSBL_LIB_PATH = $(FSBL_PATH)/lib
ROOTFS_PATH = $(SDKSRC_DIR)/firmware/filesystem/rootfs
ROOTFS_BUILD_PATH = $(ROOTFS_PATH)/build
ROOTFS_OUTPUT_PATH = $(ROOTFS_PATH)/output
ROOTFS_IMAGE_PATH = $(ROOTFS_OUTPUT_PATH)/images
ROOTFS_CPIO_FILE = rootfs.cpio
ROOTFS_CPIO_UBOOT_FILE = $(ROOTFS_CPIO_FILE).uboot
ROOTFS_CPIO_UBOOT_DIR = $(ROOTFS_CPIO_UBOOT_FILE)
ROOTFS_CPIO_UBOOT_FILE_DBG = $(ROOTFS_CPIO_UBOOT_FILE)_debug
ROOTFS_CPIO_UBOOT_FILE_REL = $(ROOTFS_CPIO_UBOOT_FILE)
ifneq ($(CONFIG_KERNEL_ARM64),y)
DTS_PATH = $(KERNEL_PATH)/arch/arm/boot/dts
else
DTS_PATH = $(KERNEL_PATH)/arch/arm64/boot/dts/augentix
endif
OPTEE_PATH = $(SDKSRC_DIR)/sdk/kernel/optee_os_4.5.0
MPP_PATH = $(SDKSRC_DIR)/sdk/core/mpp
MPP_UTILS_PATH = $(MPP_PATH)/utils
KVPP_PATH = $(MPP_PATH)/kvpp
MPP_BUILD_PATH = $(MPP_PATH)/build
EXTDRV_PATH = $(SDKSRC_DIR)/sdk/kernel/extdrv
AUDIO_PATH = $(EXTDRV_PATH)/audio
AUDIO_BUILD_PATH = $(AUDIO_PATH)/build
VB_PATH = $(MPP_PATH)/vb
SENSOR_PATH = $(SDKSRC_DIR)/sdk/sample/sensor
VENC_PATH = $(SDKSRC_DIR)/sdk/sample/venc_setting
ISP_PATH = $(MPP_PATH)/isp
BUILD_UTILS_PATH = $(FIRMWARE_BUILD_PATH)/build_utils
UTILS_PATH = $(SDKSRC_DIR)/sdk/utils
UTILS_BUILD_PATH = $(UTILS_PATH)/build
UTILS_HOST_PATH = $(UTILS_PATH)/host
UTILS_TARGET_PATH = $(UTILS_PATH)/target
SCRIPTS_PATH = $(ROOTFS_PATH)/scripts
NVSP_PATH = $(SDKSRC_DIR)/firmware/build/programmer/nvsp
UT_PATH = $(SDKSRC_DIR)/sdk/top/ut_framework
CUTEST_PATH = $(UT_PATH)/cutest
KCONFIG_PATH = $(BUILD_UTILS_PATH)/kconfig

APP_PATH = $(SDKSRC_DIR)/firmware/reference_software
REMOTE_PATH = $(SDKSRC_DIR)/sdk/kernel/remote

SAMPLE_DEMO_PATH = $(SDKSRC_DIR)/sdk/sample/demo
AMPC_PATH = $(SDKSRC_DIR)/sdk/sample/ampc
SAMPLE_OPTEE_PATH = $(SDKSRC_DIR)/sdk/sample/optee

# Used by featurelib

DEBUG_PATH = $(MPP_PATH)/libdebug
BT_PATH = $(KERNEL_PATH)/drivers/bluetooth/realtek8723du

# Feature_video and feature_audio include and library
FEATURE_VIDEO_PATH = $(SDKSRC_DIR)/sdk/core/vftr
FEATURE_ML_PATH = $(SDKSRC_DIR)/sdk/core/ml
FEATURE_AUDIO_PATH = $(SDKSRC_DIR)/sdk/core/aftr
FEATURE_IR_CONTROL_PATH = $(SDKSRC_DIR)/sdk/core/ir_control
FEATURE_PATHS = $(FEATURE_VIDEO_PATH) $(FEATURE_AUDIO_PATH) $(FEATURE_IR_CONTROL_PATH)

FEATURE_VIDEO_BUILD_PATH = $(FEATURE_VIDEO_PATH)/build
FEATURE_AUDIO_BUILD_PATH = $(FEATURE_AUDIO_PATH)/build
FEATURE_ML_BUILD_PATH = $(FEATURE_ML_PATH)/build
FEATURE_IR_CONTROL_BUILD_PATH = $(FEATURE_IR_CONTROL_PATH)/build
FEATURE_BUILD_PATHS = $(FEATURE_VIDEO_BUILD_PATH) $(FEATURE_AUDIO_BUILD_PATH) $(FEATURE_IR_CONTROL_BUILD_PATH) $(FEATURE_ML_BUILD_PATH)

FEATURE_VIDEO_LIB_PATH = $(FEATURE_VIDEO_PATH)/lib
FEATURE_AUDIO_LIB_PATH = $(FEATURE_AUDIO_PATH)/lib
FEATURE_ML_LIB_PATH = $(FEATURE_ML_PATH)/lib
FEATURE_IR_CONTROL_LIB_PATH = $(FEATURE_IR_CONTROL_PATH)/lib
FEATURE_LIB_PATHS = $(FEATURE_VIDEO_LIB_PATH) $(FEATURE_AUDIO_LIB_PATH) $(FEATURE_IR_CONTROL_LIB_PATH)

FEATURE_VIDEO_INC_PATH = $(FEATURE_VIDEO_PATH)/include
FEATURE_AUDIO_INC_PATH = $(FEATURE_AUDIO_PATH)/include
FEATURE_ML_INC_PATH = $(FEATURE_ML_PATH)/include
FEATURE_IR_CONTROL_INC_PATH = $(FEATURE_IR_CONTROL_PATH)/include
FEATURE_INC_PATHS = $(FEATURE_VIDEO_INC_PATH) $(FEATURE_AUDIO_INC_PATH) $(FEATURE_IR_CONTROL_INC_PATH)

LD_PATH = $(FEATURE_VIDEO_PATH)/src/ld
TD_PATH = $(FEATURE_VIDEO_PATH)/src/td
MD_PATH = $(FEATURE_VIDEO_PATH)/src/md
EF_PATH = $(FEATURE_VIDEO_PATH)/src/ef
AROI_PATH = $(FEATURE_VIDEO_PATH)/src/aroi
OSC_PATH = $(FEATURE_VIDEO_PATH)/src/osc
SHD_PATH = $(FEATURE_VIDEO_PATH)/src/shd
EAIF_PATH = $(FEATURE_VIDEO_PATH)/src/eaif
PFM_PATH = $(FEATURE_VIDEO_PATH)/src/pfm
FD_PATH = $(FEATURE_VIDEO_PATH)/src/fd
DK_PATH = $(FEATURE_VIDEO_PATH)/src/dk
FLD_PATH = $(FEATURE_VIDEO_PATH)/src/fld

SD_PATH =$(FEATURE_AUDIO_PATH)/src/sd
AC_PATH = $(FEATURE_AUDIO_PATH)/src/ac

FEATURE_VIDEO_UT_PATH = $(addsuffix /unit_test, $(addprefix $(FEATURE_VIDEO_PATH)/src/, $(basename $(notdir $(wildcard $(FEATURE_VIDEO_INC_PATH)/*.h)))))
FEATURE_AUDIO_UT_PATH = $(addsuffix /unit_test, $(addprefix $(FEATURE_AUDIO_PATH)/src/, $(basename $(notdir $(wildcard $(FEATURE_AUDIO_INC_PATH)/*.h)))))
FEATURE_UT_PATHS = $(FEATURE_VIDEO_UT_PATH) $(FEATURE_AUDIO_UT_PATH)

FEATURE_VIDEO_LIB = vftr
FEATURE_AUDIO_LIB = aftr
FEATURE_ML_LIB = ml
FEATURE_IR_CONTROL_LIB = ir_control
FEATURE_LIBS = $(FEATURE_VIDEO_LIB) $(FEATURE_AUDIO_LIB) $(FEATURE_IR_CONTROL_LIB)

# Include libraries
SDK_INC = $(SDKSRC_DIR)/sdk/top/include/common
GEN_INC = $(SDKSRC_DIR)/sdk/top/include/generated
CSR_DIR = $(SDKSRC_DIR)/sdk/top/include/csr/define
CSR_CST = $(SDKSRC_DIR)/sdk/top/include/csr/cstruct

# MPP include/library directories
MPP_INC = $(MPP_PATH)/include
MPP_LIB = $(MPP_PATH)/lib
MPP_KO = $(MPP_PATH)/ko

# MPI application include and library
MPI_PATH = $(MPP_PATH)/mpi

# DIP include and library
DIP_PATH = $(MPP_PATH)/dip
DIP_LIB = $(DIP_PATH)/lib
DIP_INC = $(DIP_PATH)/include

# AE include and library
AE_PATH = $(DIP_PATH)/hc_ae
AE_LIB = $(AE_PATH)
AE_INC = $(AE_PATH)

# AWB include and library
AWB_PATH = $(DIP_PATH)/hc_awb
AWB_LIB = $(AWB_PATH)
AWB_INC = $(AWB_PATH)

# IVA include and library
IVA_PATH = $(MPP_PATH)/iva
OBJDET_PATH = $(IVA_PATH)/object_detect
OBJDET_INC = $(OBJDET_PATH)

# KVPP include and library
KVPP_INC = $(KVPP_PATH)
KVPP_TRC_INC = $(KVPP_PATH)/trc

# libsensor
LIBSENSOR_INC = $(SENSOR_PATH)
LIBSENSOR_LIB = $(SENSOR_PATH)/lib

# libsns
SNS_PATH = $(MPP_PATH)/sensor
SNS_INC = $(SNS_PATH)

# libnrs
NRS_DRV_PATH = $(SDKSRC_DIR)/sdk/core/otp
NRS_DRV_BUILD = $(NRS_DRV_PATH)/build
NRS_DRV_SRC = $(NRS_DRV_PATH)/src
NRS_DRV_INC = $(NRS_DRV_PATH)/include
NRS_DRV_KO = $(NRS_DRV_PATH)/ko
NRS_DRV_SCRIPT = $(NRS_DRV_PATH)/scripts

# libvb
VB_INC = $(MPP_INC)
VB_LIB = $(VB_PATH)/lib

# libutrc
UTRC_PATH = $(MPP_PATH)/utrc
UTRC_COMMON_INC = $(MPP_PATH)/common/utrc
UTRC_INC = $(MPP_PATH)/utrc/include
KTRC_INC = $(KVPP_PATH)/trc

# libsr
SR_COMMON_INC = $(MPP_PATH)/common/sr

# VPC include and library
VPC_PATH = $(MPP_PATH)/vpc
VPLAT_PATH = $(VPC_PATH)/vplat
VPLAT_INC = $(VPLAT_PATH)
RS_PATH = $(VPC_PATH)/rs
RS_INC = $(RS_PATH)

# Utility libraries
DEBUG_INC = $(DEBUG_PATH)/inc

# remote libraries
REMOTE_LIB_PATH = $(REMOTE_PATH)/library
LIBMETAL_SRC_PATH = $(REMOTE_LIB_PATH)/libmetal
OPENAMP_SRC_PATH = $(REMOTE_LIB_PATH)/libopen_amp
AMPC_SRC_PATH = $(REMOTE_LIB_PATH)/libampc
REMOTE_LIBAMP_LIB = $(REMOTE_LIB_PATH)/lib
FREERTOS_PATH = $(REMOTE_PATH)/freertos

# ABI versioning file
ABIVER_MAKE = $(FIRMWARE_BUILD_PATH)/versioning.mk
ABIVER_FILE = $(FIRMWARE_BUILD_PATH)/.version

# Output/Release directories
SYSROOT_DBG = $(ROOTFS_OUTPUT_PATH)/target_debug
SYSROOT_REL = $(ROOTFS_OUTPUT_PATH)/target
SYSTEMFS = $(ROOTFS_OUTPUT_PATH)/system
SYSROOT = $(SYSROOT_DBG)

SYSTEM_BIN = $(SYSTEMFS)/bin
SYSTEM_LIB = $(SYSTEMFS)/lib

AGTX_MOD_PATH = $(SYSTEM_LIB)/modules/$(SDK_KERNEL_VERSION)/augentix

# AUDIO include and library
AUDIO_INC = $(AUDIO_PATH)/include
AUDIO_KO = $(AUDIO_PATH)/ko

# Earlyvideo include
EARLYVIDEO_PATH = $(EXTDRV_PATH)/earlyvideo

# Doxygen template directory
DOXYGEN_PATH = $(FIRMWARE_BUILD_PATH)/doxygen

# Secure boot key pairs
ifneq ($(strip $(CONFIG_CUSTOM_SIGN)),)
SECURE_KEY_DIR = $(FIRMWARE_BUILD_PATH)/key/$(strip $(CONFIG_CUSTOM_SIGN))
else
SECURE_KEY_DIR = $(FIRMWARE_BUILD_PATH)/key/default
endif
SPL_PUB_KEY = $(SECURE_KEY_DIR)/pubkey1.pem 
UBOOT_PUB_KEY = $(SECURE_KEY_DIR)/pubkey2.pem
FITIMG_KEY_PATH = $(SECURE_KEY_DIR)
UBOOT_DTS_KEY = $(SECURE_KEY_DIR)/u-boot_pubkey
SYSUPD_PUB_KEY = $(SECURE_KEY_DIR)/pubkey4.pem
APP_PUB_KEY = $(SECURE_KEY_DIR)/pubkey5.pem
APPUPD_PUB_KEY = $(SECURE_KEY_DIR)/pubkey6.pem
OPTEE_TA_PUB_KEY = $(SECURE_KEY_DIR)/pubkey7.pem

# Secure boot utils
SECURE_MKIMAGE = $(BUILDROOT_HOST_BIN)/mkimage
SECURE_FIT_CHECK_SIGN = $(BUILDROOT_HOST_UBOOT_TOOLS_PATH)/fit_check_sign
SECURE_DTC = $(BUILDROOT_HOST_BIN)/dtc
SECURE_APP_DIR = secure_app
SECURE_APP_PATH = /usrdata/$(SECURE_APP_DIR)
SECURE_UTILS = $(BUILD_UTILS_PATH)/secure_utils
OPENSC_PKCS11_PATH = /usr/lib/x86_64-linux-gnu/opensc-pkcs11.so # specify module to load
ROOTFS_SALT=17857b8aa5f7ee41db2f0a5d49a3d6685306e4c702a40ada4c30241dea14b03f

# gen_br directory
GEN_BR = $(HOST_UTILS_PATH)/gen_br 

# Alias for systemfs
CUSTOMFS = $(SYSTEMFS)
CUSTOM_BIN = $(SYSTEM_BIN)
CUSTOM_LIB = $(SYSTEM_LIB)

USRDATAFS_PATH = $(SDKSRC_DIR)/firmware/filesystem/usrdatafs
USRDATAFS_BUILD_PATH = $(USRDATAFS_PATH)/build
USRDATAFS = $(USRDATAFS_PATH)/usrdata

CALIBFS_PATH = $(SDKSRC_DIR)/firmware/filesystem/calibfs
CALIBFS_BUILD_PATH = $(CALIBFS_PATH)/build
CALIBFS = $(CALIBFS_PATH)/calib

ifeq ($(CONFIG_SECURE_BOOT),y)
BINPKG_DIR = $(FIRMWARE_BUILD_PATH)/output_unsigned
BINPKG_SIGN_DIR = $(FIRMWARE_BUILD_PATH)/output
else
BINPKG_DIR = $(FIRMWARE_BUILD_PATH)/output
BINPKG_SIGN_DIR =
endif
BINPKG_DIR_DEBUG = $(FIRMWARE_BUILD_PATH)/output_debug
SDKREL_DIR = $(FIRMWARE_BUILD_PATH)/SDK_release
TARGET_INIT_SCRIPTS_DIR = $(SYSROOT)/etc/init.d

ERROR_MSG_FILE = .error.txt


ifneq ("$(wildcard $(SDKSRC_DIR)/.release)", "")
	CONFIG_RELEASE := y
else
	CONFIG_RELEASE :=
endif

V ?= 0
ifeq ($(V),1)
	Q :=
	VOUT :=
else
	Q := @
	VOUT := 2>&1 1>/dev/null
endif

define show_error
	@cat $(ERROR_MSG_FILE)
endef
