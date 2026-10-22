#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_I2C_SLAVE_ADDR 0x30
#define SENSOR_I2C_SLAVE_ADDR1 0x31
#define SENSOR_I2C_SLAVE_ADDR2 0x32

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_RSTB_PIN (35)
#define SENSOR_PWDN_PIN (34)

#define SENSOR_EXT_CLK_FREQ 24000000

#ifdef CONFIG_PSEUDO_THREE_SENSOR

#ifdef SNS0
#define SET_1920_1080_10fps_2lane_PSEUDO_MASTER
#define SNS_MASTER_OUTPUT_FSYNC
#define SNS_SWITCH_MASTER
#elif defined(SNS1)
#define SET_1920_1080_10fps_2lane_PSEUDO_SLAVE
#define SNS_SLAVE_OUT_OF_SYNC
#elif defined(SNS2)
#define SET_1920_1080_10fps_2lane_PSEUDO_SLAVE
#define SNS_SLAVE_OUT_OF_SYNC
#define SNS_SLAVE_OUT_OF_SYNC2
#endif

#elif defined CONFIG_PSEUDO_TWO_SENSOR
// Settings for 2 sensors with MIPI switch
#ifdef SNS0
#define SET_1920_1080_15fps_2lane_PSEUDO_MASTER
#define SNS_MASTER_OUTPUT_FSYNC
#define SNS_SWITCH_MASTER
#elif defined(SNS1)
#define SET_1920_1080_15fps_2lane_PSEUDO_SLAVE
#define SNS_SLAVE_OUT_OF_SYNC
#endif

#else

// Default case for other products.
#define SET_1920_1080_30fps_2lane

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
