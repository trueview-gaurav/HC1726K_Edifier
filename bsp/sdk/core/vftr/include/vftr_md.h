/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_md.h
 * @brief Core feature-lib for motion detection
 */

#ifndef VFTR_MD_H_
#define VFTR_MD_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

#define VFTR_MD_MAX_THR_V_OBJ (255) /**< Maximal speed threshold of objects. */
#define VFTR_MD_MIN_THR_V_OBJ (0) /**< Minimal speed threshold of objects. */
#define VFTR_MD_MAX_THR_V_REG(W, H) ((W) * (H)*VFTR_MD_MAX_THR_V_OBJ)
#define VFTR_MD_MIN_THR_V_REG (0)
#define VFTR_MD_MAX_REG_NUM (64) /**< Maximal number of motion detection regions. */
#define VFTR_MD_MIN_REG_NUM (0) /**< Minimal number of motion detection regions. */
#define VFTR_MD_MAX_DET_SUBTRACT_NUM (3) /**< Maximal number of subtract regions in single instance. */
#define VFTR_MD_MIN_OBJ_LIFE_TH (0) /**< Minimal object life threshold. */
#define VFTR_MD_MAX_OBJ_LIFE_TH (MPI_IVA_OD_MAX_LIFE) /**< Maximal object life threshold. */
#define VFTR_MD_THR_V_REG_BIT_SHIFT 8 /**< Left shift of user set thr_v_reg */

typedef UINT16 VFTR_MD_OBJ_SP_BF; /**< Bit-field of object speed. */
typedef UINT64 VFTR_MD_REG_MOT_BF; /**< Bit-field of region motion. Max bit :VFTR_MD_INSTANCE_SP_BF * UINT32 * MPI_IVA_MAX_OBJ_NUM */

/**
 * @brief Enumeration of motion detection alarm mode.
 */
typedef enum {
	VFTR_MD_ALARM_FALSE = 0, /**< Alarm OFF. */
	VFTR_MD_ALARM_TRUE = 1, /**< Alarm ON. */
} VFTR_MD_ALARM_MODE_E;

/**
 * @brief Enumeration of motion quantization method.
 */
typedef enum {
	VFTR_MD_MOVING_AREA = 0, /**< Method of motion quantization is mainly based on size of moving objects. */
	VFTR_MD_MOVING_ENERGY = 1, /**< Method of motion quantization is mainly based on moving energy (size and velocity). */
} VFTR_MD_DET_MODE_E;

/**
 * @brief Enumeration of motion detection region attribute.
 */
typedef enum {
	VFTR_MD_DET_NORMAL = 0, /**< Normal region. */
	VFTR_MD_DET_SUBTRACT = 1, /**< The motion in this region should be neglected by other normal regions. */
} VFTR_MD_DET_METHOD_E;

/**
 * @struct VFTR_MD_REG_ATTR_S
 * @brief Struct for region attributes.
 */
typedef struct {
	INT16 id; /**< Region ID, reserved. */
	UINT16 obj_life_th; /**< Object life threshold.
	                     * Objects with life lower than threshold will be filtered-out.
	                     * It ranges [::VFTR_MD_MIN_OBJ_LIFE_TH, ::VFTR_MD_MAX_OBJ_LIFE_TH]
	                     */
	VFTR_MD_DET_METHOD_E det_method; /**< Detection method. */
	MPI_RECT_POINT_S pts; /**< Position of ROI in unit pixels. */
	VFTR_MD_OBJ_SP_BF thr_v_obj_min; /**< Minimal speed threshold of objects. (unit: pixel/frame)
	                                  * It ranges [::VFTR_MD_MIN_THR_V_OBJ, ::VFTR_MD_MAX_THR_V_OBJ], default value: 5.
	                                  */
	VFTR_MD_OBJ_SP_BF thr_v_obj_max; /**< Maximal speed threshold of objects. (unit: pixel/frame)
	                                  * It ranges [::VFTR_MD_MIN_THR_V_OBJ, ::VFTR_MD_MAX_THR_V_OBJ], default value: 255.
	                                  */
	VFTR_MD_DET_MODE_E md_mode; /**< Mode of motion detection. default value: VFTR_MD_MOVING_AREA */
	VFTR_MD_REG_MOT_BF thr_v_reg; /**< Right shifted minimal motion threshold.
	                               * (unit: pixel^2 for VFTR_MD_MOVING_AREA and pixel^3/frame for VFTR_MD_MOVING_ENERGY) of the region.
	                               * It ranges [0, ::VFTR_MD_MAX_THR_V_REG(pts)], default value: 500
	                               */
} VFTR_MD_REG_ATTR_S;

