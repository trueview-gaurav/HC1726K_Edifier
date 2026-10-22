/*
 * EXIF Snapshot Implementation with libexif
 *
 * This module provides EXIF metadata embedding for MJPEG snapshots
 * from trail cameras using the libexif library.
 */

/* Module header */
#include "exif_snapshot.h"

/* C standard library headers */
#include <errno.h>
#include <math.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* POSIX/System headers */
#include <pthread.h>
#include <sys/mman.h>
#include <unistd.h>

/* Third-party library headers - libexif */
#include <libexif/exif-content.h>
#include <libexif/exif-data.h>
#include <libexif/exif-entry.h>
#include <libexif/exif-utils.h>

/* Project headers - MPP SDK */
#include "mpi_base_types.h"
#include "mpi_enc.h"
#include "mpi_index.h"
#include "mpi_sys.h"

/* Constants */
static const int k_capture_timeout_ms = 2000;
static const int k_max_frame_retries = 30; /* Maximum retries for frame acquisition (~3 seconds) */
static const int k_frame_retry_delay_us = 100000; /* 100ms delay between frame retries */
static const int k_deinit_wait_delay_us = 10000; /* 10ms delay during deinit wait */

/* Fixed frame buffer capacity (configurable via EXIF_snapshotSetBufferCapacity) */
static const size_t k_default_frame_buffer_capacity = 6291456; /* 6 MB default for streaming at 7808x4392 CBR 40 Mbps */
static size_t g_frame_buffer_capacity = 0; /* Global buffer capacity, 0 means use default */

/* MPP frame info parameter validation ranges */
static const uint32_t k_exposure_time_min = 0; /* Minimum exposure time in microseconds */
static const uint32_t k_exposure_time_max = 1000000; /* Maximum exposure time in microseconds (1 second) */
static const uint32_t k_iso_min = 100; /* Minimum ISO (1x gain * 100) */
static const uint32_t k_iso_max = 10000; /* Maximum ISO (100x gain * 100) */

/* Fixed camera parameters (f_number, flash, focal_length not provided by MPP) */
static const uint32_t k_default_f_number = 280; /* f/2.8 (typical for trail cameras) */
static const uint16_t k_default_flash = 0; /* No Flash (trail cameras typically don't use flash in MJPEG mode) */
static const uint32_t k_default_focal_length_num = 28; /* 2.8mm focal length (numerator) */
static const uint32_t k_default_focal_length_den = 10; /* Denominator for 28/10 = 2.8mm */

/* Frame buffer for caching latest captured frame (dynamic per-frame data) */
typedef struct frame_buffer {
	unsigned char *data;
	size_t jpeg_size;       /* Actual JPEG data size in buffer */
	MPI_FRAME_INFO_S frame_info;
	_Atomic(bool) valid;
} FrameBuffer;

/* Module state with thread-safety */
typedef struct module_state {
	_Atomic(bool) initialised;
	_Atomic(bool) mpi_sys_initialised;
	_Atomic(bool) bitstream_sys_initialised;
	_Atomic(bool) bitstream_chn_created;
	_Atomic(bool) capture_thread_running;
	_Atomic(int) active_operations; /* Reference counter for safe deinit */
	MPI_ECHN encoder_channel;
	MPI_BCHN bitstream_channel;
	pthread_t capture_thread;
	size_t fb_capacity;  /* Frame buffer capacity (allocated size) */
	FrameBuffer fb;      /* Frame buffer (dynamic per-frame data) */
} ModuleState;

static ModuleState g_state = {
	.initialised = false,
	.mpi_sys_initialised = false,
	.bitstream_sys_initialised = false,
	.bitstream_chn_created = false,
	.capture_thread_running = false,
	.active_operations = 0,
	.encoder_channel = { { 0 } },
	.bitstream_channel = { { 0 } },
	.capture_thread = 0,
	.fb_capacity = 0,
	.fb = { NULL, 0, { 0 }, false }
};
static pthread_mutex_t g_state_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t g_buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
static atomic_flag g_init_lock = ATOMIC_FLAG_INIT;

/*==============================================================================
 * Forward declarations for static helper functions
 *============================================================================*/

/* Background thread */
static void *captureThreadFunc(void *arg);

/* Frame acquisition */
static int waitForValidFrame(unsigned char **jpeg_data_out, size_t *jpeg_size_out, MPI_FRAME_INFO_S *frame_info_out);

/* EXIF entry creation helpers */
static void createExifEntryAscii(ExifData *data, ExifIfd ifd, ExifTag tag, const char *string);
static void createExifEntryShort(ExifData *data, ExifIfd ifd, ExifTag tag, uint16_t value);
static void createExifEntryRational(ExifData *data, ExifIfd ifd, ExifTag tag, uint32_t numerator, uint32_t denominator);
static void addGpsCoordinate(ExifData *data, ExifTag tag, ExifTag ref_tag, double coordinate, bool is_latitude);

/* EXIF metadata builders */
static void createBasicExifMetadata(ExifData *exif_data, const ExifMetadata *metadata);
static void createCameraParametersExif(ExifData *exif_data, const MPI_FRAME_INFO_S *frame_info);
static void createGpsExifMetadata(ExifData *exif_data, const ExifMetadata *metadata);

/* File I/O */
static int writeJpegWithExif(const char *filename, const unsigned char *jpeg_data, size_t jpeg_size,
                             ExifData *exif_data);

/*==============================================================================
 * Public API Implementation
 *============================================================================*/

