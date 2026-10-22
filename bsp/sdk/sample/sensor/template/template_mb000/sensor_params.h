/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/* sensor_params.h - Other information of the sensor.
 * Information like Slave Address, streaming settings,
 * or other kinds of things that need to be shared accross files in the sensor driver.
 */

#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#include "sensor.h"

#define SENSOR_I2C_SLAVE_ADDR (0x00)
#define SENSOR_I2C_REG_LENGTH (2)
#define SENSOR_I2C_DAT_LENGTH (1)

#define SET_1920_1080_30fps_2lane // The characteristics (resolution, fps, etc.) for this macro is inside sensor_settings.h

#define SENSOR_EXT_CLK_FREQ 24000000

#endif /* SENSOR_PARAMS_H_ */
