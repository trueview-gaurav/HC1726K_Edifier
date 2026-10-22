#include "codegen_uboot.h"

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "mpi_index.h"
#include "mpi_dip_sns.h"
#include "sensor_types.h"
#include "sensor.h"
#include "sensor_settings.h"
#include "sensor_cal.h" // For UBOOT_INIT_EXPO

#ifndef SENSOR_FASTBOOT_FPS
#define SENSOR_FASTBOOT_FPS (15)
#endif

MPI_SNS_OP_INFO_S g_codegen_sensor_info;
MPI_AE_SNS_DEFAULT_S g_codegen_ae_info;
MPI_SNS_REGS_TABLE_S g_sns_regs_table;

static SensCmd g_exp_cmd[32];
static int g_exp_cmd_len = 0;
static int g_write_exp_cmd = 1;

static SensCmd g_fps_cmd[8];
static int g_fps_cmd_len = 0;
static int g_write_fps_cmd = 1;

static int g_dbc_level[4];
static int g_dcc_gain[4];
static int g_dcc_offset_2s[4];

static char f_suffix[8] = "";
#ifdef SNS0
static int g_sensor_idx = 0;
#elif defined(SNS1)
static int g_sensor_idx = 1;
#elif defined(SNS2)
static int g_sensor_idx = 2;
#else
#error
#endif

// Map MPI index to hardware SNS index, may be changed if needed.
static const int g_sns_index[MPI_MAX_INPUT_PATH_NUM] = { 0, 1 };

static void acquire_sensor_info(MPI_PATH index);
static void acquire_register_info(MPI_PATH index);
static void acquire_iq_info(MPI_PATH index);
static int gen_sensor_settings(int index, const char *dir_path);
static void gen_setting_header(FILE *fout, int index);
static int gen_sensor_ctrl(int index, const char *dir_path);
static void gen_ctrl_header(FILE *fout);
static void gen_init_settings(FILE *fout);
static void gen_start_command(FILE *fout);
static void gen_fps_command(FILE *fout);
static void gen_exposure_command(FILE *fout);
static void gen_set_fps_function(FILE *fout);
static void gen_set_exposure_function(FILE *fout);
static void gen_start_function(FILE *fout);
static int gen_sensor_cmos(const char *dir_path);
static void gen_sensor_cmos_header(FILE *fout);
static void gen_sensor_cmos_text(FILE *fout, char *buffer, long fsize);
static int gen_sensor_params(const char *dir_path);
static void gen_sensor_params_header(FILE *fout);
static int gen_sensor_cal(int index, const char *dir_path);
static void gen_sensor_cal_header(FILE *fout, int index);

int gen_uboot_file(MPI_PATH path_idx, const char *uboot_sns_path)
{
	int index = path_idx.path;
	int ret = 0;

	if (uboot_sns_path == NULL) {
		return 1;
	}

	if (g_sensor_idx > 0) {
		sprintf(f_suffix, "_%d", g_sensor_idx);
	}

	/* generate files */
	acquire_sensor_info(path_idx);
	ret |= gen_sensor_settings(index, uboot_sns_path);

	acquire_register_info(path_idx);
	ret |= gen_sensor_ctrl(index, uboot_sns_path);

	ret |= gen_sensor_cmos(uboot_sns_path);

	ret |= gen_sensor_params(uboot_sns_path);

	acquire_iq_info(path_idx);
	ret |= gen_sensor_cal(index, uboot_sns_path);

	return ret;
}

static void acquire_sensor_info(MPI_PATH path_idx)
{
	int index = path_idx.path;

	// Acquire sensor information
	g_codegen_sns_callbacks[index].dip.get_sns_op_info(index, g_sns_index[index], &g_codegen_sensor_info);
	g_codegen_sns_callbacks[index].ae.get_ae_default(path_idx, &g_codegen_ae_info);

	// Parse initial settings and I2C info
	g_codegen_sns_callbacks[index].dip.init(index);
}

static void acquire_register_info(MPI_PATH path_idx)
{
	int index = path_idx.path;
	int inttime_gain_idx[MPI_SNS_TABLE_REGS_NUM];
	memset(inttime_gain_idx, 0, sizeof(inttime_gain_idx));

	// Make sure every registers in sensor_cmos.c is reseted
	g_codegen_sns_callbacks[index].dip.get_regs_info(path_idx, &g_sns_regs_table);

	// inttime and sensor gain
	UINT32 _inttime;
	g_codegen_sns_callbacks[index].ae.set_inttime(path_idx, 12500, &_inttime);
	g_codegen_sns_callbacks[index].ae.set_sensor_gain(path_idx, 32);
	g_codegen_sns_callbacks[index].dip.get_regs_info(path_idx, &g_sns_regs_table);
	for (int i = 0; i < g_sns_regs_table.reg_num; i++) {
		if (g_sns_regs_table.i2c_data[i].is_update) {
			g_exp_cmd[g_exp_cmd_len].reg = g_sns_regs_table.i2c_data[i].reg_addr;
			g_exp_cmd[g_exp_cmd_len].val = g_sns_regs_table.i2c_data[i].reg_data;
			g_exp_cmd_len++;
			inttime_gain_idx[i] = 1;
		}
	}

	// fps
	RANGE_S _inttime_range;

	if (SENSOR_FASTBOOT_FPS > g_codegen_ae_info.max_fps) {
		fprintf(stderr,
		        "Error: Required fastboot frame rate (%.1f) is higher than the maximum frame rate (%.1f).\n",
		        (double)SENSOR_FASTBOOT_FPS, (double)g_codegen_ae_info.max_fps);
		exit(1);
	}

	g_codegen_sns_callbacks[index].ae.set_framerate(path_idx, SENSOR_FASTBOOT_FPS, &_inttime_range);
	g_codegen_sns_callbacks[index].dip.get_regs_info(path_idx, &g_sns_regs_table);
	for (int i = 0; i < g_sns_regs_table.reg_num; i++) {
		if (g_sns_regs_table.i2c_data[i].is_update) {
			// Exclude commands for inttime

			if (inttime_gain_idx[i] == 0) {
				// Not an inttime command, so it is command for fps
				g_fps_cmd[g_fps_cmd_len].reg = g_sns_regs_table.i2c_data[i].reg_addr;
				g_fps_cmd[g_fps_cmd_len].val = g_sns_regs_table.i2c_data[i].reg_data;
				g_fps_cmd_len++;
			}
		}
	}
}

