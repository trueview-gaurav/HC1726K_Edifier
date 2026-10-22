#ifndef AGTX_DIP_EXPOSURE_INFO_H_
#define AGTX_DIP_EXPOSURE_INFO_H_

#include "agtx_types.h"
struct json_object;

typedef struct {
	AGTX_INT32 flicker_free_conf;
	AGTX_FLOAT fps;
	AGTX_INT32 frame_delay;
	AGTX_INT32 inttime;
	AGTX_INT32 iso;
	AGTX_UINT32 isp_gain;
	AGTX_INT32 luma_avg;
	AGTX_INT32 ratio;
	AGTX_UINT32 sensor_gain;
	AGTX_UINT32 sys_gain;
	AGTX_INT32 video_dev_idx;
	AGTX_UINT32 hdr_inttime0;
	AGTX_UINT32 hdr_isp_gain0;
	AGTX_UINT32 hdr_sensor_gain0;
	AGTX_UINT32 hdr_sys_gain0;
	AGTX_UINT32 hdr_inttime1;
	AGTX_UINT32 hdr_isp_gain1;
	AGTX_UINT32 hdr_sensor_gain1;
	AGTX_UINT32 hdr_sys_gain1;
} AGTX_DIP_EXPOSURE_INFO_S;

#endif /* AGTX_DIP_EXPOSURE_INFO_H_ */
