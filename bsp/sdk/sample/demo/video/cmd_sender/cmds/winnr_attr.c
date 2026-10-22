#include "cmdparser.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "mpi_dip_alg.h"

#include "cmd_util.h"

#define NUM_NR_COMMON_ATTR (11)
#define NUM_NR_AUTO_MANUAL_SET (5)
#define NUM_NR_AUTO_MANUAL_ATTR (((MPI_ISO_LUT_ENTRY_NUM) + 1) * (NUM_NR_AUTO_MANUAL_SET)) // 85
#define NUM_NR_ALL_ATTR ((NUM_NR_COMMON_ATTR) + (NUM_NR_AUTO_MANUAL_ATTR)) // 96

static INT32 GET(WinNr)(CMD_DATA_S *opt)
{
	return MPI_getWinNrAttr(opt->win_idx, opt->data);
}

static INT32 SET(WinNr)(const CMD_DATA_S *opt)
{
	return MPI_setWinNrAttr(opt->win_idx, opt->data);
}

static void ARGS(WinNr)(void)
{
	printf("\t'--winnr dev_idx chn_idx win_idx mode nr_auto.y_level_3d[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] "
	       "nr_auto.c_level_3d[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] nr_auto.y_level_2d[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] "
	       "nr_auto.c_level_2d[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] nr_auto.fss_y_level_3d[0 ~ MPI_ISO_LUT_ENTRY_NUM-1]\n");
	printf("\t      nr_manual.y_level_3d nr_manual.c_level_3d nr_manual.y_level_2d nr_manual.c_level_2d "
	       "nr_manual.fss_y_level_3d motion_comp ma_y_strength mc_y_strength "
	       "ma_c_strength ratio_3d mc_y_level_offset me_frame_fallback_en fss_ratio_min fss_ratio_max lut_type'\n");
	printf("\twhere MPI_ISO_LUT_ENTRY_NUM = %d\n", MPI_ISO_LUT_ENTRY_NUM);
	printf("\t'--winnr 0 0 0 0 119 136 153 170 180 204 221 238 255 255 255 255 255 255 255 255 16 32 64 67 100 100 100 100 100 100 100 100 100 100 100 100 "
	       "255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 "
	       "119 136 153 170 180 204 221 238 255 255 255 255 255 255 255 255'\n");
	printf("\t'     128 128 128 128 128 2 30 31 4 0 0 0 993 1014 1'\n");
}

static void HELP(WinNr)(const char *str)
{
	CMD_PRINT_HELP(str, "'--winnr <MPI_WIN> [NR_ATTR]'", "Set NR attributes");
}

