/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/reboot.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#include "json.h"
#include "sqllib.h"

#include "cc_common.h"
#include "cc_utils.h"
#include "cc_data.h"
#include "cm_product_option.h"
#include "cm_venc_option.h"

static char g_json_buf[CC_JSON_STR_BUF_SIZE]; // or bigger array to append data to handle pkt defrag
static int g_jbuf_size; // val holds the string len , adds up when handle pkt defrag

static char* read_file_content(const char *file_path)
{
	int ret = 0;
	char *ptr = NULL;
	long fsize = 0;
	FILE *fp = NULL;
	size_t unused __attribute__((unused)) = 0;

	fp = fopen(file_path, "r");
	if (fp == NULL) {
		fprintf(stderr, "Failed to open file %s\n", file_path);
		goto end;
	}

	ret = fseek(fp, 0L, SEEK_END);
	if (ret) {
		fprintf(stderr, "Failed to seek file %s\n", file_path);
		goto free_fp;
	}

	fsize = ftell(fp);
	if (fsize < 0) {
		fprintf(stderr, "Failed to get file size %s\n", file_path);
		goto free_fp;
	}

	ret = fseek(fp, 0L, SEEK_SET);
	if (ret) {
		fprintf(stderr, "Failed to rewind file pointer for %s\n", file_path);
		goto free_fp;
	}

	ptr = (char *)malloc(fsize + 1);
	if (!ptr) {
		fprintf(stderr, "Failed to alloc memory for reading file\n");
		goto free_fp;
	}

	unused = fread(ptr, fsize, 1, fp);
	ptr[fsize] = '\0';

	if (ferror(fp)) {
		fprintf(stderr, "Failed to read file %s\n", file_path);
		free(ptr);
		ptr = NULL;
	}

free_fp:
	fclose(fp);

end:
	return ptr;
}

static void map_cmd_id(const CC_CMD_INFO_S **info, const char *str)
{
	int i = 0;
	const CC_CMD_INFO_S *p = NULL;

	for (i = 0; i < cmd_table_size; i++) {
		p = &cmd_table[i];

		if (strcmp(str, p->str) == 0) {
			*info = p;
			break;
		}
	}

	return;
}

static int send_data(int sd, void *data, long len)
{
	int n = 0;
	long offs = 0;
	char *p = (char *)data;

	do {
		n = send(sd, p + offs, len - offs, 0);

		if (n == -1) {
			break;
		}

		offs += n;
	} while (offs != len);

	return (offs == len) ? 0 : -1;
}

static int recv_data(int sd, void *buf, long len)
{
	int n = 0;
	long offs = 0;
	char *p = (char *)buf;

	do {
		n = recv(sd, p + offs, len - offs, 0);

		if (n == -1 || n == 0) {
			fprintf(stderr, "%s(): n = %d, errno = %d(%s)\n", __func__, n, errno, strerror(errno));
			continue;
		}

		offs += n;
	} while (offs != len);

	return (offs == len) ? 0 : -1;
}

static int control_module(int sd, uint32_t cmd_id, long size, void *data)
{
	int ret = 0, rval = 0;
	AGTX_MSG_HEADER_S header;

	header.cid = cmd_id;
	header.sid = 0;
	header.len = size;

	ret = send_data(sd, &header, sizeof(header));
	if (ret) {
		fprintf(stderr, "%s: failed to send header of cmd 0x%08X\n", __func__, cmd_id);
		return -1;
	}

	ret = send_data(sd, data, size);
	if (ret) {
		fprintf(stderr, "%s: failed to send data of cmd 0x%08X\n", __func__, cmd_id);
		return -1;
	}

	ret = recv_data(sd, &header, sizeof(header));
	if (ret) {
		fprintf(stderr, "%s: failed to receive header of cmd 0x%08X\n", __func__, cmd_id);
		return -1;

	}

	ret = recv_data(sd, &rval, sizeof(int));
	if (ret) {
		fprintf(stderr, "%s: failed to receive reply of cmd 0x%08X\n", __func__, cmd_id);
		return -1;
	}

	return rval;
}

