/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef UTILS_H_
#define UTILS_H_

#ifndef __KERNEL__
#include "printf.h"

/* Hardware independent utilities */

/** dprintf: DEBUG print functions
 *
 *  Only print if DEBUG is defined
 */
#ifdef DEBUG
#define dprintf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define dprintf(...)
#endif

/*
 * Calculate arrary size
 * Note that users *MUST* pass an array rathan than a pointer
 */
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#endif

// Minimum / Maximum
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Bitmask at bit[msb:lsb]
#define BITMASK(msb, lsb) (((msb == 31) && (lsb == 0)) ? (0xFFFFFFFFUL) : (((1 << ((msb) - (lsb) + 1)) - 1) << (lsb)))

#define write_word(addr, word) (*(volatile uint32_t *)(addr) = (word))
#define read_word(addr) (*(volatile uint32_t *)(addr))
#define set_bits_word(addr, bits) (write_word(addr, (read_word(addr) | (bits))))
#define clr_bits_word(addr, bits) (write_word(addr, (read_word(addr) & ~(bits))))

inline void set_val(uintptr_t reg, uint32_t value)
{
	*(volatile uint32_t *)reg = value;
}

inline uint32_t get_val(uintptr_t reg)
{
	return *(volatile uint32_t *)reg;
}

#endif /* UTILS_H_ */