int EXIF_snapshotSetBufferCapacity(size_t capacity)
{
	/* Validate buffer capacity (must be at least 1MB for reasonable MJPEG frames) */
	if (capacity < 1048576) { /* 1MB minimum */
		fprintf(stderr, "Error: Buffer capacity too small (minimum: 1048576 bytes)\n");
		return EXIF_ERROR_INVALID_PARAMS;
	}

	/* Cannot change buffer capacity after initialization */
	if (atomic_load(&g_state.initialised)) {
		fprintf(stderr, "Error: Cannot change buffer capacity after initialization\n");
		return EXIF_ERROR_INVALID_PARAMS;
	}

	g_frame_buffer_capacity = capacity;
	printf("Frame buffer capacity set to %zu bytes (%.1f MB)\n", capacity, capacity / 1048576.0);
	return EXIF_ERROR_NONE;
}

int EXIF_snapshotInit(void)
{
	/* Check if already initialised using atomic load */
	if (atomic_load(&g_state.initialised)) {
		printf("Module already initialised\n");
		return 0;
	}

	/* Use atomic test-and-set to ensure only one thread initialises */
	if (atomic_flag_test_and_set(&g_init_lock)) {
		/* Another thread is initialising, wait for it to complete */
		while (!atomic_load(&g_state.initialised)) {
			usleep(1000); /* Wait 1ms */
		}
		return 0;
	}

	/* Double-check after acquiring the lock */
	if (atomic_load(&g_state.initialised)) {
		atomic_flag_clear(&g_init_lock);
		return 0;
	}

	/* Initialise MPP video capture subsystem */
	INT32 ret_mpp;

	/* Initialise MPI system */
	ret_mpp = MPI_SYS_init();
	if (ret_mpp != MPI_SUCCESS) {
		fprintf(stderr, "Failed to initialise MPI system\n");
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_SYSTEM;
	}
	atomic_store(&g_state.mpi_sys_initialised, true);

	/* Initialise bitstream system */
	ret_mpp = MPI_initBitStreamSystem();
	if (ret_mpp != MPI_SUCCESS) {
		fprintf(stderr, "Failed to initialise bitstream system\n");
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_SYSTEM;
	}
	atomic_store(&g_state.bitstream_sys_initialised, true);

	/* Create encoder channel (channel 0 for MJPEG) */
	pthread_mutex_lock(&g_state_mutex);
	g_state.encoder_channel = MPI_ENC_CHN(0);

	/* Verify encoder type is MJPEG */
	MPI_VENC_ATTR_S venc_attr;
	ret_mpp = MPI_ENC_getVencAttr(g_state.encoder_channel, &venc_attr);
	if (ret_mpp != MPI_SUCCESS) {
		pthread_mutex_unlock(&g_state_mutex);
		fprintf(stderr, "Failed to get encoder attributes (error code: %d)\n", ret_mpp);
		MPI_exitBitStreamSystem();
		atomic_store(&g_state.bitstream_sys_initialised, false);
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_SYSTEM;
	}

	if (venc_attr.type != MPI_VENC_TYPE_MJPEG) {
		pthread_mutex_unlock(&g_state_mutex);
		fprintf(stderr, "Error: Encoder channel 0 is not MJPEG (type=%d). EXIF Snapshot only supports MJPEG encoder.\n",
		        venc_attr.type);
		MPI_exitBitStreamSystem();
		atomic_store(&g_state.bitstream_sys_initialised, false);
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_INVALID_PARAMS;
	}

	printf("Encoder type verified: MJPEG (channel 0)\n");

	/* Create bitstream channel */
	g_state.bitstream_channel = MPI_createBitStreamChn(g_state.encoder_channel);
	if (!VALID_MPI_ENC_BCHN(g_state.bitstream_channel)) {
		pthread_mutex_unlock(&g_state_mutex);
		fprintf(stderr, "Failed to create bitstream channel\n");
		MPI_exitBitStreamSystem();
		atomic_store(&g_state.bitstream_sys_initialised, false);
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_SYSTEM;
	}
	atomic_store(&g_state.bitstream_chn_created, true);
	pthread_mutex_unlock(&g_state_mutex);

	/* Allocate fixed-size frame buffer */
	size_t buffer_capacity = (g_frame_buffer_capacity > 0) ? g_frame_buffer_capacity : k_default_frame_buffer_capacity;
	g_state.fb.data = malloc(buffer_capacity);
	if (!g_state.fb.data) {
		fprintf(stderr, "Failed to allocate frame buffer (%zu bytes)\n", buffer_capacity);
		pthread_mutex_lock(&g_state_mutex);
		if (VALID_MPI_ENC_BCHN(g_state.bitstream_channel)) {
			MPI_destroyBitStreamChn(g_state.bitstream_channel);
		}
		atomic_store(&g_state.bitstream_chn_created, false);
		pthread_mutex_unlock(&g_state_mutex);
		MPI_exitBitStreamSystem();
		atomic_store(&g_state.bitstream_sys_initialised, false);
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_MEMORY;
	}
	g_state.fb_capacity = buffer_capacity;
	g_state.fb.jpeg_size = 0;
	atomic_store(&g_state.fb.valid, false);

	/* Lock frame buffer in physical memory to prevent OOM at runtime */
	if (mlock(g_state.fb.data, buffer_capacity) != 0) {
		fprintf(stderr, "Warning: Failed to lock frame buffer in memory (mlock): %s\n", strerror(errno));
		fprintf(stderr, "Continuing without memory locking (may increase OOM risk)\n");
	}

	printf("Allocated fixed frame buffer: %zu bytes (%.1f MB)\n", buffer_capacity, buffer_capacity / 1048576.0);

	/* Start background capture thread with reduced stack size */
	pthread_attr_t thread_attr;
	if (pthread_attr_init(&thread_attr) != 0) {
		fprintf(stderr, "Failed to initialize thread attributes\n");
		/* Free frame buffer */
		munlock(g_state.fb.data, buffer_capacity);
		free(g_state.fb.data);
		g_state.fb.data = NULL;
		g_state.fb_capacity = 0;
		g_state.fb.jpeg_size = 0;
		pthread_mutex_lock(&g_state_mutex);
		if (VALID_MPI_ENC_BCHN(g_state.bitstream_channel)) {
			MPI_destroyBitStreamChn(g_state.bitstream_channel);
		}
		atomic_store(&g_state.bitstream_chn_created, false);
		pthread_mutex_unlock(&g_state_mutex);
		MPI_exitBitStreamSystem();
		atomic_store(&g_state.bitstream_sys_initialised, false);
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_SYSTEM;
	}

	/* Set stack size to 64KB (sufficient for capture thread, saves ~7.75 MB vs default 8 MB) */
	if (pthread_attr_setstacksize(&thread_attr, 65536) != 0) {
		fprintf(stderr, "Warning: Failed to set thread stack size, using default\n");
	}

	atomic_store(&g_state.capture_thread_running, true);
	if (pthread_create(&g_state.capture_thread, &thread_attr, captureThreadFunc, NULL) != 0) {
		fprintf(stderr, "Failed to create capture thread\n");
		pthread_attr_destroy(&thread_attr);
		atomic_store(&g_state.capture_thread_running, false);
		/* Free frame buffer */
		munlock(g_state.fb.data, buffer_capacity);
		free(g_state.fb.data);
		g_state.fb.data = NULL;
		g_state.fb_capacity = 0;
		g_state.fb.jpeg_size = 0;
		pthread_mutex_lock(&g_state_mutex);
		if (VALID_MPI_ENC_BCHN(g_state.bitstream_channel)) {
			MPI_destroyBitStreamChn(g_state.bitstream_channel);
		}
		atomic_store(&g_state.bitstream_chn_created, false);
		pthread_mutex_unlock(&g_state_mutex);
		MPI_exitBitStreamSystem();
		atomic_store(&g_state.bitstream_sys_initialised, false);
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
		atomic_flag_clear(&g_init_lock);
		return EXIF_ERROR_SYSTEM;
	}

	/* Clean up thread attributes */
	pthread_attr_destroy(&thread_attr);

	/* Set initialised flag BEFORE clearing the lock to prevent race */
	atomic_store(&g_state.initialised, true);
	atomic_flag_clear(&g_init_lock);

	printf("EXIF snapshot module initialised successfully\n");
	return 0;
}

