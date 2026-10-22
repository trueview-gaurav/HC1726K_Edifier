/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file mpi_sys.h
 * @brief MPI for MPP system
 */

#ifndef MPI_SYS_H_
#define MPI_SYS_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "mpi_base_types.h"
#include "mpi_ver.h"

#define MPI_MAX_POOL_NAME_LEN 16 /**< Maximum string length for pool name. */
#define MPI_MAX_PUB_POOL 16 /**< Maximum number of public pool. */

/**
 * @brief Struct for pool configuration.
 */
typedef struct mpi_vb_pool_conf {
	UINT32 blk_size; /**< Block size in this pool. */
	UINT32 blk_cnt; /**< How many blocks in this pool. */
	UINT8 name[MPI_MAX_POOL_NAME_LEN]; /**< Pool name. */
} MPI_VB_POOL_CONF_S;

/**
 * @brief Struct for video buffer configuration.
 */
typedef struct mpi_vb_conf {
	UINT32 max_pool_cnt; /**< Max pool count including public and private pools. */
	MPI_VB_POOL_CONF_S pub_pool[MPI_MAX_PUB_POOL]; /**< Public pool configuration. */
} MPI_VB_CONF_S;

/* Interface function prototype */
INT32 MPI_VB_setConf(const MPI_VB_CONF_S *p_vb_conf);
INT32 MPI_VB_getConf(MPI_VB_CONF_S *p_vb_conf);
INT32 MPI_VB_init(VOID);
INT32 MPI_VB_exit(VOID);
INT32 _MPI_SYS_init(const char *p_ver_str);
#define MPI_SYS_init() _MPI_SYS_init(MPI_VER)
INT32 _MPI_SYS_exit(VOID);
#define MPI_SYS_exit() _MPI_SYS_exit()

/**
 * @page FAQ Frequently Asked Questions
 * @section mpp_info_retrieval How to Properly Retrieve Information from MPP
 *
 * To minimize CPU usage, the application layer should invoke MPI only when necessary.
 * Avoid redundant MPI calls by caching retrieved information locally.
 *
 * For instance, information retrieved from MPI_ENC_getVencAttr can be stored in a local variable and reused when needed.
 *
 * MPI_ENC_getVencAttr should only be reinvoked to obtain updated information upon notification that the encoder configuration has changed.
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !MPI_SYS_H_ */
