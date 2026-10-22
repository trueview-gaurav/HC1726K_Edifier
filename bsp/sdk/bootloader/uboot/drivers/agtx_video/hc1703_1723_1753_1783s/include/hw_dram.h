#ifndef AGTX_VIDEO_HW_DRAM_H
#define AGTX_VIDEO_HW_DRAM_H

#ifndef __KERNEL__
#include <stdint.h>
#endif
#include "config.h"

//DARB setting ====================
#define ROW_BEFORE_BANK 1
#define BANK_GROUP_TYPE 0

#if defined(CONFIG_DDR_TYPE_DDR2)
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
#else
#error "Please set DDR type"
#endif /* CONFIG_DRAM_TYPE */

#if (BANK_ADDR_TYPE == 0) //4-banking
#define BANK_INTERLEAVE_TYPE 2
#elif (BANK_ADDR_TYPE == 1) //8-banking
#define BANK_INTERLEAVE_TYPE 3
#else
#error "Please set DDR type"
#endif

#endif /* AGTX_VIDEO_HW_DRAM_H */
