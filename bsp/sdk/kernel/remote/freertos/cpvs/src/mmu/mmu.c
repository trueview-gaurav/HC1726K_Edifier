#include <string.h>
#include <stdint.h>


#include "mmu.h"
#include "utils/utils.h"

/* TODO: error code duplicates hw_qspi.h */
/* error code */
#define ESUCCESS 0x0
#define ETIMEOUT 0x1
#define EFAIL 0x2
#define EPAGE 0x3
#define ECHKSUM 0x4
#define EDATA 0x5

/* Register definitions */

/* System Control Register, SCTLR */
#define CPU_SCTLR_C_SET_MASK (1 << 2) // Cache enable bit
#define CPU_SCTLR_M_SET_MASK (1 << 0) // Address translation enable bit

/* Context ID register, CONTEXTIDR */
#define CPU_CONTEXTIDR_PROCID_SET_MASK (0xffffff << 8) // Process ID
#define CPU_CONTEXTIDR_ASID_SET_MASK (0xff << 0) // Address Space ID used by nG L2 translation short-descriptor

/*
 * TTBR0, TTBR1 are process-specific, and switch on context switch
 * Refer to ARMv7 A,R ARM.. B4.1.153
 */

/* Translation Table Control Register, TTBCR */
#define CPU_TTBCR_PD1_SET_MSK (1 << 5)
#define CPU_TTBCR_PD0_SET_MSK (1 << 4)
#define CPU_TTBCR_N_SET_MSK (7 << 0)
#define CPU_TTBCR_N_VALUE_GET(value) (((value) << 0) & CPU_TTBCR_N_SET_MSK)

/* Translation Table Base Register 0, TTBR0 */
#define CPU_TTBR0_TTB0BASE_SET_MSK(ttbcr_n) BITMASK(31, 14 - (ttbcr_n)) // x = (14 - TTBCR.N) with MP Extension
#define CPU_TTBR0_IRGN_0_SET_MASK (1 << 6)
#define CPU_TTBR0_NOS_SET_MSK (1 << 5)
#define CPU_TTBR0_RGN_SET_MSK (3 << 3)
#define CPU_TTBR0_IMP_SET_MSK (1 << 2)
#define CPU_TTBR0_S_SET_MSK (1 << 1)
#define CPU_TTBR0_IRGN_1_SET_MSK (1 << 0)

/* TTBR0[4:3]: Region bits */
#define CPU_TTBR0_RGN_NC (0 << 3) // RGN[1:0] = 00: Normal memory, Outer Non-Cacheable
#define CPU_TTBR0_RGN_WBA (1 << 3) // RGN[1:0] = 01: Normal memory, Outer Write-Back Write-Allocate Cacheable
#define CPU_TTBR0_RGN_WT (2 << 3) // RGN[1:0] = 10: Normal memory, Outer Write-Through Cacheable
#define CPU_TTBR0_RGN_WB (3 << 3) // RGN[1:0] = 11: Normal memory, Outer Write-Back no Write-Allocate Cacheable

/* TTBR0[0,6]: Inner region bits; TTBR0[6] is IGRN[0], and TTBR0[0] IGRN[1] */
#define CPU_TTBR0_IRGN_NC (0 << 0 | 0 << 6) // IRGN[1:0] = 00: Normal memory, Inner Non-Cacheable
#define CPU_TTBR0_IRGN_WBA (0 << 0 | 1 << 6) // IRGN[1:0] = 01: Normal memory, Inner Write-Back Write-Allocate Cacheable
#define CPU_TTBR0_IRGN_WT (1 << 0 | 0 << 6) // IRGN[1:0] = 10: Normal memory, Inner Write-Through Cacheable
#define CPU_TTBR0_IRGN_WB \
	(1 << 0 | 1 << 6) // IRGN[1:0] = 11: Normal memory, Inner Write-Back no Write-Allocate Cacheable

/* Translation Table Base Register 1, TTBR1 */
#define CPU_TTBR1_TTB1BASEADDR_SET_MSK (0x3ffffUL << 14)
#define CPU_TTBR1_IRGN_0_SET_MSK (1 << 6)
#define CPU_TTBR1_NOS_SET_MSK (1 << 5)
#define CPU_TTBR1_RGN_SET_MSK (3 << 3)
#define CPU_TTBR1_IMP_SET_MSK (1 << 2)
#define CPU_TTBR1_S_SET_MSK (1 << 1)
#define CPU_TTBR1_IRGN_1_SET_MSK (1 << 0)

