#include "secure_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

bool isFileReadable(const char *k_filename)
{
	FILE *fh;
	struct stat sb;
	memset(&sb, 0x00, sizeof(sb));

	fh = fopen(k_filename, "r");
	if (!fh) {
		perror("fopen failed");
		goto fail;
	}

	if (fstat(fileno(fh), &sb) == -1) {
		perror("fstat failed");
		goto fail;
	}

	/* check whether it is a regular file or a symbolic link, rather than a device file descriptor */
	if (!S_ISREG(sb.st_mode) && !S_ISLNK(sb.st_mode)) {
		perror("Not a regular file or symbolic link");
		goto fail;
	}

	fclose(fh);

	return true;

fail:
	if (fh) {
		fclose(fh);
	}

	return false;
}
