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

// Behaviors of SNS_MASTER_OUTPUT_FSYNC and SNS_SLAVE_OUT_OF_SYNC are defined in sensor_ctrl.c and sensor_cmos.c
#ifdef DUAL_SENSOR_SUPPORT
#ifdef SNS0
#define SET_1280_720_30FPS_1LANE
#define SNS_MASTER_OUTPUT_FSYNC
#endif
#ifdef SNS1
#define SET_1280_720_30FPS_1LANE_SLAVE
#define SNS_SLAVE_OUT_OF_SYNC
#endif
#else
// #define SET_1280_720_60FPS_1LANE
#define SET_1280_720_30FPS_1LANE
// #define SET_1280_720_30FPS_1LANE_SLAVE
#endif

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
