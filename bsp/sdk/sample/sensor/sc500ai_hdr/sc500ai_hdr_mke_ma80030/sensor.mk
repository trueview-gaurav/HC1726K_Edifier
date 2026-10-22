#Sensor options
SENSOR_NUM=1

SNS_INI := sensor_single.ini
PWR_ON_SCRIPT := sensor_power_on.sh

ifeq ($(SENSOR_NUM), 2)
	SNS_INI := sensor_dual.ini
	DEF += -DDUAL_SENSOR_SUPPORT
endif

ifeq ($(CONFIG_PROD_AGT800_30), y)
	CFLAGS += -DCONFIG_PROD_AGT800_30
else ifeq ($(CONFIG_PROD_AGT800_34), y)
	CFLAGS += -DCONFIG_PROD_AGT800_34
endif
