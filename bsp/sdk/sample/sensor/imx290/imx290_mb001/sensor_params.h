#ifndef SENSOR_PARAMS_H_
#define SENSOR_PARAMS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#ifdef DUAL_SENSOR_SUPPORT
#define SENSOR_I2C_SLAVE_ADDR 0x1A
#define SENSOR_I2C_SLAVE_ADDR1 0x1A
#else
#define SENSOR_I2C_SLAVE_ADDR 0x1A
#endif

#define SENSOR_EXT_CLK_FREQ 37125000


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SENSOR_PARAMS_H_ */
