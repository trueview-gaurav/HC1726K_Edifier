#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mpi_limits.h"
#include "mpi_dip_sns.h"
#include "sensor.h"
#include "sensor_types.h"
#include "sensor_params.h"
#include "sensor_settings.h"
#include "sensor_lvds.h"

MPI_SNS_CALLBACK_S g_codegen_sns_callbacks[MPI_MAX_INPUT_PATH_NUM];

#ifdef SNS0
extern CUSTOM_SNS_CTRL_S custom_sns(SNS0_ID);
#endif

#ifdef SNS1
extern CUSTOM_SNS_CTRL_S custom_sns(SNS1_ID);
#endif

#ifdef SNS2
extern CUSTOM_SNS_CTRL_S custom_sns(SNS2_ID);
#endif

#ifdef SNS3
extern CUSTOM_SNS_CTRL_S custom_sns(SNS3_ID);
#endif

static CUSTOM_SNS_CTRL_S *p_custom_sns[] = {
#ifdef SNS0
	&custom_sns(SNS0_ID),
#else
	NULL,
#endif
#ifdef SNS1
	&custom_sns(SNS1_ID),
#else
	NULL,
#endif
#ifdef SNS2
	&custom_sns(SNS2_ID),
#else
	NULL,
#endif
#ifdef SNS3
	&custom_sns(SNS3_ID),
#else
	NULL,
#endif
};

INT32 MPI_regSnsCallback(MPI_PATH idx, INT32 sns_id, const MPI_SNS_CALLBACK_S *p_sns_cb)
{
	int path_idx = idx.path;

	if (!p_sns_cb) {
		return MPI_FAILURE;
	}

	g_codegen_sns_callbacks[path_idx] = *p_sns_cb;
	g_codegen_sns_callbacks[path_idx].dip.global_init(idx);

	return MPI_SUCCESS;
}

INT32 MPI_deregSnsCallback(MPI_PATH idx, INT32 sns_id)
{
	/* fake */

	return 0;
}

void help(void)
{
	printf("gen_header <output filename> <sensor #>\n");
}

int main(int argc, char **argv)
{
	MPI_SNS_OP_INFO_S op_info;
	FILE *fwp = NULL;
	MPI_PATH path_idx;
	uint8_t p_idx;
	uint32_t sns_idx;
	uint32_t sensor_bit_depth;
	int lvds_data_num = 0;
	int i;

	if (argc < 2) {
		help();
		return 1;
	}

	fwp = fopen(argv[1], "w");

	if (fwp == NULL) {
		fprintf(stderr, "Error: Failed to open file %s\n", argv[1]);
		return 1;
	}

	/* AUTOGEN case: path idx = sensor idx */
	p_idx = (uint8_t)atoi(argv[2]);
	sns_idx = (uint32_t)atoi(argv[2]);

	op_info.sensor_res.width = 0;
	op_info.sensor_res.height = 0;
	path_idx = MPI_INPUT_PATH(0, p_idx);

	if (!p_custom_sns[p_idx]) {
		fprintf(stderr, "Error: Cannot find Sensor callback functions, please check if \"SNS%d\" macro exists.\n", p_idx);
		return 1;
	}

	p_custom_sns[p_idx]->reg_callback(path_idx);

	g_codegen_sns_callbacks[p_idx].dip.get_sns_op_info(p_idx, sns_idx, &op_info);

	switch (op_info.bit_width) {
	case MPI_BITS_16:
		sensor_bit_depth = 16;
		break;
	case MPI_BITS_14:
		sensor_bit_depth = 14;
		break;
	case MPI_BITS_12:
		sensor_bit_depth = 12;
		break;
	case MPI_BITS_10:
		sensor_bit_depth = 10;
		break;
	case MPI_BITS_9:
		sensor_bit_depth = 9;
		break;
	case MPI_BITS_8:
		sensor_bit_depth = 8;
		break;
	case MPI_BITS_7:
		sensor_bit_depth = 7;
		break;
	case MPI_BITS_6:
		sensor_bit_depth = 6;
		break;
	case MPI_BITS_NUM:
	default:
		fclose(fwp);
		fprintf(stderr, "Error: Unknown sensor bit width %d\n", op_info.bit_width);
		return 1;
	}

	fprintf(fwp, "#ifndef _SENSOR_DEF_%d_H_\n", p_idx);
	fprintf(fwp, "#define _SENSOR_DEF_%d_H_\n\n", p_idx);

	/* earlyvideo data collecting start */
	fprintf(fwp, "#define SENSOR_WIDTH_%d (%d)\n", p_idx, op_info.sensor_res.width);
	fprintf(fwp, "#define SENSOR_HEIGHT_%d (%d)\n", p_idx, op_info.sensor_res.height);
	for (i = 0; i < MPI_MAX_LVDSRX_LANE_NUM; i++) {
		if (op_info.serl_lane[i].lane_type < MPI_LANE_TYPE_UNUSED) {
			if (op_info.serl_lane[i].lane_type == MPI_LANE_TYPE_CLOCK) {
				fprintf(fwp, "#define LVDS_CLOCK_LANE_%d (%d)\n", p_idx, op_info.serl_lane[i].lane_idx);
			} else {
				fprintf(fwp, "#define LVDS_DATA_LANE_%d_%d (%d)\n", lvds_data_num, p_idx,
				        op_info.serl_lane[i].lane_idx);
				lvds_data_num++;
			}
		}
	}
	fprintf(fwp, "#define LVDS_DATA_NUM_%d (%d)\n", p_idx, lvds_data_num);
	fprintf(fwp, "#define SENSOR_BIT_DEPTH_%d (%d)\n", p_idx, sensor_bit_depth);
	fprintf(fwp, "#define BP_HOR_%d (%d)\n", p_idx, op_info.mipi.bp_img.hor);
	fprintf(fwp, "#define BP_VER_%d (%d)\n", p_idx, op_info.mipi.bp_img.ver);
	fprintf(fwp, "#define FP_HOR_%d (%d)\n", p_idx, op_info.mipi.fp_img.hor);
	fprintf(fwp, "#define FP_VER_%d (%d)\n", p_idx, op_info.mipi.fp_img.ver);
	fprintf(fwp, "#define T_HS_SETTLE_NS_%d (%d)\n", p_idx, op_info.mipi.t_hs_settle_ns);
	fprintf(fwp, "#define T_D_TERM_EN_NS_%d (%d)\n", p_idx, op_info.mipi.t_d_term_en_ns);
	fprintf(fwp, "#define T_CLK_SETTLE_NS_%d (%d)\n", p_idx, op_info.mipi.t_clk_settle_ns);
	fprintf(fwp, "#define T_CLK_TERM_EN_NS_%d (%d)\n", p_idx, op_info.mipi.t_clk_term_en_ns);
	fprintf(fwp, "#define SENSOR_BAYER_PHASE_%d (%d)\n", p_idx, op_info.bayer);
	/* earlyvideo data collecting end */

	fprintf(fwp, "\n#endif /* _SENSOR_DEF_%d_H_ */\n", p_idx);

	fclose(fwp);

	return 0;
}
