#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h> /* Include this header for chmod() */
#include <sys/wait.h>
#include <getopt.h> /* Include for command line parsing */
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#include "openssl/bio.h"
#include "openssl/evp.h"
#include "openssl/buffer.h"
#include "openssl/err.h"
#include "json.h"

#include "log_define.h"
#include "tee.h"

#define HTTP_BUF_SIZE 2048
#define HTPASSWD_FILE "/etc/nginx/.htpasswd"
#define DAFAULT_PASSWORD_FLAG "/system/www/.default-passwd"
#define AUTH_SOCKET_PATH "/tmp/auth_socket"
#define OPTEE_USER_AUTH_CA "/system/bin/optee_example_user_auth_agtx"
#define OPTEE_SECURE_STORAGE_FILE_NAME "tee_auth_passwd"

static int g_run_flag = 0;

/**
 * @brief Base64 decoding function.
 * @details Decodes a Base64-encoded string into raw binary data.
 * @param[in] input Base64-encoded input string.
 * @param[out] output_len Pointer to a variable that stores the length of the decoded data.
 * @return Pointer to the decoded buffer.
 * @retval Non-NULL Successful decoding.
 * @retval NULL Failed to decode or memory allocation error.
 */
unsigned char *base64Decode(const char *input, size_t *output_len)
{
	BIO *b64 = NULL, *bio = NULL;
	size_t input_len = strlen(input);
	unsigned long err = 0;

	/* Calculate the number of padding characters */
	size_t padding = 0;
	if (input_len >= 2) {
		if (input[input_len - 1] == '=')
			padding++;
		if (input[input_len - 2] == '=')
			padding++;
	}

	/* Estimate the decoded length */
	*output_len = (input_len * 3) / 4 - padding;
	unsigned char *output = malloc(*output_len + 1); /* +1 for null terminator */
	if (!output) {
		log_debug("Failed to alloc memory for base64 decode\n");
		goto return_with_error;
	}

	/* Create Base64 BIO */
	b64 = BIO_new(BIO_f_base64());
	if (!b64) {
		log_debug("Failed to create Base64 BIO\n");
		goto return_with_error;
	}

	BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); /* Disable newline processing */
	bio = BIO_new_mem_buf(input, -1); /* Use original input with automatic length calculation */
	if (!bio) {
		log_debug("Failed to create memory BIO\n");
		goto return_with_error;
	}
	bio = BIO_push(b64, bio);
	if (bio == NULL) {
		log_debug("Failed to push BIO\n");
		goto return_with_error;
	}

	/* Read the decoded data */
	int len = BIO_read(bio, output, input_len);
	if (len <= 0) {
		log_debug("Failed to decode Base64 input");
		goto return_with_error;
	} else {
		output[len] = '\0'; /* Null-terminate the decoded string */
		*output_len = len;
	}

	/* Free BIO resources */
	BIO_free_all(bio);
	return output;

return_with_error:
	err = ERR_get_error();
	log_debug("OpenSSL error: %s\n", ERR_error_string(err, NULL));

	if (output) {
		log_debug("Base64 decoding failed. Please check the input string.\n");
		free(output);
		output = NULL;
	}

	if (bio != NULL) {
		BIO_free_all(bio);
	}

	return NULL;
}

/**
 * @brief Find user in .htpasswd file
 * @details Searches for the specified username in the .htpasswd file and retrieves it.
 * @param[in] username Username to search for.
 * @arg
 * @see
 * @return Pointer to the hash string if found.
 * @retval Non-NULL Found the user
 * @retval NULL User not found or error occurred.
 */
static char *findUserInHtpasswd(const char *username)
{
	FILE *file = fopen(HTPASSWD_FILE, "r");
	if (!file) {
		log_debug("Failed to open %s\n", HTPASSWD_FILE);
		return NULL;
	}

	char line[MAX_USER_NAME_LEN];
	while (fgets(line, sizeof(line), file)) {
		/* Remove trailing newline character, if present */
		line[strcspn(line, "\n")] = '\0';

		/* Split the line into username and optional hash */
		char *stored_username = strtok(line, ":");
		if (stored_username && strcmp(stored_username, username) == 0) {
			fclose(file);
			return strdup(stored_username); /* Return a copy of the username */
		}
	}

	fclose(file);
	return NULL; /* Username not found */
}