int EXIF_snapshotDeinit(void)
{
	if (!atomic_load(&g_state.initialised)) {
		return 0;
	}

	/* Lock for exclusive deinit */
	pthread_mutex_lock(&g_state_mutex);

	/* Double-check under lock */
	if (!atomic_load(&g_state.initialised)) {
		pthread_mutex_unlock(&g_state_mutex);
		return 0;
	}

	/* Wait for active operations to complete */
	while (atomic_load(&g_state.active_operations) > 0) {
		pthread_mutex_unlock(&g_state_mutex);
		usleep(k_deinit_wait_delay_us);
		pthread_mutex_lock(&g_state_mutex);
	}

	/* Mark as not initialised first to prevent new operations */
	atomic_store(&g_state.initialised, false);

	/* Stop capture thread */
	if (atomic_load(&g_state.capture_thread_running)) {
		atomic_store(&g_state.capture_thread_running, false);
		pthread_mutex_unlock(&g_state_mutex);
		/* Wait for thread to exit */
		int join_ret = pthread_join(g_state.capture_thread, NULL);
		if (join_ret != 0) {
			fprintf(stderr, "Warning: Capture thread did not exit cleanly (ret=%d)\n", join_ret);
		}
		pthread_mutex_lock(&g_state_mutex);
	}

	/* Cleanup single frame buffer */
	pthread_mutex_lock(&g_buffer_mutex);
	if (g_state.fb.data) {
		munlock(g_state.fb.data, g_state.fb_capacity);
		free(g_state.fb.data);
		g_state.fb.data = NULL;
		g_state.fb_capacity = 0;
		g_state.fb.jpeg_size = 0;
		atomic_store(&g_state.fb.valid, false);
	}
	pthread_mutex_unlock(&g_buffer_mutex);

	/* Cleanup MPP resources in reverse order */
	if (atomic_load(&g_state.bitstream_chn_created)) {
		if (VALID_MPI_ENC_BCHN(g_state.bitstream_channel)) {
			MPI_destroyBitStreamChn(g_state.bitstream_channel);
		}
		atomic_store(&g_state.bitstream_chn_created, false);
	}

	if (atomic_load(&g_state.bitstream_sys_initialised)) {
		MPI_exitBitStreamSystem();
		atomic_store(&g_state.bitstream_sys_initialised, false);
	}

	if (atomic_load(&g_state.mpi_sys_initialised)) {
		MPI_SYS_exit();
		atomic_store(&g_state.mpi_sys_initialised, false);
	}

	pthread_mutex_unlock(&g_state_mutex);

	printf("EXIF snapshot module deinitialised\n");
	return 0;
}

int EXIF_snapshotSetGpsInfo(ExifMetadata *metadata, double latitude, double longitude, double altitude)
{
	if (!metadata) {
		return EXIF_ERROR_INVALID_PARAMS;
	}

	/* Validate GPS coordinates */
	if (latitude < -90.0 || latitude > 90.0) {
		fprintf(stderr, "Invalid latitude: %.6f (must be between -90 and 90)\n", latitude);
		return EXIF_ERROR_INVALID_PARAMS;
	}

	if (longitude < -180.0 || longitude > 180.0) {
		fprintf(stderr, "Invalid longitude: %.6f (must be between -180 and 180)\n", longitude);
		return EXIF_ERROR_INVALID_PARAMS;
	}

	/* Validate altitude - reasonable range for Earth surface */
	if (altitude < -500.0 || altitude > 10000.0) {
		fprintf(stderr, "Warning: Unusual altitude: %.1f metres\n", altitude);
		/* Allow but warn - some locations may be extreme */
	}

	metadata->latitude = latitude;
	metadata->longitude = longitude;
	metadata->altitude = altitude;
	metadata->has_gps = true;

	return EXIF_ERROR_NONE;
}

