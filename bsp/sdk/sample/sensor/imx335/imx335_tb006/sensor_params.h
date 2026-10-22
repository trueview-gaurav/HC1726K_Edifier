#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x1a
#define SENSOR_I2C_SLAVE_ADDR1 0x1a
#else
#define SENSOR_I2C_SLAVE_ADDR 0x1a
#endif

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#define SENSOR_ROTATE_IMG 0 // rotate image by 180 degrees

#define SET_2592_1944_30fps_2lane
// #define SET_2592_1944_30fps_4lane

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
