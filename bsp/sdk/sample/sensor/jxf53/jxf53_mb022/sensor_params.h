#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_I2C_SLAVE_ADDR 0x40
extern int g_i2c_fd[1];

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_1920_1080_30fps_2lanes 1

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
