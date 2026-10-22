#ifndef AGTX_DIP_FCS_CONF_H_
#define AGTX_DIP_FCS_CONF_H_

#include "agtx_types.h"
#include "agtx_common.h"

struct json_object;

typedef struct {
	AGTX_INT32 auto_strength_list[AGTX_ISO_LUT_ENTRY_NUM];
	AGTX_INT32 manual_strength;
	AGTX_INT32 mode;
	AGTX_INT32 video_dev_idx;
} AGTX_DIP_FCS_CONF_S;

#endif /* AGTX_DIP_FCS_CONF_H_ */
