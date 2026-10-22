/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor_pm.h"

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/i2c.h>
#include <linux/gpio.h>

#include "sensor_dev.h"
#include "sensor_ctrl.h"

/**
 * @brief Suspend function for this sensor.
 *
 * @param sensor_info Pre-allocated information for this sensor.
 * @return 0 if succeeded, otherwise failed.
 */
int sc431hai_suspend(struct sensor_info *sensor_info)
{
	u8 i2c_cmd[] = { 0x30, 0x2c, 0x0f, 0x01, 0x00, 0x00 };
	int cmd_len = sizeof(i2c_cmd) / sizeof(i2c_cmd[0]);
	int ret = 0;

	ret = sensor_i2c_send(sensor_info, i2c_cmd, cmd_len);
	return ret;
}

/**
 * @brief Resume function for this sensor.
 *
 * @param sensor_info Pre-allocated information for this sensor.
 * @return 0 if succeeded, otherwise failed.
 */
int sc431hai_resume(struct sensor_info *sensor_info)
{
	u8 i2c_cmd[] = { 0x30, 0x2c, 0x00, 0x01, 0x00, 0x01 };
	int cmd_len = sizeof(i2c_cmd) / sizeof(i2c_cmd[0]);
	int ret = 0;

	ret = sensor_i2c_send(sensor_info, i2c_cmd, cmd_len);
	return ret;
}

/**
 * @brief Initialize the internal data for this sensor.
 * @note Macros inside this function will be converted to constants by codegen. But they need to be defined in sensor_params.h.
 *
 * @param sensor_info Information for this sensor that will be stored.
 */
void sc431hai_init_data(struct sensor_info *sensor_info)
{
	// device info
	sensor_info->device_info.slave_address = SENSOR_I2C_SLAVE_ADDR;
	sensor_info->device_info.reg_address_length = 2;
	sensor_info->device_info.reg_data_length = 1;
	sensor_info->device_info.power_down_gpio_id = -1; // N/A
	sensor_info->device_info.reset_gpio_id = SENSOR_RSTB_PIN;
}
