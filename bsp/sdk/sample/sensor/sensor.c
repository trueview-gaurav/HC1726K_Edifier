#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

/**
 * @brief Open I2C character device for sensor
 *
 * @param[out] i2c_fd Pointer to the opened file descriptor.
 * @param[in] slave_addr Slave address of the device (7 bits).
 *
 * @return Execution result
 * @retval MPI_SUCCESS Success.
 * @retval MPI_FAILURE Error.
 */
int SENSOR_openI2cDev(int *i2c_fd, uint16_t slave_addr)
{
	int fd;

	/* open i2c dev node */
#ifdef SNS_I2C_1
	fd = open(SENSOR_I2C_DEV_NODE, O_RDWR);
	if (fd < 0) {
		sensor_log_warn("Failed to open node i2c-1, trying node i2c-0.");

		fd = open(SENSOR_I2C_DEV_NODE0, O_RDWR);
		if (fd < 0) {
			sensor_log_err("Failed to open both i2c-0 and i2c-1.");
			return MPI_FAILURE;
		}
	}
#else
	fd = open(SENSOR_I2C_DEV_NODE0, O_RDWR);
	if (fd < 0) {
		sensor_log_warn("Failed to open node i2c-0, trying node i2c-1.");

		fd = open(SENSOR_I2C_DEV_NODE, O_RDWR);
		if (fd < 0) {
			sensor_log_err("Failed to open both i2c-0 and i2c-1.");
			return MPI_FAILURE;
		}
	}
#endif

	/* set i2c slave addr */
	if (ioctl(fd, I2C_SLAVE, slave_addr) < 0) {
		int err = errno;
		sensor_log_err("Failed to set I2C slave address, err = %d.", err);
		return MPI_FAILURE;
	}

	*i2c_fd = fd;

	return MPI_SUCCESS;
}

/**
 * @brief Close the I2C device
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 *
 * @return Execution result
 * @retval MPI_SUCCESS Success.
 * @retval MPI_FAILURE Invalid fd number.
 */
int SENSOR_closeI2cDev(int i2c_fd)
{
	if (i2c_fd < 0) {
		return MPI_FAILURE;
	}

	close(i2c_fd);

	return MPI_SUCCESS;
}

/**
 * @brief Log the I2C commands to stdout.
 *
 * @param[in] n Length of cmd.
 * @param[in] cmd I2C commands.
 */
void SENSOR_printCmd(uint8_t n, SensCmd *cmd)
{
	int i;
	for (i = 0; i < n; ++i) {
		printf("[SENS-CMD] REF = %04X, VAL = %04X\n", cmd->reg, cmd->val);
		++cmd;
	}
}

/**
 * @brief Read 2 bytes of data from a sensor with 2-byte addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] reg_addr Address of the register.
 *
 * @return Register data, or error.
 * @retval MPI_FAILURE Error.
 * @retval other Register data.
 */
int SENSOR_readRegWW(int i2c_fd, uint16_t reg_addr)
{
	uint8_t data[2];
	int ret = 0;
	/* assign reg_addr to data */
	data[0] = (reg_addr & 0xff00) >> 8;
	data[1] = reg_addr & 0xff;

	if (write(i2c_fd, data, 2) != 2) {
		sensor_log_err("Failed to send register address to the sensor, err: %s", strerror(errno));
		return MPI_FAILURE;
	}

	/* read reg address */
	if (read(i2c_fd, data, 2) != 2) {
		sensor_log_err("Failed to read register data from the sensor, err: %s", strerror(errno));
		return MPI_FAILURE;
	}

	ret = (int) data[0] << 8;
	ret += data[1];
	return ret;
}

/**
 * @brief Read 1 byte of data from a sensor with 2-byte addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] reg_addr Address of the register.
 *
 * @return Register data, or error.
 * @retval MPI_FAILURE Error.
 * @retval other Register data.
 */
int SENSOR_readRegWB(int i2c_fd, uint16_t reg_addr)
{
	uint8_t data[2];
	/* assign reg_addr to data */
	data[0] = (reg_addr & 0xff00) >> 8;
	data[1] = reg_addr & 0xff;

	if (write(i2c_fd, data, 2) != 2) {
		sensor_log_err("Failed to send register address to the sensor, err: %s", strerror(errno));
		return MPI_FAILURE;
	}

	/* read reg address */
	if (read(i2c_fd, data, 1) != 1) {
		sensor_log_err("Failed to read register data from the sensor, err: %s", strerror(errno));
		return MPI_FAILURE;
	}
	return data[0];
}

