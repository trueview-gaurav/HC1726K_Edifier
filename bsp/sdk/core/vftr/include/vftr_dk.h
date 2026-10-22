/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_dk.h
 * @brief Core feature-lib for door keeper
 */

#ifndef VFTR_DK_H_
#define VFTR_DK_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_index.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

#define IVA_JIF_HZ (100) /**< IVA jiffer time (in Hz) */
#define VFTR_DK_OVERLAP_FRACTION 8
#define VFTR_DK_OVERLAP_WEIGHT_MAX (1 << (VFTR_DK_OVERLAP_FRACTION))

/**
 * @brief Enumeration of door keeper detection status
 */
typedef enum {
	VFTR_DK_DET_UNKNOWN = 0, /**< Object init in the scence */
	VFTR_DK_DET_APPEAR = 1, /**< Object appear in the scence */
	VFTR_DK_DET_PASSBY = 2, /**< Object pass through the roi */
	VFTR_DK_DET_APPROACH = 3, /**< Object approach in the scence */
	VFTR_DK_DET_LOITER = 4, /**< Object loiter in the scence */
	VFTR_DK_DET_VISIT = 5, /**< Object visit in the roi */
	VFTR_DK_DET_NUM = 6, /** Number of enum VFTR_DK_DET_RESULT_E */
} VFTR_DK_DET_RESULT_E;

/**
 * @struct VFTR_DK_PARAM_S
 * @brief Struct for door keeper parameter
 */
typedef struct {
	UINT16 obj_life_th; /**< Life threshold of object */
	UINT16 loiter_period_th; /**< Period threshold for loitering status (unit: 1/IVA_JIF_HZ s) */
	UINT16 overlap_ratio_th; /**< Overlap threshold with roi. Range: [0, DK_OVERLAP_WEIGHT_MAX] */
	MPI_RECT_POINT_S roi_pts; /**< Rectangle of roi */
	UINT32 roi_size; /**< Area of roi */
} VFTR_DK_PARAM_S;

/**
 * @struct VFTR_DK_INSTANCE_STATUS_S
 * @brief Struct for door keeper status of each object.
 */
typedef struct {
	UINT16 obj_id; /**< ID of object. */
	UINT32 duration; /**< Duration staying in the scence */
	VFTR_DK_DET_RESULT_E result; /**< Result of door keeper detection */
} VFTR_DK_INSTANCE_STATUS_S;

/**
 * @struct VFTR_DK_STATUS_S
 * @brief Struct for door keeper status.
 * @note The result of VFTR_DK_STATUS_S is on a frame, which is 
 * determined by the result of each object in this frame.
 */
typedef struct {
	UINT16 obj_num; /**< Number of object */
	VFTR_DK_DET_RESULT_E result; /**< Result of door keeper detection */
	VFTR_DK_INSTANCE_STATUS_S stat[MPI_IVA_MAX_OBJ_NUM]; /**< Status list of the objects */
} VFTR_DK_STATUS_S;

/**
 * @cond
 */

/* Struct for door keeper internal status */
typedef struct vftr_dk_algo_status_s VFTR_DK_ALGO_STATUS_S;

/**
 * @endcond
 */

/**
 * @struct VFTR_DK_INSTANCE_S
 * @brief Struct for door keeper instance. 
 * @note VFTR_DK_INSTANCE_S contains the whole context of door keeper,  
 * all function prototype of this file should affect on VFTR_DK_INSTANCE_S
 */
typedef struct {
	VFTR_DK_PARAM_S param; /**< Door keeper parameters */
	VFTR_DK_STATUS_S status; /**< Door keeper result */
	VFTR_DK_ALGO_STATUS_S *algo_status; /**< Door keeper internal status */
} VFTR_DK_INSTANCE_S;

/* Interface function prototype */
VFTR_DK_INSTANCE_S *VFTR_DK_newInstance();
INT32 VFTR_DK_deleteInstance(VFTR_DK_INSTANCE_S **instance);
INT32 VFTR_DK_setParam(VFTR_DK_INSTANCE_S *instance, const MPI_SIZE_S *res, const VFTR_DK_PARAM_S *param);
INT32 VFTR_DK_checkParam(const VFTR_DK_PARAM_S *param);
INT32 VFTR_DK_getParam(const VFTR_DK_INSTANCE_S *instance, VFTR_DK_PARAM_S *param);
INT32 _VFTR_DK_dump(VFTR_DK_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_DK_STATUS_S *status);
INT32 _VFTR_DK_detect(VFTR_DK_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_DK_STATUS_S *status);
INT32 VFTR_DK_getStat(const VFTR_DK_INSTANCE_S *instance, VFTR_DK_STATUS_S *stat);

/**
 * @brief An inline function. If variable vftr_dump_en is true, 
 * then call dump function for debugging.
 * @see _VFTR_DK_dump()
 * @see _VFTR_DK_detectMotion()
 */
FORCE_INLINE INT32 VFTR_DK_detect(VFTR_DK_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                                  VFTR_DK_STATUS_S *status)
{
	INT32 _err = _VFTR_DK_detect(instance, obj_list, status);
	if (vftr_dump_en) {
		_VFTR_DK_dump(instance, obj_list, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_DK_H_ */
