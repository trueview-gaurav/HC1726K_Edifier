#ifndef MMU_H_
#define MMU_H_

/*
 * AUGENTIX INC. - PROPRIETARY AND CONFIDENTIAL
 *
 * mmu.h - Cortex-A7 MMU management API
 * Copyright (C) 2020 ShihChieh Lin, Augentix Inc. <shihchieh.lin@augentix.com>
 *
 * NOTICE: The information contained herein is the property of Augentix Inc.
 * Unauthorized copying and distributing of this file, via any medium,
 * is strictly prohibited.
 *
 */

/*
 * The following page mapping description and attributes conform to ARMv7 A,R ARM. B3.5.
 *
 * Here we only apply short-descriptor first-level descriptor format, where PXN = 0.
 */

#include <stdbool.h>

/* Access permission (AP) */
typedef enum mmu_ap_e {
	MMU_AP_NO_ACCESS = 0,
	MMU_AP_PRIV_ACCESS = 1,
	MMU_AP_USER_READ_ONLY = 2,
	MMU_AP_FULL_ACCESS = 3,
	MMU_AP_PRIV_READ_ONLY = 5,
	MMU_AP_READ_ONLY = 7
} MMU_AP_E;

/* Domain Access Permission */
typedef enum mmu_dap_e {
	MMU_DAP_NO_ACCESS = 0,
	MMU_DAP_CLIENT = 1,
	MMU_DAP_RESERVED = 2, /* not used */
	MMU_DAP_MANAGER = 3,
} MMU_DAP_E;

/* Shareable (S) */
typedef enum mmu_ttb_s_e { MMU_TTB_S_NON_SHAREABLE = 0, MMU_TTB_S_SHAREABLE = 1 } MMU_TTB_S_E;

/* Execute Never (XN) */
typedef enum mmu_ttb_xn_e {
	MMU_TTB_XN_DISABLE = 0, // Can execute/fetch instruction from the region
	MMU_TTB_XN_ENABLE = 1, // Cannot execute/fetch instruction from the region
} MMU_TTB_XN_E;

/* Security state */
typedef enum mmu_ns_e {
	MMU_TTB_NS_SECURE = 0,
	MMU_TTB_NS_NON_SECURE = 1,
} MMU_TTB_NS_E;

/*
 * L1 Translation Table memory region attributes TEX[2:0] (C, B)
 * Refer to Table B3-10, ARMv7 A,R ARM.
 *
 * Attribute encoding rule:
 *
 * | TEX | C | B | Description                                       |
 * |:----|:--|:--|:--------------------------------------------------|
 * | 000 | 0 | 0 | Strongly-Ordered                                  |
 * | 000 | 0 | 1 | Shareable Device                                  |
 * | 000 | 1 | 0 | Inner/Outer Write-Through                         |
 * | 000 | 1 | 1 | Inner/Outer Write-Back, no Write Allocate         |
 * | 001 | 0 | 0 | Inner/Outer Non-Cacheable                         |
 * | 001 | 0 | 1 | Reserved                                          |
 * | 001 | 1 | 0 | Reserved                                          |
 * | 001 | 1 | 1 | Inner/Outer Write-Back, Write Allocate            |
 * | 010 | 0 | 0 | Non-Shareable Device                              |
 * | 010 | 0 | 1 | Reserved                                          |
 * | 010 | 1 | 0 | Reserved                                          |
 * | 010 | 1 | 1 | Reserved                                          |
 * | 1BB | A | A | Cached where AA = Inner Policy, BB = Outer Policy |
 *
 * AA, BB attribute encoding rule:
 *
 * | Encoding | Cache attribute               |
 * |:---------|:------------------------------|
 * | 00       | Non-Cacheable                 |
 * | 01       | Write-Back, Write-Allocate    |
 * | 10       | Write-Through                 |
 * | 11       | Write-Back, no Write-Allocate |
 */

/* Attributes encoded; bit[6:4]:TEX, bit[1]:C, bit[0]:B */
typedef enum mmu_attr_e {

	MMU_ATTR_STRONG = 0x00,
	MMU_ATTR_DEVICE = 0x01,
	MMU_ATTR_WT = 0x02,
	MMU_ATTR_WB = 0x03,
	MMU_ATTR_NC = 0x10,
	MMU_ATTR_WBA = 0x13,
	MMU_ATTR_DEVICE_NS = 0x20,

	MMU_ATTR_NC_NC = 0x40,
	MMU_ATTR_NC_WBA = 0x50,
	MMU_ATTR_NC_WT = 0x60,
	MMU_ATTR_NC_WB = 0x70,

	MMU_ATTR_WBA_NC = 0x41,
	MMU_ATTR_WBA_WBA = 0x51,
	MMU_ATTR_WBA_WT = 0x61,
	MMU_ATTR_WBA_WB = 0x71,

	MMU_ATTR_WT_NC = 0x42,
	MMU_ATTR_WT_WBA = 0x52,
	MMU_ATTR_WT_WT = 0x62,
	MMU_ATTR_WT_WB = 0x72,

	MMU_ATTR_WB_NC = 0x43,
	MMU_ATTR_WB_WBA = 0x53,
	MMU_ATTR_WB_WT = 0x63,
	MMU_ATTR_WB_WB = 0x73,

	MMU_ATTR_FAULT = 0xff

} MMU_ATTR_E;