/**
 * @brief Read 1 byte of data from a sensor with 1-byte addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] reg_addr Address of the register.
 *
 * @return Register data, or error.
 * @retval MPI_FAILURE Error.
 * @retval other Register data.
 */
int SENSOR_readRegBB(int i2c_fd, uint16_t reg_addr)
{
	uint8_t data[1];
	/* assign reg_addr to data */
	data[0] = reg_addr & 0xff;

	if (write(i2c_fd, data, 1) != 1) {
		sensor_log_err("Failed to send register address to the sensor, err: %s", strerror(errno));
		return MPI_FAILURE;
	}

	/* read reg address */
	if (read(i2c_fd, data, 1) != 1) {
		sensor_log_err("Failed to read register data from the sensor, err: %s", strerror(errno));
		return MPI_FAILURE;
	}

	return data[0];
}

/**
 * @brief Write a series of 2-byte data to a sensor with 2-byte register addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] num_of_write Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs)
 *
 * @return Execution result
 * @retval num_of_write Success.
 * @retval MPI_SUCCESS num_of_write is 0.
 * @retval MPI_FAILURE Error.
 *
 * @see SENSOR_writeSeqWaddrWdata()
 */
int SENSOR_writeRegWW(int i2c_fd, uint16_t num_of_write, const SensCmd *cmd)
{
	uint8_t wdata[4] = {0};
	int i = 0;

	if (num_of_write == 0) {
		return MPI_SUCCESS;
	}

	if (i2c_fd <= 0) {
		return MPI_FAILURE;
	}

	for (i = 0; i < num_of_write; ++i) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			usleep(cmd[i].val * 1000);
			continue;
		}

		wdata[0] = (cmd[i].reg & 0xff00) >> 8;
		wdata[1] = (cmd[i].reg & 0xff);
		wdata[2] = (cmd[i].val & 0xff00) >> 8;
		wdata[3] = (cmd[i].val & 0xff);

		if (write(i2c_fd, wdata, 4) != 4) {
			sensor_log_err("Error writing data %02X to reg addr %02X, errno: %s",
			               cmd[i].val, cmd[i].reg, strerror(errno));
			return MPI_FAILURE;
		}
	}

	return num_of_write;
}

/**
 * @brief Write a series of 1-byte data to a sensor with 2-byte register addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] num_of_write Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs)
 *
 * @return Execution result
 * @retval num_of_write Success.
 * @retval MPI_SUCCESS num_of_write is 0.
 * @retval MPI_FAILURE Error.
 *
 * @see SENSOR_writeSeqWaddrBdata()
 */
int SENSOR_writeRegWB(int i2c_fd, uint8_t num_of_write, const SensCmd *cmd)
{
	uint8_t wdata[3] = {0};
	int i = 0;

	if (num_of_write == 0) {
		return MPI_SUCCESS;
	}

	if (i2c_fd <= 0) {
		return MPI_FAILURE;
	}

	for (i = 0; i < num_of_write; ++i) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			usleep(cmd[i].val * 1000);
			continue;
		}

		wdata[0] = (cmd[i].reg & 0xff00) >> 8;
		wdata[1] = (cmd[i].reg & 0xff);
		wdata[2] = (cmd[i].val & 0xff);

		if (write(i2c_fd, wdata, 3) != 3) {
			sensor_log_err("Error writing data %02X to reg addr %02X, errno: %s",
			               cmd[i].val, cmd[i].reg, strerror(errno));
			return MPI_FAILURE;
		}
	}

	return num_of_write;
}

/**
 * @brief Write a series of 1-byte data to a sensor with 1-byte register addresses.
 * @note Use SENSOR_writeSeqBaddrBdata() instead to reduce system calls and interrupts.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] num_of_write Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs)
 *
 * @return Execution result
 * @retval num_of_write Success.
 * @retval MPI_SUCCESS num_of_write is 0.
 * @retval MPI_FAILURE Error.
 *
 * @see SENSOR_writeSeqBaddrBdata()
 */
