#ifndef KGD_H_
#define KGD_H_

#include <linux/types.h>

struct kgd_entry {
	bool valid;
	uint8_t	bank_num;
	uint32_t page_size;
};

#endif /* KGD_H_ */
