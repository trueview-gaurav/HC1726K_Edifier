#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <linux/stat.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <limits.h>
#include <getopt.h>
#include <dirent.h>
#include <signal.h>

#include "mp4_muxer.h"

#include <alsa/asoundlib.h>

static volatile sig_atomic_t g_stop = 0;

void sigintHandler(int signo)
{
	if (signo == SIGINT) {
		printf("[mp4_muxer] Caught SIGINT!\n");
	} else if (signo == SIGTERM) {
		printf("[mp4_muxer] Caught SIGTERM!\n");
	} else {
		perror("[mp4_muxer] Unexpected signal!\n");
		exit(1);
	}

	g_stop = 1;
}

void freePCMBuffer(void *buffer)
{
	if (buffer) {
		free(buffer);
	}
}

int extractSpsPpsFromH264(const char *filename, uint8_t **sps, size_t *sps_len, uint8_t **pps, size_t *pps_len)
{
	FILE *fp = fopen(filename, "rb");
	if (!fp)
		return -errno;

	uint8_t buf[1024 * 1024];
	size_t read_size = fread(buf, 1, sizeof(buf), fp);
	fclose(fp);

	if (read_size <= 0)
		return -EIO;

	for (size_t i = 0; i + 4 < read_size;) {
		if (buf[i] == 0x00 && buf[i + 1] == 0x00 && buf[i + 2] == 0x00 && buf[i + 3] == 0x01) {
			size_t start = i + 4;
			size_t end = start;
			i = start;
			while (i + 4 < read_size &&
			       !(buf[i] == 0x00 && buf[i + 1] == 0x00 && buf[i + 2] == 0x00 && buf[i + 3] == 0x01)) {
				i++;
			}
			end = i;
			if (start < end) {
				uint8_t nal_type = buf[start] & 0x1F;
				if (nal_type == 7 && *sps == NULL) { // SPS
					*sps_len = end - start;
					*sps = malloc(*sps_len);
					if (!*sps)
						return -ENOMEM;
					memcpy(*sps, buf + start, *sps_len);
				} else if (nal_type == 8 && *pps == NULL) { // PPS
					*pps_len = end - start;
					*pps = malloc(*pps_len);
					if (!*pps)
						return -ENOMEM;
					memcpy(*pps, buf + start, *pps_len);
				}
			}
			if (*sps && *pps)
				break;
		} else {
			i++;
		}
	}

	return (*sps && *pps) ? 0 : -ENODATA;
}

static int getPCMTotalSamples(const char *filepath, int channels, int bits_per_sample, int *total_samples,
                              void **buffer)
{
	if (!filepath || channels <= 0 || bits_per_sample <= 0 || !total_samples || !buffer)
		return -EINVAL;

	FILE *fp = fopen(filepath, "rb");
	if (!fp)
		return -errno;

	if (fseek(fp, 0, SEEK_END) != 0) {
		fclose(fp);
		return -errno;
	}

	long filesize = ftell(fp);
	if (filesize < 0) {
		fclose(fp);
		return -errno;
	}
	rewind(fp);

	int bytes_per_sample = bits_per_sample / 8;
	long frame_size = channels * bytes_per_sample;

	if (frame_size == 0) {
		fclose(fp);
		return -EINVAL;
	}

	long total = filesize / frame_size;
	if (total > INT_MAX) {
		fclose(fp);
		return -EOVERFLOW;
	}

	*total_samples = (int)total;

	if (*total_samples == 0) {
		fclose(fp);
		*buffer = NULL;
		return 0; // No samples, no need to read
	}

	printf("pcm total samples: %d\n", *total_samples);

	/** Allocate buffer and read entire PCM file. */
	void *data = malloc(filesize);
	if (!data) {
		fclose(fp);
		return -ENOMEM;
	}

	if (fread(data, 1, filesize, fp) != (unsigned int)filesize) {
		free(data);
		fclose(fp);
		return -EIO;
	}

	fclose(fp);
	*buffer = data;
	return 0;
}

