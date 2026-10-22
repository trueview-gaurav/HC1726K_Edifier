#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>

#define HOSTS_PATH       "/etc/hosts"
#define HOSTNAME_PATH    "/etc/hostname"
#define RESOLV_CONF_PATH "/tmp/resolv.conf"
#define INTERFACES_PATH  "/etc/network/interfaces"

static void runSed(char *const k_cmd, char *const k_filename)
{
	pid_t pid = fork();
	if (pid == 0) {
		char *const args[] = { "/bin/sed", "-i", k_cmd, k_filename, NULL };
		extern char **environ;

		execve("/bin/sed", args, environ);
		fprintf(stderr, "Failed to exec %.*s %.*s\n", (int)strlen(k_cmd), k_cmd, (int)strlen(k_filename),
		        k_filename);
	} else if (pid > 0) {
		wait(NULL);
	} else {
		perror("fork failed");
	}
}

static void runHostname(char *const k_hostname)
{
	pid_t pid = fork();
	if (pid == 0) {
		char *const args[] = { "/bin/hostname", k_hostname, NULL };
		extern char **environ;

		execve("/bin/hostname", args, environ);
		fprintf(stderr, "Failed to exec %.*s\n", (int)strlen(k_hostname), k_hostname); /** execve error */
	} else if (pid > 0) {
		wait(NULL);
	} else {
		perror("fork failed");
	}
}

static void runEcho(char *const k_content, char *const k_target)
{
	pid_t pid = fork();

	if (pid == 0) {
		extern char **environ;
		char command[512];
		snprintf(command, sizeof(command), "echo %s > %s", k_content, k_target);
		char *const args[] = { "/bin/sh", "-c", command, NULL };

		execve("/bin/sh", args, environ);
		fprintf(stderr, "Failed to echo %.*s\n", (int)strlen(k_content), k_content); /** execve error */
	} else if (pid > 0) {
		wait(NULL);
	} else {
		perror("fork failed");
	}
}

static void runSync()
{
	pid_t pid;
	int status;
	pid_t ret;
	char *const args[] = { "/bin/sync", NULL };
	extern char **environ;

	pid = fork();
	if (pid == -1) {
		/* Handle error */
	} else if (pid != 0) {
		while ((ret = waitpid(pid, &status, 0)) == -1) {
			if (errno != EINTR) {
				/* Handle error */
				break;
			}
		}
		if ((ret == 0) || !(WIFEXITED(status) && !WEXITSTATUS(status))) {
			/* Report unexpected child status */
		}
	} else {
		if (execve("/bin/sync", args, environ) == -1) {
			/* Handle error */
			fprintf(stderr, "Failed to sync\n");
		}
	}
}

char* const short_options = "hs:i:m:g:d:n:b:";
static const struct option long_options[] = {
	{ "help", no_argument, NULL, 'h' },
	{ "switch", required_argument, NULL, 's' },
	{ "ip", required_argument, NULL, 'i' },
	{ "mask", required_argument, NULL, 'm' },
	{ "gateway", required_argument, NULL, 'g' },
	{ "dns", required_argument, NULL, 'd' },
	{ "hostname", required_argument, NULL, 'n' },
	{ 0, 0, 0, 0 }
};

void help()
{
	printf("Usage:\n");
	printf("\tip_assign <Options> [args]\n");
	printf("\nOptions:\n");
	printf("\t-h                      help\n");
	printf("\t-s <dhcp/static>        switch inet dhcp/static\n");
	printf("\t-i <IP address>         set address <IP address>\n");
	printf("\t-m <Subnet mask>        set netmask <Subnet mask>\n");
	printf("\t-g <gateway>            set gateway <gateway>\n");
	printf("\t-d <\"DNS1 [DNS2]\">      set DNS <DNS1 [DNS2]>\n");
	printf("\t-n <Hostname>           set hostname <Hostname>\n");
}

int main(int argc, char *argv[])
{
	char command[120];
	int c = 0;

	if (argc < 2) {
		help();
		return 0;
	}

	while ((c = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
		switch (c) {
			case 'i':
			        snprintf(command, sizeof(command), "s/address .*/address %s/", optarg);
			        runSed(command, INTERFACES_PATH);
			        break;
		        case 's':
			        snprintf(command, sizeof(command), "s/iface eth0 inet .*/iface eth0 inet %s/", optarg);
			        runSed(command, INTERFACES_PATH);
			        break;
		        case 'm':
			        snprintf(command, sizeof(command), "s/netmask .*/netmask %s/\n", optarg);
			        runSed(command, INTERFACES_PATH);
			        break;
		        case 'g':
			        snprintf(command, sizeof(command), "s/gateway .*/gateway %s/", optarg);
			        runSed(command, INTERFACES_PATH);
			        break;
		        case 'd':
			        snprintf(command, sizeof(command), "s/dns-nameservers .*/dns-nameservers %s/", optarg);
			        runSed(command, INTERFACES_PATH);
			        break;
		        case 'n':
			        runHostname(optarg);
			        runEcho(optarg, HOSTNAME_PATH);
			        snprintf(command, sizeof(command), "s/127.0.1.1\t.*/127.0.1.1\t%s/", optarg);
			        runSed(command, HOSTS_PATH);
			        break;
		        case 'h':
		        default:
				help();
				break;
		}
	}
	runSync();

	return 0;
}
