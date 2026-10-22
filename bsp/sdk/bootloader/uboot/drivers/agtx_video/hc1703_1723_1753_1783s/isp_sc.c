#include "isp.h"

struct sc_double {
	int32_t integer;
	int32_t remainder;
	int32_t divisor;
};

static uint32_t __calc_gcd(uint32_t x, uint32_t y)
{
	if ((x != 0) && (y != 0)) {
		return __calc_gcd(((x >= y) ? x % y : x), ((x < y) ? y % x : y));
	} else {
		return ((x != 0) ? x : y);
	}
}

static struct sc_double __change_coordinate(uint32_t x_i, uint32_t in, uint32_t out)
{
	int32_t sum;
	uint32_t abs_re;
	uint32_t gcd;
	struct sc_double dbl;

	sum = (out - in) + 2 * x_i * out;
	dbl.divisor = (in << 1);

	/* sum / divisor = integer + remainder / divisor, integer is integer part and */
	/* remainder / divisor is decimal part */
	dbl.integer = sum / dbl.divisor;
	dbl.remainder = sum % dbl.divisor;

	abs_re = (dbl.remainder < 0) ? -dbl.remainder : dbl.remainder;
	gcd = __calc_gcd(abs_re, dbl.divisor);

	if (gcd > 1) {
		dbl.remainder = ((int32_t)dbl.remainder / (int32_t)gcd);
		dbl.divisor /= gcd;
	}

	return dbl;
}

static uint32_t __get_phase_step(uint32_t in, uint32_t out)
{
	uint32_t step;
	uint32_t gcd;
	struct sc_double dbl;
	gcd = __calc_gcd(in, out);
	in /= gcd;
	out /= gcd;
	dbl.integer = in / out;
	dbl.remainder = in % out;
	dbl.divisor = out;
	step = (dbl.remainder << EARLYVIDEO_SC_PHASE_PRECISION) / dbl.divisor +
	       (dbl.integer << EARLYVIDEO_SC_PHASE_PRECISION);

	return step;
}

static int32_t __get_ini_phase(uint32_t src_fx, uint32_t dst_fx, uint32_t in, uint32_t out, uint32_t up_scale)
{
	uint32_t dst_first_x_shifted = 0;
	int32_t ini_phase = 0;
	int32_t numerator;
	struct sc_double dbl;

	if (up_scale) {
		dst_first_x_shifted = dst_fx;
	} else {
		dst_first_x_shifted = dst_fx + (EARLYVIDEO_SC_TAP / 2);
	}

	dbl = __change_coordinate(dst_first_x_shifted, in, out);
	dbl.integer -= src_fx;

	numerator = (dbl.integer * dbl.divisor + dbl.remainder);
	ini_phase = (numerator << EARLYVIDEO_SC_PHASE_PRECISION) / dbl.divisor;

	return ini_phase;
}

static int32_t __get_ini_phase_ds(const int32_t dst_fx, const int32_t in, const int32_t out)
{
	int32_t dst_first_x_shifted = 0;
	int32_t src_x_ceiling = 0;
	int32_t ini_phase_ds = 0;
	int32_t numerator;
	struct sc_double dbl;
	struct sc_double dbl_dst;

	dst_first_x_shifted = dst_fx - (EARLYVIDEO_SC_TAP / 2);
	dbl = __change_coordinate(dst_first_x_shifted, in, out);

	if ((dbl.integer > 0) && (dbl.remainder > 0)) {
		src_x_ceiling = dbl.integer + 1;
	} else {
		src_x_ceiling = dbl.integer;
	}

	dbl_dst = __change_coordinate(src_x_ceiling, out, in);
	dbl_dst.integer -= dst_fx;

	numerator = (dbl_dst.integer * dbl_dst.divisor + dbl_dst.remainder);
	ini_phase_ds = (numerator << EARLYVIDEO_SC_PHASE_PRECISION) / dbl_dst.divisor;

	return ini_phase_ds;
}

static int32_t __get_first_down_scaling_start_phase(const uint32_t ini_phase, const uint32_t phase_step)
{
	return (int32_t)(ini_phase - EARLYVIDEO_SC_TAP * phase_step);
}

static int32_t __get_first_right_int_from_phase(const int32_t phase)
{
	/* Get first integer to the right of "left point" */
	return (int32_t)((phase + (1 << EARLYVIDEO_SC_PHASE_PRECISION) - 1) >> EARLYVIDEO_SC_PHASE_PRECISION);
}

static void __get_ini_cnts(const int32_t ini_phase, const uint32_t phase_step, int32_t (*ini_cnt)[EARLYVIDEO_SC_TAP])
{
	int32_t i = 0;
	int32_t phase;

	phase = __get_first_down_scaling_start_phase(ini_phase, phase_step);

	for (i = 0; i < EARLYVIDEO_SC_TAP; i++, phase += phase_step) {
		(*ini_cnt)[i] = (__get_first_right_int_from_phase(phase) & 0xFF);
	}
}

void isp_sc_set_tile_csr(volatile CsrBankSc *csr, struct tile_sc_param *sc_param, int t)
{
	csr->width_i = sc_param->tile_width_i[t];
	csr->width_o = sc_param->tile_width_o[t] + sc_param->crop_o_left[t];
	csr->width_i_before_crop = sc_param->tile_width_i[t];
	csr->ini_phase_hor = sc_param->ini_phase_hor[t];
	csr->ini_filt_phase_ds_hor = sc_param->ini_filt_phase_ds_hor[t];
	csr->ini_cnt_0_hor = sc_param->ini_cnt_hor[t][0];
	csr->ini_cnt_1_hor = sc_param->ini_cnt_hor[t][1];
	csr->ini_cnt_2_hor = sc_param->ini_cnt_hor[t][2];
	csr->ini_cnt_3_hor = sc_param->ini_cnt_hor[t][3];
	csr->ini_cnt_4_hor = sc_param->ini_cnt_hor[t][4];
	csr->ini_cnt_5_hor = sc_param->ini_cnt_hor[t][5];
	csr->crop_o_left = sc_param->crop_o_left[t];
}