static void acquire_iq_info(MPI_PATH path_idx)
{
	int index = path_idx.path;
	MPI_CAL_SNS_DEFAULT_S cal_data;

	// Retrieve CAL settings from sensor_cal.h
	g_codegen_sns_callbacks[index].cal.get_cal_default(path_idx, &cal_data);

	// DBC
	for (int i = 0; i < 4; i++) {
		g_dbc_level[i] = cal_data.dbc.dbc_level;
	}

	// DCC
	for (int i = 0; i < 4; i++) {
		g_dcc_gain[i] = cal_data.dcc.gain[i];
		g_dcc_offset_2s[i] = cal_data.dcc.offset_2s[i];
		if (g_dcc_offset_2s[i] > INT16_MAX) {
			g_dcc_offset_2s[i] -= 1 << 16;
			g_dcc_offset_2s[i] += 1 << 17;
		}
	}
}

static int gen_sensor_settings(int index, const char *dir_path)
{
	FILE *fout = NULL;
	char *file_path = NULL;
	int path_len;

	path_len = snprintf(NULL, 0, "%s/sensor_settings%s.h", dir_path, f_suffix) + 1;
	file_path = malloc(path_len);
	if (!file_path) {
		fprintf(stderr, "Error: Unable to allocate memory for file path.\n");
		return 1;
	}
	snprintf(file_path, path_len, "%s/sensor_settings%s.h", dir_path, f_suffix);

	fout = fopen(file_path, "w");
	if (!fout) {
		fprintf(stderr, "Error: Unable to open file '%s' for writing.\n", file_path);
		free(file_path);
		return 1;
	}

	gen_setting_header(fout, index);

	fflush(fout);
	fclose(fout);
	free(file_path);
	return 0;
}

static void gen_setting_header(FILE *fout, int index)
{
	// These macros should be defined in sensor_settings.h or headers included by it.
	unsigned frame_line = INIT_FRAME_LINE;
	unsigned line_length = INIT_LINE_LEN;
	unsigned long long pclk = PCLK;

	/* Workaround: limit pclk to 32 bits for uboot. (#58941-25) */
	while (pclk > 0xffffffffull) {
		pclk >>= 1;
		line_length >>= 1;
	}

	fprintf(fout, "/*\n");
	fprintf(fout, " * sensor_settings%s.h: Hold some constants of the sensor settings.\n", f_suffix);
	fprintf(fout, " *\n");
	fprintf(fout, " * Copyright (C) 2014- Augentix Inc.\n");
	fprintf(fout, " *\n");
	fprintf(fout, " * This file is created by codegen, DO NOT COMMIT THIS FILE.\n");
	fprintf(fout, " */\n");
	fprintf(fout, "\n");
	fprintf(fout, "#ifndef UBOOT_SENSOR_SETTINGS_H_\n");
	fprintf(fout, "#define UBOOT_SENSOR_SETTINGS_H_\n");
	fprintf(fout, "\n");
	fprintf(fout, "#define SENSOR_I2C_SLAVE_ADDR (0x%02x)\n", g_codegen_slave_addr);
	fprintf(fout, "#define SENSOR_I2C_ADDR_BYTE (%d)\n", g_codegen_cmd_addr_len);
	fprintf(fout, "#define SENSOR_I2C_DATA_BYTE (%d)\n", g_codegen_cmd_data_len);
	fprintf(fout, "\n");
	fprintf(fout, "#define SENSOR_FPS_START (%d)\n", SENSOR_FASTBOOT_FPS);
	fprintf(fout, "#define SENSOR_FPS_MAX (%d)\n", (int)g_codegen_ae_info.max_fps);
	fprintf(fout, "#define SENSOR_FPS_MIN (%d)\n", (int)g_codegen_ae_info.min_fps);
	fprintf(fout, "\n");
	fprintf(fout, "#define SENSOR_GAIN_MAX (%" PRIu32 ")\n", g_codegen_ae_info.sensor_gain_range.max);
	fprintf(fout, "#define SENSOR_GAIN_MIN (%" PRIu32 ")\n", g_codegen_ae_info.sensor_gain_range.min);
	fprintf(fout, "\n");
	fprintf(fout, "#define SENSOR_FPS (%d)\n", (int)g_codegen_sensor_info.sensor_fps);
	fprintf(fout, "#define INIT_FRAME_LINE (%u)\n", frame_line);
	fprintf(fout, "#define INIT_LINE_LEN (%u)\n", line_length);
	fprintf(fout, "#define PCLK (%llu)\n", pclk);
	fprintf(fout, "\n");
	fprintf(fout, "#define SENSOR_FRAME_LINES_MAX (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MIN)\n");
	fprintf(fout, "#define SENSOR_FRAME_LINES_MIN (INIT_FRAME_LINE * SENSOR_FPS / SENSOR_FPS_MAX)\n");
	fprintf(fout, "\n");
	fprintf(fout, "#endif /* UBOOT_SENSOR_SETTINGS_H_ */\n");
}