#ifdef DEBUG
static int getMemAvailableKb(long *mem_kb)
{
	if (!mem_kb)
		return -EINVAL;

	FILE *fp = fopen("/proc/meminfo", "r");
	if (!fp)
		return -errno;

	char line[256];
	while (fgets(line, sizeof(line), fp)) {
		if (strncmp(line, "MemAvailable:", 13) == 0) {
			/** Failed to find 'MemAvailable' field in /proc/meminfo. */
			long value;
			if (sscanf(line + 13, "%ld", &value) == 1) {
				*mem_kb = value;
				fclose(fp);
				return 0;
			} else {
				fclose(fp);
				return -EIO;
			}
		}
	}

	fclose(fp);
	return -ENOENT;
}
#endif

static bool pathExists(const char *path, bool must_be_dir)
{
	struct stat st;
	if (stat(path, &st) != 0) {
		fprintf(stderr, "[ERROR] Path does not exist: %s\n", path);
		return false;
	}
	if (must_be_dir && !S_ISDIR(st.st_mode)) {
		fprintf(stderr, "[ERROR] Path is not a directory: %s\n", path);
		return false;
	}
	if (!must_be_dir && !S_ISREG(st.st_mode)) {
		fprintf(stderr, "[ERROR] Path is not a regular file: %s\n", path);
		return false;
	}
	return true;
}

static bool validateMuxInputs(const char *pcm_path, const char *h264_path, const char *watch_dir,
                              const char *output_path, bool single_mode, bool dir_mode)
{
	if (single_mode) {
		if (!pcm_path || !h264_path) {
			fprintf(stderr, "[ERROR] Missing PCM or H264 path in single file mode.\n");
			return false;
		}
		if (!pathExists(pcm_path, false))
			return false;
		if (!pathExists(h264_path, false))
			return false;
	}

	if (dir_mode) {
		if (!watch_dir || !output_path) {
			fprintf(stderr, "[ERROR] Missing watch or output directory in directory mode.\n");
			return false;
		}

		if (!pathExists(watch_dir, true))
			return false;
		if (!pathExists(output_path, true))
			return false;
	}

	printf("%d %d %s %s\n", single_mode, dir_mode, watch_dir, output_path);

	return true;
}

static int runSingleMuxer(const char *pcm_file, const char *h264_file, const char *output_file, int sample_rate,
                          int fps)
{
	int ret = 0;
	int total_samples = 0;
	void *sample_buffer = NULL;
	uint8_t *sps = NULL, *pps = NULL;
	size_t sps_len = 0, pps_len = 0;

	printf("%s mux %s %s\n", __func__, h264_file, pcm_file);

	/** Step 1: read PCM */
	ret = getPCMTotalSamples(pcm_file, 1, snd_pcm_format_width(SND_PCM_FORMAT_S16_LE), &total_samples,
	                         &sample_buffer);
	if (ret != 0) {
		fprintf(stderr, "[ERROR] getPCMTotalSamples: %s\n", strerror(-ret));
		ret = 1;
		goto cleanup;
	}

	/** Step 2: get SPS/PPS */
	ret = extractSpsPpsFromH264(h264_file, &sps, &sps_len, &pps, &pps_len);
	if (ret != 0) {
		fprintf(stderr, "[ERROR] extractSpsPpsFromH264: %s\n", strerror(-ret));
		ret = 2;
		goto cleanup;
	}

	/** Step 3: mux MP4 (encode MP3 inside) */
	ret = muxAudioVideoToMp4(h264_file, fps, sample_buffer, total_samples, sample_rate, sps, sps_len, pps, pps_len,
	                         output_file);
	if (ret != 0) {
		fprintf(stderr, "[ERROR] muxAudioVideoToMp4 failed\n");
		ret = 4;
		goto cleanup;
	}

	ret = 0; // success

cleanup:
	if (sample_buffer)
		freePCMBuffer(sample_buffer);
	if (sps)
		free(sps);
	if (pps)
		free(pps);

	return ret;
}

