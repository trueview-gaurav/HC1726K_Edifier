#ifndef CUSTOM_SENSOR_H_
#define CUSTOM_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#include <stdint.h>

#include "mpi_dip_sns.h"
#include "sensor_types.h"
#include "sensor_log.h"

#define _custom_sns(a)             custom_sns_##a
#define  custom_sns(a)            _custom_sns(a)

#define _cmos_ctrl(a)              cmos_ctrl_##a
#define  cmos_ctrl(a)             _cmos_ctrl(a)

// I2V dev node
#define SENSOR_I2C_DEV_NODE        "/dev/i2c-1"
#define SENSOR_I2C_DEV_NODE0       "/dev/i2c-0"

#define SENSOR_DELAY_REG (0xFFFF)

// Sensor format
#define HALFHD                     0x30
#define FULLHD                     0x31
#define SQUARE                     0x32
#define FULLHD_4M                  0x33
#define FULLHD_3M                  0x34

// Sensor interface protocol
#define DVP                        0
#define MIPI                       1
#define SONYLVDS                   2
#define HISPI_S_S                  3
#define HISPI_S_SP                 4
#define HISPI_P_SP                 5
#define PANASONICLVDS              6

// Sensor interface lane
#define SINGLE_LANE                0
#define DUAL_LANE                  1
#define QUAD_LANE                  2

// Sensor operation mode
#define SLAVE                      0x20
#define MASTER                     0x21

// Sensor output bit width
#define OP10BIT                    0x40
#define OP12BIT                    0x41


/* I2C device node interface */
int SENSOR_openI2cDev(int *i2c_fd, uint16_t slave_addr);
int SENSOR_closeI2cDev(int i2c_fd);

void SENSOR_printCmd(uint8_t num_of_write, SensCmd *cmd);

/* I2C device data access util */
int SENSOR_readRegWW(int i2c_fd, uint16_t address);
int SENSOR_readRegWB(int i2c_fd, uint16_t address);
int SENSOR_readRegBB(int i2c_fd, uint16_t address);
int SENSOR_writeRegWW(int i2c_fd, uint16_t num_of_write, const SensCmd *cmd);
int SENSOR_writeRegBB(int i2c_fd, uint8_t num_of_write, const SensCmd *cmd);
int SENSOR_writeRegWB(int i2c_fd, uint8_t num_of_write, const SensCmd *cmd);
int SENSOR_writeSeqBaddrBdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr);
int SENSOR_writeSeqWaddrBdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr);
int SENSOR_writeSeqWaddrWdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr);
int SENSOR_writeRegBaddrBdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd);
int SENSOR_writeRegWaddrBdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd);
int SENSOR_writeRegWaddrWdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd);
int SENSOR_getLvdsDelay(uint32_t sns_idx, MPI_SERL_LANE_INFO_S *serl_lane);

/* Sensor control interface */
extern void SENSOR_configInit(uint8_t path_idx);
extern void SENSOR_configExit(uint8_t path_idx);
extern int32_t SENSOR_getOpInfo(uint8_t path_idx, uint32_t sns_idx, MPI_SNS_OP_INFO_S *p_op_info);
#ifdef SNS0
__attribute__((visibility("default"))) extern SENSOR_CMOS_CTRL_S cmos_ctrl(SNS0_ID);
#endif
#ifdef SNS1
__attribute__((visibility("default"))) extern SENSOR_CMOS_CTRL_S cmos_ctrl(SNS1_ID);
#endif
#ifdef SNS2
__attribute__((visibility("default"))) extern SENSOR_CMOS_CTRL_S cmos_ctrl(SNS2_ID);
#endif
#ifdef SNS3
__attribute__((visibility("default"))) extern SENSOR_CMOS_CTRL_S cmos_ctrl(SNS3_ID);
#endif

int binary_search_bin(const int value, const int *x1, const int i0, const int i1);
int binary_search_nr(const int value, const int arr[], const int start, const int end);
int interpolation(const int pix0, const int pix1, const int alpha, const int norm);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CUSTOM_SENSOR_H_ */
