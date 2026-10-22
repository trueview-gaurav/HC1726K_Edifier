#ifndef NVSP_MACH_H
#define NVSP_MACH_H
void disable_i_cache(void);

int nvsp_mach_nvsp_init(BaudRateType arg);
void machine_uart_init();

#ifdef CONFIG_DRAM_GENERIC_DDR3L
#define DDR_NAME "Generic DDR3"
#elif defined(CONFIG_DRAM_GENERIC_DDR2)
#define DDR_NAME "Generic DDR2"
#elif defined(CONFIG_DRAM_GENERIC_HYPERRAM)
#define DDR_NAME "Generic HYPERRAM"
#elif defined(CONFIG_DRAM_OPTIMIZE_NT5CC128M16JR)
#define DDR_NAME "NT5CC128M16JR"
#elif defined(CONFIG_DRAM_OPTIMIZE_NT5CC64M16GP)
#define DDR_NAME "NT5CC64M16GP"
#elif defined(CONFIG_DRAM_OPTIMIZE_M15T2G16128A)
#define DDR_NAME "M15T2G16128A"
#elif defined(CONFIG_DRAM_OPTIMIZE_M15T1G1664A)
#define DDR_NAME "M15T1G1664A"
#endif

#endif /* NVSP_MACH_H */
