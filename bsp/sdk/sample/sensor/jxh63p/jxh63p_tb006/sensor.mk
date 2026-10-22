# assume SENSOR0 is always filled
SENSOR_NUM :=1
ifneq ($(SENSOR1),)
SENSOR_NUM := 2
endif

SNS_INI := sensor_single.ini
PWR_ON_SCRIPT := sensor_power_on.sh

ifeq ($(SENSOR_NUM), 2)
	DEF += -DDUAL_SENSOR_SUPPORT
endif
