#include "agtx_video.h"

#include <config.h>
#include <env.h>
#include <stdio.h>
#include <vsprintf.h>
#include <time.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <linux/string.h>
#include <asm/io.h>
#include <asm/gpio.h>

extern struct is_drvdata g_is_drvdata;

void agtx_video_init(void)
{
	is_init_drvdata();
	is_init_hw();
	senif_init_drvdata(); /* must after is_init_drvdata() initial share memory */
	senif_init_hw();
	senif_trigger_start();
}

void agtx_video_enable_sw_light_meter(uint8_t path)
{
	is_enable_bsp_route(path);
}

void agtx_video_poll_sw_light_meter(uint8_t path)
{
	is_poll_bsp_path(path);
}

void agtx_video_enable_image_capture(uint8_t path)
{
	is_enable_dram_route(path);
}

#if EARLYVIDEO_DEBUG
void agtx_video_poll_frame_end(uint8_t path)
{
	is_poll_da(path);
}

void agtx_video_show_checksum(void)
{
	is_show_checksum();
}
#endif

void agtx_video_start(uint8_t path)
{
	is_trigger_start(path);
}

unsigned long agtx_video_setmem(unsigned long addr)
{
	unsigned long reserved_size_mb = EARLY_VB_SIZE;

	addr -= (reserved_size_mb << 20);
#if EARLYVIDEO_DEBUG
	printf("Reserving %luk for augentix video at: %08lx\n", reserved_size_mb << 10, addr);
#endif

	return addr;
}

void agtx_video_set_env(void)
{
	char value_buf[32];

	/* Set the information of shared memory */
	sprintf(value_buf, "0x%08x", (unsigned int)g_is_drvdata.shm_ptr);
	env_set("early_vb_memaddr", value_buf);
	sprintf(value_buf, "%d", EARLY_VB_SIZE);
	env_set("early_vb_size", value_buf);
}
