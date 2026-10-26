#ifndef SPL_DEFINE_H_
#define SPL_DEFINE_H_

#include <linux/types.h>

/*********** boot record ********************/
#define SHA256_LEN 32 // (256bit / 8bit) for each byte
#define MODULUS_LEN 256 // 2048-bit modulus
#define SSL_SIGN_LEN 256 // length of signature

typedef struct __attribute__((packed)) boot_record {
	uint8_t img_sign[SSL_SIGN_LEN]; // RSA signature
	uint32_t size; // Currently, this is only for the FreeRTOS image,
	        // to avoid dependency between remote and U-Boot.
	uint32_t padding; // padding to 8 bytes alignment
} BootRecord;

#endif // SPL_DEFINE_H_