static int inform_module(int sd, uint32_t cmd_id, long size, void *data)
{
	int ret = 0;
	AGTX_MSG_HEADER_S header;

	header.cid = cmd_id;
	header.sid = 0;
	header.len = size;

	ret = send_data(sd, &header, sizeof(header));
	if (ret) {
		fprintf(stderr, "%s: failed to send header of cmd 0x%08X\n", __func__, cmd_id);
		return -1;
	}

	ret = send_data(sd, data, size);
	if (ret) {
		fprintf(stderr, "%s: failed to send data of cmd 0x%08X\n", __func__, cmd_id);
		return -1;
	}

	return 0;
}


int validate_json_string_db(struct json_object **json_obj, char *str, int strlen)
{
	int ret = 0;
	struct json_object  *obj = NULL;
	struct json_tokener *tok = json_tokener_new();
	enum   json_tokener_error jerr;

	/* Parse the buf */
	if (strlen > 0) {
		obj = json_tokener_parse_ex(tok, str, strlen);
	} else {
		*json_obj = NULL;
		ret = -1;
		goto end;
	}

	jerr = json_tokener_get_error(tok);

	if (jerr == json_tokener_success) {
		*json_obj = obj;
	} else {
		fprintf(stderr, "JSON Parsing errorer %s \n", json_tokener_error_desc(jerr));

		*json_obj = NULL;
		ret = -1;
	}
end:
	json_tokener_free(tok);

	return ret;
}

int validate_json_string(struct json_object **json_obj, char *buf, int strlen)
{
	struct json_object  *obj;
	struct json_tokener *tok = json_tokener_new();
	enum   json_tokener_error jerr;

	/* Parse the buf */
	if (strlen > 0) {
		strncat(g_json_buf, buf, sizeof(g_json_buf) - strlen - 1);
		//	g_jbuf_size += strlen;  // size needed for pkt re-assembly
		g_jbuf_size = strlen;
		obj = json_tokener_parse_ex(tok, g_json_buf, g_jbuf_size);
	} else {
		/* TODO: check if needed */
		obj = json_tokener_parse_ex(tok, (char *)buf, g_jbuf_size);
	}

	jerr = json_tokener_get_error(tok);

	if (jerr != json_tokener_success) {
		fprintf(stderr, "JSON Tokener errNo: %d \n", jerr);
		fprintf(stderr, "JSON Parsing errorer %s \n", json_tokener_error_desc(jerr));

		bzero(g_json_buf, CC_JSON_STR_BUF_SIZE);
		json_tokener_free(tok);
		*json_obj = NULL;

		return -1;
	} else if (jerr == json_tokener_success) {
		//TODO: pass to sub-func's which parse a given key data type

		bzero(g_json_buf, CC_JSON_STR_BUF_SIZE);
		g_jbuf_size = 0;
	}

	json_tokener_free(tok);
	*json_obj = obj;

	return 0;
}

struct json_object* get_db_record_obj(const char *db_path, const int id)
{
	int ret = 0;
	char *rec = NULL;
	struct json_object *obj = NULL;

	rec = get_sqldata_by_id_str_path(db_path, "json_tbl", "jstr", id);
	if (!rec) {
		fprintf(stderr, "Record (id 0x%08X) is not in DB %s\n", id, db_path);
		goto end;
	}

	ret = validate_json_string_db(&obj, rec, strlen(rec));
	if (ret < 0) {
		fprintf(stderr, "Record (id 0x%08X) is not a valid JSON string\n", id);
		/* obj will be NULL pointer */
	}

	free(rec);
end:
	return obj;
}

