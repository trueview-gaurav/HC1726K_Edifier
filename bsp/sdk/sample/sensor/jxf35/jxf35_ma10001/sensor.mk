SENSOR_NUM=2

SNS_INI := sensor_single.ini
PWR_ON_SCRIPT := sensor_power_on.sh

ifeq ($(SENSOR_NUM), 2)
	SNS_INI := sensor_dual.ini
	DEF += -DDUAL_SENSOR_SUPPORT
endif