int SENSOR_writeRegBB(int i2c_fd, uint8_t num_of_write, const SensCmd *cmd)
{
	uint8_t wdata[2] = {0};
	int i = 0;

	if (num_of_write == 0) {
		return MPI_SUCCESS;
	}

	if (i2c_fd <= 0) {
		return MPI_FAILURE;
	}

	for (i = 0; i < num_of_write; ++i) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			usleep(cmd[i].val * 1000);
			continue;
		}

		wdata[0] = (cmd[i].reg & 0xff);
		wdata[1] = (cmd[i].val & 0xff);

		if (write(i2c_fd, wdata, 2) != 2) {
			sensor_log_err("Error writing data %02X to reg addr %02X, errno: %s",
			               cmd[i].val, cmd[i].reg, strerror(errno));
			return MPI_FAILURE;
		}
	}

	return num_of_write;
}

/**
 * @brief Write a series of 1-byte data to a sensor with 1-byte register addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] num_of_write Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs).
 * @param[in] slave_addr Slave address of the sensor.
 *
 * @return Execution result
 * @retval num_of_write Success.
 * @retval -1 Error or num_of_write = 0.
 */
int SENSOR_writeSeqBaddrBdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr)
{
#define BADDR_BDATA_MAX_CMD_NUM 10
#define BADDR_BDATA_CMD_SIZE 2

	struct i2c_rdwr_ioctl_data ioctl_data = { 0 };
	struct i2c_msg msg = { 0 };
	uint32_t accum_cnt = 0, sleep_us = 0, is_enable_write = 0, i;

	uint8_t wdata[1 + BADDR_BDATA_MAX_CMD_NUM * BADDR_BDATA_CMD_SIZE] = { 0 };
	uint8_t *data;

	if (num_of_write == 0) {
		return -1;
	}

	if (i2c_fd <= 0) {
		sensor_log_err("I2C device node error!");
		return -1;
	}

	msg.addr  = slave_addr;
	msg.flags = I2C_M_NOSTART;
	msg.buf   = wdata;

	ioctl_data.nmsgs = 1;
	ioctl_data.msgs  = &msg;

	data = wdata;
	data[0] = BADDR_BDATA_CMD_SIZE;

	for (i = 0; i < num_of_write; i++) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			is_enable_write = (accum_cnt > 0) ? 1 : 0;
			sleep_us = cmd[i].val * 1000;
		} else {
			data[1 + accum_cnt * BADDR_BDATA_CMD_SIZE + 0] = cmd[i].reg & 0xFF;
			data[1 + accum_cnt * BADDR_BDATA_CMD_SIZE + 1] = cmd[i].val & 0xFF;

			accum_cnt++;

			if (accum_cnt == BADDR_BDATA_MAX_CMD_NUM || i == num_of_write - 1) {
				is_enable_write = 1;
			}
		}

		if (is_enable_write) {
			msg.len = 1 + accum_cnt * BADDR_BDATA_CMD_SIZE;

			is_enable_write = 0;
			accum_cnt = 0;

			if (ioctl(i2c_fd, I2C_RDWR, &ioctl_data) < 0) {
				sensor_log_err("IOCTL i2c message failure!");
				return -1;
			}
		}

		if (sleep_us) {
			usleep(sleep_us);
			sleep_us = 0;
		}
	}

	return num_of_write;
}

/**
 * @brief Write a series of 1-byte data to a sensor with 2-byte register addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] num_of_write Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs).
 * @param[in] slave_addr Slave address of the sensor.
 *
 * @return Execution result
 * @retval num_of_write Success.
 * @retval -1 Error or num_of_write = 0.
 */
