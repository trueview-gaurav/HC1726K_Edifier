#ifndef AGTX_WEBCAM_CAP_H_
#define AGTX_WEBCAM_CAP_H_
#include "agtx_common.h"
#include "agtx_webcam.h"

static unsigned int interval[] = {
	800000,
};

static struct agtx_webcam_cap_frame frames[] = {
	{
	        .wWidth = 2592,
	        .wHeight = 1944,
	        .bFrameIntervalType = sizeof(interval) / sizeof(unsigned int *),
	        .intervals = interval,
	},
};

static struct agtx_webcam_cap_format formats[] = {
	{
	        .codec = AGTX_VENC_TYPE_H264,
	        .dwMinBitRate = 64,
	        .dwMaxBitRate = 4096,
	        .bNumFrameDescriptors = sizeof(frames) / sizeof(struct agtx_webcam_cap_frame),
	        .frames = frames,
	},
	{
	        .codec = AGTX_VENC_TYPE_MJPEG,
	        .dwMinBitRate = 64,
	        .dwMaxBitRate = 20480,
	        .bNumFrameDescriptors = sizeof(frames) / sizeof(struct agtx_webcam_cap_frame),
	        .frames = frames,
	},
};

static struct agtx_webcam_cap g_webcam_cap = {
	.bNumFormats = sizeof(formats) / sizeof(struct agtx_webcam_cap_format),
	.formats = formats,
};

#endif /* AGTX_WEBCAM_CAP_H_ */