/**
 * @brief Save the username to the .htpasswd file.
 * @details 
 * - Opens the .htpasswd file in write mode, clearing its existing content.
 * - Writes the provided username followed by a null character to the file.
 * 
 * @param[in] username Pointer to the username to be saved.
 * 
 * @arg None
 * 
 * @see None
 * 
 * @return Status of the save operation.
 * @retval 0 Successfully saved the username.
 * @retval -1 Failed to save the username (e.g., file open error).
 */
static int saveUserName(unsigned char *username)
{
	/* Open the .htpasswd file to write the new user (clearing existing content) */
	FILE *file = fopen(HTPASSWD_FILE, "w");
	if (!file) {
		log_debug("Failed to open %s: %s\n", HTPASSWD_FILE, strerror(errno));
		return -1;
	}

	if ((fprintf(file, "%s:", username) < 0) || (fputc('\0', file) == EOF)) {
		log_debug("Failed to write username character to %s: %s\n", HTPASSWD_FILE, strerror(errno));

		if (fclose(file) != 0) {
			log_debug("Failed to close %s: %s\n", HTPASSWD_FILE, strerror(errno));
		}
		return -1;
	}

	if (fclose(file) != 0) {
		log_debug("Failed to close %s: %s\n", HTPASSWD_FILE, strerror(errno));
		return -1;
	}

	return 0;
}

/**
 * @brief Run OPTEE command.
 *
 * This function forks a pid and executes the input command
 *
 * @param[in] argv
 *
 * @return 0 on success, error code on failure
 *
 * @note
 * @warning
 */
static int run_optee_cmd(char *const argv[])
{
	pid_t pid = fork();
	if (pid < 0) {
		log_err("fork failed\n");
		return -1;
	}

	if (pid == 0) {
		execv(argv[0], argv);
		perror("execv");
		_exit(127);
	}

	int status = 0;
	if (waitpid(pid, &status, 0) == -1) {
		log_err("waitpid failed\n");
		return -1;
	}

	return (WIFEXITED(status) && WEXITSTATUS(status) == 0) ? 0 : -1;
}

/**
 * @brief Check usage of TEE secure storage.
 *
 * This function checks whether OPTEE_SECURE_STORAGE_FILE_NAME is exists
 *
 * @param[in]
 * @param[out]
 *
 * @return 0 on success, error code on failure
 *
 * @note
 * @warning
 */
static int checkUsageOfTEE(void)
{
	char *const argv[] = { OPTEE_USER_AUTH_CA, "-check", OPTEE_SECURE_STORAGE_FILE_NAME, NULL };
	return run_optee_cmd(argv);
}

/**
 * @brief Save the username and password to the TEE secure storage.
 * @details 
 * - Stores the username and password in TEE secure storage file.
 * 
 * @param[in] username Pointer to the username to be saved.
 * @param[in] username_len Length of the username.
 * @param[in] password Pointer to the password to be saved.
 * @param[in] passwd_len Length of the password.
 * 
 * @arg
 * 
 * @see
 * 
 * @return Status of the save operation.
 * @retval 0 Successfully saved the password in the TEE secure storage.
 */
static int savePasswdToTEE(unsigned char *username, size_t username_len, unsigned char *password, size_t passwd_len)
{
	char *user_buf = strndup((const char *)username, username_len);
	char *pass_buf = strndup((const char *)password, passwd_len);
	if (!user_buf || !pass_buf) {
		log_err("Memory allocation failed\n");
		free(user_buf);
		free(pass_buf);
		return -1;
	}

	char *argv[] = {
		(char *)OPTEE_USER_AUTH_CA, "-reset", OPTEE_SECURE_STORAGE_FILE_NAME, user_buf, pass_buf, NULL
	};
	int ret = run_optee_cmd(argv);

	free(user_buf);
	free(pass_buf);
	return ret;
}

