#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_I2C_SLAVE_ADDR 0x40
#define SENSOR_I2C_SLAVE_ADDR1 0x42

#define SENSOR_EXT_CLK_FREQ 24000000

#define SET_1920_1080_30fps_2lane 1
#define SET_1920_1080_125fps_2lane_S2 0
#define SET_1920_1080_10fps_2lane_S2 0

#if SET_1920_1080_125fps_2lane_S2
#ifdef SNS0
#define SET_1920_1080_125fps_2lane_S2_MASTER 1
#elif defined(SNS1)
#define SET_1920_1080_125fps_2lane_S2_SLAVE 1
#endif
#endif

#ifndef SET_1920_1080_125fps_2lane_S2_MASTER
#define SET_1920_1080_125fps_2lane_S2_MASTER 0
#endif

#ifndef SET_1920_1080_125fps_2lane_S2_SLAVE
#define SET_1920_1080_125fps_2lane_S2_SLAVE 0
#endif

#if SET_1920_1080_10fps_2lane_S2
#ifdef SNS0
#define SET_1920_1080_10fps_2lane_S2_MASTER 1
#elif defined(SNS1)
#define SET_1920_1080_10fps_2lane_S2_SLAVE 1
#endif
#endif

#ifndef SET_1920_1080_10fps_2lane_S2_MASTER
#define SET_1920_1080_10fps_2lane_S2_MASTER 0
#endif

#ifndef SET_1920_1080_10fps_2lane_S2_SLAVE
#define SET_1920_1080_10fps_2lane_S2_SLAVE 0
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
