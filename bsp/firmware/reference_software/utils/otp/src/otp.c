#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <generated/autoconf.h>

#define DEVFILE "/dev/otp_agtx"
#define ROT_DEBUG 0

struct otp_vendor {
	uint32_t vendor_id[1];
};

struct otp_user {
	uint32_t user_custom[4];
};

#ifdef CONFIG_SAPPORO
#define OTP_KEY_LEN 8
#else
#define OTP_KEY_LEN 7
#endif
struct otp_key_buffer {
	uint32_t data[OTP_KEY_LEN];
};

#define OTP_ID 'f'
#define OTP_READ_VENDOR_ID _IOR(OTP_ID, 0, struct otp_vendor)
#define OTP_READ_USER _IOR(OTP_ID, 1, struct otp_user)
#define OTP_WRITE_USER _IOW(OTP_ID, 2, struct otp_user)
#define OTP_DOWNLOAD_KEY _IOW(OTP_ID, 3, uint32_t[OTP_KEY_LEN])
#define OTP_CHECK_KEY _IOR(OTP_ID, 4, uint32_t[OTP_KEY_LEN])
#define OTP_ENABLE_SECURE _IO(OTP_ID, 5)
#define OTP_DISABLE_DEBUG _IO(OTP_ID, 6)

typedef enum { OTP_OK = 0, OTP_SKIP, OTP_FAIL, ROT_EMPTY, ROT_MISMATCH } otp_result_t;

static const char *result_str[] = { [OTP_OK] = "[OK]",
	                            [OTP_SKIP] = "[SKIP]",
	                            [OTP_FAIL] = "[FAIL]",
	                            [ROT_EMPTY] = "[EMPTY]",
	                            [ROT_MISMATCH] = "[MISMATCH]" };

#define OTP_PRINT(cmd, r) printf("%s %s\n", (cmd), result_str[r])
#define GET_IOCTL_RES(ret) ((ret) == 0 ? OTP_OK : (errno == EEXIST ? OTP_SKIP : OTP_FAIL))

static inline int parse_hex_array(char *argv[], uint32_t *out, int count)
{
	char *endptr;
	int i;

	for (i = 0; i < count; i++) {
		out[i] = (uint32_t)strtoul(argv[i], &endptr, 0);
		if (*endptr != '\0') {
			fprintf(stderr, "Invalid hex at arg %d: %s\n", i, argv[i]);
			return -1;
		}
	}

	return 0;
}

static inline int is_all_zeros(const uint32_t *data, int count)
{
	uint32_t combined = 0;
	int i;

	for (i = 0; i < count; i++)
		combined |= data[i];

	return combined == 0;
}

static otp_result_t cmd_read_vendor(int fd, int argc, char *argv[])
{
	struct otp_vendor data;
	int ret;
	(void)argc;
	(void)argv;

	memset(&data, 0, sizeof(data));
	ret = ioctl(fd, OTP_READ_VENDOR_ID, &data);
	if (ret == 0)
		printf("read_vendor: 0x%08x [OK]\n", data.vendor_id[0]);
	else
		OTP_PRINT("read_vendor", OTP_FAIL);

	return ret == 0 ? OTP_OK : OTP_FAIL;
}

static otp_result_t cmd_read_user(int fd, int argc, char *argv[])
{
	struct otp_user data;
	int ret;
	(void)argc;
	(void)argv;

	memset(&data, 0, sizeof(data));
	ret = ioctl(fd, OTP_READ_USER, &data);
	if (ret == 0)
		printf("read_user: 0x%08x 0x%08x 0x%08x 0x%08x [OK]\n", data.user_custom[0], data.user_custom[1],
		       data.user_custom[2], data.user_custom[3]);
	else
		OTP_PRINT("read_user", OTP_FAIL);

	return ret == 0 ? OTP_OK : OTP_FAIL;
}

static otp_result_t cmd_write_user(int fd, int argc, char *argv[])
{
	struct otp_user data;
	otp_result_t r;
	int ret;
	(void)argc;

	if (parse_hex_array(&argv[2], data.user_custom, 4) != 0)
		return OTP_FAIL;

	if (is_all_zeros(data.user_custom, 4)) {
		fprintf(stderr, "Error: write_user data cannot be all zeros.\n");
		return OTP_FAIL;
	}

	ret = ioctl(fd, OTP_WRITE_USER, &data);
	r = GET_IOCTL_RES(ret);
	OTP_PRINT("write_user", r);

	return r;
}

static otp_result_t cmd_download_key(int fd, int argc, char *argv[])
{
	struct otp_key_buffer key;
	otp_result_t r;
	int ret;
	(void)argc;

	if (parse_hex_array(&argv[2], key.data, OTP_KEY_LEN) != 0)
		return OTP_FAIL;

	if (is_all_zeros(key.data, OTP_KEY_LEN)) {
		fprintf(stderr, "Error: download_key data cannot be all zeros.\n");
		return OTP_FAIL;
	}

	ret = ioctl(fd, OTP_DOWNLOAD_KEY, &key);
	r = GET_IOCTL_RES(ret);
	OTP_PRINT("download_key", r);

	return r;
}

