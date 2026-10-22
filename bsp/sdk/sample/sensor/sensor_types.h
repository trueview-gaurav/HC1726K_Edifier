#ifndef SENSOR_TYPES_H_
#define SENSOR_TYPES_H_

#include <stdint.h>
#include "mpi_dip_sns.h"

typedef struct {
	uint16_t reg;
	uint16_t val;
} SensCmd;

typedef struct {
	int32_t (*update_exp_cmd) (int32_t i2c_fd, uint8_t path_idx);
} SENSOR_CMOS_CTRL_S;

/*
 * structure SensInfo - data structure for sensor information
 * @line_len_pixel: How many pixels in a line
 * @frame_len_line: How many line in a frame
 * @line_exp_time_x32: Time (us) to expose a line and is multiplied by 32
 * @sensor_pclk: sensor output clk
 * @fps_line_num: Target line number to achieve target fps
 * @exp_line_num: Exposure time measured in line number
 * @vs_line_num: Vsync line number
 * @vb_line_num: Vertical blanking line number
 */
typedef struct {
	int line_exp_time_x32;
	int sensor_pclk;
	int fps_line_num;
	int exp_line_num;
	int line_len_pixel;
	int frame_len_line;
	int vs_line_num;
	int vb_line_num;
} SensInfo;

typedef struct {
	uint32_t effective_frame_line;
	uint32_t exp_gap;
	uint32_t hard_exp_max; // in lines
	uint32_t curr_exp_max; // in lines
	uint32_t exp_min; // in lines
	uint32_t exp_line; // for reference
	uint32_t inttime; // for reference
	// uint32_t hard_gain_max;
	// uint32_t soft_gain_max;
	uint32_t sensor_gain; // for reference
	int shs_idx[4];
	int gain_idx[4];
	int other_idx[8];
} CUSTOM_SNS_EXP_TABLE_S;

typedef struct {
	uint32_t sensor_gain; /* sensor gain */
	uint64_t pclk; /* Sensor pixel clock */
	uint32_t fps_line; /* Line number to achieve target fps */
	uint32_t exp_line[2]; /* Exposured time in unit line */
	uint32_t frame_line[2]; /* Total lines in a frame */
	uint32_t line_pixel[2]; /* Total pixels in a line */
	uint32_t row_time[2]; /* timex32 per row <us>*/
	MPI_SNS_REGS_TABLE_S regs_info[2]; /* [0]: curr-frame [1]: pr-frame */
	CUSTOM_SNS_EXP_TABLE_S exp_info[4];
} CUSTOM_SNS_STATE_S;

typedef struct {
	int32_t (*reg_callback) (MPI_PATH idx);
	int32_t (*dereg_callback) (MPI_PATH idx);
	void  (*standby) (MPI_PATH idx);
	void  (*restart) (MPI_PATH idx);
	int32_t (*write_reg) (MPI_PATH idx, int32_t addr, int32_t data);
	int32_t (*read_reg) (MPI_PATH idx, int32_t addr);
	int32_t (*update_exp_cmd) (int32_t i2c_fd, uint8_t path_idx);
} CUSTOM_SNS_CTRL_S;

#endif /* SENSOR_TYPES_H_ */