/* Inline functions */

static inline __attribute__((always_inline)) uint32_t __sctlr_get(void)
{
	uint32_t sctlr;
	// Read SCTLR from CP15
	asm("MRC p15, 0, %0, c1, c0, 0" : "=r"(sctlr));
	return sctlr;
}

static inline __attribute__((always_inline)) void __sctlr_set(uint32_t sctlr)
{
	// Write SCTLR to CP15
	asm("MCR p15, 0, %0, c1, c0, 0" : : "r"(sctlr));
}

static inline __attribute__((always_inline)) uint32_t __contextidr_get(void)
{
	uint32_t contextidr;
	// Read CONTEXTIDR from CP15
	asm("MRC p15, 0, %0, c13, c0, 1" : "=r"(contextidr));
	return contextidr;
}

static inline __attribute__((always_inline)) void __contextidr_set(uint32_t contextidr)
{
	// Write CONTEXTIDR to CP15
	asm("MCR p15, 0, %0, c13, c0, 1" : : "r"(contextidr));
}

static inline __attribute__((always_inline)) void __dacr_set(uint32_t dacr)
{
	// Write DACR to CP15
	asm("MCR p15, 0, %0, c3, c0, 0" : : "r"(dacr));
}

/* TTBR* registers */

static inline __attribute__((always_inline)) uint32_t __ttbcr_get(void)
{
	// Read from TTBCR using CP15.
	uint32_t ttbcr;
	asm("MRC p15, 0, %0   , c2, c0, 2" : "=r"(ttbcr));
	return ttbcr;
}

static inline __attribute__((always_inline)) void __ttbcr_set(uint32_t ttbcr)
{
	// Write to TTBCR using CP15.
	asm("MCR p15, 0, %0,    c2, c0, 2" : : "r"(ttbcr));
}

static inline __attribute__((always_inline)) uint32_t __ttbr0_get(void)
{
	// Read the TTBR0 using CP15.
	uint32_t ttbr0;
	asm("MRC p15, 0, %0,    c2, c0, 0" : "=r"(ttbr0));

	return ttbr0;
}

static inline __attribute__((always_inline)) void __ttbr0_set(uint32_t ttbr0)
{
	// Write to TTBR0 using CP15.
	asm("MCR p15, 0, %0,    c2, c0, 0" : : "r"(ttbr0));
}

static inline __attribute__((always_inline)) uint32_t __ttbr1_get(void)
{
	// Read the TTBR1 using CP15.
	uint32_t ttbr1;
	asm("MRC p15, 0, %0,    c2, c0, 1" : "=r"(ttbr1));

	return ttbr1;
}

static inline __attribute__((always_inline)) void __ttbr1_set(uint32_t ttbr1)
{
	// Write to TTBR1 using CP15.
	asm("MCR p15, 0, %0,    c2, c0, 1" : : "r"(ttbr1));
}

/* End of inline functions */

uint32_t mmu_ttbr0_set(const void *addr)
{
	uint32_t ttbcr = __ttbcr_get();
	uint32_t ttbcr_n = CPU_TTBCR_N_VALUE_GET(ttbcr);
	uint32_t ttbr0;

	if ((uint32_t)addr & ~CPU_TTBR0_TTB0BASE_SET_MSK(ttbcr_n)) {
		// addr must align to 2^(14 - TTBCR.N) bytes.
		return -EFAIL;
	}

	// TTBR0 should be inner/outer cacheable with optimized performance
	ttbr0 = CPU_TTBR0_RGN_WBA | CPU_TTBR0_IRGN_WBA;
	ttbr0 &= ~CPU_TTBR0_TTB0BASE_SET_MSK(ttbcr_n);
	ttbr0 |= (uint32_t)addr;

	__ttbr0_set(ttbr0);

	return -ESUCCESS;
}

void *mmu_ttbr0_get(void)
{
	uint32_t ttbcr;
	uint32_t ttbcr_n;
	uint32_t ttbr0;
	ttbcr = __ttbcr_get();
	ttbcr_n = CPU_TTBCR_N_VALUE_GET(ttbcr);

	return (void *)(CPU_TTBR0_TTB0BASE_SET_MSK(ttbcr_n) & ttbr0);
}

