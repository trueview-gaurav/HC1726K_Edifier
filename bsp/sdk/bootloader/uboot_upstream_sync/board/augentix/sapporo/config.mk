# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2026 Augentix Inc.

# SPL links CPVS, whose objects pass floats in VFP registers, so SPL alone has
# to match that ABI. U-Boot proper pulls no CPVS member and stays soft float.
ifdef CONFIG_XPL_BUILD
PLATFORM_RELFLAGS := $(filter-out -msoft-float -mgeneral-regs-only,$(PLATFORM_RELFLAGS)) \
		     -mfloat-abi=hard -mfpu=neon-vfpv4
endif

SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
UBOOT_SRC := $(realpath $(CURDIR))
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

PLATFORM_LIBS += -L$(CPVS_LIB) -lpid -lutil

ifdef CONFIG_XPL_BUILD
PLATFORM_LIBS += $(UBOOT_SRC)/arch/arm/mach-augentix/bearssl-0.6/libbearssl_gnueabihf.lib
endif