static int gen_sensor_ctrl(int index, const char *dir_path)
{
	FILE *fout = NULL;
	char *file_path = NULL;
	int path_len;

	if (g_codegen_start_cmd == -1) {
		fprintf(stderr, "Error: Cannot find valid sensor initial commands.\n");
		return 1;
	}

	path_len = snprintf(NULL, 0, "%s/sensor_ctrl%s.c", dir_path, f_suffix) + 1;
	file_path = malloc(path_len);
	if (!file_path) {
		fprintf(stderr, "Error: Unable to allocate memory for file path.\n");
		return 1;
	}
	snprintf(file_path, path_len, "%s/sensor_ctrl%s.c", dir_path, f_suffix);

	fout = fopen(file_path, "w");
	if (!fout) {
		fprintf(stderr, "Error: Unable to open file '%s' for writing.\n", file_path);
		free(file_path);
		return 1;
	}

	// If no valid command for exposure/fps exists, do not generate the related codes.
	if (g_exp_cmd_len <= 0) {
		g_write_exp_cmd = 0;
	}
	if (g_fps_cmd_len <= 0) {
		g_write_fps_cmd = 0;
	}
	// If this sensor setting supports auto exposure, do not generate code
	// for reading light sensors and updating exposure settings.
#ifdef USE_AUTO_EXPOSURE
	g_write_exp_cmd = 0;
#endif

	gen_ctrl_header(fout);
	gen_init_settings(fout);
	gen_start_command(fout);
	gen_fps_command(fout);
	gen_exposure_command(fout);
	gen_set_fps_function(fout);
	gen_set_exposure_function(fout);
	gen_start_function(fout);

	fflush(fout);
	fclose(fout);
	free(file_path);
	return 0;
}

static void gen_ctrl_header(FILE *fout)
{
	fprintf(fout, "/*\n");
	fprintf(fout, " * sensor_ctrl%s.c: Configure and start the sensor.\n", f_suffix);
	fprintf(fout, " *\n");
	fprintf(fout, " * Copyright (C) 2014- Augentix Inc.\n");
	fprintf(fout, " *\n");
	fprintf(fout, " * This file is created by codegen, DO NOT COMMIT THIS FILE.\n");
	fprintf(fout, " */\n");
	fprintf(fout, "\n");
	fprintf(fout, "#include <common.h>\n");
	fprintf(fout, "#include <i2c.h>\n");
	fprintf(fout, "\n");
	fprintf(fout, "#include \"sensor.h\"\n");
	fprintf(fout, "#include \"sensor_settings%s.h\"\n", f_suffix);
	fprintf(fout, "#include \"sensor_comm.h\"\n");
	fprintf(fout, "#include \"light_meter.h\"\n");
	fprintf(fout, "#include \"exposure.h\"\n");
	fprintf(fout, "\n");
	fprintf(fout, "extern long g_camera_fps[2];\n");
	fprintf(fout, "extern long g_init_exp[2];\n");
	fprintf(fout, "\n");
}

static void gen_init_settings(FILE *fout)
{
	int line_accumulate = 0;
	int addr_hex_length = g_codegen_cmd_addr_len * 2;
	int data_hex_length = g_codegen_cmd_data_len * 2;

	fprintf(fout, "static SensCmd k_sensor_initial_sequence[] = {\n");
	for (int i = 0; i < g_codegen_start_cmd; i++) {
		if (line_accumulate == 0) {
			fprintf(fout, "\t");
		} else {
			fprintf(fout, " ");
		}

		if (g_codegen_init_cmd[i].reg != SENSOR_DELAY_REG) {
			fprintf(fout, "{ 0x%0*x, 0x%0*x },", addr_hex_length, g_codegen_init_cmd[i].reg,
			        data_hex_length, g_codegen_init_cmd[i].val);
			line_accumulate++;
		} else {
			fprintf(fout, "{ SENSOR_DELAY_REG, %d },", g_codegen_init_cmd[i].val);
			line_accumulate = 5;
		}

		if (line_accumulate >= 5) {
			fprintf(fout, "\n");
			line_accumulate = 0;
		}
	}
	if (line_accumulate > 0) {
		fprintf(fout, "\n");
	}
	fprintf(fout, "};\n");
	fprintf(fout, "\n");
}

