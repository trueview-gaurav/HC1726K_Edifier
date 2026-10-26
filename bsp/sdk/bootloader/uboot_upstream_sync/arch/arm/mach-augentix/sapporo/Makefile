# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2026 Augentix Inc.

SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

ccflags-y := -I$(CPVS_INC)/csr -I$(CPVS_INC) -I$(CPVS_INC)/uart -I$(CPVS_INC)/utils \
	     -I$(GEN_INC) -I$(srctree)/arch/arm/mach-augentix/include/mach
ccflags-y += -DAUGENTIX_CPVS_CONSUMER

CFLAGS_audio.o += -include $(srctree)/arch/arm/mach-augentix/include/mach/fastboot_common.h
obj-y += audio.o
obj-$(CONFIG_EB_SMC) += agtx_smc.o
obj-$(CONFIG_XPL_BUILD) += board_pinmux.o
