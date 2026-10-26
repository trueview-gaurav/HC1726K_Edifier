# SPDX-License-Identifier: GPL-2.0+
#
# Copyright (C) 2026 Augentix Inc.

obj-y += board.o

# agtx_smc.h is the SoC half of the eFuse ABI and lives beside its SoC.
ccflags-$(CONFIG_AUGENTIX_SOC_SAPPORO) += -I$(srctree)/arch/arm/mach-augentix/sapporo
ccflags-$(CONFIG_AUGENTIX_SOC_KYOTO)   += -I$(srctree)/arch/arm/mach-augentix/kyoto

ifndef CONFIG_XPL_BUILD
obj-$(CONFIG_EFUSE_FSM_AUTOBURN) += efuse_burn_fsm.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += env_bootargs.o
endif