/**
 * @brief Verify the username and password to the TEE secure storage.
 * @details 
 * - Verify the username and password in TEE secure storage file.
 * 
 * @param[in] username Pointer to the username to be verified.
 * @param[in] username_len Length of the username.
 * @param[in] password Pointer to the password to be verified.
 * @param[in] passwd_len Length of the password.
 * 
 * @arg
 * 
 * @see
 * 
 * @return Status of the verify operation.
 * @retval 0 Successfully verified the password in the TEE secure storage.
 */
static int verifyPasswdInTEE(unsigned char *username, size_t username_len, unsigned char *password, size_t passwd_len)
{
	char *user_buf = strndup((const char *)username, username_len);
	char *pass_buf = strndup((const char *)password, passwd_len);
	if (!user_buf || !pass_buf) {
		log_err("Memory allocation failed\n");
		free(user_buf);
		free(pass_buf);
		return -1;
	}

	char *argv[] = {
		(char *)OPTEE_USER_AUTH_CA, "-verifyuser", OPTEE_SECURE_STORAGE_FILE_NAME, user_buf, pass_buf, NULL
	};
	int ret = run_optee_cmd(argv);

	free(user_buf);
	free(pass_buf);
	return ret;
}

/**
 * @brief Add new user to .htpasswd file, only allow 1 user once
 * @details Hashes the password using Argon2 and adds a new user to the .htpasswd file.
 * @param[in] new_username Username to add.
 * @param[in] new_password Password to hash and add.
 * @arg
 * @see
 * @return Result of adding user.
 * @retval 0 Successfully added user.
 * @retval -1 Failed to add user.
 */
static int addUserToHtpasswd(unsigned char *new_username, unsigned char *new_password)
{
	/* Check if the account password is the same as the old one */
	char *stored_username = findUserInHtpasswd((char *)new_username);
	if (stored_username != NULL) {
		log_debug("User exist: %s", stored_username);
		free(stored_username);
		stored_username = NULL;
	}

	/* Verify if change back to default password */
	if (strstr((char *)new_password, DEFAULT_PASSWD) != NULL) {
		log_debug("Please don't change the password including the default password.\n");
		return -EXIT_FAILURE;
	}

	if (saveUserName(new_username) != 0) {
		log_debug("Failed to add username: %s\n", new_username);
		return -EXIT_FAILURE;
	}

	if (savePasswdToTEE(new_username, strlen((char *)new_username), new_password, strlen((char *)new_password)) !=
	    0) {
		log_debug("Failed to save password\n");
		return -EXIT_FAILURE;
	}

	/* Remove default-password flag */
	if (access(DAFAULT_PASSWORD_FLAG, F_OK) == 0) {
		log_debug("Change default username and password\n");
		if (remove(DAFAULT_PASSWORD_FLAG) == 0) {
			log_debug("File '%s' deleted successfully.\n", DAFAULT_PASSWORD_FLAG);
		} else {
			log_debug("Failed to del File '%s'.\n", DAFAULT_PASSWORD_FLAG);
			return -EXIT_FAILURE;
		}
	}

	return 0;
}

/**
 * @brief Resets the username and password to their default values.
 * 
 * This function resets the system's username and password to their factory default values. 
 * It first sets the username to "admin" and writes it to the relevant file. 
 * Then, it resets the password to the predefined default password and stores it securely.
 * 
 * @return 0 on success, -1 on failure.
 *         Returns -1 if resetting either the username or the password fails.
 */
static int resetToDefault()
{
	unsigned char default_username[6];
	snprintf((char *)default_username, sizeof("admin"), "%s", "admin");

	if (saveUserName(default_username) != 0) {
		log_debug("Failed to reset default username\n");
		return -1;
	}

	if (savePasswdToTEE((unsigned char *)default_username, sizeof("admin"), (unsigned char *)DEFAULT_PASSWD,
	                    DEFAULT_PASSWD_LEN) != 0) {
		log_debug("Failed to reset default password\n");
		return -1;
	}

	return 0;
}

