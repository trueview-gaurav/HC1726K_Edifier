#include "audio_dumper.h"

#include <sys/stat.h>
#include <sys/vfs.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>

#include "utlist.h"

#ifdef AUDIO_RECORD_ENABLE
#include <alsa/asoundlib.h>
#include <alsa/hwdep.h>
#include <alsa/error.h>
#include <pcm_interfaces.h>

#define __DEBUG__ 1

#if (__DEBUG__)
#define DEBUG(fmt, args...) printf("[DEBUG] " fmt, ##args)
#else
#define DEBUG(fmt, args...)
#endif

#define DESCRIPTOR_MAX 32

static char *const DEV_PATH = "/dev/";

typedef struct file_item {
	char *path;
	uint32_t mbytes;
	struct file_item *next;
} FileItem;

typedef struct audio_dumper {
	BitStreamSubscriber base_part;
	char previous_output_path[PATH_MAX];
	char dumping_file_path[PATH_MAX];
	const char output_path[PATH_MAX];
	char descriptor[DESCRIPTOR_MAX];
	FILE *fp;
	/* max_frame_count=0 means infinity */
	uint32_t max_frame_count;
	uint32_t dumped_frame_count;
	bool dumped_to_black_hole;
	bool repeat;
	/* repeat mode only */
	FileItem *dumped_files;
	int32_t reserved_mbytes; /* negative means percentage */
	int32_t recycle_mbytes; /* negative means percentage */
	int max_dumped_files; /* add to new contructor*/
	/*recent file number in some LL*/
} AudioDumper;

static int dumpFrameToFile(const void *frame, uint32_t data_len, FILE *dest)
{
	if (!fwrite(frame, 2 /*s16le*/, data_len, dest)) {
		perror("fwrite FAILED");
		return errno;
	}
	return 0;
}

static bool detectAvailableSpace(const char *path, uint64_t *available, uint64_t *total)
{
	struct statfs fs_info;
	if (statfs(path, &fs_info)) {
		perror("statfs");
		return false;
	} else {
		if (available) {
			*available = fs_info.f_bavail * fs_info.f_bsize;
		}
		if (total) {
			*total = fs_info.f_blocks * fs_info.f_bsize;
		}
		return true;
	}
}

static bool AUDIODUMPER_interpretLevels(AudioDumper *dumper, uint32_t *reserved_mbytes, uint32_t *recycle_mbytes,
                                        uint32_t *available_mbytes, uint32_t *total_mbytes)
{
	uint64_t available, total;
	if (detectAvailableSpace(dumper->dumping_file_path, &available, &total)) {
		available >>= 20; /* to MBytes */
		total >>= 20; /* to MBytes */
		if (available_mbytes) {
			*available_mbytes = available;
		}
		if (total_mbytes) {
			*total_mbytes = total;
		}
		if (dumper->reserved_mbytes > 0) {
			*reserved_mbytes = dumper->reserved_mbytes;
		} else {
			*reserved_mbytes = total * -dumper->reserved_mbytes / 100;
		}

		if (dumper->recycle_mbytes > 0) {
			*recycle_mbytes = dumper->recycle_mbytes;
		} else {
			*recycle_mbytes = total * -dumper->recycle_mbytes / 100;
		}

		return true;
	}

	return false;
}

static void AUDIODUMPER_purgeDumpedItems(AudioDumper *dumper, uint32_t mbytes)
{
	FileItem *item = NULL;
	FileItem *tmp = NULL;
	uint32_t purged_mbytes = 0;
	LL_FOREACH_SAFE(dumper->dumped_files, item, tmp)
	{
		if (remove(item->path)) {
			perror("remove");
			switch (errno) {
			case EACCES:
			case ELOOP:
			case ENAMETOOLONG:
			case ENOENT:
				/* assume we are NOT capable to remove this file */
				LL_DELETE(dumper->dumped_files, item);
				free(item->path);
				free(item);
				break;
			}
		} else {
			purged_mbytes += item->mbytes;
			LL_DELETE(dumper->dumped_files, item);
			free(item->path);
			free(item);
		}

		if (purged_mbytes >= mbytes) {
			break;
		}
	}
	DEBUG("%s: %u MBytes files have purged.\n", dumper->descriptor, purged_mbytes);
}

