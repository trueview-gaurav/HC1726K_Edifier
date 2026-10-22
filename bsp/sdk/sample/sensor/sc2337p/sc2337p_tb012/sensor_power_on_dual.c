#ifdef __UBOOT__
#include <common.h>
#include <asm-generic/gpio.h>
#endif

#include "sensor_comm.h"
#include "sensor_params.h"

// GPIOs are determined by the machine.
#define SENSOR_RSTB_PIN (35)
#define SENSOR_PWDN_PIN (34)

void sensor_power_up()
{
	/*
	 * Sensor 1 should have been powered up by the circuits
	 * Soft reset Sensor 1 if it has already been configured
	 */
	i2c_set_bus_num(0);
	SensCmd i2c_cmd_sns1 = { .reg = 0x0103, .val = 0x01 };
	i2c_write_seq(SENSOR_I2C_SLAVE_ADDR1, &i2c_cmd_sns1, 1, 2, 1);
	udelay(10);

	/* Power down Sensor 0 */
	gpio_direction_output(SENSOR_RSTB_PIN, 0);

	/* Change Sensor 1's I2C slave address */
	i2c_set_bus_num(0);
	SensCmd i2c_cmd_dft = { .reg = 0x3004, .val = (SENSOR_I2C_SLAVE_ADDR1 * 2) };
	i2c_write_seq(SENSOR_I2C_SLAVE_ADDR, &i2c_cmd_dft, 1, 2, 1);

	/* Power up Sensor 0 */
	gpio_set_value(SENSOR_RSTB_PIN, 1);
}
