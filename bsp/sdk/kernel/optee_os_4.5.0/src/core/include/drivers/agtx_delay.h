/*
* Copyright Augentix Inc. Proprietary and confidential.
* Unauthorized use or distribution is prohibited.
* Please contact customer.support@augentix.com for any inquiries.
*/

#ifndef __DELAY_H_
#define __DELAY_H_

enum pll_status {
	PLL_OFF = 0,
	PLL_ON = 1,
};

static inline unsigned int get_cpu_counter(void)
{
	unsigned int cvall, cvalh;
	asm volatile("mrrc p15, 0, %0, %1, c14" : "=r"(cvall), "=r"(cvalh));
	return cvall;
}

/** delay_ns: use cpu built-in counter to delay
 * using this method, delay time won't be affect when cache is enabled
 * Maximum delay time limit depends on cpu counter and frequency
 * Ex: (max cpu counter value - 1) / (max cpu frequency) = (2^32 - 1) / 1008MHz = 4.26s
 */
void delay_ns(unsigned int ns);

#endif /* __DELAY_H_ */