/**
 * @brief Create an empty file or update the timestamp of an existing file.
 * @details 
 * - Opens the specified file in write mode, creating it if it does not exist.
 * - Sets the file permissions to `0644` (read/write for owner, read-only for others).
 * - If the file exists, it updates its last modification timestamp.
 * 
 * @param[in] filename Path to the file to be created or updated.
 * 
 * @arg None
 * 
 * @see None
 * 
 * @return Status of the operation.
 * @retval 0 Successfully created or updated the file.
 * @retval -1 Failed to create or update the file (e.g., open error).
 */
static int touch(const char *filename)
{
	int fd = open(filename, O_CREAT | O_WRONLY, 0644);
	if (fd == -1) {
		log_debug("Failed to create '%s'\n", filename);
		return -1;
	}
	close(fd);
	return 0;
}

/**
 * @brief Handle incoming client request
 * @details Reads and processes client socket requests, performing authentication.
 * @param[in] client_socket Socket descriptor for the client.
 * @arg
 * @see
 * @return void.
 */
void handleAuthenticationOfHttp(int client_socket)
{
	int ret;
	char buffer[HTTP_BUF_SIZE];
	ssize_t bytes_read = read(client_socket, buffer, HTTP_BUF_SIZE - 1);
	if (bytes_read <= 0) {
		log_debug("Failed to read from socket, errno: %d\n", errno);
		close(client_socket);
		return;
	}
	buffer[bytes_read] = '\0';

	log_debug("%s\n", buffer);
	const char *auth_header_prefix = "Authorization: Basic ";
	/* Find the Authorization header */
	char *auth_header = strstr(buffer, auth_header_prefix);
	if (!auth_header) {
		goto close_client;
	}

	/* Extract the Base64-encoded credentials */
	auth_header += strlen(auth_header_prefix);
	char *end = strstr(auth_header, "\r\n");

#define AUTH_HEADER_BUF_SIZE 33
	char auth_buf[AUTH_HEADER_BUF_SIZE] = { 0 };
	if (end) {
		size_t len = end - auth_header;
		if (len >= AUTH_HEADER_BUF_SIZE) {
			log_debug("Auth header too long\n");
			goto close_client;
		}
		memcpy(auth_buf, auth_header, len);
		auth_buf[len] = '\0';
	}

	/* Decode Base64 credentials */
	size_t decoded_len;
	unsigned char *decoded_credentials = base64Decode(auth_buf, &decoded_len);
	memset(auth_buf, 0, sizeof(auth_buf));
	if (!decoded_credentials) {
		log_debug("failed to find credentials\n");
		goto close_client;
		return;
	}

	log_debug("decoded_credentials: %s", decoded_credentials);

	/* Split into username and password */
	char *input_username = strtok((char *)decoded_credentials, ":");
	char *input_password = strtok(NULL, ":");
	if (!input_username || !input_password) {
		log_debug("failed to find username and password\n");
		goto free_decoded_credentials;
	}

	log_debug("HTTP user/password: %s %s, len %d\n", input_username, input_password, strlen(input_password));

	/* Find the user's hashed password in secure storage */
	char *stored_username = findUserInHtpasswd(input_username);
	if (!stored_username) {
		log_debug("failed tp find username in htpasswd\n");
		goto free_decoded_credentials;
	}

	ret = verifyPasswdInTEE((unsigned char *)stored_username, strlen(stored_username),
							(unsigned char *)input_password, strlen(input_password));
	if (ret != 0) {
		log_debug("password verify failed: (%s, %d) ret: %d", input_password, strlen(input_password), ret);
		goto free_stored_username;
	}

	memset(decoded_credentials, 0, decoded_len);
	memset(stored_username, 0, strlen(stored_username));
	free(decoded_credentials);
	free(stored_username);

	/* Check for User-Agent: curl and Content-Type: application/json */
	char *user_agent = strstr(buffer, "User-Agent: curl");
	char *content_type = strstr(buffer, "Content-Type: application/json");

	if (user_agent == NULL || content_type == NULL) {
		goto response_ok;
	}

	char *body = strstr(buffer, "\r\n\r\n");

	if (!body) {
		log_debug("Failed to find HTTP body\n");
		goto bad_request;
	}

	body += 4; /* Move past the header-body separator */
	/* Parse JSON content using json-c */
	struct json_object *parsed_json = json_tokener_parse(body);

	if (!parsed_json) {
		log_debug("Failed to parse HTTP body to JSON: %s\n", body);
		goto bad_request;
	}

	/* Extract "username", "password", and "agent" from JSON */
	struct json_object *json_username = NULL;
	struct json_object *json_password = NULL;
	struct json_object *json_agent = NULL;

	if (0 == json_object_object_get_ex(parsed_json, "username", &json_username)) {
		log_debug("Failed to find username JSON obj\n");
		goto free_json;
	}
	if (0 == json_object_object_get_ex(parsed_json, "password", &json_password)) {
		log_debug("Failed to find password JSON obj\n");
		goto free_json;
	}

	if (0 == json_object_object_get_ex(parsed_json, "agent", &json_agent)) {
		log_debug("Failed to find agent scripts JSON obj\n");
		goto free_json;
	}

	const char *k_agent_str = json_object_get_string(json_agent);
	if (strcmp(k_agent_str, "passwd_secure.sh") != 0) {
		log_debug("Failed to find passwd scripts in HTTP body\n");
		goto free_json;
	}

	/* In case of adding a new user */
	if (json_username && json_password && json_object_is_type(json_username, json_type_string) &&
	    json_object_is_type(json_password, json_type_string)) {
		const char *username_str = json_object_get_string(json_username);
		const char *password_str = json_object_get_string(json_password);

		if (username_str == NULL || password_str == NULL) {
			log_debug("Username or passwd can't be empty: %s %s\n", username_str, password_str);
			goto free_json;
		}

		if (addUserToHtpasswd((unsigned char *)username_str, (unsigned char *)password_str) == 0) {
			log_debug("User '%s':%s added to .htpasswd successfully.\n", username_str, password_str);
		} else {
			log_debug("Failed to add user '%s' to .htpasswd.\n", username_str);
			goto free_json;
		}
	}

	/* Respond with 200 OK and skip authentication if conditions are met */
	/* Clean up the JSON object */
	json_object_put(parsed_json);
response_ok:
	memset(buffer, 0, sizeof(buffer));
	dprintf(client_socket, "HTTP/1.0 200 OK\r\n\r\n");
	close(client_socket);
	return;

free_json:
	/* Clean up the JSON object */
	json_object_put(parsed_json);

bad_request:
	memset(buffer, 0, sizeof(buffer));
	dprintf(client_socket, "HTTP/1.1 400 Bad Request\r\n"
	                       "Content-Type: text/plain\r\n"
	                       "Content-Length: 0\r\n"
	                       "\r\n");
	close(client_socket);
	return;

free_stored_username:
	memset(stored_username, 0, strlen(stored_username));
	free(stored_username);

free_decoded_credentials:
	memset(decoded_credentials, 0, decoded_len);
	free(decoded_credentials);

close_client:
	memset(buffer, 0, sizeof(buffer));
	dprintf(client_socket,
	        "HTTP/1.1 401 Unauthorized\r\nContent-Length: 0\r\nWWW-Authenticate: Basic realm=\"Please input password\"\r\n\r\n");

	if (close(client_socket) < 0) {
		log_debug("Failed to close client socket, ret: %d\n", errno);
	}
}