static void gen_start_command(FILE *fout)
{
	int addr_hex_length = g_codegen_cmd_addr_len * 2;
	int data_hex_length = g_codegen_cmd_data_len * 2;

	fprintf(fout, "static SensCmd k_sensor_start_command[] = {\n");
	for (int i = g_codegen_start_cmd; i < g_codegen_init_cmd_len; i++) {
		fprintf(fout, "\t{ 0x%0*x, 0x%0*x },\n", addr_hex_length, g_codegen_init_cmd[i].reg, data_hex_length,
		        g_codegen_init_cmd[i].val);
	}
	fprintf(fout, "};\n");
	fprintf(fout, "\n");
}

static void gen_fps_command(FILE *fout)
{
	int addr_hex_length = g_codegen_cmd_addr_len * 2;
	int data_hex_length = g_codegen_cmd_data_len * 2;

	if (g_write_fps_cmd) {
		fprintf(fout, "static SensCmd g_sensor_fps_command[] = {\n");
		for (int i = 0; i < g_fps_cmd_len; i++) {
			fprintf(fout, "\t{ 0x%0*x, 0x%0*x },\n", addr_hex_length, g_fps_cmd[i].reg, data_hex_length,
			        g_fps_cmd[i].val);
		}
		fprintf(fout, "};\n");
		fprintf(fout, "\n");
	}
}

static void gen_exposure_command(FILE *fout)
{
	int addr_hex_length = g_codegen_cmd_addr_len * 2;
	int data_hex_length = g_codegen_cmd_data_len * 2;

	if (g_write_exp_cmd) {
		fprintf(fout, "static SensCmd g_sensor_exposure_command[] = {\n");
		for (int i = 0; i < g_exp_cmd_len; i++) {
			fprintf(fout, "\t{ 0x%0*x, 0x%0*x },\n", addr_hex_length, g_exp_cmd[i].reg, data_hex_length,
			        g_exp_cmd[i].val);
		}
		fprintf(fout, "};\n");
		fprintf(fout, "\n");
	}
}

static void gen_set_fps_function(FILE *fout)
{
	fprintf(fout, "void sensor_set_fps%s(int sensor_i2c_addr)\n", f_suffix);
	fprintf(fout, "{\n");
	if (g_write_fps_cmd) {
		fprintf(fout, "\tconst int fps_command_len = sizeof(g_sensor_fps_command) / sizeof(SensCmd);\n");
		fprintf(fout, "\tlong frame_rate = SENSOR_FPS_START;\n");
		fprintf(fout, "\tchar *ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_SRC) : getenv(\"lux_src\");\n");
	}

	fprintf(fout, "\n");
	fprintf(fout, "\tif (sensor_i2c_addr > 0x7F) { // 7-bit\n");
	fprintf(fout, "\t\tprintf(\"[Sensor Error] Invalid sensor slave address.\\n\");\n");
	fprintf(fout, "\t\treturn;\n");
	fprintf(fout, "\t}\n");
	fprintf(fout, "\n");

	if (g_write_fps_cmd) {
		fprintf(fout, "\t// Overwrite fps settings from environment variables\n");
		if (g_sensor_idx == 0) {
			fprintf(fout, "#if LOCK_PARAM_TO_SPEED_UP\n");
			fprintf(fout, "\t\tframe_rate = CAMERA_FPS;\n");
			fprintf(fout, "#else\n");
			fprintf(fout, "\t\tframe_rate = simple_strtol(getenv(\"camera_fps\"), NULL, 0);\n");
			fprintf(fout, "#endif\n");
		} else {
			fprintf(fout, "#if LOCK_PARAM_TO_SPEED_UP\n");
			fprintf(fout, "\t\tframe_rate = CAMERA%d_FPS;\n", g_sensor_idx);
			fprintf(fout, "#else\n");
			fprintf(fout, "\t\tframe_rate = simple_strtol(getenv(\"camera_fps_%d\"), NULL, 0);\n",
			        g_sensor_idx);
			fprintf(fout, "#endif\n");
		}
		fprintf(fout, "\tif ((frame_rate > SENSOR_FPS_MAX) || (frame_rate < SENSOR_FPS_MIN)) {\n");
		fprintf(fout, "\t\tframe_rate = SENSOR_FPS_START;\n");
		fprintf(fout, "\t}\n");
		fprintf(fout, "#ifdef CONFIG_VERBOSE\n");
		fprintf(fout, "\tprintf(\"frame_rate = %%ld\\n\", frame_rate);\n");
		fprintf(fout, "#endif\n");
		fprintf(fout, "\n");
		fprintf(fout, "\tsensor_get_fps_instruction(frame_rate, g_sensor_fps_command,\n");
		fprintf(fout, "\t                           fps_command_len, SNS%d_ID);\n", g_sensor_idx);
		fprintf(fout, "\n");
		fprintf(fout, "\t// Set environment variables for applications after booting\n");
		fprintf(fout, "\tg_camera_fps[%d] = frame_rate;\n", g_sensor_idx);
		fprintf(fout, "\n");
		if (g_sensor_idx == 0) {
			fprintf(fout, "\tif ((strcmp(ret_str, \"env\") != 0) && (strcmp(ret_str, \"hw\") != 0)) {\n");
		} else {
			fprintf(fout,
			        "\tif (ALL_SENSOR_SHARE_LUX == 0 && (strcmp(ret_str, \"env\") != 0) && (strcmp(ret_str, \"hw\") != 0)) {\n");
		}
		fprintf(fout, "\t\ti2c_write_seq(sensor_i2c_addr, g_sensor_fps_command, fps_command_len,\n");
		fprintf(fout, "\t\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");
		fprintf(fout, "\t}\n");
	}
	fprintf(fout, "}\n\n");
}

