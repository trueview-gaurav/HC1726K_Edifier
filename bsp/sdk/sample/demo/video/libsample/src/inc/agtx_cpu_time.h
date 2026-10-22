#ifndef __CPU_TIME__
#define __CPU_TIME__

#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

#define CPU_TIME_FILE "/sys/devices/system/augentix-core/cpu_time"
#define MAX_CHAR_SIZE 5

static inline uint32_t get_cpu_time(void)
{
	int fd;
	char str[MAX_CHAR_SIZE];

	fd = open(CPU_TIME_FILE, O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "Open %s fail!\n", CPU_TIME_FILE);
		return 0;
	}

	if (read(fd, &str, MAX_CHAR_SIZE) == 0) {
		fprintf(stderr, "Read %s fail!\n", CPU_TIME_FILE);
		close(fd);
		return 0;
	}

	close(fd);

	return strtoul(str, NULL, 10);
}

#endif
