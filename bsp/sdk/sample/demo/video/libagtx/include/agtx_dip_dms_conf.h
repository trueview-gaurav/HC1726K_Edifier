#ifndef AGTX_DIP_DMS_CONF_H_
#define AGTX_DIP_DMS_CONF_H_

#include "agtx_types.h"
#include "agtx_common.h"

struct json_object;

typedef enum { AGTX_DMS_MODE_DMS_DEFAULT, AGTX_DMS_MODE_DMS_ISO } AGTX_DMS_MODE_E;

typedef struct {
	AGTX_INT32 auto_g_at_m_inter_ratio_list[AGTX_ISO_LUT_ENTRY_NUM];
	AGTX_INT32 auto_m_at_g_inter_ratio_list[AGTX_ISO_LUT_ENTRY_NUM];
	AGTX_INT32 auto_m_at_m_inter_ratio_list[AGTX_ISO_LUT_ENTRY_NUM];
	AGTX_INT32 manual_g_at_m_inter_ratio;
	AGTX_INT32 manual_m_at_g_inter_ratio;
	AGTX_INT32 manual_m_at_m_inter_ratio;
	AGTX_INT32 mode;
	AGTX_INT32 video_dev_idx;
} AGTX_DIP_DMS_CONF_S;

#endif /* AGTX_DIP_DMS_CONF_H_ */
