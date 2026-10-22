/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr_dump.h
 * @brief Core feature-lib for dumping messages
 */
#ifndef VFTR_DUMP_H_
#define VFTR_DUMP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <time.h>
#include <pthread.h>

#include "mpi_base_types.h"
#include "vftr_dump_define.h"

extern int vftr_dump_en; /**< a global flag for enableing dump system */

#define FORCE_INLINE static inline __attribute__((always_inline))

/**
 * @brief Initialize dump system for debugging.
 * @param[in] args Generally use NULL as input.
 */
INT32 _VFTR_initDump(char *args);

/**
 * @brief Initialize dump system.
 * @param[in] args Generally use NULL as input.
 * @descriptions Ignore SIGPIPE to avoid program stop after pipe destoryed.
 */
#define VFTR_initDump(args)                                                     \
	do {                                                                    \
		if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {                      \
			fprintf(stderr, "failed to ignore signal SIGPIPE !\n"); \
		};                                                              \
		_VFTR_initDump(args);                                           \
	} while (0)

VOID VFTR_exitDump();
INT32 VFTR_dump(const VOID *buf, UINT32 len, UINT32 flag, TIMESPEC_S timestamp);
INT32 VFTR_dumpWithJiffies(const VOID *buf, UINT32 len, UINT32 flag, UINT32 jiffies);

extern pthread_mutex_t g_access_mutex;

FORCE_INLINE void _cleanup_push(void *args)
{
	pthread_mutex_unlock((pthread_mutex_t *)args);
}

#define VFTR_dumpStart()                                              \
	pthread_cleanup_push(_cleanup_push, (void *)&g_access_mutex); \
	pthread_mutex_lock(&g_access_mutex);

#define VFTR_dumpEnd() pthread_cleanup_pop(1);

#ifdef __cplusplus
}
#endif

#endif
