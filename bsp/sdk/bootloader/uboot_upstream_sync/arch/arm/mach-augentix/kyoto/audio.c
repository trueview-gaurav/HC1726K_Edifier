// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2026 Augentix Inc.
 */

#include <common.h>
#include <address_map.h>	/* CPVS */
#include "csr_bank_apreampcfg.h"

static volatile struct csr_bank_apreampcfg *g_apreampcfg = (void *)ADOPREAMP_BASE;

int audio_init(void)
{
	g_apreampcfg->rg_audio_preamp_ref_en = 1;
	g_apreampcfg->rg_audio_preamp_plus_en = 1;

	return 0;
}
