#include <common.h>
#include "csr_bank_apreampcfg.h"

static volatile struct csr_bank_apreampcfg *g_apreampcfg = (void *)ADOPREAMP_BASE;

int audio_init(void)
{
	g_apreampcfg->rg_audio_preamp_ref_en = 1;
	g_apreampcfg->rg_audio_preamp_plus_en = 1;

	return 0;
}