static void execCommandAndGetOutput(const char *k_cmd, char *const k_args[], char *output, size_t output_size,
                                    int *exit_status)
{
	int pipefd[2];
	if (pipe(pipefd) == -1) {
		perror("pipe failed");
		return;
	}

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork failed");
		return;
	}

	if (pid == 0) {
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		execve(k_cmd, k_args, NULL);
		perror("execve failed");
		return;
	} else {
		close(pipefd[1]);

		ssize_t count = read(pipefd[0], output, output_size - 1);
		if (count > 0) {
			output[count] = '\0';
		} else {
			perror("read failed");
			output[0] = '\0';
		}

		close(pipefd[0]);
		int wstatus;
		waitpid(pid, &wstatus, 0);
		if (WIFEXITED(wstatus)) {
			*exit_status = WEXITSTATUS(wstatus);
		} else {
			*exit_status = -1;
		}
	}
}

static int touch(const char *filename)
{
	int fd = open(filename, O_CREAT | O_WRONLY, 0644);
	if (fd == -1) {
		perror("touch");
		return -1;
	}
	close(fd);
	return 0;
}

void trigger_reset_reboot(void)
{
	int ret = 0;
	char buf[256] = { 0 };
	char output[256] = { 0 };
	int unused __attribute__((unused)) = 0;

	snprintf(buf, sizeof(buf), "`cat %s`", DBMONITOR_PID_FILE);
	char *const args[] = { "/bin/kill", "-SIGTERM", buf, NULL };
	execCommandAndGetOutput("/bin/kill", args, output, sizeof(output), &ret);

	if (ret) {
		fprintf(stderr, "Failed to kill DBMONITOR\n");
	}

	char *const args2[] = { "/bin/cp", "-af", FACTORY_DEFAULT_DB, USRDATA_ACTIVE_DB, NULL };
	execCommandAndGetOutput("/bin/cp", args2, output, sizeof(output), &ret);

	if (ret) {
		fprintf(stderr, "Failed to reset database. Try to touch reset file\n");
		touch(RESET_FILE_PATH);
	}

	sync();
	reboot(RB_AUTOBOOT);
}

int set_data_to_active_db(struct json_object *ret_obj, struct json_object *cmd_obj,
                          int sd, uint32_t cmd_id, long size)
{
	int ret = 0;
	struct json_object *obj = NULL;
	void *data = NULL;
	PARSE_FUNC_S parse_func = NULL;
	COMP_FUNC_S comp_func = NULL;

	obj = get_db_record_obj(TMP_ACTIVE_DB, cmd_id);
	if (!obj) {
		fprintf(stderr, "Database %s might be corrupted and needs to be reset\n",
			TMP_ACTIVE_DB);
		trigger_reset_reboot();
	}

	data = malloc(size);
	if (!data) {
		fprintf(stderr, "%s: failed to allocate memory for cmd 0x%08X\n", __func__, cmd_id);
		ret = -1;
		goto free_obj;
	}

	ret = determine_func(&parse_func, &comp_func, cmd_id);
	if (ret) {
		fprintf(stderr, "%s: failed to find parsing and composing func\n", __func__);
		ret = -1;
		goto free_data;
	}

	if (cmd_id == AGTX_CMD_PRODUCT_OPTION) {
		init_product_option(data);
	} else if (cmd_id == AGTX_CMD_VENC_OPTION) {
		init_venc_option(data);
	} else {
		memset(data, 0, size);
	}

	parse_func(data, obj);
	parse_func(data, cmd_obj);

	if (sd != 0) {
		ret = control_module(sd, cmd_id, size, data);
	}

	if (ret == 0) {
		/* Compose JSON object with updated data */
		comp_func(ret_obj, data);

		/* Update SQL database */
		ret = update_sqldata_by_id_str_path(TMP_ACTIVE_DB, "json_tbl", cmd_id,
		                                    "jstr", json_object_to_json_string(ret_obj));
	} else {
		/* Compose JSON string with original data */
		fprintf(stderr, "%s: failed to set cmd 0x%08X\n", __func__, cmd_id);
	}
free_data:
	free(data);
free_obj:
	json_object_put(obj);

	return ret;
}

