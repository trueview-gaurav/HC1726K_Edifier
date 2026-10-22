# Sensor options
SENSOR_NUM := 1
ifneq ($(SENSOR1),)
SENSOR_NUM := 2
endif

SNS_INI := sensor_single.ini

ifeq ($(SENSOR_NUM), 2)
	PWR_ON_SCRIPT := sensor_power_on_dual.sh
else
	PWR_ON_SCRIPT := sensor_power_on.sh
endif