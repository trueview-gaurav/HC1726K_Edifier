#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdio.h>
#include <string.h>
#include "json.h"
#include "cm_dip_exp_info.h"

void parse_dip_exposure_info(AGTX_DIP_EXPOSURE_INFO_S *data, struct json_object *cmd_obj)
{
	struct json_object *tmp_obj;
	if (json_object_object_get_ex(cmd_obj, "flicker_free_conf", &tmp_obj)) {
		data->flicker_free_conf = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "fps", &tmp_obj)) {
		data->fps = json_object_get_double(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "frame_delay", &tmp_obj)) {
		data->frame_delay = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "inttime", &tmp_obj)) {
		data->inttime = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "iso", &tmp_obj)) {
		data->iso = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "isp_gain", &tmp_obj)) {
		data->isp_gain = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "luma_avg", &tmp_obj)) {
		data->luma_avg = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "ratio", &tmp_obj)) {
		data->ratio = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "sensor_gain", &tmp_obj)) {
		data->sensor_gain = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "sys_gain", &tmp_obj)) {
		data->sys_gain = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "video_dev_idx", &tmp_obj)) {
		data->video_dev_idx = json_object_get_int(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_inttime0", &tmp_obj)) {
		data->hdr_inttime0 = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_isp_gain0", &tmp_obj)) {
		data->hdr_isp_gain0 = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_sensor_gain0", &tmp_obj)) {
		data->hdr_sensor_gain0 = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_sys_gain0", &tmp_obj)) {
		data->hdr_sys_gain0 = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_inttime1", &tmp_obj)) {
		data->hdr_inttime1 = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_isp_gain1", &tmp_obj)) {
		data->hdr_isp_gain1 = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_sensor_gain1", &tmp_obj)) {
		data->hdr_sensor_gain1 = json_object_get_int64(tmp_obj);
	}
	if (json_object_object_get_ex(cmd_obj, "hdr_sys_gain1", &tmp_obj)) {
		data->hdr_sys_gain1 = json_object_get_int64(tmp_obj);
	}
}

void comp_dip_exposure_info(struct json_object *ret_obj, AGTX_DIP_EXPOSURE_INFO_S *data)
{
	struct json_object *tmp_obj = NULL;

	tmp_obj = json_object_new_int(data->flicker_free_conf);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "flicker_free_conf", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "flicker_free_conf");
	}

	tmp_obj = json_object_new_double(data->fps);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "fps", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "fps");
	}

	tmp_obj = json_object_new_int(data->frame_delay);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "frame_delay", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "frame_delay");
	}

	tmp_obj = json_object_new_int(data->inttime);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "inttime", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "inttime");
	}

	tmp_obj = json_object_new_int(data->iso);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "iso", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "iso");
	}

	tmp_obj = json_object_new_int64(data->isp_gain);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "isp_gain", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "isp_gain");
	}

	tmp_obj = json_object_new_int(data->luma_avg);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "luma_avg", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "luma_avg");
	}

	tmp_obj = json_object_new_int(data->ratio);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "ratio", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "ratio");
	}

	tmp_obj = json_object_new_int64(data->sensor_gain);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "sensor_gain", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "sensor_gain");
	}

	tmp_obj = json_object_new_int64(data->sys_gain);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "sys_gain", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "sys_gain");
	}

	tmp_obj = json_object_new_int(data->video_dev_idx);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "video_dev_idx", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "video_dev_idx");
	}

	tmp_obj = json_object_new_int64(data->hdr_inttime0);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_inttime0", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_inttime0");
	}

	tmp_obj = json_object_new_int64(data->hdr_isp_gain0);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_isp_gain0", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_isp_gain0");
	}

	tmp_obj = json_object_new_int64(data->hdr_sensor_gain0);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_sensor_gain0", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_sensor_gain0");
	}

	tmp_obj = json_object_new_int64(data->hdr_sys_gain0);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_sys_gain0", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_sys_gain0");
	}

	tmp_obj = json_object_new_int64(data->hdr_inttime1);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_inttime1", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_inttime1");
	}

	tmp_obj = json_object_new_int64(data->hdr_isp_gain1);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_isp_gain1", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_isp_gain1");
	}

	tmp_obj = json_object_new_int64(data->hdr_sensor_gain1);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_sensor_gain1", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_sensor_gain1");
	}

	tmp_obj = json_object_new_int64(data->hdr_sys_gain1);
	if (tmp_obj) {
		json_object_object_add(ret_obj, "hdr_sys_gain1", tmp_obj);
	} else {
		printf("Cannot create %s object\n", "hdr_sys_gain1");
	}
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
