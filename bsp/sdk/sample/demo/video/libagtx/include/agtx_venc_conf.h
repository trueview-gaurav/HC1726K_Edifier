#ifndef AGTX_VENC_CONF_H_
#define AGTX_VENC_CONF_H_

#include "agtx_types.h"
struct json_object;

typedef struct {
	AGTX_UINT32 max_bit_rate;
	AGTX_UINT32 quality_level_index;
	AGTX_UINT32 fluc_level;
	AGTX_UINT32 regression_speed;
	AGTX_UINT32 scene_smooth;
	AGTX_UINT32 i_continue_weight;
	AGTX_UINT32 max_qp;
	AGTX_INT32 i_qp_offset;
	AGTX_UINT32 motion_tolerance_level;
	AGTX_UINT32 motion_tolerance_qp;
} AGTX_VENC_VBR_CONF_S;

typedef struct {
	AGTX_UINT32 bit_rate;
	AGTX_UINT32 fluc_level;
	AGTX_UINT32 regression_speed;
	AGTX_UINT32 scene_smooth;
	AGTX_UINT32 i_continue_weight;
	AGTX_UINT32 max_qp;
	AGTX_UINT32 min_qp;
	AGTX_INT32 i_qp_offset;
	AGTX_UINT32 motion_tolerance_level;
	AGTX_UINT32 motion_tolerance_qp;
} AGTX_VENC_CBR_CONF_S;

typedef struct {
	AGTX_UINT32 bit_rate;
	AGTX_UINT32 fluc_level;
	AGTX_UINT32 regression_speed;
	AGTX_UINT32 scene_smooth;
	AGTX_UINT32 i_continue_weight;
	AGTX_UINT32 max_qp;
	AGTX_UINT32 min_qp;
	AGTX_UINT32 adjust_br_thres_pc;
	AGTX_UINT32 adjust_step_times;
	AGTX_UINT32 converge_frame;
	AGTX_INT32 i_qp_offset;
	AGTX_UINT32 motion_tolerance_level;
	AGTX_UINT32 motion_tolerance_qp;
} AGTX_VENC_SBR_CONF_S;

typedef struct {
	AGTX_UINT32 i_frame_qp;
	AGTX_UINT32 p_frame_qp;
} AGTX_VENC_CQP_CONF_S;

typedef struct {
	AGTX_PRFL_E profile;
	AGTX_RC_MODE_E rc_mode;
	AGTX_UINT32 gop;
	AGTX_INT32 frm_rate_o;
	AGTX_VENC_VBR_CONF_S vbr;
	AGTX_VENC_CBR_CONF_S cbr;
	AGTX_VENC_SBR_CONF_S sbr;
	AGTX_VENC_CQP_CONF_S cqp;
} AGTX_VENC_H26X_CONF_S;

typedef struct {
	AGTX_RC_MODE_E rc_mode;
	AGTX_UINT32 frm_rate_o;
	AGTX_UINT32 fluc_level;
	AGTX_UINT32 bit_rate;
	AGTX_UINT32 max_q_factor;
	AGTX_UINT32 min_q_factor;
	AGTX_UINT32 max_bit_rate;
	AGTX_UINT32 quality_level_index;
	AGTX_UINT32 q_factor;
	AGTX_UINT32 adjust_br_thres_pc;
	AGTX_UINT32 adjust_step_times;
	AGTX_UINT32 converge_frame;
	AGTX_UINT32 motion_tolerance_level;
	AGTX_UINT32 motion_tolerance_qfactor;
} AGTX_VENC_MJPEG_CONF_S;

typedef struct {
	AGTX_VENC_TYPE_E type;
	AGTX_VENC_H26X_CONF_S h264;
	AGTX_VENC_H26X_CONF_S h265;
	AGTX_VENC_MJPEG_CONF_S mjpeg;
} AGTX_VENC_CONF_S;

#endif /* AGTX_VENC_CONF_H_ */