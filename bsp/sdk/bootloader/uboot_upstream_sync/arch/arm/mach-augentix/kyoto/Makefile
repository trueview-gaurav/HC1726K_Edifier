# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2026 Augentix Inc.

SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

ccflags-y := -I$(CPVS_INC)/csr -I$(CPVS_INC) -I$(CPVS_INC)/uart -I$(CPVS_INC)/utils \
	     -I$(GEN_INC)
ccflags-y += -DAUGENTIX_CPVS_CONSUMER

obj-y += audio.o
obj-$(CONFIG_XPL_BUILD) += board_pinmux.o
