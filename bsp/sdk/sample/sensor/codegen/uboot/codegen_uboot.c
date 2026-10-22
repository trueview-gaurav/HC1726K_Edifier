#include <stdio.h>

#include "mpi_dip_sns.h"
#include "sensor.h"

#include "codegen_uboot.h"

#if defined(SNS0_ID)
extern CUSTOM_SNS_CTRL_S custom_sns(SNS0_ID);
#elif defined(SNS1_ID)
extern CUSTOM_SNS_CTRL_S custom_sns(SNS1_ID);
#endif

int main(int argc, char *argv[])
{
	char *uboot_sns_path = NULL;
	MPI_PATH idx;
	int ret = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s uboot_sns_dir\n", argv[0]);
		return 1;
	}

	uboot_sns_path = argv[1];

	idx = MPI_INPUT_PATH(0, 0);

#if defined(SNS0_ID)
	custom_sns(SNS0_ID).reg_callback(idx);
#elif defined(SNS1_ID)
	custom_sns(SNS1_ID).reg_callback(idx);
#endif

	ret = gen_uboot_file(idx, uboot_sns_path);

	if (ret) {
		fprintf(stderr, "Error: not all files are generated correctly.\n");
		return 1;
	}

	return 0;
}