// bit [1:0] of L1 translation table entry
#define MMU_TTB1_TYPE_FAULT 0
#define MMU_TTB1_TYPE_L2_DESC 1
#define MMU_TTB1_TYPE_SECTION 2
#define MMU_TTB1_TYPE_SUPERSECTION 2

/* Size of L1 and L2 translation tables */
#define MMU_TTB1_CNT 4096 // 4096 entries for a L1 translation table
#define MMU_TTB1_SIZE (MMU_TTB1_CNT << 2)

#define MMU_TTB2_CNT 256 // 256 entries for a L2 translation table
#define MMU_TTB2_SIZE (MMU_TTB2_CNT << 2)

/*
 * | Translation  | Size  |
 * |:-------------|:------|
 * | Supersection | 16MiB |
 * | Section      | 1MiB  |
 * | Large page   | 64KiB |
 * | Small page   | 4KiB  |
 */

#define MMU_SUPERSECTION_SIZE (1UL << 24)
#define MMU_SECTION_SIZE (1UL << 20)
#define MMU_LARGE_PAGE_SIZE (1UL << 16)
#define MMU_SMALL_PAGE_SIZE (1UL << 12)

/* MMU translation table management */

/* Type of L1 translation table entry */
#define MMU_TTB1_TYPE_MASK (0x00000003)
#define MMU_TTB1_TYPE_GET(desc) (((desc)&MMU_TTB1_TYPE_MASK) >> 0)
#define MMU_TTB1_TYPE_SET(val) (((val) << 0) & MMU_TTB1_TYPE_MASK)

/* Section Entry */

/* Base address bits of L1 SECTION */
#define MMU_TTB1_SECTION_BASE_ADDR_MASK (0xfff00000)
#define MMU_TTB1_SECTION_BASE_ADDR_GET(desc) (((desc)&MMU_TTB1_SECTION_BASE_ADDR_MASK) >> 20)
#define MMU_TTB1_SECTION_BASE_ADDR_SET(val) (((val) << 20) & MMU_TTB1_SECTION_BASE_ADDR_MASK)

/* Non-Secure (NS) bit of L1 SECTION */
/* SBZ in Cortex-A7 */
#define MMU_TTB1_SECTION_NS_MASK (0x00080000)
#define MMU_TTB1_SECTION_NS_GET(desc) (((desc)&MMU_TTB1_SECTION_NS_MASK) >> 19)
#define MMU_TTB1_SECTION_NS_SET(val) (((val) << 19) & MMU_TTB1_SECTION_NS_MASK)

/* Non-Global (nG) bit of L1 SECTION */
#define MMU_TTB1_SECTION_NG_MASK (0x00020000)
#define MMU_TTB1_SECTION_NG_GET(desc) (((desc)&MMU_TTB1_SECTION_NG_MASK) >> 17)
#define MMU_TTB1_SECTION_NG_SET(val) (((val) << 17) & MMU_TTB1_SECTION_NG_MASK)

/* Shareable (S) bit of L1 SECTION */
#define MMU_TTB1_SECTION_S_MASK (0x00010000)
#define MMU_TTB1_SECTION_S_GET(desc) (((desc)&MMU_TTB1_SECTION_S_MASK) >> 16)
#define MMU_TTB1_SECTION_S_SET(val) (((val) << 16) & MMU_TTB1_SECTION_S_MASK)

/* TEX bit of L1 SECTION */
#define MMU_TTB1_SECTION_TEX_MASK (0x00007000)
#define MMU_TTB1_SECTION_TEX_GET(desc) (((desc)&MMU_TTB1_SECTION_TEX_MASK) >> 12)
#define MMU_TTB1_SECTION_TEX_SET(val) (((val) << 12) & MMU_TTB1_SECTION_TEX_MASK)

/* Access Permission (APX, AP) bits of L1 SECTION */
#define MMU_TTB1_SECTION_AP_MASK (0x00008c00)
#define MMU_TTB1_SECTION_AP_GET(desc) ((((desc)&0x00008000) >> 13) | (((desc & 0x00000c00) >> 10)))
#define MMU_TTB1_SECTION_AP_SET(val) ((((val) << 13) & 0x00008000) | ((val) << 10) & 0x00000c00)

