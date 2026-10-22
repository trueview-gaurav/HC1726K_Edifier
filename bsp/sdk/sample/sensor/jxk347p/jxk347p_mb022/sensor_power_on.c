#ifdef __UBOOT__
#include <common.h>
#endif

#include "sensor_comm.h"

// GPIOs are determined by the machine.
#define SENSOR_RSTB_PIN 49
#define SENSOR_PWDN_PIN 50

void sensor_power_up()
{
	set_gpio_out(SENSOR_PWDN_PIN, 0x00000);
	set_gpio_value(SENSOR_PWDN_PIN, 1);
	set_gpio_out(SENSOR_RSTB_PIN, 0x00000);
	set_gpio_value(SENSOR_RSTB_PIN, 1);
	udelay(1000);
	set_gpio_value(SENSOR_RSTB_PIN, 0);
	udelay(10000);
	set_gpio_value(SENSOR_RSTB_PIN, 1);
	set_gpio_value(SENSOR_PWDN_PIN, 0);
	udelay(400);
}
