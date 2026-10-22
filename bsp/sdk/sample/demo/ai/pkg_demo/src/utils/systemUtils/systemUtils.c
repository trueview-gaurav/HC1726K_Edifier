#include "systemUtils.h"

// static void handleSigInt(int signo)
// {
// 	if (signo == SIGINT || signo == SIGTERM) {
// 		g_run_flag = false;
// 	}
// }

int parseConfig(const char *file_name, MPI_IVA_OD_PARAM_S *od_param, ML_PKG_PARAM_S *pkg_param)
{
	json_object *root = NULL;
	json_object *child = NULL;
	json_object *child1 = NULL;
	json_object *child2 = NULL;
	json_object *child3 = NULL;

	// Error is logged by json-c.
	root = (file_name[0] != '\0') ? json_object_from_file(file_name) : json_object_new_object();
	if (!root) {
		root = json_object_new_object();
	}

	// RoI is required parameter.
	if (!json_object_object_get_ex(root, "roi", &child)) {
		log_err("Not found required parameter 'roi' in configuration file.");
		exit(1);
	}

	int roi_cnt = json_object_array_length(child);
	pkg_param->region_num = roi_cnt;
	if (roi_cnt > ML_PKG_MAX_REG_NUM) {
		log_err("region setup over the maximum number of snapshot maximum %d. ML_PKG_MAX_REG_NUM is limited with the MPI_MAX_ISP_VAR_CFG_NUM\n",
		        MPI_MAX_ISP_VAR_CFG_NUM);
		exit(1);
	}
	for (int i = 0; i < roi_cnt; i++) {
		child1 = json_object_array_get_idx(child, i);
		if (!child1) {
			log_err("Not found roi %d in configuration file.", i);
			exit(1);
		}

		json_object_object_get_ex(child1, "start", &child2);
		child3 = json_object_array_get_idx(child2, 0);
		pkg_param->roi[i].sx = json_object_get_int(child3);
		child3 = json_object_array_get_idx(child2, 1);
		pkg_param->roi[i].sy = json_object_get_int(child3);

		json_object_object_get_ex(child1, "end", &child2);
		child3 = json_object_array_get_idx(child2, 0);
		pkg_param->roi[i].ex = json_object_get_int(child3);
		child3 = json_object_array_get_idx(child2, 1);
		pkg_param->roi[i].ey = json_object_get_int(child3);
	}

	if (json_object_object_get_ex(root, "snapshot_w", &child)) {
		pkg_param->pkg_snapshot_w = json_object_get_int(child);
	} else {
		json_object_object_add(root, "snapshot_w", json_object_new_int(pkg_param->pkg_snapshot_w));
	}

	if (json_object_object_get_ex(root, "snapshot_h", &child)) {
		pkg_param->pkg_snapshot_h = json_object_get_int(child);
	} else {
		json_object_object_add(root, "snapshot_h", json_object_new_int(pkg_param->pkg_snapshot_h));
	}

	if (json_object_object_get_ex(root, "idle2in_th", &child)) {
		pkg_param->idle2in_th = json_object_get_int(child);
	} else {
		json_object_object_add(root, "idle2in_th", json_object_new_int(pkg_param->idle2in_th));
	}

	if (json_object_object_get_ex(root, "in2idle_th", &child)) {
		pkg_param->in2idle_th = json_object_get_int(child);
	} else {
		json_object_object_add(root, "in2idle_th", json_object_new_int(pkg_param->in2idle_th));
	}

	if (json_object_object_get_ex(root, "duration", &child)) {
		pkg_param->duration = json_object_get_int(child);
	} else {
		json_object_object_add(root, "duration", json_object_new_int(pkg_param->duration));
	}

	if (json_object_object_get_ex(root, "background_merge_delay", &child)) {
		pkg_param->background_merge_delay = json_object_get_int(child);
	} else {
		json_object_object_add(root, "background_merge_delay",
		                       json_object_new_int(pkg_param->background_merge_delay));
	}

	if (json_object_object_get_ex(root, "od_qual", &child)) {
		od_param->od_qual = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_qual", json_object_new_int(od_param->od_qual));
	}

	if (json_object_object_get_ex(root, "od_track_refine", &child)) {
		od_param->od_track_refine = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_track_refine", json_object_new_int(od_param->od_track_refine));
	}

	if (json_object_object_get_ex(root, "od_size_th", &child)) {
		od_param->od_size_th = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_size_th", json_object_new_int(od_param->od_size_th));
	}

	if (json_object_object_get_ex(root, "od_sen", &child)) {
		od_param->od_sen = json_object_get_int(child);
	} else {
		json_object_object_add(root, "od_sen", json_object_new_int(od_param->od_sen));
	}

	if (json_object_object_get_ex(root, "en_stop_det", &child)) {
		od_param->en_stop_det = json_object_get_boolean(child);
	} else {
		json_object_object_add(root, "en_stop_det", json_object_new_boolean(od_param->en_stop_det));
	}

	json_object_put(root);

	return 0;
}

uint32_t timer_record_ms()
{
	static uint8_t is_init = 0;
	static struct timespec now;
	uint32_t delta_ms = -1;

	if (!is_init) {
		struct timespec prev = { 0 };
		prev.tv_sec = now.tv_sec;
		prev.tv_nsec = now.tv_nsec;
		clock_gettime(CLOCK_MONOTONIC, &now);
		delta_ms = (now.tv_sec - prev.tv_sec) * 1000 + (now.tv_nsec - prev.tv_nsec) / 1000000;
	} else {
		clock_gettime(CLOCK_MONOTONIC, &now);
		is_init = 1;
	}
	return delta_ms;
}