static void handleSigInt(int signo)
{
	if (signo == SIGINT) {
		printf("Caught SIGINT!\n");
	} else if (signo == SIGTERM) {
		printf("Caught SIGTERM!\n");
	} else if (signo == SIGPIPE) {
		printf("Caught SIGPIPE!\n");
		return;
	} else {
		printf("Unexpected signal: %d\n", signo);
	}

	g_run_flag = 0;
}

/**
 * @brief Display usage information
 * @details Prints the usage information for the command-line options.
 * @param[in] program_name Name of the executable program.
 * @return void.
 */
static void help(const char *program_name)
{
	printf("USAGE: %s [options] ...\n", program_name);
	printf("\n");
	printf("Options:\n");
	printf("  -l               Listen to %s to verify username and password.\n", AUTH_SOCKET_PATH);
	printf("  -h               Show this help message.\n");
	printf("\n");
	printf("Examples:\n");
	printf("  %s -l\n", program_name);
	printf("\n");
}

/**
 * @brief Main function
 * @details Entry point of the program, handles argument parsing, socket creation, and request handling.
 * @param[in] argc Number of command-line arguments.
 * @param[in] argv Array of command-line argument strings.
 * @arg
 * @see
 * @return Exit status.
 * @retval 0 Successful execution.
 * @retval Non-zero Error occurred.
 */