static void gen_set_exposure_function(FILE *fout)
{
	fprintf(fout, "void sensor_set_exposure%s(int sensor_i2c_addr)\n", f_suffix);
	fprintf(fout, "{\n");
	if (g_write_exp_cmd) {
		fprintf(fout,
		        "\tconst int exposure_command_len = sizeof(g_sensor_exposure_command) / sizeof(SensCmd);\n");
		fprintf(fout, "\tlong init_exposure;\n");
		fprintf(fout, "\tchar *ret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_SRC) : getenv(\"lux_src\");\n");
	}

	fprintf(fout, "\n");
	fprintf(fout, "\tif (sensor_i2c_addr > 0x7F) { // 7-bit\n");
	fprintf(fout, "\t\tprintf(\"[Sensor Error] Invalid sensor slave address.\\n\");\n");
	fprintf(fout, "\t\treturn;\n");
	fprintf(fout, "\t}\n");
	fprintf(fout, "\n");

	if (g_write_exp_cmd) {
		fprintf(fout, "\t// Determine exposure time/gain from the light sensor\n");
		if (g_sensor_idx == 0) {
			fprintf(fout, "\tinit_exposure = sensor_measure_init_exposure(LIGHT_ADC_CH, SNS0_ID);\n");
		} else {
			fprintf(fout, "#ifdef LIGHT%d_ADC_CH\n", g_sensor_idx);
			fprintf(fout, "\tinit_exposure = sensor_measure_init_exposure(LIGHT%d_ADC_CH, SNS%d_ID);\n", g_sensor_idx, g_sensor_idx);
			fprintf(fout, "#else\n");
			fprintf(fout, "\tinit_exposure = sensor_measure_init_exposure(LIGHT_ADC_CH, SNS%d_ID);\n", g_sensor_idx);
			fprintf(fout, "#endif\n");
		}
		fprintf(fout, "#ifdef CONFIG_VERBOSE\n");
		fprintf(fout, "\tprintf(\"exposure value = %%ld\\n\", init_exposure);\n");
		fprintf(fout, "#endif\n");

		fprintf(fout, "\tsensor_get_exposure_instruction(init_exposure, g_sensor_exposure_command,\n");
		fprintf(fout, "\t                                exposure_command_len, SNS%d_ID);\n", g_sensor_idx);
		fprintf(fout, "\n");
		if (g_sensor_idx == 0) {
			fprintf(fout, "\tif ((strcmp(ret_str, \"env\") != 0) && (strcmp(ret_str, \"hw\") != 0)) {\n");
		} else {
			fprintf(fout,
			        "\tif (ALL_SENSOR_SHARE_LUX == 0 && (strcmp(ret_str, \"env\") != 0) && (strcmp(ret_str, \"hw\") != 0)) {\n");
		}
		fprintf(fout, "\t\ti2c_write_seq(sensor_i2c_addr, g_sensor_exposure_command, exposure_command_len,\n");
		fprintf(fout, "\t\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");
		fprintf(fout, "\t}\n");
	}
	fprintf(fout, "}\n\n");
}