int EXIF_snapshotSetDatetime(ExifMetadata *metadata, const char *datetime)
{
	if (!metadata || !datetime) {
		return EXIF_ERROR_INVALID_PARAMS;
	}

	strncpy(metadata->datetime, datetime, EXIF_MAX_DATETIME_LEN - 1);
	metadata->datetime[EXIF_MAX_DATETIME_LEN - 1] = '\0';

	return EXIF_ERROR_NONE;
}

int EXIF_snapshotCapture(const char *output_path, const ExifMetadata *metadata)
{
	ExifData *exif_data = NULL;
	unsigned char *jpeg_data = NULL;
	size_t jpeg_size;
	MPI_FRAME_INFO_S frame_info = { 0 };
	int ret = 0;

	if (!atomic_load(&g_state.initialised)) {
		return EXIF_ERROR_NOT_INITIALIZED;
	}

	if (!output_path || !metadata) {
		return EXIF_ERROR_INVALID_PARAMS;
	}

	/* Increment active operations counter */
	atomic_fetch_add(&g_state.active_operations, 1);

	/* Check capture thread status */
	if (!atomic_load(&g_state.capture_thread_running)) {
		fprintf(stderr, "Error: Capture thread not running\n");
		atomic_fetch_sub(&g_state.active_operations, 1);
		return EXIF_ERROR_NOT_INITIALIZED;
	}

	/* Wait for valid frame from capture thread */
	/* NOTE: waitForValidFrame() locks g_buffer_mutex and keeps it locked */
	ret = waitForValidFrame(&jpeg_data, &jpeg_size, &frame_info);
	if (ret != EXIF_ERROR_NONE) {
		/* waitForValidFrame() failed - mutex not locked */
		atomic_fetch_sub(&g_state.active_operations, 1);
		return ret;
	}

	/* At this point: g_buffer_mutex is LOCKED by waitForValidFrame() */
	/* jpeg_data points directly to g_state.frame_buffer.data */

	/* Create EXIF data structure */
	exif_data = exif_data_new();
	if (!exif_data) {
		pthread_mutex_unlock(&g_buffer_mutex);
		atomic_fetch_sub(&g_state.active_operations, 1);
		return EXIF_ERROR_MEMORY;
	}

	/* Set byte order */
	exif_data_set_byte_order(exif_data, EXIF_BYTE_ORDER_INTEL);

	/* Create IFD structures */
	exif_data_fix(exif_data);

	/* Add basic EXIF metadata */
	createBasicExifMetadata(exif_data, metadata);

	/* Add camera parameters from MPP frame info */
	createCameraParametersExif(exif_data, &frame_info);

	/* Add GPS metadata if available */
	createGpsExifMetadata(exif_data, metadata);

	/* Write JPEG with EXIF */
	ret = writeJpegWithExif(output_path, jpeg_data, jpeg_size, exif_data);

	/* Cleanup */
	exif_data_unref(exif_data);

	/* Unlock frame buffer - background thread can now write new frames */
	pthread_mutex_unlock(&g_buffer_mutex);

	/* Decrement active operations counter */
	atomic_fetch_sub(&g_state.active_operations, 1);

	return ret;
}

/*==============================================================================
 * Static Helper Functions
 *============================================================================*/

/*------------------------------------------------------------------------------
 * Background Thread
 *----------------------------------------------------------------------------*/

/**
 * @brief Background thread function for continuous bitstream capture
 * @details
 * This thread continuously gets bitstream from MPP and updates the frame buffer.
 * Uses single-buffer mechanism with fast memcpy() under lock for main thread access.
 * @param[in] arg Thread argument (unused)
 * @return NULL on thread exit
 */
static void *captureThreadFunc(void *arg)
{
	(void)arg; /* Unused parameter */

	printf("Capture thread started\n");

	while (atomic_load(&g_state.capture_thread_running)) {
		MPI_STREAM_PARAMS_V3_S stream_params;
		INT32 mpp_ret;

		/* Get bitstream from encoder - protect MPP access */
		pthread_mutex_lock(&g_state_mutex);

		/* Check if still running and initialised */
		if (!atomic_load(&g_state.capture_thread_running) || !atomic_load(&g_state.bitstream_chn_created)) {
			pthread_mutex_unlock(&g_state_mutex);
			break;
		}

		mpp_ret = MPI_getBitStreamV3(g_state.bitstream_channel, &stream_params, k_capture_timeout_ms);

		if (mpp_ret == MPI_SUCCESS && stream_params.seg_cnt > 0) {
			/* Calculate total size from all segments */
			size_t jpeg_size = 0;
			UINT32 seg_idx;
			for (seg_idx = 0; seg_idx < stream_params.seg_cnt; seg_idx++) {
				jpeg_size += stream_params.seg[seg_idx].size;
			}

			/* Lock buffer mutex for write */
			pthread_mutex_lock(&g_buffer_mutex);

			/* Check if frame fits in fixed-size buffer */
			if (jpeg_size > g_state.fb_capacity) {
				/* Frame too large for buffer, skip this frame */
				pthread_mutex_unlock(&g_buffer_mutex);
				MPI_releaseBitStreamV3(g_state.bitstream_channel, &stream_params);
				pthread_mutex_unlock(&g_state_mutex);
				fprintf(stderr, "Warning: Frame size (%zu bytes) exceeds buffer capacity (%zu bytes), skipping frame\n",
				        jpeg_size, g_state.fb_capacity);
				/* No delay needed - MPI_getBitStreamV3 will block on next iteration */
				continue;
			}

			/* Copy all segments into the fixed-size buffer */
			size_t offset = 0;
			for (seg_idx = 0; seg_idx < stream_params.seg_cnt; seg_idx++) {
				memcpy(g_state.fb.data + offset,
				       stream_params.seg[seg_idx].uaddr, stream_params.seg[seg_idx].size);
				offset += stream_params.seg[seg_idx].size;
			}

			/* Store frame info, JPEG size, and mark buffer as valid */
			g_state.fb.frame_info = stream_params.frame_info;
			g_state.fb.jpeg_size = jpeg_size;
			atomic_store(&g_state.fb.valid, true);

			pthread_mutex_unlock(&g_buffer_mutex);

			/* Release the bitstream */
			MPI_releaseBitStreamV3(g_state.bitstream_channel, &stream_params);
			pthread_mutex_unlock(&g_state_mutex);
		} else {
			pthread_mutex_unlock(&g_state_mutex);
			/* MPI_getBitStreamV3 already blocked, no additional delay needed */
		}
	}

	printf("Capture thread exiting\n");
	return NULL;
}

