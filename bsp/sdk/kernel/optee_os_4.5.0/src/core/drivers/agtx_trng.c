/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <io.h>
#include <kernel/mutex.h>
#include <kernel/panic.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mm/core_mmu.h>
#include <mm/core_memprot.h>
#include <rng_support.h>
#include <tee/tee_cryp_utl.h>
#include <drivers/agtx_delay.h>

#define RNG_BASE 0x80880000
#define RNG_REG_SIZE 0x50

#define TRNG_EN 0x04
#define RG_TRNG_OUT 0x08
#define RG_TRNG_OUT_1 0x0C
#define IRQ_ST 0x14
#define IRQ_CLR 0x18
#define OP_CONFIG 0x20

#define APT_WINDOW_SIZE 512
#define APT_CUTOFF 25
#define RCT_CUTOFF 5

static mbedtls_entropy_context entropy;
static mbedtls_ctr_drbg_context ctr_drbg;
static struct mutex drbg_lock = MUTEX_INITIALIZER;
static vaddr_t rng;

static uint8_t rct_byte = 0, apt_byte = 0;
static size_t rct_repeat_count = 0, apt_repeat_count = 0;
static size_t apt_index = 0;

union TRNG_out {
	uint32_t value_u32[2];
	uint8_t value_u8[2][4];
};

void clear_irq(void);
void get_trng(void);
bool rct_test(uint8_t byte);
bool apt_test(uint8_t byte);
int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen);

register_phys_mem_pgdir(MEM_AREA_IO_SEC, RNG_BASE, RNG_REG_SIZE);

void clear_irq(void)
{
	io_write32(rng + IRQ_CLR, 0x00000001);
	delay_ns(3000);
}

void get_trng(void)
{
	io_write32(rng + OP_CONFIG, 0x00000100);

	io_write32(rng, 0x00000001);
	while (io_read32(rng + IRQ_ST) != 0x00000001) {
	}

	clear_irq();
}

bool rct_test(uint8_t byte)
{
	if (byte == rct_byte) {
		rct_repeat_count++;
		if (rct_repeat_count >= RCT_CUTOFF) {
			EMSG("RCT test failed: byte 0x%02x repeated %zu times", byte, rct_repeat_count);
			return false;
		}
	} else {
		rct_byte = byte;
		rct_repeat_count = 1;
	}

	return true;
}

bool apt_test(uint8_t byte)
{
	if (apt_index == 0) {
		apt_byte = byte;
		apt_repeat_count = 1;
	} else {
		if (byte == apt_byte)
			apt_repeat_count++;
	}

	apt_index++;
	if (apt_index == APT_WINDOW_SIZE)
		apt_index = 0;

	if (apt_repeat_count >= APT_CUTOFF) {
		EMSG("APT failed: byte 0x%02x appeared %zu times in APT window", apt_byte, apt_repeat_count);
		return false;
	}
	return true;
}

int mbedtls_hardware_poll(void *data, unsigned char *output, size_t len, size_t *olen)
{
	union TRNG_out trng_out;
	unsigned char byte;

	(void)data;

	if (len > INT_MAX)
		return TEE_ERROR_BAD_PARAMETERS;

	for (int i = 0; i < (int)len / 8; i++) {
		trng_out.value_u32[0] = 0;
		trng_out.value_u32[1] = 0;
		byte = 0;

		// A
		io_write32(rng + TRNG_EN, 0x00000011);
		get_trng();
		trng_out.value_u32[0] ^= io_read32(rng + RG_TRNG_OUT);
		trng_out.value_u32[1] ^= io_read32(rng + RG_TRNG_OUT_1);

		// D_0
		io_write32(rng + TRNG_EN, 0x00000111);
		get_trng();
		trng_out.value_u32[0] ^= io_read32(rng + RG_TRNG_OUT);
		trng_out.value_u32[1] ^= io_read32(rng + RG_TRNG_OUT_1);

		// D_1
		io_write32(rng + TRNG_EN, 0x00001111);
		get_trng();
		trng_out.value_u32[0] ^= io_read32(rng + RG_TRNG_OUT);
		trng_out.value_u32[1] ^= io_read32(rng + RG_TRNG_OUT_1);

		// D_2
		io_write32(rng + TRNG_EN, 0x00002111);
		get_trng();
		trng_out.value_u32[0] ^= io_read32(rng + RG_TRNG_OUT);
		trng_out.value_u32[1] ^= io_read32(rng + RG_TRNG_OUT_1);

		// D_3
		io_write32(rng + TRNG_EN, 0x00003111);
		get_trng();
		trng_out.value_u32[0] ^= io_read32(rng + RG_TRNG_OUT);
		trng_out.value_u32[1] ^= io_read32(rng + RG_TRNG_OUT_1);

		// order: 3 2 1 0 7 6 5 4
		for (int j = 0; j < 2; j++) {
			for (int k = 3; k >= 0; k--) {
				byte = trng_out.value_u8[j][k];

				if (!rct_test(byte) || !apt_test(byte)) {
					*olen = 0;
					return MBEDTLS_ERR_ENTROPY_SOURCE_FAILED;
				}

				output[(*olen)++] = byte;
			}
		}
	}

	return 0;
}

TEE_Result hw_get_random_bytes(void *buf, size_t len)
{
	TEE_Result ret;

	mutex_lock(&drbg_lock);
	ret = mbedtls_ctr_drbg_random(&ctr_drbg, buf, len);
	mutex_unlock(&drbg_lock);

	return ret == 0 ? TEE_SUCCESS : TEE_ERROR_GENERIC;
}

void plat_rng_init(void)
{
	rng = (vaddr_t)phys_to_virt(RNG_BASE, MEM_AREA_IO_SEC, RNG_REG_SIZE);

	mbedtls_entropy_init(&entropy);
	mbedtls_ctr_drbg_init(&ctr_drbg);

	if (mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, NULL, 0) != 0) {
		EMSG("DRBG seed failed");
		panic();
	}
}
