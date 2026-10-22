/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

//char memory[20000];

struct block {
	int size;
	int free;
	struct block *next;
};

void initialize();
void split(struct block *fitting_slot, int size);
void *bm_malloc(int noOfBytes);
void *memcpy(void *dest, const void *src, unsigned int len);
void *memset(void *dest, int val, unsigned int len);

void merge();
void free(void *ptr);