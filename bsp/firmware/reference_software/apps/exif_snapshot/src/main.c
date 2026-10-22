/*
 * EXIF Snapshot - Trail Camera Reference Application
 *
 * This application demonstrates MJPEG snapshot capture with EXIF metadata
 * for trail camera applications using the Augentix MPI.
 */

/* Module header */
#include "exif_snapshot.h"

/* C standard library headers */
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* POSIX/System headers */
#include <getopt.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/* Module running state - use sig_atomic_t for signal safety */
static volatile sig_atomic_t g_running = 1;

/*==============================================================================
 * Forward declarations for static helper functions
 *============================================================================*/

/* Signal handling */
static void signalHandler(int sig);

/* CLI utilities */
static void printUsage(const char *prog);
static void printVersion(void);

/* Path validation and filesystem operations */
static bool isSafePath(const char *path);
static int createOutputDirectory(const char *path);

/* Timestamp and filename generation */
static void getCurrentDatetime(char *datetime, size_t len);
static void generateFilename(char *filename, size_t size, const char *output_dir);

/* System configuration */
static void setOOMScore(void);

/*==============================================================================
 * Public Function (main entry point)
 *============================================================================*/

/**
 * @brief Main entry point
 * @details
 * @param[in] argc Argument count
 * @param[in] argv Argument vector
 * @return Exit code (0 for success)
 */
