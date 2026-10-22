#define _GNU_SOURCE

#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <ftw.h>
#include <errno.h>

#include "inc/fcgi.h"
#include "inc/utils.h"
#include <fcgi_stdio.h>
#include <json.h>
#include <dirent.h>

int wait_module_unload(const char *sysfs_module, int retry, int sleep_us)
{
	for (int i = 0; i < retry; i++) {
		if (access(sysfs_module, F_OK) != 0) {
			return 0; // module removed successfully.
		}

		usleep(sleep_us);
	}

	return -1; // timeout
}

void fcgiGetUploadFile(char *name)
{
	FILE *fp;
	char key[100];
	char buf[2048];
	int size, idx, keylen, check_len, match_flag;

	if ((fp = fopen(name, "wb")) != NULL) {
		key[0] = '\r';
		key[1] = '\n';
		match_flag = 0;
		fgets(&key[2], 100, stdin);
		// fprintf(fp,"key:%s\n",key);
		keylen = strlen(key) - 4;
		key[keylen] = 0;

		do {
			fgets(buf, 2048, stdin);
			size = strlen(buf);
			// fprintf(fp,"pass:%s size:%d",buf,size);
		} while (size > 2); // bypass all the header

		size = fread(buf, 1, keylen - 1, stdin);

		if (size < keylen - 1) {
			return;
		}

		check_len = 2049 - keylen;

		while ((size = fread(&buf[keylen - 1], 1, check_len, stdin)) > 0) {
			check_len = size;
			idx = 0;

			for (idx = 0; idx < check_len; idx++) {
				int i;
				int str_flag = 1;

				for (i = 0; i < keylen; i++) {
					str_flag = (buf[idx + i] == key[i]);

					if (!str_flag) {
						break;
					}
				}

				if (str_flag) {
					match_flag = 1;
				}

				if (match_flag) {
					break;
				}
			}
			if (match_flag) {
				if (idx > 0) {
					// fprintf(fp,"idx:%d\n",idx);
					fwrite(buf, 1, idx, fp);
				}

				break;
			} else {
				// fprintf(fp,"check_len:%d\n",check_len);
				fwrite(buf, 1, check_len, fp);

				for (int i = 0; i < keylen; i++) {
					buf[i] = buf[check_len + i];
				}
			}
		}
		memset(buf, 0, sizeof(buf));
		fclose(fp);
	}

	printf("Content-type: text/html\r\n\r\n");
}

void getTz(void)
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

static void execCommandAndGetOutput(const char *k_cmd, char *const k_args[], char *output, size_t output_size,
                                    int *exit_status)
{
	extern char **environ;
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

		execve(k_cmd, k_args, environ);
		perror("execve failed");
		_exit(127);
	} else {
		close(pipefd[1]);

		size_t total = 0;
		while (total < output_size - 1) {
			ssize_t n = read(pipefd[0], output + total, output_size - 1 - total);
			if (n <= 0)
				break;
			total += n;
		}
		output[total] = '\0';
		close(pipefd[0]);

		waitpid(pid, exit_status, 0);
	}
}

int secure_exec_script(const char *path, char *const args[], int *exit_code) {
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork failed");
		return -1;
	}

	if (pid == 0) {
		// Child process：replace with target program
		execve(path, args, environ);
		perror("execve failed");  // If execve fails, print error and exit with code 127
		_exit(127);
	} else {
		// Parent process: wait for child to complete
		int status;
		if (waitpid(pid, &status, 0) == -1) {
			perror("waitpid failed");
			return -1;
		}
		if (WIFEXITED(status)) {
			// Store the exit code of the child process
			*exit_code = WEXITSTATUS(status);
		} else {
			*exit_code = -1;
		}
		return 0;
	}
}

void fcgiUpdateCA(void)
{
	char output[1024] = { 0 };
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");

	char *const args[] = { "/system/www/cgi-bin/updateCA.sh", NULL };
	execCommandAndGetOutput("/system/www/cgi-bin/updateCA.sh", args, output, sizeof(output), &status);

	printf("{\"rval\":%d}", status);
}

void fcgiResetCA(void)
{
	char output[1024] = { 0 };
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");

	char *const args[] = { "/system/www/cgi-bin/resetCA.sh", NULL };
	execCommandAndGetOutput("/system/www/cgi-bin/resetCA.sh", args, output, sizeof(output), &status);

	printf("{\"rval\":%d}", status);
}

