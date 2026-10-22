/*
 * sensor.h: Function wrappers for other files in the uboot sensor driver.
 *
 * Copyright (C) 2014- Augentix Inc.
 */

#ifndef UBOOT_SENSOR_H_
#define UBOOT_SENSOR_H_

#include <common.h>

#include "mpi_dip_sns.h"

#define DEBUG_SENSOR (0)

#define sensor_log_err(fmt, ...) printf("Error: " fmt "\n", ##__VA_ARGS__)
#define sensor_log_warn(fmt, ...) printf("Warning: " fmt "\n", ##__VA_ARGS__)
#define sensor_log_notice(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define sensor_log_info(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#if DEBUG_SENSOR
#define sensor_log_debug(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#else
#define sensor_log_debug(fmt, ...)
#endif

#define _custom_sns(a) custom_sns_##a
#define custom_sns(a) _custom_sns(a)

typedef struct {
	uint16_t reg;
	uint16_t val;
} SensCmd;

typedef struct {
	uint32_t effective_frame_line;
	uint32_t exp_gap;
	uint32_t hard_exp_max;
	uint32_t curr_exp_max;
	uint32_t exp_min;
	uint32_t exp_line;
	uint32_t inttime;
	uint32_t sensor_gain;
	int shs_idx[4];
	int gain_idx[4];
	int other_idx[8];
} CUSTOM_SNS_EXP_TABLE_S;

typedef struct {
	uint32_t sensor_gain;
	// Workaround: if pclk is 64 bits, compiler might use functions from gcc's pre-built functions
	//             and failed to link due to hard/soft float imcompatibility. (#58941-25)
	uint32_t pclk;
	uint32_t fps_line;
	uint32_t exp_line[2];
	uint32_t frame_line[2];
	uint32_t line_pixel[2];
	uint32_t row_time[2];
	MPI_SNS_REGS_TABLE_S regs_info[2];
	CUSTOM_SNS_EXP_TABLE_S exp_info[4];
} CUSTOM_SNS_STATE_S;

typedef struct {
	int32_t (*reg_callback)(MPI_PATH idx);
	int32_t (*dereg_callback)(MPI_PATH idx);
	void (*standby)(MPI_PATH idx);
	void (*restart)(MPI_PATH idx);
	int32_t (*write_reg)(MPI_PATH idx, int32_t addr, int32_t data);
	int32_t (*read_reg)(MPI_PATH idx, int32_t addr);
	int32_t (*update_exp_cmd)(int32_t i2c_fd, uint8_t path_idx);
} CUSTOM_SNS_CTRL_S;

#ifdef SNS0
extern CUSTOM_SNS_CTRL_S custom_sns(SNS0_ID);
#endif

#ifdef SNS1
extern CUSTOM_SNS_CTRL_S custom_sns(SNS1_ID);
#endif

void sensor_power_up(void);

INT32 MPI_regSnsCallback(MPI_PATH idx, INT32 sns_id, const MPI_SNS_CALLBACK_S *p_sns_cb);
INT32 MPI_deregSnsCallback(MPI_PATH idx, INT32 sns_id);
int binary_search_bin(const int value, const int *x1, const int i0, const int i1);
int binary_search_nr(const int value, const int arr[], const int start, const int end);

int sensor_get_fps_instruction(long frame_rate, SensCmd *command_arr, int arr_len, int sns_id);
int sensor_get_exposure_instruction(unsigned long init_exposure, SensCmd *command_arr, int arr_len, int sns_id);

#endif /* UBOOT_SENSOR_H_ */
