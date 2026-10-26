// SPDX-License-Identifier: GPL-2.0+
/*
 *  Author: Christian Marangi <ansuelsmth@gmail.com>
 *
 * Augentix MTD env backend, built in place of env/mtd.c.
 */
#include <env_internal.h>
#include <errno.h>
#include <malloc.h>
#include <mtd.h>
#include <asm/cache.h>
#include <asm/global_data.h>
#include <linux/mtd/mtd.h>
#include <u-boot/crc.h>

DECLARE_GLOBAL_DATA_PTR;

#ifndef CONFIG_ENV_OFFSET_REDUND
#define CONFIG_ENV_OFFSET_REDUND CONFIG_ENV_OFFSET
#endif

#ifndef CONFIG_ENV_RANGE
#define CONFIG_ENV_RANGE CONFIG_ENV_SIZE
#endif

static int setup_mtd_device(struct mtd_info **mtd_env)
{
	struct mtd_info *mtd;

	mtd_probe_devices();

	mtd = get_mtd_device_nm(CONFIG_ENV_MTD_DEV);
	if (IS_ERR_OR_NULL(mtd)) {
		env_set_default("get_mtd_device_nm() failed", 0);
		return mtd ? PTR_ERR(mtd) : -EINVAL;
	}

	*mtd_env = mtd;

	return 0;
}

/* Bad-block scan bounded to the CONFIG_ENV_RANGE window, as env/nand.c */
static int env_mtd_skip_bad(struct mtd_info *mtd_env, u32 *offset, u32 end)
{
	int ret;

	while (*offset < end) {
		ret = mtd_block_isbad(mtd_env, *offset);
		if (ret < 0)
			return ret;
		if (!ret)
			return 0;

		*offset += mtd_env->erasesize;
	}

	return -ENOSPC;
}

static int env_mtd_read_buf(struct mtd_info *mtd_env, u32 base, u32 size,
			    char *buf)
{
	u32 sect_size = mtd_env->erasesize;
	u32 end = base + CONFIG_ENV_RANGE;
	size_t ret_len = 0;
	int remaining = size;
	u32 offset = base;
	char *tmp = buf;
	int ret;

	/* A short mtd_read/mtd_write drives remaining past zero, so the
	 * test is signed, as in env_mtd_erase_range() below.
	 */
	while (remaining > 0) {
		if (!(offset % sect_size)) {
			ret = env_mtd_skip_bad(mtd_env, &offset, end);
			if (ret)
				return ret;
		}

		ret = mtd_read(mtd_env, offset, mtd_env->writesize,
			       &ret_len, tmp);
		if (ret)
			return ret;
		if (!ret_len)
			return -EIO;

		tmp += ret_len;
		offset += ret_len;
		remaining -= ret_len;
	}

	return 0;
}

static int env_mtd_write_buf(struct mtd_info *mtd_env, u32 base, u32 size,
			     char *buf)
{
	u32 sect_size = mtd_env->erasesize;
	u32 end = base + CONFIG_ENV_RANGE;
	size_t ret_len = 0;
	int remaining = size;
	u32 offset = base;
	char *tmp = buf;
	int ret;

	/* A short mtd_read/mtd_write drives remaining past zero, so the
	 * test is signed, as in env_mtd_erase_range() below.
	 */
	while (remaining > 0) {
		if (!(offset % sect_size)) {
			ret = env_mtd_skip_bad(mtd_env, &offset, end);
			if (ret)
				return ret;
		}

		ret = mtd_write(mtd_env, offset, mtd_env->writesize,
				&ret_len, tmp);
		if (ret)
			return ret;
		if (!ret_len)
			return -EIO;

		offset += ret_len;
		remaining -= ret_len;
		tmp += ret_len;
	}

	return 0;
}