static int renameFile(const char *old_path, const char *new_path)
{
	if (rename(old_path, new_path) == 0) {
		printf("Renamed: %s → %s\n", old_path, new_path);
		return 0;
	} else {
		perror("rename failed");
		return -1;
	}
}

static int replaceAudioFilenameBodyWithTimestamp(const char *input_path, uint64_t timestamp, char *output_path,
                                                 size_t max_len)
{
	const char *last_slash = strrchr(input_path, '/');
	const char *audio_ext = strstr(input_path, ".audio.");
	if (!audio_ext)
		return -1;

	/** Extract directory path (including trailing slash if present) */
	size_t dir_len = last_slash ? (size_t)(last_slash - input_path + 1) : 0;

	/** Compose new filename with .pcm.<serial> extension */
	int written = snprintf(output_path, max_len, "%.*s%llu.pcm.%s", (int)dir_len, input_path,
	                       (unsigned long long)timestamp, audio_ext + strlen(".audio."));

	return (written < 0 || (size_t)written >= max_len) ? -1 : 0;
}

static void appendSerialNumberToPath(char *path, int serial, size_t max_len)
{
	size_t len = strlen(path);
	size_t remaining = max_len - len;

	if (remaining > 0) {
		size_t written = snprintf(path + len, remaining, ".%d", serial);
		if (written >= remaining) {
			// Truncated
			fprintf(stderr, "Path buffer not large enough to append serial number.\n");
		}
	}
}

static void normalizeRootfsPath(char *path)
{
	const char *prefix = "/root/";
	size_t prefix_len = strlen(prefix);

	if (strncmp(path, prefix, prefix_len) == 0) {
		/** Ensure the path after "/root/" starts with "tmp/" */
		if (strncmp(path + prefix_len, "tmp/", 4) == 0) {
			/** Shift "/tmp/..." to start from index 1 */
			memmove(path + 1, path + prefix_len, strlen(path + prefix_len) + 1);
			path[0] = '/'; /** Manually add leading '/' at index 0 */
		}
	}
}

static bool AUDIODUMPER_prepareNextFile(AudioDumper *dumper)
{
	time_t t;
	struct tm *tm;
	t = time(NULL);
	tm = localtime(&t);
	bool append_serial_to_path;

	if (!tm) {
		perror("localtime");
		/* we CANNOT construct next output path from current timestamp */
		append_serial_to_path = true;
		strncpy(dumper->previous_output_path, dumper->output_path, sizeof(dumper->previous_output_path));
		fprintf(stderr, "%s: CANNOT get localtime.\n", dumper->descriptor);
	} else {
		/* try to construct next output path from current timestamp */
		char next_path[sizeof(dumper->dumping_file_path)];
		size_t s = strftime(next_path, sizeof(next_path), dumper->output_path, tm);
		if (!s) {
			append_serial_to_path = true;
			strncpy(dumper->previous_output_path, dumper->output_path,
			        sizeof(dumper->previous_output_path));
			printf("%s: dumping file path is exceed buffer size(%d)!\n", dumper->descriptor,
			       sizeof(next_path));
		} else if (strcmp(next_path, dumper->previous_output_path) != 0) {
			/* OK, output path is alternating */
			strncpy(dumper->previous_output_path, next_path, sizeof(dumper->previous_output_path));
			strncpy(dumper->dumping_file_path, next_path, sizeof(dumper->dumping_file_path));
			append_serial_to_path = false;
		} else {
			append_serial_to_path = true;
		}
	}

	if (append_serial_to_path) {
		snprintf(dumper->dumping_file_path, sizeof(dumper->dumping_file_path), "%s.%ld",
		         dumper->previous_output_path, t);
	}

	if (dumper->max_dumped_files) {
		int dumped_files_count = 0;
		FileItem *item;
		LL_COUNT(dumper->dumped_files, item, dumped_files_count);
		appendSerialNumberToPath(dumper->dumping_file_path, dumped_files_count,
		                         sizeof(dumper->dumping_file_path));
	}

	while (1) { /** wait for sd card mounting */
		if (((access("/dev/mmcblk0p1", F_OK) != 0) || (access("/dev/mmcblk0", F_OK) != 0)) &&
		    strstr(dumper->dumping_file_path, "/mnt/sdcard") != NULL) {
			usleep(10000);
			continue;
		}

		dumper->fp = fopen(dumper->dumping_file_path, "wb");
		if (dumper->fp == NULL && strstr(dumper->dumping_file_path, "/mnt/sdcard") != NULL) {
			continue;
		}

		if (dumper->fp == NULL && strstr(dumper->dumping_file_path, "/root/tmp") != NULL) {
			normalizeRootfsPath(dumper->dumping_file_path);
			continue;
		}

		break;
	}

	printf("%s: opening file %s ...\n", dumper->descriptor, dumper->dumping_file_path);

	return dumper->fp != NULL;
}