int get_data_from_active_db(struct json_object *ret_obj, int sd, uint32_t cmd_id, long size)
{
	int ret = 0;
	struct json_object *obj = NULL;
	void *data = NULL;
	PARSE_FUNC_S parse_func = NULL;
	COMP_FUNC_S comp_func = NULL;

	obj = get_db_record_obj(TMP_ACTIVE_DB, cmd_id);
	if (!obj) {
		fprintf(stderr, "Database %s might be corrupted and needs to be reset\n",
			TMP_ACTIVE_DB);
		trigger_reset_reboot();
	}

	data = malloc(size);
	if (!data) {
		fprintf(stderr, "%s: failed to allocate memory for cmd 0x%08X\n", __func__, cmd_id);
		ret = -1;
		goto free_obj;
	}

	ret = determine_func(&parse_func, &comp_func, cmd_id);
	if (ret) {
		fprintf(stderr, "%s: failed to find parsing and composing func\n", __func__);
		ret = -1;
		goto free_data;
	}

	if (cmd_id == AGTX_CMD_PRODUCT_OPTION) {
		init_product_option(data);
	} else if (cmd_id == AGTX_CMD_VENC_OPTION) {
		init_venc_option(data);
	} else {
		memset(data, 0, size);
	}

	parse_func(data, obj);

	if (sd != 0) {
		ret = inform_module(sd, cmd_id, size, data);
		if (ret) {
			fprintf(stderr, "%s: failed to inform module for cmd 0x%08X\n", __func__, cmd_id);
		}
	} else {
		comp_func(ret_obj, data);
		/* TODO: handle fail to compose JSON string */
	}
free_data:
	free(data);
free_obj:
	json_object_put(obj);

	return ret;
}

static bool isFileReadable(const char *k_filename)
{
	FILE *fh = NULL;
	struct stat sb;
	memset(&sb, 0x00, sizeof(sb));

	printf("enter; %s\n", k_filename);

	fh = fopen(k_filename, "r");
	if (!fh) {
		perror("fopen failed");
		goto fail;
	}

	if (fstat(fileno(fh), &sb) == -1) {
		perror("fstat failed");
		goto fail;
	}

	/* check whether it is a regular file or a symbolic link, rather than a device file descriptor */
	if (!S_ISREG(sb.st_mode) && !S_ISLNK(sb.st_mode)) {
		perror("Not a regular file or symbolic link");
		goto fail;
	}

	fclose(fh);
	fh = NULL;
	return true;

fail:
	if (fh) {
		fclose(fh);
	}
	printf("%s is not readable\n", k_filename);
	return false;
}

