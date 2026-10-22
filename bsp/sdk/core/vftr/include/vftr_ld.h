/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_ld.h
 * @brief Core feature-lib for light detection
 */

#ifndef VFTR_LD_H_
#define VFTR_LD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_index.h"
#include "vftr_dump.h"

#define VFTR_LD_MAX_SEN_TH 255
#define VFTR_LD_MIN_SEN_TH 1
#define VFTR_LD_MAX_ALARM_SUPR 10
#define VFTR_LD_MIN_ALARM_SUPR 0
#define VFTR_LD_MAX_ALARM_LATENCY 10
#define VFTR_LD_MIN_ALARM_LATENCY 0
#define VFTR_LD_MAX_ALARM_LATENCY_CYC 5
#define VFTR_LD_MIN_ALARM_LATENCY_CYC 1
#define VFTR_LD_MAX_DET_PERIOD 10
#define VFTR_LD_MIN_DET_PERIOD 0

/**
 * @brief Enumeration of light detection mode.
 */
typedef enum {
	VFTR_LD_LIGHT_NONE = 0x0, /**< Change none.*/
	VFTR_LD_LIGHT_ON = 0x1, /**< Triggered by light ON. */
	VFTR_LD_LIGHT_OFF = 0x2, /**< Triggered by light OFF. */
	VFTR_LD_LIGHT_BOTH = 0x3, /**< Triggered by both light ON and light OFF. */
	VFTR_LD_LIGHT_NUM = 0x4, /**< Number of light condition. */
} VFTR_LD_COND_E;

/**
 * @brief Structure of light detection parameters.
 */
typedef struct {
	UINT8 alarm_supr; /**< Interval(sec) for alarm suppression. */
	UINT8 alarm_latency; /**< Latency(sec) for alarm and canceling. */
	UINT8 alarm_latency_cycle; /**< Detection period(sec) in latency interval when first alarm is triggered. */
	UINT8 det_period; /**< Detection period(sec) in normal circumstance. */
	UINT16 sen_th; /**< Threshold of light change(sensitivity). */
	MPI_RECT_POINT_S roi; /**< Defined roi. */
	VFTR_LD_COND_E trig_cond; /**< Trigger condition. */
} VFTR_LD_PARAM_S;

/**
 * @brief Structure of light detection status.
 */
typedef struct {
	VFTR_LD_COND_E trig_cond; /**< Triggered condition. */
} VFTR_LD_STATUS_S;

/**
 * @brief Structure for the light detection instance.
 */
typedef struct {
	VFTR_LD_PARAM_S param; /**< light detection parameters */
	VFTR_LD_STATUS_S status; /**< light detection status */
} VFTR_LD_INSTANCE_S;

/* Interface function prototype */

VFTR_LD_INSTANCE_S *VFTR_LD_newInstance();
INT32 VFTR_LD_deleteInstance(VFTR_LD_INSTANCE_S **instance);
INT32 VFTR_LD_setParam(VFTR_LD_INSTANCE_S *instance, const MPI_SIZE_S *res, const VFTR_LD_PARAM_S *param);
INT32 VFTR_LD_checkParam(const MPI_SIZE_S *res, const VFTR_LD_PARAM_S *param);
INT32 VFTR_LD_getParam(const VFTR_LD_INSTANCE_S *instance, VFTR_LD_PARAM_S *param);
INT32 _VFTR_LD_dump(VFTR_LD_INSTANCE_S *instance, const UINT8 mcvp_avg_y_cfg_idx, VFTR_LD_STATUS_S *status);
INT32 _VFTR_LD_detect(VFTR_LD_INSTANCE_S *instance, const UINT8 mcvp_avg_y_cfg_idx, VFTR_LD_STATUS_S *status);

/**
 * @brief An inline function. If variable vftr_dump_en is true, 
 * then call dump function for debugging.
 * @see _VFTR_AROI_dump()
 * @see _VFTR_AROI_detectRoi()
 */
FORCE_INLINE INT32 VFTR_LD_detect(VFTR_LD_INSTANCE_S *instance, const UINT8 mcvp_avg_y_cfg_idx,
                                  VFTR_LD_STATUS_S *status)
{
	INT32 _err = _VFTR_LD_detect(instance, mcvp_avg_y_cfg_idx, status);
	if (vftr_dump_en) {
		_VFTR_LD_dump(instance, mcvp_avg_y_cfg_idx, status);
	}
	return _err;
}

INT32 VFTR_LD_getStat(const VFTR_LD_INSTANCE_S *instance, VFTR_LD_STATUS_S *status);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !VFTR_LD_H_ */