static void gen_start_function(FILE *fout)
{
#ifdef UBOOT_INIT_EXPO
	fprintf(fout, "#define INIT_EXPO (%d)\n\n", UBOOT_INIT_EXPO);
#else
	fprintf(fout, "#define INIT_EXPO (128000)\n\n");
#endif
	fprintf(fout, "void sensor_start%s(int sensor_i2c_addr)\n", f_suffix);
	fprintf(fout, "{\n");
	fprintf(fout, "\tMPI_PATH idx = MPI_INPUT_PATH(0, 0);\n");
	fprintf(fout, "\tconst int initial_sequence_len = sizeof(k_sensor_initial_sequence) / sizeof(SensCmd);\n");
	fprintf(fout, "\tconst int start_command_len = sizeof(k_sensor_start_command) / sizeof(SensCmd);\n");
	if (g_write_fps_cmd) {
		fprintf(fout, "\tconst int fps_command_len = sizeof(g_sensor_fps_command) / sizeof(SensCmd);\n");
	}
	if (g_write_exp_cmd) {
		fprintf(fout,
		        "\tconst int exposure_command_len = sizeof(g_sensor_exposure_command) / sizeof(SensCmd);\n");
		fprintf(fout, "\tlong init_exposure;\n");
	}
	fprintf(fout, "\tchar *ret_str;\n");
	fprintf(fout, "\n");

	fprintf(fout, "\tif (sensor_i2c_addr > 0x7F) { // 7-bit\n");
	fprintf(fout, "\t\tprintf(\"[Sensor Error] Invalid sensor slave address.\\n\");\n");
	fprintf(fout, "\t\treturn;\n");
	fprintf(fout, "\t}\n");
	fprintf(fout, "\n");
	fprintf(fout, "\tcustom_sns(SNS%d_ID).reg_callback(idx);\n", g_sensor_idx);
	fprintf(fout, "\n");
	if (g_write_exp_cmd) {
		if (g_sensor_idx == 0) {
			fprintf(fout, "\tret_str = getenv(\"init_exp\");\n");
		} else {
			fprintf(fout, "\tret_str = getenv(\"init_exp_%d\");\n", g_sensor_idx);
		}
		fprintf(fout, "\tif (ret_str == NULL) {\n");
		fprintf(fout, "\t\tinit_exposure = INIT_EXPO;\n");
		fprintf(fout, "\t} else {\n");
		fprintf(fout, "\t\tinit_exposure = (long)simple_strtoul(ret_str, NULL, 10);\n");
		fprintf(fout, "\t}\n");
		fprintf(fout, "\tg_init_exp[%d] = init_exposure;\n", g_sensor_idx);
	}
	fprintf(fout, "\n");
	fprintf(fout, "\tret_str = LOCK_PARAM_TO_SPEED_UP ? TO_STR(LIGHT_SRC) : getenv(\"lux_src\");\n");
	fprintf(fout, "\n");
	fprintf(fout, "\t// Measure the light meter and switch IR cut as soon as possible\n");
	if (g_sensor_idx == 0) {
		fprintf(fout, "\tif ((strcmp(ret_str, \"env\") == 0) || (strcmp(ret_str, \"hw\") == 0)) {\n");
	} else {
		fprintf(fout,
		        "\tif (ALL_SENSOR_SHARE_LUX || (strcmp(ret_str, \"env\") == 0) || (strcmp(ret_str, \"hw\") == 0)) {\n");
	}
	fprintf(fout, "\t\tsensor_set_fps%s(sensor_i2c_addr);\n", f_suffix);
	fprintf(fout, "\t\tsensor_set_exposure%s(sensor_i2c_addr);\n", f_suffix);
	fprintf(fout, "\t}\n");
	fprintf(fout, "\n");
	fprintf(fout, "\ti2c_write_seq(sensor_i2c_addr, k_sensor_initial_sequence, initial_sequence_len,\n");
	fprintf(fout, "\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");
	fprintf(fout, "\n");
	if (g_sensor_idx == 0) {
		fprintf(fout, "\tif ((strcmp(ret_str, \"env\") == 0) || (strcmp(ret_str, \"hw\") == 0)) {\n");
	} else {
		fprintf(fout,
		        "\tif (ALL_SENSOR_SHARE_LUX || (strcmp(ret_str, \"env\") == 0) || (strcmp(ret_str, \"hw\") == 0)) {\n");
	}
	fprintf(fout, "\t\ti2c_write_seq(sensor_i2c_addr, g_sensor_fps_command, fps_command_len,\n");
	fprintf(fout, "\t\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");
	fprintf(fout, "\t\ti2c_write_seq(sensor_i2c_addr, g_sensor_exposure_command, exposure_command_len,\n");
	fprintf(fout, "\t\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");
	fprintf(fout, "\t} else if (strcmp(ret_str, \"sw\") == 0) {\n");
	if (g_write_fps_cmd) {
		fprintf(fout, "\t\tlong frame_rate = SENSOR_FPS_MAX;\n");
	}
	fprintf(fout, "\n");

	if (g_write_fps_cmd) {
		fprintf(fout, "\t\t// Set initial FPS\n");
		fprintf(fout, "\t\tsensor_get_fps_instruction(frame_rate, g_sensor_fps_command,\n");
		fprintf(fout, "\t\t                           fps_command_len, SNS%d_ID);\n", g_sensor_idx);
		fprintf(fout, "\t\ti2c_write_seq(sensor_i2c_addr, g_sensor_fps_command, fps_command_len,\n");
		fprintf(fout, "\t\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");
	}
	fprintf(fout, "\n");

	if (g_write_exp_cmd) {
		fprintf(fout, "\t\t// Set initial exposure\n");
		fprintf(fout, "\t\tsensor_get_exposure_instruction(init_exposure, g_sensor_exposure_command,\n");
		fprintf(fout, "\t\t                                exposure_command_len, SNS%d_ID);\n", g_sensor_idx);

		fprintf(fout, "\t\ti2c_write_seq(sensor_i2c_addr, g_sensor_exposure_command, exposure_command_len,\n");
		fprintf(fout, "\t\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");
	}
	fprintf(fout, "\t}\n");
	fprintf(fout, "\n");

	fprintf(fout, "\ti2c_write_seq(sensor_i2c_addr, k_sensor_start_command, start_command_len,\n");
	fprintf(fout, "\t              SENSOR_I2C_ADDR_BYTE, SENSOR_I2C_DATA_BYTE);\n");

	fprintf(fout, "}\n");
}

