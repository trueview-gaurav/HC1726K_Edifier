/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_ef.h
 * @brief Core feature-lib for electronic fence
 */

#ifndef VFTR_EF_H_
#define VFTR_EF_H_

#ifdef __cplusplus
extern "C" {
#endif /**< __cplusplus */

#include "mpi_base_types.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

#define VFTR_EF_MAX_FENCE_NUM (16) /**< Max fence number. */
#define VFTR_EF_VL_MIN_FENCE_ID (1) /**< Min fence id. */
#define VFTR_EF_VL_MAX_FENCE_ID (VFTR_EF_MAX_FENCE_NUM) /**< Max fence id. */
#define VFTR_EF_MAX_THR_V_OBJ (255)	/**< Maximal speed threshold of objects. */
#define VFTR_EF_MIN_THR_V_OBJ (0) /**< Minimal speed threshold of objects. */
#define VFTR_EF_DIR_NUM (2) /**< Directions: positive and negative. */
#define VFTR_EF_MIN_OBJ_LIFE_TH (0) /**< Minimal object life threshold. */
#define VFTR_EF_MAX_OBJ_LIFE_TH (MPI_IVA_OD_MAX_LIFE) /**< Maximal object life threshold. */

/* FIXME */
typedef UINT8 VFTR_EF_INSTANCE_SP_BF;

/**
 * @brief Enumeration of fence direction.
 */
typedef enum {
	VFTR_EF_DIR_NONE = 0x0, /**< no crossing */
	VFTR_EF_DIR_POS = 0x1, /**< only positive crossing */
	VFTR_EF_DIR_NEG = 0x2, /**< only negative crossing */
	VFTR_EF_DIR_BOTH = 0x3, /**< both direction of crossing */
} VFTR_EF_DIR_E;

/**
 * @struct VFTR_EF_VL_ATTR_S
 * @brief Structure of virtual line parameters.
 */
typedef struct {
	INT32 id; /**< returned fence id when successfully added, should not equal to zero */
	UINT16 obj_life_th; /**< specify the minimal life of object to be considered */
	MPI_RECT_POINT_S line; /**< describes the start/end x/y of the line */
	MPI_SIZE_S obj_size_min; /**< minimal width/height of object to be considered */
	MPI_SIZE_S obj_size_max; /**< maximal width/height of object to be considered */
	UINT32 obj_area; /**< object area when increasing the count (0=always increase the count by 1) */
	VFTR_EF_INSTANCE_SP_BF obj_v_th; /**< minimal speed of object to be considered */
	VFTR_EF_DIR_E mode; /**< detection mode of the fence */
} VFTR_EF_VL_ATTR_S;

/**
 * @struct VFTR_EF_VL_STAT_S
 * @brief Structure of virtual line status.
 */
typedef struct {
	VFTR_EF_DIR_E alarm; /**< alarm result of the fence */
	UINT16 cnt[VFTR_EF_DIR_NUM]; /**< count of positive and negative crossing */
} VFTR_EF_VL_STAT_S;

/**
 * @struct VFTR_EF_PARAM_S
 * @brief Struct for electronic fence parameter
 */
typedef struct {
	INT32 fence_num; /**< number of virtual line */
	VFTR_EF_VL_ATTR_S attr[VFTR_EF_MAX_FENCE_NUM]; /**< virtual line parameters */
} VFTR_EF_PARAM_S;

/**
 * @struct VFTR_EF_STATUS_S
 * @brief Struct for electronic fence status
 */
typedef struct {
	INT32 fence_num; /**< number of virtual line */
	VFTR_EF_VL_ATTR_S attr[VFTR_EF_MAX_FENCE_NUM]; /**< virtual line parameters */
	VFTR_EF_VL_STAT_S stat[VFTR_EF_MAX_FENCE_NUM]; /**< virtual line status */
} VFTR_EF_STATUS_S;

/**
 * @cond
 */

typedef struct vftr_ef_algo_status_s VFTR_EF_ALGO_STATUS_S;

/**
 * @endcond
 */

/**
 * @struct VFTR_EF_INSTANCE_S
 * @brief Struct for electronic fence instance.
 * @note VFTR_EF_INSTANCE_S contains the whole context of electronic fence,
 * all function prototype of this file should affect on VFTR_EF_INSTANCE_S
 */
typedef struct {
	VFTR_EF_PARAM_S tmp_param; /**< Electronic fence parameters */
	VFTR_EF_STATUS_S status; /**< Electronic fence result */
	VFTR_EF_ALGO_STATUS_S *algo_status; /**< Electronic fence internal status */
} VFTR_EF_INSTANCE_S;

/* Interface function prototype */
VFTR_EF_INSTANCE_S *VFTR_EF_newInstance();
INT32 VFTR_EF_deleteInstance(VFTR_EF_INSTANCE_S **instance);
INT32 VFTR_EF_setParam(VFTR_EF_INSTANCE_S *instance, const VFTR_EF_PARAM_S *param);
INT32 VFTR_EF_checkParam(const VFTR_EF_PARAM_S *param, const MPI_SIZE_S *res);
INT32 VFTR_EF_getParam(const VFTR_EF_INSTANCE_S *instance, VFTR_EF_PARAM_S *param);
INT32 _VFTR_EF_dump(VFTR_EF_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_EF_STATUS_S *status);
INT32 _VFTR_EF_detect(VFTR_EF_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_EF_STATUS_S *status);

FORCE_INLINE INT32 VFTR_EF_detect(VFTR_EF_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                                  VFTR_EF_STATUS_S *status)
{
	INT32 _err = _VFTR_EF_detect(instance, obj_list, status);
	if (vftr_dump_en) {
		_VFTR_EF_dump(instance, obj_list, status);
	}
	return _err;
}

INT32 VFTR_EF_getStat(const VFTR_EF_INSTANCE_S *instance, VFTR_EF_STATUS_S *status);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_EF_H_ */
