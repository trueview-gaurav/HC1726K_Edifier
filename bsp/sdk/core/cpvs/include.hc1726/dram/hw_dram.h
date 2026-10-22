/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef SAPPORO_HW_DRAM_H_
#define SAPPORO_HW_DRAM_H_

#ifndef __KERNEL__
#include <stdint.h>
#endif

#include "autoconf.h"

//DARB setting ====================
#define ROW_BEFORE_BANK 1
#define BANK_GROUP_TYPE 0

#if defined(CONFIG_FPGA)

#if defined(CONFIG_DDR_TYPE_HYPERRAM)
/* FPGA platform VU9P513 use HyperRAM */
#define DDR_TYPE "HYPERRAM"
#define BANK_ADDR_TYPE 0 /* 2 bits */
#define ROW_ADDR_TYPE 0 /* 12 bits */
#define COL_ADDR_TYPE 2 /* 11 bits */
#elif defined(CONFIG_DDR_TYPE_DDR3)
/* FPGA platform VCU118 and VU9P513 use DDR3 */
#define DDR_TYPE "DDR3"
#ifdef CONFIG_OSAKA
#define BANK_ADDR_TYPE 1
#define ROW_ADDR_TYPE 4
#define COL_ADDR_TYPE 3
#elif defined(CONFIG_SAPORO)
#define BANK_ADDR_TYPE 1
#define ROW_ADDR_TYPE 3
#define COL_ADDR_TYPE 2
#endif
#else
#error "The FPGA can only be configured for HyperRAM or DDR3 types"
#endif

#elif defined(CONFIG_DDR_TYPE_DDR2)

#define DDR_TYPE "DDR2"
#if (CONFIG_DRAM_CAPACITY == 32)
#define BANK_ADDR_TYPE 0
#define ROW_ADDR_TYPE 1
#define COL_ADDR_TYPE 1
#elif (CONFIG_DRAM_CAPACITY == 64)
#define BANK_ADDR_TYPE 0
#define ROW_ADDR_TYPE 1
#define COL_ADDR_TYPE 2
#elif (CONFIG_DRAM_CAPACITY == 128)
#define BANK_ADDR_TYPE 1
#define ROW_ADDR_TYPE 1
#define COL_ADDR_TYPE 2
#else
#error "Error CONFIG_DRAM_CAPACITY"
#endif

#elif defined(CONFIG_DDR_TYPE_DDR3)

#define DDR_TYPE "DDR3"
#if (CONFIG_DRAM_CAPACITY == 64)
#define BANK_ADDR_TYPE 1
#define ROW_ADDR_TYPE 0
#define COL_ADDR_TYPE 2
#elif (CONFIG_DRAM_CAPACITY == 128)
#define BANK_ADDR_TYPE 1
#define ROW_ADDR_TYPE 1
#define COL_ADDR_TYPE 2
#elif (CONFIG_DRAM_CAPACITY == 256)
#define BANK_ADDR_TYPE 1
#define ROW_ADDR_TYPE 2
#define COL_ADDR_TYPE 2
#elif (CONFIG_DRAM_CAPACITY == 512)
#define BANK_ADDR_TYPE 1
#define ROW_ADDR_TYPE 3
#define COL_ADDR_TYPE 2
#else
#error "Error CONFIG_DRAM_CAPACITY"
#endif

#elif defined(CONFIG_DDR_TYPE_HYPERRAM)

#define DDR_TYPE "HYPERRAM"
/*
 * In practice, HyperRAM does not need to distinguish between bank, row, or column addressing. 
 * It only requires that the entire address is 25 bits, and that both DARB and DA are 
 * consistently configured the same way.
 */
#if (CONFIG_DRAM_CAPACITY == 32)
#define BANK_ADDR_TYPE 0 /* 2 bits */
#define ROW_ADDR_TYPE 0 /* 12 bits */
#define COL_ADDR_TYPE 2 /* 11 bits */
#else
#error "Error CONFIG_DRAM_CAPACITY"
#endif

#else
#error "Please set DDR type"
#endif /* CONFIG_DRAM_TYPE */

/*
 * Reference bitwidth values from DARB's datasheet
 */
#define MIN_BITWIDTH_BANK 2
#define MAX_BITWIDTH_BANK 3

#define MIN_BITWIDTH_ROW 12
#define MAX_BITWIDTH_ROW 16

#define MIN_BITWIDTH_COL 9
#define MAX_BITWIDTH_COL 12

#if (BANK_ADDR_TYPE == 0) //4-banking
#define BANK_INTERLEAVE_TYPE 2
#elif (BANK_ADDR_TYPE == 1) //8-banking
#define BANK_INTERLEAVE_TYPE 3
#else
#error "Please set DDR type"
#endif

//DDR setting ====================
#if defined(CONFIG_DDR_TYPE_DDR3)
#if defined(CONFIG_FPGA)
#define DDR_DATA_RATE 1700
#elif defined(CONFIG_DRAM_MTS_1600)
#define DDR_DATA_RATE 1600
#elif defined(CONFIG_DRAM_MTS_1333)
#define DDR_DATA_RATE 1333
#elif defined(CONFIG_DRAM_MTS_1066)
#define DDR_DATA_RATE 1066
#else
#error "Only 1600 / 1333 / 1066 MT/s are supported by DDR3 DRAM."
#endif
#elif defined(CONFIG_DDR_TYPE_DDR2)
#if defined(CONFIG_DRAM_MTS_1333)
#define DDR_DATA_RATE 1333
#elif defined(CONFIG_DRAM_MTS_1200)
#define DDR_DATA_RATE 1200
#elif defined(CONFIG_DRAM_MTS_1066)
#define DDR_DATA_RATE 1066
#elif defined(CONFIG_DRAM_MTS_800)
#define DDR_DATA_RATE 800
#else
#error "Only 1333 / 1200 / 1066 / 800 MT/s are supported by DDR2 DRAM."
#endif
#elif defined(CONFIG_DDR_TYPE_HYPERRAM)
#if defined(CONFIG_DRAM_MTS_500)
#define DDR_DATA_RATE 500
#else
#error "Only 500 MT/s are supported by HyperRAM."
#endif
#endif

//========== DDR function========
void hw_darb_init(uint8_t row_addr_type, uint8_t bank_addr_type, uint8_t col_addr_type);
void hw_axiqos_init(void);

#endif /* SAPPORO_HW_DRAM_H_ */
