#include "sensor_ctrl.h"

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/i2c.h>
#include <linux/gpio.h>

#include "sensor_dev.h"

#define I2C_CMD_MAX_LEN (32) // Related to maximum buffer size in the underlying hardware

int sensor_gpio_ctrl(int gpio_id, int level)
{
	int ret = 0;

	if (!gpio_is_valid(gpio_id)) {
		printk(KERN_ERR "[Error][Sensor] Invalid GPIO ID %d.\n", gpio_id);
		return -EINVAL;
	}

	ret = gpio_request(gpio_id, "SENSOR");
	if (ret < 0) {
		printk(KERN_ERR "[Error][Sensor] Request GPIO-%d failed.\n", gpio_id);
		return ret;
	}
	ret = gpio_direction_output(gpio_id, level);
	gpio_free(gpio_id);
	if (ret < 0) {
		printk(KERN_ERR "[Error][Sensor] Failed to control GPIO-%d.\n", gpio_id);
		return ret;
	}

	return 0;
}

int sensor_i2c_send(struct sensor_info *sensor_info, const u8 *cmd, int cmd_len)
{
	struct i2c_msg msg;
	u8 i2c_cmd[I2C_CMD_MAX_LEN] = { 0 };
	int cmd_size = 0;
	int max_single_cmd_len = 0;
	int cmd_offset = 0;
	int ret = 0;

	if (!sensor_info || !cmd) {
		printk(KERN_ERR "[Error][Sensor] Invalid data pointer.\n");
		return -EINVAL;
	}
	if (sensor_info->i2c_adapter == NULL) {
		printk(KERN_ERR "[Error][Sensor] I2C client not registered.\n");
		return -ENODEV;
	}

	cmd_size = sensor_info->device_info.reg_address_length + sensor_info->device_info.reg_data_length;
	if (cmd_size < 2 || cmd_size > I2C_CMD_MAX_LEN - 1) {
		printk(KERN_WARNING "[Error][Sensor] Unsupported command size %d.\n", cmd_size);
		return -EINVAL;
	}
	if (cmd_len % cmd_size != 0) {
		printk(KERN_WARNING "[Warning][Sensor] Unexpected command length %d.\n", cmd_len);
		cmd_len = cmd_len / cmd_size * cmd_size;
	}
	i2c_cmd[0] = cmd_size;
	max_single_cmd_len = (I2C_CMD_MAX_LEN - 1) / cmd_size * cmd_size;

	msg.addr = sensor_info->device_info.slave_address;
	msg.flags = I2C_M_NOSTART; // This flag is crucial for this message format
	msg.buf = i2c_cmd;
	while (cmd_offset < cmd_len) {
		int remainding_cmd = cmd_len - cmd_offset;
		int curr_cmd_length = min(max_single_cmd_len, remainding_cmd);

		memcpy(&i2c_cmd[1], &cmd[cmd_offset], curr_cmd_length);
		msg.len = curr_cmd_length + 1;
		ret = i2c_transfer(sensor_info->i2c_adapter, &msg, 1);
		if (ret != 1) {
			printk(KERN_ERR "[Error][Sensor] Cannot send I2C commands, err = %d.\n", ret);
			return ret;
		}
		cmd_offset += curr_cmd_length;
	}

	return 0;
}
