#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_I2C_SLAVE_ADDR 0x3c
#define SENSOR_I2C_SLAVE_ADDR1 0x3c
#define SENSOR_I2C_SLAVE_ADDR2 0x3c

#ifdef SNS0
#define SET_1920_1080_15fps_2lane_PSEUDO_MASTER
#define SNS_MASTER_OUTPUT_FSYNC
#define SET_1920_1080_20fps_2lane
#elif defined(SNS1)
#define SET_1920_1080_15fps_2lane_PSEUDO_SLAVE
#define SNS_SLAVE_OUT_OF_SYNC
#elif defined(SNS2)
#define SET_1920_1080_15fps_2lane_PSEUDO_MASTER
#else
#define SET_1920_1080_20fps_2lane
#endif

#define SENSOR_I2C_REG_LENGTH 1
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
