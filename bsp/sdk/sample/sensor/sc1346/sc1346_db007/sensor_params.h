#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x30
#define SENSOR_I2C_SLAVE_ADDR1 0x31
#else
#define SENSOR_I2C_SLAVE_ADDR 0x30
#endif

#define SET_1280_720_15FPS_1LANE
//#define SET_1280_720_10FPS_1LANE

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
