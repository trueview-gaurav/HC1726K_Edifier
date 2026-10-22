#ifdef __cplusplus
extern "C" {
#endif /**< __cplusplus */

#include "app_view_api.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mpi_dev.h"
#include "mpi_enc.h"
#define STITCH_SENSOR_NUM 2
#define STITCH_TABLE_NUM 3

static void toMpiStitchAttr(MPI_STITCH_ATTR_S *stitch_attr, const AGTX_STITCH_CONF_S *attr)
{
	INT32 i = 0;

	stitch_attr->enable = attr->enable;
	stitch_attr->dft_dist = attr->dft_dist;
	stitch_attr->table_num = attr->dist_tbl_cnt;

	stitch_attr->center[0].x = attr->center_0_x;
	stitch_attr->center[0].y = attr->center_0_y;
	stitch_attr->center[1].x = attr->center_1_x;
	stitch_attr->center[1].y = attr->center_1_y;

	for (i = 0; i < STITCH_TABLE_NUM; i++) {
		stitch_attr->table[i].dist = attr->dist_tbl[i].dist;
		stitch_attr->table[i].ver_disp = attr->dist_tbl[i].ver_disp;
		stitch_attr->table[i].straighten = attr->dist_tbl[i].straighten;
		stitch_attr->table[i].src_zoom = attr->dist_tbl[i].src_zoom;

		stitch_attr->table[i].theta[0] = attr->dist_tbl[i].theta_0;
		stitch_attr->table[i].radius[0] = attr->dist_tbl[i].radius_0;
		stitch_attr->table[i].curvature[0] = attr->dist_tbl[i].curvature_0;
		stitch_attr->table[i].fov_ratio[0] = attr->dist_tbl[i].fov_ratio_0;
		stitch_attr->table[i].ver_scale[0] = attr->dist_tbl[i].ver_scale_0;
		stitch_attr->table[i].ver_shift[0] = attr->dist_tbl[i].ver_shift_0;

		stitch_attr->table[i].theta[1] = attr->dist_tbl[i].theta_1;
		stitch_attr->table[i].radius[1] = attr->dist_tbl[i].radius_1;
		stitch_attr->table[i].curvature[1] = attr->dist_tbl[i].curvature_1;
		stitch_attr->table[i].fov_ratio[1] = attr->dist_tbl[i].fov_ratio_1;
		stitch_attr->table[i].ver_scale[1] = attr->dist_tbl[i].ver_scale_1;
		stitch_attr->table[i].ver_shift[1] = attr->dist_tbl[i].ver_shift_1;
	}
}

static void toMpiLdcAttr(MPI_LDC_ATTR_S *ldc_attr, const AGTX_LDC_CONF_S *ldc_cfg)
{
	ldc_attr->enable = ldc_cfg->enable;
	ldc_attr->view_type = ldc_cfg->view_type;
	ldc_attr->center_offset.x = ldc_cfg->center_x_offset;
	ldc_attr->center_offset.y = ldc_cfg->center_y_offset;
	ldc_attr->ratio = ldc_cfg->ratio;
}

static void toMpiPanoramaAttr(MPI_PANORAMA_ATTR_S *pano_attr, const AGTX_PANORAMA_CONF_S *pano_cfg)
{
	pano_attr->enable = pano_cfg->enable;
	pano_attr->center_offset.x = pano_cfg->center_offset_x;
	pano_attr->center_offset.y = pano_cfg->center_offset_y;
	pano_attr->ldc_ratio = pano_cfg->ldc_ratio;
	pano_attr->radius = pano_cfg->radius;
	pano_attr->curvature = pano_cfg->curvature;
	pano_attr->straighten = pano_cfg->straighten;
}

static void toMpiPanningAttr(MPI_PANNING_ATTR_S *pann_attr, const AGTX_PANNING_CONF_S *pann_cfg)
{
	pann_attr->enable = pann_cfg->enable;
	pann_attr->center_offset.x = pann_cfg->center_offset_x;
	pann_attr->center_offset.y = pann_cfg->center_offset_y;
	pann_attr->ldc_ratio = pann_cfg->ldc_ratio;
	pann_attr->radius = pann_cfg->radius;
	pann_attr->hor_strength = pann_cfg->hor_strength;
	pann_attr->ver_strength = pann_cfg->ver_strength;
}

static void toMpiSurroundAttr(MPI_SURROUND_ATTR_S *surr_attr, const AGTX_SURROUND_CONF_S *surr_cfg)
{
	surr_attr->enable = surr_cfg->enable;
	surr_attr->center_offset.x = surr_cfg->center_offset_x;
	surr_attr->center_offset.y = surr_cfg->center_offset_y;
	surr_attr->ldc_ratio = surr_cfg->ldc_ratio;
	surr_attr->min_radius = surr_cfg->min_radius;
	surr_attr->max_radius = surr_cfg->max_radius;
	surr_attr->rotate = surr_cfg->rotate;
}

static void toAppStitchCfg(MPI_STITCH_ATTR_S *stitch_attr, AGTX_STITCH_CONF_S *stitch_cfg)
{
	INT32 i = 0;

	stitch_cfg->enable = stitch_attr->enable;
	stitch_cfg->dft_dist = stitch_attr->dft_dist;
	stitch_cfg->dist_tbl_cnt = stitch_attr->table_num;

	stitch_cfg->center_0_x = stitch_attr->center[0].x;
	stitch_cfg->center_0_y = stitch_attr->center[0].y;
	stitch_cfg->center_1_x = stitch_attr->center[1].x;
	stitch_cfg->center_1_y = stitch_attr->center[1].y;

	for (i = 0; i < STITCH_TABLE_NUM; i++) {
		stitch_cfg->dist_tbl[i].tbl_idx = i;
		stitch_cfg->dist_tbl[i].dist = stitch_attr->table[i].dist;
		stitch_cfg->dist_tbl[i].ver_disp = stitch_attr->table[i].ver_disp;
		stitch_cfg->dist_tbl[i].straighten = stitch_attr->table[i].straighten;
		stitch_cfg->dist_tbl[i].src_zoom = stitch_attr->table[i].src_zoom;
		stitch_cfg->dist_tbl[i].theta_0 = stitch_attr->table[i].theta[0];
		stitch_cfg->dist_tbl[i].radius_0 = stitch_attr->table[i].radius[0];
		stitch_cfg->dist_tbl[i].curvature_0 = stitch_attr->table[i].curvature[0];
		stitch_cfg->dist_tbl[i].fov_ratio_0 = stitch_attr->table[i].fov_ratio[0];
		stitch_cfg->dist_tbl[i].ver_scale_0 = stitch_attr->table[i].ver_scale[0];
		stitch_cfg->dist_tbl[i].ver_shift_0 = stitch_attr->table[i].ver_shift[0];
		stitch_cfg->dist_tbl[i].theta_1 = stitch_attr->table[i].theta[1];
		stitch_cfg->dist_tbl[i].radius_1 = stitch_attr->table[i].radius[1];
		stitch_cfg->dist_tbl[i].curvature_1 = stitch_attr->table[i].curvature[1];
		stitch_cfg->dist_tbl[i].fov_ratio_1 = stitch_attr->table[i].fov_ratio[1];
		stitch_cfg->dist_tbl[i].ver_scale_1 = stitch_attr->table[i].ver_scale[1];
		stitch_cfg->dist_tbl[i].ver_shift_1 = stitch_attr->table[i].ver_shift[1];
	}

	stitch_cfg->video_dev_idx = 0;
}

static void toAppLdcCfg(MPI_LDC_ATTR_S *ldc_attr, AGTX_LDC_CONF_S *ldc_cfg)
{
	ldc_cfg->enable = ldc_attr->enable;
	ldc_cfg->view_type = ldc_attr->view_type;
	ldc_cfg->center_x_offset = ldc_attr->center_offset.x;
	ldc_cfg->center_y_offset = ldc_attr->center_offset.y;
	ldc_cfg->ratio = ldc_attr->ratio;
	ldc_cfg->video_dev_idx = 0;
}

static void toAppPanoramaCfg(MPI_PANORAMA_ATTR_S *pano_attr, AGTX_PANORAMA_CONF_S *pano_cfg)
{
	pano_cfg->enable = pano_attr->enable;
	pano_cfg->center_offset_x = pano_attr->center_offset.x;
	pano_cfg->center_offset_y = pano_attr->center_offset.y;
	pano_cfg->ldc_ratio = pano_attr->ldc_ratio;
	pano_cfg->radius = pano_attr->radius;
	pano_cfg->curvature = pano_attr->curvature;
	pano_cfg->straighten = pano_attr->straighten;
	pano_cfg->video_dev_idx = 0;
}

static void toAppPanningCfg(MPI_PANNING_ATTR_S *pann_attr, AGTX_PANNING_CONF_S *pann_cfg)
{
	pann_cfg->enable = pann_attr->enable;
	pann_cfg->center_offset_x = pann_attr->center_offset.x;
	pann_cfg->center_offset_y = pann_attr->center_offset.y;
	pann_cfg->ldc_ratio = pann_attr->ldc_ratio;
	pann_cfg->radius = pann_attr->radius;
	pann_cfg->hor_strength = pann_attr->hor_strength;
	pann_cfg->ver_strength = pann_attr->ver_strength;
	pann_cfg->video_dev_idx = 0;
}

static void toAppSurroundCfg(MPI_SURROUND_ATTR_S *surr_attr, AGTX_SURROUND_CONF_S *surr_cfg)
{
	surr_cfg->enable = surr_attr->enable;
	surr_cfg->center_offset_x = surr_attr->center_offset.x;
	surr_cfg->center_offset_y = surr_attr->center_offset.y;
	surr_cfg->ldc_ratio = surr_attr->ldc_ratio;
	surr_cfg->min_radius = surr_attr->min_radius;
	surr_cfg->max_radius = surr_attr->max_radius;
	surr_cfg->rotate = surr_attr->rotate;
	surr_cfg->video_dev_idx = 0;
}

INT32 APP_VIEW_setStitchAttr(MPI_PATH path_idx, AGTX_STITCH_CONF_S *conf)
{
	INT32 ret = MPI_FAILURE;
	MPI_STITCH_ATTR_S attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	toMpiStitchAttr(&attr, conf);
	ret = MPI_DEV_setStitchAttr(idx, &attr);

	if (ret != MPI_SUCCESS) {
		fprintf(stderr, "Set STITCH attr for device %d channel %d window %d failed.\n", idx.dev, idx.chn,
		        idx.win);
		return MPI_FAILURE;
	}

	return MPI_SUCCESS;
}

INT32 APP_VIEW_setLdcConf(MPI_PATH path_idx, const AGTX_LDC_CONF_S *ldc_cfg)
{
	INT32 ret = MPI_FAILURE;
	MPI_LDC_ATTR_S ldc_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	toMpiLdcAttr(&ldc_attr, ldc_cfg);

	ret = MPI_DEV_setLdcAttr(idx, &ldc_attr);
	if (ret != MPI_SUCCESS) {
		fprintf(stderr, "Set LDC attr for device %d channel %d window %d failed.\n", idx.dev, idx.chn, idx.win);
		return MPI_FAILURE;
	}

	return MPI_SUCCESS;
}

INT32 APP_VIEW_setPanoramaConf(MPI_PATH path_idx, const AGTX_PANORAMA_CONF_S *pano_cfg)
{
	INT32 ret = 0;
	MPI_PANORAMA_ATTR_S pano_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	toMpiPanoramaAttr(&pano_attr, pano_cfg);

	ret = MPI_DEV_setPanoramaAttr(idx, &pano_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	return MPI_SUCCESS;
}

INT32 APP_VIEW_setPanningConf(MPI_PATH path_idx, const AGTX_PANNING_CONF_S *pann_cfg)
{
	INT32 ret = 0;
	MPI_PANNING_ATTR_S pann_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	toMpiPanningAttr(&pann_attr, pann_cfg);

	ret = MPI_DEV_setPanningAttr(idx, &pann_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	return MPI_SUCCESS;
}

INT32 APP_VIEW_setSurroundConf(MPI_PATH path_idx, const AGTX_SURROUND_CONF_S *surr_cfg)
{
	INT32 ret = 0;
	MPI_SURROUND_ATTR_S surr_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	toMpiSurroundAttr(&surr_attr, surr_cfg);

	ret = MPI_DEV_setSurroundAttr(idx, &surr_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	return MPI_SUCCESS;
}

INT32 APP_VIEW_setStitchConf(MPI_PATH path_idx, const AGTX_STITCH_CONF_S *stitch_cfg)
{
	INT32 ret = 0;
	MPI_STITCH_ATTR_S stitch_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	toMpiStitchAttr(&stitch_attr, stitch_cfg);

	ret = MPI_DEV_setStitchAttr(idx, &stitch_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	return MPI_SUCCESS;
}

INT32 APP_VIEW_getLdcConf(MPI_PATH path_idx, AGTX_LDC_CONF_S *ldc_cfg)
{
	INT32 ret = MPI_FAILURE;
	MPI_LDC_ATTR_S ldc_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	ret = MPI_DEV_getLdcAttr(idx, &ldc_attr);
	if (ret != MPI_SUCCESS) {
		fprintf(stderr, "Set LDC attr for device %d channel %d window %d failed.\n", idx.dev, idx.chn, idx.win);
		return MPI_FAILURE;
	}

	toAppLdcCfg(&ldc_attr, ldc_cfg);

	return MPI_SUCCESS;
}

INT32 APP_VIEW_getPanoramaConf(MPI_PATH path_idx, AGTX_PANORAMA_CONF_S *pano_cfg)
{
	INT32 ret = 0;
	MPI_PANORAMA_ATTR_S pano_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	ret = MPI_DEV_getPanoramaAttr(idx, &pano_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	toAppPanoramaCfg(&pano_attr, pano_cfg);

	return MPI_SUCCESS;
}

INT32 APP_VIEW_getPanningConf(MPI_PATH path_idx, AGTX_PANNING_CONF_S *pann_cfg)
{
	INT32 ret = 0;
	MPI_PANNING_ATTR_S pann_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	ret = MPI_DEV_getPanningAttr(idx, &pann_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	toAppPanningCfg(&pann_attr, pann_cfg);

	return MPI_SUCCESS;
}

INT32 APP_VIEW_getSurroundConf(MPI_PATH path_idx, AGTX_SURROUND_CONF_S *surr_cfg)
{
	INT32 ret = 0;
	MPI_SURROUND_ATTR_S surr_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	ret = MPI_DEV_getSurroundAttr(idx, &surr_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	toAppSurroundCfg(&surr_attr, surr_cfg);

	return MPI_SUCCESS;
}

INT32 APP_VIEW_getStitchConf(MPI_PATH path_idx, AGTX_STITCH_CONF_S *stitch_cfg)
{
	INT32 ret = 0;
	MPI_STITCH_ATTR_S stitch_attr = { 0 };
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);

	ret = MPI_DEV_getStitchAttr(idx, &stitch_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}

	toAppStitchCfg(&stitch_attr, stitch_cfg);

	return MPI_SUCCESS;
}

INT32 APP_VIEW_getWinViewType(MPI_PATH path_idx, AGTX_VIEW_TYPE_INFO_S *view_type_info)
{
	INT32 ret = 0;
	MPI_WIN_ATTR_S mpi_win_attr;
	MPI_WIN idx = MPI_VIDEO_WIN(path_idx.dev, 0, 0);
	ret = MPI_DEV_getWindowAttr(idx, &mpi_win_attr);
	if (ret != MPI_SUCCESS) {
		return MPI_FAILURE;
	}
	view_type_info->video_win_idx = idx.value;
	view_type_info->view_type = mpi_win_attr.view_type;
	return MPI_SUCCESS;
}

INT32 getH264Attr(MPI_VENC_ATTR_H264_S *venc_attr, AGTX_VENC_H26X_CONF_S *venc_cfg)
{
	venc_cfg->profile = (AGTX_PRFL_E)venc_attr->profile;
	MPI_MCVC_RC_ATTR_S rc = venc_attr->rc;
	venc_cfg->rc_mode = (AGTX_RC_MODE_E)rc.mode;
	venc_cfg->gop = rc.gop;
	venc_cfg->frm_rate_o = rc.frm_rate_o;
	if ((int)rc.mode == AGTX_RC_MODE_VBR) {
		venc_cfg->vbr.max_bit_rate = rc.vbr.max_bit_rate;
		venc_cfg->vbr.quality_level_index = rc.vbr.quality_level_index;
		venc_cfg->vbr.fluc_level = rc.vbr.fluc_level;
		venc_cfg->vbr.regression_speed = rc.vbr.regression_speed;
		venc_cfg->vbr.scene_smooth = rc.vbr.scene_smooth;
		venc_cfg->vbr.i_continue_weight = rc.vbr.i_continue_weight;
		venc_cfg->vbr.max_qp = rc.vbr.max_qp;
		venc_cfg->vbr.i_qp_offset = rc.vbr.i_qp_offset;
		venc_cfg->vbr.motion_tolerance_level = rc.vbr.motion_tolerance_level;
		venc_cfg->vbr.motion_tolerance_qp = rc.vbr.motion_tolerance_qp;

	} else if ((int)rc.mode == AGTX_RC_MODE_CBR) {
		venc_cfg->cbr.bit_rate = rc.cbr.bit_rate;
		venc_cfg->cbr.fluc_level = rc.cbr.fluc_level;
		venc_cfg->cbr.regression_speed = rc.cbr.regression_speed;
		venc_cfg->cbr.scene_smooth = rc.cbr.scene_smooth;
		venc_cfg->cbr.i_continue_weight = rc.cbr.i_continue_weight;
		venc_cfg->cbr.max_qp = rc.cbr.max_qp;
		venc_cfg->cbr.min_qp = rc.cbr.min_qp;
		venc_cfg->cbr.i_qp_offset = rc.cbr.i_qp_offset;
		venc_cfg->cbr.motion_tolerance_level = rc.cbr.motion_tolerance_level;
		venc_cfg->cbr.motion_tolerance_qp = rc.cbr.motion_tolerance_qp;
	} else if ((int)rc.mode == AGTX_RC_MODE_SBR) {
		venc_cfg->sbr.bit_rate = rc.sbr.bit_rate;
		venc_cfg->sbr.fluc_level = rc.sbr.fluc_level;
		venc_cfg->sbr.regression_speed = rc.sbr.regression_speed;
		venc_cfg->sbr.scene_smooth = rc.sbr.scene_smooth;
		venc_cfg->sbr.i_continue_weight = rc.sbr.i_continue_weight;
		venc_cfg->sbr.max_qp = rc.sbr.max_qp;
		venc_cfg->sbr.min_qp = rc.sbr.min_qp;
		venc_cfg->sbr.adjust_br_thres_pc = rc.sbr.adjust_br_thres_pc;
		venc_cfg->sbr.adjust_step_times = rc.sbr.adjust_step_times;
		venc_cfg->sbr.converge_frame = rc.sbr.converge_frame;
		venc_cfg->sbr.i_qp_offset = rc.sbr.i_qp_offset;
		venc_cfg->sbr.motion_tolerance_level = rc.sbr.motion_tolerance_level;
		venc_cfg->sbr.motion_tolerance_qp = rc.sbr.motion_tolerance_qp;
	} else if ((int)rc.mode == AGTX_RC_MODE_CQP) {
		venc_cfg->cqp.i_frame_qp = rc.cqp.i_frame_qp;
		venc_cfg->cqp.p_frame_qp = rc.cqp.p_frame_qp;
	} else {
		return MPI_FAILURE;
	}
	return MPI_SUCCESS;
}

INT32 getH265Attr(MPI_VENC_ATTR_H265_S *venc_attr, AGTX_VENC_H26X_CONF_S *venc_cfg)
{
	venc_cfg->profile = (AGTX_PRFL_E)venc_attr->profile;
	MPI_MCVC_RC_ATTR_S rc = venc_attr->rc;
	venc_cfg->rc_mode = (AGTX_RC_MODE_E)rc.mode;
	venc_cfg->gop = rc.gop;
	venc_cfg->frm_rate_o = rc.frm_rate_o;
	if ((int)rc.mode == AGTX_RC_MODE_VBR) {
		venc_cfg->vbr.max_bit_rate = rc.vbr.max_bit_rate;
		venc_cfg->vbr.quality_level_index = rc.vbr.quality_level_index;
		venc_cfg->vbr.fluc_level = rc.vbr.fluc_level;
		venc_cfg->vbr.regression_speed = rc.vbr.regression_speed;
		venc_cfg->vbr.scene_smooth = rc.vbr.scene_smooth;
		venc_cfg->vbr.i_continue_weight = rc.vbr.i_continue_weight;
		venc_cfg->vbr.max_qp = rc.vbr.max_qp;
		venc_cfg->vbr.i_qp_offset = rc.vbr.i_qp_offset;
		venc_cfg->vbr.motion_tolerance_level = rc.vbr.motion_tolerance_level;
		venc_cfg->vbr.motion_tolerance_qp = rc.vbr.motion_tolerance_qp;

	} else if ((int)rc.mode == AGTX_RC_MODE_CBR) {
		venc_cfg->cbr.bit_rate = rc.cbr.bit_rate;
		venc_cfg->cbr.fluc_level = rc.cbr.fluc_level;
		venc_cfg->cbr.regression_speed = rc.cbr.regression_speed;
		venc_cfg->cbr.scene_smooth = rc.cbr.scene_smooth;
		venc_cfg->cbr.i_continue_weight = rc.cbr.i_continue_weight;
		venc_cfg->cbr.max_qp = rc.cbr.max_qp;
		venc_cfg->cbr.min_qp = rc.cbr.min_qp;
		venc_cfg->cbr.i_qp_offset = rc.cbr.i_qp_offset;
		venc_cfg->cbr.motion_tolerance_level = rc.cbr.motion_tolerance_level;
		venc_cfg->cbr.motion_tolerance_qp = rc.cbr.motion_tolerance_qp;
	} else if ((int)rc.mode == AGTX_RC_MODE_SBR) {
		venc_cfg->sbr.bit_rate = rc.sbr.bit_rate;
		venc_cfg->sbr.fluc_level = rc.sbr.fluc_level;
		venc_cfg->sbr.regression_speed = rc.sbr.regression_speed;
		venc_cfg->sbr.scene_smooth = rc.sbr.scene_smooth;
		venc_cfg->sbr.i_continue_weight = rc.sbr.i_continue_weight;
		venc_cfg->sbr.max_qp = rc.sbr.max_qp;
		venc_cfg->sbr.min_qp = rc.sbr.min_qp;
		venc_cfg->sbr.adjust_br_thres_pc = rc.sbr.adjust_br_thres_pc;
		venc_cfg->sbr.adjust_step_times = rc.sbr.adjust_step_times;
		venc_cfg->sbr.converge_frame = rc.sbr.converge_frame;
		venc_cfg->sbr.i_qp_offset = rc.sbr.i_qp_offset;
		venc_cfg->sbr.motion_tolerance_level = rc.sbr.motion_tolerance_level;
		venc_cfg->sbr.motion_tolerance_qp = rc.sbr.motion_tolerance_qp;
	} else if ((int)rc.mode == AGTX_RC_MODE_CQP) {
		venc_cfg->cqp.i_frame_qp = rc.cqp.i_frame_qp;
		venc_cfg->cqp.p_frame_qp = rc.cqp.p_frame_qp;
	} else {
		return MPI_FAILURE;
	}
	return MPI_SUCCESS;
}
INT32 APP_VIEW_getVencAttr(MPI_ECHN echn_idx, AGTX_VENC_CONF_S *venc_cfg)
{
	INT32 ret = 0;
	MPI_VENC_ATTR_S mpi_venc_attr;
	ret = MPI_ENC_getVencAttr(echn_idx, &mpi_venc_attr);
	if (ret == MPI_FAILURE) {
		return ret;
	}
	venc_cfg->type = (AGTX_VENC_TYPE_E)mpi_venc_attr.type;
	if (venc_cfg->type == AGTX_VENC_TYPE_H264) {
		ret = getH264Attr(&(mpi_venc_attr.h264), &(venc_cfg->h264));
	} else if (venc_cfg->type == AGTX_VENC_TYPE_H265) {
		ret = getH265Attr(&(mpi_venc_attr.h265), &(venc_cfg->h265));
	} else if (venc_cfg->type == AGTX_VENC_TYPE_MJPEG) {
		venc_cfg->mjpeg.rc_mode = (AGTX_RC_MODE_E)mpi_venc_attr.mjpeg.rc.mode;
		venc_cfg->mjpeg.frm_rate_o = mpi_venc_attr.mjpeg.rc.frm_rate_o;
		venc_cfg->mjpeg.fluc_level = mpi_venc_attr.mjpeg.rc.fluc_level;
		venc_cfg->mjpeg.bit_rate = mpi_venc_attr.mjpeg.rc.bit_rate;
		venc_cfg->mjpeg.max_q_factor = mpi_venc_attr.mjpeg.rc.max_q_factor;
		venc_cfg->mjpeg.min_q_factor = mpi_venc_attr.mjpeg.rc.min_q_factor;
		venc_cfg->mjpeg.max_bit_rate = mpi_venc_attr.mjpeg.rc.max_bit_rate;
		venc_cfg->mjpeg.quality_level_index = mpi_venc_attr.mjpeg.rc.quality_level_index;
		venc_cfg->mjpeg.q_factor = mpi_venc_attr.mjpeg.rc.q_factor;
		venc_cfg->mjpeg.adjust_br_thres_pc = mpi_venc_attr.mjpeg.rc.adjust_br_thres_pc;
		venc_cfg->mjpeg.adjust_step_times = mpi_venc_attr.mjpeg.rc.adjust_step_times;
		venc_cfg->mjpeg.converge_frame = mpi_venc_attr.mjpeg.rc.converge_frame;
		venc_cfg->mjpeg.motion_tolerance_level = mpi_venc_attr.mjpeg.rc.motion_tolerance_level;
		venc_cfg->mjpeg.motion_tolerance_qfactor = mpi_venc_attr.mjpeg.rc.motion_tolerance_qfactor;
	}

	return ret;
}

INT32 setH264Attr(MPI_VENC_ATTR_H264_S *venc_attr, AGTX_VENC_H26X_CONF_S *venc_cfg)
{
	venc_attr->profile = (MPI_VENC_PRFL_E)venc_cfg->profile;
	MPI_MCVC_RC_ATTR_S *rc = &(venc_attr->rc);
	rc->mode = (MPI_RC_MODE_E)venc_cfg->rc_mode;
	rc->gop = (UINT32)venc_cfg->gop;
	rc->frm_rate_o = (INT32)venc_cfg->frm_rate_o;
	if ((int)rc->mode == AGTX_RC_MODE_VBR) {
		rc->vbr.max_bit_rate = (UINT32)venc_cfg->vbr.max_bit_rate;
		rc->vbr.quality_level_index = (UINT32)venc_cfg->vbr.quality_level_index;
		rc->vbr.fluc_level = (UINT32)venc_cfg->vbr.fluc_level;
		rc->vbr.regression_speed = (UINT32)venc_cfg->vbr.regression_speed;
		rc->vbr.scene_smooth = (UINT32)venc_cfg->vbr.scene_smooth;
		rc->vbr.i_continue_weight = 0;
		rc->vbr.max_qp = (UINT32)venc_cfg->vbr.max_qp;
		rc->vbr.i_qp_offset = (INT32)venc_cfg->vbr.i_qp_offset;
		rc->vbr.motion_tolerance_level = (UINT32)venc_cfg->vbr.motion_tolerance_level;
		rc->vbr.motion_tolerance_qp = (UINT32)venc_cfg->vbr.motion_tolerance_qp;
	} else if ((int)rc->mode == AGTX_RC_MODE_CBR) {
		rc->cbr.bit_rate = (UINT32)venc_cfg->cbr.bit_rate;
		rc->cbr.fluc_level = (UINT32)venc_cfg->cbr.fluc_level;
		rc->cbr.regression_speed = (UINT32)venc_cfg->cbr.regression_speed;
		rc->cbr.scene_smooth = (UINT32)venc_cfg->cbr.scene_smooth;
		rc->vbr.i_continue_weight = 0;
		rc->cbr.max_qp = (UINT32)venc_cfg->cbr.max_qp;
		rc->cbr.min_qp = (UINT32)venc_cfg->cbr.min_qp;
		rc->cbr.i_qp_offset = (INT32)venc_cfg->cbr.i_qp_offset;
		rc->cbr.motion_tolerance_level = (UINT32)venc_cfg->cbr.motion_tolerance_level;
		rc->cbr.motion_tolerance_qp = (UINT32)venc_cfg->cbr.motion_tolerance_qp;
	} else if ((int)rc->mode == AGTX_RC_MODE_SBR) {
		rc->sbr.bit_rate = (UINT32)venc_cfg->sbr.bit_rate;
		rc->sbr.fluc_level = (UINT32)venc_cfg->sbr.fluc_level;
		rc->sbr.regression_speed = (UINT32)venc_cfg->sbr.regression_speed;
		rc->sbr.scene_smooth = (UINT32)venc_cfg->sbr.scene_smooth;
		rc->vbr.i_continue_weight = 0;
		rc->sbr.max_qp = (UINT32)venc_cfg->sbr.max_qp;
		rc->sbr.min_qp = (UINT32)venc_cfg->sbr.min_qp;
		rc->sbr.adjust_br_thres_pc = (UINT32)venc_cfg->sbr.adjust_br_thres_pc;
		rc->sbr.adjust_step_times = (UINT32)venc_cfg->sbr.adjust_step_times;
		rc->sbr.converge_frame = (UINT32)venc_cfg->sbr.converge_frame;
		rc->sbr.i_qp_offset = (INT32)venc_cfg->sbr.i_qp_offset;
		rc->sbr.motion_tolerance_level = (UINT32)venc_cfg->sbr.motion_tolerance_level;
		rc->sbr.motion_tolerance_qp = (UINT32)venc_cfg->sbr.motion_tolerance_qp;
	} else if ((int)rc->mode == AGTX_RC_MODE_CQP) {
		rc->cqp.i_frame_qp = (UINT32)venc_cfg->cqp.i_frame_qp;
		rc->cqp.p_frame_qp = (UINT32)venc_cfg->cqp.p_frame_qp;
	} else {
		return MPI_FAILURE;
	}
	return MPI_SUCCESS;
}

INT32 setH265Attr(MPI_VENC_ATTR_H265_S *venc_attr, AGTX_VENC_H26X_CONF_S *venc_cfg)
{
	venc_attr->profile = (MPI_VENC_PRFL_E)venc_cfg->profile;
	MPI_MCVC_RC_ATTR_S *rc = &(venc_attr->rc);
	rc->mode = (MPI_RC_MODE_E)venc_cfg->rc_mode;
	rc->gop = (UINT32)venc_cfg->gop;
	rc->frm_rate_o = (INT32)venc_cfg->frm_rate_o;
	if ((int)rc->mode == AGTX_RC_MODE_VBR) {
		rc->vbr.max_bit_rate = (UINT32)venc_cfg->vbr.max_bit_rate;
		rc->vbr.quality_level_index = (UINT32)venc_cfg->vbr.quality_level_index;
		rc->vbr.fluc_level = (UINT32)venc_cfg->vbr.fluc_level;
		rc->vbr.regression_speed = (UINT32)venc_cfg->vbr.regression_speed;
		rc->vbr.scene_smooth = (UINT32)venc_cfg->vbr.scene_smooth;
		rc->vbr.i_continue_weight = 0;
		rc->vbr.max_qp = (UINT32)venc_cfg->vbr.max_qp;
		rc->vbr.i_qp_offset = (INT32)venc_cfg->vbr.i_qp_offset;
		rc->vbr.motion_tolerance_level = (UINT32)venc_cfg->vbr.motion_tolerance_level;
		rc->vbr.motion_tolerance_qp = (UINT32)venc_cfg->vbr.motion_tolerance_qp;
	} else if ((int)rc->mode == AGTX_RC_MODE_CBR) {
		rc->cbr.bit_rate = (UINT32)venc_cfg->cbr.bit_rate;
		rc->cbr.fluc_level = (UINT32)venc_cfg->cbr.fluc_level;
		rc->cbr.regression_speed = (UINT32)venc_cfg->cbr.regression_speed;
		rc->cbr.scene_smooth = (UINT32)venc_cfg->cbr.scene_smooth;
		rc->vbr.i_continue_weight = 0;
		rc->cbr.max_qp = (UINT32)venc_cfg->cbr.max_qp;
		rc->cbr.min_qp = (UINT32)venc_cfg->cbr.min_qp;
		rc->cbr.i_qp_offset = (INT32)venc_cfg->cbr.i_qp_offset;
		rc->cbr.motion_tolerance_level = (UINT32)venc_cfg->cbr.motion_tolerance_level;
		rc->cbr.motion_tolerance_qp = (UINT32)venc_cfg->cbr.motion_tolerance_qp;
	} else if ((int)rc->mode == AGTX_RC_MODE_SBR) {
		rc->sbr.bit_rate = (UINT32)venc_cfg->sbr.bit_rate;
		rc->sbr.fluc_level = (UINT32)venc_cfg->sbr.fluc_level;
		rc->sbr.regression_speed = (UINT32)venc_cfg->sbr.regression_speed;
		rc->sbr.scene_smooth = (UINT32)venc_cfg->sbr.scene_smooth;
		rc->vbr.i_continue_weight = 0;
		rc->sbr.max_qp = (UINT32)venc_cfg->sbr.max_qp;
		rc->sbr.min_qp = (UINT32)venc_cfg->sbr.min_qp;
		rc->sbr.adjust_br_thres_pc = (UINT32)venc_cfg->sbr.adjust_br_thres_pc;
		rc->sbr.adjust_step_times = (UINT32)venc_cfg->sbr.adjust_step_times;
		rc->sbr.converge_frame = (UINT32)venc_cfg->sbr.converge_frame;
		rc->sbr.i_qp_offset = (INT32)venc_cfg->sbr.i_qp_offset;
		rc->sbr.motion_tolerance_level = (UINT32)venc_cfg->sbr.motion_tolerance_level;
		rc->sbr.motion_tolerance_qp = (UINT32)venc_cfg->sbr.motion_tolerance_qp;
	} else if ((int)rc->mode == AGTX_RC_MODE_CQP) {
		rc->cqp.i_frame_qp = (UINT32)venc_cfg->cqp.i_frame_qp;
		rc->cqp.p_frame_qp = (UINT32)venc_cfg->cqp.p_frame_qp;
	} else {
		return MPI_FAILURE;
	}
	return MPI_SUCCESS;
}

INT32 APP_VIEW_setVencAttr(MPI_ECHN echn_idx, AGTX_VENC_CONF_S *venc_cfg)
{
	INT32 ret = 0;
	MPI_VENC_ATTR_S mpi_venc_attr;
	ret = MPI_ENC_getVencAttr(echn_idx, &(mpi_venc_attr));
	if (ret == MPI_FAILURE) {
		return ret;
	}
	int type_diff = mpi_venc_attr.type != (MPI_VENC_TYPE_E)venc_cfg->type ? 1 : 0;
	mpi_venc_attr.type = (MPI_VENC_TYPE_E)venc_cfg->type;
	if (venc_cfg->type == AGTX_VENC_TYPE_H264) {
		ret = setH264Attr(&(mpi_venc_attr.h264), &(venc_cfg->h264));
	} else if (venc_cfg->type == AGTX_VENC_TYPE_H265) {
		ret = setH265Attr(&(mpi_venc_attr.h265), &(venc_cfg->h265));
	} else if (venc_cfg->type == AGTX_VENC_TYPE_MJPEG) {
		mpi_venc_attr.mjpeg.rc.mode = (MPI_RC_MODE_E)venc_cfg->mjpeg.rc_mode;
		mpi_venc_attr.mjpeg.rc.frm_rate_o = (UINT32)venc_cfg->mjpeg.frm_rate_o;
		mpi_venc_attr.mjpeg.rc.fluc_level = (UINT32)venc_cfg->mjpeg.fluc_level;
		mpi_venc_attr.mjpeg.rc.bit_rate = (UINT32)venc_cfg->mjpeg.bit_rate;
		mpi_venc_attr.mjpeg.rc.max_q_factor = (UINT32)venc_cfg->mjpeg.max_q_factor;
		mpi_venc_attr.mjpeg.rc.min_q_factor = (UINT32)venc_cfg->mjpeg.min_q_factor;
		mpi_venc_attr.mjpeg.rc.max_bit_rate = (UINT32)venc_cfg->mjpeg.max_bit_rate;
		mpi_venc_attr.mjpeg.rc.quality_level_index = (UINT32)venc_cfg->mjpeg.quality_level_index;
		mpi_venc_attr.mjpeg.rc.q_factor = (UINT32)venc_cfg->mjpeg.q_factor;
		mpi_venc_attr.mjpeg.rc.adjust_br_thres_pc = (UINT32)venc_cfg->mjpeg.adjust_br_thres_pc;
		mpi_venc_attr.mjpeg.rc.adjust_step_times = (UINT32)venc_cfg->mjpeg.adjust_step_times;
		mpi_venc_attr.mjpeg.rc.converge_frame = (UINT32)venc_cfg->mjpeg.converge_frame;
		mpi_venc_attr.mjpeg.rc.motion_tolerance_level = (UINT32)venc_cfg->mjpeg.motion_tolerance_level;
		mpi_venc_attr.mjpeg.rc.motion_tolerance_qfactor = (UINT32)venc_cfg->mjpeg.motion_tolerance_qfactor;
	}
	if (ret == MPI_FAILURE) {
		return ret;
	}
	if (type_diff == 1) {
		MPI_ENC_BIND_INFO_S bind_info;
		memset(&bind_info, 0, sizeof(MPI_ENC_BIND_INFO_S));
		//stop the specific running encoder
		ret = MPI_ENC_stopChn(echn_idx);
		if (ret != MPI_SUCCESS) {
			printf("MPI_ENC_stopChn(%d) failed. err: %d (%s).\n", echn_idx.chn, ret, strerror(-ret));
			return MPI_FAILURE;
		}
		ret = MPI_ENC_setVencAttr(echn_idx, &(mpi_venc_attr));
		if (ret != MPI_SUCCESS) {
			return ret;
		}
		//restart the specific running encoder
		bind_info.idx = MPI_VIDEO_CHN(0, echn_idx.chn);
		ret = MPI_ENC_bindToVideoChn(echn_idx, &bind_info);
		if (ret != MPI_SUCCESS) {
			printf("MPI_ENC_bindToVideoChn(%d, %d) failed. err: %d (%s).\n", echn_idx.chn,
			       bind_info.idx.chn, ret, strerror(-ret));
			return ret;
		}
		ret = MPI_ENC_startChn(echn_idx);
		if (ret != MPI_SUCCESS) {
			printf("MPI_ENC_startChn(%d) failed. err: %d (%s).\n", echn_idx.chn, ret, strerror(-ret));
			return ret;
		}
	} else {
		ret = MPI_ENC_setVencAttr(echn_idx, &(mpi_venc_attr));
		if (ret != MPI_SUCCESS) {
			return ret;
		}
	}
	return ret;
}

#ifdef __cplusplus
}
#endif /**< __cplusplus */
