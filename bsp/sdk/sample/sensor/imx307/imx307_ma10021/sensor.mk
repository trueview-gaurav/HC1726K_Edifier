# Sensor options
SENSOR_NUM:=1
ifneq ($(SENSOR1),)
SENSOR_NUM:=2
endif

# overwrite the filenames of IQ parameters and power on script
SNS_INI := sensor_single.ini
PWR_ON_SCRIPT := sensor_power_on.sh

ifeq ($(SENSOR_NUM),2)
DEF += -DDUAL_SENSOR_SUPPORT
endif

# overwrite I2C device/bus usage for specific sensor
ifeq ($(SNS_ID),0)
I2C_FLAG := -DSNS_I2C_0
endif
ifeq ($(SNS_ID),1)
I2C_FLAG := -DSNS_I2C_1
endif