int SENSOR_writeSeqWaddrBdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr)
{
#define WADDR_BDATA_MAX_CMD_NUM 10
#define WADDR_BDATA_CMD_SIZE 3

	struct i2c_rdwr_ioctl_data ioctl_data = { 0 };
	struct i2c_msg msg = { 0 };
	uint32_t accum_cnt = 0, sleep_us = 0, is_enable_write = 0, i;

	uint8_t wdata[1 + WADDR_BDATA_MAX_CMD_NUM * WADDR_BDATA_CMD_SIZE] = { 0 };
	uint8_t *data;

	if (num_of_write == 0) {
		return -1;
	}

	if (i2c_fd <= 0) {
		sensor_log_err("I2C device node error!");
		return -1;
	}

	msg.addr  = slave_addr;
	msg.flags = I2C_M_NOSTART;
	msg.buf   = wdata;

	ioctl_data.nmsgs = 1;
	ioctl_data.msgs  = &msg;

	data = wdata;
	data[0] = WADDR_BDATA_CMD_SIZE;

	for (i = 0; i < num_of_write; i++) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			is_enable_write = (accum_cnt > 0) ? 1 : 0;
			sleep_us = cmd[i].val * 1000;
		} else {
			data[1 + accum_cnt * WADDR_BDATA_CMD_SIZE + 0] = (cmd[i].reg & 0xFF00) >> 8;
			data[1 + accum_cnt * WADDR_BDATA_CMD_SIZE + 1] = cmd[i].reg & 0xFF;
			data[1 + accum_cnt * WADDR_BDATA_CMD_SIZE + 2] = cmd[i].val & 0xFF;

			accum_cnt++;

			if (accum_cnt == WADDR_BDATA_MAX_CMD_NUM || i == num_of_write - 1) {
				is_enable_write = 1;
			}
		}

		if (is_enable_write) {
			msg.len = 1 + accum_cnt * WADDR_BDATA_CMD_SIZE;

			is_enable_write = 0;
			accum_cnt = 0;

			if (ioctl(i2c_fd, I2C_RDWR, &ioctl_data) < 0) {
				sensor_log_err("IOCTL i2c message failure!");
				return -1;
			}
		}

		if (sleep_us) {
			usleep(sleep_us);
			sleep_us = 0;
		}
	}

	return num_of_write;
}

/**
 * @brief Write a series of 2-byte data to a sensor with 2-byte register addresses.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] num_of_write Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs).
 * @param[in] slave_addr Slave address of the sensor.
 *
 * @return Execution result
 * @retval num_of_write Success.
 * @retval -1 Error or num_of_write = 0.
 */
int SENSOR_writeSeqWaddrWdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr)
{
#define WADDR_WDATA_MAX_CMD_NUM 7
#define WADDR_WDATA_CMD_SIZE 4

	struct i2c_rdwr_ioctl_data ioctl_data = { 0 };
	struct i2c_msg msg = { 0 };
	uint32_t accum_cnt = 0, sleep_us = 0, is_enable_write = 0, i;

	uint8_t wdata[1 + WADDR_WDATA_MAX_CMD_NUM * WADDR_WDATA_CMD_SIZE] = { 0 };
	uint8_t *data;

	if (num_of_write == 0) {
		return -1;
	}

	if (i2c_fd <= 0) {
		sensor_log_err("I2C device node error!");
		return -1;
	}

	msg.addr  = slave_addr;
	msg.flags = I2C_M_NOSTART;
	msg.buf   = wdata;

	ioctl_data.nmsgs = 1;
	ioctl_data.msgs  = &msg;

	data = wdata;
	data[0] = WADDR_WDATA_CMD_SIZE;

	for (i = 0; i < num_of_write; i++) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			is_enable_write = (accum_cnt > 0) ? 1 : 0;
			sleep_us = cmd[i].val * 1000;
		} else {
			data[1 + accum_cnt * WADDR_WDATA_CMD_SIZE + 0] = (cmd[i].reg & 0xFF00) >> 8;
			data[1 + accum_cnt * WADDR_WDATA_CMD_SIZE + 1] = cmd[i].reg & 0xFF;
			data[1 + accum_cnt * WADDR_WDATA_CMD_SIZE + 2] = (cmd[i].val & 0xFF00) >> 8;
			data[1 + accum_cnt * WADDR_WDATA_CMD_SIZE + 3] = cmd[i].val & 0xFF;

			accum_cnt++;

			if (accum_cnt == WADDR_WDATA_MAX_CMD_NUM || i == num_of_write - 1) {
				is_enable_write = 1;
			}
		}

		if (is_enable_write) {
			msg.len = 1 + accum_cnt * WADDR_WDATA_CMD_SIZE;

			is_enable_write = 0;
			accum_cnt = 0;

			if (ioctl(i2c_fd, I2C_RDWR, &ioctl_data) < 0) {
				sensor_log_err("IOCTL i2c message failure!");
				return -1;
			}
		}

		if (sleep_us) {
			usleep(sleep_us);
			sleep_us = 0;
		}
	}

	return num_of_write;
}

