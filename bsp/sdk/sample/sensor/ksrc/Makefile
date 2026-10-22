# Copyright Augentix Inc. Proprietary and confidential.
# Unauthorized use or distribution is prohibited.
# Please contact customer.support@augentix.com for any inquiries.

################################################################################
# SDK related definitions
################################################################################

export SDKSRC_DIR ?= $(realpath $(CURDIR)/../../../..)

include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

################################################################################
# Build tools and commands
################################################################################

ifeq ($(CONFIG_KERNEL_V6_1),y)
ifeq ($(CONFIG_KERNEL_ARM64), y)
CROSS_COMPILE_LINUX := $(CROSS_COMPILE_5)
ARCH_LINUX := arm64
else
CROSS_COMPILE_LINUX := $(CROSS_COMPILE_2)
ARCH_LINUX := arm
endif
else
CROSS_COMPILE_LINUX := $(CROSS_COMPILE)
ARCH_LINUX := arm
endif

### First, specify the build tools.
ifeq ($(CONFIG_UCLIBC),y)
XTOOL_PATH := $(XTOOL_PATH_2)
CROSS_COMPILE := $(CROSS_COMPILE_2)
endif

CC := $(CROSS_COMPILE)gcc
CX := $(CROSS_COMPILE)g++
AR := $(CROSS_COMPILE)ar
RM := rm
LN := ln
MKDIR := mkdir
RMDIR := rmdir
STRIP := $(CROSS_COMPILE)strip
INSTALL := install
INSTALL_DATA := $(INSTALL) -c -m 644
TAR := tar
NICE := nice

################################################################################
# Target Module
################################################################################

DEST := $(SENSOR_PATH)/ko
MODULE_NAME := sensor.ko

MAKEFLAGS += -j

################################################################################
# Directory
################################################################################

################################################################################
# Dependency
################################################################################

obj-m += sensor.o
sensor-objs := sensor_dev.o sensor_pm.o sensor_ctrl.o
ccflags-y += -iquote $(MPP_INC)

# Workaround: bypass some warnings that were fixed in later versions for Linux v3.18.
ifneq ($(CONFIG_KERNEL_V6_1),y)
ccflags-y += -Wno-attributes -Wno-missing-attributes
endif

# Assume the SENSOR information are filled in the correct order in the top-level config.
ifneq ($(SENSOR),)
SENSOR_NUM := 1
ifneq ($(wildcard $(SENSOR_PATH)/ksrc/sensor_pm_sns0.c),)
sensor-objs += sensor_pm_sns0.o
ccflags-y += -DSNS0
endif
endif
ifneq ($(SENSOR1),)
SENSOR_NUM := 2
ifneq ($(wildcard $(SENSOR_PATH)/ksrc/sensor_pm_sns1.c),)
sensor-objs += sensor_pm_sns1.o
ccflags-y += -DSNS1
endif
endif
ifneq ($(SENSOR2),)
SENSOR_NUM := 3
ifneq ($(wildcard $(SENSOR_PATH)/ksrc/sensor_pm_sns2.c),)
sensor-objs += sensor_pm_sns2.o
ccflags-y += -DSNS2
endif
endif
ifneq ($(SENSOR3),)
SENSOR_NUM := 4
ifneq ($(wildcard $(SENSOR_PATH)/ksrc/sensor_pm_sns3.c),)
sensor-objs += sensor_pm_sns3.o
ccflags-y += -DSNS3
endif
endif
ccflags-y += -DSENSOR_NUM=$(SENSOR_NUM)

################################################################################
# Make targets
################################################################################

.PHONY: all
all: target

.PHONY: target
target: $(DEST)/$(MODULE_NAME)

$(DEST)/$(MODULE_NAME): $(MODULE_NAME)
	$(Q)install -m 666 $< $(dir $@)

.PHONY: $(MODULE_NAME)
$(MODULE_NAME):
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD modules KBUILD_MODPOST_WARN=1 CROSS_COMPILE=$(CROSS_COMPILE_LINUX) ARCH=$(ARCH_LINUX)

$(DEST):
	$(Q)install -d $@

.PHONY: clean
clean:
	$(Q)$(MAKE) -C $(KERNEL_PATH) M=$$PWD clean
	$(Q)$(RM) -f $(DEST)/$(MODULE_NAME)

