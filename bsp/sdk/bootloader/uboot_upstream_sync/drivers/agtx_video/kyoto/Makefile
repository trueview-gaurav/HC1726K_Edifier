# List files required for augentix video driver

obj-$(CONFIG_AUGENTIX_FASTBOOT) += senif.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += is.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += is_kernel_ctrl.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += isp_sc.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += isp_pca.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += isp_ccq.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += da.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += agtx_video.o
obj-$(CONFIG_AUGENTIX_FASTBOOT) += board_early_video.o

SENSOR_INC = $(srctree)/drivers/sensor

ccflags-y += -I$(src) -I$(src)/include -I$(SENSOR_INC)
ccflags-y += -include $(srctree)/arch/arm/mach-augentix/include/mach/fastboot_common.h
ccflags-y += -I$(srctree)/arch/arm/mach-augentix/include/mach
