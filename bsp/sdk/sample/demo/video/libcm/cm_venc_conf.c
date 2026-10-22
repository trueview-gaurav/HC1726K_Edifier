#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "cm_venc_conf.h"

#include <stdio.h>
#include <string.h>
#include "json.h"

#include "agtx_common.h"

const char *type_map[] = { "H264", "H265", "MJPEG" };
const char *profile_map[] = { "BASELINE", "MAIN", "HIGH" };
const char *rc_mode_map[] = { "VBR", "CBR", "SBR", "CQP" };

void parse_venc_vbr_conf(AGTX_VENC_VBR_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	if (json_object_object_get_ex(cmd_obj, "max_bit_rate", &tmp_obj)) {
		data->max_bit_rate = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "quality_level_index", &tmp_obj)) {
		data->quality_level_index = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "fluc_level", &tmp_obj)) {
		data->fluc_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "regression_speed", &tmp_obj)) {
		data->regression_speed = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "scene_smooth", &tmp_obj)) {
		data->scene_smooth = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "i_continue_weight", &tmp_obj)) {
		data->i_continue_weight = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "max_qp", &tmp_obj)) {
		data->max_qp = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "i_qp_offset", &tmp_obj)) {
		data->i_qp_offset = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_level", &tmp_obj)) {
		data->motion_tolerance_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_qp", &tmp_obj)) {
		data->motion_tolerance_qp = json_object_get_int(tmp_obj);
	}
}
void parse_venc_cbr_conf(AGTX_VENC_CBR_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	if (json_object_object_get_ex(cmd_obj, "bit_rate", &tmp_obj)) {
		data->bit_rate = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "fluc_level", &tmp_obj)) {
		data->fluc_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "regression_speed", &tmp_obj)) {
		data->regression_speed = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "scene_smooth", &tmp_obj)) {
		data->scene_smooth = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "i_continue_weight", &tmp_obj)) {
		data->i_continue_weight = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "max_qp", &tmp_obj)) {
		data->max_qp = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "min_qp", &tmp_obj)) {
		data->min_qp = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "i_qp_offset", &tmp_obj)) {
		data->i_qp_offset = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_level", &tmp_obj)) {
		data->motion_tolerance_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_qp", &tmp_obj)) {
		data->motion_tolerance_qp = json_object_get_int(tmp_obj);
	}
}

void parse_venc_sbr_conf(AGTX_VENC_SBR_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	if (json_object_object_get_ex(cmd_obj, "bit_rate", &tmp_obj)) {
		data->bit_rate = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "fluc_level", &tmp_obj)) {
		data->fluc_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "regression_speed", &tmp_obj)) {
		data->regression_speed = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "scene_smooth", &tmp_obj)) {
		data->scene_smooth = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "i_continue_weight", &tmp_obj)) {
		data->i_continue_weight = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "max_qp", &tmp_obj)) {
		data->max_qp = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "min_qp", &tmp_obj)) {
		data->min_qp = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "adjust_br_thres_pc", &tmp_obj)) {
		data->adjust_br_thres_pc = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "adjust_step_times", &tmp_obj)) {
		data->adjust_step_times = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "converge_frame", &tmp_obj)) {
		data->converge_frame = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "i_qp_offset", &tmp_obj)) {
		data->i_qp_offset = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_level", &tmp_obj)) {
		data->motion_tolerance_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_qp", &tmp_obj)) {
		data->motion_tolerance_qp = json_object_get_int(tmp_obj);
	}
}
void parse_venc_cqp_conf(AGTX_VENC_CQP_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	if (json_object_object_get_ex(cmd_obj, "i_frame_qp", &tmp_obj)) {
		data->i_frame_qp = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "p_frame_qp", &tmp_obj)) {
		data->p_frame_qp = json_object_get_int(tmp_obj);
	}
}
void parse_venc_h26x_conf(AGTX_VENC_CONF_S *venc, struct json_object *all_obj)
{
	struct json_object *cmd_obj;
	if (json_object_object_get_ex(all_obj, "H264_H265", &cmd_obj)) {
		struct json_object *tmp_obj;
		int i;
		const char *str;
		AGTX_VENC_H26X_CONF_S *data;
		if (venc->type == AGTX_VENC_TYPE_H264) {
			data = &(venc->h264);
		} else {
			data = &(venc->h265);
		}
		if (json_object_object_get_ex(cmd_obj, "profile", &tmp_obj)) {
			str = json_object_get_string(tmp_obj);
			for (i = 0; (unsigned int)i < sizeof(profile_map) / sizeof(char *); i++) {
				if (strcmp(profile_map[i], str) == 0) {
					data->profile = (AGTX_PRFL_E)i;
					break;
				}
			}
		}
		if (json_object_object_get_ex(cmd_obj, "gop", &tmp_obj)) {
			data->gop = json_object_get_int(tmp_obj);
		}
		if (json_object_object_get_ex(cmd_obj, "frm_rate_o", &tmp_obj)) {
			data->frm_rate_o = json_object_get_int(tmp_obj);
		}
		if (json_object_object_get_ex(cmd_obj, "rc_mode", &tmp_obj)) {
			str = json_object_get_string(tmp_obj);
			if (strcmp(str, "VBR") == 0) {
				data->rc_mode = AGTX_RC_MODE_VBR;
				if (json_object_object_get_ex(all_obj, "VBR", &tmp_obj)) {
					parse_venc_vbr_conf(&(data->vbr), tmp_obj);
				}
			} else if (strcmp(str, "CBR") == 0) {
				data->rc_mode = AGTX_RC_MODE_CBR;
				if (json_object_object_get_ex(all_obj, "CBR", &tmp_obj)) {
					parse_venc_cbr_conf(&(data->cbr), tmp_obj);
				}
			} else if (strcmp(str, "SBR") == 0) {
				data->rc_mode = AGTX_RC_MODE_SBR;
				if (json_object_object_get_ex(all_obj, "SBR", &tmp_obj)) {
					parse_venc_sbr_conf(&(data->sbr), tmp_obj);
				}
			} else if (strcmp(str, "CQP") == 0) {
				data->rc_mode = AGTX_RC_MODE_CQP;
				if (json_object_object_get_ex(all_obj, "CQP", &tmp_obj)) {
					parse_venc_cqp_conf(&(data->cqp), tmp_obj);
				}
			}
		}
	}
}

