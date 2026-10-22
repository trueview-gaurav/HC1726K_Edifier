#ifndef SETPROGRESS_H_
#define SETPROGRESS_H_

#define DBG_ADDR 0x8000009C // PC.CK RESV_0 on Kyoto
#define RESV2_ADDR 0x800000A4 // PC.CK RESV_2 on Kyoto
#define ac_addr(addr) *((volatile uint32_t *)addr)

#if !FPGA_TEST // def DEBUG we always use this value to debug
#define set_progress(i)                                                                                                \
	do {                                                                                                           \
		*(volatile uint32_t *)(DBG_ADDR) = i;                                                                  \
	} while (0);
#else
#include "printf.h"
#define set_progress(i) printf("set_progress: 0x%X(%d)\n", i, i);
#endif

enum progress_state {
	STATE_BEGIN = 0X0,
	STATE_SET_PLL = 0X1,
	STATE_SET_DRAM = 0X2,
	STATE_SWITCH_CLK_SRC = 0X3,
	STATE_CHANGE_PROG = 0X4,
	STATE_PROGRAM_END = 0xF,
};

#endif