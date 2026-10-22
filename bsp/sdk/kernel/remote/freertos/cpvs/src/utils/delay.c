#include "delay.h"

/*
 * RTOS only use in Kyoto
 * PLL on: CPU clock 1008 MHz, PLL off: CPU clock 24 MHz
 */
void delay_ns(unsigned int ns)
{
	register unsigned int current = get_cpu_counter();
	register unsigned int left = 0xFFFFFFFFUL - current;
	register unsigned int cycle;
	register unsigned int cval;

	/* cycle = ns * cpu_freq / 1000000000 */
#ifdef CONFIG_FPGA
	unsigned int cpu_freq = CONFIG_CPU_FREQ / 1000000;
#else
	unsigned int cpu_freq = 1008;
#endif

	if (ns > 1000000)
		cycle = (ns / 1000 + 1) * cpu_freq;	// ns > 1ms
	else
		cycle = ns * cpu_freq / 1000 + 1;	// ns < 1ms

	if (left > cycle) {
		cval = current + cycle;
		while(get_cpu_counter() < cval);
	} else {
		cval = cycle - left;
		while(get_cpu_counter() > cval);
		while(get_cpu_counter() < cval);
	}
}