void update_cal_data(const char *cal_data, const char *flag_file, unsigned int force_update)
{
	void *data = NULL;
	char *fbuf = NULL, *rec = NULL;
	struct json_object *fobj = NULL, *jobj = NULL, *nobj = NULL;
	const CC_CMD_INFO_S *info = NULL;
	PARSE_FUNC_S parse_func = NULL;
	COMP_FUNC_S comp_func = NULL;
	unsigned int is_update = 0x0;
	int ret = 0;
	FILE *flag_fp = NULL;

	DECLARE_TIMEVAL(btime);
	DECLARE_TIMEVAL(etime);

	get_time(&btime);

	flag_fp = fopen(flag_file, "r");
	if (flag_fp) {
		is_update |= 0x1;
		fclose(flag_fp);

		ret = remove(flag_file);
		if (ret != 0) {
			fprintf(stderr, "Unable to delete file %s\n", flag_file);
		} else {
			fprintf(stderr, "File deleted succeed\n");
		}
	}

	if (force_update) {
		is_update |= 0x2;
	}

	if (is_update) {
		if (isFileReadable(cal_data) == false) {
			fprintf(stderr, "No cal file %s\n", cal_data);
			goto end;
		}

		fbuf = read_file_content(cal_data);
		if (!fbuf) {
			fprintf(stderr, "Failed to read content from file %s\n", cal_data);
			goto end;
		}

		fobj = json_tokener_parse(fbuf);
		if (!fobj) {
			fprintf(stderr, "Not a valid JSON string\n");
			goto free_fbuf;
		}

		ret = json_object_object_get_ex(fobj, "cmd_id", &nobj);
		if (!ret) {
			fprintf(stderr, "Failed to get command ID\n");
			goto free_fobj;
		}

		map_cmd_id(&info, json_object_get_string(nobj));
		if (!info) {
			fprintf(stderr, "Invalid command ID found\n");
			goto free_fobj;
		}

		ret = determine_func(&parse_func, &comp_func, info->cmd_id);
		if (ret) {
			fprintf(stderr, "Can not find parse and compose function\n");
			goto free_fobj;
		}

		ret = json_object_object_get_ex(fobj, "json_content", &nobj);
		if (!ret) {
			fprintf(stderr, "Failed to get JSON content\n");
			goto free_fobj;
		}

		rec = get_sqldata_by_id_str("json_tbl", "jstr", info->cmd_id);
		if (!rec) {
			fprintf(stderr, "Record (id 0x%08X) is not in DB\n", info->cmd_id);
			goto free_fobj;
		}

		ret = validate_json_string(&jobj, rec, strlen(rec));
		if (ret < 0) {
			fprintf(stderr, "Not a valid JSON string\n");
			goto free_rec;
		}

		data = malloc(info->size);
		if (!data) {
			fprintf(stderr, "No memory\n");
			goto free_jobj;
		}

		memset(data, 0, info->size);

		parse_func(data, jobj);
		parse_func(data, nobj);

		nobj = json_object_new_object();
		if (!nobj) {
			fprintf(stderr, "Cannot new a JSON object\n");
			goto free_data;
		}

		comp_func(nobj, data);
		update_sqldata_by_id_str("json_tbl", info->cmd_id, "jstr", json_object_to_json_string(nobj));

		json_object_put(nobj);

		fprintf(stderr, "Update %s succeed with value 0x%X\n", cal_data, is_update);
free_data:
		free(data);
free_jobj:
		json_object_put(jobj);
free_rec:
		free(rec);
free_fobj:
		json_object_put(fobj);
free_fbuf:
		free(fbuf);
	}
end:
	get_time(&etime);
	print_timediff(btime, etime);

	return;
}

ssize_t readn(int fd, void *buffer, size_t n)
{
	ssize_t num_read; /* # of bytes fetched by last read() */
	size_t total_read; /* Total # of bytes read so far */
	char *buf;
	buf = buffer; /* No pointer arithmetic on "void *" */
	for (total_read = 0; total_read < n; ) {
		num_read = read(fd, buf, n - total_read);
		if (num_read == 0) /* EOF */
			return total_read; /* May be 0 if this is first read() */
		if (num_read == -1) {
			if (errno == EINTR)
				continue; /* Interrupted --> restart read() */
			else
				return -1; /* Some other error */
		}
		total_read += num_read;
		buf += num_read;
	}
	return total_read; /* Must be 'n' bytes if we get here */
}

ssize_t writen(int fd, void *buffer, size_t n)
{
	ssize_t num_written; /* # of bytes written by last write() */
	size_t total_written; /* Total # of bytes written so far */
	const char *buf;
	buf = buffer; /* No pointer arithmetic on "void *" */
	for (total_written = 0; total_written < n; ) {
		num_written = write(fd, buf, n - total_written);
		if (num_written <= 0) {
			if (num_written == -1 && errno == EINTR)
				continue; /* Interrupted --> restart write() */
			else
				return -1; /* Some other error */
		}
		total_written += num_written;
		buf += num_written;
	}
	return total_written; /* Must be 'n' bytes if we get here */
}
