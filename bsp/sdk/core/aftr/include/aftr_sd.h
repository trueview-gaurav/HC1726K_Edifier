/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file aftr_sd.h
 * @brief Core feature-lib for sound detection
 */

#ifndef AFTR_SD_H_
#define AFTR_SD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @cond
 */

#include "mpi_base_types.h"
#include "mpi_iva.h"

#define AFTR_SD_MIN_UINT8 (0)
#define AFTR_SD_MAX_UINT8 (255)

/**
 * @endcond
 */

/**
 * @brief Struct for sound detection parameter
 */
typedef struct {
	UINT8 volume; /**< minimal trigger volume. Range: [0, 255]*/
	float duration; /**< maximal trigger duration. Range: [0, 255] */
	float suppression; /**< suppression time after triggered. Range: [0, 255] */
} AFTR_SD_PARAM_S;

/**
 * @brief Struct for sd status.
 */
typedef struct {
	UINT8 volume; /**< sound volume */
	UINT8 alarm; /**< detection result */
} AFTR_SD_STATUS_S;

/**
 * @cond
 */

/* Struct for sound detection internal status */
typedef struct aftr_sd_algo_status_s AFTR_SD_ALGO_STATUS_S;

/**
 * @endcond
 */

/**
 * @struct AFTR_SD_INSTANCE_S
 * @brief Struct for sound detection instance. 
 * @note AFTR_SD_INSTANCE_S contains the whole context of sound detection,  
 * all function prototype of this file should affect on AFTR_SD_INSTANCE_S
 */
typedef struct {
	AFTR_SD_PARAM_S param; /**< sound detection parameters */
	AFTR_SD_STATUS_S status; /**< sound detection result */
	AFTR_SD_ALGO_STATUS_S *algo_status; /**< sound detection internal status */
} AFTR_SD_INSTANCE_S;

/* Interface function prototype */
AFTR_SD_INSTANCE_S *AFTR_SD_newInstance();
INT32 AFTR_SD_deleteInstance(AFTR_SD_INSTANCE_S **instance);
INT32 AFTR_SD_setParam(AFTR_SD_INSTANCE_S *instance, const AFTR_SD_PARAM_S *param);
INT32 AFTR_SD_checkParam(const AFTR_SD_PARAM_S *param);
INT32 AFTR_SD_getParam(AFTR_SD_INSTANCE_S *instance, AFTR_SD_PARAM_S *param);
INT32 AFTR_SD_detect(AFTR_SD_INSTANCE_S *instance, const char *raw_buffer, int size_of_raw, AFTR_SD_STATUS_S *status);
INT32 AFTR_SD_getStat(AFTR_SD_INSTANCE_S *instance, AFTR_SD_STATUS_S *status);
INT32 AFTR_SD_reset(AFTR_SD_INSTANCE_S *instance);
#ifdef UNIT_TEST
INT32 UT_checkSdParam(const AFTR_SD_PARAM_S *param);
#endif /* UNIT_TEST */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* AFTR_SD_H_ */