/*------------------------------------------------------------------------------
 * Frame Acquisition
 *----------------------------------------------------------------------------*/

/**
 * @brief Wait for a valid frame from the capture thread
 * @details
 * Polls the frame buffer with timeout until a valid frame is available.
 * @param[out] jpeg_data_out Pointer to allocated JPEG data (caller must free)
 * @param[out] jpeg_size_out Size of JPEG data
 * @param[out] frame_info_out Frame information from MPP
 * @return 0 on success, negative error code on failure
 */
static int waitForValidFrame(unsigned char **jpeg_data_out, size_t *jpeg_size_out, MPI_FRAME_INFO_S *frame_info_out)
{
	int retry_count = 0;

	if (!jpeg_data_out || !jpeg_size_out || !frame_info_out) {
		return EXIF_ERROR_INVALID_PARAMS;
	}

	while (retry_count < k_max_frame_retries) {
		if (atomic_load(&g_state.fb.valid)) {
			/* Lock buffer for reading - CALLER MUST UNLOCK after processing */
			pthread_mutex_lock(&g_buffer_mutex);

			/* Double-check validity under lock */
			if (atomic_load(&g_state.fb.valid)) {
				/* Return pointer directly to frame buffer (no copy) */
				*jpeg_size_out = g_state.fb.jpeg_size;
				*jpeg_data_out = g_state.fb.data;
				*frame_info_out = g_state.fb.frame_info;

				/* Mark buffer as consumed to prevent duplicate frames */
				atomic_store(&g_state.fb.valid, false);

				/* NOTE: g_buffer_mutex remains LOCKED - caller must unlock after EXIF processing */

				printf("Captured MJPEG frame: %zu bytes from buffer\n", *jpeg_size_out);
				printf("Frame info - Exposure: %u us, ISO: %u (F-number: f/2.8 fixed, Flash: No Flash fixed)\n",
				       frame_info_out->exposure_time, frame_info_out->iso);
				return EXIF_ERROR_NONE;
			}

			pthread_mutex_unlock(&g_buffer_mutex);
		}

		/* No valid frame yet, wait and retry */
		retry_count++;
		usleep(k_frame_retry_delay_us);

		/* Check if thread is still running */
		if (!atomic_load(&g_state.capture_thread_running)) {
			fprintf(stderr, "Error: Capture thread stopped unexpectedly\n");
			return EXIF_ERROR_SYSTEM;
		}
	}

	/* Max retries exceeded */
	fprintf(stderr, "Error: No valid frame available after %d retries\n", k_max_frame_retries);
	return EXIF_ERROR_TIMEOUT;
}

/*------------------------------------------------------------------------------
 * EXIF Entry Creation Helpers
 *----------------------------------------------------------------------------*/

/**
 * @brief Create and set an ASCII EXIF entry
 * @details
 * Helper function to create and populate an ASCII EXIF tag.
 * @param[in,out] data EXIF data structure
 * @param[in] ifd IFD section for the tag
 * @param[in] tag EXIF tag identifier
 * @param[in] string ASCII string value
 */
static void createExifEntryAscii(ExifData *data, ExifIfd ifd, ExifTag tag, const char *string)
{
	ExifEntry *entry;
	size_t len;

	if (!data || !string) {
		return;
	}

	entry = exif_entry_new();
	if (!entry) {
		return;
	}

	len = strlen(string) + 1; /* Include null terminator */

	entry->data = malloc(len);
	if (!entry->data) {
		exif_entry_unref(entry);
		return;
	}

	memcpy(entry->data, string, len);
	entry->size = len;
	entry->tag = tag;
	entry->components = len;
	entry->format = EXIF_FORMAT_ASCII;

	exif_content_add_entry(data->ifd[ifd], entry);
	exif_entry_unref(entry);
}

/**
 * @brief Create and set a SHORT EXIF entry
 * @details
 * Helper function to create and populate a 16-bit EXIF tag.
 * @param[in,out] data EXIF data structure
 * @param[in] ifd IFD section for the tag
 * @param[in] tag EXIF tag identifier
 * @param[in] value 16-bit value
 */