static void SHOW(WinNr)(const CMD_DATA_S *opt)
{
	const MPI_NR_ATTR_S *attr = (MPI_NR_ATTR_S *)opt->data;
	int i;

	printf("device index: %d, channel index: %d, window index: %d\n", opt->win_idx.dev, opt->win_idx.chn,
	       opt->win_idx.win);
	printf("mode=%d\n", attr->mode);
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
		printf("nr_auto.y_level_3d[%d]=%hhu\n", i, attr->nr_auto.y_level_3d[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
		printf("nr_auto.c_level_3d[%d]=%hhu\n", i, attr->nr_auto.c_level_3d[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
		printf("nr_auto.y_level_2d[%d]=%hhu\n", i, attr->nr_auto.y_level_2d[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
		printf("nr_auto.c_level_2d[%d]=%hhu\n", i, attr->nr_auto.c_level_2d[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
		printf("nr_auto.fss_y_level_3d[%d]=%hhu\n", i, attr->nr_auto.fss_y_level_3d[i]);
	}
	printf("nr_manual.y_level_3d=%hhu\n", attr->nr_manual.y_level_3d);
	printf("nr_manual.c_level_3d=%hhu\n", attr->nr_manual.c_level_3d);
	printf("nr_manual.y_level_2d=%hhu\n", attr->nr_manual.y_level_2d);
	printf("nr_manual.c_level_2d=%hhu\n", attr->nr_manual.c_level_2d);
	printf("nr_manual.fss_y_level_3d=%hhu\n", attr->nr_manual.fss_y_level_3d);
	printf("motion_comp=%hhu\n", attr->motion_comp);
	printf("ma_y_strength=%hhu\n", attr->ma_y_strength);
	printf("mc_y_strength=%hhu\n", attr->mc_y_strength);
	printf("ma_c_strength=%hhu\n", attr->ma_c_strength);
	printf("ratio_3d=%hhu\n", attr->ratio_3d);
	printf("mc_y_level_offset=%hd\n", attr->mc_y_level_offset);
	printf("me_frame_fallback_en=%hhu\n", attr->me_frame_fallback_en);
	printf("fss_ratio_min=%hu\n", attr->fss_ratio_min);
	printf("fss_ratio_max=%hu\n", attr->fss_ratio_max);
	printf("lut_type=%d\n", attr->lut_type);
}

static int PARSE(WinNr)(int argc, char **argv, CMD_DATA_S *opt)
{
	MPI_NR_ATTR_S *data = (MPI_NR_ATTR_S *)opt->data;
	const int num = argc - optind;
	int i;

	if (num == (NUM_NR_ALL_ATTR + 3)) {
		opt->action = CMD_ACTION_SET;
		opt->win_idx.dev = (uint8_t)atoi(argv[optind]);
		optind++;
		opt->win_idx.chn = (uint8_t)atoi(argv[optind]);
		optind++;
		opt->win_idx.win = (uint8_t)atoi(argv[optind]);
		optind++;

		data->mode = atoi(argv[optind]);
		optind++;

		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->nr_auto.y_level_3d[i] = (uint8_t)atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->nr_auto.c_level_3d[i] = (uint8_t)atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->nr_auto.y_level_2d[i] = (uint8_t)atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->nr_auto.c_level_2d[i] = (uint8_t)atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->nr_auto.fss_y_level_3d[i] = (uint8_t)atoi(argv[optind]);
			optind++;
		}

		data->nr_manual.y_level_3d = (uint8_t)atoi(argv[optind]);
		optind++;
		data->nr_manual.c_level_3d = (uint8_t)atoi(argv[optind]);
		optind++;
		data->nr_manual.y_level_2d = (uint8_t)atoi(argv[optind]);
		optind++;
		data->nr_manual.c_level_2d = (uint8_t)atoi(argv[optind]);
		optind++;
		data->nr_manual.fss_y_level_3d = (uint8_t)atoi(argv[optind]);
		optind++;
		data->motion_comp = (uint8_t)atoi(argv[optind]);
		optind++;
		data->ma_y_strength = (uint8_t)atoi(argv[optind]);
		optind++;
		data->mc_y_strength = (uint8_t)atoi(argv[optind]);
		optind++;
		data->ma_c_strength = (uint8_t)atoi(argv[optind]);
		optind++;
		data->ratio_3d = (uint8_t)atoi(argv[optind]);
		optind++;
		data->mc_y_level_offset = (int16_t)atoi(argv[optind]);
		optind++;
		data->me_frame_fallback_en = (uint8_t)atoi(argv[optind]);
		optind++;
		data->fss_ratio_min = (uint16_t)atoi(argv[optind]);
		optind++;
		data->fss_ratio_max = (uint16_t)atoi(argv[optind]);
		optind++;
		data->lut_type = atoi(argv[optind]);
		optind++;
	} else if (num == 3) {
		opt->action = CMD_ACTION_GET;
		opt->win_idx.dev = (uint8_t)atoi(argv[optind]);
		optind++;
		opt->win_idx.chn = (uint8_t)atoi(argv[optind]);
		optind++;
		opt->win_idx.win = (uint8_t)atoi(argv[optind]);
		optind++;
	} else {
		return -EINVAL;
	}

	return 0;
}

static CMD_S winnr_ops = MAKE_CMD("winnr", MPI_NR_ATTR_S, WinNr);

__attribute__((constructor)) void regWinNrCmd(void)
{
	CMD_register(&winnr_ops);
}
