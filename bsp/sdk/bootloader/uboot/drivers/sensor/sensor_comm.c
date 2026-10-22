/*
 * sensor_comm.c: Functions for communicating with the sensor.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#include "sensor_comm.h"
#include <i2c.h> // for i2c_write()

int i2c_write_seq(int slave_addr, const SensCmd *cmd, int num_of_write, int addr_len, int data_len)
{
	int i;

	if (slave_addr > 0x7F) {
		return -1; // only 7-bit
	}

	if (num_of_write == 0) {
		return -1;
	}

	for (i = 0; i < num_of_write; i++) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			mdelay(cmd[i].val);
		} else {
			i2c_write(slave_addr, cmd[i].reg, addr_len, (uint8_t *)&cmd[i].val, data_len);
		}
	}

	return num_of_write;
}
