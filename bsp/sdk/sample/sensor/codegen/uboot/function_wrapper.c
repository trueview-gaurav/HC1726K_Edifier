#include "mpi_dip_sns.h"
#include "sensor.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "mpi_base_types.h"
#include "mpi_limits.h"

#define INIT_CMD_ALLOC_SIZE (256)

MPI_SNS_CALLBACK_S g_codegen_sns_callbacks[MPI_MAX_INPUT_PATH_NUM];
int g_codegen_slave_addr = 0;
SensCmd *g_codegen_init_cmd = NULL;
int g_codegen_init_cmd_len = 0;
static int g_codegen_init_cmd_alloc_size = 0;
int g_codegen_start_cmd = -1; // The position of the command that will start the streaming
int g_codegen_cmd_addr_len = 0;
int g_codegen_cmd_data_len = 0;

INT32 MPI_regSnsCallback(MPI_PATH idx, INT32 sns_id, const MPI_SNS_CALLBACK_S *p_sns_cb)
{
	int path_idx = idx.path;

	if (!p_sns_cb) {
		return MPI_FAILURE;
	}

	g_codegen_sns_callbacks[path_idx] = *p_sns_cb;
	g_codegen_sns_callbacks[path_idx].dip.global_init(idx);

	return MPI_SUCCESS;
}

INT32 MPI_deregSnsCallback(MPI_PATH idx, INT32 sns_id)
{
	return MPI_SUCCESS;
}

int SENSOR_openI2cDev(int *i2c_fd, uint16_t slave_addr)
{
	g_codegen_slave_addr = slave_addr;
	if (i2c_fd) {
		*i2c_fd = 10;
	}

	return MPI_SUCCESS;
}

int SENSOR_closeI2cDev(int i2c_fd)
{
	return MPI_SUCCESS;
}

void SENSOR_printCmd(uint8_t num_of_write, SensCmd *cmd)
{
	;
}

static void check_slave_address(int slave_addr)
{
	if (!g_codegen_slave_addr) {
		// Record the I2C slave address.
		g_codegen_slave_addr = slave_addr;
	} else if (g_codegen_slave_addr != slave_addr) {
		// Show warning if the slave addresses do not match.
		fprintf(stderr, "Warning: The sensor driver uses different I2C slave addresses.\n");
	}
}

static void check_cmd_length(int addr_len, int data_len)
{
	if (!g_codegen_cmd_addr_len && !g_codegen_cmd_data_len) {
		// Record the length of register address and data.
		g_codegen_cmd_addr_len = addr_len;
		g_codegen_cmd_data_len = data_len;
	} else if (g_codegen_cmd_addr_len != addr_len || g_codegen_cmd_data_len != data_len) {
		// Show warning if the previous command length settings are not the same.
		fprintf(stderr, "Warning: The sensor driver uses different I2C addr/data lengths.\n");
		g_codegen_cmd_addr_len = addr_len;
		g_codegen_cmd_data_len = data_len;
	}
}

static int update_cmd(const SensCmd *cmd, int len)
{
	// input argument check
	if (!cmd || len <= 0) {
		return MPI_FAILURE;
	}

	// Update position of the "start" command.
	if (g_codegen_start_cmd != -1) {
		// If this function is called multiple times, it's more likely that the later ones are the real "start" command.
		g_codegen_start_cmd = g_codegen_init_cmd_len;
	}

	// Allocate g_codegen_init_cmd space.
	if (!g_codegen_init_cmd) {
		g_codegen_init_cmd = calloc(INIT_CMD_ALLOC_SIZE, sizeof(SensCmd));
		if (!g_codegen_init_cmd) {
			fprintf(stderr, "Error: Cannot allocate enough memory for g_codegen_init_cmd.\n");
			return MPI_FAILURE;
		}
		g_codegen_init_cmd_alloc_size = INIT_CMD_ALLOC_SIZE;
	}

	// Record I2C commands into g_codegen_init_cmd.
	for (int i = 0; i < len; i++) {
		// Reallocate the memory if needed.
		if (g_codegen_init_cmd_len >= g_codegen_init_cmd_alloc_size) {
			int new_size = g_codegen_init_cmd_alloc_size + INIT_CMD_ALLOC_SIZE;
			void *new_ptr = realloc(g_codegen_init_cmd, sizeof(SensCmd) * new_size);
			if (!new_ptr) {
				fprintf(stderr, "Error: Cannot allocate enough memory for g_codegen_init_cmd.\n");
				return MPI_FAILURE;
			}
			g_codegen_init_cmd = new_ptr;
			g_codegen_init_cmd_alloc_size = new_size;
		}

		g_codegen_init_cmd[g_codegen_init_cmd_len] = cmd[i];
		g_codegen_init_cmd_len++;
	}

	// Update position of the "start" command.
	if (g_codegen_start_cmd == -1) {
		// If this function is called for the first time, we will treat the last command is the one that starts the streaming.
		g_codegen_start_cmd = g_codegen_init_cmd_len - 1;
	}

	return MPI_SUCCESS;
}

