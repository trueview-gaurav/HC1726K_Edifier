#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_RSTB_PIN (49)
#define SENSOR_PWDN_PIN (48)

#define SENSOR_I2C_SLAVE_ADDR 0x30

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_2048_1536_30fps_1lane 0
#define SET_2048_1536_30fps_2lane 1
#define SET_2048_1536_1fps_2lane 0
#define SET_768_768_120fps_2lane 0

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
