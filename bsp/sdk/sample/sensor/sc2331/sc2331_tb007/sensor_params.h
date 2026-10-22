#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// Note: Slave addresses may need to be changed to fit the actual hardware layout
#define SENSOR_I2C_SLAVE_ADDR 0x30
#define SENSOR_I2C_SLAVE_ADDR1 0x32

#define SET_1920_1080_30fps_2lane

#define SENSOR_EXT_CLK_FREQ 24000000

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
