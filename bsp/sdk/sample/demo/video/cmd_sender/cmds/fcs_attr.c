#include "cmdparser.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "mpi_dip_alg.h"

#include "cmd_util.h"

#define NUM_FCS_ATTR (1 + 1 * MPI_ISO_LUT_ENTRY_NUM + 1) // 18

static INT32 GET(FcsAttr)(CMD_DATA_S *opt)
{
	return MPI_getFcsAttr(opt->path_idx, opt->data);
}

static INT32 SET(FcsAttr)(const CMD_DATA_S *opt)
{
	return MPI_setFcsAttr(opt->path_idx, opt->data);
}

static void ARGS(FcsAttr)(void)
{
	printf("\t'--fcs dev_idx path_idx mode fcs_auto.strength[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] fcs_manual.strength'\n");
	printf("\t'--fcs 0 0 0 150 140 130 120 100 90 0 0 0 0 0 0 0 0 0 0 0\n");
}

static void HELP(FcsAttr)(const char *str)
{
	CMD_PRINT_HELP(str, "'--fcs <MPI_PATH> [FCS_ATTR]'", "Set FCS attributes");
}

static void SHOW(FcsAttr)(const CMD_DATA_S *opt)
{
	MPI_FCS_ATTR_S *attr = (MPI_FCS_ATTR_S *)opt->data;
	int i;

	printf("device index: %d, path index: %d\n", opt->path_idx.dev, opt->path_idx.path);
	printf("mode=%d (0: auto, 2: manual)\n", attr->mode);
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
		printf("fcs_auto.strength[%d]=%d\n", i, attr->fcs_auto.strength[i]);
	}
	printf("fcs_manual.strength=%d\n", attr->fcs_manual.strength);
}

static int PARSE(FcsAttr)(int argc, char **argv, CMD_DATA_S *opt)
{
	MPI_FCS_ATTR_S *data = (MPI_FCS_ATTR_S *)opt->data;
	int num = argc - optind;
	int i;

	if (num == (NUM_FCS_ATTR + 2)) {
		opt->action = CMD_ACTION_SET;
		opt->path_idx.dev = atoi(argv[optind]);
		optind++;
		opt->path_idx.path = atoi(argv[optind]);
		optind++;

		data->mode = atoi(argv[optind]);
		optind++;

		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			data->fcs_auto.strength[i] = atoi(argv[optind]);
			optind++;
		}

		data->fcs_manual.strength = atoi(argv[optind]);
		optind++;
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

static CMD_S fcs_ops = MAKE_CMD("fcs", MPI_FCS_ATTR_S, FcsAttr);

__attribute__((constructor)) void regFcsCmd(void)
{
	CMD_register(&fcs_ops);
}