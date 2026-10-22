#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x37
#define SENSOR_I2C_SLAVE_ADDR1 0x3F
#else
#define SENSOR_I2C_SLAVE_ADDR 0x37
#endif

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_1920_1080_30fps_2lanes 0
#define SET_1920_1080_30fps_1lanes 1

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
