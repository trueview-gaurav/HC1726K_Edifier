/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file aftr_cd.h
 * @brief Core feature-lib for cry detection
 * @note Because the CD feature is still evolving, this interface is experimental.
 */

#ifndef AFTR_CD_H_
#define AFTR_CD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @cond
 */

#include "alsa/asoundlib.h"

#include "mpi_base_types.h"
#include "mpi_iva.h"

#define AFTR_CD_MIN_UINT8 (0)
#define AFTR_CD_MAX_UINT8 (255)
#define AFTR_CD_MIN_UINT16 (0)
#define AFTR_CD_MAX_UINT16 (65535)
#define AFTR_CD_MIN_VOLUME (0)
#define AFTR_CD_MAX_VOLUME (120)
#define AFTR_CD_MIN_WINDOW_SIZE (20)
#define AFTR_CD_MAX_WINDOW_SIZE (256)
#define AFTR_CD_MIN_STRIDE (10)
#define AFTR_CD_MAX_STRIDE (128)
#define AFTR_CD_MIN_TIME (1)
#define AFTR_CD_MAX_TIME (10)

/**
 * @endcond
 */

/**
 * @brief Enumeration of cry detection model windowing function
 */
typedef enum {
	AFTR_CD_MODEL_WINDOW_HAMM = 0, /**< apply Hamming window function */
	AFTR_CD_MODEL_WINDOW_HANN = 1 /**< apply Hanning window function */
} AFTR_CD_WINDOW_FUNCTION_E;

/**
 * @brief Struct for cry detection model parameter
 */
typedef struct {
	AFTR_CD_WINDOW_FUNCTION_E window_function; /**< apply which windowing function during feature extraction. */
	UINT16 window_size; /**< duration of the time window. Unit: ms. It ranges [20, 256], default value: 256 */
	UINT16 stride; /**< step size between successive frames. Unit: ms. It ranges [10, 128], default value: 64 */
} AFTR_CD_MODEL_PARAM_S;

/**
 * @brief Struct for cry detection parameter
 */
typedef struct {
	AFTR_CD_MODEL_PARAM_S m_param; /**< model input param, see AFTR_CD_MODEL_PARAM_S */
	UINT32 sample_rate; /**< sample rate for cry detection. Unit: Hz. Now it only supports 8000 */
	UINT16 time; /**< sound duration for ALSA input, needs to be a multiple of 1024. Unit: ms. It ranges [1024, 10240], default value: 5120 */
	INT16 volume; /**< minimal analyzed volume threshold. Unit: dB. It ranges [0, 120], default value: 60 */
	UINT8 sensitivity; /**< sensitivity value of the model to determine the sound of crying. It ranges [0, 255], default value: 127 */
	snd_pcm_format_t format; /**< pcm format in ALSA. Now it only supports s16_le. */
} AFTR_CD_PARAM_S;

/**
 * @brief Struct for cry detection status
 */
typedef struct {
	UINT8 alarm; /**< detection result, it represents positive (1) or negative (0) */
} AFTR_CD_STATUS_S;

/**
 * @cond
 */

/* Struct for cry detection internal status */
typedef struct aftr_cd_algo_status_s AFTR_CD_ALGO_STATUS_S;

/**
 * @endcond
 */

/**
 * @struct AFTR_CD_INSTANCE_S
 * @brief Struct for cry detection instance
 * @note AFTR_CD_INSTANCE_S contains the whole context of cry detection,  
 * all function prototype of this file should affect on AFTR_CD_INSTANCE_S
 */
typedef struct {
	AFTR_CD_PARAM_S param; /**< cry detection parameters */
	AFTR_CD_STATUS_S status; /**< cry detection result */
	AFTR_CD_ALGO_STATUS_S *algo_status; /**< cry detection internal status */
} AFTR_CD_INSTANCE_S;

/* Interface function prototype */
AFTR_CD_INSTANCE_S *AFTR_CD_newInstance();
INT32 AFTR_CD_deleteInstance(AFTR_CD_INSTANCE_S **instance);
INT32 AFTR_CD_setParam(AFTR_CD_INSTANCE_S *instance, const AFTR_CD_PARAM_S *param);
INT32 AFTR_CD_checkParam(const AFTR_CD_PARAM_S *param);
INT32 AFTR_CD_getParam(AFTR_CD_INSTANCE_S *instance, AFTR_CD_PARAM_S *param);
INT32 AFTR_CD_detect(AFTR_CD_INSTANCE_S *instance, const char *raw_buffer, const int size_of_raw,
                     AFTR_CD_STATUS_S *status);
INT32 AFTR_CD_getStat(AFTR_CD_INSTANCE_S *instance, AFTR_CD_STATUS_S *status);
INT32 AFTR_CD_reset(AFTR_CD_INSTANCE_S *instance);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* AFTR_CD_H_ */
