#include "cmdparser.h"

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mpi_dip_alg.h"

#include "cmd_util.h"

#define NUM_WDR_ATTR (2)

static INT32 GET(WdrAttr)(CMD_DATA_S *opt)
{
	return MPI_getWdrAttr(opt->path_idx, opt->data);
}

static INT32 SET(WdrAttr)(const CMD_DATA_S *opt)
{
	return MPI_setWdrAttr(opt->path_idx, opt->data);
}

static void ARGS(WdrAttr)(void)
{
	printf("\t'--wdr dev_idx path_idx wdr_mode wdr_strength\n");
	printf("\t'--wdr 0 0 0 0'\n");
}

static void HELP(WdrAttr)(const char *str)
{
	CMD_PRINT_HELP(str, "'--wdr <MPI_PATH> [WDR_ATTR]'", "Set WDR attributes");
}

static void SHOW(WdrAttr)(const CMD_DATA_S *opt)
{
	MPI_WDR_ATTR_S *attr = (MPI_WDR_ATTR_S *)opt->data;

	printf("device index: %d, path index: %d\n", opt->path_idx.dev, opt->path_idx.path);
	printf("wdr_en=%d\n", attr->wdr_en);
	printf("wdr_strength=%d\n", attr->wdr_strength);
}

static int PARSE(WdrAttr)(int argc, char **argv, CMD_DATA_S *opt)
{
	MPI_WDR_ATTR_S *data = (MPI_WDR_ATTR_S *)opt->data;
	int num = argc - optind;

	if (num == (NUM_WDR_ATTR + 2)) {
		opt->action = CMD_ACTION_SET;
		opt->path_idx.dev = atoi(argv[optind]);
		optind++;
		opt->path_idx.path = atoi(argv[optind]);
		optind++;

		data->wdr_en = atoi(argv[optind]);
		optind++;
		data->wdr_strength = atoi(argv[optind]);
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

static CMD_S wdr_ops = MAKE_CMD("wdr", MPI_WDR_ATTR_S, WdrAttr);

__attribute__((constructor)) void regWdrCmd(void)
{
	CMD_register(&wdr_ops);
}
