/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef HW_DRAM_CSR_H_
#define HW_DRAM_CSR_H_

/* clang-format off */
/*
 * ===============================================
 *  Registers for the chip_clock_gen
 * ===============================================
 */
#define DEF_AXI_DRAM   0x80000060
#define DEF_CPU_1      0x80000068
#define DEF_AXI_SYS    0x8000006C

/*
 * ===============================================
 *  Registers for reset_control
 * ===============================================
 */
#define LV_DRAM        0x80000480
#define LV_AXI_DRAMC   0x80000484
/* LV_DRAM reset bits */
#define LV_RST_DDRPHY_DLL   0
#define LV_RST_DDRPHY       1
#define LV_RST_DDRPHY_HDR   2
#define LV_RST_DRAMC_HDR    3
#define LV_RST_APB_DDRPHY   4
#define LV_RST_APB_DRAMC    5
/* LV_AXI_DRAMC reset bits */
#define LV_RST_AXI_DRAMC    0

/*
 * =================================================
 *  Registers for the DWC_ddr_umctl2_map Memory Map
 * =================================================
 */
#define DRAM_CONTROLLER(offset) *((volatile uint32_t *)(0x81860000 + offset))

#define MSTR             0x000
#define STAT             0x004
#define PWRCTL           0x030
#define PWRTMG           0x034
#define HWLPCTL          0x038
#define RFSHCTL0         0x050
#define RFSHCTL3         0x060
#define RFSHTMG          0x064
#define INIT0            0x0D0
#define DIMMCTL          0x0F0
#define CRCPARCTL0       0x0C0
#define DRAMTMG0         0x100
#define DRAMTMG1         0x104
#define DRAMTMG2         0x108
#define DRAMTMG3         0x10C
#define DRAMTMG4         0x110
#define DRAMTMG5         0x114
#define DRAMTMG8         0x120
#define DRAMTMG15        0x13C
#define ZQCTL0           0x180
#define ZQCTL1           0x184
#define DFITMG0          0x190
#define DFITMG1          0x194
#define DFILPCFG0        0x198
#define DFIUPD0          0x1A0
#define DFIUPD1          0x1A4
#define DFIUPD2          0x1A8
#define DFIMISC          0x1B0
#define ADDRMAP1         0x204
#define ADDRMAP2         0x208
#define ADDRMAP3         0x20C
#define ADDRMAP4         0x210
#define ADDRMAP5         0x214
#define ADDRMAP6         0x218
#define ADDRMAP7         0x21C
#define ODTCFG           0x240
#define ODTMAP           0x244
#define SCHED            0x250
#define SCHED1           0x254
#define SCHED2           0x258
#define PERFHPR1         0x25C
#define PERFLPR1         0x264
#define PERFWR1          0x26C
#define DBG0             0x300
#define DBG1             0x304
#define DBGCMD           0x30C
#define SWCTL            0x320
#define SWSTAT           0x324
#define PCCFG            0x400
#define PCFGR_0          0x404
#define PCFGR_1          0x4B4
#define PCFGW_0          0x408
#define PCFGW_1          0x4B8
#define PCTRL_0          0x490
#define PCTRL_1          0x540

#define PCFGQOS0_0       0x494
#define PCFGQOS0_1       0x544
#define PCFGQOS1_0       0x498
#define PCFGQOS1_1       0x548
#define PCFGWQOS0_0      0x49C
#define PCFGWQOS0_1      0x54C
#define PCFGWQOS1_0      0x4A0
#define PCFGWQOS1_1      0x550

/*
 * ===============================================
 *  Registers for DDRPHY
 * ===============================================
 */
#define DDRPHY(offset) *((volatile uint32_t *)(0x81840000 + offset))

#define RIDR             0x000
#define PIR              0x004
#define PGCR             0x008
#define PGSR             0x00C
#define DLLGCR           0x010
#define ACDLLCR          0x014
#define PTR0             0x018
#define PTR1             0x01C
#define PTR2             0x020
#define ACIOCR           0x024
#define DXCCR            0x028
#define DSGCR            0x02C
#define DCR              0x030
#define DTPR0            0x034
#define DTPR1            0x038
#define DTPR2            0x03C
#define MR0              0x040
#define MR1              0x044
#define MR2              0x048
#define MR3              0x04C
#define ODTCR            0x050
#define DTAR             0x054
#define DTDR0            0x058
#define DTDR1            0x05C
#define BISTRR           0x100
#define BISTWCR          0x10C
#define BISTAR0          0x114
#define BISTAR1          0x118
#define BISTAR2          0x11C
#define BISTGSR          0x124
#define BISTWER          0x128
#define ZQ0CR0           0x180
#define ZQ0CR1           0x184
#define ZQ1CR0           0x190
#define DX0GCR           0x1C0
#define DX0DLLCR         0x1CC
#define DX0DQTR          0x1D0
#define DX0DQSTR         0x1D4
#define DX1GCR           0x200
#define DX1DLLCR         0x20C
#define DX1DQTR          0x210
#define DX1DQSTR         0x214

/*
 * ===============================================
 *  Registers for the CPU/DDR PLL
 * ===============================================
 */
#define DDRPLL(offset) *((volatile uint32_t *)(0x80011000 + offset))
#define CPUPLL(offset) *((volatile uint32_t *)(0x80012000 + offset))

#define PLL_ENABLE0            0x00
#define PLL_OVERWRITE_ENABLE   0x04
#define PLL_DIG_EN             0x08
#define PLL_PFD_SEL            0x10
#define PLL_LF_SEL             0x18
#define PLL_LPF_SEL            0x1C
#define PLL_KBAND_SEL          0x20
#define PLL_DIV_SEL            0x24
#define PLL_POST_DIV_SEL       0x28
#define PLL_POSTDIV_CLKIN_SEL  0x2C
#define PLL_MON_CLK_SEL        0x3C

#define DDRPLL_SSCG_F          0x44
#define DDRPLL_REF_CLK_SEL     0x54
#define CPUPLL_REF_CLK_SEL     0x4C

/*
 * ===============================================
 *  Registers for the DRAMCCFG
 * ===============================================
 */
#define DDRCCFG(offset) *((volatile uint32_t *)(0x81310000 + offset))

#define DDRC_IRQ_STA_0  0x000
#define DDRC_IRQ_STA_1  0x004
#define DDRC_IRQ_STA_2  0x008
#define DDRC_IRQ_CLR_0  0x00C
#define DDRC_IRQ_CLR_1  0x010
#define DDRC_IRQ_CLR_2  0x014
#define DDRC_IRQ_MSK_0  0x018
#define DDRC_IRQ_MSK_1  0x01C
#define DDRC_IRQ_MSK_2  0x020
#define DDRC_LP_ENTR    0x04C
#define DDRC_LP_EXIT    0x050
#define DDRC_LP_CFG     0x054
#define DDRC_LP_STA     0x058
#define AXI_LP_ENTR     0x05C
#define AXI_LP_EXIT     0x060
#define AXI_LP_CFG      0x064
#define AXI_LP_STA      0x068
/* clang-format on */

#endif