int main(int argc, char **argv)
{
	if (signal(SIGINT, handleSigInt) == SIG_ERR) {
		perror("Cannot handle SIGINT!\n");
		exit(1);
	}

	if (signal(SIGTERM, handleSigInt) == SIG_ERR) {
		perror("Cannot handle SIGTERM!\n");
		exit(1);
	}

	if (signal(SIGPIPE, handleSigInt) == SIG_ERR) {
		perror("Cannot handle SIGPIPE!\n");
		exit(1);
	}

	int server_socket = 0, client_socket = 0;
	int opt;
	struct sockaddr_un server_addr;

	/* Parse command-line arguments */
	while ((opt = getopt(argc, argv, "l")) != -1) {
		switch (opt) {
		case 'l':
			break;
		case 'h':
		default:
			help(argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	/* reset to default if default flag exist. */
	if (access(DAFAULT_PASSWORD_FLAG, F_OK) == 0) {
		resetToDefault();
	}

	/* Forward Compatibility: if no default flag but passwd not stored in Secure Storage, 
	 * it will reset to default username and passwd */
	if (checkUsageOfTEE() != 0) {
		touch(DAFAULT_PASSWORD_FLAG);
		resetToDefault();
	}

	/* Create a Unix socket */
	server_socket = socket(AF_UNIX, SOCK_STREAM, 0);
	if (server_socket < 0) {
		log_debug("Failed to create unix socket\n");
		goto exit_with_error;
	}

	/* Set up the socket address structure */
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strncpy(server_addr.sun_path, AUTH_SOCKET_PATH, sizeof(server_addr.sun_path) - 1);

	if (unlink(AUTH_SOCKET_PATH) < 0) {
		log_debug("Failed to unlink unix socket, errno: %d\n", errno);
	}

	/* Bind the socket */
	if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		log_debug("Failed to bind unix socket, errno: %d\n", errno);
		goto exit_with_error;
	}

	/* Listen for incoming connections */
	if (listen(server_socket, 5) < 0) {
		log_debug("Failed to listen unix socket, errno: %d\n", errno);
		goto exit_with_error;
	}

	log_debug("Listening on %s...\n", AUTH_SOCKET_PATH);

	struct stat initial_stat, final_stat;
	/* check init stat */
	if (stat(AUTH_SOCKET_PATH, &initial_stat) == -1) {
		log_debug("initial_stat failed");
		goto exit_with_error;
	}

	/* Set the permissions to 766 */
	if (chmod(AUTH_SOCKET_PATH, 0766) != 0) {
		log_debug("Failed to chmod '%s',  errno: %d\n", AUTH_SOCKET_PATH, errno);
		goto exit_with_error;
	}

	/* check final stat */
	if (stat(AUTH_SOCKET_PATH, &final_stat) == -1) {
		log_debug("final stat failed");
		goto exit_with_error;
	}

	/* Compare inode and owner to ensure the file has not been modified */
	if (initial_stat.st_ino != final_stat.st_ino || initial_stat.st_uid != final_stat.st_uid) {
		log_debug("File was modified during the operation.\n");
		goto exit_with_error;
	}

	/* Main loop to accept and handle requests */
	g_run_flag = 1;
	while (g_run_flag) {
		client_socket = accept(server_socket, NULL, NULL);
		if (client_socket < 0) {
			log_debug("failed to accept client, errno: %d\n", errno);
			continue;
		}

		handleAuthenticationOfHttp(client_socket);
	}

	if (close(server_socket) < 0) {
		log_debug("failed to close server socket, errno: %d\n", errno);
	}

	return 0;

exit_with_error:
	if (server_socket != 0 && close(server_socket) < 0) {
		log_debug("failed to close server socket, errno: %d\n", errno);
	}
	return -EXIT_FAILURE;
}
