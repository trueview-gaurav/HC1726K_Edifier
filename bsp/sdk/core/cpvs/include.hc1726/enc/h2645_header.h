/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_H2645_HEADER_H_
#define KYOTO_H2645_HEADER_H_

#include "enc.h"

#define EMBEDDED_VUI 0

struct hdr_data {
	u32 len;
	u64 buf_0; // data_0, data_1
	u64 buf_1; // data_2, data_3
};

void ue(int codeNum, int *bitString, int *length);
void write_code_to_buf(u32 code_length, u32 code_value, u32 *cur_bit_buf_size, u64 *final_bs_buf_0,
                       u64 *final_bs_buf_1);
void write_bytes_to_stream(uint32_t *code_length, uint32_t bit_buf, uint8_t *final_bs_buf, int *buf_byte_cnt);
int h264_sps_header(int profile_code, int level, const EncFrameConfig *frame_cfg, uint8_t *seq_header);
void h264_pps_header(int profile_code, int is_cabac_flg, int is_tr8_flg, u64 *final_bs_buf_0, u64 *final_bs_buf_1,
                     u32 *slice_header_length);
void h264_i_slice_header(int is_cabac, int slice_qp, int db_disable, int db_beta_offset_div2, int db_tc_offset_div2,
                         u64 *final_bs_buf_0, u64 *final_bs_buf_1, u32 *slice_header_length);
void h264_p_slice_header(int is_cabac, int frame_idx, int slice_qp, int db_disable, int db_beta_offset_div2,
                         int db_tc_offset_div2, u64 *final_bs_buf_0, u64 *final_bs_buf_1, u32 *slice_header_length);
u32 h265_seq_header(const EncFrameConfig *frame_cfg, int level, u8 *final_bs_buf);
void h265_i_slice_header(int slice_qp, int slice_luma_sao_flag, int db_beta_offset_div2, int db_tc_offset_div2,
                         u32 *hdr_data_0, u32 *hdr_data_1, u32 *hdr_data_2, u32 *hdr_data_3, u32 *slice_header_length);
void h265_p_slice_header(int frame_idx, int slice_qp, int slice_luma_sao_flag, int db_beta_offset_div2,
                         int db_tc_offset_div2, u32 *hdr_data_0, u32 *hdr_data_1, u32 *hdr_data_2, u32 *hdr_data_3,
                         u32 *slice_header_length);

#endif
