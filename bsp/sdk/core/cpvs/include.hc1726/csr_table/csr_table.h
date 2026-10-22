/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#ifndef CSR_TABLE_H_
#define CSR_TABLE_H_

#include <stdint.h>

#define CSR_RW 0
#define CSR_WO 1
#define CSR_RO 2
#define CSR_W1P 3

typedef struct {
	char *field_name;
	uint32_t offset;
	uint32_t msb;
	uint32_t lsb;
	int access_type;
	uint32_t default_value;
} CsrFieldEntry;

typedef struct {
	char *region_bank_name;
	uint32_t start_address;
	uint32_t end_address;
	uint32_t start_offset;
	uint32_t end_offset;
	CsrFieldEntry *field_table;
} CsrRegionBankEntry;

#include "csr_table_ck.h"
#include "csr_table_rst.h"
#include "csr_table_syscfg.h"
#include "csr_table_pioc.h"
#include "csr_table_gpioc.h"
#include "csr_table_eirq.h"
#include "csr_table_ipll.h"
#include "csr_table_fm.h"
#include "csr_table_fpll.h"
#include "csr_table_peri.h"
#include "csr_table_ft.h"
#include "csr_table_i2cs.h"
#include "csr_table_timer.h"
#include "csr_table_pwm.h"
#include "csr_table_i2cm.h"
#include "csr_table_efuse_ctrl.h"
#include "csr_table_saadcctr.h"
#include "csr_table_adoin.h"
#include "csr_table_adoin_syscfg.h"
#include "csr_table_adoout.h"
#include "csr_table_adoout_syscfg.h"
#include "csr_table_audior.h"
#include "csr_table_ccqw.h"
#include "csr_table_i2s.h"
#include "csr_table_aadc.h"
#include "csr_table_amic.h"
#include "csr_table_dmic.h"
#include "csr_table_adodec.h"
#include "csr_table_audio_ldo.h"
#include "csr_table_adodac.h"
#include "csr_table_tzpc.h"
#include "csr_table_tzasc.h"
#include "csr_table_cpu_cfg.h"
#include "csr_table_tz_irq.h"
#include "csr_table_rtc.h"
#include "csr_table_pmu.h"
#include "csr_table_pmu_wdt.h"
#include "csr_table_pmu_ioc.h"
#include "csr_table_aon.h"
#include "csr_table_wdt.h"
#include "csr_table_wdt_stable.h"
#include "csr_table_aioc.h"
#include "csr_table_spi_slave.h"
#include "csr_table_spi.h"
#include "csr_table_uart.h"
#include "csr_table_trng.h"
#include "csr_table_cpudbg.h"
#include "csr_table_dlm.h"
#include "csr_table_fpga_cfg.h"
#include "csr_table_fpga_route.h"
#include "csr_table_enc.h"
#include "csr_table_srcr.h"
#include "csr_table_bsw.h"
#include "csr_table_enc_syscfg.h"
#include "csr_table_enc_osd.h"
#include "csr_table_osdr.h"
#include "csr_table_jpeg.h"
#include "csr_table_venc.h"
#include "csr_table_mv8r.h"
#include "csr_table_refr.h"
#include "csr_table_refw.h"
#include "csr_table_darb_secure.h"
#include "csr_table_darb.h"
#include "csr_table_ccfg.h"
#include "csr_table_perf.h"
#include "csr_table_axiqos.h"
#include "csr_table_sdc_cfg.h"
#include "csr_table_eqos_cfg.h"
#include "csr_table_usbcfg.h"
#include "csr_table_ck_apb1.h"
#include "csr_table_ddrphy.h"
#include "csr_table_dramcontroller.h"
#include "csr_table_emac.h"
#include "csr_table_sdc.h"
#include "csr_table_isp.h"
#include "csr_table_isp_cfg.h"
#include "csr_table_isp_checksum.h"
#include "csr_table_ispin_checksum.h"
#include "csr_table_ccq.h"
#include "csr_table_ccqr.h"
#include "csr_table_pg.h"
#include "csr_table_pxr.h"
#include "csr_table_cs.h"
#include "csr_table_gfx.h"
#include "csr_table_coordr.h"
#include "csr_table_bld.h"
#include "csr_table_hdr.h"
#include "csr_table_dms.h"
#include "csr_table_fcs.h"
#include "csr_table_dbf.h"
#include "csr_table_ccm.h"
#include "csr_table_pca.h"
#include "csr_table_cst.h"
#include "csr_table_sc.h"
#include "csr_table_cus.h"
#include "csr_table_cds.h"
#include "csr_table_mcvp.h"
#include "csr_table_me.h"
#include "csr_table_nr.h"
#include "csr_table_mer.h"
#include "csr_table_nrw.h"
#include "csr_table_vp.h"
#include "csr_table_vp_cfg.h"
#include "csr_table_vp_checksum.h"
#include "csr_table_mv8w.h"
#include "csr_table_dwb2r.h"
#include "csr_table_pup.h"
#include "csr_table_pxw.h"
#include "csr_table_qspiw.h"
#include "csr_table_nr2d.h"
#include "csr_table_shp.h"
#include "csr_table_dhz.h"
#include "csr_table_ck_apb2.h"
#include "csr_table_is.h"
#include "csr_table_is_cfg.h"
#include "csr_table_is_checksum.h"
#include "csr_table_lpmd.h"
#include "csr_table_tg.h"
#include "csr_table_edp.h"
#include "csr_table_lup.h"
#include "csr_table_isk.h"
#include "csr_table_isk_cfg.h"
#include "csr_table_isk_checksum.h"
#include "csr_table_crop.h"
#include "csr_table_bls.h"
#include "csr_table_dbc.h"
#include "csr_table_dcc.h"
#include "csr_table_lsc.h"
#include "csr_table_bsp.h"
#include "csr_table_dfk.h"
#include "csr_table_cvs.h"
#include "csr_table_fsc.h"
#include "csr_table_rx_phycfg.h"
#include "csr_table_rx_ctrl.h"
#include "csr_table_rx.h"
#include "csr_table_dec.h"
#include "csr_table_ps.h"
#include "csr_table_slb.h"
#include "csr_table_senif_syscfg.h"
#include "csr_table_senif_ctrl.h"
#include "csr_table_spirx_dec.h"
#include "csr_table_secure_dma.h"
#include "csr_table_aes_enc.h"
#include "csr_table_aes_dec.h"
#include "csr_table_aes_codec.h"
#include "csr_table_qspir.h"
#include "csr_table_lli.h"
#include "csr_table_sdma_syscfg.h"
#include "csr_table_dma.h"
#include "csr_table_dma_syscfg.h"
#include "csr_table_qspi.h"
#include "csr_table_ck_apb3.h"
#include "csr_table_gic.h"
#include "csr_table_usbotg.h"