uint32_t mmu_ttbr1_set(const void *addr)
{
	uint32_t ttbr1;
	if ((uint32_t)addr & ~CPU_TTBR1_TTB1BASEADDR_SET_MSK) {
		return -EFAIL;
	}

	ttbr1 = __ttbr1_get();
	ttbr1 &= ~CPU_TTBR1_TTB1BASEADDR_SET_MSK;
	ttbr1 |= (uint32_t)addr;

	__ttbr1_set(ttbr1);
	return -ESUCCESS;
}

void *mmu_ttbr1_get(void)
{
	uint32_t ttbr1 = __ttbr1_get();
	return (void *)(CPU_TTBR1_TTB1BASEADDR_SET_MSK & ttbr1);
}

uint32_t mmu_ttbcr_set(const bool ttbr0_walk_enabled, const bool ttbr1_walk_enabled, const uint32_t base_addr_width)
{
	uint32_t ttbcr = 0;

	if (!ttbr0_walk_enabled) {
		ttbcr |= CPU_TTBCR_PD0_SET_MSK;
	}

	if (!ttbr1_walk_enabled) {
		ttbcr |= CPU_TTBCR_PD1_SET_MSK;
	}

	if (base_addr_width > 7) {
		return -EFAIL;
	}

	ttbcr |= base_addr_width;

	__ttbcr_set(ttbcr);

	return -ESUCCESS;
}

uint32_t mmu_dacr_set(const MMU_DAP_E domain_ap[], const uint32_t num)
{
	int i;
	MMU_DAP_E ap;
	uint32_t dacr = 0;

	if (num > 16) {
		return -EFAIL;
	}

	for (i = 0; i < num; ++i) {
		ap = domain_ap[i];
		switch (ap) {
		case MMU_DAP_NO_ACCESS:
		case MMU_DAP_CLIENT:
		case MMU_DAP_MANAGER:
			dacr |= ap << (i * 2);
			break;
		default:
		case MMU_DAP_RESERVED:
			return -EFAIL;
		}
	}

	__dacr_set(dacr);

	return -ESUCCESS;
}

uint32_t mmu_contextidr_set(const uint32_t procid, const uint32_t asid)
{
	uint32_t contextidr;

	if ((procid > 0x00ffffff) || (asid > 0xff)) {
		return -EFAIL;
	}

	contextidr = (procid << 8) | (asid << 0);
	__contextidr_set(contextidr);

	return -ESUCCESS;
}

uint32_t mmu_tlb_invalidate(void)
{
	int dummy = 0;
	asm("MCR p15, 0, %0,    c8, c3, 0" : : "r"(dummy));
	return -ESUCCESS;
}

uint32_t mmu_tlb_invalidate_inner(void)
{
	int dummy = 0;
	asm("MCR p15, 0, %0,    c8, c7, 0\n"
	    "dsb"
	    :
	    : "r"(dummy));
	return -ESUCCESS;
}

uint32_t mmu_disable(void)
{
	uint32_t sctlr = __sctlr_get();
	if (sctlr & CPU_SCTLR_C_SET_MASK) {
		// Data cache is not enabled
		dprintf("[WARN] DCache is still enabled\n");
	}

	sctlr &= ~CPU_SCTLR_M_SET_MASK;
	__sctlr_set(sctlr);

	return -ESUCCESS;
}

uint32_t mmu_enable(void)
{
	uint32_t sctlr;

	mmu_tlb_invalidate();

	sctlr = __sctlr_get();
	sctlr |= CPU_SCTLR_M_SET_MASK;
	__sctlr_set(sctlr);
	return -ESUCCESS;
}

static uint32_t __mmu_l1_ttb_init(uint32_t *ttb_l1)
{
	/* TTBCR.N = 0 (Base address field in TTBR0 is bit[31:14])
	   Therefore L1 TTB must be 16KiB-aligned */
	uint32_t ttbcr_n = 0;
	mmu_ttbcr_set(true, true, ttbcr_n);

	// Verify L1 TTB alignment
	if ((uint32_t)ttb_l1 & ~CPU_TTBR0_TTB0BASE_SET_MSK(ttbcr_n)) {
		return -EFAIL;
	}

	// Initialize L1 TTB memory
	memset(ttb_l1, 0, MMU_TTB1_SIZE);
	return -ESUCCESS;
}

