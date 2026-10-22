#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_dev.h"

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x30
#define SENSOR_I2C_SLAVE_ADDR1 0x30
#else
#define SENSOR_I2C_SLAVE_ADDR 0x30
#endif

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#if defined(CONFIG_PROD_AGT800_40)
#define SET_2560_1440_30fps_4lane_SHDR
#else
// #define SET_2880_1624_25fps_4lane_SHDR
// #define SET_2560_1440_30fps_4lane_SHDR
#define SET_2880_1624_15fps_2lane_SHDR
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
