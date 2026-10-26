# List files required for augentix video driver

obj-$(CONFIG_AUGENTIX_FASTBOOT) += is.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += is_kernel_ctrl.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += is_da.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += senif.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += agtx_video.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += board_early_video.o

SENSOR_INC = $(srctree)/drivers/sensor

ccflags-y += -I$(src) -I$(SENSOR_INC) -I$(src)/include -include $(srctree)/arch/arm/mach-augentix/include/mach/fastboot_common.h
ccflags-y += -I$(srctree)/arch/arm/mach-augentix/include/mach
ccflags-$(CONFIG_AUGENTIX_SOC_SAPPORO) += -I$(srctree)/arch/arm/mach-augentix/sapporo
ccflags-$(CONFIG_AUGENTIX_SOC_KYOTO) += -I$(srctree)/arch/arm/mach-augentix/kyoto
