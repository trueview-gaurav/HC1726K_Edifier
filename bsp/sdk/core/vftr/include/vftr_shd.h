/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_shd.h
 * @brief Core feature-lib for shaking object detection (SHD)
 */

#ifndef VFTR_SHD_H_
#define VFTR_SHD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @cond
 */

#include "mpi_base_types.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

/**
 * @endcond
 */

#define VFTR_SHD_LONGTERM_NUM (10) /**< Support long term object number */
#define IVA_JIF_HZ (100) /**< IVA jiffer time (in Hz) */

#define VFTR_SHD_MIN_OBJ_LIFE_TH (0) /**< Minimal object life threshold. */
#define VFTR_SHD_MAX_OBJ_LIFE_TH (MPI_IVA_OD_MAX_LIFE) /**< Maximal object life threshold. */

#define VFTR_SHD_MAX_SEN_MIN_TH (1) /**< Minimum threshold for sensitivity */
#define VFTR_SHD_MAX_SEN_MAX_TH (100) /**< Maximum threshold for sensitivity */
#define VFTR_SHD_MAX_QUA_MIN_TH (1) /**< Minimum threshold for quality */
#define VFTR_SHD_MAX_QUA_MAX_TH (100) /**< Maximum threshold for quality */
#define VFTR_SHD_MAX_LONGTERM_ACTIVE_MIN_TH (1)

/**
 * @cond
 */

typedef struct vftr_shd_algo_status_s VFTR_SHD_ALGO_STATUS_S;

/**
 * @endcond
 */

/**
 * @brief Struct for shd long term attributes
 */
typedef struct {
	MPI_RECT_POINT_S rgn;
} VFTR_SHD_LT_OBJ_ATTR_S;

/**
 * @brief Struct for shd long term list
 */
typedef struct {
	int num; /**< Number of valid long term objects in items */
	VFTR_SHD_LT_OBJ_ATTR_S item[VFTR_SHD_LONGTERM_NUM]; /**< Long term object list */
} VFTR_SHD_LONGTERM_LIST_S;

/**
 * @brief Struct for object shaking detection parameter
 */
typedef struct {
	INT32 en; /**< Enable shaking object detection */
	UINT8 sensitivity; /**< Sensitivity of shaking object detection */
	UINT8 quality; /**< Quality of shaking object detection */
	UINT8 longterm_life_th; /**< Minimum threshold for registered list item to be activated */
	UINT16 obj_life_th; /**< Minimal object life threshold */
	UINT16 instance_duration; /**< instance object duration 0.1sec */
	UINT32 shaking_update_duration; /**< shaking object update duration 1sec */
	UINT32 longterm_dec_period; /**< registered list decrement period 1sec */
} VFTR_SHD_PARAM_S;

/**
 * @brief Struct for shaking object status.
 */
typedef struct {
	MPI_RECT_POINT_S shake_rect[MPI_IVA_MAX_OBJ_NUM]; /**< Shaking region */
	UINT8 shaking[MPI_IVA_MAX_OBJ_NUM]; /**< Detection result */
	INT32 obj_num; /**< The number of objects, should be consistent with input object number */
} VFTR_SHD_STATUS_S;

/**
 * @brief Struct for shaking object detection instance.
 */
typedef struct {
	VFTR_SHD_PARAM_S param; /**< Shaking object detector parameter */
	VFTR_SHD_STATUS_S status; /**< Shaking object detector result */
	VFTR_SHD_ALGO_STATUS_S *algo_status; /**< Shaking object detector internal status */
} VFTR_SHD_INSTANCE_S;

VFTR_SHD_INSTANCE_S *VFTR_SHD_newInstance(void);
INT32 VFTR_SHD_deleteInstance(VFTR_SHD_INSTANCE_S **instance);
INT32 VFTR_SHD_setParam(VFTR_SHD_INSTANCE_S *instance, const VFTR_SHD_PARAM_S *param);
INT32 VFTR_SHD_getParam(const VFTR_SHD_INSTANCE_S *instance, VFTR_SHD_PARAM_S *param);
INT32 _VFTR_SHD_dumpShake(VFTR_SHD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_SHD_STATUS_S *status);
INT32 _VFTR_SHD_detectShake(VFTR_SHD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                            VFTR_SHD_STATUS_S *status);
INT32 VFTR_SHD_getStat(const VFTR_SHD_INSTANCE_S *instance, VFTR_SHD_STATUS_S *status);
INT32 VFTR_SHD_setUserLongTermList(VFTR_SHD_INSTANCE_S *instance, const VFTR_SHD_LONGTERM_LIST_S *lt_list);
INT32 VFTR_SHD_getUserLongTermList(const VFTR_SHD_INSTANCE_S *instance, VFTR_SHD_LONGTERM_LIST_S *lt_list);

/**
 * @brief An inline function. If variable vftr_dump_en is true,
 * then call dump function for debugging.
 * @see _VFTR_SHD_dumpShake()
 * @see _VFTR_SHD_detectShake()
 */
FORCE_INLINE INT32 VFTR_SHD_detectShake(VFTR_SHD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                                        VFTR_SHD_STATUS_S *status)
{
	INT32 _err = _VFTR_SHD_detectShake(instance, obj_list, status);
	if (vftr_dump_en) {
		_VFTR_SHD_dumpShake(instance, obj_list, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_SHD_H_ */