static uint32_t AUDIODUMPER_closeDumpingFile(AudioDumper *dumper, uint64_t timestamp)
{
	if (dumper->fp != NULL) {
		fclose(dumper->fp);
		char rename_dumping_file_path[PATH_MAX] = { 0 };

		if (strstr(dumper->dumping_file_path, "/root/tmp") != NULL) {
			normalizeRootfsPath(dumper->dumping_file_path);
		}
		replaceAudioFilenameBodyWithTimestamp(dumper->dumping_file_path, timestamp, rename_dumping_file_path,
		                                      sizeof(rename_dumping_file_path));

		renameFile(dumper->dumping_file_path, rename_dumping_file_path);
		snprintf(dumper->dumping_file_path, sizeof(dumper->dumping_file_path), "%s", rename_dumping_file_path);
		dumper->fp = NULL;
		g_audio_dumper_should_flush = false;
	}

	struct stat file_stat;
	if (stat(dumper->dumping_file_path, &file_stat)) {
		perror("stat");
		fprintf(stderr, "failed to stat %s\n", dumper->dumping_file_path);
		return 0;
	} else {
		uint32_t mbytes = file_stat.st_size >> 20;
		printf("%s: %u MBytes have dumped to %s.\n", dumper->descriptor, mbytes, dumper->dumping_file_path);
		return mbytes;
	}
}

static bool AUDIODUMPER_deliveryWillStart(void *context)
{
	AudioDumper *dumper = context;

	if (AUDIODUMPER_prepareNextFile(dumper)) {
		if (dumper->repeat) {
			uint32_t reserved_mbytes, recycle_mbytes, total_mbytes;
			if (AUDIODUMPER_interpretLevels(dumper, &reserved_mbytes, &recycle_mbytes, NULL,
			                                &total_mbytes)) {
				if (dumper->reserved_mbytes > 0) {
					printf("%s: reservation level: %u MBytes.\n", dumper->descriptor,
					       reserved_mbytes);
				} else if (dumper->reserved_mbytes < 0) {
					printf("%s: reservation level(%d%%): %u/%u MBytes.\n", dumper->descriptor,
					       -dumper->reserved_mbytes, reserved_mbytes, total_mbytes);
				}

				if (dumper->recycle_mbytes > 0) {
					printf("%s: recycle policy: %u MBytes.\n", dumper->descriptor, recycle_mbytes);
				} else if (dumper->recycle_mbytes < 0) {
					printf("%s: recycle policy(%d%%): %u/%u MBytes.\n", dumper->descriptor,
					       -dumper->recycle_mbytes, recycle_mbytes, total_mbytes);
				}
			}
		}

		dumper->dumped_frame_count = 0;
		return false;
	}

	/* If the dumping file is NOT ready, we cancel the subscription */
	return true;
}