#define MAX_SERIAL 1000
static int runDirectoryMuxer(const char *watch_dir, const char *output_dir, int sample_rate, int fps)
{
	/** Track processed serials */
	bool processed[MAX_SERIAL] = { false };

	while (!g_stop) {
		DIR *dir = opendir(watch_dir);
		if (!dir) {
			fprintf(stderr, "Failed to open dir: %s\n", strerror(errno));
			return 1;
		}

		/** Temporary tables to store matching pcm/raw paths by serial */
		char *pcm_path_table[MAX_SERIAL] = { 0 };
		char *raw_path_table[MAX_SERIAL] = { 0 };

		struct dirent *entry;

		/** Scan and build .pcm.<N> and .264.<N> tables */
		while ((entry = readdir(dir)) != NULL) {
			int serial = -1;

			/** Match .pcm.<serial> */
			if (strstr(entry->d_name, ".pcm.")) {
				if (sscanf(entry->d_name, "%*[^.].pcm.%d", &serial) == 1 && serial >= 0 &&
				    serial < MAX_SERIAL) {
					if (!pcm_path_table[serial]) {
						pcm_path_table[serial] = strdup(entry->d_name);
					}
				}
			}

			/** Match .264.<serial> */
			if (strstr(entry->d_name, ".264.")) {
				if (sscanf(entry->d_name, "%*[^.].264.%d", &serial) == 1 && serial >= 0 &&
				    serial < MAX_SERIAL) {
					if (!raw_path_table[serial]) {
						raw_path_table[serial] = strdup(entry->d_name);
					}
				}
			}
		}

		closedir(dir);

		/** Process first unprocessed pair found */
		for (int serial = 0; serial < MAX_SERIAL; serial++) {
			if (processed[serial])
				continue;
			if (!pcm_path_table[serial] || !raw_path_table[serial])
				continue;

			char pcm_full[PATH_MAX];
			char raw_full[PATH_MAX];
			char out_full[PATH_MAX];

			snprintf(pcm_full, sizeof(pcm_full), "%s/%s", watch_dir, pcm_path_table[serial]);
			snprintf(raw_full, sizeof(raw_full), "%s/%s", watch_dir, raw_path_table[serial]);
			snprintf(out_full, sizeof(out_full), "%s/%d.mp4", output_dir, serial);

			/** Skip if output already exists */
			if (access(out_full, F_OK) == 0) {
				processed[serial] = true;
				continue;
			}

			printf("[INFO] Muxing serial %d:\n", serial);
			printf("       PCM: %s\n", pcm_full);
			printf("       RAW: %s\n", raw_full);
			printf("       OUT: %s\n", out_full);

			int ret = runSingleMuxer(pcm_full, raw_full, out_full, sample_rate, fps);
			if (ret == 0) {
				printf("[✓] Muxed serial %d successfully\n", serial);
				processed[serial] = true;
			} else {
				fprintf(stderr, "[X] Failed to mux serial %d\n", serial);
			}

			break; // Only one per loop
		}

		/** Clean up malloced strdup */
		for (int i = 0; i < MAX_SERIAL; i++) {
			if (pcm_path_table[i])
				free(pcm_path_table[i]);
			if (raw_path_table[i])
				free(raw_path_table[i]);
		}

		sleep(1);
	}

	printf("Directory muxer stopped by user.\n");
	return 0;
}

static void printArguments(bool single_mode, bool dir_mode, const char *pcm_file, const char *h264_file,
                           const char *watch_dir, const char *output_file, int sample_rate, int fps)
{
	printf("=====================================\n");
	printf("        Parsed Command Arguments     \n");
	printf("=====================================\n");

	if (single_mode) {
		printf("Mode           : Single File Mode\n");
		printf("Audio PCM File : %s\n", pcm_file ? pcm_file : "(null)");
		printf("H264 File      : %s\n", h264_file ? h264_file : "(null)");
		printf("Output File    : %s\n", output_file ? output_file : "(null)");
	} else if (dir_mode) {
		printf("Mode           : Directory Watch Mode\n");
		printf("Watch Dir      : %s\n", watch_dir ? watch_dir : "(null)");
		printf("Output Dir     : %s\n", output_file ? output_file : "(null)");
	} else {
		printf("Mode           : Unknown or Incomplete\n");
	}

	printf("Sample Rate    : %d\n", sample_rate);
	printf("FPS            : %d\n", fps);
	printf("=====================================\n");
}