void parse_venc_mjpeg_conf(AGTX_VENC_MJPEG_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	if (json_object_object_get_ex(cmd_obj, "rc_mode", &tmp_obj)) {
		const char *str = json_object_get_string(tmp_obj);
		if (strcmp(str, "VBR") == 0) {
			data->rc_mode = AGTX_RC_MODE_VBR;
		} else if (strcmp(str, "CBR") == 0) {
			data->rc_mode = AGTX_RC_MODE_CBR;
		} else if (strcmp(str, "SBR") == 0) {
			data->rc_mode = AGTX_RC_MODE_SBR;
		} else if (strcmp(str, "CQP") == 0) {
			data->rc_mode = AGTX_RC_MODE_CQP;
		}
	}
	if (json_object_object_get_ex(cmd_obj, "frm_rate_o", &tmp_obj)) {
		data->frm_rate_o = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "fluc_level", &tmp_obj)) {
		data->fluc_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "bit_rate", &tmp_obj)) {
		data->bit_rate = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "max_q_factor", &tmp_obj)) {
		data->max_q_factor = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "min_q_factor", &tmp_obj)) {
		data->min_q_factor = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "max_bit_rate", &tmp_obj)) {
		data->max_bit_rate = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "quality_level_index", &tmp_obj)) {
		data->quality_level_index = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "q_factor", &tmp_obj)) {
		data->q_factor = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "adjust_br_thres_pc", &tmp_obj)) {
		data->adjust_br_thres_pc = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "adjust_step_times", &tmp_obj)) {
		data->adjust_step_times = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "converge_frame", &tmp_obj)) {
		data->converge_frame = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_level", &tmp_obj)) {
		data->motion_tolerance_level = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "motion_tolerance_qfactor", &tmp_obj)) {
		data->motion_tolerance_qfactor = json_object_get_int(tmp_obj);
	}
}
void parse_venc_conf(AGTX_VENC_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	if (json_object_object_get_ex(cmd_obj, "codec", &tmp_obj)) {
		const char *str = json_object_get_string(tmp_obj);
		if (strcmp(str, "H264") == 0) {
			data->type = AGTX_VENC_TYPE_H264;
			parse_venc_h26x_conf(data, cmd_obj);
		} else if (strcmp(str, "H265") == 0) {
			data->type = AGTX_VENC_TYPE_H265;
			parse_venc_h26x_conf(data, cmd_obj);
		} else if (strcmp(str, "MJPEG") == 0) {
			data->type = AGTX_VENC_TYPE_MJPEG;
			if (json_object_object_get_ex(cmd_obj, "MJPEG", &tmp_obj)) {
				parse_venc_mjpeg_conf(&(data->mjpeg), tmp_obj);
			}
		}
	}
}

