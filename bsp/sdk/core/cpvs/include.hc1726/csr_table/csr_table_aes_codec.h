/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_AES_CODEC_H_
#define CSR_TABLE_AES_CODEC_H_

#include <stdint.h>

CsrFieldEntry csr_field_table_aes_codec[] = {
	// WORD word_frame_start
	{ "frame_start", 0x00000000, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_FRAME_START", 0x00000000, 31, 0, CSR_W1P, 0x00000000 },
	// WORD word_irq_clear
	{ "irq_clear_frame_end", 0x00000004, 0, 0, CSR_W1P, 0x00000000 },
	{ "WORD_IRQ_CLEAR", 0x00000004, 31, 0, CSR_W1P, 0x00000000 },
	// WORD word_status
	{ "status_frame_end", 0x00000008, 0, 0, CSR_RO, 0x00000000 },
	{ "WORD_STATUS", 0x00000008, 31, 0, CSR_RO, 0x00000000 },
	// WORD word_irq_mask
	{ "irq_mask_frame_end", 0x0000000C, 0, 0, CSR_RW, 0x00000001 },
	{ "WORD_IRQ_MASK", 0x0000000C, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_mode
	{ "mode", 0x00000010, 0, 0, CSR_RW, 0x00000000 },
	{ "WORD_MODE", 0x00000010, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_data_swap
	{ "word_swap", 0x00000014, 0, 0, CSR_RW, 0x00000000 },
	{ "byte_swap", 0x00000014, 8, 8, CSR_RW, 0x00000000 },
	{ "WORD_DATA_SWAP", 0x00000014, 31, 0, CSR_RW, 0x00000000 },
	// WORD word_len
	{ "length", 0x00000018, 22, 0, CSR_RW, 0x00000000 },
	{ "WORD_LEN", 0x00000018, 31, 0, CSR_RW, 0x00000000 },
	// WORD cur_length
	{ "ack_i_cnt", 0x0000001C, 22, 0, CSR_RO, 0x00000000 },
	{ "CUR_LENGTH", 0x0000001C, 31, 0, CSR_RO, 0x00000000 },
	// WORD reversed
	{ "reserved", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	{ "REVERSED", 0x00000020, 31, 0, CSR_RW, 0x00000000 },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_AES_CODEC_H_
