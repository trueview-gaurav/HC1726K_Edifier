# List files required for fastboot sensor driver

obj-$(CONFIG_FASTBOOT) += sensor.o
obj-$(CONFIG_FASTBOOT) += sensor_comm.o
obj-$(CONFIG_FASTBOOT) += exposure.o
obj-$(CONFIG_FASTBOOT) += light_meter.o

obj-$(CONFIG_FASTBOOT) += sensor_ctrl.o
obj-$(CONFIG_FASTBOOT) += sensor_cmos.o
obj-$(CONFIG_FASTBOOT) += sensor_power_on.o

CFLAGS_sensor.o += -DSNS0 -DSNS0_ID=0
CFLAGS_sensor_cmos.o += -DSNS0 -DSNS0_ID=0
CFLAGS_sensor_ctrl.o += -DSNS0 -DSNS0_ID=0
CFLAGS_exposure.o += -DSNS0 -DSNS0_ID=0
CFLAGS_light_meter.o += -DSNS0 -DSNS0_ID=0

ifdef CONFIG_DUAL_SENSOR_SUPPORT
obj-$(CONFIG_FASTBOOT) += sensor_ctrl_1.o
obj-$(CONFIG_FASTBOOT) += sensor_cmos_1.o

CFLAGS_sensor.o += -DSNS1 -DSNS1_ID=1
CFLAGS_sensor_cmos_1.o += -DSNS1 -DSNS1_ID=1
CFLAGS_sensor_ctrl_1.o += -DSNS1 -DSNS1_ID=1
CFLAGS_exposure.o += -DSNS1 -DSNS1_ID=1
CFLAGS_light_meter.o += -DSNS1 -DSNS1_ID=1
endif

