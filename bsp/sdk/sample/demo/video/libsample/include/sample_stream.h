#ifndef SAMPLE_STREAM_H_
#define SAMPLE_STREAM_H_

#include <linux/limits.h>
#ifdef __cplusplus
extern "C" {
#endif /**< __cplusplus */

#include "mpi_base_types.h"
#include "mpi_dev.h"
#include "mpi_enc.h"
#include "mpi_index.h"
#include "mpi_sys.h"

#include "sample_dip.h"
#include "sample_light_src.h"

#define SAMPLE_MAX_INI_FILES (3)
#define SAMPLE_MAX_PERI_GPIO_NUM (2)

#define MAX_IP_LENGTH 32

/* MPI unrelated parameters */
typedef enum { AOV_RTC, AOV_PIR } AOV_SRC_E;
#define AOV_CTRL_FNAME "/etc/aov"

typedef struct {
	UINT8 show_params; /**< 0: hide, 1: verbose */
	UINT8 aov_en; /**< Whether AOV is enabled */
	UINT8 aov_src; /**< 0: all, 1: rtc, 2: PIR, 3:network */
	UINT32 aov_period_ms;   /**< AOV sleep period time in milliseconds */
	UINT32 aov_stable_cnt;   /**< AOV counter (unit: second) if no motion, then go suspend */
} CONF_CASE_GEN_PARAM;

typedef struct {
	UINT8 enable;
	char client_ip[MAX_IP_LENGTH];
	UINT32 client_port;
} CONF_UDPSTREAM_PARAM_S;

typedef struct {
	UINT8 enable;
	UINT8 startup_skip_count;
	INT32 frame_num;
	char fname[256]; /* TODO */
	INT32 max_dumped_files;
	UINT8 sync_with_audio;
	UINT8 file_mode; /**< RECORD_FILE_BLOCKING_RETRY(0) or RECORD_FILE_NONBLOCK_REDIRECT(1), see frame_dumper.h */
} CONF_RECORDING_PARAM_S;

typedef struct {
	UINT8 enable;
	CONF_UDPSTREAM_PARAM_S stream;
	CONF_RECORDING_PARAM_S record;
} CONF_BITSTREAM_PARAM_S;

typedef enum audio_format { UNKNOWN = -1, S16LE } AUDIO_FORMAT_E;

typedef struct {
	UINT32 audio_sample_rate;
	UINT32 audio_frame_size;
	AUDIO_FORMAT_E format;
	char fname[256];
	INT32 max_dumped_files;
	INT32 audio_max_frame_count;
} CONF_AUDIO_RECORDING_PARAM_S;

typedef struct {
	UINT8 enable;
	CONF_AUDIO_RECORDING_PARAM_S record;
} CONF_AUDIO_PARAM_S;

/**
 * @struct CONF_SYS_PARAM_S
 * @brief Structure for storing VB configuration
 */
typedef struct {
	MPI_VB_CONF_S vb_conf;
} CONF_SYS_PARAM_S;

/**
 * @struct CONF_PATH_PARAM_S
 * @brief Structure for storing video path configuration
 */
typedef struct {
	UINT8 enable; /**< Enable flag. */
	char pca_file[PATH_MAX];
	MPI_PATH_ATTR_S attr;
} CONF_PATH_PARAM_S;

/**
 * @struct CONF_CHN_PARAM_S
 * @brief Structure for storing video channel configuration
 */
typedef struct {
	UINT8 enable; /**< Enable flag */
	MPI_CHN_ATTR_S attr;
	MPI_CHN_LAYOUT_S layout;
	MPI_WIN_ATTR_S win[MPI_MAX_VIDEO_WIN_NUM];
} CONF_CHN_PARAM_S;

/**
 * @struct CONF_DEV_PARAM_S
 * @brief Structure for storing video device configuration.
 */
typedef struct {
	UINT8 enable; /**< Enable flag */
	MPI_DEV_ATTR_S attr;
	CONF_PATH_PARAM_S path[MPI_MAX_INPUT_PATH_NUM];
	CONF_CHN_PARAM_S chn[MPI_MAX_VIDEO_CHN_NUM];
	MPI_STITCH_ATTR_S stitch;
	MPI_LDC_ATTR_S ldc;
	MPI_PANORAMA_ATTR_S panorama;
	MPI_PANNING_ATTR_S panning;
	MPI_SURROUND_ATTR_S surround;
} CONF_DEV_PARAM_S;

typedef struct {
	UINT8 enable; /**< Enable flag */
	MPI_ENC_BIND_INFO_S bind;
	MPI_ENC_CHN_ATTR_S attr;
	MPI_VENC_ATTR_S venc_attr;
} CONF_ECHN_PARAM_S;

/**
 * @struct SAMPLE_CONF_S
 * @brief Structure for storing video pipeline configurations.
 */
typedef struct {
	UINT8 osd_visible; /**< Flag to set OSD visiblity when start streaming */
	CONF_CASE_GEN_PARAM casegen;
	CONF_SYS_PARAM_S sys;
	CONF_DEV_PARAM_S dev[MPI_MAX_VIDEO_DEV_NUM];
	CONF_ECHN_PARAM_S enc_chn[MPI_MAX_ENC_CHN_NUM];
	CONF_BITSTREAM_PARAM_S bitstream[MPI_MAX_ENC_CHN_NUM];
	CONF_AUDIO_PARAM_S audio;
} SAMPLE_CONF_S;

int SAMPLE_createVideoPipeline(const SAMPLE_CONF_S *conf);
int SAMPLE_destroyVideoPipeline(const SAMPLE_CONF_S *conf);
int SAMPLE_startStream(const SAMPLE_CONF_S *conf);
int SAMPLE_stopStream(const SAMPLE_CONF_S *conf);

#ifdef __cplusplus
}
#endif /**< __cplusplus */

#endif /**< SAMPLE_STREAM_H_ */
