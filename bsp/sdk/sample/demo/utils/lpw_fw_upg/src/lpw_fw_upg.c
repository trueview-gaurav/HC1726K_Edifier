#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "lpw_fw_upg.h"
#include "log.h"

//#define DEBUG

/* default setting */
#ifdef DEBUG
#define DBG(...) printf(__VA_ARGS__)
#else
#define DBG(...)
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

static int executeIfdownSafely(const char *cmd)
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

	if (token == NULL || strcmp(token, "ifdown") != 0) {
		parent_return_val = -1;
		goto cleanup;
	} else {
		args[i++] = "/sbin/ifdown";
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

static int executeKillallSafely(const char *cmd)
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

	if (token == NULL || strcmp(token, "killall") != 0) {
		parent_return_val = -1;
		goto cleanup;
	} else {
		args[i++] = "/usr/bin/killall";
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

static int executeRmmodSafely(const char *cmd)
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

	if (token == NULL || strcmp(token, "rmmod") != 0) {
		parent_return_val = -1;
		goto cleanup;
	} else {
		args[i++] = "/sbin/rmmod";
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

/**
 * @brief call libLPW API to upgrade the firmware of the Wi-Fi module
 * @details
 * @param[in] *new_fw_path path of new firmware
 * @return ret
 * @retval 0     upgrade success
 * @retval not 0 upgrade failure
 * @see
 */
int LPW_appUpgFw(unsigned char *new_fw_path)
{
	int ret = 0;
	lpw_handle hd;
	lpw_fw_ver_t fw_ver_before_upg;

	/* check new fw upgrade file is not null */
	if (new_fw_path == NULL) {
		log_err("new firmware path is null.\n");
		return -ENOENT;
	}

	/* initialize LPW handler */
	hd = lpw_open();
	if (hd == (lpw_handle)NULL) {
		log_err("open LPW device fail.\n");
		return -EPERM;
	}

	/* get the current version of firmware */
	lpw_module_get_version(hd, &fw_ver_before_upg);
	log_info("current firmware version : [%u.%u.%u]\n", fw_ver_before_upg.ver[0], fw_ver_before_upg.ver[1],
	         fw_ver_before_upg.ver[2]);

	/* call libLPW API to start the firmware upgrade */
	ret = lpw_fw_upg(hd, new_fw_path);
	if (ret != 0) {
		log_err("firmware upgrade fail. Error no. = %d\n", ret);
		ret = -EPERM;
		goto end;
	}
end:
	lpw_close(hd);

	if (ret == 0) { // upgrade success
		ret = executeIfdownSafely("ifdown wlan0");
		if (ret == -1) {
			log_err("Error executing system command.\n");
			return ret;
		}

		/* wait for Wi-Fi module proceed */
		sleep(5);
		printf("Wireless module FW upgrade success, please reboot!\n");

		ret = executeKillallSafely("killall lpw_controller");

		if (ret == -1) {
			log_err("Error executing system command.\n");
			return ret;
		}
#ifdef CONFIG_LPW_HI3861L
		ret = executeRmmodSafely("killall lpw_controller");

		if (ret == -1) {
			log_err("Error executing system command.\n");
			return ret;
		}
#endif
	}

	return ret;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