void fcgiGetTime(void)
{
	time_t rawtime;
	struct tm *timeinfo;
	printf("Content-type: text/html\r\n\r\n");
	getTz();
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("%04d.%02d.%02d-%02d:%02d:%02d\n", 1900 + timeinfo->tm_year, (timeinfo->tm_mon) + 1, timeinfo->tm_mday,
	       timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

void fcgiGetSntpConf(void)
{
	printf("Content-type: text/html\r\n\r\n");
	char ip[100];
	char hr[100];
	FILE *fp;
	if ((fp = fopen("/usrdata/active_setting/sntp.conf", "rb")) != NULL) {
		fgets(ip, 100, fp);
		fgets(hr, 100, fp);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	if ((sscanf(ip, "NTP_server=%99s", ip) != EOF) && (sscanf(hr, "Interval=%99s", hr) != EOF)) {
		printf("{\"NTPserver\":\"%s\",\"Interval\":\"%s\"}", ip, hr);
	} else {
		printf("{\"NTPserver\":\"\",\"Interval\":\"\"}");
	}
}

void fcgiGetEnabledConf(void)
{
    printf("Content-type: text/html\r\n\r\n");

    FILE *fp = fopen("/usrdata/active_setting/timeMode.conf", "rb");
    if (!fp) {
        // Failed to open configuration file
        perror("fopen failed");
        printf("{\"Manual_enabled\":\"\",\"DST_enabled\":\"\",\"SyncWithPC_enabled\":\"\"}");
        return;
    }

    char line[128];
    int Manual_en = -1, DST_en = -1, Sync_en = -1;

    // Read each line and parse the settings
    while (fgets(line, sizeof(line), fp)) {
        // Remove trailing newline or carriage return
        line[strcspn(line, "\r\n")] = 0;

        // Match and extract values
        if (sscanf(line, "Manual_enabled=%d", &Manual_en) == 1)
            continue;
        if (sscanf(line, "DST_enabled=%d", &DST_en) == 1)
            continue;
        if (sscanf(line, "SyncWithPC_enabled=%d", &Sync_en) == 1)
            continue;
    }

    fclose(fp);

    // Check if all values were found
    if (Manual_en != -1 && DST_en != -1 && Sync_en != -1) {
        printf("{\"Manual_enabled\":%d,\"DST_enabled\":%d,\"SyncWithPC_enabled\":%d}",
               Manual_en, DST_en, Sync_en);
    } else {
        // Return empty fields if any value is missing
        printf("{\"Manual_enabled\":\"\",\"DST_enabled\":\"\",\"SyncWithPC_enabled\":\"\"}");
    }
}


void fcgiGetDSTConf(void)
{
	printf("Content-type: text/html\r\n\r\n");
	char DSTConf[100];
	char s[5] = ",", s1[5] = "DST", s2[5] = ":", s3[5] = ".", s4[5] = "/";
	char *TZ;
	char *DSTStart;
	char *DSTEnd;
	char *SGMT;
	char *SGMThr;
	char *SGMTmin;
	char *SMonthStart;
	char *SPriorityStart;
	char *SWeekStart;
	char *SHourStart;
	char *SMonthEnd;
	char *SPriorityEnd;
	char *SWeekEnd;
	char *SHourEnd;
	char *SBiasSet;
	char *SBiasHr;
	char *SBiasMin;
	int BiasHr = 0;
	int BiasMin = 0;
	int GMT = 0;
	int GMThr = 0;
	int GMTmin = 0;
	int MonthStart = 0;
	int PriorityStart = 0;
	int WeekStart = 0;
	int HourStart = 0;
	int MonthEnd = 0;
	int PriorityEnd = 0;
	int WeekEnd = 0;
	int HourEnd = 0;
	int BiasSet = 0;

	FILE *fp;
	if ((fp = fopen("/etc/TZ", "rb")) != NULL) {
		fgets(DSTConf, 100, fp);
	}

	if (fp != NULL) {
		fclose(fp);
	}
	// s = ","
	TZ = strtok(DSTConf, s);
	DSTStart = strtok(NULL, s);
	DSTEnd = strtok(NULL, s);

	// s1 = "DST"
	strtok(TZ, s1);
	SGMT = strtok(NULL, s1);
	SBiasSet = strtok(NULL, s1);
	SGMThr = strtok(SGMT, s2);
	SGMTmin = strtok(NULL, s2);
	GMThr = atoi(SGMThr);
	GMTmin = atoi(SGMTmin);
	if (GMThr > 0) {
		GMT = GMThr * 60 + GMTmin;
	} else {
		GMT = GMThr * 60 - GMTmin;
	}

	// s2 = ":"
	SBiasHr = strtok(SBiasSet, s2);
	SBiasMin = strtok(NULL, s2);
	BiasHr = atoi(SBiasHr);
	BiasMin = atoi(SBiasMin);
	if (BiasHr > 0) {
		BiasHr = BiasHr * 60 + BiasMin;
	} else {
		BiasHr = BiasHr * 60 - BiasMin;
	}
	BiasHr = GMT - BiasHr;

	// s3 = "."
	SMonthStart = strtok(DSTStart, s3);
	SPriorityStart = strtok(NULL, s3);
	DSTStart = strtok(NULL, s3);
	sscanf(SMonthStart, "M%2s",
	       SMonthStart); /* The month values range from 1 to 12, with a maximum of two digits */

	SMonthEnd = strtok(DSTEnd, s3);
	SPriorityEnd = strtok(NULL, s3);
	DSTEnd = strtok(NULL, s3);
	sscanf(SMonthEnd, "M%2s", SMonthEnd); /* The month values range from 1 to 12, with a maximum of two digits */

	// s4 = "/"
	SWeekStart = strtok(DSTStart, s4);
	SHourStart = strtok(NULL, s4);

	SWeekEnd = strtok(DSTEnd, s4);
	SHourEnd = strtok(NULL, s4);

	MonthStart = atoi(SMonthStart);
	PriorityStart = atoi(SPriorityStart);
	WeekStart = atoi(SWeekStart);
	HourStart = atoi(SHourStart);
	MonthEnd = atoi(SMonthEnd);
	PriorityEnd = atoi(SPriorityEnd);
	WeekEnd = atoi(SWeekEnd);
	HourEnd = atoi(SHourEnd);
	BiasSet = BiasHr;

	printf("{\"GMT\":%d,\"MonthStart\":%d,\"PriorityStart\":%d,\"WeekStart\":"
	       "%d,\"HourStart\":%d,\"MonthEnd\":%d,\"PriorityEnd\":%d,"
	       "\"WeekEnd\":%d,\"HourEnd\":%d,\"BiasSet\":%d}",
	       GMT, MonthStart, PriorityStart, WeekStart, HourStart, MonthEnd, PriorityEnd, WeekEnd, HourEnd, BiasSet);
}
void fcgiGetTZ(void)
{
	char TZConf[20];
	char s[5] = "GMT", s1[5] = ":";
	char *TZ;
	char *TZ_hr;
	char *TZ_min;
	FILE *fp;
	int GMT = 0;
	printf("Content-type: text/html\r\n\r\n");
	if ((fp = fopen("/etc/TZ", "rb")) != NULL) {
		fgets(TZConf, sizeof(TZConf), fp);
		fclose(fp);
	}
	TZ = strtok(TZConf, s);
	TZ_hr = strtok(TZ, s1);
	TZ_min = strtok(NULL, s1);
	if (TZ_min == NULL) {
		TZ_min = "0";
	}
	GMT = atoi(TZ_hr);

	if (GMT < 0) {
		GMT = GMT * 60 - atoi(TZ_min);
	} else {
		GMT = GMT * 60 + atoi(TZ_min);
	}
	printf("{\"GMT\":%d,\"MonthStart\":4,\"PriorityStart\":1,\"WeekStart\":0,"
	       "\"HourStart\":2,\"MonthEnd\":10,\"PriorityEnd\":2,\"WeekEnd\":0,"
	       "\"HourEnd\":2,\"BiasSet\":60}",
	       GMT);
}

void fcgiGetTimeSwitch(void)
{
	char Switch_enabled[100];
	char SwitchStart_hr[100];
	char SwitchStart_min[100];
	char SwitchEnd_hr[100];
	char SwitchEnd_min[100];
	printf("Content-type: text/html\r\n\r\n");
	int Switch_en = 0;
	FILE *fp;
	if ((fp = fopen("/usrdata/active_setting/TimeSwitch.conf", "rb")) != NULL) {
		fgets(Switch_enabled, 100, fp);
		fgets(SwitchStart_hr, 100, fp);
		fgets(SwitchStart_min, 100, fp);
		fgets(SwitchEnd_hr, 100, fp);
		fgets(SwitchEnd_min, 100, fp);
	}

	if (fp != NULL) {
		fclose(fp);
	}

	if ((sscanf(Switch_enabled, "TimeSwitch_enabled=%99s", Switch_enabled) != EOF) &&
	    (sscanf(SwitchStart_hr, "TimeStartHr=%99s", SwitchStart_hr) != EOF) &&
	    (sscanf(SwitchStart_min, "TimeStartMin=%99s", SwitchStart_min) != EOF) &&
	    (sscanf(SwitchEnd_hr, "TimeEndHr=%99s", SwitchEnd_hr) != EOF) &&
	    (sscanf(SwitchEnd_min, "TimeEndMin=%99s", SwitchEnd_min) != EOF)) {
		Switch_en = atoi(Switch_enabled);
		printf("{\"TimeSwitch_enabled\":%d,\"time_start\":\"%s:%s\",\"time_"
		       "end\":\"%s:%s\"}",
		       Switch_en, SwitchStart_hr, SwitchStart_min, SwitchEnd_hr, SwitchEnd_min);
	} else {
		printf("{\"TimeSwitch_enabled\":\"\",\"time_start\":\"\",\"time_end\":"

		       "\"\"}");
	}
}

void fcgiExportSetting(void)
{
	FILE *fp;
	size_t bytes;
	char buf[2048] = { 0 };
	int status = 0;
	printf("Content-Type:application/octet-stream; name = \"Export.dat\"\r\n");
	printf("Content-Disposition: attachment; filename = \"Export.dat\"\r\n\n");

	char *const args[] = { "/system/www/cgi-bin/exportSetting.sh", NULL };
	execCommandAndGetOutput("/system/www/cgi-bin/exportSetting.sh", args, buf, sizeof(buf), &status);

	memset(buf, 0x00, sizeof(buf));

	if ((fp = fopen("/tmp/Export.dat", "rb")) != NULL) {
		while (0 < (bytes = fread(buf, 1, sizeof(buf), fp))) {
			fwrite(buf, 1, bytes, FCGI_stdout);
		}

		fclose(fp);
	}
}

#ifdef SECURE_WEB_PAGE
char *g_pattern;

static int removeCallback(const char *path, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
	(void)(sb);
	(void)(ftwbuf);

	const char *filename = strrchr(path, '/');
	if (filename) {
		filename++; /* ignore '/' */
	} else {
		filename = path;
	}

	if (strncmp(filename, g_pattern, strlen(g_pattern)) == 0) {
		if (typeflag == FTW_F || typeflag == FTW_SL) {
			if (unlink(path) != 0) {
				perror("Failed to delete file");
			}
		} else if (typeflag == FTW_DP) {
			if (rmdir(path) != 0) {
				perror("Failed to delete directory");
			}
		}
	}
	return 0;
}

static void removeMatchingFiles(const char *search_dir, const char *pattern)
{
	g_pattern = strdup(pattern); /* save pattern in global var */
	if (g_pattern == NULL) {
		perror("Memory allocation failed");
	}

	if (nftw(search_dir, removeCallback, 10, FTW_DEPTH | FTW_PHYS) == -1) {
		perror("nftw failed");
	}

	free(g_pattern);
}
#endif

static int moveFirstMatchingFile(const char *source_dir, const char *prefix, const char *dest_file)
{
	struct dirent *entry;
	DIR *dir = opendir(source_dir);
	char src_path[1024];

	if (!dir) {
		perror("opendir failed");
		return -1;
	}

	while ((entry = readdir(dir)) != NULL) {
		// Skip . and ..
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;

		if (strncmp(entry->d_name, prefix, strlen(prefix)) == 0) {
			snprintf(src_path, sizeof(src_path), "%s/%s", source_dir, entry->d_name);
			closedir(dir);

			if (rename(src_path, dest_file) != 0) {
				perror("rename failed");
				return -1;
			}

			return 0; // Success
		}
	}

	closedir(dir);
	fprintf(stderr, "No matching file found\n");
	return -1;
}

void fcgiFirmwareUpload(void)
{
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");
	printf("<p>Try to rename /tmp/00000* -> /tmp/update.swu</p>\n");
	status = moveFirstMatchingFile("/tmp", "00000", "/tmp/update.swu");
	printf("<p>status = %d</p>\n", status);

#ifdef SECURE_WEB_PAGE
	char buf1[2048];
	int bootpart_to_write = 0;
	char img_collection[50];
	int ret = 0;

	char output[10];
	char *const args[] = { "/usr/sbin/fw_printenv", "slot_b_active", "-n", NULL };
	execCommandAndGetOutput("/usr/sbin/fw_printenv", args, output, sizeof(output), &ret);

	output[strcspn(output, "\n")] = 0; // Remove newline
	if (strcmp(output, "1") == 0) {
		bootpart_to_write = 1;
	} else {
		bootpart_to_write = 2;
	}

	snprintf(img_collection, sizeof(img_collection), "release,copy_%d", bootpart_to_write);
	fprintf(stderr, "img_collection : %s\n", img_collection);

	// Construct swupdate command
	snprintf(buf1, sizeof(buf1),
	         "swupdate -v -c -b \"0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19\" "
	         "-e \"%s\" -i /tmp/update.swu -k /usr/share/misc/sysupd_pub_key.pem > /tmp/swupdate.log 2>&1",
	         img_collection);

	// Execute swupdate command
	fprintf(stderr, "swupdate command : %s\n", buf1);

	/* Prepare arguments for execve */
	char *args2[] = { "/usr/bin/swupdate",
		          "-v",
		          "-c",
		          "-b",
		          "\"0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19\"",
		          "-e",
		          img_collection,
		          "-i",
		          "/tmp/update.swu",
		          "-k",
		          "/usr/share/misc/sysupd_pub_key.pem",
		          NULL };

	pid_t pid = fork();
	extern char **environ;

	if (pid == -1) {
		/* Fork failed */
		perror("fork failed");
		return;
	} else if (pid == 0) {
		/* redirect optput */
		int fd = open("/tmp/swupdate.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1) {
			perror("open log file failed");
			_exit(126);
		}
		dup2(fd, STDOUT_FILENO); /* redirect stdout */
		dup2(fd, STDERR_FILENO); /* redirect stderr */
		close(fd);

		/* Child process: Execute the command */
		execve(args2[0], args2, environ);

		/* If execve returns, there was an error */
		perror("execve failed");
		_exit(127);
	} else {
		/* Parent process: Wait for the child to finish */
		if (waitpid(pid, &status, 0) == -1) {
			perror("waitpid failed");
			return;
		}

		/* Check child process exit status */
		if (WIFEXITED(status)) {
			/* successful case */
		} else if (WIFSIGNALED(status)) {
			return;
		} else {
			return;
		}
	}
	fprintf(stderr, "status = %d\n", status);

	if (status != 0) {
		perror("Failed to verify the firmware image or the image is illeagal\n");
		remove("/tmp/update.swu");
		removeMatchingFiles("/tmp", "sw-description");

		return;
	}

	printf("<p>chmod 400 /tmp/update.swu\n</p>");

	struct stat initial_stat, final_stat;
	if (stat("/tmp/update.swu", &initial_stat) == -1) {
		perror("stat failed");
		return;
	}

	status = chmod("/tmp/update.swu", 0400);

	if (stat("/tmp/update.swu", &final_stat) == -1) {
		perror("stat failed");
		return;
	}

	/* Compare inode and owner to ensure the file has not been modified */
	if (initial_stat.st_ino != final_stat.st_ino || initial_stat.st_uid != final_stat.st_uid) {
		perror("File was modified during the operation.");
		return;
	}

	printf("<p>status=%d</p>", status);
#endif

	return;
}

void fcgiGetHostname(void)
{
	char hostname[128];
	printf("Content-type: text/html\r\n\r\n");
	gethostname(hostname, 127);
	printf("%s", hostname);
}

void fcgiSetToDefault(void)
{
	printf("Content-type: text/html\r\n\r\n");
#ifdef SECURE_WEB_PAGE
	char *const args[] = { "/system/www/cgi-bin/setToDefault_secure.sh", NULL };
#else
	char *const args[] = { "/system/www/cgi-bin/setToDefault.sh", NULL };
#endif
	int status = 0;
	char output[1024] = { 0 };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("{\"rval\":0}");
}

void fcgiReboot(void)
{
	printf("Content-type: text/html\r\n\r\n");

	int status = 0;
	char output[1024];
	char *const args[] = { "/sbin/reboot", NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("{\"rval\":0}");
}

static void runStopScript(const char *script_path, const char *script_desc)
{
	if (script_path == NULL || script_path[0] == '\0') {
		fprintf(stderr, "No script found for %s\n", script_desc);
		return;
	}

	fprintf(stderr, "Stopping %s : %s\n", script_desc, script_path);

	char output[1024] = { 0 };
	int status = 0;
	char *const args[] = { "/bin/sh", (char *)script_path, "stop", NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	fprintf(stderr, "[%s] status = %d, output = %s\n", script_desc, status, output);
}

static void runScriptWithArgs(const char *script_path, const char *script_desc, const char *arg1)
{
	if (script_path == NULL || script_path[0] == '\0') {
		fprintf(stderr, "No script found for %s\n", script_desc);
		return;
	}

	fprintf(stderr, "Running %s : %s %s\n", script_desc, script_path, arg1);

	char output[1024] = { 0 };
	int status = 0;
	char *const args[] = { "/bin/sh", (char *)script_path, (char *)arg1, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	fprintf(stderr, "[%s] status = %d, output = %s\n", script_desc, status, output);
}

void fcgiStopStream(char *MachineMode)
{
	printf("Content-type: text/html\r\n\r\n");

#ifdef SECURE_WEB_PAGE
#define DEVELOP_MODE_INITSCRIPT_PATH "/etc/init.d/develop/"
#define FLV_PREFIX "S95flv_agt"
#define AV_MAIN2_PREFIX "S26av_main2_agt"

	char flv_script[256] = { 0 };
	char av_main2_script[256] = { 0 };
	char ccserver_path[256];
	char dbserver_path[256];

	DIR *dir = opendir(DEVELOP_MODE_INITSCRIPT_PATH);
	if (!dir) {
		perror("Failed to open init.d develop directory");
		printf("{\"rval\":1}");
		return;
	}

	struct dirent *entry = NULL;
	while ((entry = readdir(dir)) != NULL) {
		if (strncmp(entry->d_name, FLV_PREFIX, strlen(FLV_PREFIX)) == 0) {
			snprintf(flv_script, sizeof(flv_script), "%s", DEVELOP_MODE_INITSCRIPT_PATH);
			strncat(flv_script, entry->d_name, sizeof(flv_script) - strlen(flv_script) - 1);
		} else if (strncmp(entry->d_name, AV_MAIN2_PREFIX, strlen(AV_MAIN2_PREFIX)) == 0) {
			snprintf(av_main2_script, sizeof(av_main2_script), "%s", DEVELOP_MODE_INITSCRIPT_PATH);
			strncat(av_main2_script, entry->d_name, sizeof(av_main2_script) - strlen(av_main2_script) - 1);
		}
	}
	closedir(dir);

	snprintf(ccserver_path, sizeof(ccserver_path), "/etc/init.d/%s/S22ccserver", MachineMode);
	snprintf(dbserver_path, sizeof(dbserver_path), "/etc/init.d/%s/S21db", MachineMode);

	setenv("LD_LIBRARY_PATH", "/system/lib", 1);

	runStopScript(flv_script, "FLV server");
	runStopScript(av_main2_script, "AV main2");
	runStopScript(ccserver_path, "CCServer");
	runStopScript(dbserver_path, "DB server");
	runScriptWithArgs("/system/mpp/script/load_mpp.sh", "MPP", "-e");

#else
	char path[256];

	snprintf(path, sizeof(path), "/etc/init.d/%s/S95rtmp", MachineMode);
	runStopScript(path, "RTMP");

	snprintf(path, sizeof(path), "/etc/init.d/%s/S26av_main", MachineMode);
	runStopScript(path, "AV main");

	runScriptWithArgs("/system/mpp/script/load_mpp.sh", "MPP", "-e");
#endif

	const char *sysfs_mpp = "/sys/module/mpp";

	int r = wait_module_unload(sysfs_mpp, 20, 500000); // retry 20 times, sleep 0.5s if failed.
	if (0 == r)
		printf("{\"rval\":0}"); // remove successfully.
	else
		printf("{\"rval\":2}"); // remove module failed.
}

static int runSysupd(const char *target_output)
{
	if (target_output == NULL)
		return -1;

	int fd = open(target_output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Failed to open log file");
		return -1;
	}

	char *const args[] = { "/usr/sbin/sysupd", NULL };
	extern char **environ;
	pid_t pid = fork();
	int status;

	if (pid == -1) {
		perror("fork failed");
		close(fd);
		return -1;
	}

	if (pid == 0) {
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);
		close(fd);
		execve(args[0], args, environ);
		perror("execve failed");
		_exit(127); // execve error fallback
	} else {
		close(fd);
		if (waitpid(pid, &status, 0) == -1) {
			perror("waitpid failed");
			return -1;
		}
		if (WIFEXITED(status)) {
			return WEXITSTATUS(status);
		}
		return -1;
	}
}

void fcgiSysupdOS(void)
{
	printf("Content-type: text/html\r\n\r\n");
	int status = runSysupd("/tmp/sysupd_terminal.log");
	printf("{\"rval\":%d}", status == 0 ? 0 : 1);
}

void fcgiSwitch2SysupdOS(void)
{
	printf("Content-type: text/html\r\n\r\n");

	char buf[1024] = { 0 };
	int status = 0;
	char *const args[] = { "/usr/sbin/sysupd-recover", NULL };
	execCommandAndGetOutput(args[0], args, buf, sizeof(buf), &status);

	printf("{\"rval\":0}");
}

void fcgiChangePass(char *buf, const char *auth_value)
{
	int exists, exists1;
	enum json_type type;
	char name[100];
	char pass[100];
	char output[1024] = { 0 };
	int status = 0;
	json_object *obj_name, *obj_pass;
	json_object *jobj;
	const char *resp_status = "200 OK";
	(void)auth_value;

	jobj = json_tokener_parse(buf);
	exists = json_object_object_get_ex(jobj, "name", &obj_name);

	if (!exists) {
		resp_status = "400 Bad Request";
		goto response;
	}

	type = json_object_get_type(obj_name);

	if (type != json_type_string) {
		resp_status = "400 Bad Request";
		goto response;
	}

	strncpy(name, json_object_get_string(obj_name), 100);
	// printf("<p>name:%s\n</p>",hostname);

	exists1 = json_object_object_get_ex(jobj, "pass", &obj_pass);
	if (!exists1) {
		resp_status = "400 Bad Request";
		goto response;
	}

	type = json_object_get_type(obj_pass);

	if (type == json_type_string) {
		strncpy(pass, json_object_get_string(obj_pass), 100);
		// printf("<p>pass:%s\n</p>",pass);
#ifdef SECURE_WEB_PAGE
		char *const args[] = { "/system/www/cgi-bin/passwd_secure.sh", name, pass, auth_value,
						   NULL };

#else
		char *const args[] = { "/system/www/cgi-bin/passwd.sh", name, pass, NULL };
#endif
		execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
		memset(pass, 0, sizeof(pass));
		if (status) {
			resp_status = "403 Forbidden";
		}
	} else {
		resp_status = "400 Bad Request";
	}
response:
	printf("Status: %s\r\n", resp_status);
	printf("Content-Type: text/html; charset=utf-8\r\n\r\n");

	json_object_put(jobj);
}

void fcgiAssignIP(char *MachineMode, char *buf)
{
	(void)MachineMode;
	/* ---- parse inputs ---- */
	enum json_type type;
	char dec_buf[2048];
	json_object *jobj = NULL;
	json_object *obj_hostname = NULL, *obj_IPAddress = NULL, *obj_Netmask = NULL;
	json_object *obj_Gateway = NULL, *obj_DNS1 = NULL, *obj_DNS2 = NULL, *obj_dhcp_status = NULL;

	char hostname[128] = {0};
	char IPAddress[20] = {0};
	char Netmask[20]   = {0};
	char Gateway[20]   = {0};
	char DNS1[20]      = {0};
	char DNS2[20]      = {0};
	char dns_arg[64]   = {0};   /* combined "DNS1 DNS2" or just DNS1 */
	int  dhcp_status   = -1;
	int status = -1;

	int has_hostname = 0, has_ip = 0, has_mask = 0, has_gw = 0;
	int has_dns1 = 0, has_dns2 = 0, has_dhcp = 0;

	/* build argv for /system/bin/ip_assign */
	char *argv[32] = {0};
	int   argi = 0;

	/* Always send Content-Type once */
	printf("Content-type: application/json\r\n\r\n");

	/* decode + parse */
	decode(buf, dec_buf);
	jobj = json_tokener_parse(dec_buf);
	if (!jobj) {
		printf("{\"rval\":-1,\"msg\":\"invalid JSON\"}\n");
		return;
	}

	if (json_object_object_get_ex(jobj, "Hostname", &obj_hostname) &&
		(type = json_object_get_type(obj_hostname)) == json_type_string) {
		strncpy(hostname, json_object_get_string(obj_hostname), sizeof(hostname) - 1);
		hostname[sizeof(hostname) - 1] = '\0';
		has_hostname = (hostname[0] != '\0');
	}

	if (json_object_object_get_ex(jobj, "IPAddress", &obj_IPAddress) &&
		(type = json_object_get_type(obj_IPAddress)) == json_type_string) {
		strncpy(IPAddress, json_object_get_string(obj_IPAddress), sizeof(IPAddress) - 1);
		IPAddress[sizeof(IPAddress) - 1] = '\0';
		has_ip = (IPAddress[0] != '\0');
	}

	if (json_object_object_get_ex(jobj, "Netmask", &obj_Netmask) &&
		(type = json_object_get_type(obj_Netmask)) == json_type_string) {
		strncpy(Netmask, json_object_get_string(obj_Netmask), sizeof(Netmask) - 1);
		Netmask[sizeof(Netmask) - 1] = '\0';
		has_mask = (Netmask[0] != '\0');
	}

	if (json_object_object_get_ex(jobj, "Gateway", &obj_Gateway) &&
		(type = json_object_get_type(obj_Gateway)) == json_type_string) {
		strncpy(Gateway, json_object_get_string(obj_Gateway), sizeof(Gateway) - 1);
		Gateway[sizeof(Gateway) - 1] = '\0';
		has_gw = (Gateway[0] != '\0');
	}

	if (json_object_object_get_ex(jobj, "dhcp", &obj_dhcp_status) &&
		(type = json_object_get_type(obj_dhcp_status)) == json_type_int) {
		dhcp_status = json_object_get_int(obj_dhcp_status);
		has_dhcp = 1;
	}

	if (json_object_object_get_ex(jobj, "DNS1", &obj_DNS1) &&
		(type = json_object_get_type(obj_DNS1)) == json_type_string) {
		strncpy(DNS1, json_object_get_string(obj_DNS1), sizeof(DNS1) - 1);
		DNS1[sizeof(DNS1) - 1] = '\0';
		has_dns1 = (DNS1[0] != '\0');
	}
	if (json_object_object_get_ex(jobj, "DNS2", &obj_DNS2) &&
		(type = json_object_get_type(obj_DNS2)) == json_type_string) {
		strncpy(DNS2, json_object_get_string(obj_DNS2), sizeof(DNS2) - 1);
		DNS2[sizeof(DNS2) - 1] = '\0';
		has_dns2 = (DNS2[0] != '\0');
	}

	/* done with JSON */
	json_object_put(jobj);

	/* validate basics */
	if (!has_dhcp) {
		printf("{\"rval\":-2,\"msg\":\"missing dhcp\"}\n");
		return;
	}
	if (dhcp_status == 0) { /* static */
			if (!has_ip || !has_mask || !has_gw) {
			 printf("{\"rval\":-3,\"msg\":\"static requires IPAddress, Netmask, Gateway\"}\n");
			return;
		}
	}

	/*build argv (do not use shell) */
	argi = 0;
	argv[argi++] = "/system/bin/ip_assign";
	if (has_hostname) { argv[argi++] = "-n"; argv[argi++] = hostname; }
	if (has_ip)       { argv[argi++] = "-i"; argv[argi++] = IPAddress; }
	if (has_mask)     { argv[argi++] = "-m"; argv[argi++] = Netmask; }
	if (has_gw)       { argv[argi++] = "-g"; argv[argi++] = Gateway; }

	argv[argi++] = "-s";
	argv[argi++] = (dhcp_status ? (char*)"dhcp" : (char*)"static");

	if (has_dns1) {
		argv[argi++] = "-d";
		if (has_dns2) snprintf(dns_arg, sizeof(dns_arg), "%s %s", DNS1, DNS2);
		else          snprintf(dns_arg, sizeof(dns_arg), "%s", DNS1);
		argv[argi++] = dns_arg;  /* single argv containing both DNS if present */
	}
	argv[argi] = NULL;

	pid_t pid = fork();
	if (pid == 0) {
		/* child: detach and apply changes */
		setsid();
		/* detach stdio to avoid writing to the closed CGI socket */
		int nullfd = open("/dev/null", O_RDWR);
		if (nullfd >= 0) {
			dup2(nullfd, STDIN_FILENO);
			dup2(nullfd, STDOUT_FILENO);
			dup2(nullfd, STDERR_FILENO);
			if (nullfd > 2) close(nullfd);
		}
		sleep(1); /* give client time to receive the response */

		int code = -1;
		/* run ip_assign */
		secure_exec_script(argv[0], argv, &code);

		_exit(0);
	}

	/* wait child process for finishing their jobs. */
	waitpid(pid, &status, 0);

	/* response now */
	printf("{\"rval\":0,\"msg\":\"accepted\"}\n");
	fflush(stdout);

	/* parent: return immediately */
}

void fcgiNetInfo(void)
{
	char buf[100];
	char buf1[50];
	char hostname[128];
	char IPAddress[20];
	char Netmask[20];
	char Gateway[20];
	char DNS1[20];
	char DNS2[20];
	char MAC[20];
	int dhcp_status;

	printf("Content-type: text/html\r\n\r\n");
	IPAddress[0] = 0;
	Netmask[0] = 0;
	DNS1[0] = 0;
	DNS2[0] = 0;
	MAC[0] = 0;
	Gateway[0] = 0;
	dhcp_status = 0;

	gethostname(hostname, 127);
	FILE *fp = fopen("/etc/network/interfaces", "rb");

	fgets(buf, sizeof(buf), fp);
	fgets(buf, sizeof(buf), fp);

	while (fgets(buf, sizeof(buf), fp) != NULL) {
		if (sscanf(buf, "iface eth0 inet %49s", buf1) == 1) {
			if (strcmp(buf1, "static") == 0) {
				dhcp_status = 0;
			} else {
				dhcp_status = 1;
			}
		} else if (sscanf(buf, "address %19s", IPAddress) == 1) {
		} else if (sscanf(buf, "netmask %19s", Netmask) == 1) {
		} else if (sscanf(buf, "gateway %19s", Gateway) == 1) {
		} else if (sscanf(buf, "dns-nameservers %19s %19s", DNS1, DNS2) > 1) {
		}
	}

	fclose(fp);
	fp = fopen("/sys/class/net/eth0/address", "rb");
	fgets(buf, sizeof(buf), fp);
	sscanf(buf, "%19s", MAC);
	memset(buf, 0, sizeof(buf));
	fclose(fp);
	printf("{\"Hostname\":\"%s\",\"IPAddress\":\"%s\",\"Netmask\":\"%s\","
	       "\"Gateway\":\"%s\",\"DNS1\":\"%s\",\"DNS2\":\"%s\",\"MAC\":\"%"
	       "s\",\"dhcp\":%d}",
	       hostname, IPAddress, Netmask, Gateway, DNS1, DNS2, MAC, dhcp_status);
	memset(MAC, 0, sizeof(MAC));
}

void fcgiUpTime(void)
{
	struct sysinfo sys_info;
	int days, hours, mins;

	printf("Content-type: text/html\r\n\r\n");

	if (sysinfo(&sys_info) != 0) {
		perror("sysinfo");
	}

	days = sys_info.uptime / 86400;
	hours = (sys_info.uptime / 3600) - (days * 24);
	mins = (sys_info.uptime / 60) - (days * 1440) - (hours * 60);

	printf("%ddays, %dhours, %dminutes, %ldseconds", days, hours, mins, sys_info.uptime % 60);
}

void fcgiGetMAC(void)
{
	char buf[50];
	printf("Content-type: text/html\r\n\r\n");
	FILE *fp = fopen("/sys/class/net/eth0/address", "rb");
	fgets(buf, 50, fp);
	fclose(fp);
	printf("%s\n", buf);
	memset(buf, 0, sizeof(buf));
}

void fcgiGetFirmwareVersion(void)
{
	char buf[100];
	FILE *fp;
	printf("Content-type: text/html\r\n\r\n");

	if ((fp = fopen("/etc/sw-version", "rb")) != NULL) {
		fgets(buf, 100, fp);
		fclose(fp);
		printf("%s\n", buf);
	} else {
		printf("0.0.1\n");
	}
}

void fcgiGetIPAddress(void)
{
	int fd;
	struct ifreq ifr;

	printf("Content-type: text/html\r\n\r\n");
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	/* I want to get an IPv4 IP address */
	ifr.ifr_addr.sa_family = AF_INET;
	/* I want IP address attached to "eth0" */
	strncpy(ifr.ifr_name, "eth0", IFNAMSIZ - 1);
	ioctl(fd, SIOCGIFADDR, &ifr);
	close(fd);
	/* display result */
	printf("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}

void fcgiGetNetmask(void)
{
	int fd;
	struct ifreq ifr;

	printf("Content-type: text/html\r\n\r\n");
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	/* I want to get an IPv4 IP address */
	ifr.ifr_addr.sa_family = AF_INET;
	/* I want IP address attached to "eth0" */
	strncpy(ifr.ifr_name, "eth0", IFNAMSIZ - 1);
	ioctl(fd, SIOCGIFNETMASK, &ifr);
	close(fd);
	/* display result */
	printf("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
}

void fcgiGetGateway(void)
{
	FILE *fp;
	unsigned int p;
	char buf[256];
	char iface[16];
	unsigned long dest_addr, gate_addr;
	struct in_addr addr;

	printf("Content-type: text/html\r\n\r\n");
	p = (unsigned int)INADDR_NONE;

	fp = fopen("/proc/net/route", "r");

	if (fp == NULL) {
		// break;
		return;
	}

	/* Skip title line */
	fgets(buf, sizeof(buf), fp);

	while (fgets(buf, sizeof(buf), fp)) {
		if (sscanf(buf, "%15s\t%lX\t%lX", iface, &dest_addr, &gate_addr) != 3 || dest_addr != 0) {
			continue;
		}

		p = (unsigned int)gate_addr;
		break;
	}

	fclose(fp);
	addr.s_addr = (in_addr_t)p;
	printf("%s\n", inet_ntoa(addr));
}

void fcgiGetDNS(void)
{
	FILE *fp;
	char dns1[32];
	char dns2[32];
	char buf[2048];

	printf("Content-type: text/html\r\n\r\n");
	fp = fopen("/etc/resolv.conf", "r");

	if (fp == NULL) {
		return;
	}

	/* Skip title line */
	fgets(buf, sizeof(buf), fp);

	while (fgets(buf, sizeof(buf), fp)) {
		if (sscanf(buf, "nameserver %31s", dns1) != 1) {
			continue;
		}

		fgets(buf, sizeof(buf), fp);
		sscanf(buf, "nameserver %31s", dns2);
		break;
	}

	fclose(fp);
	printf("{\"dns1\":\"%s\",\"dns2\":\"%s\"}\n", dns1, dns2);
}

static bool isValidIp(const char *input)
{
	if (input == NULL) {
		goto end;
	}

	struct in_addr ipv4_addr;
	struct in6_addr ipv6_addr;

	if (inet_pton(AF_INET, input, &ipv4_addr) == 1) {
		return true;
	}

	if (inet_pton(AF_INET6, input, &ipv6_addr) == 1) {
		return true;
	}

end:
	return false;
}

void fcgiSetIP(char *buf)
{
	pid_t pid;
	int status;
	printf("Content-type: text/html\r\n\r\n");
	printf("arg:%s", buf);
	pid = fork();

	if (pid == 0) {
		if (isValidIp(buf))
			execl("/system/www/cgi-bin/setIP.sh", "setIP.sh", buf, (char *)NULL);

		_exit(0);
	} else {
		wait(&status);
	}
}

#define MASK_PARTS 4
#define MAX_PART_VALUE 255
static bool isValidMask(const char *mask)
{
	int num, dots = 0;
	const char *ptr = mask;
	int values[MASK_PARTS] = { 0 };
	int part_index = 0;

	if (!mask || *mask == '\0') {
		return false;
	}

	while (*ptr) {
		if (*ptr == '.') {
			if (part_index >= MASK_PARTS - 1)
				return 0; /* Too many dots */
			dots++;
			ptr++;
			continue;
		}

		if (!isdigit(*ptr))
			return 0; /* Invalid character */

		num = 0;
		while (*ptr && isdigit(*ptr)) {
			num = num * 10 + (*ptr - '0');
			if (num > MAX_PART_VALUE)
				return 0; /* Exceeds valid byte range */
			ptr++;
		}

		values[part_index++] = num;

		if (*ptr && *ptr != '.')
			return 0; /* Invalid separator */
	}

	if (dots != 3 || *(ptr - 1) == '.') {
		return false; /* Invalid mask format */
	}

	/* Validate mask values (only continuous ones followed by zeros allowed) */
	unsigned int mask_value = (values[0] << 24) | (values[1] << 16) | (values[2] << 8) | values[3];

	if ((mask_value & (~mask_value + 1)) + mask_value != 0xFFFFFFFF) {
		return false; /* Invalid subnet mask pattern */
	}

	return true; /* Valid subnet mask */
}

void fcgiSetMask(char *buf)
{
	pid_t pid;
	int status;
	printf("Content-type: text/html\r\n\r\n");
	printf("arg:%s", buf);
	pid = fork();

	if (pid == 0) {
		if (isValidMask(buf))
			execl("/system/www/cgi-bin/setMask.sh", "setMask.sh", buf, (char *)NULL);
		_exit(0);
	} else {
		wait(&status);
	}
}

void fcgiSetGateway(char *buf)
{
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");
	printf("arg:%s", buf);

	char output[1024] = { 0 };
	char *const args[] = { "/system/www/cgi-bin/setGateway.sh", buf, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
}

void fcgiSetDNS(char *buf)
{
	char primary[20] = "";
	char secondary[20] = "";
	char str[3] = " ";
	char str1[3] = "\"";
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");
	printf("arg:%s", buf);
	sscanf(buf, "%19[^&]&%19s", primary, secondary);
	strncat(str1, primary, sizeof(str1) - strlen(primary) - 1);
	strncat(str1, str, sizeof(str1) - strlen(str) - 1);
	strncat(str1, secondary, sizeof(str1) - strlen(secondary) - 1);

	char output[1024] = { 0 };
	char *const args[] = { "/system/www/cgi-bin/setDNS.sh", str1, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
}

void fcgiSetTime(char *MachineMode, char *buf)
{
	char buf1[2048] = { 0 };
	int status = 0;
	char output[1024] = { 0 };
	printf("Content-type: text/html\r\n\r\n");
	printf("arg:%s", buf);

	char *const args[] = { "/system/www/cgi-bin/time.sh", buf, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	snprintf(buf1, sizeof(buf1), "/etc/init.d/%s/S50sntp", MachineMode);
	char *const args1[] = { buf1, "stop", NULL };
	execCommandAndGetOutput(args1[0], args1, output, sizeof(output), &status);
	printf("<p>status(echo)=%d</p>", status);

	snprintf(buf1, sizeof(buf1), "/etc/init.d/%s/S99cron", MachineMode);
	char *const args2[] = { buf1, "restart", NULL };
	execCommandAndGetOutput(args2[0], args2, output, sizeof(output), &status);
	printf("<p>%s restart\n</p>", buf1);
	printf("<p>status(echo)=%d</p>", status);
}

void fcgiSetSntpConf(char *MachineMode, char *buf)
{
	int exists, exists1;
	enum json_type type;
	char cmdstr[200];
	char buf1[2048];
	int status = 0;
	char NTPserver[20];
	char Interval[20];
	char output[1024] = { 0 };
	json_object *obj_NTPserver, *obj_Interval;
	json_object *jobj = json_tokener_parse(buf);

	printf("Content-type: text/html\r\n\r\n");
	cmdstr[0] = 0;

	exists = json_object_object_get_ex(jobj, "NTPserver", &obj_NTPserver);

	if (exists) {
		type = json_object_get_type(obj_NTPserver);

		if (type == json_type_string) {
			strncpy(NTPserver, json_object_get_string(obj_NTPserver), 20);
			strncat(cmdstr, NTPserver, sizeof(cmdstr) - strlen(NTPserver) - 1);

			exists1 = json_object_object_get_ex(jobj, "Interval", &obj_Interval);

			if (exists1) {
				type = json_object_get_type(obj_Interval);

				if (type == json_type_string) {
					strncpy(Interval, json_object_get_string(obj_Interval), 20);
					strncat(cmdstr, " ", sizeof(cmdstr) - strlen(" ") - 1);
					strncat(cmdstr, Interval, sizeof(cmdstr) - strlen(Interval) - 1);
				}
			}
		}
	}

	json_object_put(jobj);

	snprintf(buf1, sizeof(buf1), "/system/www/cgi-bin/SntpConf.sh set %s", cmdstr);
	printf("<p>%s\n</p>", buf1);
	char *const args[] = { "/system/www/cgi-bin/SntpConf.sh", "set", cmdstr, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
	printf("<p>status=%d</p>", status);

	snprintf(buf1, sizeof(buf1), "/etc/init.d/%s/S50sntp", MachineMode);
	printf("<p>%s restart\n</p>", buf1);
	char *const args2[] = { buf1, "restart", NULL };
	execCommandAndGetOutput(args2[0], args2, output, sizeof(output), &status);
	printf("<p>status(echo)=%d</p>", status);

	snprintf(buf1, sizeof(buf1), "/etc/init.d/%s/S99cron", MachineMode);
	printf("<p>%s restart\n</p>", buf1);
	char *const args3[] = { buf1, "restart", NULL };
	execCommandAndGetOutput(args3[0], args3, output, sizeof(output), &status);
	printf("<p>status(echo)=%d</p>", status);
}

void fcgiDSTSet(char *buf)
{
	int exists;
	int BiasHr = 0;
	enum json_type type;
	char cmdstr[200];
	char buf1[2048];
	int status;
	int GMT = 0;
	int GMT_hr = 0;
	int GMT_min = 0;
	int MonthStart = 0;
	int PriorityStart = 0;
	int WeekStart = 0;
	int HourStart = 0;
	int MonthEnd = 0;
	int PriorityEnd = 0;
	int WeekEnd = 0;
	int HourEnd = 0;
	int BiasSet = 0;
	json_object *obj_GMT, *obj_MonthStart, *obj_PriorityStart, *obj_WeekStart, *obj_HourStart, *obj_MonthEnd,
	        *obj_PriorityEnd, *obj_WeekEnd, *obj_HourEnd, *obj_BiasSet;
	json_object *jobj = json_tokener_parse(buf);
	printf("Content-type: text/html\r\n\r\n");
	cmdstr[0] = 0;

	exists = json_object_object_get_ex(jobj, "GMT", &obj_GMT);

	if (exists) {
		type = json_object_get_type(obj_GMT);

		if (type == json_type_int) {
			GMT = json_object_get_int(obj_GMT);
		}
	}

	exists = json_object_object_get_ex(jobj, "MonthStart", &obj_MonthStart);

	if (exists) {
		type = json_object_get_type(obj_MonthStart);

		if (type == json_type_int) {
			MonthStart = json_object_get_int(obj_MonthStart);
		}
	}

	exists = json_object_object_get_ex(jobj, "PriorityStart", &obj_PriorityStart);

	if (exists) {
		type = json_object_get_type(obj_PriorityStart);

		if (type == json_type_int) {
			PriorityStart = json_object_get_int(obj_PriorityStart);
		}
	}

	exists = json_object_object_get_ex(jobj, "WeekStart", &obj_WeekStart);

	if (exists) {
		type = json_object_get_type(obj_WeekStart);

		if (type == json_type_int) {
			WeekStart = json_object_get_int(obj_WeekStart);
		}
	}

	exists = json_object_object_get_ex(jobj, "HourStart", &obj_HourStart);

	if (exists) {
		type = json_object_get_type(obj_HourStart);
		if (type == json_type_int) {
			HourStart = json_object_get_int(obj_HourStart);
		}

		exists = json_object_object_get_ex(jobj, "MonthEnd", &obj_MonthEnd);

		if (exists) {
			type = json_object_get_type(obj_MonthEnd);

			if (type == json_type_int) {
				MonthEnd = json_object_get_int(obj_MonthEnd);
			}
		}

		exists = json_object_object_get_ex(jobj, "PriorityEnd", &obj_PriorityEnd);

		if (exists) {
			type = json_object_get_type(obj_PriorityEnd);

			if (type == json_type_int) {
				PriorityEnd = json_object_get_int(obj_PriorityEnd);
			}
		}

		exists = json_object_object_get_ex(jobj, "WeekEnd", &obj_WeekEnd);

		if (exists) {
			type = json_object_get_type(obj_WeekEnd);

			if (type == json_type_int) {
				WeekEnd = json_object_get_int(obj_WeekEnd);
			}
		}

		exists = json_object_object_get_ex(jobj, "HourEnd", &obj_HourEnd);

		if (exists) {
			type = json_object_get_type(obj_HourEnd);

			if (type == json_type_int) {
				HourEnd = json_object_get_int(obj_HourEnd);
			}
		}

		exists = json_object_object_get_ex(jobj, "BiasSet", &obj_BiasSet);

		if (exists) {
			type = json_object_get_type(obj_BiasSet);

			if (type == json_type_int) {
				BiasSet = json_object_get_int(obj_BiasSet);
			}
		}

		BiasSet = GMT - BiasSet;
		BiasHr = BiasSet / 60;
		BiasSet = BiasSet - BiasHr * 60;
		if (BiasSet < 0) {
			BiasSet = -BiasSet;
		}

		GMT_hr = GMT / 60;
		GMT_min = GMT - GMT_hr * 60;
		if (GMT_min < 0) {
			GMT_min = -GMT_min;
		}

		json_object_put(jobj);

		snprintf(cmdstr, sizeof(cmdstr), "GMT%d:%dDST%d:%d,M%d.%d.%d/%d,M%d.%d.%d/%d", GMT_hr, GMT_min, BiasHr,
		         BiasSet, MonthStart, PriorityStart, WeekStart, HourStart, MonthEnd, PriorityEnd, WeekEnd,
		         HourEnd);

		snprintf(buf1, sizeof(buf1), "/system/www/cgi-bin/DSTConf.sh set %s", cmdstr);
		printf("<p>%s\n</p>", buf1);

		char *const args[] = { "/system/www/cgi-bin/DSTConf.sh", "set", cmdstr, NULL };
		char output[1024] = { 0 };
		execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

		printf("<p>status=%d</p>", status);
	}
}

void fcgiTZSet(char *buf)
{
	int exists;
	enum json_type type;
	char cmdstr[200];
	char buf1[2048];
	int status;
	int GMT = 0;
	int GMT_hr = 0;
	int GMT_min = 0;
	json_object *obj_GMT;
	json_object *jobj = json_tokener_parse(buf);
	printf("Content-type: text/html\r\n\r\n");
	cmdstr[0] = 0;

	exists = json_object_object_get_ex(jobj, "GMT", &obj_GMT);

	if (exists) {
		type = json_object_get_type(obj_GMT);

		if (type == json_type_int) {
			GMT = json_object_get_int(obj_GMT);
		}
	}

	GMT_hr = GMT / 60;
	GMT_min = GMT - GMT_hr * 60;
	if (GMT_min < 0) {
		GMT_min = -GMT_min;
	}

	json_object_put(jobj);
	snprintf(cmdstr, sizeof(cmdstr), "GMT%d:%d", GMT_hr, GMT_min);
	snprintf(buf1, sizeof(buf1), "/system/www/cgi-bin/DSTConf.sh set %s", cmdstr);
	printf("<p>%s\n</p>", buf1);

	char output[1024] = { 0 };
	char *const args[] = { "/system/www/cgi-bin/DSTConf.sh", "set", cmdstr, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("<p>status=%d</p>", status);
}

void fcgiEnabledSet(char *buf)
{
	int exists;
	int Manual_en = 0;
	int DST_en = 0;
	int Sync_en = 0;
	enum json_type type;
	char cmdstr[200];
	char buf1[2048];
	int status;
	json_object *obj_Manual, *obj_DST, *obj_Sync;
	json_object *jobj = json_tokener_parse(buf);
	printf("Content-type: text/html\r\n\r\n");
	cmdstr[0] = 0;

	exists = json_object_object_get_ex(jobj, "Manual_enabled", &obj_Manual);

	if (exists) {
		type = json_object_get_type(obj_Manual);

		if (type == json_type_boolean) {
			Manual_en = json_object_get_int(obj_Manual);
		}
	}

	exists = json_object_object_get_ex(jobj, "DST_enabled", &obj_DST);

	if (exists) {
		type = json_object_get_type(obj_DST);

		if (type == json_type_boolean) {
			DST_en = json_object_get_int(obj_DST);
		}
	}

	exists = json_object_object_get_ex(jobj, "SyncWithPC_enabled", &obj_Sync);

	if (exists) {
		type = json_object_get_type(obj_Sync);

		if (type == json_type_boolean) {
			Sync_en = json_object_get_int(obj_Sync);
		}
	}

	json_object_put(jobj);
	snprintf(cmdstr, sizeof(cmdstr), "%d %d %d", Manual_en, DST_en, Sync_en);
	snprintf(buf1, sizeof(buf1), "/system/www/cgi-bin/DSTConf.sh setEnabled %s", cmdstr);
	printf("<p>%s\n</p>", buf1);

	char output[1024] = { 0 };
	char arg1[8], arg2[8], arg3[8];
	snprintf(arg1, sizeof(arg1), "%d", Manual_en);
	snprintf(arg2, sizeof(arg2), "%d", DST_en);
	snprintf(arg3, sizeof(arg3), "%d", Sync_en);
	char *const args[] = { "/system/www/cgi-bin/DSTConf.sh", "setEnabled", arg1, arg2, arg3, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("<p>status=%d</p>", status);
}

void fcgiTimeSwitchSet(char *MachineMode, char *buf)
{
	int exists;
	char TimeStart[20];
	char TimeEnd[20];
	char s[5] = ":";
	char *TimeStart_hr;
	char *TimeStart_min;
	char *TimeEnd_hr;
	char *TimeEnd_min;
	int timeStart_hr = 0;
	int timeStart_min = 0;
	int timeEnd_hr = 0;
	int timeEnd_min = 0;
	int TimeSwitch_en = 0;
	int timeNow_hr = 0;
	int timeNow_min = 0;
	enum json_type type;
	char cmdstr[200];
	char buf1[2048];
	int status = 0;
	char output[1024] = { 0 };
	json_object *obj_TimeStart, *obj_TimeEnd, *obj_TimeSwitch_enabled, *obj_TimeNowHr, *obj_TimeNowMin;
	json_object *jobj = json_tokener_parse(buf);
	printf("Content-type: text/html\r\n\r\n");
	cmdstr[0] = 0;

	exists = json_object_object_get_ex(jobj, "TimeSwitch_enabled", &obj_TimeSwitch_enabled);

	if (exists) {
		type = json_object_get_type(obj_TimeSwitch_enabled);

		if (type == json_type_boolean) {
			TimeSwitch_en = json_object_get_int(obj_TimeSwitch_enabled);
		}
	}

	exists = json_object_object_get_ex(jobj, "time_start", &obj_TimeStart);

	if (exists) {
		type = json_object_get_type(obj_TimeStart);

		if (type == json_type_string) {
			strncpy(TimeStart, json_object_get_string(obj_TimeStart), 20);
		}
	}

	exists = json_object_object_get_ex(jobj, "time_end", &obj_TimeEnd);

	if (exists) {
		type = json_object_get_type(obj_TimeEnd);

		if (type == json_type_string) {
			strncpy(TimeEnd, json_object_get_string(obj_TimeEnd), 20);
		}
	}

	exists = json_object_object_get_ex(jobj, "time_now_hr", &obj_TimeNowHr);

	if (exists) {
		type = json_object_get_type(obj_TimeNowHr);

		if (type == json_type_int) {
			timeNow_hr = json_object_get_int(obj_TimeNowHr);
		}
	}

	exists = json_object_object_get_ex(jobj, "time_now_min", &obj_TimeNowMin);

	if (exists) {
		type = json_object_get_type(obj_TimeNowMin);

		if (type == json_type_int) {
			timeNow_min = json_object_get_int(obj_TimeNowMin);
		}
	}

	TimeStart_hr = strtok(TimeStart, s);
	TimeStart_min = strtok(NULL, s);

	TimeEnd_hr = strtok(TimeEnd, s);
	TimeEnd_min = strtok(NULL, s);

	timeStart_hr = atoi(TimeStart_hr);
	timeStart_min = atoi(TimeStart_min);
	timeEnd_hr = atoi(TimeEnd_hr);
	timeEnd_min = atoi(TimeEnd_min);

	json_object_put(jobj);

	if (timeEnd_hr >= timeStart_hr) {
		if (timeEnd_hr == timeNow_hr && timeNow_hr > timeStart_hr) {
			if (timeNow_min >= timeEnd_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",      "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
					               "'{\"night_mode\":\"ON\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			} else if (timeNow_min < timeEnd_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",       "-c",
					               "AGTX_CMD_ADV_IMG_PREF",      "-s",
					               "'{\"night_mode\":\"OFF\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			}
		} else if (timeEnd_hr > timeNow_hr && timeNow_hr == timeStart_hr) {
			if (timeNow_min >= timeStart_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",       "-c",
					               "AGTX_CMD_ADV_IMG_PREF",      "-s",
					               "'{\"night_mode\":\"OFF\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			} else if (timeNow_min < timeStart_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",      "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
					               "'{\"night_mode\":\"ON\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			}
		} else if (timeEnd_hr > timeNow_hr && timeNow_hr > timeStart_hr) {
			sprintf(buf1, "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
			printf("<p>%s\n</p>", buf1);
			char *const args[] = { "/system/bin/ccclient",       "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
				               "'{\"night_mode\":\"OFF\"}'", NULL };
			execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
			printf("<p>status=%d</p>", status);
		} else if (timeEnd_hr == timeNow_hr && timeNow_hr == timeStart_hr) {
			if (timeEnd_min > timeStart_min) {
				if (timeEnd_min > timeNow_min && timeNow_min >= timeStart_min) {
					sprintf(buf1,
					        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
					printf("<p>%s\n</p>", buf1);
					char *const args[] = { "/system/bin/ccclient",       "-c",
						               "AGTX_CMD_ADV_IMG_PREF",      "-s",
						               "'{\"night_mode\":\"OFF\"}'", NULL };
					execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
					printf("<p>status=%d</p>", status);
				} else {
					sprintf(buf1,
					        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
					printf("<p>%s\n</p>", buf1);
					char *const args[] = { "/system/bin/ccclient",      "-c",
						               "AGTX_CMD_ADV_IMG_PREF",     "-s",
						               "'{\"night_mode\":\"ON\"}'", NULL };
					execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
					printf("<p>status=%d</p>", status);
				}
			} else if (timeEnd_min < timeStart_min) {
				if (timeStart_min > timeNow_min && timeNow_min >= timeEnd_min) {
					sprintf(buf1,
					        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
					printf("<p>%s\n</p>", buf1);
					char *const args[] = { "/system/bin/ccclient",      "-c",
						               "AGTX_CMD_ADV_IMG_PREF",     "-s",
						               "'{\"night_mode\":\"ON\"}'", NULL };
					execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
					printf("<p>status=%d</p>", status);
				} else {
					sprintf(buf1,
					        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
					printf("<p>%s\n</p>", buf1);
					char *const args[] = { "/system/bin/ccclient",       "-c",
						               "AGTX_CMD_ADV_IMG_PREF",      "-s",
						               "'{\"night_mode\":\"OFF\"}'", NULL };
					execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
					printf("<p>status=%d</p>", status);
				}
			}
		} else {
			sprintf(buf1, "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
			printf("<p>%s\n</p>", buf1);
			char *const args[] = { "/system/bin/ccclient",      "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
				               "'{\"night_mode\":\"ON\"}'", NULL };
			execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
			printf("<p>status=%d</p>", status);
		}
	} else if (timeStart_hr > timeEnd_hr) {
		if (timeStart_hr == timeNow_hr && timeNow_hr > timeEnd_hr) {
			if (timeNow_min >= timeStart_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",       "-c",
					               "AGTX_CMD_ADV_IMG_PREF",      "-s",
					               "'{\"night_mode\":\"OFF\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			} else if (timeNow_min < timeStart_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",      "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
					               "'{\"night_mode\":\"ON\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			}
		} else if (timeStart_hr > timeNow_hr && timeNow_hr == timeEnd_hr) {
			if (timeNow_min >= timeEnd_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",      "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
					               "'{\"night_mode\":\"ON\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			} else if (timeNow_min < timeEnd_min) {
				sprintf(buf1,
				        "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
				printf("<p>%s\n</p>", buf1);
				char *const args[] = { "/system/bin/ccclient",       "-c",
					               "AGTX_CMD_ADV_IMG_PREF",      "-s",
					               "'{\"night_mode\":\"OFF\"}'", NULL };
				execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
				printf("<p>status=%d</p>", status);
			}
		} else if (timeEnd_hr > timeNow_hr && timeNow_hr > timeStart_hr) {
			sprintf(buf1, "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"ON\"}'");
			printf("<p>%s\n</p>", buf1);
			char *const args[] = { "/system/bin/ccclient",      "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
				               "'{\"night_mode\":\"ON\"}'", NULL };
			execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
			printf("<p>status=%d</p>", status);
		} else {
			sprintf(buf1, "/system/bin/ccclient -c AGTX_CMD_ADV_IMG_PREF -s '{\"night_mode\":\"OFF\"}'");
			printf("<p>%s\n</p>", buf1);
			char *const args[] = { "/system/bin/ccclient",       "-c", "AGTX_CMD_ADV_IMG_PREF", "-s",
				               "'{\"night_mode\":\"OFF\"}'", NULL };
			execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
			printf("<p>status=%d</p>", status);
		}
	}

	snprintf(cmdstr, sizeof(cmdstr), "%d %02d %02d %02d %02d", TimeSwitch_en, timeStart_hr, timeStart_min,
	         timeEnd_hr, timeEnd_min);
	snprintf(buf1, sizeof(buf1), "/system/www/cgi-bin/TimeSwitch.sh setTimeSwitch %s", cmdstr);
	printf("<p>%s\n</p>", buf1);

	char *const args[] = { "/system/www/cgi-bin/TimeSwitch.sh", "setTimeSwitch", cmdstr, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
	printf("<p>status=%d</p>", status);

	snprintf(buf1, sizeof(buf1), "/etc/init.d/%s/S55timeSwitch", MachineMode);
	printf("<p>%s restart\n</p>", buf1);
	char *const args2[] = { buf1, "restart", NULL };
	execCommandAndGetOutput(args2[0], args2, output, sizeof(output), &status);
	printf("<p>status(echo)=%d</p>", status);

	snprintf(buf1, sizeof(buf1), "/etc/init.d/%s/S99cron", MachineMode);
	printf("<p>%s restart\n</p>", buf1);
	char *const args3[] = { buf1, "restart", NULL };
	execCommandAndGetOutput(args3[0], args3, output, sizeof(output), &status);
	printf("<p>status(echo)=%d</p>", status);
}

void fcgiGetFaceModelList(void)
{
	DIR *dir;
	struct dirent *ent;
	char *FaceModelPath = "/usrdata/eaif/facereco/faces";
	int count = 0;

	printf("Content-type: text/html\r\n\r\n");
	printf("[");
	if ((dir = opendir(FaceModelPath)) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			if (count <= 1) {
				// omit directory . & ..
			} else if (count == 2) {
				printf("\"%s\"", ent->d_name);
			} else {
				printf(",\"%s\"", ent->d_name);
			}
			count++;
		}
		closedir(dir);
	} else {
		/*   could not open directory */
		perror("");
	}
	printf("]");
}

void fcgiRemoveFile(char *buf)
{
	char remove_file[200] = { 0 };
	char output[1024] = { 0 };
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");

	snprintf(remove_file, sizeof(remove_file), "\"%s\"", buf);
	char *const args[] = { "/system/www/cgi-bin/removeFile.sh", remove_file, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("{\"rval\":%d}", status);
}

void fcgiValidateFaceModel(char *buf)
{
	char face_model[200] = { 0 };
	char output[1024] = { 0 };
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");

	snprintf(face_model, sizeof(face_model), "\"%s\"", buf);
	char *const args[] = { "/system/www/cgi-bin/validateFaceModel.sh", face_model, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("{\"rval\":%d}", status);
}

void fcgiRegisterFaceModel(char *buf)
{
	char face_model[200] = { 0 };
	char output[1024] = { 0 };
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");

	snprintf(face_model, sizeof(face_model), "\"%s\"", buf);
	char *const args[] = { "/system/www/cgi-bin/registerFaceModel.sh", face_model, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("{\"rval\":%d}", status);
}

void fcgiUnregisterFaceModel(char *buf)
{
	char face_model[200] = { 0 };
	char output[1024] = { 0 };
	int status = 0;
	printf("Content-type: text/html\r\n\r\n");

	snprintf(face_model, sizeof(face_model), "\"%s\"", buf);
	char *const args[] = { "/system/www/cgi-bin/unregisterFaceModel.sh", face_model, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);

	printf("{\"rval\":%d}", status);
}

void fcgiSetWifi(char *buf)
{
	int exists, exists1;
	int status;
	char output[1024] = { 0 };
	enum json_type type;
	char cmdstr[200];
	char ssid[100];
	char psk[100];
	json_object *obj_ssid, *obj_psk;
	json_object *jobj;
	cmdstr[0] = 0;
	printf("Content-type: text/html\r\n\r\n");
	jobj = json_tokener_parse(buf);
	exists = json_object_object_get_ex(jobj, "ssid", &obj_ssid);
	if (exists) {
		type = json_object_get_type(obj_ssid);
		if (type == json_type_string) {
			strncpy(ssid, json_object_get_string(obj_ssid), 100);
			printf("<p>ssid:%s\n</p>", ssid);

			exists1 = json_object_object_get_ex(jobj, "psk", &obj_psk);
			if (exists1) {
				type = json_object_get_type(obj_psk);

				if (type == json_type_string) {
					strncpy(psk, json_object_get_string(obj_psk), 100);
					printf("<p>psk:%s\n</p>", psk);
					//printf("{\"rval\":0}");
				}
			}
		}
	}
	json_object_put(jobj);
	printf("<p>%s\n</p>", cmdstr);

	// Edit /etc/wpa_supplicant.conf
	char *const args[] = { "/system/www/cgi-bin/setWPA.sh", ssid, psk, NULL };
	execCommandAndGetOutput(args[0], args, output, sizeof(output), &status);
	memset(ssid, 0, sizeof(ssid));
	memset(psk, 0, sizeof(psk));
	printf("<p>status=%d\n</p>", status);

	// Connet wifi with /etc/wpa_supplicant.conf
	char *const args2[] = { "/system/script/wifi_on.sh", "/etc/wpa_supplicant.conf", NULL };
	int exit_status;
	int rc = secure_exec_script(args2[0], args2, &exit_status);
	if (rc == 0 && exit_status == 0) {
	    printf("Script success\n");
	} else {
	    printf("Script failed: rc=%d exit_status=%d\n", rc, exit_status);
	}
}

void fcgiDisconnectWifi()
{
	printf("Content-type: text/html\r\n\r\n");
	char buf[1024] = { 0 };
	int status = 0;
	char *const args[] = { "/system/script/wifi_off.sh", NULL };
	execCommandAndGetOutput(args[0], args, buf, sizeof(buf), &status);
}

static void scanSSIDtoTargetFile(const char *target_file)
{
	int pipefd[2];

	/* Create a pipe to connect the output of `iw` to the input of `grep` */
	if (pipe(pipefd) == -1) {
		perror("pipe");
		return;
	}

	/* Fork the first child process to execute `iw dev wlan0 scan` */

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return;
	}

	if (pid == 0) { /* Child process to execute `iw` */
		close(pipefd[0]); /* Close the read end of the pipe */
		dup2(pipefd[1], STDOUT_FILENO); /* Redirect stdout to the pipe's write end */
		close(pipefd[1]); /* Close the write end of the pipe */

		/* Execute `iw dev wlan0 scan` */
		char *argv[] = { "/usr/sbin/iw", "dev", "wlan0", "scan", NULL };
		execve("/usr/sbin/iw", argv, NULL);

		/* Print error message if execve fails */
		perror("execve failed");
		_exit(127);
	}

	/* Fork the second child process to execute `grep SSID:` */
	pid_t pid2 = fork();
	if (pid2 == -1) {
		perror("fork");
		return;
	}

	if (pid2 == 0) { /* Child process to execute `grep` */
		close(pipefd[1]); /* Close the write end of the pipe */
		dup2(pipefd[0], STDIN_FILENO); /* Redirect stdin to the pipe's read end */
		close(pipefd[0]); /* Close the read end of the pipe */

		/* Open the output file for writing. Create it if not exists */
		FILE *output = fopen(target_file, "w");
		if (!output) {
			perror("fopen");
			_exit(126);
		}

		/* Redirect stdout to the file */
		dup2(fileno(output), STDOUT_FILENO);
		fclose(output);

		/* Execute `grep SSID:` */
		char *argv[] = { "/bin/grep", "SSID:", NULL };
		execve("/bin/grep", argv, NULL);

		/* Print error message if execve fails */
		perror("execve failed");
		_exit(127);
	}

	/* Parent process closes unused pipe ends and waits for child processes */
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);

	return;
}

void fcgiGetSSID()
{
	char *tmp;
	int i = 0, j = 0;
	char str[128];
	char buffer[128];
	char SSID[128][128];
	char list[1024];
	char number[16];
	list[0] = 0;
	printf("Content-type: text/html\r\n\r\n");
	scanSSIDtoTargetFile("/tmp/SSID");
	FILE *fp = fopen("/tmp/SSID", "r");
	while (fgets(buffer, sizeof(buffer), fp)) {
		tmp = strstr(buffer, "SSID:");
		sscanf(tmp, "%*s %127[^\t\n]", str);
		memset(buffer, 0x00, sizeof(buffer));
		strncpy(SSID[i], str, sizeof(SSID[i]));
		i++;
	}
	fclose(fp);
	strncat(list, "{\"ssidnumber\":", sizeof(list) - strlen("{\"ssidnumber\":") - 1);
	sprintf(number, "%d", i);
	strncat(list, number, sizeof(list) - strlen(number) - 1);
	strncat(list, ",\"SSID\":[", sizeof(list) - strlen("{\"SSID\":") - 1);
	for (j = 0; j < i; j++) {
		strncat(list, "\"", sizeof(list) - strlen("\"") - 1);
		strncat(list, SSID[j], sizeof(list) - strlen(SSID[j]) - 1);
		if (j < i - 1) {
			strncat(list, "\",", sizeof(list) - strlen("\",") - 1);
		} else {
			strncat(list, "\"]}", sizeof(list) - strlen("\"]}") - 1);
		}
	}
	memset(SSID, 0, sizeof(SSID));
	printf("%.*s", strlen(list), list);
	memset(list, 0, sizeof(list));
}

void fcgiGetWPASSID()
{
	char *tmp;
	char str[128];
	char ssid[128];
	char psk[128];
	printf("Content-type: text/html\r\n\r\n");
	FILE *fp = fopen("/etc/wpa_supplicant.conf", "r");
	while (fgets(str, sizeof(str), fp)) {
		if ((tmp = strstr(str, "ssid"))) {
			sscanf(tmp, "%*[^\"]\"%127[^\"]", ssid);
		}
		if ((tmp = strstr(str, "psk"))) {
			sscanf(tmp, "%*[^\"]\"%127[^\"]", psk);
		}
	}
	fclose(fp);
	printf("{\"ssid\":\"%s\",\"psk\":\"%s\"}", ssid, psk);
	memset(ssid, 0, sizeof(ssid));
	memset(psk, 0, sizeof(psk));
	memset(str, 0, sizeof(str));
}

void fcgiGetWlanInfo()
{
	char *tmp;
	char ssid[128] = {0};
	char straddr[128] = {0};
	char output[1024] = {0};
	int ret;

	printf("Content-type: text/html\r\n\r\n");

	// === use iw to get SSID ===
	setenv("PATH", "/sbin:/usr/sbin:/bin:/usr/bin", 1);  // make sure busybox path
	char *const iw_args[] = {"/usr/sbin/iw", "dev", "wlan0", "link", NULL};
	execCommandAndGetOutput("/usr/sbin/iw", iw_args, output, sizeof(output), &ret);
	fprintf(stderr, "iw output: [%s], ret=%d\n", output, ret);

	tmp = strstr(output, "SSID:");
	if (tmp) {
		sscanf(tmp, "SSID: %127[^\n]", ssid);
	}

	// === use ifconfig to get IP ===
	memset(output, 0, sizeof(output));
	char *const ifconfig_args[] = {"/sbin/ifconfig", "wlan0", NULL};
	execCommandAndGetOutput("/sbin/ifconfig", ifconfig_args, output, sizeof(output), &ret);
	fprintf(stderr, "ifconfig output: [%s], ret=%d\n", output, ret);

	char *line = strtok(output, "\n");
	while (line) {
		tmp = strstr(line, "inet addr:");
		if (tmp) {
			sscanf(tmp, "inet addr:%127s", straddr);
			break;
		}
		line = strtok(NULL, "\n");
	}

	printf("{\"ssid\":\"%s\",\"wifiIP\":\"%s\"}", ssid, straddr);
	memset(ssid, 0, sizeof(ssid));
}


void fcgiPackNginxLog(void)
{
	int status = 0;
	char buf[1024] = { 0 };
	printf("Content-type: text/html\r\n\r\n");
	char *const args[] = { "/system/www/cgi-bin/packNginxLog.sh", NULL };
	execCommandAndGetOutput(args[0], args, buf, sizeof(buf), &status);
	printf("{\"rval\":%d}", status);
}

