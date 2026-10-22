/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */
/**
 * @file mpi_errno.h
 * @brief MPI error codes
 */

#ifndef MPI_ERRNO_H_
#define MPI_ERRNO_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <errno.h>

#include "mpi_base_types.h"

/**
 * @brief Enumeration of MPI module.
 */
typedef enum {
	MPI_MOD_PLAT, /**< Module video platform. */
	MPI_MOD_DEV, /**< Module video device. */
	MPI_MOD_ENC, /**< Module video encoder. */
	MPI_MOD_NUM,
} MPI_MOD_E;

/**
 * @brief Enumeration of error level.
 */
typedef enum {
	MPI_ERR_LEVEL_DEBUG = 0, /**< Debug. */
	MPI_ERR_LEVEL_INFO, /**< Information. */
	MPI_ERR_LEVEL_WARNING, /**< Warning. */
	MPI_ERR_LEVEL_ERROR, /**< Error. */
	MPI_ERR_LEVEL_FATAL, /**< Fatal error. */
	MPI_ERR_LEVEL_NUM,
} MPI_ERR_LEVEL_E;

/**
 * @brief Enumeration of error id.
 */
typedef enum {
	MPI_ERR_NONE = 0,
	MPI_ERR_INVALID_PATH, /**< Invalid path id. */
	MPI_ERR_INVALID_DEV, /**< Invalid input device id. */
	MPI_ERR_INVALID_CHN, /**< Invalid channel id. */
	MPI_ERR_INVALID_WIN, /**< Invalid window id. */
	MPI_ERR_INVALID_PARAM, /**< Invalid parameters. */
	MPI_ERR_NULL_POINTER, /**< NULL pointer. */
	MPI_ERR_NOT_CONFIG, /**< Enable before setting it. */
	MPI_ERR_NOT_EXIST, /**< Query before setting it. */
	MPI_ERR_CONFLICT, /**< Enable same resource more than once. */
	MPI_ERR_NOMEM, /**< No memory. */
	MPI_ERR_NOT_INIT, /**< Initialization failed. */
	MPI_ERR_BAD_ADDR, /**< Bad address. */
	MPI_ERR_BUSY, /**< Disable before stopping system. */
	MPI_ERR_NOT_PERM, /**< Not permit operation. */
	MPI_ERR_NUM,
} MPI_ERR_CODE_E;

/**
 * @brief Constant for indicating that some value is an error code.
 */
#define MPI_ERR_ID (0xE)

/**
 * @brief A macro that define error type consist of module, level and error id.
 */
