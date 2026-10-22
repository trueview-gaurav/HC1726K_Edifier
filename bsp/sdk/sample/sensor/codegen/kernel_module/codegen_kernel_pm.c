#include "codegen_kernel_pm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sendfile.h>

#include "sensor_params.h"
#include "sensor_settings.h"

// SENSOR_NAME should be defined by Makefile
// #define SENSOR_NAME sc301iot
#define SUSPEND_FUNC(SNS) _SUSPEND_FUNC(SNS)
#define _SUSPEND_FUNC(SNS) (#SNS "_suspend")
#define RESUME_FUNC(SNS) _RESUME_FUNC(SNS)
#define _RESUME_FUNC(SNS) (#SNS "_resume")
#define INIT_FUNC(SNS) _INIT_FUNC(SNS)
#define _INIT_FUNC(SNS) (#SNS "_init_data")

#define CMD_BUF_LEN (1024)

int generate_pm_file(int sensor_idx, const char *dst_fname, const char *src_fname)
{
	int ret;
	// Create the file
	int fd_dst = -1;
	int fd_src = -1;

	fd_dst = creat(dst_fname, 0660);
	if (fd_dst < 0) {
		fprintf(stderr, "Error: Unable to create destination file '%s', err = %d.\n", dst_fname, errno);
		goto dst_error;
	}
	fd_src = open(src_fname, O_RDONLY);
	if (fd_src < 0) {
		fprintf(stderr, "Error: Unable to open the source file '%s', err = %d.\n", src_fname, errno);
		goto src_error;
	}

	// Copy the file
	// We cannot simply use cp since cp always ask if you want to overwrite a file if '-i' flag presents,
	// even if '-f' flag is specified.
	// So we truncated the destination file and copy every content by ourselves.
	struct stat file_stat;
	fstat(fd_src, &file_stat);
	ret = sendfile(fd_dst, fd_src, NULL, file_stat.st_size);
	if (ret < 0) {
		fprintf(stderr, "Error: Unable to copy the file content, err = %d.\n", errno);
		goto misc_error;
	}
	close(fd_src);
	close(fd_dst);

	// Replace function names and macros
	// This is too complicated so we will just call sed through shell to help us
	char cmd_buffer[CMD_BUF_LEN];
	int slen;

#define CHECK_CMD_LEN()                                                                         \
	do {                                                                                    \
		if (slen >= CMD_BUF_LEN) {                                                      \
			fprintf(stderr, "Error: The command is too long to be constructed.\n"); \
			goto dst_error;                                                         \
		}                                                                               \
	} while (0)

	slen = snprintf(cmd_buffer, CMD_BUF_LEN, "sed -i 's/%s/sns%d_suspend/' \"%s\"", SUSPEND_FUNC(SENSOR_NAME),
	                sensor_idx, dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);
	slen = snprintf(cmd_buffer, CMD_BUF_LEN, "sed -i 's/%s/sns%d_resume/' \"%s\"", RESUME_FUNC(SENSOR_NAME),
	                sensor_idx, dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);
	slen = snprintf(cmd_buffer, CMD_BUF_LEN, "sed -i 's/%s/sns%d_init_data/' \"%s\"", INIT_FUNC(SENSOR_NAME),
	                sensor_idx, dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);

#ifdef SENSOR_I2C_SLAVE_ADDR
	unsigned int slave_addr = SENSOR_I2C_SLAVE_ADDR;

#ifdef SENSOR_I2C_SLAVE_ADDR1
	if (sensor_idx == 1) {
		slave_addr = SENSOR_I2C_SLAVE_ADDR1;
	}
#endif
#ifdef SENSOR_I2C_SLAVE_ADDR2
	if (sensor_idx == 2) {
		slave_addr = SENSOR_I2C_SLAVE_ADDR2;
	}
#endif
#ifdef SENSOR_I2C_SLAVE_ADDR3
	if (sensor_idx == 3) {
		slave_addr = SENSOR_I2C_SLAVE_ADDR3;
	}
#endif
	slen = snprintf(cmd_buffer, CMD_BUF_LEN,"sed -i 's/SENSOR_I2C_SLAVE_ADDR/0x%x/g' \"%s\"", slave_addr, dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);
#endif

#ifdef SENSOR_I2C_REG_LENGTH
	slen = snprintf(cmd_buffer, CMD_BUF_LEN, "sed -i 's/SENSOR_I2C_REG_LENGTH/%d/g' \"%s\"", SENSOR_I2C_REG_LENGTH,
	                dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);
#endif
#ifdef SENSOR_I2C_DAT_LENGTH
	slen = snprintf(cmd_buffer, CMD_BUF_LEN, "sed -i 's/SENSOR_I2C_DAT_LENGTH/%d/g' \"%s\"", SENSOR_I2C_DAT_LENGTH,
	                dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);
#endif
#ifdef SENSOR_PWDN_PIN
	slen = snprintf(cmd_buffer, CMD_BUF_LEN, "sed -i 's/SENSOR_PWDN_PIN/%d/g' \"%s\"", SENSOR_PWDN_PIN, dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);
#endif
#ifdef SENSOR_RSTB_PIN
	slen = snprintf(cmd_buffer, CMD_BUF_LEN, "sed -i 's/SENSOR_RSTB_PIN/%d/g' \"%s\"", SENSOR_RSTB_PIN, dst_fname);
	CHECK_CMD_LEN();
	system(cmd_buffer);
#endif

	return 0;

misc_error:
	close(fd_src);
src_error:
	close(fd_dst);
dst_error:
	return -1;
}
