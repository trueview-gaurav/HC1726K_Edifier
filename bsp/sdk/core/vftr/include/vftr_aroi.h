/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_aroi.h
 * @brief Core feature-lib for automatic region of interest (AROI)
 */

#ifndef VFTR_AROI_H_
#define VFTR_AROI_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_index.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

#define VFTR_AROI_MIN_UPDATE_RATIO (0) /**< Min update ratio of AROI. */
#define VFTR_AROI_MAX_UPDATE_RATIO (64) /**< Max update ratio of AROI. */
#define VFTR_AROI_AR_FRACTIONAL_BIT (13) /**< Fraction bit of AROI */
#define VFTR_AROI_MIN_TRACK_DELTA (1) /**< Min track delta of AROI. */
#define VFTR_AROI_MAX_TRACK_DELTA (255) /**< Max track delta of AROI. */
#define VFTR_AROI_MIN_WAIT_TIME (0) /**< Min wait time of AROI. */
#define VFTR_AROI_MAX_WAIT_TIME (1023) /**< Max wait time of AROI. */
#define VFTR_AROI_MIN_RETURN_DELTA (1) /**< Min return delta of AROI. */
#define VFTR_AROI_MAX_RETURN_DELTA (255) /**< Max return delta of AROI. */
#define VFTR_AROI_MIN_OBJ_LIFE_TH (0) /**< Min object life threshold of AROI . */
#define VFTR_AROI_MAX_OBJ_LIFE_TH (MPI_IVA_OD_MAX_LIFE) /**< Max object life threshold of AROI . */

/**
 * @struct VFTR_AROI_PARAM_S
 * @brief Struct for automatic region of interest parameter.
 * @details
 * @see VFTR_AROI_INSTANCE_S
 * @see VFTR_AROI_setParam()
 * @see VFTR_AROI_checkParam()
 * @see VFTR_AROI_getParam()
 * @property UINT16 VFTR_AROI_PARAM_S::obj_life_th
 * @arg Range [::VFTR_AROI_MIN_OBJ_LIFE_TH, ::VFTR_AROI_MAX_OBJ_LIFE_TH]
 * @property MPI_SIZE_S VFTR_AROI_PARAM_S::min_roi
 * @arg Range of width (0, @link max_roi @endlink .width]
 * @arg Range of height (0, @link max_roi @endlink .height]
 * @property MPI_SIZE_S VFTR_AROI_PARAM_S::max_roi
 * @arg Range of width >= @link min_roi @endlink .width.
 * @arg Range of height >= @link min_roi @endlink .height.
 * @property UINT8 VFTR_AROI_PARAM_S::max_track_delta_x
 * @arg Range [::VFTR_AROI_MIN_TRACK_DELTA, ::VFTR_AROI_MAX_TRACK_DELTA]
 * @property UINT8 VFTR_AROI_PARAM_S::max_track_delta_y
 * @arg Range [::VFTR_AROI_MIN_TRACK_DELTA, ::VFTR_AROI_MAX_TRACK_DELTA]
 * @property UINT8 VFTR_AROI_PARAM_S::max_return_delta_x
 * @arg Range [::VFTR_AROI_MIN_RETURN_DELTA, ::VFTR_AROI_MAX_RETURN_DELTA]
 * @property UINT8 VFTR_AROI_PARAM_S::max_return_delta_y
 * @arg Range [::VFTR_AROI_MIN_RETURN_DELTA, ::VFTR_AROI_MAX_RETURN_DELTA]
 * @property UINT16 VFTR_AROI_PARAM_S::wait_time
 * @arg Range [::VFTR_AROI_MIN_WAIT_TIME, ::VFTR_AROI_MAX_WAIT_TIME]
 * @property UINT8 VFTR_AROI_PARAM_S::update_ratio
 * @arg Range [::VFTR_AROI_MIN_UPDATE_RATIO, ::VFTR_AROI_MAX_UPDATE_RATIO]
 */
