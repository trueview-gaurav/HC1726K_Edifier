#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x10
#define SENSOR_I2C_SLAVE_ADDR1 0x10
#else
#define SENSOR_I2C_SLAVE_ADDR 0x10
#endif

#define SENSOR_EXT_CLK_FREQ 24000000

#if (FORMAT == FULLHD_4M)
#define SET_2688_1520_30fps_4lane
#elif (FORMAT == FULLHD_3M)
#define SET_2032_1520_25fps_2lane
#else
#if (LANE == SINGLE_LANE)
#define SET_1920_1080_30fps_1lane
#elif (LANE == DUAL_LANE)
#define SET_1920_1080_30fps_2lane
#else /* (LANE == QUAD_LANE) */
#define SET_1920_1080_30fps_4lane
#endif
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
