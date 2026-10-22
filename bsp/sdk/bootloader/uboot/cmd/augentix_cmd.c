#include <common.h>
#include <command.h>
#include <console.h>
#include <mmc.h>
#include <u-boot/crc.h>

#define EMMC_BURN_PARTTBL_ADDR 0x3000000
#define GPT_BLK_SIZE 34
#define MMC_BLK_SIZE 0x200
#define MMC_ERASE_UNIT 0x400
#define MMC_LARGE_ERASE_UNIT (MMC_ERASE_UNIT * 1000)
#define INIT_BLK_PARTTBL 0x400 // to avoid erasing PARTTBL
#define MMC_BLK_SHIFT 9
#define ALIGN_UP(x, a) (((x) + ((a)-1)) & ~((a)-1))
#define BYTES_TO_BLK(size) (ALIGN_UP(size, MMC_BLK_SIZE) >> MMC_BLK_SHIFT)
#define BLK_TO_BYTES(size) (size << MMC_BLK_SHIFT)
#define LOG_REQ(req_name, fmt, ...) printf("REQ(%s:" fmt ")\n", req_name, ##__VA_ARGS__)

typedef struct __attribute__((packed)) emmc_burn_partition_table {
	char pt_name[16];
	uint32_t pt_blk_start;
	uint32_t pt_blk_size;
	uint32_t img_start;
	uint32_t img_blk_size;
} EmmcBurnPartTable;

typedef struct __attribute__((packed)) emmc_burn_config {
	uint32_t part_num;
	EmmcBurnPartTable pt_list[20];
	uint64_t capacity_blk_cnt;
} EmmcBurnConfig;

static int req_fail(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	LOG_REQ("IMG_FAIL", "%s", argv[1]);
	return CMD_RET_SUCCESS;
}
U_BOOT_CMD(req_fail, 1, 0, req_fail, "req_fail", "");

static int req_done(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	LOG_REQ("DONE", "%s", argv[1]);
	return CMD_RET_SUCCESS;
}
U_BOOT_CMD(req_done, 2, 0, req_done, "req_done", "");

static int exec_mmc_cmd(const char *fmt, ...)
{
	char buf[64];
	va_list args;

	va_start(args, fmt);
	vsnprintf(buf, sizeof(buf), fmt, args);
	va_end(args);

	return run_command(buf, 0);
}

