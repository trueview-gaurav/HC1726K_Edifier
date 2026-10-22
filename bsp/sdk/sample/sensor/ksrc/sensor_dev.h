/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SENSOR_DEV_H_
#define SENSOR_DEV_H_

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#include "mpi_limits.h"

/**
 * @brief Device information of the sensor
 */
struct sensor_device_info {
	uint16_t power_down_gpio_id; /**< Index of the GPIO used for powering down. */
	uint16_t reset_gpio_id; /**< Index of the GPIO used for resetting. */
	uint16_t slave_address; /**< I2C slave address */
	uint8_t reg_address_length; /**< Length of the register address in I2C commands. */
	uint8_t reg_data_length; /**< Length of the register data in I2C commands. */
};

/**
 * @brief Internal information for a sensor.
 */
struct sensor_info {
	void *i2c_adapter; /**< Pointer to the I2C client data structure. */
	struct sensor_device_info device_info; /**< Device information. */
};

/**
 * @brief Internal information for each sensor.
 */
struct sensor_drv_data {
	struct sensor_info *sensor_info[MPI_MAX_INPUT_PATH_NUM]; /**< Information of each sensor. */
};

/**
 * @brief Internal data stored inside the driver.
 */
extern struct sensor_drv_data *sensor_priv_data;

#ifdef SNS0
void sns0_init_data(struct sensor_info *sensor_info);
#endif
#ifdef SNS1
void sns1_init_data(struct sensor_info *sensor_info);
#endif
#ifdef SNS2
void sns2_init_data(struct sensor_info *sensor_info);
#endif
#ifdef SNS3
void sns3_init_data(struct sensor_info *sensor_info);
#endif

#endif