typedef struct {
	UINT16 obj_life_th; /**< life threshold of object */
	UINT16 aspect_ratio; /**< aspect ratio of AROI */
	MPI_SIZE_S min_roi; /**< minimal AROI */
	MPI_SIZE_S max_roi; /**< maximal AROI */
	UINT8 max_track_delta_x; /**< maximal x component of AROI movement when tracking */
	UINT8 max_track_delta_y; /**< maximal y component of AROI movement when tracking */
	UINT8 max_return_delta_x; /**< maximal x component of AROI movement when return */
	UINT8 max_return_delta_y; /**< maximal y component of AROI movement when return */
	UINT16 wait_time; /**< wait time between last object and return to center */
	UINT8 update_ratio; /**< updating ratio */
} VFTR_AROI_PARAM_S;

/**
 * @struct VFTR_AROI_STATUS_S
 * @brief Struct for aroi status.
 * @details
 * @see VFTR_AROI_INSTANCE_S
 * @see VFTR_AROI_detectRoi()
 * @see VFTR_AROI_getStat()
 */
typedef struct {
	MPI_RECT_POINT_S roi; /**< Coordinate of ROI */
} VFTR_AROI_STATUS_S;

/**
 * @cond
 */

typedef struct vftr_aroi_algo_status_s VFTR_AROI_ALGO_STATUS_S;

/**
 * @endcond
 */

/**
 * @struct VFTR_AROI_INSTANCE_S
 * @brief Struct for AROI instance status.
 * @note VFTR_AROI_INSTANCE_S contains the whole context of AROI, all function prototype of this file should affect on VFTR_AROI_INSTANCE_S
 * @see VFTR_AROI_newInstance()
 * @see VFTR_AROI_deleteInstance()
 * @see VFTR_AROI_setParam()
 * @see VFTR_AROI_getParam()
 * @see VFTR_AROI_detectRoi()
 * @see VFTR_AROI_getStat()
 * @see VFTR_AROI_getTarget()
 */
typedef struct {
	VFTR_AROI_PARAM_S param;
	VFTR_AROI_STATUS_S status;
	VFTR_AROI_ALGO_STATUS_S *algo_status;
} VFTR_AROI_INSTANCE_S;

VFTR_AROI_INSTANCE_S *VFTR_AROI_newInstance();
INT32 VFTR_AROI_deleteInstance(VFTR_AROI_INSTANCE_S **instance);
INT32 VFTR_AROI_setParam(VFTR_AROI_INSTANCE_S *instance, const MPI_SIZE_S *res, const VFTR_AROI_PARAM_S *param);
INT32 VFTR_AROI_checkParam(const VFTR_AROI_PARAM_S *param, const MPI_SIZE_S *res);
INT32 VFTR_AROI_getParam(const VFTR_AROI_INSTANCE_S *instance, VFTR_AROI_PARAM_S *param);
INT32 _VFTR_AROI_dump(VFTR_AROI_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_AROI_STATUS_S *status);
INT32 _VFTR_AROI_detectRoi(VFTR_AROI_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                           VFTR_AROI_STATUS_S *status);

/**
 * @brief An inline function. If variable vftr_dump_en is true, 
 * then call dump function for debugging.
 * @see _VFTR_AROI_dump()
 * @see _VFTR_AROI_detectRoi()
 */
FORCE_INLINE INT32 VFTR_AROI_detectRoi(VFTR_AROI_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                                       VFTR_AROI_STATUS_S *status)
{
	INT32 _err = _VFTR_AROI_detectRoi(instance, obj_list, status);
	if (vftr_dump_en) {
		_VFTR_AROI_dump(instance, obj_list, status);
	}
	return _err;
}

INT32 VFTR_AROI_getStat(const VFTR_AROI_INSTANCE_S *instance, VFTR_AROI_STATUS_S *status);
INT32 VFTR_AROI_getTarget(const VFTR_AROI_INSTANCE_S *instance, MPI_RECT_POINT_S *target);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_AROI_H_ */