static bool AUDIODUMPER_receiveFrame(void *context, const void *frame_data, uint32_t data_len, uint64_t timestamp)
{
	AudioDumper *dumper = context;
	if (dumper->fp == NULL) {
		return true;
	}

	if (data_len <= 0) { /** skip one time*/
		return false;
	}

	if (dumper->max_frame_count == 0 || dumper->repeat ||
	    dumper->dumped_frame_count < dumper->max_frame_count /*max frame in single file*/) {
		int error = dumpFrameToFile(frame_data, data_len, dumper->fp);
		if (error) {
			fprintf(stderr, "%s: dump frame to file %s FAILED (err: %d).\n", dumper->descriptor,
			        dumper->dumping_file_path, error);
			fclose(dumper->fp);
			dumper->fp = NULL;
			return true;
		}
		++dumper->dumped_frame_count; /*recent frames number in single file*/
		if (dumper->dumped_frame_count % 8 == 0) {
			char limit[11];
			if (dumper->max_frame_count) {
				snprintf(limit, sizeof(limit), "%u", dumper->max_frame_count);
			} else {
				snprintf(limit, sizeof(limit), "---");
			}
			printf("%s: %u frames are saved!\n", dumper->descriptor, dumper->dumped_frame_count);
		}

		if (g_audio_dumper_should_flush) {
			uint32_t dumped_mbytes = AUDIODUMPER_closeDumpingFile(dumper, timestamp);
			FileItem *new_item = malloc(sizeof(FileItem));
			size_t path_len = strlen(dumper->dumping_file_path) + 1;
			new_item->path = malloc(path_len);
			strncpy(new_item->path, dumper->dumping_file_path, path_len);
			new_item->mbytes = dumped_mbytes;
			LL_APPEND(dumper->dumped_files, new_item);

			/* try to purge some dumped files if storage running low */
			if (dumper->reserved_mbytes && dumper->recycle_mbytes) {
				uint32_t reserved_mbytes;
				uint32_t recycle_mbytes;
				uint32_t available;
				if (AUDIODUMPER_interpretLevels(dumper, &reserved_mbytes, &recycle_mbytes, &available,
				                                NULL)) {
					DEBUG("%s: storage available: %u MBytes.\n", dumper->descriptor, available);
					if (available < reserved_mbytes) {
						AUDIODUMPER_purgeDumpedItems(dumper, recycle_mbytes);
					}
				}
			}

			/*now add a new file, add max file number check here, if max return true(true means unsuscribe)*/
			int dumped_files_count = 0;
			FileItem *item;
			LL_COUNT(dumper->dumped_files, item, dumped_files_count);
			if (dumped_files_count >= dumper->max_dumped_files && dumper->max_dumped_files > 0) {
				printf("%s: get max %d dumped files\n", dumper->descriptor, dumped_files_count);
				return true;
			}

			if (AUDIODUMPER_prepareNextFile(dumper)) {
				dumper->dumped_frame_count = 0;
			} else {
				/* unable to prepare next file, we signal publisher to stop delivery */
				return true;
			}
		}
	}

	return dumper->max_frame_count ? dumper->max_frame_count <= dumper->dumped_frame_count : false;
}

static void AUDIODUMPER_deliveryDidEnd(void *context, uint64_t timestamp)
{
	AUDIODUMPER_closeDumpingFile(context, timestamp);

	/** list all dumping files */
	AudioDumper *dumper = context;
	printf("%s: dumped file list -----\n", dumper->descriptor);
	int i = 0;
	FileItem *item = NULL;
	FileItem *tmp = NULL;
	LL_FOREACH_SAFE(dumper->dumped_files, item, tmp)
	{
		++i;
		printf("%d: %s, %u MBytes.\n", i, item->path, item->mbytes);
		LL_DELETE(dumper->dumped_files, item);
		free(item);
	}
}

BitStreamSubscriber *newAudioDumper(const char *output_path, uint32_t frame_count, bool repeat,
                                    int32_t reservation_level, int32_t recycle_level, int max_dumped_files)

{
	AudioDumper *dumper = malloc(sizeof(*dumper));
	snprintf((char *)dumper->output_path, sizeof(dumper->output_path), "%s", output_path);
	dumper->fp = NULL;
	dumper->repeat = repeat;
	dumper->dumped_files = NULL;
	dumper->reserved_mbytes = reservation_level;
	dumper->recycle_mbytes = recycle_level;
	dumper->max_dumped_files = max_dumped_files;
	dumper->max_frame_count = frame_count; // limit max frame cnt, else 0 = ulimited length

	if (dumper->recycle_mbytes == 0) {
		dumper->recycle_mbytes = 1;
	}

	memset(dumper->previous_output_path, 0, sizeof(dumper->previous_output_path));
	snprintf(dumper->descriptor, sizeof(dumper->descriptor), "AudioDumper");

	if (!dumper->repeat || strncmp(dumper->output_path, DEV_PATH, strlen(DEV_PATH)) == 0) {
		dumper->dumped_to_black_hole = true;
		printf("%s: assume dumping frames to unlimited sink.\n", dumper->descriptor);
	} else {
		dumper->dumped_to_black_hole = false;
	}

	BitStreamSubscriber *base = &dumper->base_part;
	base->context = dumper;
	base->deliveryWillStart = AUDIODUMPER_deliveryWillStart;
	base->receiveFrame = AUDIODUMPER_receiveFrame;
	base->deliveryDidEnd = AUDIODUMPER_deliveryDidEnd;
	return base;
}

#endif