int SENSOR_writeSeqBaddrBdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr)
{
	const int addr_len = 1;
	const int data_len = 1;

	// Check I2C slave address.
	check_slave_address(slave_addr);

	// Check I2C command.
	check_cmd_length(addr_len, data_len);

	// Record I2C commands.
	return update_cmd(cmd, num_of_write);
}

int SENSOR_writeSeqWaddrBdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr)
{
	const int addr_len = 2;
	const int data_len = 1;

	// Check I2C slave address.
	check_slave_address(slave_addr);

	// Check I2C command.
	check_cmd_length(addr_len, data_len);

	// Record I2C commands.
	return update_cmd(cmd, num_of_write);
}

int SENSOR_writeSeqWaddrWdata(int i2c_fd, int num_of_write, const SensCmd *cmd, uint16_t slave_addr)
{
	const int addr_len = 2;
	const int data_len = 2;

	// Check I2C slave address.
	check_slave_address(slave_addr);

	// Check I2C command.
	check_cmd_length(addr_len, data_len);

	// Record I2C commands.
	return update_cmd(cmd, num_of_write);
}

int SENSOR_writeRegBaddrBdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd)
{
	return SENSOR_writeSeqBaddrBdata(i2c_fd, cmd_num, cmd, g_codegen_slave_addr);
}

int SENSOR_writeRegWaddrBdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd)
{
	return SENSOR_writeSeqWaddrBdata(i2c_fd, cmd_num, cmd, g_codegen_slave_addr);
}

int SENSOR_writeRegWaddrWdata(int i2c_fd, uint32_t cmd_num, const SensCmd *cmd)
{
	return SENSOR_writeSeqWaddrWdata(i2c_fd, cmd_num, cmd, g_codegen_slave_addr);
}

int SENSOR_writeRegBB(int i2c_fd, uint8_t num_of_write, const SensCmd *cmd)
{
	return SENSOR_writeSeqBaddrBdata(i2c_fd, num_of_write, cmd, g_codegen_slave_addr);
}

int SENSOR_writeRegWB(int i2c_fd, uint8_t num_of_write, const SensCmd *cmd)
{
	return SENSOR_writeSeqWaddrBdata(i2c_fd, num_of_write, cmd, g_codegen_slave_addr);
}

int SENSOR_writeRegWW(int i2c_fd, uint16_t num_of_write, const SensCmd *cmd)
{
	return SENSOR_writeSeqWaddrWdata(i2c_fd, num_of_write, cmd, g_codegen_slave_addr);
}

int SENSOR_readRegBB(int i2c_fd, uint16_t address)
{
	return 0;
}

int SENSOR_readRegWB(int i2c_fd, uint16_t address)
{
	return 0;
}

int SENSOR_readRegWW(int i2c_fd, uint16_t address)
{
	return 0;
}

int SENSOR_getLvdsDelay(uint32_t sns_idx, MPI_SERL_LANE_INFO_S *serl_lane)
{
	return 0;
}

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

int interpolation(const int pix0, const int pix1, const int alpha, const int norm)
{
	int64_t tmp = (int64_t)alpha * (int64_t)(pix0 - pix1);

	return (tmp > 0) ? pix1 + (tmp + (norm >> 1)) / norm : pix1 + (tmp - (norm >> 1)) / norm;
}
