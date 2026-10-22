/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */
#ifndef DEBUG_H
#define DEBUG_H

#include "mpi_index.h"

/**
 * @cond code fragment skipped by Doxygen.
 */

#define DEBUG_STR_LEN 128
#define DEBUG_COLOR_MODE BGR
#define DEBUG_LIST_ITEM_MAX 60
#define DEBUG_GBUFFER_LEN 128

typedef enum {
	DEBUG_FEATURE_AROI = 0,
	DEBUG_FEATURE_OD,
	DEBUG_FEATURE_MD,
	DEBUG_FEATURE_EF,
	DEBUG_FEATURE_RMS,
	DEBUG_FEATURE_PD,
	DEBUG_FEATURE_TD,
	DEBUG_FEATURE_NUM,
} DEBUG_FEATURE_E;

typedef enum {
	DEBUG_AVMAIN_AROI = 0,
	DEBUG_AVMAIN_OSDPM,
	DEBUG_AVMAIN_NUM,
} DEBUG_AVMAIN_E;

typedef enum {
	DEBUG_DIP_AE = 0,
	DEBUG_DIP_EXPO,
	DEBUG_DIP_NUM,
} DEBUG_DIP_E;

typedef enum {
	DEBUG_MPP_IVA_OD = 0,
	DEBUG_MPP_IVA_RMS,
	DEBUG_MPP_IVA_NUM,
} DEBUG_MPP_IVA_E;

typedef enum {
	DEBUG_AVMAIN = 0,
	DEBUG_MPP_IVA,
	DEBUG_FEATURE,
	DEBUG_DIP,
	DEBUG_MODULES_NUM,
} DEBUG_MODULES_E;

typedef struct {
	UINT8 line_width;
	UINT8 line_alpha;
	UINT8 line_color[3]; /**< BGR color */
	MPI_RECT_POINT_S pts; /**< Required */
	UINT8 fill_alpha;
	UINT8 fill_color[3]; /**< BGR color */
} DEBUG_RECT_S;

typedef struct {
	UINT8 width;
	UINT8 alpha;
	UINT8 color[3]; /**< BGR color */
	MPI_RECT_POINT_S pts; /**< Required */
} DEBUG_LINE_S;

typedef struct {
	UINT8 size;
	UINT8 alpha;
	UINT8 color[3];
	MPI_POINT_S pt;
	char str[DEBUG_STR_LEN];
} DEBUG_TEXT_S;

typedef struct {
	char str[DEBUG_STR_LEN];
} DEBUG_STR_S;

typedef enum {
	DEBUG_NONE = -1,
	DEBUG_LINE,
	DEBUG_RECT,
	DEBUG_TEXT,
	DEBUG_STR,
	DEBUG_ITEM_NUM,
} DEBUG_ITEM_E;

typedef struct {
	DEBUG_ITEM_E type;
	union {
		DEBUG_RECT_S rect;
		DEBUG_TEXT_S text;
		DEBUG_LINE_S line;
		DEBUG_STR_S str;
	};
} DEBUG_ITEM_S;

typedef struct {
	INT32 num;
	DEBUG_ITEM_S item[DEBUG_LIST_ITEM_MAX];
} DEBUG_ITEM_LIST_S;

INT32 DEBUG_enable(void);
INT32 DEBUG_disable(void);
INT32 DEBUG_getInfoState(void);
INT32 DEBUG_flushBuffer(char *data);
INT32 DEBUG_getList(DEBUG_ITEM_LIST_S *list);
INT32 DEBUG_registerWriteFunc(DEBUG_ITEM_E type, void *writeFunc);
INT32 DEBUG_register(DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_unregister(DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_getComponentState(DEBUG_MODULES_E module, UINT32 comp_id, UINT32 *state);
INT32 DEBUG_getModuleState(DEBUG_MODULES_E module, UINT32 *state);
INT32 DEBUG_setLock(DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_rmLock(DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_rmLockAll(void);
INT32 DEBUG_waitLock(DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_getState(UINT32 *state);
INT32 DEBUG_putLine(DEBUG_LINE_S *line, DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_putRect(DEBUG_RECT_S *rect, DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_putText(DEBUG_TEXT_S *text, DEBUG_MODULES_E module, UINT32 comp_id);
INT32 DEBUG_putStr(DEBUG_STR_S *str, DEBUG_MODULES_E module, UINT32 comp_id);

/**
 * @endcond
 */

#endif /* DEBUG_H */
