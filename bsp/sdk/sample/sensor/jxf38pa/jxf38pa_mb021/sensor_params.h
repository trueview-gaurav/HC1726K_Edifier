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

#define SENSOR_EXT_CLK_FREQ 24000000

// 2M@30 1lane: 864Mbps/lane
#define SET_1920_1080_30fps_1lane 1
// 2M@30 2lanes: 432Mbps/lane
#define SET_1920_1080_30fps_2lane 0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
