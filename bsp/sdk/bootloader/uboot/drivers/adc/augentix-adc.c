#include <common.h>
#include <asm/io.h>

#include "augentix_adc.h"
#include "csr_bank_adcctr.h"
#include "csr_bank_adccfg.h"
#include "csr_bank_adoin.h"

#define MAX_TRIAL_TIMES 70

#define ADCCFG_BASE 0x80100000
#define ADCCTR_BASE 0x80108000
#define ADOIN_BASE 0x80140000

#define DATA_OFFSET 0x30
#define IRQ_ST0_OFFSET 0x1C
#define IRQ_ST1_OFFSET 0x40
#define IRQ_CLR0_OFFSET 0xC
#define IRQ_CLR1_OFFSET 0x3C

#define ENV_DATA_ADDR(x) (ADCCTR_BASE + DATA_OFFSET + (x << 2))
#define IRQ_ST_ADDR(x) ((x) > 3 ? (ADOIN_BASE + IRQ_ST1_OFFSET) : (ADOIN_BASE + IRQ_ST0_OFFSET))
#define IRQ_CLR_ADDR(x) ((x) > 3 ? (ADOIN_BASE + IRQ_CLR1_OFFSET) : (ADOIN_BASE + IRQ_CLR0_OFFSET))

/* workaround for ADC malfunction: #59442 #32163 */
void augentix_adc_workaround(void)
{
	volatile CsrBankAdcctr *adcctr = (volatile CsrBankAdcctr *)ADCCTR_BASE;
	adcctr->adc_stop = 1;
	adcctr->adc_clk_stop = 1;
	adcctr->env_init = 1;
	adcctr->adc_clk_start = 1;
	adcctr->adc_start = 1;
}

int augentix_adc_read(int adc_ch, uint32_t *adc_result)
{
	volatile CsrBankAdcctr *adcctr = (volatile CsrBankAdcctr *)ADCCTR_BASE;
	uint32_t env_data_addr, irq_st_addr, irq_clr_addr;
	uint32_t ch_bit;
	int i;

	switch (adc_ch) {
	case 0:
		ch_bit = BIT(0);
		adcctr->virtual_ch_0_selref = 0;
		adcctr->env_query_0 = 1;
		break;
	case 1:
		ch_bit = BIT(8);
		adcctr->virtual_ch_1_selref = 0;
		adcctr->env_query_1 = 1;
		break;
	case 2:
		ch_bit = BIT(16);
		adcctr->virtual_ch_2_selref = 0;
		adcctr->env_query_2 = 1;
		break;
	case 3:
		ch_bit = BIT(24);
		adcctr->virtual_ch_3_selref = 0;
		adcctr->env_query_3 = 1;
		break;
	case 4:
		ch_bit = BIT(0);
		adcctr->virtual_ch_4_selref = 0;
		adcctr->env_query_4 = 1;
		break;
	case 5:
		ch_bit = BIT(8);
		adcctr->virtual_ch_5_selref = 0;
		adcctr->env_query_5 = 1;
		break;
	default:
		printf("adc_ch %d is invalid\n", adc_ch);
		return -1;
		break;
	}
	env_data_addr = ENV_DATA_ADDR(adc_ch);
	irq_st_addr = IRQ_ST_ADDR(adc_ch);
	irq_clr_addr = IRQ_CLR_ADDR(adc_ch);

	for (i = 0; i < MAX_TRIAL_TIMES; i++) {
		udelay(1);
		if (readl(irq_st_addr) & ch_bit) {
			writel(ch_bit, irq_clr_addr); // clear irq
			*adc_result = readl(env_data_addr);
			return 0;
		}
	}

	return -1;
}

void augentix_adc_power_on(void)
{
	volatile CsrBankAdcctr *adcctr = (volatile CsrBankAdcctr *)ADCCTR_BASE;
	adcctr->adc_clk_start = 1;
	adcctr->adc_start = 1;
}

void augentix_adc_power_off(void)
{
	volatile CsrBankAdcctr *adcctr = (volatile CsrBankAdcctr *)ADCCTR_BASE;
	adcctr->adc_stop = 1;
	adcctr->adc_clk_stop = 1;
}

void augentix_adc_setup(void)
{
	volatile CsrBankAdccfg *adccfg = (volatile CsrBankAdccfg *)ADCCFG_BASE;
	volatile CsrBankAdcctr *adcctr = (volatile CsrBankAdcctr *)ADCCTR_BASE;

	adccfg->adc_enadc = 1;
	// resolution is set as 12 bits
	adccfg->adc_selres = 3;

	adcctr->ch_num = 1;
	adcctr->adc_format = 0;

	// another selres set as 12 bit
	adcctr->adc_selres_reg = 3;
}
