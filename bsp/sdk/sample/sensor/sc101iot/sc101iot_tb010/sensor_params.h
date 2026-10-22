#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define SENSOR_I2C_SLAVE_ADDR 0x68

#define SENSOR_I2C_REG_LENGTH 1
#define SENSOR_I2C_DAT_LENGTH 1

#define SENSOR_EXT_CLK_FREQ 24000000

#define SENSOR_ROTATE_IMG 1 // rotate image by 180 degrees

#define SENSOR_DVP_BIT_WIDTH MPI_BITS_8

#define SET_1280_720_15fps // 36Mpx/s

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
