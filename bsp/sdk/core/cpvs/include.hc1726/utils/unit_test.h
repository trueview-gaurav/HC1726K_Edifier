/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef UNIT_TEST_H_
#define UNIT_TEST_H_

#include "printf.h"
#include <stdint.h>
#include "intc/hw_gic.h"
#include "autoconf.h"
#if defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA)
#include "trustzone/trustzone.h"
#endif

#define __aligned(x) __attribute__((aligned(x)))

#define FAIL "\e[0;91mFAIL\033[0m"
#define OK "\e[0;92mOK\033[0m"

extern char *current_test_module_name;
extern int current_test_id;

#define UNIT_TEST_LOG(fmt, ...) printf("[%s][%d] " fmt "...", current_test_module_name, current_test_id, ##__VA_ARGS__)
#define UNIT_TEST_OK() printf(OK "\n");
#define UNIT_TEST_FAIL() printf(FAIL "\n");

struct unit_test {
	char *name;
	void (*func)(void);
	int id;
};

#define UNIT_TEST_DECLARE(_name, _id, _func)                                            \
	struct unit_test unit_test_##_name##_x_##_id __aligned(4)                       \
	        __attribute__((unused, section(".unit_test_2_" #_name "_x_" #_id))) = { \
		        .name = #_name,                                                 \
		        .func = _func,                                                  \
		        .id = _id,                                                      \
	        };

#define UNIT_TEST_START()                                                                           \
	({                                                                                          \
		static char start[0] __aligned(4) __attribute__((unused, section(".unit_test_1"))); \
		(struct unit_test *)&start;                                                         \
	})

#define UNIT_TEST_END()                                                                           \
	({                                                                                        \
		static char end[0] __aligned(4) __attribute__((unused, section(".unit_test_3"))); \
		(struct unit_test *)&end;                                                         \
	})

#define UNIT_TEST_COUNT()                                    \
	({                                                   \
		struct unit_test *start = UNIT_TEST_START(); \
		struct unit_test *end = UNIT_TEST_END();     \
		unsigned int count = end - start;            \
		count;                                       \
	})

inline void set_val(uintptr_t reg, uint32_t value)
{
	*(volatile uint32_t *)reg = value;
}

inline uint32_t get_val(uintptr_t reg)
{
	return *(volatile uint32_t *)reg;
}

#endif /* UNIT_TEST_H_ */