static int gen_sensor_cmos(const char *dir_path)
{
	FILE *fin = NULL;
	FILE *fout = NULL;
	char *file_path = NULL;
	char *buffer = NULL;
	int path_len;
	long fsize;

	/* read mpp/custom/sensor/${sensor}/sensor_cmos.c */
	fin = fopen("sensor_cmos.c", "r");
	if (!fin) {
		fprintf(stderr, "Error: Unable to open file sensor_cmos.c for reading.\n");
		return 1;
	}
	fseek(fin, 0, SEEK_END);
	fsize = ftell(fin);
	fseek(fin, 0, SEEK_SET);

	buffer = malloc(fsize + 1);
	if (!buffer) {
		fprintf(stderr, "Error: Unable to allocate memory for read sensor_cmos.c buffer.\n");
		return 1;
	}
	fread(buffer, fsize, 1, fin);

	/* write file to dir_path */
	path_len = snprintf(NULL, 0, "%s/sensor_cmos%s.c", dir_path, f_suffix) + 1;
	file_path = malloc(path_len);
	if (!file_path) {
		fprintf(stderr, "Error: Unable to allocate memory for file path.\n");
		return 1;
	}
	snprintf(file_path, path_len, "%s/sensor_cmos%s.c", dir_path, f_suffix);

	fout = fopen(file_path, "w");
	if (!fout) {
		fprintf(stderr, "Error: Unable to open file '%s' for writing.\n", file_path);
		free(file_path);
		return 1;
	}

	gen_sensor_cmos_header(fout);
	gen_sensor_cmos_text(fout, buffer, fsize);

	fflush(fout);
	fclose(fout);

	free(file_path);
	free(buffer);

	return 0;
}

static void gen_sensor_cmos_header(FILE *fout)
{
	fprintf(fout, "/*\n");
	fprintf(fout, " * sensor_cmos%s.c: implementation of exposure control and IQ API.\n", f_suffix);
	fprintf(fout, " *\n");
	fprintf(fout, " * Copyright (C) 2014- Augentix Inc.\n");
	fprintf(fout, " *\n");
	fprintf(fout, " * This file is created by codegen, DO NOT COMMIT THIS FILE.\n");
	fprintf(fout, " */\n");
	fprintf(fout, "\n");
}

static void gen_sensor_cmos_text(FILE *fout, char *buffer, long fsize)
{
	char text[150] = { 0 };
	char *param_text = "#include \"sensor_params.h\"";
	char *setting_text = "#include \"sensor_settings.h\"";
	int idx = 0;
	int write_flag = 0;
	int directives_found = 0;
	long i = 0;

	// Read sensor_cmos.c until we find '#include "sensor_params.h"' or
	// '#include "sensor_settings.h"' and replace them. Other valid headers or lines are kept.
	// Note: assume the valid contents start with directives (lines start with #).
	// TODO: rewrite this for loop with getline(3) and use dynamic buffers for each line.
	for (i = 0; i < fsize; i++) {
		if (buffer[i] == '\n') {
			text[idx] = '\0';
			if (!write_flag && text[0] == '#') {
				write_flag = 1;
			}
			if (write_flag) {
				if (strcmp(text, param_text) == 0) {
					fprintf(fout, "#include \"sensor_params%s.h\"\n", f_suffix);
					directives_found |= 1;
				} else if (strcmp(text, setting_text) == 0) {
					fprintf(fout, "#include \"sensor_settings%s.h\"\n", f_suffix);
					directives_found |= 2;
				} else {
					fprintf(fout, "%s\n", text);
				}
				// clear the string to indicate that this string is parsed.
				memset(text, 0, sizeof(text));
				// Note: it's ok that not both of the headers are found.
				// This for loop will still run until every line of charcters is parsed.
				if (directives_found == 3) {
					break;
				}
			}
			idx = 0;
		} else {
			text[idx] = buffer[i];
			idx++;
		}
	}
	if (text[0]) {
		fprintf(fout, "%s\n", text);
	}

	// Dump the rest of the file
	++i;
	if (i < fsize) {
		fwrite(buffer + i, sizeof(char), fsize - i, fout);
	}
}

static int gen_sensor_params(const char *dir_path)
{
	FILE *fout = NULL;
	char *file_path = NULL;
	int path_len;

	/* write file to dir_path */
	path_len = snprintf(NULL, 0, "%s/sensor_params%s.h", dir_path, f_suffix) + 1;
	file_path = malloc(path_len);
	if (!file_path) {
		fprintf(stderr, "Error: Unable to allocate memory for file path.\n");
		return 1;
	}
	snprintf(file_path, path_len, "%s/sensor_params%s.h", dir_path, f_suffix);

	fout = fopen(file_path, "w");
	if (!fout) {
		fprintf(stderr, "Error: Unable to open file '%s' for writing.\n", file_path);
		free(file_path);
		return 1;
	}

	gen_sensor_params_header(fout);

	fflush(fout);
	fclose(fout);

	free(file_path);

	return 0;
}