void isp_sc_set_frame_csr(volatile CsrBankSc *csr, struct tile_sc_param *sc_param)
{
	csr->up_scaling_hor = sc_param->up_scaling_hor;
	csr->up_scaling_ver = sc_param->up_scaling_ver;
	csr->height_i = sc_param->frame_height_i;
	csr->height_i_before_crop = sc_param->frame_height_i;
	csr->height_o = sc_param->frame_height_o;
	csr->ini_phase_ver = sc_param->ini_phase_ver;
	csr->phase_step_hor = sc_param->phase_step_hor;
	csr->phase_step_ver = sc_param->phase_step_ver;
	csr->ini_filt_phase_ds_ver = sc_param->ini_filt_phase_ds_ver;
	csr->filt_phase_step_ds_hor = sc_param->filt_phase_step_ds_hor;
	csr->filt_phase_step_ds_ver = sc_param->filt_phase_step_ds_ver;
	csr->ini_cnt_0_ver = sc_param->ini_cnt_ver[0];
	csr->ini_cnt_1_ver = sc_param->ini_cnt_ver[1];
	csr->ini_cnt_2_ver = sc_param->ini_cnt_ver[2];
	csr->ini_cnt_3_ver = sc_param->ini_cnt_ver[3];
	csr->ini_cnt_4_ver = sc_param->ini_cnt_ver[4];
	csr->ini_cnt_5_ver = sc_param->ini_cnt_ver[5];
}

void isp_calc_sc_ver_param(struct tile_sc_param *sc_param, uint16_t frame_height_i, uint16_t frame_height_o)
{
	sc_param->frame_height_i = frame_height_i;
	sc_param->frame_height_o = frame_height_o;
	sc_param->up_scaling_ver = (frame_height_i > frame_height_o) ? 0 : 1;
	sc_param->phase_step_ver = __get_phase_step(frame_height_i, frame_height_o);
	sc_param->ini_phase_ver = __get_ini_phase(0, 0, frame_height_o, frame_height_i, sc_param->up_scaling_ver);

	if (!sc_param->up_scaling_ver) {
		sc_param->filt_phase_step_ds_ver = __get_phase_step(frame_height_o, frame_height_i);

		sc_param->ini_filt_phase_ds_ver = __get_ini_phase_ds(0, frame_height_o, frame_height_i);
		__get_ini_cnts(sc_param->ini_phase_ver, sc_param->phase_step_ver, &sc_param->ini_cnt_ver);
	}
}

void isp_calc_sc_hor_param(struct tile_sc_param *sc_param, uint16_t frame_width_i, uint16_t frame_width_o,
                           const struct tile_info *tile_i, const struct tile_info *tile_o, int tile_n)
{
	const struct tile_info *info_in;
	const struct tile_info *info_out;
	int32_t start_phase;
	int32_t start_ini_cnt;
	int32_t first_x_o;
	int tile;

	sc_param->frame_width_i = frame_width_i;
	sc_param->frame_width_o = frame_width_o;
	sc_param->up_scaling_hor = (frame_width_i > frame_width_o) ? 0 : 1;
	sc_param->phase_step_hor = __get_phase_step(frame_width_i, frame_width_o);
	sc_param->filt_phase_step_ds_hor = __get_phase_step(frame_width_o, frame_width_i);

	for (tile = 0; tile < tile_n; tile++) {
		info_in = &tile_i[tile];
		info_out = &tile_o[tile];
		sc_param->tile_width_i[tile] = info_in->tile_in_width;
		sc_param->tile_width_o[tile] = info_out->tile_in_width;
		sc_param->ini_phase_hor[tile] = __get_ini_phase(info_in->first_x, info_out->first_x, frame_width_o,
		                                                frame_width_i, sc_param->up_scaling_hor);
		sc_param->crop_o_left[tile] = 0;
		if (!sc_param->up_scaling_hor) {
			first_x_o = info_out->first_x - sc_param->crop_o_left[tile];
			start_phase = __get_first_down_scaling_start_phase(sc_param->ini_phase_hor[tile],
			                                                   sc_param->phase_step_hor);
			start_ini_cnt = __get_first_right_int_from_phase(start_phase);

			while (start_ini_cnt >= 0) {
				sc_param->crop_o_left[tile] += 2;
				first_x_o = info_out->first_x - sc_param->crop_o_left[tile];
				sc_param->ini_phase_hor[tile] = __get_ini_phase(info_in->first_x, first_x_o,
				                                                frame_width_o, frame_width_i,
				                                                sc_param->up_scaling_hor);
				start_phase = __get_first_down_scaling_start_phase(sc_param->ini_phase_hor[tile],
				                                                   sc_param->phase_step_hor);
				start_ini_cnt = __get_first_right_int_from_phase(start_phase);
			}
			sc_param->ini_filt_phase_ds_hor[tile] =
			        __get_ini_phase_ds(first_x_o, frame_width_o, frame_width_i);
			__get_ini_cnts(sc_param->ini_phase_hor[tile], sc_param->phase_step_hor,
			               &sc_param->ini_cnt_hor[tile]);
		}
	}
}