/**
 * @brief Write a series of 1-byte data to a sensor with 1-byte register addresses.
 * @note Use SENSOR_writeSeqBaddrBdata() instead to reduce system calls and interrupts.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] cmd_num Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs)
 *
 * @return Execution result
 * @retval cmd_num Success.
 * @retval MPI_SUCCESS cmd_num is 0.
 * @retval MPI_FAILURE Error.
 *
 * @see SENSOR_writeSeqBaddrBdata()
 */
int SENSOR_writeRegBaddrBdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd)
{
	uint8_t wdata[2]; /* 1 bytes for addr, 1 byte for data */
	int i;

	if (cmd_num == 0) {
		return MPI_SUCCESS;
	}

	if (i2c_fd < 0) {
		return MPI_FAILURE;
	}

	for (i = 0; i < cmd_num; ++i) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			usleep(cmd[i].val * 1000);
			continue;
		}

		wdata[0] = (cmd[i].reg & 0xFF);
		wdata[1] = (cmd[i].val & 0xFF);

		if (write(i2c_fd, wdata, 2) != 2) {
			sensor_log_err("Error writing data %02X to reg addr %02X, errno: %s.",
			               cmd[i].val, cmd[i].reg, strerror(errno));
			return MPI_FAILURE;
		}
	}

	return cmd_num;
}

/**
 * @brief Write a series of 1-byte data to a sensor with 2-byte register addresses.
 * @note Use SENSOR_writeSeqWaddrBdata() instead to reduce system calls and interrupts.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] cmd_num Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs)
 *
 * @return Execution result
 * @retval cmd_num Success.
 * @retval MPI_SUCCESS cmd_num is 0.
 * @retval MPI_FAILURE Error.
 *
 * @see SENSOR_writeSeqWaddrBdata()
 */
int SENSOR_writeRegWaddrBdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd)
{
	uint8_t wdata[3]; /* 2 bytes for addr, 1 byte for data */
	int i;

	if (cmd_num == 0) {
		return MPI_SUCCESS;
	}

	if (i2c_fd < 0) {
		return MPI_FAILURE;
	}

	for (i = 0; i < cmd_num; ++i) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			usleep(cmd[i].val * 1000);
			continue;
		}

		wdata[0] = (cmd[i].reg & 0xFF00) >> 8;
		wdata[1] = (cmd[i].reg & 0xFF);
		wdata[2] = (cmd[i].val & 0xFF);

		if (write(i2c_fd, wdata, 3) != 3) {
			sensor_log_err("Error writing data %02X to reg addr %02X, errno: %s.",
			               cmd[i].val, cmd[i].reg, strerror(errno));
			return MPI_FAILURE;
		}
	}

	return cmd_num;
}

/**
 * @brief Write a series of 2-byte data to a sensor with 2-byte register addresses.
 * @note Use SENSOR_writeSeqBaddrBdata() instead to reduce system calls and interrupts.
 *
 * @param[in] i2c_fd File descriptor of the I2C device.
 * @param[in] cmd_num Length of cmd.
 * @param[in] cmd I2C commands (register/data pairs)
 *
 * @return Execution result
 * @retval cmd_num Success.
 * @retval MPI_SUCCESS cmd_num is 0.
 * @retval MPI_FAILURE Error.
 *
 * @see SENSOR_writeSeqBaddrBdata()
 */
int SENSOR_writeRegWaddrWdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd)
{
	uint8_t wdata[4];
	int i;

	if (cmd_num == 0) {
		return MPI_SUCCESS;
	}

	if (i2c_fd < 0) {
		return MPI_FAILURE;
	}

	for (i = 0; i < cmd_num; ++i) {
		if (cmd[i].reg == SENSOR_DELAY_REG) {
			usleep(cmd[i].val * 1000);
			continue;
		}

		wdata[0] = (cmd[i].reg & 0xFF00) >> 8;
		wdata[1] = (cmd[i].reg & 0x00FF);
		wdata[2] = (cmd[i].val & 0xFF00) >> 8;
		wdata[3] = (cmd[i].val & 0x00FF);

		if (write(i2c_fd, wdata, 4) != 4) {
			sensor_log_err("Error writing data %02X to reg addr %02X, errno: %s.",
			               cmd[i].val, cmd[i].reg, strerror(errno));
			return MPI_FAILURE;
		}
	}

	return cmd_num;
}

