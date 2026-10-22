#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_I2C_SLAVE_ADDR 0x40
#define SENSOR_I2C_SLAVE_ADDR1 0x42
#define SENSOR_I2C_SLAVE_ADDR2 0x44

#define SENSOR_I2C_REG_LENGTH 1
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

// 1280x720@60fps, 1 lane
#define SET_1280_720_60fps_1lane 0
#define SET_1280_720_30fps_1lane 0
#define SET_1280_720_15fps_1lane_S2 1
#define SET_1280_720_15fps_1lane_S3 0

#if SET_1280_720_15fps_1lane_S2
#ifdef SNS0
#define SET_1280_720_15fps_1lane_S2_MASTER 1
#elif defined(SNS1)
#define SET_1280_720_15fps_1lane_S2_SLAVE 1
#endif
#endif

#if SET_1280_720_15fps_1lane_S3
#ifdef SNS0
#define SET_1280_720_15fps_1lane_S3_MASTER 1
#elif defined(SNS1)
#define SET_1280_720_15fps_1lane_S3_SLAVE1 1
#elif defined(SNS2)
#define SET_1280_720_15fps_1lane_S3_SLAVE2 1
#endif
#endif

#ifndef SET_1280_720_15fps_1lane_S2_MASTER
#define SET_1280_720_15fps_1lane_S2_MASTER 0
#endif

#ifndef SET_1280_720_15fps_1lane_S2_SLAVE
#define SET_1280_720_15fps_1lane_S2_SLAVE 0
#endif

#ifndef SET_1280_720_15fps_1lane_S3_MASTER
#define SET_1280_720_15fps_1lane_S3_MASTER 0
#endif

#ifndef SET_1280_720_15fps_1lane_S3_SLAVE1
#define SET_1280_720_15fps_1lane_S3_SLAVE1 0
#endif

#ifndef SET_1280_720_15fps_1lane_S3_SLAVE2
#define SET_1280_720_15fps_1lane_S3_SLAVE2 0
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
