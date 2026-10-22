SENSOR_NUM=1

SNS_INI := sensor_single.ini
PWR_ON_SCRIPT := sensor_power_on.sh
MIPI_LP := y

ifeq ($(SENSOR_NUM), 2)
	SNS_INI := sensor_dual.ini
	DEF += -DDUAL_SENSOR_SUPPORT
endif

ifeq ($(MIPI_LP), y)
	DEF += -DMIPI_LP
endif