/* Domain (DOMAIN) bit of L1 SECTION */
#define MMU_TTB1_SECTION_DOMAIN_MASK (0x000001e0)
#define MMU_TTB1_SECTION_DOMAIN_GET(desc) (((desc)&MMU_TTB1_SECTION_DOMAIN_MASK) >> 5)
#define MMU_TTB1_SECTION_DOMAIN_SET(val) (((val) << 5) & MMU_TTB1_SECTION_DOMAIN_MASK)

/* Execute-Never (XN) bit of L1 SECTION */
#define MMU_TTB1_SECTION_XN_MASK (0x00000010)
#define MMU_TTB1_SECTION_XN_GET(desc) (((desc)&MMU_TTB1_SECTION_XN_MASK) >> 4)
#define MMU_TTB1_SECTION_XN_SET(val) (((val) << 4) & MMU_TTB1_SECTION_XN_MASK)

/* C bit of L1 SECTION */
#define MMU_TTB1_SECTION_C_MASK (0x00000008)
#define MMU_TTB1_SECTION_C_GET(desc) (((desc)&MMU_TTB1_SECTION_C_MASK) >> 3)
#define MMU_TTB1_SECTION_C_SET(val) (((val) << 3) & MMU_TTB1_SECTION_C_MASK)

/* B bit of L1 SECTION */
#define MMU_TTB1_SECTION_B_MASK (0x00000004)
#define MMU_TTB1_SECTION_B_GET(desc) (((desc)&MMU_TTB1_SECTION_B_MASK) >> 2)
#define MMU_TTB1_SECTION_B_SET(val) (((val) << 2) & MMU_TTB1_SECTION_B_MASK)

/* L1 translation table: Fault entry */
struct mmu_ttb1_fault_entry {
	uint32_t type : 2;
	uint32_t : 30;
};

/* L1 translation table: Section entry */
struct mmu_ttb1_section_entry {
	uint32_t type : 2;
	uint32_t b : 1;
	uint32_t c : 1;
	uint32_t xn : 1;
	uint32_t domain : 4;
	uint32_t : 1;
	uint32_t ap : 2; // AP[1:0]
	uint32_t tex : 3;
	uint32_t apx : 1; // AP[2]
	uint32_t s : 1;
	uint32_t ng : 1;
	uint32_t : 1;
	uint32_t ns : 1; // SBZ in Cortex-A7
};

/* MMU APIs */

/* Initialize L1 translation table memory block */
uint32_t mmu_ttb_l1_init(uint32_t *ttb_l1);

/*
 * mmu_ttb_l1_entry_set: Set L1 translation table entries for VA mapping
 *
 * @ttb_l1: Base address of L1 translation table
 * @va:     Virtual address of L1 translation table entry to set the value; 1MiB aligned for section entries
 * @entry:  Short-descriptor value to apply for the given virtual address @va.
 */
uint32_t mmu_ttb_l1_entry_set(uint32_t *ttb_l1, const void *va, const uint32_t entry);

uint32_t mmu_enable(void);
uint32_t mmu_disable(void);

uint32_t mmu_ttbr0_set(const void *addr);
void *mmu_ttbr0_get(void);

uint32_t mmu_ttbr1_set(const void *addr);
void *mmu_ttbr1_get(void);

uint32_t mmu_ttbcr_set(const bool ttbr0_walk_enabled, const bool ttbr1_walk_enabled, const uint32_t base_addr_width);

/* Set access permissions of 16 Domain Access Control Register fields */
uint32_t mmu_dacr_set(const MMU_DAP_E dap[], const uint32_t num);

uint32_t mmu_contextidr_set(const uint32_t procid, const uint32_t asid);

/* Invalidate the entire unified TLB */
uint32_t mmu_tlb_invalidate(void);

/* Invalidate the entire unified TLB in the Inner shareability domain */
uint32_t mmu_tlb_invalidate_inner(void);

struct mmu_mem_region {
	void *va;
	void *pa;
	uint32_t size;

	MMU_AP_E access;
	MMU_ATTR_E attributes;
	MMU_TTB_S_E shareable;
	MMU_TTB_XN_E xn;
	MMU_TTB_NS_E ns;
};
#define MMU_ATTR_TO_TEX(attr) (((attr) >> 4) & 0x7)
#define MMU_ATTR_TO_C(attr) (((attr) >> 1) & 0x1)
#define MMU_ATTR_TO_B(attr) (((attr) >> 0) & 0x1)

/* Initializes processor MMU */
uint32_t mmu_init(uint32_t *mmu_l1_ttb, struct mmu_mem_region *mem_regions, int num_mem_regions);

#endif /* MMU_H */