/* Erase per block; a bad block is skipped, never erased over */
static int env_mtd_erase_range(struct mtd_info *mtd_env, u32 base, u32 len)
{
	u32 sect_size = mtd_env->erasesize;
	u32 end = base + CONFIG_ENV_RANGE;
	int remaining = len;
	u32 offset = base;
	int ret;

	while (remaining > 0) {
		ret = env_mtd_skip_bad(mtd_env, &offset, end);
		if (ret)
			return ret;

		struct erase_info ei = {
			.mtd = mtd_env,
			.addr = offset,
			.len = sect_size,
		};

		ret = mtd_erase(mtd_env, &ei);
		if (ret)
			return ret;

		offset += sect_size;
		remaining -= sect_size;
	}

	return 0;
}

static int env_mtd_save_one(struct mtd_info *mtd_env, u32 base,
			    env_t *env_new)
{
	char *saved_buf = NULL, *write_buf;
	u32 sect_size, sect_num;
	u32 write_size;
	int ret;

	sect_size = mtd_env->erasesize;

	/* Is the sector larger than the env (i.e. embedded) */
	if (sect_size > CONFIG_ENV_SIZE) {
		saved_buf = malloc(sect_size);
		if (!saved_buf)
			return -ENOMEM;

		ret = env_mtd_read_buf(mtd_env, base, sect_size, saved_buf);
		if (ret)
			goto done;
	}

	sect_num = DIV_ROUND_UP(CONFIG_ENV_SIZE, sect_size);

	puts("Erasing MTD...");
	ret = env_mtd_erase_range(mtd_env, base, sect_num * sect_size);
	if (ret)
		goto done;

	if (sect_size > CONFIG_ENV_SIZE) {
		memcpy(saved_buf, env_new, CONFIG_ENV_SIZE);
		write_size = sect_size;
		write_buf = saved_buf;
	} else {
		write_size = sect_num * sect_size;
		write_buf = (char *)env_new;
	}

	puts("Writing to MTD...");
	ret = env_mtd_write_buf(mtd_env, base, write_size, write_buf);
	if (ret)
		goto done;

	ret = 0;
	puts("done\n");

done:
	if (saved_buf)
		free(saved_buf);

	return ret;
}

static int env_mtd_save(void)
{
	struct mtd_info *mtd_env;
	u32 base = CONFIG_ENV_OFFSET;
	env_t env_new;
	int ret;

	ret = setup_mtd_device(&mtd_env);
	if (ret)
		return ret;

	ret = env_export(&env_new);
	if (ret)
		goto done;

	/* Write the copy that is not the one just loaded */
	if (IS_ENABLED(CONFIG_ENV_REDUNDANT) && gd->env_valid == ENV_VALID)
		base = CONFIG_ENV_OFFSET_REDUND;

	ret = env_mtd_save_one(mtd_env, base, &env_new);
	if (!IS_ENABLED(CONFIG_ENV_REDUNDANT))
		goto done;

	if (!ret) {
		gd->env_valid = gd->env_valid == ENV_VALID ? ENV_REDUND :
				ENV_VALID;
		goto done;
	}

	/* Fall back to the other copy, as env/nand.c */
	base = base == CONFIG_ENV_OFFSET ? CONFIG_ENV_OFFSET_REDUND :
			CONFIG_ENV_OFFSET;

	ret = env_mtd_save_one(mtd_env, base, &env_new);
	if (!ret)
		printf("Warning: primary env write failed,"
		       " redundancy is lost!\n");

done:
	put_mtd_device(mtd_env);

	return ret;
}

