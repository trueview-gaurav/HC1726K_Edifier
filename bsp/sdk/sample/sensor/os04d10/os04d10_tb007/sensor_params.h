#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_I2C_SLAVE_ADDR 0x3c

#define SENSOR_I2C_REG_LENGTH 1
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_2560_1440_30fps_2lane 1
#define SET_2568_1448_30fps_2lane 0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
