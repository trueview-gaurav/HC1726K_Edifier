/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef __TRUSTZONE_H__
#define __TRUSTZONE_H__

#define FILTER_0 (1)
#define FILTER_1 (1 << 1)
#define FILTER_2 (1 << 2)
#define FILTER_3 (1 << 3)

struct region_info {
	uint32_t base;
	uint32_t top;
	uint32_t secure; // 0 = non-secure, 1 = secure
};

/* init regions for DA test */
void tz_init(void);

/* @id: is DA id nubmer
 * @secure_mode: 0 is non-secure, 1 is secure
 * @rw: 'r'(read) or 'w'(write)
 */
void tz_set_da_mode(uint32_t id, char rw, uint32_t secure_mode);

/* @region_num should be 0~8
 */
struct region_info tz_get_areas_info(uint32_t region_num);

/* @return: -1 for no error occur, positive value for DA number
 */
int32_t tz_get_err_agent(void);

void abort_init(void *stack_pointer);
void tz_switch_to_secure(void);
void tz_switch_to_nsecure(void);

#endif
