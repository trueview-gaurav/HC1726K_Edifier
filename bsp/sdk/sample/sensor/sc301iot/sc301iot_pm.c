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

// Suspend method
#define SUSPEND_GPIO // Use GPIO to suspend/resume the sensor
// #define SUSPEND_I2C // Use I2C to suspend/resume the sensor

/**
 * @brief Suspend function for this sensor.
 *
 * @param sensor_info Pre-allocated information for this sensor.
 * @return 0 if succeeded, otherwise failed.
 */
int sc301iot_suspend(struct sensor_info *sensor_info)
{
	int ret = 0;

#ifdef SUSPEND_GPIO
	ret = sensor_gpio_ctrl(sensor_info->device_info.power_down_gpio_id, 0);
#endif

#ifdef SUSPEND_I2C
	u8 i2c_cmd[] = { 0x01, 0x00, 0x00 };
	int cmd_len = sizeof(i2c_cmd) / sizeof(i2c_cmd[0]);

	ret = sensor_i2c_send(sensor_info, i2c_cmd, cmd_len);
#endif

	return ret;
}

/**
 * @brief Resume function for this sensor.
 *
 * @param sensor_info Pre-allocated information for this sensor.
 * @return 0 if succeeded, otherwise failed.
 */
int sc301iot_resume(struct sensor_info *sensor_info)
{
	int ret = 0;

#ifdef SUSPEND_GPIO
	ret = sensor_gpio_ctrl(sensor_info->device_info.power_down_gpio_id, 1);
#endif

#ifdef SUSPEND_I2C
	u8 i2c_cmd[] = { 0x01, 0x00, 0x01 };
	int cmd_len = sizeof(i2c_cmd) / sizeof(i2c_cmd[0]);

	ret = sensor_i2c_send(sensor_info, i2c_cmd, cmd_len);
#endif

	return ret;
}

/**
 * @brief Initialize the internal data for this sensor.
 * @note Macros inside this function will be converted to constants by codegen. But they need to be defined in sensor_params.h.
 *
 * @param sensor_info Information for this sensor that will be stored.
 */
void sc301iot_init_data(struct sensor_info *sensor_info)
{
	// device info
	sensor_info->device_info.slave_address = SENSOR_I2C_SLAVE_ADDR;
	sensor_info->device_info.reg_address_length = SENSOR_I2C_REG_LENGTH;
	sensor_info->device_info.reg_data_length = SENSOR_I2C_DAT_LENGTH;
	sensor_info->device_info.power_down_gpio_id = SENSOR_PWDN_PIN;
	sensor_info->device_info.reset_gpio_id = SENSOR_RSTB_PIN;
}
