#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#include <stdio.h>
#include <string.h>

#include "json.h"

#include "agtx_dip_iso_conf.h"

void parse_dip_iso_conf(AGTX_DIP_ISO_CONF_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	int i;
	if (json_object_object_get_ex(cmd_obj, "auto_iso_table", &tmp_obj)) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			data->auto_iso_table[i] = json_object_get_int(json_object_array_get_idx(tmp_obj, i));
		}
	}
	if (json_object_object_get_ex(cmd_obj, "iso_type", &tmp_obj)) {
		data->iso_type = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "manual_iso", &tmp_obj)) {
		data->manual_iso = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "mode", &tmp_obj)) {
		data->mode = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "video_dev_idx", &tmp_obj)) {
		data->video_dev_idx = json_object_get_int(tmp_obj);
	}
}

void comp_dip_iso_conf(struct json_object *ret_obj, AGTX_DIP_ISO_CONF_S *data)
{
	struct json_object *tmp_obj  = NULL;
	struct json_object *tmp1_obj = NULL;

	int i;
	tmp_obj = json_object_new_array();
	if (tmp_obj) {
		for (i = 0; i < AGTX_ISO_LUT_ENTRY_NUM; i++) {
			tmp1_obj = json_object_new_int(data->auto_iso_table[i]);
			json_object_array_add(tmp_obj, tmp1_obj);
		}
		json_object_object_add(ret_obj, "auto_iso_table", tmp_obj);
	} else {
		printf("Cannot create array %s object\n", "auto_iso_table");
	}

	tmp_obj = json_object_new_int(data->iso_type);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "iso_type", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "iso_type");
	}

	tmp_obj = json_object_new_int(data->manual_iso);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "manual_iso", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "manual_iso");
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
