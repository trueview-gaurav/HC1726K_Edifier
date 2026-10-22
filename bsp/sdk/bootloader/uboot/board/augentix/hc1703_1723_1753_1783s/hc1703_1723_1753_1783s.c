/*
 * (C) Copyright 2017-2018  Augentix Inc.
 * ShihChieh Lin, Augentix Inc., <shihchieh.lin@augentix.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <environment.h>
#include <malloc.h>
#include <asm/io.h>

#if defined(CONFIG_RESET_PHY_R) && defined(CONFIG_MACB)
#include <net.h>
#endif
#include <netdev.h>
#include <miiphy.h>
#include <div64.h>
#include <asm-generic/gpio.h>
#include <dwmmc.h>
#include "agtx_early_amp.h"
#ifdef CONFIG_EFUSE_FSM_AUTOBURN
#include "efuse_burn_fsm.h"
#endif

DECLARE_GLOBAL_DATA_PTR;

/* ------------------------------------------------------------------------- */
/*
 * Miscelaneous platform dependent initialisations
 */
extern int eqos_emac_initialize(u32 interface);

#ifdef CONFIG_EARLYVIDEO
extern void agtx_video_set_env(void);
#endif
#if (defined(CONFIG_SAPPORO) && defined(CONFIG_EARLYAUDIO))
extern void earlyaudio_set_env(void);
#endif

#ifdef CONFIG_GENERIC_MMC
int board_mmc_init(bd_t *bd)
{
	struct dwmci_host *host = NULL;

	host = malloc(sizeof(struct dwmci_host));
	if (!host) {
		printf("dwmci_host malloc fail!\n");
		return 1;
	}

	memset(host, 0, sizeof(struct dwmci_host));
#if (defined(CONFIG_SAPPORO) || defined(CONFIG_OSAKA) || defined(CONFIG_KAMO))
	u32 csr = readl(SDC_GPI_SEL_BASE);
#ifdef CONFIG_EMMC
	csr = (csr & 0xffff00ff) | (63 << 8); // Set SDC0 CD to GPIO63 (default: 63)
#else
	csr = (csr & 0xffff00ff) | (CONFIG_SDC_CD_GPIO << 8);
#endif
	writel(csr, SDC_GPI_SEL_BASE); // Set SDC0 CD
#endif
	host->name = "Synopsys Mobile storage";
	host->ioaddr = (void *)SDC0_BASE;
#if (CONFIG_AGTX_MMC_BMODE == 4)
	host->buswidth = 4;
#else //CONFIG_AGTX_MMC_BMODE == 1
	host->buswidth = 1;
#endif
	host->dev_index = 0;
#ifdef CONFIG_SAPPORO
	/* refer to hc1706k.dtsi clock-frequency = <49800000> */
	host->bus_hz = 49800000;
#else
	host->bus_hz = 100000000;
#endif
#ifdef CONFIG_HC1703_1723_1753_1783S	
	host->fifo_mode = true;
#endif	
	// host->fifoth_val = 0x100;

	add_dwmci(host, host->bus_hz, 400000);

	return 0;
}
#endif

int board_early_init_f(void)
{
	return 0;
}

int board_init(void)
{
	/* adress of boot parameters */
	gd->bd->bi_boot_params = CONFIG_SYS_SDRAM_BASE + 0x100;
	return 0;
}

#ifdef CONFIG_EFUSE_FSM_AUTOBURN
int efuse_burn_init(void)
{
	const char *factory_mode = getenv("factory_mode");

	if (!factory_mode) {
		printf("factory_mode not found, auto-set to 1\n");
		setenv("factory_mode", "1");
		saveenv();
		factory_mode = "1";
	}

	if (strcmp(factory_mode, "1") == 0) {
		efuse_fsm_context_t *ctx = eb_fsm_get_context();
		eb_fsm_init(ctx);

		if (eb_sdc_load_data() == 0) {
			int ret = eb_fsm_start();
			if (ret != 0) {
				printf("eFuse FSM Failed (ret=%d)\n", ret);
			}
		}
	}

	return 0;
}
#endif

#if CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
#ifdef CONFIG_EARLYVIDEO
	agtx_video_set_env();
#endif
#if (defined(CONFIG_SAPPORO) && defined(CONFIG_EARLYAUDIO))
	earlyaudio_set_env();
#elif defined(CONFIG_OSAKA)
#else
	audio_init();
#endif
#ifdef CONFIG_EFUSE_FSM_AUTOBURN
	efuse_burn_init();
#endif
	return 0;
}
#endif

int dram_init(void)
{
	gd->ram_size = get_ram_size((void *)CONFIG_SYS_SDRAM_BASE, CONFIG_SYS_SDRAM_SIZE);
	return 0;
}

int board_eth_init(bd_t *bis)
{
#ifdef CONFIG_NET
	gpio_direction_output(PHY_RESET_GPIO, 0);
	mdelay(20); //reset hold time
	gpio_set_value(PHY_RESET_GPIO, 1);
	mdelay(150); //mdio ready after reset
	eqos_emac_initialize(PHY_INTERFACE_MODE_RMII);
#endif
	return 0;
}
