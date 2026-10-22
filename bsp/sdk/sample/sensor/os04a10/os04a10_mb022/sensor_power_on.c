#ifdef __UBOOT__
#include <common.h>
#endif

#include "sensor_comm.h"

// GPIOs are determined by the machine.
#define SENSOR_RSTB_PIN (49)

void sensor_power_up()
{
	set_gpio_out(SENSOR_RSTB_PIN, 0);
	set_gpio_value(SENSOR_RSTB_PIN, 0);

	set_gpio_value(SENSOR_RSTB_PIN, 1);
	mdelay(5);
}