/**
 * @brief Read LVDS timing calibration data from a calibration file.
 * @note This is function is deprecated and should not be used.
 *
 * @param[in] sns_idx Index of the sensor.
 * @param[out] serl_lane LVDS lane usage and timing information.
 *
 * @return Execution result
 * @retval 0 Success.
 * @retval -EINVAL Invalid sns_idx
 * @retval -ENODATA Cannot read the content from the calibration file, or the size of the file is insufficient.
 * @retval -ENOENT Cannot open the calibration file.
 */
int SENSOR_getLvdsDelay(uint32_t sns_idx, MPI_SERL_LANE_INFO_S *serl_lane)
{
	SERL_DATA_LANES_DELAY_S lanes_delay;
	FILE *ptr;
	int i;
	int ret;

	if (sns_idx >= MPI_MAX_INPUT_PATH_NUM) {
		return -EINVAL;
	}

	ret = access(LVDS_CALIB_FILE, R_OK);
	if (ret == 0) {
		ptr = fopen(LVDS_CALIB_FILE, "rb");
		if (ptr != NULL) {
			fseek(ptr, sns_idx * sizeof(SERL_DATA_LANES_DELAY_S), SEEK_SET);
			ret = fread(&lanes_delay, sizeof(SERL_DATA_LANES_DELAY_S), 1, ptr);
			if (ret == 1) {
				for (i = 0; i < MPI_MAX_DATA_LANE_NUM; i++) {
					serl_lane[i].data_delay = lanes_delay.data[i].data_delay;
					serl_lane[i].clock_delay = lanes_delay.data[i].clock_delay;
				}
				ret = 0;
			} else {
				ret = -ENODATA;
			}
			fclose(ptr);
		} else {
			ret = -ENOENT;
		}
	}

	return ret;
}

/**
 * @brief Binary search
 *
 * @param value Search target
 * @param x1 The array for matching the target value
 * @param i0 starting index
 * @param i1 ending index, inclusive
 *
 * @return The smallest index in the array that is greater than the given value, but never exceeds i1.
 * Or just i1 if the given indices are invalid.
 *
 * @see binary_search_nr()
 */
int binary_search_bin(const int value, const int *x1, const int i0, const int i1)
{
	if ((i1 - i0) <= 1) {
		return i1;
	}

	int i = (i0 + i1) >> 1;

	if (value < x1[i]) {
		return binary_search_bin(value, x1, i0, i);
	}

	return binary_search_bin(value, x1, i, i1);
}

/**
 * @brief non-recursive binary search
 * @note This function behalves slightly different from binary_search_bin()
 *
 * @param value Search target
 * @param arr The array for matching the target value
 * @param start starting index
 * @param end ending index, exclusive
 *
 * @return the largest index between start and end satisfies arr[index] <= value if found,
 * @retval 0 or (start - 1) if no satisfied index is found,
 * @retval -EINVAL if start == end
 * @retval other the result index
 */
int binary_search_nr(const int value, const int arr[], const int start, const int end)
{
	int idx = 0;
	int mask = 0x40000000;
	int tmp_idx;

	if (start == end) {
		return -EINVAL;
	}

	for (; mask; mask >>= 1) {
		tmp_idx = idx + mask;
		if (tmp_idx >= end) {
			continue;
		}
		if (tmp_idx < start) {
			idx = tmp_idx;
			continue;
		}

		if (arr[tmp_idx] <= value) {
			idx = tmp_idx;
		}
	}

	return idx;
}

/**
 * @brief Calculate linear interpolation (or sometimes referred as alpha-blending) from given values.
 *
 * @param[in] pix0 The "y0" value.
 * @param[in] pix1 The "y1" value.
 * @param[in] alpha The distance between the result and pix0, or "(x - x0)".
 * @param[in] norm The distance betwwen pix0 and pix1, or "(x1 - x0)".
 *
 * @return The interpolation result.
 */
int interpolation(const int pix0, const int pix1, const int alpha, const int norm)
{
	int64_t tmp = (int64_t)alpha * (int64_t)(pix0 - pix1);

	return (tmp > 0) ? pix1 + (tmp + (norm >> 1)) / norm : pix1 + (tmp - (norm >> 1)) / norm;

}

#ifdef __cplusplus
}
#endif /* __cplusplus */
