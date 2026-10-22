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

#include "mpi_limits.h"

#include "sensor_dev.h"

static int (*sensor_suspend_path[MPI_MAX_INPUT_PATH_NUM])(struct sensor_info *) = {
#ifdef SNS0
	sns0_suspend,
#else
	NULL,
#endif
#ifdef SNS1
	sns1_suspend,
#else
	NULL,
#endif
#ifdef SNS2
	sns2_suspend,
#else
	NULL,
#endif
#ifdef SNS3
	sns3_suspend,
#else
	NULL,
#endif
};

static int (*sensor_resume_path[MPI_MAX_INPUT_PATH_NUM])(struct sensor_info *) = {
#ifdef SNS0
	sns0_resume,
#else
	NULL,
#endif
#ifdef SNS1
	sns1_resume,
#else
	NULL,
#endif
#ifdef SNS2
	sns2_resume,
#else
	NULL,
#endif
#ifdef SNS3
	sns3_resume,
#else
	NULL,
#endif
};

/**
 * @brief Suspend the target sensor.
 *
 * @param path_idx Index of the sensor, or -1 to suspend every sensor.
 * @return 0 if Succeeded, otherwise failed.
 */
int sensor_suspend(int path_idx)
{
	int ret = 0;

	// path index limit, -1 is ok to suspend every existing sensor
	if (path_idx < -1 || path_idx >= MPI_MAX_INPUT_PATH_NUM) {
		printk(KERN_ERR "[Error][Sensor] Invalid path index %d.\n", path_idx);
		return -EINVAL;
	}
	// internal data
	if (!sensor_priv_data || !(sensor_priv_data->sensor_info[path_idx])) {
		printk(KERN_ERR "[Error][Sensor] Internal driver data for sensor %d is not well-prepared.\n", path_idx);
		return -ENOMEM;
	}

	// Suspend the sensor
	if (path_idx == -1) {
		int i;
		// Suspend every sensor
		// Although the indices of the sensors or the functions should be set by order, we still check is there's a valid function for each possible path.
		for (i = 0; i < MPI_MAX_INPUT_PATH_NUM; ++i) {
			if (sensor_suspend_path[i]) {
				int tmp_ret = 0;
				tmp_ret = sensor_suspend_path[i](sensor_priv_data->sensor_info[i]);
				if (tmp_ret) {
					ret = tmp_ret;
				}
			}
		}
	} else {
		// Suspend the target sensor
		if (!sensor_suspend_path[path_idx]) {
			printk(KERN_ERR "[Error][Sensor] Suspension function for sensor %d is not implemented.\n",
			       path_idx);
			return -ENODEV;
		}

		ret = sensor_suspend_path[path_idx](sensor_priv_data->sensor_info[path_idx]);
	}

	return ret;
}

/**
 * @brief Resume the target sensor.
 *
 * @param path_idx Index of the sensor, or -1 to suspend every sensor.
 * @return 0 if Succeeded, otherwise failed.
 */
int sensor_resume(int path_idx)
{
	int ret;

	// path index limit
	if (path_idx < -1 || path_idx >= MPI_MAX_INPUT_PATH_NUM) {
		printk(KERN_ERR "[Error][Sensor] Invalid path index %d.\n", path_idx);
		return -EINVAL;
	}
	// internal data
	if (!sensor_priv_data || !(sensor_priv_data->sensor_info[path_idx])) {
		printk(KERN_ERR "[Error][Sensor] Internal driver data for sensor %d is not well-prepared.\n", path_idx);
		return -ENOMEM;
	}

	// Resume the sensor
	if (path_idx == -1) {
		int i;
		// Resume every sensor
		// Although the indices of the sensors or the functions should be set by order, we still check is there's a valid function for each possible path.
		for (i = 0; i < MPI_MAX_INPUT_PATH_NUM; ++i) {
			if (sensor_resume_path[i]) {
				int tmp_ret = 0;
				tmp_ret = sensor_resume_path[i](sensor_priv_data->sensor_info[i]);
				if (tmp_ret) {
					ret = tmp_ret;
				}
			}
		}
	} else {
		// Resume the target sensor
		if (!sensor_resume_path[path_idx]) {
			printk(KERN_ERR "[Error][Sensor] Resuming function for sensor %d is not implemented.\n",
			       path_idx);
			return -ENODEV;
		}

		ret = sensor_resume_path[path_idx](sensor_priv_data->sensor_info[path_idx]);
	}

	return ret;
}
