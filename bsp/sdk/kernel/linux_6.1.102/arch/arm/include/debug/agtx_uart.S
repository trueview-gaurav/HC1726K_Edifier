/* arch/arm/mach-imx/include/mach/debug-macro.S
 *
 * Debugging macro include header
 *
 *  Copyright (C) 1994-1999 Russell King
 *  Moved from linux/arch/arm/kernel/debug.S by Ben Dooks
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#if defined(CONFIG_OSAKA)
#define AGTX_DEBUG_UART_PHYS 0x811D0000
#define AGTX_DEBUG_UART_VIRT 0xE11D0000
#elif defined(CONFIG_SAPPORO) || defined(CONFIG_KAMO)
#define AGTX_DEBUG_UART_PHYS 0x80830000
#define AGTX_DEBUG_UART_VIRT 0xE0830000
#else
#define AGTX_DEBUG_UART_PHYS 0x80820000
#define AGTX_DEBUG_UART_VIRT 0xE0820000
#endif

/*
 * FIXME: This is a copy of IMX_IO_P2V in hardware.h, and needs to
 * stay sync with that.  It's hard to maintain, and should be fixed
 * globally for multi-platform build to use a fixed virtual address
 * for low-level debug uart port across platforms.
 */

		.macro	addruart, rp, rv, tmp
		ldr	\rp, =AGTX_DEBUG_UART_PHYS	@ physical
		ldr	\rv, =AGTX_DEBUG_UART_VIRT	@ virtual
		.endm

		.macro	senduart,rd,rx
		str	\rd, [\rx, #0x00]	@ TXDATA
		.endm

                .macro  waituarttxrdy,rd,rx
                .endm

		.macro	busyuart,rd,rx
1002:		ldr	\rd, [\rx, #0x14]	@ LSR
		tst	\rd, #1 << 5		@ THRE
		beq	1002b			@ wait until transmit done
		.endm

