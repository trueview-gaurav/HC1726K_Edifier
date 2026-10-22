#ifndef SENSOR_CTRL_H_
#define SENSOR_CTRL_H_

#include <linux/types.h>

#include "sensor_dev.h"

#define I2C_CMD_MAX_LEN (32) // Related to maximum buffer size in the underlying hardware

int sensor_gpio_ctrl(int gpio_id, int level);
int sensor_i2c_send(struct sensor_info *sensor_info, const u8 *cmd, int cmd_len);

#endif
