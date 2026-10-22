#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x10
#define SENSOR_I2C_SLAVE_ADDR1 0x10
#else
#define SENSOR_I2C_SLAVE_ADDR 0x10
#endif

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_4096_3072_5fps_2lane
// #define SET_1920_1080_30fps_4lane // need to be fixed

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