static void createExifEntryShort(ExifData *data, ExifIfd ifd, ExifTag tag, uint16_t value)
{
	ExifEntry *entry;
	ExifByteOrder order;

	if (!data) {
		return;
	}

	entry = exif_entry_new();
	if (!entry) {
		return;
	}

	entry->data = malloc(2);
	if (!entry->data) {
		exif_entry_unref(entry);
		return;
	}

	entry->tag = tag;
	entry->format = EXIF_FORMAT_SHORT;
	entry->components = 1;
	entry->size = 2;

	order = exif_data_get_byte_order(data);
	exif_set_short(entry->data, order, value);

	exif_content_add_entry(data->ifd[ifd], entry);
	exif_entry_unref(entry);
}

/**
 * @brief Create and set a RATIONAL EXIF entry
 * @details
 * Helper function to create and populate a rational EXIF tag.
 * @param[in,out] data EXIF data structure
 * @param[in] ifd IFD section for the tag
 * @param[in] tag EXIF tag identifier
 * @param[in] numerator Rational numerator
 * @param[in] denominator Rational denominator
 */
static void createExifEntryRational(ExifData *data, ExifIfd ifd, ExifTag tag, uint32_t numerator, uint32_t denominator)
{
	ExifEntry *entry;
	ExifRational rational;
	ExifByteOrder order;

	if (!data) {
		return;
	}

	entry = exif_entry_new();
	if (!entry) {
		return;
	}

	/* NOLINTNEXTLINE(clang-analyzer-unix.MallocSizeof) - EXIF lib uses unsigned char* as generic buffer */
	entry->data = malloc(sizeof(ExifRational));
	if (!entry->data) {
		exif_entry_unref(entry);
		return;
	}

	rational.numerator = numerator;
	rational.denominator = denominator;

	entry->tag = tag;
	entry->format = EXIF_FORMAT_RATIONAL;
	entry->components = 1;
	entry->size = sizeof(ExifRational);

	order = exif_data_get_byte_order(data);
	exif_set_rational(entry->data, order, rational);

	exif_content_add_entry(data->ifd[ifd], entry);
	exif_entry_unref(entry);
}

/**
 * @brief Add GPS coordinate to EXIF data
 * @details
 * Converts decimal degrees to DMS and adds to GPS IFD.
 * @param[in,out] data EXIF data structure
 * @param[in] tag GPS coordinate tag (latitude or longitude)
 * @param[in] ref_tag GPS reference tag (N/S or E/W)
 * @param[in] coordinate Decimal degree value
 * @param[in] is_latitude True for latitude, false for longitude
 */
static void addGpsCoordinate(ExifData *data, ExifTag tag, ExifTag ref_tag, double coordinate, bool is_latitude)
{
	ExifEntry *entry;
	ExifRational values[3];
	ExifByteOrder order;
	char ref[2] = { 0 };
	double abs_coord;
	uint32_t degrees, minutes, seconds_numerator;

	if (!data) {
		return;
	}

	/* Determine reference direction */
	if (is_latitude) {
		ref[0] = (coordinate >= 0) ? 'N' : 'S';
	} else {
		ref[0] = (coordinate >= 0) ? 'E' : 'W';
	}

	/* Add reference */
	createExifEntryAscii(data, EXIF_IFD_GPS, ref_tag, ref);

	/* Convert to DMS */
	abs_coord = fabs(coordinate);
	degrees = (uint32_t)abs_coord;
	double min_decimal = (abs_coord - degrees) * 60.0;
	minutes = (uint32_t)min_decimal;
	double sec_decimal = (min_decimal - minutes) * 60.0;
	seconds_numerator = (uint32_t)(sec_decimal * 10000.0);

	/* Create coordinate entry */
	entry = exif_entry_new();
	if (!entry) {
		return;
	}

	/* NOLINTNEXTLINE(clang-analyzer-unix.MallocSizeof) - EXIF lib uses unsigned char* as generic buffer */
	entry->data = malloc(3 * sizeof(ExifRational));
	if (!entry->data) {
		exif_entry_unref(entry);
		return;
	}

	values[0].numerator = degrees;
	values[0].denominator = 1;
	values[1].numerator = minutes;
	values[1].denominator = 1;
	values[2].numerator = seconds_numerator;
	values[2].denominator = 10000;

	entry->tag = tag;
	entry->format = EXIF_FORMAT_RATIONAL;
	entry->components = 3;
	entry->size = 3 * sizeof(ExifRational);

	order = exif_data_get_byte_order(data);
	exif_set_rational(entry->data, order, values[0]);
	exif_set_rational(entry->data + sizeof(ExifRational), order, values[1]);
	exif_set_rational(entry->data + 2 * sizeof(ExifRational), order, values[2]);

	exif_content_add_entry(data->ifd[EXIF_IFD_GPS], entry);
	exif_entry_unref(entry);
}

/*------------------------------------------------------------------------------
 * EXIF Metadata Builders
 *----------------------------------------------------------------------------*/

/**
 * @brief Create basic EXIF metadata tags
 * @details
 * Adds standard EXIF tags including make, model, software, datetime, etc.
 * @param[in,out] exif_data EXIF data structure
 * @param[in] metadata Metadata to embed
 */