static int env_mtd_load(void)
{
	struct mtd_info *mtd_env;
	char *buf, *buf_red = NULL;
	int ret_red;
	int ret;

	buf = (char *)memalign(ARCH_DMA_MINALIGN, CONFIG_ENV_SIZE);
	if (!buf) {
		env_set_default("memalign() failed", 0);
		return -EIO;
	}

	ret = setup_mtd_device(&mtd_env);
	if (ret)
		goto out_nodev;

	if (IS_ENABLED(CONFIG_ENV_REDUNDANT)) {
		buf_red = (char *)memalign(ARCH_DMA_MINALIGN,
					   CONFIG_ENV_SIZE);
		if (!buf_red) {
			env_set_default("memalign() failed", 0);
			ret = -EIO;
			goto out;
		}

		ret = env_mtd_read_buf(mtd_env, CONFIG_ENV_OFFSET,
				       CONFIG_ENV_SIZE, buf);
		ret_red = env_mtd_read_buf(mtd_env, CONFIG_ENV_OFFSET_REDUND,
					   CONFIG_ENV_SIZE, buf_red);

		ret = env_import_redund(buf, ret, buf_red, ret_red,
					H_EXTERNAL);
		goto out;
	}

	ret = env_mtd_read_buf(mtd_env, CONFIG_ENV_OFFSET, CONFIG_ENV_SIZE,
			       buf);
	if (ret) {
		env_set_default("mtd_read() failed", 1);
		goto out;
	}

	ret = env_import(buf, 1, H_EXTERNAL);
	if (!ret)
		gd->env_valid = ENV_VALID;

out:
	put_mtd_device(mtd_env);

out_nodev:
	free(buf);

	if (buf_red)
		free(buf_red);

	return ret;
}

static int env_mtd_erase_one(struct mtd_info *mtd_env, u32 base)
{
	u32 sect_size, sect_num;
	char *saved_buf = NULL;
	int ret;

	sect_size = mtd_env->erasesize;

	/* Is the sector larger than the env (i.e. embedded) */
	if (sect_size > CONFIG_ENV_SIZE) {
		saved_buf = malloc(sect_size);
		if (!saved_buf)
			return -ENOMEM;

		ret = env_mtd_read_buf(mtd_env, base, sect_size, saved_buf);
		if (ret)
			goto done;
	}

	sect_num = DIV_ROUND_UP(CONFIG_ENV_SIZE, sect_size);

	ret = env_mtd_erase_range(mtd_env, base, sect_num * sect_size);
	if (ret)
		goto done;

	if (sect_size > CONFIG_ENV_SIZE) {
		memset(saved_buf, 0, CONFIG_ENV_SIZE);

		ret = env_mtd_write_buf(mtd_env, base, sect_size, saved_buf);
		if (ret)
			goto done;
	}

	ret = 0;

done:
	if (saved_buf)
		free(saved_buf);

	return ret;
}

static int env_mtd_erase(void)
{
	struct mtd_info *mtd_env;
	int ret;

	ret = setup_mtd_device(&mtd_env);
	if (ret)
		return ret;

	ret = env_mtd_erase_one(mtd_env, CONFIG_ENV_OFFSET);
	if (ret)
		goto done;

	if (IS_ENABLED(CONFIG_ENV_REDUNDANT))
		ret = env_mtd_erase_one(mtd_env, CONFIG_ENV_OFFSET_REDUND);

done:
	put_mtd_device(mtd_env);

	return ret;
}

__weak void *env_mtd_get_env_addr(void)
{
	return (void *)CONFIG_ENV_ADDR;
}

/*
 * Check if Environment on CONFIG_ENV_ADDR is valid.
 */
static int env_mtd_init_addr(void)
{
	env_t *env_ptr = (env_t *)env_mtd_get_env_addr();

	if (!env_ptr)
		return -ENOENT;

	if (crc32(0, env_ptr->data, ENV_SIZE) == env_ptr->crc) {
		gd->env_addr = (ulong)&env_ptr->data;
		gd->env_valid = ENV_VALID;
	} else {
		gd->env_valid = ENV_INVALID;
	}

	return 0;
}

static int env_mtd_init(void)
{
	/*
	 * -ENOENT propagates so env_init() can set the init bit, and the
	 * default environment is used if no other storage is defined.
	 */
	return env_mtd_init_addr();
}

U_BOOT_ENV_LOCATION(mtd_augentix) = {
	.location	= ENVL_MTD,
	ENV_NAME("MTD")
	.load		= env_mtd_load,
	.save		= ENV_SAVE_PTR(env_mtd_save),
	.erase		= ENV_ERASE_PTR(env_mtd_erase),
	.init		= env_mtd_init,
};