/**
 * @struct VFTR_MD_REG_STAT_S
 * @brief Struct for region status.
 */
typedef struct {
	VFTR_MD_ALARM_MODE_E alarm; /**< Alarm of region .*/
	VFTR_MD_REG_MOT_BF v_reg; /**< Motion quantity in the region.
	                           * Its unit is pixel^2 for ::VFTR_MD_MOVING_AREA and pixel^3/frame for ::VFTR_MD_MOVING_ENERGY)
	                           */
} VFTR_MD_REG_STAT_S;

/**
 * @struct VFTR_MD_PARAM_S
 * @brief Struct for motion detection parameter.
 */
typedef struct {
	INT32 region_num; /**< Number of motion detection regions. It ranges [1, 64] */
	VFTR_MD_REG_ATTR_S attr[VFTR_MD_MAX_REG_NUM]; /**< Attributes list of the motion detection region. */
} VFTR_MD_PARAM_S;

/**
 * @struct VFTR_MD_STATUS_S
 * @brief Struct for motion detection status.
 */
typedef struct {
	INT32 region_num; /**< Number of motion detection regions. It ranges [1, 64] */
	VFTR_MD_REG_ATTR_S attr[VFTR_MD_MAX_REG_NUM]; /**< Attributes list of the motion detection region. */
	VFTR_MD_REG_STAT_S stat[VFTR_MD_MAX_REG_NUM]; /**< Status list of the motion detection region. */
} VFTR_MD_STATUS_S;

/**
 * @struct VFTR_MD_INSTANCE_S
 * @brief Struct for motion detection object.
 * @note VFTR_MD_INSTANCE_S contains the whole context of motion detection,
 * all function prototype of this file should affect on VFTR_MD_INSTANCE_S
 */
typedef struct {
	VFTR_MD_PARAM_S tmp_param; /**< Motion detection parameter */
	VFTR_MD_STATUS_S status; /**< Motion detection result */
} VFTR_MD_INSTANCE_S;

/* Interface function prototype */
VFTR_MD_INSTANCE_S *VFTR_MD_newInstance();
INT32 VFTR_MD_deleteInstance(VFTR_MD_INSTANCE_S **instance);
INT32 VFTR_MD_setParam(VFTR_MD_INSTANCE_S *instance, const VFTR_MD_PARAM_S *param);
INT32 VFTR_MD_checkParam(const VFTR_MD_PARAM_S *param, const MPI_SIZE_S *res);
INT32 VFTR_MD_getParam(const VFTR_MD_INSTANCE_S *instance, VFTR_MD_PARAM_S *param);
INT32 _VFTR_MD_dump(VFTR_MD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_MD_STATUS_S *status);
INT32 _VFTR_MD_detectMotion(VFTR_MD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_MD_STATUS_S *status);

/**
 * @brief An inline function. If variable vftr_dump_en is true,
 * then call dump function for debugging.
 * @see _VFTR_MD_dump()
 * @see _VFTR_MD_detectMotion()
 */
FORCE_INLINE INT32 VFTR_MD_detectMotion(VFTR_MD_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                                        VFTR_MD_STATUS_S *status)
{
	INT32 _err = _VFTR_MD_detectMotion(instance, obj_list, status);
	if (vftr_dump_en) {
		_VFTR_MD_dump(instance, obj_list, status);
	}
	return _err;
}

INT32 VFTR_MD_getStat(const VFTR_MD_INSTANCE_S *instance, VFTR_MD_STATUS_S *stat);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_MD_H_ */
