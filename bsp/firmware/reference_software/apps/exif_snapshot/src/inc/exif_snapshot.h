/*
 * EXIF Snapshot v1.1.0 - Trail Camera MJPEG Capture with EXIF Metadata
 *
 * Changelog:
 *   v1.1.0 (2025-11-28)
 *     - Added continuous bitstream capture with background thread
 *     - Implemented single-buffer mechanism with fast memcpy() under lock
 *     - Enhanced support for long capture intervals
 *     - Camera parameter integration from bitstream V3
 *
 *   v1.0.0 (2025-10-16)
 *     - MJPEG snapshot capture with EXIF 2.32 metadata embedding
 *     - GPS coordinate support (latitude, longitude, altitude)
 *     - Configurable capture intervals and output directory
 *     - Thread-safe operation with proper resource management
 */

#ifndef EXIF_SNAPSHOT_H_
#define EXIF_SNAPSHOT_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EXIF_SNAPSHOT_VERSION "1.1.0"
#define EXIF_MAX_PATH_LEN 256
#define EXIF_MAX_DATETIME_LEN 32

/**
 * @brief Error codes for EXIF snapshot module
 * @details
 * Standard error codes returned by module functions following
 * Augentix coding standards with ERROR_NONE = 0
 */
typedef enum exif_error_code {
	EXIF_ERROR_NONE = 0, /**< Success */
	EXIF_ERROR_NOT_INITIALIZED = -1, /**< Module not initialised */
	EXIF_ERROR_INVALID_PARAMS = -2, /**< Invalid parameters provided */
	EXIF_ERROR_FILE_OPERATION = -3, /**< File operation failed */
	EXIF_ERROR_MEMORY = -4, /**< Memory allocation failed */
	EXIF_ERROR_MPP_FAILURE = -5, /**< MPP operation failed */
	EXIF_ERROR_TIMEOUT = -6, /**< Operation timed out */
	EXIF_ERROR_SYSTEM = -7, /**< System call failed */
	EXIF_ERROR_CAPTURE_FAILED = -8, /**< Capture operation failed */
	EXIF_ERROR_UNKNOWN = -99 /**< Unknown error */
} ExifErrorCode;

/**
 * @brief EXIF metadata structure for trail camera snapshots
 * @details
 * Structure containing comprehensive EXIF metadata fields
 * suitable for trail camera applications including GPS coordinates,
 * timestamps, and camera information.
 */
typedef struct exif_metadata {
	/* Basic EXIF tags */
	char make[32];
	char model[64];
	char software[64];
	char description[256];
	char datetime[EXIF_MAX_DATETIME_LEN];

	/* GPS information (optional) */
	bool has_gps;
	double latitude;
	double longitude;
	double altitude;

	/* Image properties */
	uint32_t image_width;
	uint32_t image_height;
	uint16_t orientation;

	/* Camera capture parameters from MPP */
	uint32_t exposure_time; /* Exposure time in microseconds */
	uint32_t f_number; /* F-number of lens */
	uint32_t flash; /* Flash status */
	uint32_t iso; /* ISO speed rating (sensor_gain * isp_gain * 100) */
} ExifMetadata;

/**
 * @brief Set frame buffer capacity before initialization
 * @details
 * Configures the fixed frame buffer capacity for MJPEG capture.
 * Must be called before EXIF_snapshotInit().
 * Default capacity is 6291456 bytes (6 MB) if not specified.
 * @param[in] capacity Buffer capacity in bytes
 * @return 0 on success, negative error code on failure
 * @note This function must be called before initialization
 * @see EXIF_snapshotInit()
 */
int EXIF_snapshotSetBufferCapacity(size_t capacity);

/**
 * @brief Initialise the EXIF snapshot module
 * @details
 * Initialises the module and prepares for snapshot capture.
 * Must be called before any other module functions.
 * Allocates a fixed-size frame buffer (configurable via EXIF_snapshotSetBufferCapacity).
 * @return 0 on success, negative error code on failure
 * @note This function allocates resources that must be freed by calling deinit
 * @see EXIF_snapshotDeinit()
 * @see EXIF_snapshotSetBufferCapacity()
 */
int EXIF_snapshotInit(void);

/**
 * @brief Deinitialise the EXIF snapshot module
 * @details
 * Cleans up all resources allocated by the module.
 * @return 0 on success, negative error code on failure
 * @see EXIF_snapshotInit()
 */
int EXIF_snapshotDeinit(void);

/**
 * @brief Capture MJPEG snapshot with EXIF metadata
 * @details
 * Captures a MJPEG frame from the camera and saves it with
 * embedded EXIF metadata to the specified file path.
 * @param[in] output_path Path where the JPEG file will be saved
 * @param[in] metadata EXIF metadata to embed in the image
 * @return 0 on success, negative error code on failure
 * @retval 0 Success
 * @retval -1 Module not initialised
 * @retval -2 Invalid parameters
 * @retval -3 File operation failed
 * @retval -4 Memory allocation failed
 * @note The output directory must exist before calling this function
 */
int EXIF_snapshotCapture(const char *output_path, const ExifMetadata *metadata);

/**
 * @brief Set GPS coordinates in metadata
 * @details
 * Helper function to set GPS coordinates in the metadata structure.
 * @param[in,out] metadata Metadata structure to update
 * @param[in] latitude Latitude in decimal degrees (positive for North)
 * @param[in] longitude Longitude in decimal degrees (positive for East)
 * @param[in] altitude Altitude in metres above sea level
 * @return 0 on success, negative error code on failure
 * @note GPS coordinates will be converted to EXIF format internally
 */
int EXIF_snapshotSetGpsInfo(ExifMetadata *metadata, double latitude, double longitude, double altitude);

/**
 * @brief Set current datetime in metadata
 * @details
 * Helper function to set the capture datetime in metadata.
 * @param[in,out] metadata Metadata structure to update
 * @param[in] datetime DateTime string in "YYYY:MM:DD HH:MM:SS" format
 * @return 0 on success, negative error code on failure
 */
int EXIF_snapshotSetDatetime(ExifMetadata *metadata, const char *datetime);

#ifdef __cplusplus
}
#endif

#endif /* EXIF_SNAPSHOT_H_ */