int main(int argc, char *argv[])
{
	int ret = 0;
	int opt;
	char output_path[EXIF_MAX_PATH_LEN] = "/tmp/snapshots";
	double interval = 0.0;
	int count = 0;
	ExifMetadata metadata;

	static const struct option k_long_options[] = { { "output", required_argument, 0, 'o' },
		                                        { "interval", required_argument, 0, 'i' },
		                                        { "count", required_argument, 0, 'c' },
		                                        { "buffer-capacity", required_argument, 0, 'b' },
		                                        { "gps", required_argument, 0, 'g' },
		                                        { "altitude", required_argument, 0, 'a' },
		                                        { "model", required_argument, 0, 'm' },
		                                        { "make", required_argument, 0, 'k' },
		                                        { "description", required_argument, 0, 'd' },
		                                        { "version", no_argument, 0, 'v' },
		                                        { "help", no_argument, 0, 'h' },
		                                        { 0, 0, 0, 0 } };

	/* Set OOM killer protection early to reduce risk of being killed */
	setOOMScore();

	/* Initialise metadata with defaults */
	memset(&metadata, 0, sizeof(metadata));
	strncpy(metadata.make, "Augentix", sizeof(metadata.make) - 1);
	metadata.make[sizeof(metadata.make) - 1] = '\0';
	strncpy(metadata.model, "Trail Camera", sizeof(metadata.model) - 1);
	metadata.model[sizeof(metadata.model) - 1] = '\0';
	strncpy(metadata.software, "EXIF Snapshot v" EXIF_SNAPSHOT_VERSION, sizeof(metadata.software) - 1);
	metadata.software[sizeof(metadata.software) - 1] = '\0';
	strncpy(metadata.description, "Trail camera snapshot", sizeof(metadata.description) - 1);
	metadata.description[sizeof(metadata.description) - 1] = '\0';
	metadata.orientation = 1; /* Normal orientation */
	metadata.has_gps = false;

	/* Parse command line arguments */
	while ((opt = getopt_long(argc, argv, "o:i:c:b:g:a:m:k:d:vh", k_long_options, NULL)) != -1) {
		switch (opt) {
		case 'o':
			if (!isSafePath(optarg)) {
				fprintf(stderr, "Error: Invalid or unsafe output path: %s\n", optarg);
				return EXIT_FAILURE;
			}
			if (strlen(optarg) >= sizeof(output_path)) {
				fprintf(stderr, "Error: Output path too long (max %zu characters): %s\n",
				        sizeof(output_path) - 1, optarg);
				return EXIT_FAILURE;
			}
			strncpy(output_path, optarg, sizeof(output_path) - 1);
			output_path[sizeof(output_path) - 1] = '\0';
			break;
		case 'i':
			interval = atof(optarg);
			if (interval < 0.0) {
				fprintf(stderr, "Error: Invalid interval: %s (must be >= 0)\n", optarg);
				return EXIT_FAILURE;
			}
			/* Prevent race conditions: enforce minimum safe interval */
			if (interval < 0.01) {
				interval = 0.01;
			}
			break;
		case 'c':
			count = atoi(optarg);
			if (count < 0) {
				fprintf(stderr, "Error: Invalid count: %s\n", optarg);
				return EXIT_FAILURE;
			}
			break;
		case 'b': {
			size_t buffer_capacity;
			char *endptr;

			/* Parse buffer capacity using strtoul for proper error handling */
			errno = 0;
			buffer_capacity = strtoul(optarg, &endptr, 10);
			if (errno != 0 || *endptr != '\0') {
				fprintf(stderr, "Error: Invalid buffer capacity: %s\n", optarg);
				return EXIT_FAILURE;
			}

			/* Set buffer capacity (validation will be done in EXIF_snapshotSetBufferCapacity) */
			if (EXIF_snapshotSetBufferCapacity(buffer_capacity) != 0) {
				return EXIT_FAILURE;
			}
			break;
		}
		case 'g': {
			double lat, lon;
			char *endptr;
			char *comma;

			/* Find comma separator */
			comma = strchr(optarg, ',');
			if (!comma) {
				fprintf(stderr, "Error: Invalid GPS format: %s\n", optarg);
				fprintf(stderr, "Use format: latitude,longitude\n");
				return EXIT_FAILURE;
			}

			/* Parse latitude using strtod (safer than sscanf) */
			errno = 0;
			lat = strtod(optarg, &endptr);
			if (errno != 0 || endptr != comma) {
				fprintf(stderr, "Error: Invalid latitude value: %s\n", optarg);
				fprintf(stderr, "Use format: latitude,longitude\n");
				return EXIT_FAILURE;
			}

			/* Parse longitude using strtod */
			errno = 0;
			lon = strtod(comma + 1, &endptr);
			if (errno != 0 || (*endptr != '\0' && *endptr != ' ')) {
				fprintf(stderr, "Error: Invalid longitude value: %s\n", comma + 1);
				fprintf(stderr, "Use format: latitude,longitude\n");
				return EXIT_FAILURE;
			}

			/* Use the EXIF module's GPS validation function */
			int gps_ret = EXIF_snapshotSetGpsInfo(&metadata, lat, lon, metadata.altitude);
			if (gps_ret != 0) {
				/* Error message already printed by the function */
				return EXIT_FAILURE;
			}
			break;
		}
		case 'a':
			metadata.altitude = atof(optarg);
			break;
		case 'm':
			if (strlen(optarg) >= sizeof(metadata.model)) {
				fprintf(stderr, "Error: Model name too long (max %zu characters): %s\n",
				        sizeof(metadata.model) - 1, optarg);
				return EXIT_FAILURE;
			}
			strncpy(metadata.model, optarg, sizeof(metadata.model) - 1);
			metadata.model[sizeof(metadata.model) - 1] = '\0';
			break;
		case 'k':
			if (strlen(optarg) >= sizeof(metadata.make)) {
				fprintf(stderr, "Error: Make name too long (max %zu characters): %s\n",
				        sizeof(metadata.make) - 1, optarg);
				return EXIT_FAILURE;
			}
			strncpy(metadata.make, optarg, sizeof(metadata.make) - 1);
			metadata.make[sizeof(metadata.make) - 1] = '\0';
			break;
		case 'd':
			if (strlen(optarg) >= sizeof(metadata.description)) {
				fprintf(stderr, "Error: Description too long (max %zu characters): %s\n",
				        sizeof(metadata.description) - 1, optarg);
				return EXIT_FAILURE;
			}
			strncpy(metadata.description, optarg, sizeof(metadata.description) - 1);
			metadata.description[sizeof(metadata.description) - 1] = '\0';
			break;
		case 'v':
			printVersion();
			return EXIT_SUCCESS;
		case 'h':
			printUsage(argv[0]);
			return EXIT_SUCCESS;
		default:
			printUsage(argv[0]);
			return EXIT_FAILURE;
		}
	}

	/* Install signal handlers for graceful shutdown using sigaction for reliability */
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signalHandler;
	sa.sa_flags = SA_RESTART; /* Restart interrupted system calls */
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);

	/* Create output directory if needed */
	if (createOutputDirectory(output_path) != 0) {
		return EXIT_FAILURE;
	}

	/* Initialise the EXIF snapshot module */
	printf("Initialising EXIF snapshot module...\n");
	ret = EXIF_snapshotInit();
	if (ret != 0) {
		fprintf(stderr, "Error: Failed to initialise module (code: %d)\n", ret);
		return EXIT_FAILURE;
	}

	/* Display capture configuration */
	printf("\nSnapshot Capture Configuration:\n");
	printf("  Output directory: %s\n", output_path);
	printf("  Interval: %.2f seconds\n", interval);
	printf("  Count: %s\n", count == 0 ? "unlimited" : "limited");
	if (metadata.has_gps) {
		printf("  GPS: %.6f, %.6f (altitude: %.1f m)\n", metadata.latitude, metadata.longitude,
		       metadata.altitude);
	}
	printf("  Camera: %s %s\n", metadata.make, metadata.model);
	printf("\nStarting capture loop (press Ctrl+C to stop)...\n\n");

	/* Main capture loop */
	int captured = 0;
	while (g_running && (count == 0 || captured < count)) {
		char filename[EXIF_MAX_PATH_LEN];
		char datetime[EXIF_MAX_DATETIME_LEN];

		/* Update timestamp for current capture */
		getCurrentDatetime(datetime, sizeof(datetime));
		EXIF_snapshotSetDatetime(&metadata, datetime);

		/* Generate unique filename */
		generateFilename(filename, sizeof(filename), output_path);

		/* Capture snapshot with EXIF metadata */
		printf("[%d] Capturing: %s\n", captured + 1, filename);
		ret = EXIF_snapshotCapture(filename, &metadata);
		if (ret != 0) {
			fprintf(stderr, "Warning: Capture failed (code: %d)\n", ret);
			/* Continue trying */
		} else {
			captured++;
		}

		/* Wait for next capture interval if interval > 0 */
		if (g_running && (count == 0 || captured < count) && interval > 0.0) {
			usleep((useconds_t)(interval * 1000000));
		}
	}

	/* Cleanup */
	printf("\nShutting down...\n");
	EXIF_snapshotDeinit();
	printf("Total snapshots captured: %d\n", captured);

	return ret == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

