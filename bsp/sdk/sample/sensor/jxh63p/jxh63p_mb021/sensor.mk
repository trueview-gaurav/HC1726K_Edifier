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
PWR_ON_SCRIPT := sensor_power_on.sh