static otp_result_t cmd_check_key(int fd, int argc, char *argv[])
{
	struct otp_key_buffer expected, actual;
	int ret, i;
	(void)argc;

	if (parse_hex_array(&argv[2], expected.data, OTP_KEY_LEN) != 0)
		return OTP_FAIL;

	memset(&actual, 0, sizeof(actual));
	ret = ioctl(fd, OTP_CHECK_KEY, &actual);
	if (ret == -1) {
		OTP_PRINT("check_key", OTP_FAIL);
		return OTP_FAIL;
	}

	for (i = 0; i < OTP_KEY_LEN; i++) {
		if (actual.data[i] != 0)
			break;
	}

	if (i == OTP_KEY_LEN) {
		OTP_PRINT("check_key", ROT_EMPTY);
		return ROT_EMPTY;
	}

#if ROT_DEBUG
	fprintf(stderr, "expected:");
	for (i = 0; i < OTP_KEY_LEN; i++)
		fprintf(stderr, " 0x%08x", expected.data[i]);
	fprintf(stderr, "\n");
	fprintf(stderr, "actual:  ");
	for (i = 0; i < OTP_KEY_LEN; i++)
		fprintf(stderr, " 0x%08x", actual.data[i]);
	fprintf(stderr, "\n");
#endif

	if (memcmp(&expected, &actual, sizeof(actual)) == 0) {
		OTP_PRINT("check_key", OTP_OK);
		return OTP_OK;
	}

	OTP_PRINT("check_key", ROT_MISMATCH);
	return ROT_MISMATCH;
}

static otp_result_t cmd_enable_secure(int fd, int argc, char *argv[])
{
	otp_result_t r;
	(void)argc;
	(void)argv;

	r = GET_IOCTL_RES(ioctl(fd, OTP_ENABLE_SECURE, NULL));
	OTP_PRINT("enable_secure", r);

	return r;
}

static otp_result_t cmd_disable_debug(int fd, int argc, char *argv[])
{
	otp_result_t r;
	(void)argc;
	(void)argv;

	r = GET_IOCTL_RES(ioctl(fd, OTP_DISABLE_DEBUG, NULL));
	OTP_PRINT("disable_debug", r);

	return r;
}

typedef otp_result_t (*cmd_handler_t)(int fd, int argc, char *argv[]);

typedef struct {
	const char *name;
	int min_argc;
	int max_argc;
	cmd_handler_t handler;
	const char *usage;
} otp_command_t;

#define KEY_ARGC (2 + OTP_KEY_LEN)

static const otp_command_t commands[] = {
	{ "read_vendor", 2, 2, cmd_read_vendor, "Read vendor ID" },
	{ "read_user", 2, 2, cmd_read_user, "Read user custom data (4 words)" },
	{ "write_user", 6, 6, cmd_write_user, "<w0> <w1> <w2> <w3>  Write 4-word user custom data" },
	{ "download_key", KEY_ARGC, KEY_ARGC, cmd_download_key, "<w0> ... <wN>  Write Public Key Hash (ROT)" },
	{ "check_key", KEY_ARGC, KEY_ARGC, cmd_check_key, "<w0> ... <wN>  Verify Public Key Hash matches OTP" },
	{ "enable_secure", 2, 2, cmd_enable_secure, "Permanently enable secure boot" },
	{ "disable_debug", 2, 2, cmd_disable_debug, "Permanently disable debug ports (JTAG/I2C)" },
	{ NULL, 0, 0, NULL, NULL }
};

static void usage(const char *app_name)
{
	const otp_command_t *cmd;

	fprintf(stderr, "Usage: %s <command> [args...]\n\n", app_name);
	fprintf(stderr, "Commands:\n");
	for (cmd = commands; cmd->name != NULL; cmd++)
		fprintf(stderr, "  %-14s %s\n", cmd->name, cmd->usage);
}

static const otp_command_t *find_command(const char *name)
{
	const otp_command_t *cmd;

	for (cmd = commands; cmd->name != NULL; cmd++) {
		if (strcmp(name, cmd->name) == 0)
			return cmd;
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	const otp_command_t *cmd;
	otp_result_t r;
	int fd;

	if (argc < 2) {
		usage(argv[0]);
		return 1;
	}

	cmd = find_command(argv[1]);
	if (!cmd) {
		fprintf(stderr, "Error: Unknown command '%s'\n", argv[1]);
		usage(argv[0]);
		return 1;
	}

	if (argc < cmd->min_argc || argc > cmd->max_argc) {
		if (cmd->min_argc == cmd->max_argc)
			fprintf(stderr, "Error: %s requires exactly %d arguments.\n", cmd->name, cmd->min_argc - 2);
		else
			fprintf(stderr, "Error: %s requires %d-%d arguments.\n", cmd->name, cmd->min_argc - 2,
			        cmd->max_argc - 2);
		usage(argv[0]);
		return 1;
	}

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
		perror("open");
		return 1;
	}

	r = cmd->handler(fd, argc, argv);

	close(fd);
	return (r <= OTP_SKIP) ? 0 : 1;
}
