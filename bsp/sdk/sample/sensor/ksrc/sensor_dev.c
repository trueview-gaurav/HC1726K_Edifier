/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include "sensor_dev.h"

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/printk.h>
#include <linux/i2c.h>

#include "mpi_senif.h"

#include "sensor_pm.h"

#define DRV_NAME "sensor"

struct sensor_drv_data *sensor_priv_data = NULL;

static const struct sensor_pm_ops k_sensor_cb = {
	.sensor_suspend_callback = sensor_suspend,
	.sensor_resume_callback = sensor_resume,
};

static void (*sensor_init_path[MPI_MAX_INPUT_PATH_NUM])(struct sensor_info *) = {
#ifdef SNS0
	sns0_init_data,
#else
	NULL,
#endif
#ifdef SNS1
	sns1_init_data,
#else
	NULL,
#endif
#ifdef SNS2
	sns2_init_data,
#else
	NULL,
#endif
#ifdef SNS3
	sns3_init_data,
#else
	NULL,
#endif
};

// initialize the kernel sensor driver
static int __init sensor_init(void)
{
	int i;
	int ret = 0;
	struct i2c_adapter *i2c_adap = NULL;

	// Prevent unused variable warning for products not supporting power management
	(void)ret;

	// Acquire the I2C adapter/bus, we force it to use I2C 0 for now.
	i2c_adap = i2c_get_adapter(0);
	if (i2c_adap == NULL) {
		printk(KERN_WARNING "[Warning][Sensor] Cannot acquire I2C device.\n");
	}

	// Allocate data for the sensors.
	sensor_priv_data = kzalloc(sizeof(*sensor_priv_data), GFP_KERNEL);
	if (!sensor_priv_data) {
		printk(KERN_ERR "[Error][Sensor] Unable to allocate internal memory for the sensor driver.\n");
		goto top_allocate_failed;
	}
	for (i = 0; i < SENSOR_NUM; ++i) {
		void *tmp = kzalloc(sizeof(sensor_priv_data->sensor_info[0]), GFP_KERNEL);
		if (!tmp) {
			printk(KERN_ERR "[Error][Sensor] Unable to allocate internal memory for sensor %d.\n", i);
			goto internal_failed;
		}
		sensor_priv_data->sensor_info[i] = tmp;
		sensor_priv_data->sensor_info[i]->i2c_adapter = i2c_adap;
		if (sensor_init_path[i]) {
			sensor_init_path[i](sensor_priv_data->sensor_info[i]);
		}
	}
	if (i2c_adap) {
		i2c_put_adapter(i2c_adap);
		i2c_adap = NULL;
	}

	// Pass the callback functions to mpp
	// MPP only provides callback for power management only if kernel also provides this option.
#ifdef CONFIG_PM_SLEEP
	ret = sensor_register_pm_cb(&k_sensor_cb);
	if (ret) {
		printk(KERN_ERR "[Error][Sensor] Unable to send callback functions to mpp.\n");
		goto internal_failed;
	}
#endif

	printk(KERN_DEBUG "[Debug][Sensor] Successfully initialized the sensor driver.\n");

	return 0;

internal_failed:
	if (sensor_priv_data) {
		for (i = 0; i < MPI_MAX_INPUT_PATH_NUM; ++i) {
			if (sensor_priv_data->sensor_info[i]) {
				kfree(sensor_priv_data->sensor_info[i]);
			}
		}
		kfree(sensor_priv_data);
		sensor_priv_data = NULL;
	}

top_allocate_failed:
	if (i2c_adap) {
		i2c_put_adapter(i2c_adap);
		i2c_adap = NULL;
	}
	return -1;
}
module_init(sensor_init);

// destroy the kernel sensor driver
static void __exit sensor_exit(void)
{
	int i;
	int ret = 0;

	// Prevent unused variable warning for products not supporting power management
	(void)ret;

	// Unregister the callback functions from mpp
#ifdef CONFIG_PM_SLEEP
	ret = sensor_unregister_pm_cb();
	if (ret) {
		printk(KERN_WARNING "[Warning][Sensor] Kernel sensor driver might not be unregistered correctly.\n");
	}
#endif

	if (sensor_priv_data) {
		for (i = 0; i < MPI_MAX_INPUT_PATH_NUM; ++i) {
			if (sensor_priv_data->sensor_info[i]) {
				kfree(sensor_priv_data->sensor_info[i]);
			}
		}
		kfree(sensor_priv_data);
		sensor_priv_data = NULL;
	}

	printk(KERN_DEBUG "[Debug][Sensor] Complete removing the sensor driver.\n");
}
module_exit(sensor_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eugene Lee");
