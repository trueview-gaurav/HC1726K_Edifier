#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x30
#define SENSOR_I2C_SLAVE_ADDR1 0x30
#else
#define SENSOR_I2C_SLAVE_ADDR 0x30
#endif

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_2592_1944_20fps_2lane
// #define SET_2592_1944_25fps_2lane
// #define SET_2560_1440_25fps_2lane // NYI

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
