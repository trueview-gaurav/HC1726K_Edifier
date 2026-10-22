/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_fld.h
 * @brief Core feature-lib for fall detection (FLD)
 */

#ifndef VFTR_FLD_H_
#define VFTR_FLD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_index.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

/**
 * @cond
 */
#define VFTR_FLD_DBG 0
/**
 * @endcond
 */

#define VFTR_FLD_FRACTION 8 /**< Fraction bit of FLD */
#define VFTR_FLD_WEIGHT_MAX (1 << (VFTR_FLD_FRACTION)) /**< Maximum weight of FLD. */

/**
 * @brief Enumeration of fall detection result.
 */
typedef enum {
	VFTR_FLD_UNKNOWN = 0, /**< Object init in the scence */
	VFTR_FLD_NORMAL = 1, /**< Object normal in the scence */
	VFTR_FLD_FALLING = 2, /**< Object falling in the scence */
	VFTR_FLD_DOWN = 3, /**< Object down in the scence */
	VFTR_FLD_FALLEN = 4, /**< Object fallen in the scence */
	VFTR_FLD_NUM = 5, /**< Number of enum FLD_RESULT_E */
} VFTR_FLD_RESULT_E;

/**
 * @struct VFTR_FLD_PARAM_S
 * @brief Structure for the parameters of FLD.
 * @details
 * @see VFTR_FLD_INSTANCE_S
 * @see VFTR_FLD_setParam()
 * @see VFTR_FLD_checkParam()
 * @see VFTR_FLD_getParam()
 * @property UINT16 VFTR_FLD_PARAM_S::obj_life_th
 * @arg Range [::VFTR_FLD_MIN_OBJ_LIFE_TH, ::VFTR_FLD_MAX_OBJ_LIFE_TH]
 * @property UINT16 VFTR_FLD_PARAM_S::obj_falling_mv_th
 * @arg Range [::VFTR_FLD_MIN_OBJ_FALLING_MV, ::VFTR_FLD_MAX_OBJ_FALLING_MV]
 * @property UINT16 VFTR_FLD_PARAM_S::obj_stop_mv_th
 * @arg Range [::VFTR_FLD_MIN_OBJ_STOP_MV, ::VFTR_FLD_MAX_OBJ_STOP_MV]
 * @property UINT16 VFTR_FLD_PARAM_S::obj_high_ratio_th
 * @arg Range [::VFTR_FLD_MIN_OBJ_HIGH_RATIO_TH, ::VFTR_FLD_MAX_OBJ_HIGH_RATIO_TH]
 * @property UINT16 VFTR_FLD_PARAM_S::falling_period_th
 * @arg Range [::VFTR_FLD_MIN_FALLING_PERIOD_TH, ::VFTR_FLD_MAX_FALLING_PERIOD_TH]
 * @property UINT16 VFTR_FLD_PARAM_S::down_period_th
 * @arg Range [::VFTR_FLD_MIN_DOWN_PERIOD_TH, ::VFTR_FLD_MAX_DOWN_PERIOD_TH]
 * @property UINT16 VFTR_FLD_PARAM_S::fallen_period_th
 * @arg Range [::VFTR_FLD_MIN_FALLEN_PERIOD_TH, ::VFTR_FLD_MAX_FALLEN_PERIOD_TH]
 * @property UINT16 VFTR_FLD_PARAM_S::demo_level
 * @arg simple: ::VFTR_FLD_MIN_DEMO_LEVEL
 * @arg detailed ::VFTR_FLD_MAX_DEMO_LEVEL
 */
typedef struct {
	UINT16 obj_life_th; /**< Life threshold of object. */
	UINT16 obj_falling_mv_th; /**< Falling mv threshold of object. */
	UINT16 obj_stop_mv_th; /**< Stop mv threshold of object. */
	UINT16 obj_high_ratio_th; /**< High ratio threshold with height history of object. */
	UINT16 falling_period_th; /**< Period threshold for falling status (unit: 1/100 s) */
	UINT16 down_period_th; /**< Period threshold for down status (unit: 1/100 s) */
	UINT16 fallen_period_th; /**< Period threshold for fallen status (unit: 1/100 s) */
	UINT16 demo_level; /**< Demo level of detail. */
} VFTR_FLD_PARAM_S;

