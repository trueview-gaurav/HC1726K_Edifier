#include "earlyaudio.h"

#include <linux/init.h>
#include <linux/mm.h>
#include <linux/module.h>

/* Early audio arguments and parameters */
#define EARLYAUDIO_STR_CONCAT(s1, s2) s1##s2
#define EARLYAUDIO_UBOOTENV_SETUP(var, value)  \
	static int EARLYAUDIO_STR_CONCAT(g_ubootenv_, var) = value;                                        \
	static __attribute__((unused)) int __init EARLYAUDIO_STR_CONCAT(earlyaudio_setup_, var)(char *str) \
	{                                                                                                  \
		sscanf(str, "%i", &EARLYAUDIO_STR_CONCAT(g_ubootenv_, var));                               \
		return 1;                                                                                  \
	}                                                                                                  \
	__setup(#var "=", EARLYAUDIO_STR_CONCAT(earlyaudio_setup_, var));

EARLYAUDIO_UBOOTENV_SETUP(early_audio_buf_addr, 0);
EARLYAUDIO_UBOOTENV_SETUP(early_audio_buf_kb, 0);
/* Early audio auguments and parameters */

static struct early_audio_args g_args;

void early_audio_free()
{
	free_reserved_area((void *)phys_to_virt(g_args.addr), (void *)(phys_to_virt(g_args.addr) + (g_ubootenv_early_audio_buf_kb << 10)), -1, NULL);

	g_args.addr = 0;
	g_args.size = 0;
}
EXPORT_SYMBOL(early_audio_free);

void early_audio_retrieve_args(struct early_audio_args *args)
{
	*args = g_args;
}
EXPORT_SYMBOL(early_audio_retrieve_args);

static int __init early_audio_init(void)
{
	g_args.addr = g_ubootenv_early_audio_buf_addr;
	g_args.size = (g_ubootenv_early_audio_buf_kb / 24 * 24) << 10;

	return 0;
}

static void __exit early_audio_exit(void)
{
	/* Do nothing */
}

module_init(early_audio_init);
module_exit(early_audio_exit);

MODULE_DESCRIPTION("Augentix early audio module");
MODULE_AUTHOR("<henry.liu@augentix.com>");
MODULE_LICENSE("GPL");
