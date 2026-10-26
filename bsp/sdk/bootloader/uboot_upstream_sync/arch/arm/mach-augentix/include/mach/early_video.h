/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2026 Augentix Inc.
 */

#ifndef __ASM_ARCH_AUGENTIX_EARLY_VIDEO_H
#define __ASM_ARCH_AUGENTIX_EARLY_VIDEO_H

extern unsigned long agtx_fb_base;
unsigned long agtx_video_setmem(unsigned long addr);
int board_early_video_init(void);
void board_early_video_wait_finish(void);
void agtx_video_set_env(void);
void sensor_set_env(void);
void ir_cut_control_idle(void);

#endif /* __ASM_ARCH_AUGENTIX_EARLY_VIDEO_H */
