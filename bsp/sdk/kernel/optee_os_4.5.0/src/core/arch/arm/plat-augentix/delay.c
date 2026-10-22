/*
* Copyright Augentix Inc. Proprietary and confidential.
* Unauthorized use or distribution is prohibited.
* Please contact customer.support@augentix.com for any inquiries.
*/

#include <drivers/agtx_delay.h>

/*
 * Currently only support HC1706
 * PLL on: CPU clock 891 MHz, PLL off: CPU clock 24 MHz
 */
void delay_ns(unsigned int ns)
{
	register unsigned int current = get_cpu_counter();
	register unsigned int left = 0xFFFFFFFFUL - current;
	register unsigned int cycle;
	register unsigned int cval;

#ifdef defined(CONFIG_FPGA)
	unsigned int cpu_freq = CONFIG_CPU_FREQ / 1000000;
#elif defined(CONFIG_CPU_LOW_SPEED)
	unsigned int cpu_freq = 450;
#else
	unsigned int cpu_freq = 891;
#endif

	if (ns > 1000000)
		cycle = (ns / 1000 + 1) * cpu_freq; // ns > 1ms
	else
		cycle = ns * cpu_freq / 1000 + 1; // ns < 1ms

	if (left > cycle) {
		cval = current + cycle;
		while (get_cpu_counter() < cval)
			;
	} else {
		cval = cycle - left;
		while (get_cpu_counter() > cval)
			;
		while (get_cpu_counter() < cval)
			;
	}
}