static void createBasicExifMetadata(ExifData *exif_data, const ExifMetadata *metadata)
{
	if (!exif_data || !metadata) {
		return;
	}

	/* Add standard EXIF tags */
	createExifEntryAscii(exif_data, EXIF_IFD_0, EXIF_TAG_MAKE, metadata->make);
	createExifEntryAscii(exif_data, EXIF_IFD_0, EXIF_TAG_MODEL, metadata->model);
	createExifEntryAscii(exif_data, EXIF_IFD_0, EXIF_TAG_SOFTWARE, metadata->software);
	createExifEntryAscii(exif_data, EXIF_IFD_0, EXIF_TAG_DATE_TIME, metadata->datetime);
	createExifEntryAscii(exif_data, EXIF_IFD_0, EXIF_TAG_IMAGE_DESCRIPTION, metadata->description);

	/* Add orientation */
	createExifEntryShort(exif_data, EXIF_IFD_0, EXIF_TAG_ORIENTATION, metadata->orientation);

	/* Add resolution (72 DPI default) */
	createExifEntryRational(exif_data, EXIF_IFD_0, EXIF_TAG_X_RESOLUTION, 72, 1);
	createExifEntryRational(exif_data, EXIF_IFD_0, EXIF_TAG_Y_RESOLUTION, 72, 1);
	createExifEntryShort(exif_data, EXIF_IFD_0, EXIF_TAG_RESOLUTION_UNIT, 2);

	/* Add EXIF SubIFD tags */
	createExifEntryAscii(exif_data, EXIF_IFD_EXIF, EXIF_TAG_DATE_TIME_ORIGINAL, metadata->datetime);
	createExifEntryAscii(exif_data, EXIF_IFD_EXIF, EXIF_TAG_DATE_TIME_DIGITIZED, metadata->datetime);

	/* Update EXIF version to 2.32 (exif_data_fix creates default 0210) */
	ExifEntry *version_entry = exif_content_get_entry(exif_data->ifd[EXIF_IFD_EXIF], EXIF_TAG_EXIF_VERSION);
	if (version_entry && version_entry->data && version_entry->size >= 4) {
		const unsigned char exif_version[] = { '0', '2', '3', '2' }; /* EXIF 2.32 */
		memcpy(version_entry->data, exif_version, 4);
	}
}

/**
 * @brief Create camera parameter EXIF tags from MPP frame info
 * @details
 * Adds camera capture parameters including exposure time, ISO, f-number,
 * flash, white balance, focal length, and exposure program.
 * @param[in,out] exif_data EXIF data structure
 * @param[in] frame_info Frame information from MPP
 */
static void createCameraParametersExif(ExifData *exif_data, const MPI_FRAME_INFO_S *frame_info)
{
	if (!exif_data || !frame_info) {
		return;
	}

	/* Add camera capture parameters from MPP frame info */
	/* ExposureTime: stored as RATIONAL (exposure_time in microseconds / 1000000) */
	/* Validate exposure_time range [0, 1000000] us */
	if (frame_info->exposure_time >= k_exposure_time_min && frame_info->exposure_time <= k_exposure_time_max) {
		createExifEntryRational(exif_data, EXIF_IFD_EXIF, EXIF_TAG_EXPOSURE_TIME, frame_info->exposure_time,
		                        1000000);
	} else {
		fprintf(stderr, "Warning: Invalid exposure_time %u us (valid range: [%u, %u]), skipping tag\n",
		        frame_info->exposure_time, k_exposure_time_min, k_exposure_time_max);
	}

	/* FNumber: Use fixed value f/2.8 (MPP does not provide real f_number) */
	createExifEntryRational(exif_data, EXIF_IFD_EXIF, EXIF_TAG_FNUMBER, k_default_f_number, 100);

	/* Flash: Use fixed value 0 = No Flash (MPP does not provide real flash status) */
	createExifEntryShort(exif_data, EXIF_IFD_EXIF, EXIF_TAG_FLASH, k_default_flash);

	/* ISO (PhotographicSensitivity in EXIF 2.3+, was ISOSpeedRatings in EXIF 2.2) */
	/* Validate ISO range [100, 10000] (1x to 100x gain) */
	if (frame_info->iso >= k_iso_min && frame_info->iso <= k_iso_max) {
		createExifEntryShort(exif_data, EXIF_IFD_EXIF, EXIF_TAG_ISO_SPEED_RATINGS, (uint16_t)frame_info->iso);
	} else {
		fprintf(stderr, "Warning: Invalid ISO %u (valid range: [%u, %u]), skipping tag\n", frame_info->iso,
		        k_iso_min, k_iso_max);
	}

	/* WhiteBalance: 0 = Auto, 1 = Manual */
	createExifEntryShort(exif_data, EXIF_IFD_EXIF, EXIF_TAG_WHITE_BALANCE, 0);

	/* FocalLength: Use fixed value 2.8mm (MPP does not provide real focal length) */
	createExifEntryRational(exif_data, EXIF_IFD_EXIF, EXIF_TAG_FOCAL_LENGTH, k_default_focal_length_num,
	                        k_default_focal_length_den);

	/* ExposureProgram: 0 = Not defined, 1 = Manual, 2 = Normal program */
	createExifEntryShort(exif_data, EXIF_IFD_EXIF, EXIF_TAG_EXPOSURE_PROGRAM, 2);
}

/**
 * @brief Create GPS EXIF metadata tags
 * @details
 * Adds GPS coordinates, altitude, and timestamp to EXIF data.
 * @param[in,out] exif_data EXIF data structure
 * @param[in] metadata Metadata containing GPS information
 */
