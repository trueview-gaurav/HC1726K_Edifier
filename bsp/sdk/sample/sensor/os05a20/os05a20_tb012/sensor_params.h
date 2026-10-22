#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x36
#define SENSOR_I2C_SLAVE_ADDR1 0x10
#else
#define SENSOR_I2C_SLAVE_ADDR 0x36
#endif

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#ifdef SNS0
#define SET_2592_1944_15fps_1lane
#elif defined(SNS1)
#define SET_2560_1440_15fps_1lane
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
