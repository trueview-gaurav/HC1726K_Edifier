/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef KYOTO_JPEG_H_
#define KYOTO_JPEG_H_

#include "enc.h"

#define ENC_AANSCALE_SHIFT_BIT 14
#define ENC_JPEG_Q_TABLE_ROW_NUM 8
#define ENC_JPEG_Q_TABLE_ELE_NUM 16
#define ENC_JPEG_DCT_SIZE 64
#define ENC_JPEG_PAR_TABLE_ELE_NUM (ENC_JPEG_DCT_SIZE * 2)
#define ENC_JPEG_PAR_LOOP_CNT (ENC_JPEG_PAR_TABLE_ELE_NUM >> 2)

typedef struct enc_jpeg_table {
	int par[ENC_JPEG_PAR_TABLE_ELE_NUM];
	u32 luma_qt[ENC_JPEG_Q_TABLE_ELE_NUM];
	u32 chroma_qt[ENC_JPEG_Q_TABLE_ELE_NUM];
} EncJpegTable;

static const u16 g_enc_jpeg_std_luma_q_table[ENC_JPEG_DCT_SIZE] = {
	16, 11,  10,  16, 24, 40, 51, 61, 12,  12,  14,  19,  26, 58, 60, 55,  14,  13,  16,  24, 40, 57,
	69, 56,  14,  17, 22, 29, 51, 87, 80,  62,  18,  22,  37, 56, 68, 109, 103, 77,  24,  35, 55, 64,
	81, 104, 113, 92, 49, 64, 78, 87, 103, 121, 120, 101, 72, 92, 95, 98,  112, 100, 103, 99,
};

static const u16 g_enc_jpeg_std_chroma_q_table[ENC_JPEG_DCT_SIZE] = {
	17, 18, 24, 47, 99, 99, 99, 99, 18, 21, 26, 66, 99, 99, 99, 99, 24, 26, 56, 99, 99, 99,
	99, 99, 47, 66, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
	99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
};

static const s16 g_enc_jpeg_aanscales[ENC_JPEG_DCT_SIZE] = {
	/* precomputed values scaled up by 14 bits */
	16384, 22725, 21407, 19266, 16384, 12873, 8867,  4520, 22725, 31521, 29692, 26722, 22725, 17855, 12299, 6270,
	21407, 29692, 27969, 25172, 21407, 16819, 11585, 5906, 19266, 26722, 25172, 22654, 19266, 15137, 10426, 5315,
	16384, 22725, 21407, 19266, 16384, 12873, 8867,  4520, 12873, 17855, 16819, 15137, 12873, 10114, 6967,  3552,
	8867,  12299, 11585, 10426, 8867,  6967,  4799,  2446, 4520,  6270,  5906,  5315,  4520,  3552,  2446,  1247,
};

EncJpegTable g_q_table = { { 0 } };

#endif
