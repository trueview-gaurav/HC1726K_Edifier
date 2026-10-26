/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2026 Augentix Inc.
 */

#ifndef __ASM_ARCH_AUGENTIX_AUDIO_H
#define __ASM_ARCH_AUGENTIX_AUDIO_H

extern unsigned long agtx_audio_base;

int audio_init(void);

#ifdef CONFIG_EARLYAUDIO
int earlyaudio_init(void);
void earlyaudio_set_env(void);
#endif

#endif /* __ASM_ARCH_AUGENTIX_AUDIO_H */