/*==============================================================================
 * Static Helper Functions
 *============================================================================*/

/*------------------------------------------------------------------------------
 * Signal Handling
 *----------------------------------------------------------------------------*/

/**
 * @brief Signal handler for graceful shutdown
 * @details
 * Handles SIGINT and SIGTERM signals to enable graceful shutdown.
 * @param[in] sig Signal number received
 */
static void signalHandler(int sig)
{
	/* Only set flag - no I/O operations in signal handler for async-signal-safety */
	(void)sig; /* Avoid unused parameter warning */
	g_running = 0;
}

/*------------------------------------------------------------------------------
 * CLI Utilities
 *----------------------------------------------------------------------------*/

/**
 * @brief Print usage information
 * @details
 * @param[in] prog Program name from argv[0]
 */
static void printUsage(const char *prog)
{
	printf("Usage: %s [options]\n", prog);
	printf("\nOptions:\n");
	printf("  -o, --output PATH      Output directory for snapshots (default: /tmp/snapshots)\n");
	printf("  -i, --interval SEC     Interval between snapshots in seconds (minimum: 0.01, supports decimals)\n");
	printf("  -c, --count NUM        Number of snapshots to capture (0 = unlimited, default: 0)\n");
	printf("  -b, --buffer-capacity SIZE Frame buffer capacity in bytes (default: 6291456, minimum: 1048576)\n");
	printf("  -g, --gps LAT,LON      GPS coordinates (e.g., 37.7749,-122.4194)\n");
	printf("  -a, --altitude ALT     GPS altitude in metres\n");
	printf("  -m, --model NAME       Camera model name\n");
	printf("  -k, --make NAME        Camera manufacturer name\n");
	printf("  -d, --description      Image description\n");
	printf("  -v, --version          Show version information\n");
	printf("  -h, --help             Show this help message\n");
}

/**
 * @brief Print version information
 * @details
 */
static void printVersion(void)
{
	printf("EXIF Snapshot v%s\n", EXIF_SNAPSHOT_VERSION);
}

/*------------------------------------------------------------------------------
 * Path Validation and Filesystem Operations
 *----------------------------------------------------------------------------*/

/**
 * @brief Sanitize and validate path for security
 * @details
 * Prevents directory traversal attacks by checking for dangerous patterns.
 * Uses realpath to resolve the actual path and verify it's safe.
 * @param[in] path Path to validate
 * @return true if path is safe, false otherwise
 */
static bool isSafePath(const char *path)
{
	if (!path || !*path) {
		return false;
	}

	/* Check for directory traversal patterns */
	if (strstr(path, "..") != NULL || strstr(path, "//") != NULL) {
		return false;
	}

	/* Ensure path doesn't start with dangerous characters */
	if (path[0] == '~') {
		return false;
	}

	/* Check for reasonable path length */
	if (strlen(path) >= PATH_MAX) {
		return false;
	}

	/* Use realpath to resolve symbolic links and verify actual path */
	char resolved_path[PATH_MAX];
	if (realpath(path, resolved_path) != NULL) {
		/* Path exists - verify it's not trying to escape to system directories */
		if (strncmp(resolved_path, "/etc", 4) == 0 || strncmp(resolved_path, "/sys", 4) == 0 ||
		    strncmp(resolved_path, "/proc", 5) == 0 || strncmp(resolved_path, "/dev", 4) == 0) {
			return false;
		}
	} else if (errno != ENOENT) {
		/* If error is not "file doesn't exist", it's potentially dangerous */
		return false;
	}

	return true;
}

