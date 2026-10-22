/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_td.h
 * @brief Core feature-lib for tamper detection
 */

#ifndef VFTR_TD_H_
#define VFTR_TD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @cond
*/
#include "mpi_base_types.h"
#include "mpi_index.h"

#include "mpi_dip_alg.h"
#include "mpi_dev.h"
#include "vftr_dump.h"

/** @endcond
*/

#define VFTR_TD_SENSITIVITY_MIN 0 /**< minimal sensitivity. */
#define VFTR_TD_SENSITIVITY_MAX 255 /**< maximal sensitivity. */
#define VFTR_TD_ENDURANCE_MIN 0 /**< minimal endurance. */
#define VFTR_TD_ENDURANCE_MAX 255 /**< maximal endurance. */
#define VFTR_TD_REDIRECT_SENSITIVITY_MIN 0 /**< minimal redirect sensitivity. */
#define VFTR_TD_REDIRECT_SENSITIVITY_MAX 255 /**< maximal redirect sensitivity. */
#define VFTR_TD_REDIRECT_GLOBAL_CHANGE_MIN 0 /**< minimal global change. */
#define VFTR_TD_REDIRECT_GLOBAL_CHANGE_MAX 255 /**< maximal global change. */
#define VFTR_TD_REDIRECT_TRIGGER_DELAY_MIN 0 /**< minimal trigger delay. */
#define VFTR_TD_REDIRECT_TRIGGER_DELAY_MAX 3600 /**< maximal trigger delay. */

/**
 * @brief Enumeration of tamper alarm.
 */
typedef enum {
	VFTR_TD_ALARM_BLOCK, /**< Block tamper type detects. */
	VFTR_TD_ALARM_REDIRECT, /**< redirect tamper type detects. */
	VFTR_TD_ALARM_NUM /**< The number of the tamper type. */
} VFTR_TD_ALARM_E;

/**
 * @brief Structure for the parameters of tamper detection.
 */
typedef struct {
	BOOL en_block_det; /**< Indicate whether block tamper detection is enabled. */
	BOOL en_redirect_det; /**< Indicate whether redirect tamper detection is enabled. */

	INT32 sensitivity; /**< The sensitivity of block tamper detection. */
	INT32 endurance; /**< The endurance of the block tamper event to trigger alarm. */

	INT32 redirect_sensitivity; /**< The sensitivity of redirect tamper detection. */
	INT32 redirect_global_change; /**< The global change of redirect tamper detection. */
	INT32 redirect_trigger_delay; /**< The trigger delay of redirect tamper detection. */
} VFTR_TD_PARAM_S;

/**
 * @brief Structure for the result of tamper detection.
 */
typedef struct {
	INT32 timestamp; /**< Reserved. */
	INT32 alarm; /**< Tamper alarm. */
} VFTR_TD_STATUS_S;

/**
 * @brief Structure for the inputs of tamper detection within Region of interest.
 */
typedef struct {
	MPI_DIP_STAT_S dip_stat;
	MPI_ISP_MV_HIST_S mv_hist; /**< Motion vector histogram */
	MPI_ISP_VAR_S var; /**< Variance value */
} VFTR_TD_MPI_INPUT_S;

typedef struct vftr_td_algo_status_s VFTR_TD_ALGO_STATUS_S;

/**
 * @brief Structure for the tamper detection object.
 */
typedef struct {
	VFTR_TD_PARAM_S param; /**< Tamper detection parameters */
	VFTR_TD_STATUS_S status; /**< Tamper detection status */
	VFTR_TD_ALGO_STATUS_S *algo_status; /**< Anonymous TD internal object pointer */
	INT32 state; /**< Current TD state */
	INT32 frame_cnt; /**< Current TD frame count */
	INT32 next_frame; /**< Current TD next detect frame */
	INT32 regis_frame_cnt; /**< Current TD registration frame count */
} VFTR_TD_INSTANCE_S;

/* Interface function prototype */

VFTR_TD_INSTANCE_S *VFTR_TD_newInstance();
INT32 VFTR_TD_deleteInstance(VFTR_TD_INSTANCE_S **instance);
INT32 VFTR_TD_setParam(VFTR_TD_INSTANCE_S *instance, const VFTR_TD_PARAM_S *param);
INT32 VFTR_TD_checkParam(const VFTR_TD_PARAM_S *param);
INT32 VFTR_TD_getParam(const VFTR_TD_INSTANCE_S *instance, VFTR_TD_PARAM_S *param);
INT32 _VFTR_TD_dump(VFTR_TD_INSTANCE_S *instance, const VFTR_TD_MPI_INPUT_S *mpi_input, VFTR_TD_STATUS_S *status);
INT32 _VFTR_TD_detect(VFTR_TD_INSTANCE_S *instance, const VFTR_TD_MPI_INPUT_S *mpi_input, VFTR_TD_STATUS_S *status);
INT32 VFTR_TD_getStat(const VFTR_TD_INSTANCE_S *instance, VFTR_TD_STATUS_S *stat);

INT32 VFTR_TD_init(VFTR_TD_INSTANCE_S *instance, const MPI_RECT_S *roi, const int fps);

/**
 * @brief An inline function. If variable vftr_dump_en is true,
 * then call dump function for debugging.
 * @see _VFTR_TD_dump()
 * @see _VFTR_TD_detect()
 */
FORCE_INLINE INT32 VFTR_TD_detect(VFTR_TD_INSTANCE_S *instance, const VFTR_TD_MPI_INPUT_S *mpi_input,
                                  VFTR_TD_STATUS_S *status)
{
	INT32 _err = _VFTR_TD_detect(instance, mpi_input, status);
	if (vftr_dump_en) {
		_VFTR_TD_dump(instance, mpi_input, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TD_H_ */
