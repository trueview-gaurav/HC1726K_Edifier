# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2026 Augentix Inc.

# CPVS float ABI follows the per-chip toolchain.
# SPL and bearssl must match it: hc1725 soft, hc1705k and *-fpu hard.
ifdef CONFIG_XPL_BUILD
ifneq (,$(findstring eabihf,$(CROSS_COMPILE)))
PLATFORM_RELFLAGS := $(filter-out -msoft-float -mgeneral-regs-only,$(PLATFORM_RELFLAGS)) \
		     -mfloat-abi=hard -mfpu=neon-vfpv4
BEARSSL_LIB := libbearssl_gnueabihf.lib
else
BEARSSL_LIB := libbearssl_gnueabi.lib
endif
endif

SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
UBOOT_SRC := $(realpath $(CURDIR))
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

PLATFORM_LIBS += -L$(CPVS_LIB) -lpid -lutil

ifdef CONFIG_XPL_BUILD
PLATFORM_LIBS += $(UBOOT_SRC)/arch/arm/mach-augentix/bearssl-0.6/$(BEARSSL_LIB)
endif
