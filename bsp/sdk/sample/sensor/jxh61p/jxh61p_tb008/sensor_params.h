#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x40
#define SENSOR_I2C_SLAVE_ADDR1 0x42
extern int g_i2c_fd[2];
#else
#define SENSOR_I2C_SLAVE_ADDR 0x40
extern int g_i2c_fd[1];
#endif

#define SENSOR_I2C_REG_LENGTH 1
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_1280_720_30fps_1lane 0
#define SET_1280_720_50fps_1lane 0
#define SET_1280_720_60fps_1lane 1

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
