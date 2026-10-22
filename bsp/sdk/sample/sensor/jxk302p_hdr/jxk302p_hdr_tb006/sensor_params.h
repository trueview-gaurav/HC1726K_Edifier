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

// #define SET_2688_1520_30fps_hdr_nonVC_4lane
#define SET_2688_1520_15fps_hdr_nonVC_2lane

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
