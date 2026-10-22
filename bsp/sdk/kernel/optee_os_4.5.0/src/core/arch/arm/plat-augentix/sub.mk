global-incdirs-y += .
srcs-y += main.c
srcs-y += psci.c
srcs-y += a7_plat_init.S
srcs-y += delay.c
srcs-$(CFG_SM_PLATFORM_HANDLER) += agtx_smc.c
srcs-$(CFG_SM_PLATFORM_SUSPEND)	+= augentix_suspend.c
