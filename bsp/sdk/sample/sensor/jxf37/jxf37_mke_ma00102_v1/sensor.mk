SENSOR_NUM=1

SNS_INI := sensor_single.ini
LVDS_DT_HEADER := lvds-single.h
PWR_ON_SCRIPT := sensor_power_on.sh

ifeq ($(SENSOR_NUM), 2)
	SNS_INI := sensor_dual.ini
	LVDS_DT_HEADER := lvds-dual.h
	DEF += -DDUAL_SENSOR_SUPPORT
endif