/**
 * @brief Create output directory if it doesn't exist
 * @details
 * @param[in] path Directory path to create
 * @return 0 on success, negative errno on failure
 */
static int createOutputDirectory(const char *path)
{
	struct stat st = { 0 };

	if (!isSafePath(path)) {
		fprintf(stderr, "Error: Invalid or unsafe path: %s\n", path);
		return -EINVAL; /* Invalid argument */
	}

	if (stat(path, &st) == -1) {
		if (mkdir(path, 0755) != 0) {
			int err = errno; /* Capture errno immediately */
			fprintf(stderr, "Failed to create output directory '%s': %s\n", path, strerror(err));
			return -err; /* Return negative errno */
		}
		printf("Created output directory: %s\n", path);
	}

	return 0;
}

/*------------------------------------------------------------------------------
 * Timestamp and Filename Generation
 *----------------------------------------------------------------------------*/

/**
 * @brief Get current datetime in EXIF format
 * @details
 * Formats current local time as YYYY:MM:DD HH:MM:SS for EXIF.
 * @param[out] datetime Buffer to store formatted datetime
 * @param[in] len Buffer length
 */
static void getCurrentDatetime(char *datetime, size_t len)
{
	time_t now;
	struct tm tm_info_buf;
	const struct tm *tm_info;

	time(&now);
	tm_info = localtime_r(&now, &tm_info_buf);
	if (tm_info) {
		strftime(datetime, len, "%Y:%m:%d %H:%M:%S", tm_info);
	} else {
		/* Fallback if localtime_r fails */
		snprintf(datetime, len, "1970:01:01 00:00:00");
	}
}

/**
 * @brief Generate unique filename with timestamp
 * @details
 * Creates filename in format: snapshot_YYYY-MM-DD_HH-MM-SS-mmm.jpg
 * where mmm is milliseconds (000-999)
 * @param[out] filename Buffer for generated filename
 * @param[in] size Buffer capacity
 * @param[in] output_dir Output directory path
 */
static void generateFilename(char *filename, size_t size, const char *output_dir)
{
	struct timespec ts;
	struct tm tm_info_buf;
	const struct tm *tm_info;
	char timestamp[48];
	int ret;
	int millisec;

	/* Get current time with millisecond precision */
	clock_gettime(CLOCK_REALTIME, &ts);
	millisec = ts.tv_nsec / 1000000; /* Convert nanoseconds to milliseconds */

	tm_info = localtime_r(&ts.tv_sec, &tm_info_buf);
	if (tm_info) {
		/* Format: YYYY-MM-DD_HH-MM-SS-mmm */
		strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", tm_info);
		snprintf(timestamp + strlen(timestamp), sizeof(timestamp) - strlen(timestamp), "-%03d", millisec);
	} else {
		/* Fallback timestamp with nanoseconds */
		snprintf(timestamp, sizeof(timestamp), "%ld-%09ld", (long)ts.tv_sec, ts.tv_nsec);
	}

	ret = snprintf(filename, size, "%s/snapshot_%s.jpg", output_dir, timestamp);
	if (ret >= (int)size) {
		/* Path was truncated, use a shorter format */
		snprintf(filename, size, "snapshot_%s.jpg", timestamp);
	}
}

/*------------------------------------------------------------------------------
 * System Configuration
 *----------------------------------------------------------------------------*/

/**
 * @brief Set OOM killer score adjustment for process protection
 * @details
 * Sets /proc/self/oom_score_adj to -500 (high priority but not absolute immunity).
 * Lower values make the process less likely to be killed by the OOM killer.
 * Range: -1000 (never kill, requires CAP_SYS_ADMIN) to +1000 (always kill first).
 * Value -500 provides strong protection while allowing OOM killer to still act
 * in extreme memory pressure scenarios.
 */
static void setOOMScore(void)
{
	FILE *fp = fopen("/proc/self/oom_score_adj", "w");
	if (fp) {
		if (fprintf(fp, "%d", -500) < 0) {
			fprintf(stderr, "Warning: Failed to set OOM score adjustment\n");
		}
		fclose(fp);
	} else {
		fprintf(stderr, "Warning: Unable to open /proc/self/oom_score_adj (may need elevated privileges)\n");
	}
}
