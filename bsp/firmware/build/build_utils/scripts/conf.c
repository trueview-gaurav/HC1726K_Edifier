#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define AMP_MEM_LAYOUT                                                                                  \
	"#define AMP_SHM_START_ADDR ((CONFIG_DRAM_CAPACITY * 1024 * 1024) - CONFIG_SYS_MEM_TOP_HIDE)\n" \
	"#define AMP_SHM_TOTAL_SIZE CONFIG_SYS_MEM_TOP_HIDE\n"                                          \
	"#define AMP_AMPC_SHM_ADDR AMP_SHM_START_ADDR\n"                                                \
	"#define AMP_AMPC_SHM_SIZE (60 * 1024)\n"                                                       \
	"#define AMP_DRIVER_SHM_ADDR (AMP_SHM_START_ADDR + (60 * 1024))\n"                              \
	"#define AMP_DRIVER_SHM_SIZE (4 * 1024)\n"                                                      \
	"#define AMP_FREERTOS_START_ADDR (AMP_SHM_START_ADDR + (64 * 1024))\n"                          \
	"#define AMP_FREERTOS_MEM_SIZE (AMP_SHM_TOTAL_SIZE - (64 * 1024))\n"

struct config {
	const char * config_file;
	const char * output_header;
};

void printUsage(const char* progname)
{
	printf("Usage:\t%s <config-file> <output-header>\n", progname);
}

int parseCmd(int ac, char **av, struct config *cfg)
{
	if (ac != 3)
		return EXIT_FAILURE;

	cfg->config_file = strdup(av[1]);
	cfg->output_header = strdup(av[2]);
	return EXIT_SUCCESS;
}

int genAutoconf(struct config * cfg)
{
	FILE *infp = NULL, *outfp = NULL;
	const char *config_file = cfg->config_file;
	const char *output_header = cfg->output_header;
	int ret = EXIT_SUCCESS;
	int sensor_cnt = 0;
	size_t len;
	ssize_t read;
	char yes[2] = "y";
	char *line = NULL;;
	char *cfg_item = NULL, *value = NULL;

	infp = fopen(config_file, "r");
	if (infp == NULL) {
		printf("Failed to open file \"%s\"!\n", config_file);
		ret = EXIT_FAILURE;
		goto infp_fail;
	}

	outfp = fopen(output_header, "w");
	if (outfp == NULL) {
		printf("Failed to open file \"%s\" !\n", output_header);
		ret = EXIT_FAILURE;
		goto outfp_fail;
	}

	/* Print banner message */
	fprintf(outfp, "/*\n * Automatically generated file; DO NOT EDIT.\n */\n");

	while ((read = getline(&line, &len, infp)) != -1) {
		if ((len == 0) ||
		    (line[0] == '#') ||
		    (line[0] == '\n'))
			continue;

		cfg_item = strtok(line, "=\t\n ");
		if (cfg_item == NULL)
			continue;

		if (strncmp(cfg_item, "SENSOR", 6) == 0) {
			value = strtok(NULL, "\t\n ");
			if (value) {
				sensor_cnt += 1;
			}
			continue;
		}

		if (strncmp(cfg_item, "CONFIG_", 7)) {
			continue;
		}

		value = strtok(NULL, "\t\n ");
		if (value == NULL) {
			printf("[ERROR]: config \"%s\": Value not identified!\n",
					cfg_item);
			ret = EXIT_FAILURE;
			goto excp;
		}

		if (!strcmp(value, yes)) {
			fprintf(outfp, "#define %s 1\n", cfg_item);
			if (!strncmp(cfg_item, "CONFIG_AMP", 10)) {
				fprintf(outfp, "/** AMP Memory layout definitions **/\n");
				fprintf(outfp, AMP_MEM_LAYOUT);
				fprintf(outfp, "/** End of AMP Memory layout definitions **/\n");
			}
		} else
			fprintf(outfp, "#define %s %s\n", cfg_item, value);
	}

	if (sensor_cnt == 2) {
		fprintf(outfp, "#define CONFIG_DUAL_SENSOR_SUPPORT 1\n");
	}
excp:
	fclose(outfp);
outfp_fail:
	fclose(infp);
infp_fail:
	return ret;
}

int main(int ac, char **av)
{
	const char *progname = av[0];
	struct config cfg;
	int ret;

	ret = parseCmd(ac, av, &cfg);
	if (ret) {
		printUsage(progname);
		return EXIT_FAILURE;
	}

	ret = genAutoconf(&cfg);
	if (ret) {
		printf("Error: Failed to generate autoconf.h!\n");
		return EXIT_FAILURE;
	}

	free((void *)cfg.config_file);
	cfg.config_file = NULL;
	free((void *)cfg.output_header);
	cfg.output_header = NULL;
	return EXIT_SUCCESS;
}
