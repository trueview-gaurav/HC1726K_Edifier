#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codegen_kernel_pm.h"

#define STR(NAME) _STR(NAME)
#define _STR(NAME) #NAME

struct program_option {
	int idx;
	const char *dst_dir;
	const char *src_dir;
};

void parse_option(int argc, char *argv[], struct program_option *option);

int main(int argc, char *argv[])
{
	struct program_option option;
	int ret;

	parse_option(argc, argv, &option);

	char *dst_file;
	char *src_file;
	int filename_len;
	filename_len = snprintf(NULL, 0, "%s/sensor_pm_sns%d.c", option.dst_dir, option.idx);
	dst_file = malloc(filename_len + 1);
	if (!dst_file) {
		fprintf(stderr, "Unable to allocate memory for the process.\n");
		return 1;
	}
	snprintf(dst_file, filename_len + 1, "%s/sensor_pm_sns%d.c", option.dst_dir, option.idx);
	filename_len = snprintf(NULL, 0, "%s/%s_pm.c", option.src_dir, STR(SENSOR_NAME));
	src_file = malloc(filename_len + 1);
	if (!src_file) {
		fprintf(stderr, "Unable to allocate memory for the process.\n");
		return 1;
	}
	snprintf(src_file, filename_len + 1, "%s/%s_pm.c", option.src_dir, STR(SENSOR_NAME));

	ret = generate_pm_file(option.idx, dst_file, src_file);

	free(dst_file);
	free(src_file);

	return ret;
}

void parse_option(int argc, char *argv[], struct program_option *option)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: %s idx dst_dir src_dir\n", argv[0]);
		exit(1);
	}

	option->idx = atoi(argv[1]);
	option->dst_dir = argv[2];
	option->src_dir = argv[3];
}
