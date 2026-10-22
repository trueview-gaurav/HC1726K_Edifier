# Sensor options
ifneq ($(SENSOR2),)
SENSOR_NUM := 3
else ifneq ($(SENSOR1),)
SENSOR_NUM := 2
else
SENSOR_NUM := 1
endif

SNS_INI := sensor_single.ini

ifeq ($(CONFIG_PROD_AGT706_6),y)
CFLAGS += -DCHIP_HC1706H
PWR_ON_SCRIPT := sensor_power_on_pseudo_3_sensor.sh
DEF += -DCONFIG_PSEUDO_THREE_SENSOR -DDISABLE_SOFT_RESET
else
PWR_ON_SCRIPT := sensor_power_on.sh
endif
