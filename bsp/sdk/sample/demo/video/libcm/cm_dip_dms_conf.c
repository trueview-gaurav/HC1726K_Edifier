#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <string.h>
#include "json.h"
#include "cm_dip_dms_conf.h"

const char *agtx_dms_mode_e_map[] = { "DMS_DEFAULT", "DMS_ISO" };

void parse_dip_dms_conf(AGTX_DIP_DMS_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	int i;
	if (json_object_object_get_ex(cmd_obj, "auto_g_at_m_inter_ratio_list", &tmp_obj)) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			data->auto_g_at_m_inter_ratio_list[i] =
			        json_object_get_int(json_object_array_get_idx(tmp_obj, i));
		}
	}
	if (json_object_object_get_ex(cmd_obj, "auto_m_at_g_inter_ratio_list", &tmp_obj)) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			data->auto_m_at_g_inter_ratio_list[i] =
			        json_object_get_int(json_object_array_get_idx(tmp_obj, i));
		}
	}
	if (json_object_object_get_ex(cmd_obj, "auto_m_at_m_inter_ratio_list", &tmp_obj)) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			data->auto_m_at_m_inter_ratio_list[i] =
			        json_object_get_int(json_object_array_get_idx(tmp_obj, i));
		}
	}
	if (json_object_object_get_ex(cmd_obj, "manual_g_at_m_inter_ratio", &tmp_obj)) {
		data->manual_g_at_m_inter_ratio = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "manual_m_at_g_inter_ratio", &tmp_obj)) {
		data->manual_m_at_g_inter_ratio = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "manual_m_at_m_inter_ratio", &tmp_obj)) {
		data->manual_m_at_m_inter_ratio = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "mode", &tmp_obj)) {
		data->mode = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "video_dev_idx", &tmp_obj)) {
		data->video_dev_idx = json_object_get_int(tmp_obj);
	}
}

void comp_dip_dms_conf(struct json_object *ret_obj, AGTX_DIP_DMS_CONF_S *data)
{
	struct json_object *tmp_obj = NULL;

	int i;
	tmp_obj = json_object_new_array();
	if (tmp_obj) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			json_object_array_add(tmp_obj, json_object_new_int(data->auto_g_at_m_inter_ratio_list[i]));
		}
		json_object_object_add(ret_obj, "auto_g_at_m_inter_ratio_list", tmp_obj);
	} else {
		printf("Cannot create array %s object\n", "auto_g_at_m_inter_ratio_list");
	}

	tmp_obj = json_object_new_array();
	if (tmp_obj) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			json_object_array_add(tmp_obj, json_object_new_int(data->auto_m_at_g_inter_ratio_list[i]));
		}
		json_object_object_add(ret_obj, "auto_m_at_g_inter_ratio_list", tmp_obj);
	} else {
		printf("Cannot create array %s object\n", "auto_m_at_g_inter_ratio_list");
	}

	tmp_obj = json_object_new_array();
	if (tmp_obj) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			json_object_array_add(tmp_obj, json_object_new_int(data->auto_m_at_m_inter_ratio_list[i]));
		}
		json_object_object_add(ret_obj, "auto_m_at_m_inter_ratio_list", tmp_obj);
	} else {
		printf("Cannot create array %s object\n", "auto_m_at_m_inter_ratio_list");
	}

	tmp_obj = json_object_new_int(data->manual_g_at_m_inter_ratio);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "manual_g_at_m_inter_ratio", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "manual_g_at_m_inter_ratio");
	}

	tmp_obj = json_object_new_int(data->manual_m_at_g_inter_ratio);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "manual_m_at_g_inter_ratio", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "manual_m_at_g_inter_ratio");
	}

	tmp_obj = json_object_new_int(data->manual_m_at_m_inter_ratio);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "manual_m_at_m_inter_ratio", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "manual_m_at_m_inter_ratio");
	}

	tmp_obj = json_object_new_int(data->mode);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "mode", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "mode");
	}

	tmp_obj = json_object_new_int(data->video_dev_idx);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "video_dev_idx", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "video_dev_idx");
	}
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
