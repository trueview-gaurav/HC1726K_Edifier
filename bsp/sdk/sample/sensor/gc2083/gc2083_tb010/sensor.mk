# assume SENSOR0 is always filled
SENSOR_NUM :=1
ifneq ($(SENSOR1),)
SENSOR_NUM := 2
endif

SNS_INI := sensor_single.ini

ifeq ($(SENSOR_NUM), 2)
	PWR_ON_SCRIPT := sensor_power_on_dual.sh
	DEF += -DDISABLE_SOFT_RESET -DDUAL_SENSOR_SUPPORT
else
	PWR_ON_SCRIPT := sensor_power_on.sh
endif

ifeq ($(CONFIG_PROD_AGT706_5),y)
CFLAGS += -DCHIP_HC1706K
else
CFLAGS += -DCHIP_HC1706
endif
