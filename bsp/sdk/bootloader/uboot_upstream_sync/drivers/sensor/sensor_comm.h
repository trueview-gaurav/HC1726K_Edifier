/*
 * sensor_comm.h: Functions for communicating with the sensor.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_SENSOR_COMM_H_
#define UBOOT_SENSOR_COMM_H_

#include <linux/types.h>

#include "sensor.h"

#define SENSOR_DELAY_REG (0xFFFF)

/* I2C */
/**
 * @brief Update sensor's registers through I2C
 *
 * @param slave_addr I2C slave address of the target sensor.
 * @param cmd { register, value } pairs of the commands.
 * @param num_of_write Length of the commands.
 * @param addr_len Length of the register address.
 * @param data_len Length of the register data.
 * @return Number of commands successfully written.
 */
int i2c_write_seq(int slave_addr, const SensCmd *cmd, int num_of_write, int addr_len, int data_len);

#endif // UBOOT_SENSOR_COMM_H_
