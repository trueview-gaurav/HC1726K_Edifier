#ifndef __DELAY_N_H
#define __DELAY_N_H

#ifndef delay_n
extern inline void __delay_n(uint32_t ns)
{
	/* according to RTL simulation, delay in nano second is the loop count divided by 8 when I$ enabled. */
	asm volatile (
		"add r10, %[__delay_ns], #7\n"
		"mov r10, r10, LSR #3\n"
		"delay_loop_%=:\n"
		"subs r10, r10, #1\n"
		"bne delay_loop_%=\n"
		:
		: [__delay_ns] "r" (ns)
		: "r10", "cc"
		);
}
#define delay_n(x) __delay_n(x)
#endif /* delay_n */

#endif /* __DELAY_N_H */
