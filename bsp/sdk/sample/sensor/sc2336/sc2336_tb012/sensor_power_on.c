#ifdef __UBOOT__
#include <common.h>
#include <asm-generic/gpio.h>
#endif

#include "sensor_comm.h"

// GPIOs are determined by the machine.
#define SENSOR_RSTB_PIN (32)

void sensor_power_up()
{
	printf("[SC2336] sensor_power_up\n");
	gpio_direction_output(SENSOR_RSTB_PIN, 0);
	udelay(1000);
	gpio_set_value(SENSOR_RSTB_PIN, 1);
	udelay(5342);
}
