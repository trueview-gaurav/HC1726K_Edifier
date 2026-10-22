#ifndef SE_SQ7131_H_
#define SE_SQ7131_H_

#include <stdint.h>

#define APP_MAGIC_NUM \
	"\x58\xeb\x20\xf2\xe5\x8a\xa3\xa4\xca\xff\x3f\x22\x3a\xbc\xb2\xf8\xb6\xc2\x72\xb2\x88\xbe\x95\x7d\x74\xf4\x26\xea\xb2\x24\x23\x80"

#define SLOT_8 8 // SE secret key, write only
#define SLOT_8_LEN 32
#define SLOT_22 22 // IO protection key, write only
#define SLOT_22_LEN 32
#define SLOT_36 36 // 32 bytes, general data
#define SLOT_36_LEN 32
#define SLOT_37 37 // 32 bytes, general data

#define COUNTER_INCREASE ((uint8_t)0x01)
#define COUNTER_READ ((uint8_t)0x00)
#define COUNTERS_ONE ((uint8_t)0x00)
#define COUNTERS_TWO ((uint8_t)0x01)
#define COUNTER_OUT_SIZE 4

typedef struct meta_data {
	uint8_t i2c_bus_id;
	uint8_t counter_id;
	uint8_t slot_id;
	uint32_t desired_counter_val;
	char *f_product_id;
	char *f_device_id;
	char *f_device_secret;
	char *f_encrypted_device_secret;
} Meta_data;

typedef enum {
	CASE_DEVICE_SECRET_FLASH = 0,
	CASE_DECRYPTED_DEVICE_SECRET_FLASH,
	CASE_DEVICE_SECRET_SE,
	CASE_AUTHENTICATION,
	CASE_SECURE_STORAGE_PROVISION,
	CASE_UID,
	CASE_COUNTER_READ,
	CASE_COUNTER_INCREASE,
	CASE_LOCK_SLOT,
	CASE_SLOT_STATUS,
	CASE_RNG_STARTUP_TEST,
	CASE_NUM
} CaseType;

int SE_executeDemo(const CaseType case_type, const Meta_data meta_data);

#endif /* SE_SQ7131_H_ */
