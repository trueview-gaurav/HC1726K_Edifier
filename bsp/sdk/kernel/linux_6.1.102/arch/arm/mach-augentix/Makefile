obj-$(CONFIG_MACH_HC17XX) += pm.o
obj-$(CONFIG_MACH_HC17XX) += mach_augentix.o
ifneq ($(CONFIG_ARM_PSCI),y)
obj-$(CONFIG_SMP) += platsmp.o
endif
obj-$(CONFIG_AUGENTIX_AMP) += augentix_amp.o
ifeq ($(CONFIG_AUGENTIX_AMP), y)
EXTRA_CFLAGS += -I$(SDKSRC_DIR)/sdk/top/include
endif
ifeq ($(CONFIG_SAPPORO),y)
obj-$(CONFIG_PM) += augentix_aon_rtc.o
obj-$(CONFIG_PM) += sleep_asm.o
obj-$(CONFIG_PM) += sleep.o
AFLAGS_sleep_asm.o := -march=armv7-a -fpic
AFLAGS_sleep.o := -march=armv7-a -fpic
endif