#include <stddef.h>
#include <sys/statvfs.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <linux/limits.h>

#include "dumper_utils.h"

/* Tag used in all log lines from this module */
#define DUMPER_UTILS_TAG "[dumper_utils]"

bool DUMPERUTILS_is_mount_ready(const char *dir, char *resolved_dir)
{
	if (!dir || dir[0] == '\0') {
		fprintf(stderr, "%s mount_ready(%s): WARN — null or empty path\n",
		        DUMPER_UTILS_TAG, dir ? dir : "(null)");
		return false;
	}

	/*
	* Use output_file directly.
	* No path remap (/proc/mounts or /root ↔ /mnt). Just verify target dir.
	*/
	const char *check = dir;

	/* Layer 1: configured directory must be accessible */
	if (access(check, F_OK) != 0) {
		fprintf(stderr, "%s mount_ready(%s): WARN — dir does not exist (errno=%d: %s)\n",
		        DUMPER_UTILS_TAG, check, errno, strerror(errno));
		return false;
	}

	/* Layer 2: configured directory must be writable */
	if (access(check, W_OK) != 0) {
		fprintf(stderr, "%s mount_ready(%s): WARN — dir not writable (errno=%d: %s)\n",
		        DUMPER_UTILS_TAG, check, errno, strerror(errno));
		return false;
	}

	/* Layer 3: filesystem must have real blocks */
	struct statvfs vfs;
	if (statvfs(check, &vfs) != 0) {
		fprintf(stderr, "%s mount_ready(%s): WARN — statvfs failed (errno=%d: %s)\n",
		        DUMPER_UTILS_TAG, check, errno, strerror(errno));
		return false;
	}

	if (vfs.f_blocks == 0) {
		fprintf(stderr, "%s mount_ready(%s): WARN — f_blocks=0, not a real mount\n",
		        DUMPER_UTILS_TAG, check);
		return false;
	}

	printf("%s mount_ready(%s): OK — f_blocks=%lu, f_bavail=%lu, bsize=%lu\n",
	       DUMPER_UTILS_TAG, check,
	       (unsigned long)vfs.f_blocks,
	       (unsigned long)vfs.f_bavail,
	       (unsigned long)vfs.f_bsize);

	if (resolved_dir) {
		snprintf(resolved_dir, PATH_MAX, "%s", check);
	}
	return true;
}

/**
 * @brief Extract the directory portion of a file path.
 */
void DUMPERUTILS_extract_dir(const char *path, char *dir_out, size_t size)
{
	if (!path || !dir_out || size == 0) {
		return;
	}

	const char *last_slash = strrchr(path, '/');
	if (!last_slash) {
		/* No slash — current directory */
		snprintf(dir_out, size, ".");
		return;
	}

	size_t dir_len = (size_t)(last_slash - path);
	if (dir_len == 0) {
		/* Path like "/foo.raw" — directory is root "/" */
		snprintf(dir_out, size, "/");
		return;
	}

	size_t copy_len = (dir_len < size - 1) ? dir_len : size - 1;
	memcpy(dir_out, path, copy_len);
	dir_out[copy_len] = '\0';
}


/**
 * Build fallback path by replacing DUMPER_SDCARD_PREFIX with DUMPER_FALLBACK_DIR.
 * Only the prefix is replaced; basename is preserved.
 * If prefix doesn’t match, keep path unchanged.
 */
void DUMPERUTILS_build_fallback_path(const char *original_path, char *fallback_out, size_t size)
{
	if (!original_path || !fallback_out || size == 0) {
		return;
	}

	size_t prefix_len = strlen(DUMPER_SDCARD_PREFIX);

	if (strncmp(original_path, DUMPER_SDCARD_PREFIX, prefix_len) != 0) {
		/* Not a /mnt/ path — keep as-is */
		snprintf(fallback_out, size, "%s", original_path);
		return;
	}

	/* Find the basename (last component after the last '/') */
	const char *last_slash = strrchr(original_path, '/');
	const char *basename = last_slash ? last_slash + 1 : original_path;

	snprintf(fallback_out, size, "%s/%s", DUMPER_FALLBACK_DIR, basename);
}