static void printUsage(const char *prog_name)
{
	printf("Usage (single file mode):\n");
	printf("  %s -a <audio_pcm_file> -r <sample_rate> -v <h264_file> -f <fps> -o <output_file>\n", prog_name);

	printf("\nUsage (directory watch mode):\n");
	printf("  %s -d <watch_dir> -r <sample_rate> -f <fps> [-o <output_dir>]\n", prog_name);

	printf("\nOptions:\n");
	printf("  -a <audio_pcm_file>     Path to PCM audio file (S16LE only)\n");
	printf("  -v <h264_file>          Path to H.264 video file\n");
	printf("  -d <watch_dir>          Directory to watch for matching .pcm and .h264 files\n");
	printf("  -r <sample_rate>        PCM sample rate (e.g., 8000)\n");
	printf("  -f <fps>                H.264 frames per second (e.g., 30)\n");
	printf("  -o <output_file/dir>    In single file mode: output file path (must end with .mp4)\n");
	printf("                          In directory mode:  output directory (filenames auto-generated)\n");
	printf("  -h                      Show this help message\n");

	printf("\nNotes:\n");
	printf("  - Directory mode (-d) monitors the specified folder for matching <basename>.pcm.<serial num> and <basename>.264..<serial num> files.\n");
	printf("    When both exist, they will be muxed into <output_dir>/<sequence>.mp4 (e.g., 0.mp4, 1.mp4).\n");
}

int main(int argc, char *argv[])
{
	/** Set signal handler. */

	if (signal(SIGINT, sigintHandler) == SIG_ERR) {
		perror("Cannot handle SIGINT!\n");
		exit(1);
	}

	if (signal(SIGTERM, sigintHandler) == SIG_ERR) {
		perror("Cannot handle SIGTERM!\n");
		exit(1);
	}

	char *pcm_file = NULL;
	int sample_rate = 0;
	char *h264_file = NULL;
	int fps = 0;
	char *output_file = "./";
	const char *watch_dir = NULL;

	int opt;
	while ((opt = getopt(argc, argv, "a:v:r:f:o:d:h")) != -1) {
		switch (opt) {
		case 'a':
			pcm_file = optarg;
			break;
		case 'v':
			h264_file = optarg;
			break;
		case 'r':
			sample_rate = atoi(optarg);
			break;
		case 'f':
			fps = atoi(optarg);
			break;
		case 'o':
			output_file = optarg;
			break;
		case 'd':
			watch_dir = optarg;
			break;
		case 'h':
		default:
			printUsage(argv[0]);
			return EXIT_FAILURE;
		}
	}

	bool single_mode = (pcm_file && h264_file && sample_rate && fps && output_file);
	bool dir_mode = (watch_dir && output_file && sample_rate && fps);

	if (single_mode && dir_mode) {
		fprintf(stderr, "Error: Cannot use -a/-v and -d at the same time.\n");
		return EXIT_FAILURE;
	}

	if (!single_mode && !dir_mode) {
		fprintf(stderr, "Error: Missing required arguments.\n");
		printUsage(argv[0]);
		return EXIT_FAILURE;
	}

	printArguments(single_mode, dir_mode, pcm_file, h264_file, watch_dir, output_file, sample_rate, fps);

	if (!validateMuxInputs(pcm_file, h264_file, watch_dir, output_file, single_mode, dir_mode)) {
		return EXIT_FAILURE;
	}

	if (single_mode) {
		return runSingleMuxer(pcm_file, h264_file, output_file, sample_rate, fps);
	}

	if (dir_mode) {
		runDirectoryMuxer(watch_dir, output_file, sample_rate, fps);
	}
}
