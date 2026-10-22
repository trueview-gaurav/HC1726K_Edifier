#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x40
#define SENSOR_I2C_SLAVE_ADDR1 0x40
extern int g_i2c_fd[2];
#else
#define SENSOR_I2C_SLAVE_ADDR 0x40
extern int g_i2c_fd[1];
#endif

#define SENSOR_I2C_REG_LENGTH 1
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

// 1280x720@30fps, 1 lane, 432Mbps
#define SET_1280_720_30fps_1lane

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
