/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_osc.h
 * @brief Core feature-lib for object shape classifier (OSC)
 */

#ifndef VFTR_OSC_H_
#define VFTR_OSC_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @cond
 */

#include "mpi_base_types.h"
#include "mpi_index.h"
#include "mpi_iva.h"
#include "vftr_dump.h"

typedef struct vftr_osc_algo_status VFTR_OSC_ALGO_STATUS_S;

/**
 * @endcond
 */

#define VFTR_OSC_AR_FRACTIONAL_BIT (16)
#define VFTR_OSC_MIN_ASPECT_RATIO (1) /**< Minimal OSC aspect ratio */
#define VFTR_OSC_MAX_ASPECT_RATIO (0xffffffff) /**< Maximal OSC aspect ratio */
#define VFTR_OSC_MIN_OBJ_LIFE_TH (0) /**< Minimal object life threshold */
#define VFTR_OSC_MAX_OBJ_LIFE_TH (MPI_IVA_OD_MAX_LIFE) /**< Maximal object life threshold */

/**
 * @brief Struct for object shape classifier parameter
 */
typedef struct {
	MPI_SIZE_S min_sz; /**< minimal OSC size */
	MPI_SIZE_S max_sz; /**< maximal OSC size */
	UINT32 min_aspect_ratio; /**< minimal OSC aspect ratio */
	UINT32 max_aspect_ratio; /**< maximal OSC aspect ratio */
	UINT16 obj_life_th; /**< object life threshold */
} VFTR_OSC_PARAM_S;

/**
 * @brief Struct for osc status.
 */
typedef struct {
	UINT8 category[MPI_IVA_MAX_OBJ_NUM]; /**< classification result */
} VFTR_OSC_STATUS_S;

/**
 * @brief Struct for OSC instance.
 */
typedef struct {
	VFTR_OSC_PARAM_S param; /**< Object shape classifier parameters */
	VFTR_OSC_STATUS_S status; /**< Object shape classification result */
} VFTR_OSC_INSTANCE_S;

VFTR_OSC_INSTANCE_S *VFTR_OSC_newInstance(void);
INT32 VFTR_OSC_deleteInstance(VFTR_OSC_INSTANCE_S **instance);
INT32 VFTR_OSC_setParam(VFTR_OSC_INSTANCE_S *instance, const MPI_SIZE_S *size, const VFTR_OSC_PARAM_S *param);
INT32 VFTR_OSC_getParam(const VFTR_OSC_INSTANCE_S *instance, VFTR_OSC_PARAM_S *param);
INT32 _VFTR_OSC_dump(VFTR_OSC_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_OSC_STATUS_S *status);
INT32 _VFTR_OSC_classify(VFTR_OSC_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list, VFTR_OSC_STATUS_S *status);
INT32 VFTR_OSC_getStat(const VFTR_OSC_INSTANCE_S *instance, VFTR_OSC_STATUS_S *status);

/**
 * @brief An inline function. If variable vftr_dump_en is true,
 * then call dump function for debugging.
 * @see _VFTR_OSC_dump()
 * @see _VFTR_OSC_classify()
 */
FORCE_INLINE INT32 VFTR_OSC_classify(VFTR_OSC_INSTANCE_S *instance, const MPI_IVA_OBJ_LIST_S *obj_list,
                                     VFTR_OSC_STATUS_S *status)
{
	INT32 _err = _VFTR_OSC_classify(instance, obj_list, status);
	if (vftr_dump_en) {
		_VFTR_OSC_dump(instance, obj_list, status);
	}
	return _err;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VFTR_OSC_H_ */
