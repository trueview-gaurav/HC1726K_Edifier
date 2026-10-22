#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x30
#define SENSOR_I2C_SLAVE_ADDR1 0x30
#else
#define SENSOR_I2C_SLAVE_ADDR 0x30
#endif

#define SENSOR_I2C_REG_LENGTH 2
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#define SENSOR_ROTATE_IMG 1 // rotate image by 180 degrees

#define SENSOR_DVP_BIT_WIDTH MPI_BITS_12

// #define SET_2304_1536_30fps // 118.8Mpx/s require further development
// #define SET_1536_1536_30fps // 118.8Mpx/s NYI
#define SET_1536_1536_15fps // 59.4Mpx/s

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
