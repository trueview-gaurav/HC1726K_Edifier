/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/**
 * @file vftr.h
 * @brief Core feature-lib for initialization
 */
#ifndef VFTR_H_
#define VFTR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <signal.h>

#include "vftr_ver.h"
#include "vftr_dump.h"

/**
 * @brief Check versions are matched and print version info
 * @param[in] ver_str The version string defined in vftr_ver.h
 * @see VFTR_VER
 */
int _VFTR_init(const char *ver_str);

/**
 * @brief Check the version and initialize dump system
 *
 * If this function is not called at the begining, then
 * dump functions are disabled for all VFTR modules.
 */
#define VFTR_init(args)                      \
	do {                                 \
		_VFTR_init(VFTR_VER);        \
		vftr_dump_en = true;         \
		if (vftr_dump_en) {          \
			VFTR_initDump(args); \
		}                            \
	} while (0)

/**
 * @brief Exit dump system
 */
#define VFTR_exit()              \
	do {                     \
		VFTR_exitDump(); \
	} while (0)

#ifdef __cplusplus
}
#endif

#endif