CsrRegionBankEntry csr_region_bank_table[] = {
	{ "pc.ck", 0x80000000, 0x800003FF, 0x00000000, 0x000003FF, csr_field_table_ck },
	{ "pc.rst", 0x80000400, 0x800007FF, 0x00000400, 0x000007FF, csr_field_table_rst },
	{ "pc.syscfg", 0x80000800, 0x8000083F, 0x00000800, 0x0000083F, csr_field_table_syscfg },
	{ "io.pioc", 0x80001000, 0x800013FF, 0x00001000, 0x000013FF, csr_field_table_pioc },
	{ "io.gpioc", 0x80001400, 0x800014FF, 0x00001400, 0x000014FF, csr_field_table_gpioc },
	{ "eirq.eirq", 0x80002000, 0x80002FFF, 0x00002000, 0x00002FFF, csr_field_table_eirq },
	{ "pll_cascade.ipll", 0x80010000, 0x8001007F, 0x00010000, 0x0001007F, csr_field_table_ipll },
	{ "pll_cascade.fm", 0x80010400, 0x800107FF, 0x00010400, 0x000107FF, csr_field_table_fm },
	{ "pll_ddr.fpll", 0x80011000, 0x8001107F, 0x00011000, 0x0001107F, csr_field_table_fpll },
	{ "pll_ddr.fm", 0x80011400, 0x800117FF, 0x00011400, 0x000117FF, csr_field_table_fm },
	{ "pll_cpu.ipll", 0x80012000, 0x8001207F, 0x00012000, 0x0001207F, csr_field_table_ipll },
	{ "pll_cpu.fm", 0x80012400, 0x800127FF, 0x00012400, 0x000127FF, csr_field_table_fm },
	{ "pll_sensor.ipll", 0x80015000, 0x8001507F, 0x00015000, 0x0001507F, csr_field_table_ipll },
	{ "pll_sensor.fm", 0x80015400, 0x800157FF, 0x00015400, 0x000157FF, csr_field_table_fm },
	{ "pll_audio.fpll", 0x80017000, 0x8001707F, 0x00017000, 0x0001707F, csr_field_table_fpll },
	{ "pll_audio.fm", 0x80017400, 0x800177FF, 0x00017400, 0x000177FF, csr_field_table_fm },
	{ "usb_fm.fm", 0x80018000, 0x800183FF, 0x00018000, 0x000183FF, csr_field_table_fm },
	{ "peri.peri", 0x80020000, 0x8002FFFF, 0x00020000, 0x0002FFFF, csr_field_table_peri },
	{ "ft.ft", 0x80030000, 0x8003FFFF, 0x00030000, 0x0003FFFF, csr_field_table_ft },
	{ "i2cs.i2cs", 0x80040000, 0x8004FFFF, 0x00040000, 0x0004FFFF, csr_field_table_i2cs },
	{ "timer.timer", 0x80050000, 0x800503FF, 0x00050000, 0x000503FF, csr_field_table_timer },
	{ "pwm.pwm", 0x80060000, 0x8006FFFF, 0x00060000, 0x0006FFFF, csr_field_table_pwm },
	{ "i2cm0.i2cm", 0x80070000, 0x800703FF, 0x00070000, 0x000703FF, csr_field_table_i2cm },
	{ "i2cm1.i2cm", 0x80080000, 0x800803FF, 0x00080000, 0x000803FF, csr_field_table_i2cm },
	{ "i2cm2.i2cm", 0x80090000, 0x800903FF, 0x00090000, 0x000903FF, csr_field_table_i2cm },
	{ "efuse_ctrl.efuse_ctrl", 0x80100000, 0x801003FF, 0x00100000, 0x001003FF, csr_field_table_efuse_ctrl },
	{ "adosaadc_ctr.saadcctr", 0x80110000, 0x801100FF, 0x00110000, 0x001100FF, csr_field_table_saadcctr },
	{ "adoin.adoin", 0x80120000, 0x801203FF, 0x00120000, 0x001203FF, csr_field_table_adoin },
	{ "adoin.adoin_syscfg", 0x80120400, 0x801207FF, 0x00120400, 0x001207FF, csr_field_table_adoin_syscfg },
	{ "adoout.adoout", 0x80130000, 0x801303FF, 0x00130000, 0x001303FF, csr_field_table_adoout },
	{ "adoout.adoout_syscfg", 0x80130400, 0x801307FF, 0x00130400, 0x001307FF, csr_field_table_adoout_syscfg },
	{ "ador.audior", 0x80140000, 0x801403FF, 0x00140000, 0x001403FF, csr_field_table_audior },
	{ "adow.ccqw", 0x80150000, 0x801503FF, 0x00150000, 0x001503FF, csr_field_table_ccqw },
	{ "adoi2stx.i2s", 0x80160000, 0x8016FFFF, 0x00160000, 0x0016FFFF, csr_field_table_i2s },
	{ "adoi2srx.i2s", 0x80170000, 0x8017FFFF, 0x00170000, 0x0017FFFF, csr_field_table_i2s },
	{ "adoaadc_l.aadc", 0x80180000, 0x801803FF, 0x00180000, 0x001803FF, csr_field_table_aadc },
	{ "adoaadc_r.aadc", 0x80190000, 0x801903FF, 0x00190000, 0x001903FF, csr_field_table_aadc },
	{ "adoamic_l.amic", 0x80200000, 0x8020FFFF, 0x00200000, 0x0020FFFF, csr_field_table_amic },
	{ "adoamic_r.amic", 0x80210000, 0x8021FFFF, 0x00210000, 0x0021FFFF, csr_field_table_amic },
	{ "adodmic_l.dmic", 0x80220000, 0x8022FFFF, 0x00220000, 0x0022FFFF, csr_field_table_dmic },
	{ "adodmic_r.dmic", 0x80230000, 0x8023FFFF, 0x00230000, 0x0023FFFF, csr_field_table_dmic },
	{ "adodec.adodec", 0x80240000, 0x8024FFFF, 0x00240000, 0x0024FFFF, csr_field_table_adodec },
	{ "adoldo.audio_ldo", 0x80250000, 0x802503FF, 0x00250000, 0x002503FF, csr_field_table_audio_ldo },
	{ "adodac.adodac", 0x80260000, 0x802603FF, 0x00260000, 0x002603FF, csr_field_table_adodac },
	{ "tzone.tzpc", 0x80270000, 0x80270FFF, 0x00270000, 0x00270FFF, csr_field_table_tzpc },
	{ "tzone.tzasc", 0x80271000, 0x80271FFF, 0x00271000, 0x00271FFF, csr_field_table_tzasc },
	{ "tzone.cpu_cfg", 0x80272000, 0x80272FFF, 0x00272000, 0x00272FFF, csr_field_table_cpu_cfg },
	{ "tzone.tz_irq", 0x80273000, 0x802730FF, 0x00273000, 0x002730FF, csr_field_table_tz_irq },
	{ "pmu.rtc", 0x80290000, 0x802903FF, 0x00290000, 0x002903FF, csr_field_table_rtc },
	{ "pmu.pmu", 0x80290400, 0x802907FF, 0x00290400, 0x002907FF, csr_field_table_pmu },
	{ "pmu.pmu_wdt", 0x80290800, 0x80290BFF, 0x00290800, 0x00290BFF, csr_field_table_pmu_wdt },
	{ "pmu.pmu_ioc", 0x80290C00, 0x80290FFF, 0x00290C00, 0x00290FFF, csr_field_table_pmu_ioc },
	{ "aon.rtc", 0x80300000, 0x803003FF, 0x00300000, 0x003003FF, csr_field_table_rtc },
	{ "aon.aon", 0x80300400, 0x803007FF, 0x00300400, 0x003007FF, csr_field_table_aon },
	{ "aon.wdt", 0x80300800, 0x80300BFF, 0x00300800, 0x00300BFF, csr_field_table_wdt },
	{ "aon.wdt_stable", 0x80300C00, 0x80300FFF, 0x00300C00, 0x00300FFF, csr_field_table_wdt_stable },
	{ "aon.aioc", 0x80301000, 0x803013FF, 0x00301000, 0x003013FF, csr_field_table_aioc },
	{ "spi_slave0.spi_slave", 0x80790000, 0x807900FF, 0x00790000, 0x007900FF, csr_field_table_spi_slave },
	{ "spi0.spi", 0x80800000, 0x808000FF, 0x00800000, 0x008000FF, csr_field_table_spi },
	{ "spi1.spi", 0x80810000, 0x808100FF, 0x00810000, 0x008100FF, csr_field_table_spi },
	{ "uart0.uart", 0x80820000, 0x808200FF, 0x00820000, 0x008200FF, csr_field_table_uart },
	{ "uart1.uart", 0x80830000, 0x808300FF, 0x00830000, 0x008300FF, csr_field_table_uart },
	{ "uart2.uart", 0x80840000, 0x808400FF, 0x00840000, 0x008400FF, csr_field_table_uart },
	{ "trng.trng", 0x80880000, 0x80880FFF, 0x00880000, 0x00880FFF, csr_field_table_trng },
	{ "cpudbg.cpudbg", 0x80A00000, 0x80BFFFFF, 0x00A00000, 0x00BFFFFF, csr_field_table_cpudbg },
	{ "pvt.dlm", 0x80C00000, 0x80C000FF, 0x00C00000, 0x00C000FF, csr_field_table_dlm },
	{ "fpga_cfg.fpga_cfg", 0x80FF0000, 0x80FF03FF, 0x00FF0000, 0x00FF03FF, csr_field_table_fpga_cfg },
	{ "fpga_cfg.fpga_route", 0x80FF0400, 0x80FF07FF, 0x00FF0400, 0x00FF07FF, csr_field_table_fpga_route },
	{ "enc.enc", 0x81000000, 0x810003FF, 0x01000000, 0x010003FF, csr_field_table_enc },
	{ "enc.srcr", 0x81000400, 0x810007FF, 0x01000400, 0x010007FF, csr_field_table_srcr },
	{ "enc.bsw", 0x81000800, 0x81000BFF, 0x01000800, 0x01000BFF, csr_field_table_bsw },
	{ "enc.enc_syscfg", 0x81000C00, 0x81000CFF, 0x01000C00, 0x01000CFF, csr_field_table_enc_syscfg },
	{ "enc_osd.enc_osd", 0x81010000, 0x8101FFFF, 0x01010000, 0x0101FFFF, csr_field_table_enc_osd },
	{ "enc_osdr_0.osdr", 0x81020000, 0x810203FF, 0x01020000, 0x010203FF, csr_field_table_osdr },
	{ "enc_osdr_1.osdr", 0x81030000, 0x810303FF, 0x01030000, 0x010303FF, csr_field_table_osdr },
	{ "jpeg.jpeg", 0x81040000, 0x810403FF, 0x01040000, 0x010403FF, csr_field_table_jpeg },
	{ "venc.venc", 0x81050000, 0x810503FF, 0x01050000, 0x010503FF, csr_field_table_venc },
	{ "venc.mv8r", 0x81050400, 0x810507FF, 0x01050400, 0x010507FF, csr_field_table_mv8r },
	{ "venc.refr", 0x81050800, 0x81050BFF, 0x01050800, 0x01050BFF, csr_field_table_refr },
	{ "venc.refw", 0x81050C00, 0x81050FFF, 0x01050C00, 0x01050FFF, csr_field_table_refw },
	{ "darb_secure_0.darb_secure", 0x812F0000, 0x812F03FF, 0x012F0000, 0x012F03FF, csr_field_table_darb_secure },
	{ "darb0.darb", 0x81300000, 0x813003FF, 0x01300000, 0x013003FF, csr_field_table_darb },
	{ "dramccfg.ccfg", 0x81310000, 0x813103FF, 0x01310000, 0x013103FF, csr_field_table_ccfg },
	{ "dramccfg.perf", 0x81310400, 0x813107FF, 0x01310400, 0x013107FF, csr_field_table_perf },
	{ "axiqos0.axiqos", 0x81320000, 0x813200FF, 0x01320000, 0x013200FF, csr_field_table_axiqos },
	{ "axiqos1.axiqos", 0x81330000, 0x813300FF, 0x01330000, 0x013300FF, csr_field_table_axiqos },
	{ "sdc_cfg0.sdc_cfg", 0x81340000, 0x8134FFFF, 0x01340000, 0x0134FFFF, csr_field_table_sdc_cfg },
	{ "sdc_cfg1.sdc_cfg", 0x81350000, 0x8135FFFF, 0x01350000, 0x0135FFFF, csr_field_table_sdc_cfg },
	{ "eqos_cfg.eqos_cfg", 0x81360000, 0x8136FFFF, 0x01360000, 0x0136FFFF, csr_field_table_eqos_cfg },
	{ "usbcfg.usbcfg", 0x81370000, 0x813700FF, 0x01370000, 0x013700FF, csr_field_table_usbcfg },
	{ "ck_apb1.ck_apb1", 0x81400000, 0x81400FFF, 0x01400000, 0x01400FFF, csr_field_table_ck_apb1 },
	{ "ddrphy.ddrphy", 0x81840000, 0x818403FF, 0x01840000, 0x018403FF, csr_field_table_ddrphy },
	{ "dramcontroller.dramcontroller", 0x81860000, 0x81867FFF, 0x01860000, 0x01867FFF,
	  csr_field_table_dramcontroller },
	{ "emacqoscontroller.emac", 0x81880000, 0x8188FFFF, 0x01880000, 0x0188FFFF, csr_field_table_emac },
	{ "sdc0.sdc", 0x818A0000, 0x818A03FF, 0x018A0000, 0x018A03FF, csr_field_table_sdc },
	{ "sdc1.sdc", 0x818C0000, 0x818C03FF, 0x018C0000, 0x018C03FF, csr_field_table_sdc },
	{ "isp.isp", 0x82000000, 0x820003FF, 0x02000000, 0x020003FF, csr_field_table_isp },
	{ "isp.isp_cfg", 0x82000400, 0x820007FF, 0x02000400, 0x020007FF, csr_field_table_isp_cfg },
	{ "isp.isp_checksum", 0x82000800, 0x82000BFF, 0x02000800, 0x02000BFF, csr_field_table_isp_checksum },
	{ "isp.ispin_checksum", 0x82000C00, 0x82000FFF, 0x02000C00, 0x02000FFF, csr_field_table_ispin_checksum },
	{ "ispccq.ccq", 0x82010000, 0x820100FF, 0x02010000, 0x020100FF, csr_field_table_ccq },
	{ "ispccq.ccqr", 0x82010400, 0x820107FF, 0x02010400, 0x020107FF, csr_field_table_ccqr },
	{ "ispccq.ccqw", 0x82010800, 0x82010BFF, 0x02010800, 0x02010BFF, csr_field_table_ccqw },
	{ "isppg0.pg", 0x82020000, 0x820203FF, 0x02020000, 0x020203FF, csr_field_table_pg },
	{ "isppg1.pg", 0x82030000, 0x820303FF, 0x02030000, 0x020303FF, csr_field_table_pg },
	{ "ispr0.pxr", 0x82060000, 0x820603FF, 0x02060000, 0x020603FF, csr_field_table_pxr },
	{ "ispr1.pxr", 0x82070000, 0x820703FF, 0x02070000, 0x020703FF, csr_field_table_pxr },
	{ "isprcs0.cs", 0x820A0000, 0x820A0FFF, 0x020A0000, 0x020A0FFF, csr_field_table_cs },
	{ "isprcs1.cs", 0x820B0000, 0x820B0FFF, 0x020B0000, 0x020B0FFF, csr_field_table_cs },
	{ "gfx0.gfx", 0x820E0000, 0x820E03FF, 0x020E0000, 0x020E03FF, csr_field_table_gfx },
	{ "gfx0.coordr", 0x820E0400, 0x820E07FF, 0x020E0400, 0x020E07FF, csr_field_table_coordr },
	{ "bld.bld", 0x82110000, 0x821101FF, 0x02110000, 0x021101FF, csr_field_table_bld },
	{ "hdr.hdr", 0x82130000, 0x821303FF, 0x02130000, 0x021303FF, csr_field_table_hdr },
	{ "dms.dms", 0x82140000, 0x8214003F, 0x02140000, 0x0214003F, csr_field_table_dms },
	{ "fcs.fcs", 0x82150000, 0x821500FF, 0x02150000, 0x021500FF, csr_field_table_fcs },
	{ "dbf.dbf", 0x82160000, 0x821600FF, 0x02160000, 0x021600FF, csr_field_table_dbf },
	{ "ccm.ccm", 0x82170000, 0x8217FFFF, 0x02170000, 0x0217FFFF, csr_field_table_ccm },
	{ "pca.pca", 0x82190000, 0x821900FF, 0x02190000, 0x021900FF, csr_field_table_pca },
	{ "cst.cst", 0x821A0000, 0x821AFFFF, 0x021A0000, 0x021AFFFF, csr_field_table_cst },
	{ "sc.sc", 0x821B0000, 0x821B00FF, 0x021B0000, 0x021B00FF, csr_field_table_sc },
	{ "ispcus.cus", 0x821D0000, 0x821DFFFF, 0x021D0000, 0x021DFFFF, csr_field_table_cus },
	{ "ispcds.cds", 0x821E0000, 0x821E0FFF, 0x021E0000, 0x021E0FFF, csr_field_table_cds },
	{ "vp.mcvp", 0x82200000, 0x822003FF, 0x02200000, 0x022003FF, csr_field_table_mcvp },
	{ "vp.me", 0x82200400, 0x822007FF, 0x02200400, 0x022007FF, csr_field_table_me },
	{ "vp.nr", 0x82200800, 0x82200BFF, 0x02200800, 0x02200BFF, csr_field_table_nr },
	{ "vp.mer", 0x82200C00, 0x82200FFF, 0x02200C00, 0x02200FFF, csr_field_table_mer },
	{ "vp.nrw", 0x82201000, 0x822013FF, 0x02201000, 0x022013FF, csr_field_table_nrw },
	{ "vp.vp", 0x82201400, 0x822017FF, 0x02201400, 0x022017FF, csr_field_table_vp },
	{ "vp.vp_cfg", 0x82201800, 0x82201BFF, 0x02201800, 0x02201BFF, csr_field_table_vp_cfg },
	{ "vp.vp_checksum", 0x82201C00, 0x82201FFF, 0x02201C00, 0x02201FFF, csr_field_table_vp_checksum },
	{ "vp_mv8w.mv8w", 0x82210000, 0x822103FF, 0x02210000, 0x022103FF, csr_field_table_mv8w },
	{ "vp_mv8r.mv8r", 0x82220000, 0x822203FF, 0x02220000, 0x022203FF, csr_field_table_mv8r },
	{ "vp_venc_mvw.mv8w", 0x82230000, 0x822303FF, 0x02230000, 0x022303FF, csr_field_table_mv8w },
	{ "vpb2r.dwb2r", 0x82240000, 0x822403FF, 0x02240000, 0x022403FF, csr_field_table_dwb2r },
	{ "vppup.pup", 0x82250000, 0x8225FFFF, 0x02250000, 0x0225FFFF, csr_field_table_pup },
	{ "vpw0.pxw", 0x82290000, 0x822903FF, 0x02290000, 0x022903FF, csr_field_table_pxw },
	{ "vpw1.pxw", 0x822A0000, 0x822A03FF, 0x022A0000, 0x022A03FF, csr_field_table_pxw },
	{ "vpw2.qspiw", 0x822B0000, 0x822B03FF, 0x022B0000, 0x022B03FF, csr_field_table_qspiw },
	{ "nr2d.nr2d", 0x82300000, 0x823001FF, 0x02300000, 0x023001FF, csr_field_table_nr2d },
	{ "shp.shp", 0x82310000, 0x823103FF, 0x02310000, 0x023103FF, csr_field_table_shp },
	{ "dhz.dhz", 0x82320000, 0x8232007F, 0x02320000, 0x0232007F, csr_field_table_dhz },
	{ "ck_apb2.ck_apb2", 0x82A00000, 0x82A00FFF, 0x02A00000, 0x02A00FFF, csr_field_table_ck_apb2 },
	{ "is_set0.is", 0x83000000, 0x830003FF, 0x03000000, 0x030003FF, csr_field_table_is },
	{ "is_set0.is_cfg", 0x83000400, 0x830007FF, 0x03000400, 0x030007FF, csr_field_table_is_cfg },
	{ "is_set0.is_checksum", 0x83000800, 0x83000BFF, 0x03000800, 0x03000BFF, csr_field_table_is_checksum },
	{ "is_set0.lpmd", 0x83000C00, 0x83000FFF, 0x03000C00, 0x03000FFF, csr_field_table_lpmd },
	{ "isccq_set0.ccq", 0x83010000, 0x830100FF, 0x03010000, 0x030100FF, csr_field_table_ccq },
	{ "isccq_set0.ccqr", 0x83010400, 0x830107FF, 0x03010400, 0x030107FF, csr_field_table_ccqr },
	{ "isccq_set0.ccqw", 0x83010800, 0x83010BFF, 0x03010800, 0x03010BFF, csr_field_table_ccqw },
	{ "isfe0_set0.pg", 0x83020000, 0x830203FF, 0x03020000, 0x030203FF, csr_field_table_pg },
	{ "isfe0_set0.tg", 0x83020400, 0x830207FF, 0x03020400, 0x030207FF, csr_field_table_tg },
	{ "isfe0_set0.edp", 0x83020800, 0x830209FF, 0x03020800, 0x030209FF, csr_field_table_edp },
	{ "isfe1_set0.pg", 0x83030000, 0x830303FF, 0x03030000, 0x030303FF, csr_field_table_pg },
	{ "isfe1_set0.tg", 0x83030400, 0x830307FF, 0x03030400, 0x030307FF, csr_field_table_tg },
	{ "isfe1_set0.edp", 0x83030800, 0x830309FF, 0x03030800, 0x030309FF, csr_field_table_edp },
	{ "isr0_set0.ccqr", 0x83040000, 0x830403FF, 0x03040000, 0x030403FF, csr_field_table_ccqr },
	{ "isr1_set0.ccqr", 0x83050000, 0x830503FF, 0x03050000, 0x030503FF, csr_field_table_ccqr },
	{ "isw0_set0.pxw", 0x83060000, 0x830603FF, 0x03060000, 0x030603FF, csr_field_table_pxw },
	{ "isw1_set0.pxw", 0x83070000, 0x830703FF, 0x03070000, 0x030703FF, csr_field_table_pxw },
	{ "isw2_set0.pxw", 0x83080000, 0x830803FF, 0x03080000, 0x030803FF, csr_field_table_pxw },
	{ "isw3_set0.pxw", 0x83090000, 0x830903FF, 0x03090000, 0x030903FF, csr_field_table_pxw },
	{ "islup0_set0.lup", 0x83092000, 0x8309203F, 0x03092000, 0x0309203F, csr_field_table_lup },
	{ "islup1_set0.lup", 0x83094000, 0x8309403F, 0x03094000, 0x0309403F, csr_field_table_lup },
	{ "isk0.isk", 0x83100000, 0x831003FF, 0x03100000, 0x031003FF, csr_field_table_isk },
	{ "isk0.isk_cfg", 0x83100400, 0x831007FF, 0x03100400, 0x031007FF, csr_field_table_isk_cfg },
	{ "isk0.isk_checksum", 0x83100800, 0x83100BFF, 0x03100800, 0x03100BFF, csr_field_table_isk_checksum },
	{ "iscrop0.crop", 0x83118000, 0x831181FF, 0x03118000, 0x031181FF, csr_field_table_crop },
	{ "bls0.bls", 0x83120000, 0x831203FF, 0x03120000, 0x031203FF, csr_field_table_bls },
	{ "dbc0.dbc", 0x83128000, 0x831283FF, 0x03128000, 0x031283FF, csr_field_table_dbc },
	{ "dcc0.dcc", 0x83130000, 0x83130FFF, 0x03130000, 0x03130FFF, csr_field_table_dcc },
	{ "lsc0.lsc", 0x83138000, 0x831380FF, 0x03138000, 0x031380FF, csr_field_table_lsc },
	{ "bsp0.bsp", 0x83140000, 0x83140FFF, 0x03140000, 0x03140FFF, csr_field_table_bsp },
	{ "dfk0.dfk", 0x83148000, 0x8314BFFF, 0x03148000, 0x0314BFFF, csr_field_table_dfk },
	{ "iscvs0.cvs", 0x83150000, 0x83150FFF, 0x03150000, 0x03150FFF, csr_field_table_cvs },
	{ "iscs0.cs", 0x83158000, 0x83158FFF, 0x03158000, 0x03158FFF, csr_field_table_cs },
	{ "fsc0.fsc", 0x83160000, 0x8316003F, 0x03160000, 0x0316003F, csr_field_table_fsc },
	{ "isk1.isk", 0x83180000, 0x831803FF, 0x03180000, 0x031803FF, csr_field_table_isk },
	{ "isk1.isk_cfg", 0x83180400, 0x831807FF, 0x03180400, 0x031807FF, csr_field_table_isk_cfg },
	{ "isk1.isk_checksum", 0x83180800, 0x83180BFF, 0x03180800, 0x03180BFF, csr_field_table_isk_checksum },
	{ "iscrop1.crop", 0x83198000, 0x831981FF, 0x03198000, 0x031981FF, csr_field_table_crop },
	{ "bls1.bls", 0x831A0000, 0x831A03FF, 0x031A0000, 0x031A03FF, csr_field_table_bls },
	{ "dbc1.dbc", 0x831A8000, 0x831A83FF, 0x031A8000, 0x031A83FF, csr_field_table_dbc },
	{ "dcc1.dcc", 0x831B0000, 0x831B0FFF, 0x031B0000, 0x031B0FFF, csr_field_table_dcc },
	{ "lsc1.lsc", 0x831B8000, 0x831B80FF, 0x031B8000, 0x031B80FF, csr_field_table_lsc },
	{ "bsp1.bsp", 0x831C0000, 0x831C0FFF, 0x031C0000, 0x031C0FFF, csr_field_table_bsp },
	{ "dfk1.dfk", 0x831C8000, 0x831CBFFF, 0x031C8000, 0x031CBFFF, csr_field_table_dfk },
	{ "iscvs1.cvs", 0x831D0000, 0x831D0FFF, 0x031D0000, 0x031D0FFF, csr_field_table_cvs },
	{ "iscs1.cs", 0x831D8000, 0x831D8FFF, 0x031D8000, 0x031D8FFF, csr_field_table_cs },
	{ "fsc1.fsc", 0x831E0000, 0x831E003F, 0x031E0000, 0x031E003F, csr_field_table_fsc },
	{ "rxphy0.rx_phycfg", 0x83500000, 0x835003FF, 0x03500000, 0x035003FF, csr_field_table_rx_phycfg },
	{ "rxphy0.rx_ctrl", 0x83500400, 0x835007FF, 0x03500400, 0x035007FF, csr_field_table_rx_ctrl },
	{ "rxphy0.fm", 0x83500800, 0x83500BFF, 0x03500800, 0x03500BFF, csr_field_table_fm },
	{ "lvds0.rx", 0x83520000, 0x835203FF, 0x03520000, 0x035203FF, csr_field_table_rx },
	{ "lvds0.dec", 0x83520400, 0x835207FF, 0x03520400, 0x035207FF, csr_field_table_dec },
	{ "lvds1.dec", 0x83530000, 0x835303FF, 0x03530000, 0x035303FF, csr_field_table_dec },
	{ "ps.ps", 0x83540000, 0x835403FF, 0x03540000, 0x035403FF, csr_field_table_ps },
	{ "slb0.slb", 0x83550000, 0x83550FFF, 0x03550000, 0x03550FFF, csr_field_table_slb },
	{ "slb1.slb", 0x83560000, 0x83560FFF, 0x03560000, 0x03560FFF, csr_field_table_slb },
	{ "senif.senif_syscfg", 0x83570000, 0x835703FF, 0x03570000, 0x035703FF, csr_field_table_senif_syscfg },
	{ "senif.senif_ctrl", 0x83570400, 0x835707FF, 0x03570400, 0x035707FF, csr_field_table_senif_ctrl },
	{ "spirx.spirx_dec", 0x83580000, 0x835803FF, 0x03580000, 0x035803FF, csr_field_table_spirx_dec },
	{ "secure_dma.secure_dma", 0x835F0000, 0x835F03FF, 0x035F0000, 0x035F03FF, csr_field_table_secure_dma },
	{ "secure_dma.aes_enc", 0x835F0400, 0x835F07FF, 0x035F0400, 0x035F07FF, csr_field_table_aes_enc },
	{ "secure_dma.aes_dec", 0x835F0800, 0x835F0BFF, 0x035F0800, 0x035F0BFF, csr_field_table_aes_dec },
	{ "secure_dma.aes_codec", 0x835F0C00, 0x835F0FFF, 0x035F0C00, 0x035F0FFF, csr_field_table_aes_codec },
	{ "secure_dma.qspir", 0x835F1000, 0x835F13FF, 0x035F1000, 0x035F13FF, csr_field_table_qspir },
	{ "secure_dma.qspiw", 0x835F1400, 0x835F17FF, 0x035F1400, 0x035F17FF, csr_field_table_qspiw },
	{ "secure_dma.lli", 0x835F1800, 0x835F1BFF, 0x035F1800, 0x035F1BFF, csr_field_table_lli },
	{ "secure_dma.sdma_syscfg", 0x835F1C00, 0x835F1FFF, 0x035F1C00, 0x035F1FFF, csr_field_table_sdma_syscfg },
	{ "dma.dma", 0x83600000, 0x836003FF, 0x03600000, 0x036003FF, csr_field_table_dma },
	{ "dma.pxr", 0x83600400, 0x836007FF, 0x03600400, 0x036007FF, csr_field_table_pxr },
	{ "dma.pxw", 0x83600800, 0x83600BFF, 0x03600800, 0x03600BFF, csr_field_table_pxw },
	{ "dma.lli", 0x83600C00, 0x83600FFF, 0x03600C00, 0x03600FFF, csr_field_table_lli },
	{ "dma.dma_syscfg", 0x83601000, 0x836013FF, 0x03601000, 0x036013FF, csr_field_table_dma_syscfg },
	{ "qspi.qspi", 0x83610000, 0x8361FFFF, 0x03610000, 0x0361FFFF, csr_field_table_qspi },
	{ "qspir.qspir", 0x83620000, 0x836203FF, 0x03620000, 0x036203FF, csr_field_table_qspir },
	{ "qspiw.qspiw", 0x83630000, 0x836303FF, 0x03630000, 0x036303FF, csr_field_table_qspiw },
	{ "ck_apb3.ck_apb3", 0x83700000, 0x83700FFF, 0x03700000, 0x03700FFF, csr_field_table_ck_apb3 },
	{ "gic.gic", 0x84000000, 0x840000FF, 0x04000000, 0x040000FF, csr_field_table_gic },
	{ "usbotg.usbotg", 0xA0000000, 0xA00000FF, 0x20000000, 0x200000FF, csr_field_table_usbotg },
	// end of table
	{ 0, 0, 0, 0, 0, 0 }
};

#endif // CSR_TABLE_H_
