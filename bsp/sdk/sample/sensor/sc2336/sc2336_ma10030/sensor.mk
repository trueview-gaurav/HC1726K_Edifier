# Sensor options
ifneq ($(SENSOR3),)
SENSOR_NUM := 4
else ifneq ($(SENSOR2),)
SENSOR_NUM := 3
else ifneq ($(SENSOR1),)
SENSOR_NUM := 2
else
SENSOR_NUM := 1
endif

SNS_INI := sensor_single.ini

ifeq ($(CONFIG_PROD_AGT100_30),y)
PWR_ON_SCRIPT := sensor_power_on_pseudo_3_sensor.sh
DEF += -DCONFIG_PSEUDO_THREE_SENSOR -DDISABLE_SOFT_RESET
else ifeq ($(CONFIG_PROD_AGT100_31),y)
PWR_ON_SCRIPT := sensor_power_on_pseudo_3_sensor.sh
DEF += -DCONFIG_PSEUDO_THREE_SENSOR -DDISABLE_SOFT_RESET
else ifeq ($(CONFIG_PROD_AGT725_7),y)
PWR_ON_SCRIPT := sensor_power_on_pseudo_4_sensor.sh
DEF += -DCONFIG_PSEUDO_FOUR_SENSOR -DDISABLE_SOFT_RESET
else
PWR_ON_SCRIPT := sensor_power_on.sh
endif
