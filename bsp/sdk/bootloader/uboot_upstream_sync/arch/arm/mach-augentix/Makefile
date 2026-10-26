SDKSRC_DIR := $(realpath $(CURDIR)/../../..)
include $(SDKSRC_DIR)/firmware/build/sdksrc.mk

# CONFIG_MACH arrives unquoted from firmware/build/.config through sdksrc.mk.
# define2mk.sed:22 also emits it quoted into include/autoconf.mk.
# CONFIG_ARCH_AUGENTIX is unset during a clean descent.
ifdef CONFIG_ARCH_AUGENTIX
augentix-mach := $(patsubst "%",%,$(CONFIG_MACH))
augentix-ddt  := $(patsubst "%",%,$(CONFIG_DEFAULT_DEVICE_TREE))
ifneq ($(augentix-mach),$(augentix-ddt))
$(error product identity mismatch: SDK CONFIG_MACH=$(augentix-mach) but U-Boot CONFIG_DEFAULT_DEVICE_TREE=$(augentix-ddt))
endif
endif

ccflags-y := -I$(CPVS_INC) -I$(CPVS_INC)/csr -I$(CPVS_INC)/uart -I$(CPVS_INC)/utils \
	     -I$(GEN_INC) -I$(srctree)/arch/arm/mach-augentix/bearssl-0.6/inc
ccflags-y += -DAUGENTIX_CPVS_CONSUMER

# spl_pub_key_mod.h is generated per SoC and includes spl_define.h by bare name.
ccflags-y += -I$(srctree)/arch/arm/mach-augentix/include/mach
ccflags-$(CONFIG_AUGENTIX_SOC_SAPPORO) += -I$(srctree)/arch/arm/mach-augentix/sapporo
ccflags-$(CONFIG_AUGENTIX_SOC_KYOTO)   += -I$(srctree)/arch/arm/mach-augentix/kyoto

# u-boot.bin must exist before the SPL links; UBOOT_FILESIZE is read from it.
UBOOT_IMG = $(objtree)/u-boot.bin
ifneq ("$(wildcard $(UBOOT_IMG))","")
IMG_SIZE = $(shell stat -c%s $(UBOOT_IMG))
KBUILD_CFLAGS += -DUBOOT_FILESIZE=$(shell echo $$(( ($(IMG_SIZE) + 3) & ~3 )))
endif

obj-y += cpu.o
obj-$(CONFIG_AUGENTIX_GIC) += interrupts.o
ifndef CONFIG_XPL_BUILD
obj-$(CONFIG_AUGENTIX_FASTBOOT) += fastboot_mem.o
endif

obj-$(CONFIG_XPL_BUILD) += machine.o
obj-$(CONFIG_XPL_BUILD) += spl.o

obj-$(CONFIG_AUGENTIX_SOC_SAPPORO) += sapporo/
obj-$(CONFIG_AUGENTIX_SOC_KYOTO)   += kyoto/
