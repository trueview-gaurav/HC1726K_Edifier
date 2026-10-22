obj-y	+= cpu.o
obj-y	+= interrupts.o

ifndef CONFIG_SKIP_LOWLEVEL_INIT
obj-y	+= lowlevel_init.o
endif

CPVS_INC = ../../../sdk/core/cpvs/include
CPVS_LIB = ../../../sdk/core/cpvs/lib
ccflags-y = -I$(CPVS_INC) -I$(CPVS_INC)/csr -I$(CPVS_INC)/uart -I$(CPVS_INC)/utils -I./include -I./include/linux -I../../../buildroot/output/build/bearssl-0.6/inc
LDFLAGS += -L$(CPVS_LIB) -lpid -lutil
UBOOT_IMG = $(srctree)/u-boot.bin

ifneq ("$(wildcard $(UBOOT_IMG))","")
IMG_SIZE=$(shell stat -c%s $(UBOOT_IMG))
SIZE_ALIGN_4=$$((($(IMG_SIZE) + 4 - 1) & (~(4 - 1))))
KBUILD_CFLAGS += -DUBOOT_FILESIZE=$(SIZE_ALIGN_4)
endif

obj-$(CONFIG_SPL_BUILD) += machine.o
obj-$(CONFIG_SPL_BUILD) += board_pinmux.o
obj-$(CONFIG_SPL_BUILD) += spl.o