#define MMC_CMD(fmt, ...)                     \
	if (exec_mmc_cmd(fmt, ##__VA_ARGS__)) \
	goto burn_fail

static int parse_tbl(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	int i;
	struct mmc *mmc;
	u32 temp_blk_cnt;
	char pt_start_kb[16];
	char pt_size_kb[16];
	char part_buf[500];
	int offset = 0;
	EmmcBurnConfig *p = (EmmcBurnConfig *)EMMC_BURN_PARTTBL_ADDR;

	mmc = find_mmc_device(0);
	if (!mmc) {
		return CMD_RET_FAILURE;
	}

	mmc_init(mmc);
	p->capacity_blk_cnt = BYTES_TO_BLK(mmc->capacity);
	printf("capacity_blk_cnt = 0x%llx\n", p->capacity_blk_cnt);

	for (i = 0; i < p->part_num; i++) {
		printf("[Partition %d: %s]\n\tbase = 0x%08x, size = 0x%08x\n", i, p->pt_list[i].pt_name,
		       p->pt_list[i].pt_blk_start, p->pt_list[i].pt_blk_size);
		printf("\timg_addr = 0x%08x, size = 0x%08x\n", p->pt_list[i].img_start, p->pt_list[i].img_blk_size);
		if (p->pt_list[i].pt_blk_size == 0 || !strcmp(p->pt_list[i].pt_name, "boot"))
			continue;
		snprintf(pt_start_kb, sizeof(pt_start_kb), "%uK", p->pt_list[i].pt_blk_start >> 1);
		snprintf(pt_size_kb, sizeof(pt_size_kb), "%uK", p->pt_list[i].pt_blk_size >> 1);
		if (i == p->part_num - 1) {
			snprintf(pt_size_kb, sizeof(pt_size_kb), "%c", '-');
			temp_blk_cnt = p->pt_list[i].pt_blk_start + p->pt_list[i].img_blk_size;
			if (temp_blk_cnt > p->capacity_blk_cnt) {
				printf("total used blk size 0x%x > mmc capacity 0x%llx\n", temp_blk_cnt,
				       p->capacity_blk_cnt);
				return CMD_RET_FAILURE;
			}
		}
		offset += snprintf(part_buf + offset, sizeof(part_buf) - offset, "name=%s,start=%s,size=%s;",
		                   p->pt_list[i].pt_name, pt_start_kb, pt_size_kb);
	}
	setenv("partitions", part_buf);

	return CMD_RET_SUCCESS;
}

U_BOOT_CMD(parse_tbl, 1, 0, parse_tbl, "parse burn table", "");

#define PART_START_LBA_OFS 0x20
#define PART_END_LBA_OFS 0x28
#define PART_LABEL_OFS 0x38
#define PART_ENTRY_OFS 0x80

static int parse_mmc_part(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	char pt_name[20][16] = { "" };
	uint32_t pt_blk_start[20];
	uint32_t pt_blk_size[20];
	uint32_t label;
	int i = 0;
	int j = 0;
	int curr_part_num;
	uint32_t checked_pt_blk_size;
	EmmcBurnConfig *p = (EmmcBurnConfig *)EMMC_BURN_PARTTBL_ADDR;

	// read parttbl in mmc, Partition Entry Array starts from block 2
	MMC_CMD("mmc read 0 2 0x20");

	for (;;) {
		label = PART_LABEL_OFS + j * PART_ENTRY_OFS;
		if (*(volatile uint8_t *)(label) == 0) {
			curr_part_num = j;
			break;
		}

		pt_blk_start[j] = *(volatile uint32_t *)(PART_START_LBA_OFS + j * PART_ENTRY_OFS);
		pt_blk_size[j] = *(volatile uint32_t *)(PART_END_LBA_OFS + j * PART_ENTRY_OFS) + 1 - pt_blk_start[j];
		for (i = 0;; i += 1) {
			if (*(volatile uint8_t *)(label + i * 0x2) == 0)
				break;
			memcpy(&pt_name[j][i], (void *)(label + i * 0x2), 1);
		}
		printf("pt_blk_start = 0x%x, pt_blk_size = 0x%x, label = %s\n", pt_blk_start[j], pt_blk_size[j],
		       pt_name[j]);
		j++;
	}

	for (i = 0; i < p->part_num; i++) {
		if (!(strcmp(p->pt_list[i].pt_name, "boot")))
			continue;
		if (i == (p->part_num - 1)) {
			checked_pt_blk_size = (p->capacity_blk_cnt - GPT_BLK_SIZE + 1) - p->pt_list[i].pt_blk_start;
			printf("checked_pt_blk_size 0x%x\n", checked_pt_blk_size);
		} else {
			checked_pt_blk_size = p->pt_list[i].pt_blk_size;
			printf("checked_pt_blk_size 0x%x\n", checked_pt_blk_size);
		}
		for (j = 0; j < curr_part_num; j++) {
			if ((strcmp(p->pt_list[i].pt_name, pt_name[j]) == 0) &&
			    (pt_blk_start[j] == p->pt_list[i].pt_blk_start) &&
			    (pt_blk_size[j] == checked_pt_blk_size)) {
				printf("Partition %d: %s matched\n", i, pt_name[j]);
				break;
			}
		}
		if (j == curr_part_num) {
			printf("not matched with current partition table, run emmc_partition_check\n");
			return CMD_RET_FAILURE;
		}
	}
	printf("partition layout correct, skip emmc_partition_check\n");
	return CMD_RET_SUCCESS;

burn_fail:
	LOG_REQ("IMG_FAIL", "%d", 15);
	while (1)
		;
}

U_BOOT_CMD(parse_mmc_part, 1, 0, parse_mmc_part, "parse_mmc_part", "");

static int image_crc32_check(uint32_t part_start_blk, uint32_t img_start_addr, uint32_t img_blkcnt)
{
	uint32_t crc32_1, crc32_2;
	uint32_t size = BLK_TO_BYTES(img_blkcnt);

	crc32_1 = crc32(0, (const unsigned char *)img_start_addr, size);
	MMC_CMD("mmc read 0x%x 0x%x 0x%x", img_start_addr, part_start_blk, img_blkcnt);
	crc32_2 = crc32(0, (const unsigned char *)img_start_addr, size);

	if (crc32_1 != crc32_2) {
		printf("img crc32 compare failed\n");
		return 1;
	}

	return 0;
burn_fail:
	LOG_REQ("IMG_FAIL", "%d", 15);
	while (1)
		;
}

static int emmc_part_burn(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
	int i = 0;
	static int first_flag = 1;
	uint32_t part_start_blk;
	uint32_t part_blkcnt;
	uint32_t img_start_addr;
	uint32_t img_blkcnt;
	uint32_t erased_blk = INIT_BLK_PARTTBL;
	uint32_t target_erase_blkcnt = 0;
	uint32_t part_end_blk;
	uint32_t temp;
	EmmcBurnConfig *p = (EmmcBurnConfig *)EMMC_BURN_PARTTBL_ADDR;

	for (i = 0; i < p->part_num; i++) {
		part_start_blk = p->pt_list[i].pt_blk_start;
		part_blkcnt = p->pt_list[i].pt_blk_size;
		img_start_addr = p->pt_list[i].img_start;
		img_blkcnt = p->pt_list[i].img_blk_size;

		if (!strcmp(p->pt_list[i].pt_name, "boot")) {
			MMC_CMD("mmc dev 0 1");
			LOG_REQ("eprog", "%d,0", i);
			MMC_CMD("mmc erase 0 0x%x", part_blkcnt);
			LOG_REQ("eprog", "%d,100", i);

			LOG_REQ("prog", "%d,0", i);
			MMC_CMD("mmc write 0x%x 0 0x%x", img_start_addr, img_blkcnt);
			if (image_crc32_check(0, img_start_addr, img_blkcnt))
				goto burn_fail;

			MMC_CMD("mmc dev 0 2");
			MMC_CMD("mmc erase 0 0x%x", part_blkcnt);
			MMC_CMD("mmc write 0x%x 0 0x%x", img_start_addr, img_blkcnt);
			if (image_crc32_check(0, img_start_addr, img_blkcnt))
				goto burn_fail;
			LOG_REQ("prog", "%d,100", i);
			MMC_CMD("mmc dev 0 0");
		} else {
			if (first_flag) {
				erased_blk = (part_start_blk > INIT_BLK_PARTTBL) ? part_start_blk : INIT_BLK_PARTTBL;
				first_flag = 0;
			}
			temp = 0;
			part_end_blk = ALIGN_UP((part_start_blk + part_blkcnt), MMC_ERASE_UNIT);

			/* erased blk should be less than capacity - GPT_BLK_SIZE (backup GPT) */
			if (part_end_blk > (p->capacity_blk_cnt - GPT_BLK_SIZE))
				part_end_blk = (p->capacity_blk_cnt - GPT_BLK_SIZE) & ~(MMC_ERASE_UNIT - 1);

			if (part_end_blk > erased_blk) {
				LOG_REQ("eprog", "%d,0", i);
				target_erase_blkcnt = part_end_blk - erased_blk;
				while (part_end_blk - erased_blk >= MMC_LARGE_ERASE_UNIT) {
					MMC_CMD("mmc erase 0x%x 0x%x", erased_blk, MMC_LARGE_ERASE_UNIT);
					erased_blk += MMC_LARGE_ERASE_UNIT;
					temp++;
					LOG_REQ("eprog", "%d,%u", i,
					        temp * 100 / (target_erase_blkcnt / (MMC_LARGE_ERASE_UNIT)));
				}
				MMC_CMD("mmc erase 0x%x 0x%x", erased_blk, part_end_blk - erased_blk);
				LOG_REQ("eprog", "%d,100", i);
				erased_blk = part_end_blk;
			}
			if (img_blkcnt) {
				LOG_REQ("prog", "%d,0", i);
				MMC_CMD("mmc write 0x%x 0x%x 0x%x", img_start_addr, part_start_blk, img_blkcnt);
				if (image_crc32_check(part_start_blk, img_start_addr, img_blkcnt))
					goto burn_fail;
				LOG_REQ("prog", "%d,100", i);
			}
		}
	}

	return CMD_RET_SUCCESS;
burn_fail:
	LOG_REQ("IMG_FAIL", "%d", 15);
	while (1)
		;
}

U_BOOT_CMD(emmc_part_burn, 1, 0, emmc_part_burn, "emmc_part_burn", "");