void comp_venc_h26x_conf(struct json_object *ret_obj, AGTX_VENC_H26X_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;
	tmp_obj = json_object_new_string(profile_map[data->profile]);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "profile", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "profile");
	}
	tmp_obj = json_object_new_string(rc_mode_map[data->rc_mode]);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "rc_mode", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "rc_mode");
	}

	tmp_obj = json_object_new_int(data->gop);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "gop", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "gop");
	}

	tmp_obj = json_object_new_int(data->frm_rate_o);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "frm_rate_o", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "frm_rate_o");
	}
}
void comp_venc_vbr_conf(struct json_object *ret_obj, AGTX_VENC_VBR_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;
	tmp_obj = json_object_new_int(data->max_bit_rate);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "max_bit_rate", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "max_bit_rate");
	}
	tmp_obj = json_object_new_int(data->quality_level_index);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "quality_level_index", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "quality_level_index");
	}
	tmp_obj = json_object_new_int(data->fluc_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "fluc_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "fluc_level");
	}
	tmp_obj = json_object_new_int(data->regression_speed);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "regression_speed", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "regression_speed");
	}
	tmp_obj = json_object_new_int(data->scene_smooth);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "scene_smooth", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "scene_smooth");
	}
	tmp_obj = json_object_new_int(data->i_continue_weight);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "i_continue_weight", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "i_continue_weight");
	}
	tmp_obj = json_object_new_int(data->max_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "max_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "max_qp");
	}
	tmp_obj = json_object_new_int(data->i_qp_offset);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "i_qp_offset", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "i_qp_offset");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_level");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_qp");
	}
}
void comp_venc_cbr_conf(struct json_object *ret_obj, AGTX_VENC_CBR_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;
	tmp_obj = json_object_new_int(data->bit_rate);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "bit_rate", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "bit_rate");
	}
	tmp_obj = json_object_new_int(data->fluc_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "fluc_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "fluc_level");
	}
	tmp_obj = json_object_new_int(data->regression_speed);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "regression_speed", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "regression_speed");
	}
	tmp_obj = json_object_new_int(data->scene_smooth);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "scene_smooth", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "scene_smooth");
	}
	tmp_obj = json_object_new_int(data->i_continue_weight);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "i_continue_weight", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "i_continue_weight");
	}
	tmp_obj = json_object_new_int(data->max_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "max_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "max_qp");
	}
	tmp_obj = json_object_new_int(data->min_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "min_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "min_qp");
	}
	tmp_obj = json_object_new_int(data->i_qp_offset);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "i_qp_offset", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "i_qp_offset");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_level");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_qp");
	}
}
void comp_venc_sbr_conf(struct json_object *ret_obj, AGTX_VENC_SBR_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;
	tmp_obj = json_object_new_int(data->bit_rate);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "bit_rate", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "bit_rate");
	}
	tmp_obj = json_object_new_int(data->fluc_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "fluc_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "fluc_level");
	}
	tmp_obj = json_object_new_int(data->regression_speed);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "regression_speed", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "regression_speed");
	}
	tmp_obj = json_object_new_int(data->scene_smooth);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "scene_smooth", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "scene_smooth");
	}
	tmp_obj = json_object_new_int(data->i_continue_weight);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "i_continue_weight", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "i_continue_weight");
	}
	tmp_obj = json_object_new_int(data->max_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "max_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "max_qp");
	}
	tmp_obj = json_object_new_int(data->min_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "min_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "min_qp");
	}
	tmp_obj = json_object_new_int(data->adjust_br_thres_pc);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "adjust_br_thres_pc", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "adjust_br_thres_pc");
	}
	tmp_obj = json_object_new_int(data->adjust_step_times);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "adjust_step_times", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "adjust_step_times");
	}
	tmp_obj = json_object_new_int(data->converge_frame);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "converge_frame", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "converge_frame");
	}
	tmp_obj = json_object_new_int(data->i_qp_offset);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "i_qp_offset", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "i_qp_offset");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_level");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_qp");
	}
}
void comp_venc_cqp_conf(struct json_object *ret_obj, AGTX_VENC_CQP_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;
	tmp_obj = json_object_new_int(data->i_frame_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "i_frame_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "i_frame_qp");
	}
	tmp_obj = json_object_new_int(data->p_frame_qp);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "p_frame_qp", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "p_frame_qp");
	}
}
void comp_venc_mjpeg_conf(struct json_object *ret_obj, AGTX_VENC_MJPEG_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;
	tmp_obj = json_object_new_string(rc_mode_map[data->rc_mode]);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "rc_mode", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "mode");
	}
	tmp_obj = json_object_new_int(data->frm_rate_o);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "frm_rate_o", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "frm_rate_o");
	}
	tmp_obj = json_object_new_int(data->fluc_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "fluc_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "fluc_level");
	}
	tmp_obj = json_object_new_int(data->bit_rate);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "bit_rate", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "bit_rate");
	}
	tmp_obj = json_object_new_int(data->max_q_factor);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "max_q_factor", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "max_q_factor");
	}
	tmp_obj = json_object_new_int(data->min_q_factor);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "min_q_factor", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "min_q_factor");
	}
	tmp_obj = json_object_new_int(data->max_bit_rate);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "max_bit_rate", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "max_bit_rate");
	}
	tmp_obj = json_object_new_int(data->quality_level_index);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "quality_level_index", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "quality_level_index");
	}
	tmp_obj = json_object_new_int(data->q_factor);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "q_factor", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "q_factor");
	}
	tmp_obj = json_object_new_int(data->adjust_br_thres_pc);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "adjust_br_thres_pc", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "adjust_br_thres_pc");
	}
	tmp_obj = json_object_new_int(data->adjust_step_times);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "adjust_step_times", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "adjust_step_times");
	}
	tmp_obj = json_object_new_int(data->converge_frame);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "converge_frame", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "converge_frame");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_level);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_level", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_level");
	}
	tmp_obj = json_object_new_int(data->motion_tolerance_qfactor);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "motion_tolerance_qfactor", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "motion_tolerance_qfactor");
	}
}
void comp_venc_conf(struct json_object *ret_obj, AGTX_VENC_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;

	tmp_obj = json_object_new_string(type_map[data->type]);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "codec", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "type");
	}

	tmp_obj = json_object_new_object();
	if (data->type == AGTX_VENC_TYPE_H264) {
		comp_venc_h26x_conf(tmp_obj, &(data->h264));
		json_object_object_add(ret_obj, "H264_H265", tmp_obj);
		tmp_obj = json_object_new_object();
		if (data->h264.rc_mode == AGTX_RC_MODE_VBR) {
			comp_venc_vbr_conf(tmp_obj, &(data->h264.vbr));
			json_object_object_add(ret_obj, "VBR", tmp_obj);
		} else if (data->h264.rc_mode == AGTX_RC_MODE_CBR) {
			comp_venc_cbr_conf(tmp_obj, &(data->h264.cbr));
			json_object_object_add(ret_obj, "CBR", tmp_obj);
		} else if (data->h264.rc_mode == AGTX_RC_MODE_SBR) {
			comp_venc_sbr_conf(tmp_obj, &(data->h264.sbr));
			json_object_object_add(ret_obj, "SBR", tmp_obj);
		} else if (data->h264.rc_mode == AGTX_RC_MODE_CQP) {
			comp_venc_cqp_conf(tmp_obj, &(data->h264.cqp));
			json_object_object_add(ret_obj, "CQP", tmp_obj);
		}
	}

	else if (data->type == AGTX_VENC_TYPE_H265) {
		comp_venc_h26x_conf(tmp_obj, &(data->h265));
		json_object_object_add(ret_obj, "H264_H265", tmp_obj);
		tmp_obj = json_object_new_object();
		if (data->h265.rc_mode == AGTX_RC_MODE_VBR) {
			comp_venc_vbr_conf(tmp_obj, &(data->h265.vbr));
			json_object_object_add(ret_obj, "VBR", tmp_obj);
		} else if (data->h265.rc_mode == AGTX_RC_MODE_CBR) {
			comp_venc_cbr_conf(tmp_obj, &(data->h265.cbr));
			json_object_object_add(ret_obj, "CBR", tmp_obj);
		} else if (data->h265.rc_mode == AGTX_RC_MODE_SBR) {
			comp_venc_sbr_conf(tmp_obj, &(data->h265.sbr));
			json_object_object_add(ret_obj, "SBR", tmp_obj);
		} else if (data->h265.rc_mode == AGTX_RC_MODE_CQP) {
			comp_venc_cqp_conf(tmp_obj, &(data->h265.cqp));
			json_object_object_add(ret_obj, "CQP", tmp_obj);
		}
	} else if (data->type == AGTX_VENC_TYPE_MJPEG) {
		comp_venc_mjpeg_conf(tmp_obj, &(data->mjpeg));
		json_object_object_add(ret_obj, "MJPEG", tmp_obj);
	}
}
#ifdef __cplusplus
}
#endif /* __cplusplus */
