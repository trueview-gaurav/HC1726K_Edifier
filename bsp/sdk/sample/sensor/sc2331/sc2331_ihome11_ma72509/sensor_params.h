#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// Note: Slave addresses may need to be changed to fit the actual hardware layout
#define SENSOR_I2C_SLAVE_ADDR 0x30
#define SENSOR_I2C_SLAVE_ADDR1 0x32
#define SENSOR_I2C_SLAVE_ADDR2 0x31

#ifdef SNS0
#define SET_1920_1080_20fps_2lane_PSEUDO_MASTER
#define SET_1920_1080_20fps_2lane
#define SET_1920_1080_20to10fps_2lane
#define SNS_MASTER_OUTPUT_FSYNC
#define SNS_MASTER_MODE
#elif defined(SNS1)
#define SET_1920_1080_20fps_2lane_PSEUDO_SLAVE
#define SET_1920_1080_20fps_2lane
#define SET_1920_1080_20to10fps_2lane
#define SNS_SLAVE_OUT_OF_SYNC
#elif defined(SNS2)
#define SET_1920_1080_20fps_2lane_PSEUDO_MASTER
#define SET_1920_1080_20fps_2lane
#define SET_1920_1080_20to125fps_2lane
#else
#define SET_1920_1080_30fps_2lane
#endif

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