/**
 * @struct VFTR_FLD_INSTANCE_STATUS_S
 * @brief Structure of FLD object status.
 * @details
 * @see VFTR_FLD_STATUS_S
 * @property INT32 VFTR_FLD_INSTANCE_STATUS_S::obj_id
 * @arg Range [0, INT_MAX)
 * @property VFTR_FLD_RESULT_E VFTR_FLD_INSTANCE_STATUS_S::result
 * @arg Range [::VFTR_FLD_UNKNOWN, ::VFTR_FLD_NUM)
 */
typedef struct {
	INT32 obj_id; /**< ID of object. */
	VFTR_FLD_RESULT_E result; /**< Result of object */
} VFTR_FLD_INSTANCE_STATUS_S;

/**
 * @struct VFTR_FLD_STATUS_S
 * @brief Struct for FLD status.
 * @details
 * @note The result of VFTR_FLD_STATUS_S is on a frame, which is determined by the result of each object in this frame.
 * @see VFTR_FLD_INSTANCE_S
 * @see VFTR_FLD_detect()
 * @see VFTR_FLD_getStat()
 * @property UINT16 VFTR_FLD_STATUS_S::obj_num
 * @arg Range [0, ::MPI_IVA_MAX_OBJ_NUM]
 * @property VFTR_FLD_RESULT_E VFTR_FLD_STATUS_S::result
 * @arg Range [::VFTR_FLD_UNKNOWN, ::VFTR_FLD_NUM)
 */
typedef struct {
	UINT16 obj_num; /**< Number of object */
	VFTR_FLD_RESULT_E result; /**< Result of fall detection */
	VFTR_FLD_INSTANCE_STATUS_S obj_stat_list[MPI_IVA_MAX_OBJ_NUM]; /**< Status list of objects */
} VFTR_FLD_STATUS_S;

/**
 * @cond
 */

/* Struct for door keeper internal status */
typedef struct vftr_fld_algo_status_s VFTR_FLD_ALGO_STATUS_S;

/**
 * @endcond
 */

/**
 * @struct VFTR_FLD_INSTANCE_S
 * @brief Struct for FLD instance status.
 * @note VFTR_FLD_INSTANCE_S contains the whole context of FLD, all function prototype of this file should affect on VFTR_FLD_INSTANCE_S
 * @see VFTR_FLD_newInstance()
 * @see VFTR_FLD_deleteInstance()
 * @see VFTR_FLD_setParam()
 * @see VFTR_FLD_getParam()
 * @see VFTR_FLD_detect()
 * @see VFTR_FLD_getStat()
 */
typedef struct {
	VFTR_FLD_PARAM_S param; /**< FLD parameters */
	VFTR_FLD_STATUS_S status; /**< FLD result */
	VFTR_FLD_ALGO_STATUS_S *algo_status; /**< FLD internal status */
} VFTR_FLD_INSTANCE_S;

/* Interface function prototype */
VFTR_FLD_INSTANCE_S *VFTR_FLD_newInstance();
INT32 VFTR_FLD_deleteInstance(VFTR_FLD_INSTANCE_S **instance);
INT32 VFTR_FLD_setParam(VFTR_FLD_INSTANCE_S *instance, const VFTR_FLD_PARAM_S *param);
INT32 VFTR_FLD_checkParam(const VFTR_FLD_PARAM_S *param);
INT32 VFTR_FLD_getParam(const VFTR_FLD_INSTANCE_S *instance, VFTR_FLD_PARAM_S *param);
INT32 _VFTR_FLD_dump(VFTR_FLD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_FLD_STATUS_S *status);
INT32 _VFTR_FLD_detect(VFTR_FLD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_FLD_STATUS_S *status);
INT32 VFTR_FLD_getStat(const VFTR_FLD_INSTANCE_S *instance, VFTR_FLD_STATUS_S *stat);

/**
 * @brief An inline function. If variable vftr_dump_en is true,
 * then call dump function for debugging.
 * @see _VFTR_FLD_dump()
 * @see _VFTR_FLD_detect()
 */
FORCE_INLINE INT32 VFTR_FLD_detect(VFTR_FLD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                                   VFTR_FLD_STATUS_S *status)
{
	INT32 _err = _VFTR_FLD_detect(instance, obj_list, status);
	if (vftr_dump_en) {
		_VFTR_FLD_dump(instance, obj_list, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_FLD_H_ */