static inline uint32_t mmu_gen_section_entry(uint32_t pa, const struct mmu_mem_region *region)
{
	int tex;
	int c;
	int b;
	if (region->attributes == MMU_ATTR_FAULT) {
		return 0;
	}

	// Decode TEX, C, B
	tex = MMU_ATTR_TO_TEX(region->attributes);
	c = MMU_ATTR_TO_C(region->attributes);
	b = MMU_ATTR_TO_B(region->attributes);

	return (MMU_TTB1_TYPE_SET(MMU_TTB1_TYPE_SECTION) | MMU_TTB1_SECTION_B_SET(b) | MMU_TTB1_SECTION_C_SET(c) |
	        MMU_TTB1_SECTION_XN_SET(region->xn) | MMU_TTB1_SECTION_DOMAIN_SET(0) |
	        MMU_TTB1_SECTION_AP_SET(region->access) | MMU_TTB1_SECTION_TEX_SET(tex) |
	        MMU_TTB1_SECTION_S_SET(region->shareable) | MMU_TTB1_SECTION_NG_SET(0) |
	        MMU_TTB1_SECTION_NS_SET(region->ns) | MMU_TTB1_SECTION_BASE_ADDR_SET(pa >> 20));
}

static uint32_t __mmu_l1_ttb_create(uint32_t *ttb_l1, const struct mmu_mem_region *mem_regions,
                                    const uint32_t num_mem_regions)
{
	int i;
	int ret;

	for (i = 0; i < num_mem_regions; ++i) {
		uint32_t va = (uint32_t)mem_regions[i].va;
		uint32_t pa = (uint32_t)mem_regions[i].pa;
		uint32_t size = mem_regions[i].size;
		uint32_t desc;

		dprintf("Region: %d: va 0x%08x-> pa 0x%08x, size = 0x%08x\n", i, va, pa, size);
		// SECTION: check whether region is 1MiB-aligned
		if ((va & (MMU_SECTION_SIZE - 1)) || (pa & (MMU_SECTION_SIZE - 1)) || (size & (MMU_SECTION_SIZE - 1))) {
			return -EFAIL;
		}

		// SECTION: Use section mapping only
		while (size >= MMU_SECTION_SIZE) {
			desc = mmu_gen_section_entry(pa, &mem_regions[i]);
			// Check whether memory was alreay mapped
			if (ttb_l1[va >> 20] != 0) {
				return -EFAIL;
			}

			ttb_l1[va >> 20] = desc;

			va += MMU_SECTION_SIZE;
			pa += MMU_SECTION_SIZE;
			size -= MMU_SECTION_SIZE;
		}
	}

	return -ESUCCESS;
}

static uint32_t __mmu_l1_ttb_enable(const uint32_t *ttb_l1)
{
	int i;
	int ret;
	MMU_DAP_E domain_ap[16];

	// TTBR0 uses ttb1
	ret = mmu_ttbr0_set((const void *)ttb_l1);
	if (ret != -ESUCCESS) {
		return ret;
	}

	/* On Cortex-A7, simply set all domain ID fields to zero, and set all DACR fields to Client */
	for (i = 0; i < 16; ++i) {
		domain_ap[i] = MMU_DAP_CLIENT;
	}
	ret = mmu_dacr_set(domain_ap, ARRAY_SIZE(domain_ap));
	if (ret != -ESUCCESS) {
		return ret;
	}

	// Enable MMU
	ret = mmu_enable();
	if (ret != -ESUCCESS) {
		dprintf("[ERROR] Failed to enable MMU!\n");
		return ret;
	}

	return -ESUCCESS;
}

uint32_t mmu_init(uint32_t *mmu_l1_ttb, struct mmu_mem_region *mem_regions, int num_mem_regions)
{
	int ret;

	dprintf("Init L1 table\n");
	/* L1 translation table is 16KiB-aligned */
	ret = __mmu_l1_ttb_init(mmu_l1_ttb);
	if (ret != -ESUCCESS) {
		return ret;
	}

	dprintf("Create L1 table\n");
	/* SECTION: required memory of mmu_l1_pt for total translation table */
	ret = __mmu_l1_ttb_create(mmu_l1_ttb, mem_regions, num_mem_regions);
	if (ret != -ESUCCESS) {
		return ret;
	}

	dprintf("Enable MMU\n");
	ret = __mmu_l1_ttb_enable(mmu_l1_ttb);
	if (ret != -ESUCCESS) {
		return ret;
	}

	return -ESUCCESS;
}
