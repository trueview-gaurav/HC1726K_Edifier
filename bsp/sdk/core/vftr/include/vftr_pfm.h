/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_pfm.h
 * @brief Core feature-lib for pet feeding monitor
 * @note Because the PFM feature is still evolving, this interface is experimental.
 */

#ifndef VFTR_PFM_H_
#define VFTR_PFM_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_dev.h"
#include "mpi_iva.h"
#include "mpi_dip_alg.h"
#include "vftr_dump.h"

#define VFTR_PFM_SENSITIVITY_MIN 0 /**< Minimal sensitivity. */
#define VFTR_PFM_SENSITIVITY_MAX 255 /**< Maximal sensitivity. */
#define VFTR_PFM_ENDURANCE_MIN 0 /**< Minimal endurance. */
#define VFTR_PFM_REMAINDER_MAX 100 /**< Maximal remainder. */
#define VFTR_PFM_REMAINDER_MIN 0 /**< Minimal remainder. */

/**
 * @brief Enumeration of pet feeding monitor event.
 */
typedef enum {
	VFTR_PFM_EVENT_IDLE = 0,
	VFTR_PFM_EVENT_FILLED,
	VFTR_PFM_EVENT_EATING,
	VFTR_PFM_EVENT_FINISH,
} VFTR_PFM_EVENT_E;

/**
 * @brief Structure for the parameters of pet feeding monitor.
 */
typedef struct {
	INT32 sensitivity; /**< The sensitivity of pet feeding monitor.
	                    * Valid range: [::VFTR_PFM_SENSITIVITY_MIN, ::VFTR_PFM_SENSITIVITY_MAX].
	                    */
	INT32 endurance; /**< The time duration for pet feeding monitor to determine the finish stage.
	                  * Valid range: [::VFTR_PFM_ENDURANCE_MIN, INT_MAX].
	                  */
	MPI_RECT_POINT_S roi; /**< The location of food plate, unit: pixel. */
	MPI_RECT_S window; /**< Resolution of the window performs pet feeding monitor, unit: pixel. */
} VFTR_PFM_PARAM_S;

/**
 * @brief Structure for the pet feeding monitor video features.
 */
typedef struct {
	const MPI_IVA_OBJ_LIST_S *obj_list; /**< Pointer to object list
	                                     * @see MPI_IVA_getBitStreamObjList()
	                                     */
	MPI_ISP_VAR_S var; /**< Variance of the roi.
	                     * @see MPI_DEV_getIspVar
	                     */
	MPI_ISP_Y_AVG y_avg; /**< Y average value of the roi.
	                       * @see MPI_DEV_getIspYAvg
	                       */
	MPI_DIP_STAT_S dip_stat; /**< DIP statistics of the roi.
	                           * @see MPI_getStatistics
	                           */
} VFTR_PFM_INPUT_S;

/**
 * @brief Structure for the result of pet feeding monitor.
 */
typedef struct {
	UINT8 remainder; /**< Pet food remainder percentage. */
	VFTR_PFM_EVENT_E event; /**< Current event. */
} VFTR_PFM_STATUS_S;

typedef struct vftr_pfm_instance VFTR_PFM_INSTANCE_S;

VFTR_PFM_INSTANCE_S *VFTR_PFM_newInstance(void);
int VFTR_PFM_deleteInstance(VFTR_PFM_INSTANCE_S **instance);
int VFTR_PFM_checkParam(const VFTR_PFM_PARAM_S *param);
int VFTR_PFM_setParam(VFTR_PFM_INSTANCE_S *instance, const VFTR_PFM_PARAM_S *param);
int VFTR_PFM_getParam(const VFTR_PFM_INSTANCE_S *instance, VFTR_PFM_PARAM_S *param);
int VFTR_PFM_getStat(const VFTR_PFM_INSTANCE_S *instance, VFTR_PFM_STATUS_S *status);
int _VFTR_PFM_dump(VFTR_PFM_INSTANCE_S *instance, const VFTR_PFM_INPUT_S *input, VFTR_PFM_STATUS_S *status);
int _VFTR_PFM_detect(VFTR_PFM_INSTANCE_S *instance, const VFTR_PFM_INPUT_S *input, VFTR_PFM_STATUS_S *status);

/**
 * @brief An inline function. If variable vftr_dump_en is true, 
 * then call dump function for debugging.
 * @see _VFTR_PFM_dump()
 * @see _VFTR_PFM_detect()
 */
FORCE_INLINE INT32 VFTR_PFM_detect(VFTR_PFM_INSTANCE_S *instance, const VFTR_PFM_INPUT_S *input,
                                   VFTR_PFM_STATUS_S *status)
{
	INT32 _err = _VFTR_PFM_detect(instance, input, status);
	if (vftr_dump_en) {
		_VFTR_PFM_dump(instance, input, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_PFM_H_ */
