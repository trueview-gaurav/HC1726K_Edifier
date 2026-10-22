#include "cmdparser.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "mpi_dip_alg.h"

#include "cmd_util.h"

#define NUM_TE_ATTR (4 + MPI_TE_CURVE_ENTRY_NUM + 8 * MPI_ISO_LUT_ENTRY_NUM) // 192

static INT32 GET(TeAttr)(CMD_DATA_S *opt)
{
	return MPI_getTeAttr(opt->path_idx, opt->data);
}

static INT32 SET(TeAttr)(const CMD_DATA_S *opt)
{
	return MPI_setTeAttr(opt->path_idx, opt->data);
}

static void ARGS(TeAttr)(void)
{
	printf("\t'--te dev_idx path_idx mode te_normal.curve[0 ~ MPI_TE_CURVE_ENTRY_NUM-1] \
	te_adpat.dark_enhance[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] te_adapt.te_adapt_based_type \
	te_adpat.str_auto[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] te_adapt.speed te_adpat.white_th[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] \
	te_adpat.black_th[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] te_adpat.max_str[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] \
	te_adpat.dark_protect_smooth[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] te_adpat.dark_protect_str[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] \
	te_adapt.max_str_prec_sel te_adapt.dark_enhance_th[0 ~ MPI_ISO_LUT_ENTRY_NUM-1]'\n");
	printf("\t'--te 0 0 0 0 16 32 64 113 172 230 280 340 460 580 600 740 880 1030 1200 1370 1540 1700 1860 2048 2176 2304 \
	2432 2560 2816 3072 3328 3584 3840 4096 4352 4608 4864 5120 5376 5632 5888 6144 6400 6656 7168 7680 8192 8704 9216 9728 \
	10240 10752 11264 11776 12288 12800 13312 13824 14336 14848 15360 15872 16384 \
	8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 102 \
	15040 15040 15040 15040 15040 15040 15040 15040 15040 15040 15040 15040 15040 15040 15040 15040 512 512 512 512 512 512 512 512 512 512 512 512 512 512 512 512 \
	7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 7 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 \
	0 2048 2048 2048 2048 2048 2048 2048 2048 2048 2048 2048 2048 2048 2048 2048 2048\n");
}

static void HELP(TeAttr)(const char *str)
{
	CMD_PRINT_HELP(str, "'--te <MPI_PATH> [TE_ATTR]'", "Set TE attributes");
}

static void SHOW(TeAttr)(const CMD_DATA_S *opt)
{
	MPI_TE_ATTR_S *attr = (MPI_TE_ATTR_S *)opt->data;
	int i;

	printf("device index: %d, path index: %d\n", opt->path_idx.dev, opt->path_idx.path);
	printf("mode=%d (0: NORMAL, 3:ADAPT)\n", attr->mode);

	for (i = 0; i < MPI_TE_CURVE_ENTRY_NUM; ++i) {
		printf("te_normal.curve[%d]=%d\n", i, attr->te_normal.curve[i]);
	}

	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.dark_enhance[%d] = %d\n", i, attr->te_adapt.dark_enhance[i]);
	}
	printf("te_adapt.te_adapt_based_type= %d (0: TE_ADAPT_NL_BASED, 1: TE_ADAPT_INTTIME_BASED , 2: TE_ADAPT_EV_BASED ,3: TE_ADAPT_BASED_TYPE_RSV)\n",
	       attr->te_adapt.te_adapt_based_type);
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.str_auto[%d] = %d\n", i, attr->te_adapt.str_auto[i]);
	}
	printf("te_adapt.speed= %d\n", attr->te_adapt.speed);
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.white_th[%d] = %d\n", i, attr->te_adapt.white_th[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.black_th[%d] = %d\n", i, attr->te_adapt.black_th[i]);
	}
	printf("te_adapt.max_str_prec_sel= %d\n", attr->te_adapt.max_str_prec_sel);
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.max_str[%d] = %d\n", i, attr->te_adapt.max_str[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.dark_protect_smooth[%d] = %d\n", i, attr->te_adapt.dark_protect_smooth[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.dark_protect_str[%d] = %d\n", i, attr->te_adapt.dark_protect_str[i]);
	}
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; i++) {
		printf("te_adapt.dark_enhance_th[%d] = %d\n", i, attr->te_adapt.dark_enhance_th[i]);
	}
}

static int PARSE(TeAttr)(int argc, char **argv, CMD_DATA_S *opt)
{
	MPI_TE_ATTR_S *data = (MPI_TE_ATTR_S *)opt->data;
	int num = argc - optind;
	int i;

	if (num == (NUM_TE_ATTR + 2)) {
		opt->action = CMD_ACTION_SET;
		opt->path_idx.dev = atoi(argv[optind]);
		optind++;
		opt->path_idx.path = atoi(argv[optind]);
		optind++;

		data->mode = atoi(argv[optind]);
		optind++;

		for (i = 0; i < MPI_TE_CURVE_ENTRY_NUM; ++i) {
			data->te_normal.curve[i] = atoi(argv[optind]);
			optind++;
		}

		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.dark_enhance[i] = atoi(argv[optind]);
			optind++;
		}
		data->te_adapt.te_adapt_based_type = atoi(argv[optind]);
		optind++;
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.str_auto[i] = atoi(argv[optind]);
			optind++;
		}
		data->te_adapt.speed = atoi(argv[optind]);
		optind++;
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.white_th[i] = atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.black_th[i] = atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.max_str[i] = atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.dark_protect_smooth[i] = atoi(argv[optind]);
			optind++;
		}
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.dark_protect_str[i] = atoi(argv[optind]);
			optind++;
		}
		data->te_adapt.max_str_prec_sel = atoi(argv[optind]);
		optind++;
		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->te_adapt.dark_enhance_th[i] = atoi(argv[optind]);
			optind++;
		}

	} else if (num == 2) {
		opt->action = CMD_ACTION_GET;
		opt->path_idx.dev = atoi(argv[optind]);
		optind++;
		opt->path_idx.path = atoi(argv[optind]);
		optind++;
	} else {
		return -EINVAL;
	}

	return 0;
}

static CMD_S te_ops = MAKE_CMD("te", MPI_TE_ATTR_S, TeAttr);

__attribute__((constructor)) void regTeCmd(void)
{
	CMD_register(&te_ops);
}
