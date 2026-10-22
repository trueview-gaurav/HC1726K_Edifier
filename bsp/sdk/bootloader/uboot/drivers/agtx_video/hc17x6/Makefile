# List files required for augentix video driver

obj-$(CONFIG_FASTBOOT) += is.o
obj-$(CONFIG_FASTBOOT) += is_kernel_ctrl.o
obj-$(CONFIG_FASTBOOT) += is_da.o
obj-$(CONFIG_FASTBOOT) += senif.o
obj-$(CONFIG_FASTBOOT) += agtx_video.o
obj-$(CONFIG_FASTBOOT) += board_early_video.o

SENSOR_INC = $(srctree)/drivers/sensor

ccflags-y += -I$(src)/include -I$(SENSOR_INC)