#define MPI_DEF_ERR(module, level, errid)                                                                              \
	((INT32)(((MPI_ERR_ID) << 28) | ((MPI_MOD_##module) << 16) | ((MPI_ERR_LEVEL_##level) << 8) |                  \
	         (MPI_ERR_##errid)))

#define MPI_ERR_PLAT_INVALID_PARAM MPI_DEF_ERR(PLAT, ERROR, INVALID_PARAM) /**< Invalid parameters */
#define MPI_ERR_PLAT_NULL_POINTER MPI_DEF_ERR(PLAT, ERROR, NULL_POINTER) /**< NULL pointer */
#define MPI_ERR_PLAT_NOT_CONFIG MPI_DEF_ERR(PLAT, ERROR, NOT_CONFIG) /**< Enable before setting it. */
#define MPI_ERR_PLAT_NOT_EXIST MPI_DEF_ERR(PLAT, ERROR, NOT_EXIST) /**< Query before setting it. */
//#define MPI_ERR_PLAT_CONFLICT         MPI_DEF_ERR(PLAT, ERROR, CONFLICT)
//#define MPI_ERR_PLAT_NOMEM            MPI_DEF_ERR(PLAT, ERROR, NOMEM)
#define MPI_ERR_PLAT_NOT_INIT MPI_DEF_ERR(PLAT, ERROR, NOT_INIT) /**< Initialization failed. */
//#define MPI_ERR_PLAT_BAD_ADDR         MPI_DEF_ERR(PLAT, ERROR, BAD_ADDR)
//#define MPI_ERR_PLAT_BUSY             MPI_DEF_ERR(PLAT, ERROR, BUSY)
#define MPI_ERR_PLAT_NOT_PERM MPI_DEF_ERR(PLAT, ERROR, NOT_PERM) /**< Not permit operation. */

#define MPI_ERR_DEV_INVALID_PATH MPI_DEF_ERR(DEV, ERROR, INVALID_PATH) /**< Invalid input path index. */
#define MPI_ERR_DEV_INVALID_DEV MPI_DEF_ERR(DEV, ERROR, INVALID_DEV) /**< Invalid video device index. */
#define MPI_ERR_DEV_INVALID_CHN MPI_DEF_ERR(DEV, ERROR, INVALID_CHN) /**< Invalid video channel index. */
#define MPI_ERR_DEV_INVALID_WIN MPI_DEF_ERR(DEV, ERROR, INVALID_WIN) /**< Invalid video window index. */
#define MPI_ERR_DEV_INVALID_PARAM MPI_DEF_ERR(DEV, ERROR, INVALID_PARAM) /**< Invalid parameters. */
#define MPI_ERR_DEV_NULL_POINTER MPI_DEF_ERR(DEV, ERROR, NULL_POINTER) /**< NULL pointer. */
#define MPI_ERR_DEV_NOT_CONFIG MPI_DEF_ERR(DEV, ERROR, NOT_CONFIG) /**< Enable before setting it. */
#define MPI_ERR_DEV_NOT_EXIST MPI_DEF_ERR(DEV, ERROR, NOT_EXIST) /**< Query before creating it. */
#define MPI_ERR_DEV_CONFLICT MPI_DEF_ERR(DEV, ERROR, CONFLICT) /**< Enable same resource more than once. */
#define MPI_ERR_DEV_NOMEM MPI_DEF_ERR(DEV, ERROR, NOMEM) /**< No memory. */
#define MPI_ERR_DEV_NOT_INIT MPI_DEF_ERR(DEV, ERROR, NOT_INIT) /**< Initialization failed. */
#define MPI_ERR_DEV_BAD_ADDR MPI_DEF_ERR(DEV, ERROR, BAD_ADDR) /**< Bad address. */
#define MPI_ERR_DEV_BUSY MPI_DEF_ERR(DEV, ERROR, BUSY) /**< Disable before stopping system. */
#define MPI_ERR_DEV_NOT_PERM MPI_DEF_ERR(DEV, ERROR, NOT_PERM) /**< Not permit operations. */

//#define MPI_ERR_ENC_INVALID_PATH_ID   MPI_DEF_ERR(ENC, ERROR, INVALID_PATH_ID)
//#define MPI_ERR_ENC_INVALID_DEV_ID    MPI_DEF_ERR(ENC, ERROR, INVALID_DEV_ID)
#define MPI_ERR_ENC_INVALID_CHN MPI_DEF_ERR(ENC, ERROR, INVALID_CHN) /**< Invalid encoder channel index. */
#define MPI_ERR_ENC_INVALID_PARAM MPI_DEF_ERR(ENC, ERROR, INVALID_PARAM) /**< Invalid parameters. */
#define MPI_ERR_ENC_NULL_POINTER MPI_DEF_ERR(ENC, ERROR, NULL_POINTER) /**< NULL pointer. */
#define MPI_ERR_ENC_NOT_CONFIG MPI_DEF_ERR(ENC, ERROR, NOT_CONFIG) /**< Enable before setting it. */
#define MPI_ERR_ENC_NOT_EXIST MPI_DEF_ERR(ENC, ERROR, NOT_EXIST) /**< Query before creating it. */
#define MPI_ERR_ENC_CONFLICT MPI_DEF_ERR(ENC, ERROR, CONFLICT) /**< Enable same resource more than once. */
#define MPI_ERR_ENC_NOMEM MPI_DEF_ERR(ENC, ERROR, NOMEM) /**< No memory. */
#define MPI_ERR_ENC_NOT_INIT MPI_DEF_ERR(ENC, ERROR, NOT_INIT) /**< Initialization failed. */
#define MPI_ERR_ENC_BAD_ADDR MPI_DEF_ERR(ENC, ERROR, BAD_ADDR) /**< Bad address. */
#define MPI_ERR_ENC_BUSY MPI_DEF_ERR(ENC, ERROR, BUSY) /**< Disable before stopping system. */
#define MPI_ERR_ENC_NOT_PERM MPI_DEF_ERR(ENC, ERROR, NOT_PERM) /**< Not permit operations. */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MPI_ERRNO_H_ */
