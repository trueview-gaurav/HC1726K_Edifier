#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x37
#define SENSOR_I2C_SLAVE_ADDR1 0x37
#else
#define SENSOR_I2C_SLAVE_ADDR 0x37
#endif

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_1280_720_30fps_1lane 1
#define SET_640_360_60fps_1lane 0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
