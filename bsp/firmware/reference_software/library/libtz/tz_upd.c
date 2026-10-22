/*
 * AUGENTIX INC. - PROPRIETARY
 *
 * tz_update.c - library for update timezone
 * Copyright (C) 2018-2019 Augentix Inc. - All Rights Reserved
 *
 * NOTICE: The information contained herein is the property of Augentix Inc.
 * Copying and distributing of this file, via any medium,
 * must be licensed by Augentix Inc.
 *
 * * Brief: library for update timezone
 * *
 * * Author: Henry Liu <henry.liu@augentix.com>
 */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <sys/inotify.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include "agtx_types.h"

#define TZ_THREAD_UPDATE_TZ_NAME "update_tz"
#define TZ_FILE_PATH "/etc/TZ"
#define DST_ENABLE_PATH "/usrdata/active_setting/timeMode.conf"

pthread_t threadUpdateTimeZone;
int isDst = 0;

static void getTz(void)
{
	FILE *fp_tz;
	char buffer[128];

	fp_tz = fopen(TZ_FILE_PATH, "r");
	if (fp_tz) {
		fgets(buffer, 128, fp_tz);
		fclose(fp_tz);
		setenv("TZ", buffer, 1);
		tzset();
	}
}

int getDst(void)
{
	FILE *fp_DST;
	char buffer[128];
	char temp_buf[128] = { 0 };

	fp_DST = fopen(DST_ENABLE_PATH, "rb");
	if(fp_DST) {
		while(fgets(buffer, 128, fp_DST)!=NULL) {
			if (sscanf(buffer, "DST_enabled=%127[^\n]", temp_buf) != 0) {
				snprintf(buffer, sizeof(buffer), "%s", temp_buf);
				isDst = atoi(buffer);
			}
		}
	}
	fclose(fp_DST);
	fp_DST = NULL;
	return isDst;
}

static int executeSetDstSafely(const char *cmd)
{
	pid_t pid;
	int status = 0;
	pid_t ret = 0;
	char *args[32] = { NULL };
	extern char **environ;
	int parent_return_val = 0;

	char *cmd_copy = strdup(cmd);
	if (cmd_copy == NULL) {
		return -1;
	}

	char *token = strtok(cmd_copy, " ");
	int i = 0;

	if (token == NULL || strcmp(token, "/system/bin/setDST_en.sh") != 0) {
		parent_return_val = -1;
		goto cleanup;
	} else {
		args[i++] = "/system/bin/setDST_en.sh";
	}

	while ((token = strtok(NULL, " ")) != NULL) {
		if (i >= 31) {
			parent_return_val = -1;
			goto cleanup;
		}
		args[i++] = token;
	}

	args[i] = NULL;

	pid = fork();
	if (pid == -1) {
		parent_return_val = -1;
		goto cleanup;
	} else if (pid != 0) {
		/* parent waits on child */
		while ((ret = waitpid(pid, &status, 0)) == -1) {
			if (errno != EINTR) {
				parent_return_val = -1;
				goto cleanup;
			}
		}

		if ((ret == 0) || !(WIFEXITED(status) && !WEXITSTATUS(status))) {
			parent_return_val = -1;
			goto cleanup;
		}
	} else {
		/* child */
		if (execve(args[0], args, environ) == -1) {
			_Exit(127); // child process memory (including cmd_copy) is freed by OS on exit
		}
	}

cleanup:
	free(cmd_copy);
	return parent_return_val;
}

int setDst(int enabled)
{
	char buffer[128] = { 0 };
	snprintf(buffer, sizeof(buffer), "/system/bin/setDST_en.sh setDST %d", enabled);
	if (executeSetDstSafely(buffer) != 0) {
		return -1;
	}
	return 0;
}

static int executeEchoSafely(const char *cmd)
{
	pid_t pid;
	int status = 0;
	pid_t ret = 0;
	char *args[32] = { NULL };
	extern char **environ;
	int parent_return_val = 0;

	char *cmd_copy = strdup(cmd);
	if (cmd_copy == NULL) {
		return -1;
	}

	char *token = strtok(cmd_copy, " ");
	int i = 0;

	if (token == NULL || strcmp(token, "echo") != 0) {
		parent_return_val = -1;
		goto cleanup;
	} else {
		args[i++] = "/bin/echo";
	}

	while ((token = strtok(NULL, " ")) != NULL) {
		if (i >= 31) {
			parent_return_val = -1;
			goto cleanup;
		}
		args[i++] = token;
	}

	args[i] = NULL;

	pid = fork();
	if (pid == -1) {
		parent_return_val = -1;
		goto cleanup;
	} else if (pid != 0) {
		/* parent waits on child */
		while ((ret = waitpid(pid, &status, 0)) == -1) {
			if (errno != EINTR) {
				parent_return_val = -1;
				goto cleanup;
			}
		}

		if ((ret == 0) || !(WIFEXITED(status) && !WEXITSTATUS(status))) {
			parent_return_val = -1;
			goto cleanup;
		}
	} else {
		/* child */
		if (execve(args[0], args, environ) == -1) {
			_Exit(127); // child process memory (including cmd_copy) is freed by OS on exit
		}
	}

cleanup:
	free(cmd_copy);
	return parent_return_val;
}

int setTimeinfo(int DSTenabled, char *TZ)
{
	char buffer[128] = { 0 };
	snprintf(buffer, sizeof(buffer), "echo -n \"%s\" > /etc/TZ", TZ);
	executeEchoSafely(buffer);
	setenv("TZ", TZ, 1);
	tzset();

	if (setDst(DSTenabled) != 0){
		return -1;
	}
	return 0;
}

static void cleanupTimeZone(int *desc)
{
	int fd = desc[0];
	int wd = desc[1];

	inotify_rm_watch(fd, wd);
	close(fd);
}

static void *updateTimeZone(void *data)
{
	AGTX_UNUSED(data);
	char buffer[128];
	int fd = -1;
	int wd = -1;
	fd_set readfds;
	int ret = 0;
	int desc[2];

	getTz();

	fd = inotify_init();
	assert(fd != -1);

	wd = inotify_add_watch(fd, TZ_FILE_PATH, IN_CLOSE_WRITE);
	assert(wd != -1);

	desc[0] = fd;
	desc[1] = wd;
	pthread_cleanup_push(cleanupTimeZone, desc);

	while (1) {
		FD_ZERO(&readfds);
		FD_SET(fd, &readfds);
		ret = select(fd + 1, &readfds, 0, 0, NULL);
		if (ret == -1) {
			continue;
		}
		ret = read(fd, buffer, 128);
		if (ret <= 0) {
			continue;
		}
		getTz();
	}

	pthread_cleanup_pop(1);
	return NULL;
}

int enableTzUpdate(void)
{
	int ret = pthread_create(&threadUpdateTimeZone, NULL, updateTimeZone, TZ_THREAD_UPDATE_TZ_NAME);
	if (ret < 0) {
		return ret;
	}
	pthread_setname_np(threadUpdateTimeZone, TZ_THREAD_UPDATE_TZ_NAME);
	return 0;
}

int disableTzUpdate(void)
{
	int32_t ret = 0;

	ret = pthread_cancel(threadUpdateTimeZone);
	if (ret < 0) {
		return ret;
	}

	ret = pthread_join(threadUpdateTimeZone, NULL);
	return ret;
}