static void createGpsExifMetadata(ExifData *exif_data, const ExifMetadata *metadata)
{
	ExifEntry *entry;

	if (!exif_data || !metadata || !metadata->has_gps) {
		return;
	}

	/* GPS version */
	const unsigned char gps_version[] = { 2, 3, 0, 0 };
	entry = exif_entry_new();
	if (entry) {
		entry->data = malloc(4);
		if (entry->data) {
			memcpy(entry->data, gps_version, 4);
			entry->size = 4;
			entry->tag = EXIF_TAG_GPS_VERSION_ID;
			entry->components = 4;
			entry->format = EXIF_FORMAT_BYTE;
			exif_content_add_entry(exif_data->ifd[EXIF_IFD_GPS], entry);
		} else {
			/* Handle allocation failure */
			fprintf(stderr, "Warning: Failed to allocate GPS version data\n");
		}
		exif_entry_unref(entry);
	}

	/* Add coordinates */
	addGpsCoordinate(exif_data, EXIF_TAG_GPS_LATITUDE, EXIF_TAG_GPS_LATITUDE_REF, metadata->latitude, true);
	addGpsCoordinate(exif_data, EXIF_TAG_GPS_LONGITUDE, EXIF_TAG_GPS_LONGITUDE_REF, metadata->longitude, false);

	/* Add altitude - check for overflow before conversion */
	double abs_altitude = fabs(metadata->altitude);
	double max_altitude = (double)UINT32_MAX / 100.0;
	if (abs_altitude > max_altitude) {
		/* Clamp to maximum representable value */
		abs_altitude = max_altitude;
		fprintf(stderr, "Warning: Altitude clamped to maximum representable value\n");
	}
	createExifEntryRational(exif_data, EXIF_IFD_GPS, EXIF_TAG_GPS_ALTITUDE, (uint32_t)(abs_altitude * 100), 100);

	/* Altitude reference (0 = above sea level, 1 = below) */
	unsigned char alt_ref = (metadata->altitude >= 0) ? 0 : 1;
	entry = exif_entry_new();
	if (entry) {
		entry->data = malloc(1);
		if (entry->data) {
			entry->data[0] = alt_ref;
			entry->size = 1;
			entry->tag = EXIF_TAG_GPS_ALTITUDE_REF;
			entry->components = 1;
			entry->format = EXIF_FORMAT_BYTE;
			exif_content_add_entry(exif_data->ifd[EXIF_IFD_GPS], entry);
		} else {
			/* Handle allocation failure */
			fprintf(stderr, "Warning: Failed to allocate altitude ref data\n");
		}
		exif_entry_unref(entry);
	}

	/* Add GPS timestamp */
	time_t now = time(NULL);
	struct tm utc_tm_buf;
	const struct tm *utc_tm = gmtime_r(&now, &utc_tm_buf);
	if (utc_tm) {
		char gps_datestamp[32]; /* YYYY:MM:DD plus null terminator with extra space for safety */
		/* Ensure values are within expected ranges for safety */
		int year = utc_tm->tm_year + 1900;
		int month = utc_tm->tm_mon + 1;
		int day = utc_tm->tm_mday;

		/* Clamp values to reasonable ranges to prevent truncation */
		if (year < 0 || year > 9999) {
			year = 1970;
		}
		if (month < 1 || month > 12) {
			month = 1;
		}
		if (day < 1 || day > 31) {
			day = 1;
		}

		snprintf(gps_datestamp, sizeof(gps_datestamp), "%04d:%02d:%02d", year, month, day);
		createExifEntryAscii(exif_data, EXIF_IFD_GPS, EXIF_TAG_GPS_DATE_STAMP, gps_datestamp);
	}
}

/*------------------------------------------------------------------------------
 * File I/O
 *----------------------------------------------------------------------------*/

/**
 * @brief Write JPEG with EXIF data
 * @details
 * Writes JPEG data with embedded EXIF to file.
 * @param[in] filename Output filename
 * @param[in] jpeg_data JPEG image data
 * @param[in] jpeg_size Size of JPEG data
 * @param[in] exif_data EXIF data structure
 * @return 0 on success, negative error code on failure
 */
static int writeJpegWithExif(const char *filename, const unsigned char *jpeg_data, size_t jpeg_size,
                             ExifData *exif_data)
{
	FILE *fp;
	unsigned char *exif_buffer = NULL;
	unsigned int exif_size = 0;
	int write_result = 0;

	/* Generate EXIF data */
	exif_data_save_data(exif_data, &exif_buffer, &exif_size);
	if (!exif_buffer) {
		return EXIF_ERROR_MEMORY;
	}

	fp = fopen(filename, "wb");
	if (!fp) {
		free(exif_buffer);
		return EXIF_ERROR_FILE_OPERATION;
	}

	/* Write JPEG SOI marker */
	if (fputc(0xFF, fp) == EOF || fputc(0xD8, fp) == EOF) {
		write_result = EXIF_ERROR_FILE_OPERATION;
		goto cleanup;
	}

	/* Write EXIF APP1 segment */
	if (fputc(0xFF, fp) == EOF || fputc(0xE1, fp) == EOF) {
		write_result = EXIF_ERROR_FILE_OPERATION;
		goto cleanup;
	}
	/* APP1 size (big-endian, includes size field) */
	if (fputc((exif_size + 2) >> 8, fp) == EOF || fputc((exif_size + 2) & 0xFF, fp) == EOF) {
		write_result = EXIF_ERROR_FILE_OPERATION;
		goto cleanup;
	}
	/* Write EXIF data */
	if (fwrite(exif_buffer, 1, exif_size, fp) != exif_size) {
		write_result = EXIF_ERROR_FILE_OPERATION;
		goto cleanup;
	}

	/* Write rest of JPEG (skip original SOI if present) */
	if (jpeg_size >= 2 && jpeg_data[0] == 0xFF && jpeg_data[1] == 0xD8) {
		/* Skip SOI marker */
		if (fwrite(jpeg_data + 2, 1, jpeg_size - 2, fp) != jpeg_size - 2) {
			write_result = EXIF_ERROR_FILE_OPERATION;
			goto cleanup;
		}
	} else {
		/* Write all data */
		if (fwrite(jpeg_data, 1, jpeg_size, fp) != jpeg_size) {
			write_result = EXIF_ERROR_FILE_OPERATION;
			goto cleanup;
		}
	}

cleanup:
	fclose(fp);
	free(exif_buffer);
	return write_result;
}
