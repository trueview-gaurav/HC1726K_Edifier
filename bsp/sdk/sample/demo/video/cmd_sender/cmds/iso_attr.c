#include "cmdparser.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "mpi_dip_alg.h"

#include "cmd_util.h"

#define NUM_ISO_ATTR (1 + 1 * MPI_ISO_LUT_ENTRY_NUM + 2) // 19

static INT32 GET(IsoAttr)(CMD_DATA_S *opt)
{
	return MPI_getIsoAttr(opt->path_idx, opt->data);
}

static INT32 SET(IsoAttr)(const CMD_DATA_S *opt)
{
	return MPI_setIsoAttr(opt->path_idx, opt->data);
}

static void ARGS(IsoAttr)(void)
{
	printf("\t'--iso dev_idx path_idx mode iso_auto.effective_iso[0 ~ MPI_ISO_LUT_ENTRY_NUM-1] iso_manual.effective_iso iso_type'\n");
	printf("\t'--iso 0 0 0 100 200 400 800 1600 3200 6400 12800 25600 51200 102400 102400 102400 102400 102400 102400 100 0'\n");
}

static void HELP(IsoAttr)(const char *str)
{
	CMD_PRINT_HELP(str, "'--iso <MPI_PATH> [ISO_ATTR]'", "Set ISO attributes");
}

static void SHOW(IsoAttr)(const CMD_DATA_S *opt)
{
	MPI_ISO_ATTR_S *attr = (MPI_ISO_ATTR_S *)(opt->data);
	int i;

	printf("device index: %d, path index: %d\n", opt->path_idx.dev, opt->path_idx.path);
	printf("mode=%d\n", attr->mode);
	for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
		printf("iso_auto.effective_iso[%d]=%d\n", i, attr->iso_auto.effective_iso[i]);
	}
	printf("iso_manual.effective_iso=%d\n", attr->iso_manual.effective_iso);
	printf("iso_type=%d\n", attr->iso_type);
}

static int PARSE(IsoAttr)(int argc, char **argv, CMD_DATA_S *opt)
{
	MPI_ISO_ATTR_S *iso = (MPI_ISO_ATTR_S *)opt->data;
	int num = argc - optind;
	int i;

	if (num == (NUM_ISO_ATTR + 2)) {
		opt->action = CMD_ACTION_SET;
		opt->path_idx.dev = atoi(argv[optind]);
		optind++;
		opt->path_idx.path = atoi(argv[optind]);
		optind++;

		iso->mode = atoi(argv[optind]);
		optind++;

		for (i = 0; i < MPI_ISO_LUT_ENTRY_NUM; ++i) {
			iso->iso_auto.effective_iso[i] = atoi(argv[optind]);
			optind++;
		}

		iso->iso_manual.effective_iso = atoi(argv[optind]);
		optind++;
		iso->iso_type = atoi(argv[optind]);
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

static CMD_S iso_ops = MAKE_CMD("iso", MPI_ISO_ATTR_S, IsoAttr);

__attribute__((constructor)) void regIsoCmd(void)
{
	CMD_register(&iso_ops);
}