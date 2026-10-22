#ifdef __UBOOT__
#include <common.h>
#include <asm-generic/gpio.h>
#endif

#include "sensor_comm.h"

// GPIOs are determined by the machine.
#define SENSOR_RSTB_PIN 49
#define SENSOR_PWDN_PIN 50

void sensor_power_up()
{
	gpio_direction_output(SENSOR_PWDN_PIN, 1);
	gpio_direction_output(SENSOR_RSTB_PIN, 1);
	udelay(10);

	gpio_set_value(SENSOR_RSTB_PIN, 0);
	udelay(12000);

	gpio_set_value(SENSOR_RSTB_PIN, 1);
	gpio_set_value(SENSOR_PWDN_PIN, 0);

	udelay(400);
}