static void gen_sensor_params_header(FILE *fout)
{
	fprintf(fout, "/*\n");
	fprintf(fout, " * sensor_params%s.h\n", f_suffix);
	fprintf(fout, " *\n");
	fprintf(fout, " * Copyright (C) 2014- Augentix Inc.\n");
	fprintf(fout, " *\n");
	fprintf(fout, " * This file is created by codegen, DO NOT COMMIT THIS FILE.\n");
	fprintf(fout, " */\n");
	fprintf(fout, "\n");

	fprintf(fout, "#ifndef UBOOT_SENSOR_PARAMS%s_H_\n", f_suffix);
	fprintf(fout, "#define UBOOT_SENSOR_PARAMS%s_H_\n", f_suffix);
	fprintf(fout, "\n");

#if defined(SNS_I2C_0)
	fprintf(fout, "#define SNS_I2C_0\n");
#endif
#if defined(SNS_I2C_1)
	fprintf(fout, "#define SNS_I2C_1\n");
#endif
	fprintf(fout, "\n");

#if defined(SENSOR_I2C_SLAVE_ADDR)
	fprintf(fout, "#ifdef SENSOR_I2C_SLAVE_ADDR\n");
	fprintf(fout, "#undef SENSOR_I2C_SLAVE_ADDR\n");
	fprintf(fout, "#endif\n");
	fprintf(fout, "#define SENSOR_I2C_SLAVE_ADDR (0x%02x)\n", SENSOR_I2C_SLAVE_ADDR);
#endif
#if defined(SENSOR_I2C_SLAVE_ADDR1)
	fprintf(fout, "#ifdef SENSOR_I2C_SLAVE_ADDR1\n");
	fprintf(fout, "#undef SENSOR_I2C_SLAVE_ADDR1\n");
	fprintf(fout, "#endif\n");
	fprintf(fout, "#define SENSOR_I2C_SLAVE_ADDR1 (0x%02x)\n", SENSOR_I2C_SLAVE_ADDR1);
#endif
	fprintf(fout, "\n");
	fprintf(fout, "#endif /* UBOOT_SENSOR_PARAMS%s_H_ */\n", f_suffix);
}

static int gen_sensor_cal(int index, const char *dir_path)
{
	FILE *fout = NULL;
	char *file_path = NULL;
	int path_len;
	int ret;

	path_len = snprintf(NULL, 0, "%s/sensor_cal%s.h", dir_path, f_suffix) + 1;
	file_path = malloc(path_len);
	if (!file_path) {
		fprintf(stderr, "Error: Unable to allocate memory for file path.\n");
		return 1;
	}
	ret = snprintf(file_path, path_len, "%s/sensor_cal%s.h", dir_path, f_suffix);
	if (ret == path_len) {
		// failsafe
		file_path[path_len - 1] = '\0';
	}

	fout = fopen(file_path, "w");
	if (!fout) {
		fprintf(stderr, "Error: Unable to open file '%s' for writing.\n", file_path);
		free(file_path);
		return 1;
	}

	gen_sensor_cal_header(fout, index);

	fflush(fout);
	fclose(fout);
	free(file_path);

	return 0;
}

static void gen_sensor_cal_header(FILE *fout, int index)
{
	// File comments
	fprintf(fout, "/*\n");
	fprintf(fout, " * sensor_cal%s.h: IQ settings for Early AE.\n", f_suffix);
	fprintf(fout, " *\n");
	fprintf(fout, " * Copyright (C) 2014- Augentix Inc.\n");
	fprintf(fout, " *\n");
	fprintf(fout, " * This file is created by codegen, DO NOT COMMIT THIS FILE.\n");
	fprintf(fout, " */\n");
	fprintf(fout, "\n");

	// define guard
	fprintf(fout, "#ifndef UBOOT_SENSOR_CAL%s_H_\n", f_suffix);
	fprintf(fout, "#define UBOOT_SENSOR_CAL%s_H_\n", f_suffix);
	fprintf(fout, "\n");

	// Required headers in uboot/driver/agtx_video
	fprintf(fout, "#include \"is_setting.h\"\n");
	fprintf(fout, "\n");

	// DBC
	fprintf(fout, "static struct is_dbc_cfg dbc_init_cfg_%d = {\n", g_sensor_idx);
	fprintf(fout, "\t.mode = IS_DBC_MODE_NORMAL,\n");
	fprintf(fout, "\t.level = {\n");
	fprintf(fout, "\t\t");
	for (int i = 0; i < 4; i++) {
		// G0, R, B, G1
		fprintf(fout, "%d, ", g_dbc_level[i]);
	}
	// S
	fprintf(fout, "%d,\n", g_dbc_level[0]);
	fprintf(fout, "\t},\n");
	fprintf(fout, "};\n");
	fprintf(fout, "\n");

	// DCC
	fprintf(fout, "static struct is_dcc_cfg dcc_init_cfg_%d = {\n", g_sensor_idx);
	fprintf(fout, "\t.mode = IS_DCC_MODE_NORMAL,\n");
	fprintf(fout, "\t.gain = {\n");
	fprintf(fout, "\t\t");
	for (int i = 0; i < 4; i++) {
		// G0, R, B, G1
		fprintf(fout, "%d, ", g_dcc_gain[i]);
	}
	// S
	fprintf(fout, "%d,\n", g_dcc_gain[0]);
	fprintf(fout, "\t},\n");
	fprintf(fout, "\t.offset_2s = {\n");
	fprintf(fout, "\t\t");
	for (int i = 0; i < 4; i++) {
		// G0, R, B, G1
		fprintf(fout, "%d, ", g_dcc_offset_2s[i]);
	}
	// S
	fprintf(fout, "%d,\n", g_dcc_offset_2s[0]);
	fprintf(fout, "\t},\n");
	fprintf(fout, "};\n");
	fprintf(fout, "\n");

	// define guard
	fprintf(fout, "#endif\n");
}
