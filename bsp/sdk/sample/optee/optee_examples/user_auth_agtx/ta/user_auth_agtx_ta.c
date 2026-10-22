/*
 * Copyright (c) 2017, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <user_auth_agtx_ta.h>
#include <string_ext.h>
#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>

static TEE_Result hash_password_to_hex(const void *password, size_t password_sz, char *out_hex, size_t out_hex_len)
{
	if (out_hex_len < 65) // 64 hex chars + '\0'
		return TEE_ERROR_SHORT_BUFFER;

	TEE_Result res;
	TEE_OperationHandle sha256_ctx = TEE_HANDLE_NULL;
	uint8_t hash_bin[32];
	uint32_t hash_len = sizeof(hash_bin);

	res = TEE_AllocateOperation(&sha256_ctx, TEE_ALG_SHA256, TEE_MODE_DIGEST, 0);
	if (res != TEE_SUCCESS)
		return res;

	TEE_DigestUpdate(sha256_ctx, password, password_sz);
	res = TEE_DigestDoFinal(sha256_ctx, NULL, 0, hash_bin, &hash_len);
	TEE_FreeOperation(sha256_ctx);
	if (res != TEE_SUCCESS)
		return res;

	for (size_t i = 0; i < 32; i++)
		snprintf(&out_hex[i * 2], 3, "%02x", hash_bin[i]);

	out_hex[64] = '\0'; // null-terminate

	return TEE_SUCCESS;
}

static TEE_Result format_user_entry(const char *username, size_t username_sz, const void *password, size_t password_sz,
                                    char **out_entry, size_t *out_entry_len)
{
	char hash_hex[65];
	TEE_Result res = hash_password_to_hex(password, password_sz, hash_hex, sizeof(hash_hex));
	if (res != TEE_SUCCESS)
		return res;

	*out_entry_len = username_sz + 1 + 64 + 1; // "username:hash\n"
	*out_entry = TEE_Malloc(*out_entry_len, 0);
	if (!*out_entry)
		return TEE_ERROR_OUT_OF_MEMORY;

	snprintf(*out_entry, *out_entry_len + 1, "%s:%s\n", username, hash_hex);
	return TEE_SUCCESS;
}

static TEE_Result check_object(uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE,
	                                                 TEE_PARAM_TYPE_NONE, TEE_PARAM_TYPE_NONE);
	TEE_ObjectHandle object;
	TEE_Result res;
	char *obj_id;
	size_t obj_id_sz;

	/*
	 * Safely get the invocation parameters
	 */
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	obj_id_sz = params[0].memref.size;
	obj_id = TEE_Malloc(obj_id_sz, 0);
	if (!obj_id)
		return TEE_ERROR_OUT_OF_MEMORY;

	TEE_MemMove(obj_id, params[0].memref.buffer, obj_id_sz);

	/*
	 * Check object exists
	 */
	res = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE, obj_id, obj_id_sz,
	                               TEE_DATA_FLAG_ACCESS_READ |
	                                       TEE_DATA_FLAG_ACCESS_WRITE_META, /* we must be allowed to delete it */
	                               &object);

	if (res != TEE_SUCCESS) {
		EMSG("Failed to open persistent object, res=0x%08x", res);
		TEE_Free(obj_id);
		return res;
	}

	TEE_Free(obj_id);

	return res;
}

static TEE_Result reset_object(uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT,
	                                                 TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE);
	TEE_ObjectHandle object;
	TEE_Result res;
	char *obj_id = NULL;
	char *username = NULL;
	char *password = NULL;
	char *entry = NULL;
	size_t obj_id_sz;
	size_t username_sz;
	size_t password_sz;
	size_t entry_len;
	uint32_t obj_data_flag;

	/*
	 * Safely get the invocation parameters
	 */
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	obj_id_sz = params[0].memref.size;
	obj_id = TEE_Malloc(obj_id_sz, 0);
	if (!obj_id)
		return TEE_ERROR_OUT_OF_MEMORY;

	TEE_MemMove(obj_id, params[0].memref.buffer, obj_id_sz);

	username_sz = params[1].memref.size;
	username = TEE_Malloc(username_sz, 0);
	if (!username)
		return TEE_ERROR_OUT_OF_MEMORY;

	TEE_MemMove(username, params[1].memref.buffer, username_sz);

	password_sz = params[2].memref.size;
	password = TEE_Malloc(password_sz, 0);
	if (!password)
		return TEE_ERROR_OUT_OF_MEMORY;

	TEE_MemMove(password, params[2].memref.buffer, password_sz);

	/* 
	 * Format username;HASH256(password)
	 */
	res = format_user_entry(username, username_sz, password, password_sz, &entry, &entry_len);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/*
	 * Create object in secure storage and fill with data
	 */
	obj_data_flag = TEE_DATA_FLAG_ACCESS_READ | /* we can later read the oject */
	                TEE_DATA_FLAG_ACCESS_WRITE | /* we can later write into the object */
	                TEE_DATA_FLAG_ACCESS_WRITE_META | /* we can later destroy or rename the object */
	                TEE_DATA_FLAG_OVERWRITE; /* destroy existing object of same ID */

	/* 
	 * Create new object
	 */
	res = TEE_CreatePersistentObject(TEE_STORAGE_PRIVATE, obj_id, obj_id_sz, obj_data_flag, TEE_HANDLE_NULL, entry,
	                                 entry_len, &object);

	if (res != TEE_SUCCESS) {
		EMSG("TEE_CreatePersistentObject failed 0x%08x", res);
		goto cleanup;
	}

	if (res == TEE_SUCCESS && object != TEE_HANDLE_NULL)
		TEE_CloseObject(object);

cleanup:
	if (obj_id)
		TEE_Free(obj_id);
	if (username)
		TEE_Free(username);
	if (password)
		TEE_Free(password);
	if (entry)
		TEE_Free(entry);
	return res;
}

static TEE_Result add_user_object(uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT,
	                                                 TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE);
	TEE_ObjectHandle object;
	TEE_Result res;
	char *obj_id;
	char *username;
	char *password;
	char *entry;
	size_t obj_id_sz;
	size_t username_sz;
	size_t password_sz;
	size_t entry_len;
	uint32_t obj_data_flag;

	/*
	 * Safely get the invocation parameters
	 */
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	obj_id_sz = params[0].memref.size;
	obj_id = TEE_Malloc(obj_id_sz, 0);
	if (!obj_id)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(obj_id, params[0].memref.buffer, obj_id_sz);

	username_sz = params[1].memref.size;
	username = TEE_Malloc(username_sz, 0);
	if (!username)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(username, params[1].memref.buffer, username_sz);

	password_sz = params[2].memref.size;
	password = TEE_Malloc(password_sz, 0);
	if (!password)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(password, params[2].memref.buffer, password_sz);

	/*
	 * Generate username:SHA256(password)
	 */
	res = format_user_entry(username, username_sz, password, password_sz, &entry, &entry_len);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/*
	 * Try to open existing object
	 */
	res = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE, obj_id, obj_id_sz,
	                               TEE_DATA_FLAG_ACCESS_WRITE | TEE_DATA_FLAG_ACCESS_READ |
	                                       TEE_DATA_FLAG_SHARE_READ | TEE_DATA_FLAG_SHARE_WRITE,
	                               &object);

	if (res == TEE_ERROR_ITEM_NOT_FOUND) {
		/*
		 * Create new object
		 */
		obj_data_flag = TEE_DATA_FLAG_ACCESS_WRITE | TEE_DATA_FLAG_ACCESS_READ |
		                TEE_DATA_FLAG_ACCESS_WRITE_META;

		res = TEE_CreatePersistentObject(TEE_STORAGE_PRIVATE, obj_id, obj_id_sz, obj_data_flag, TEE_HANDLE_NULL,
		                                 entry, entry_len, &object);
	} else if (res == TEE_SUCCESS) {
		/*
		 * Check if username already exists in object
		 */
		TEE_ObjectInfo obj_info;
		char *read_buf = NULL;
		char *line = NULL;
		char *saveptr = NULL;
		bool matched = false;
		uint32_t bytes_read = 0;

		res = TEE_GetObjectInfo1(object, &obj_info);
		if (res != TEE_SUCCESS)
			goto cleanup_obj;

		read_buf = TEE_Malloc(obj_info.dataSize + 1, 0); // +1 for null terminator
		if (!read_buf) {
			res = TEE_ERROR_OUT_OF_MEMORY;
			goto cleanup_obj;
		}

		res = TEE_ReadObjectData(object, read_buf, obj_info.dataSize, &bytes_read);
		if (res != TEE_SUCCESS || bytes_read != obj_info.dataSize) {
			TEE_Free(read_buf);
			goto cleanup_obj;
		}

		read_buf[obj_info.dataSize] = '\0';

		/*
		 * Read and match line-by-line
		 */
		line = strtok_r(read_buf, "\n", &saveptr);
		while (line != NULL) {
			if (TEE_MemCompare(line, username, username_sz) == 0 && line[username_sz] == ':') {
				matched = true;
				break;
			}
			line = strtok_r(NULL, "\n", &saveptr);
		}

		TEE_Free(read_buf);

		if (matched) {
			EMSG("Username already exists");
			res = TEE_ERROR_ACCESS_CONFLICT;
			goto cleanup_obj;
		}

		/*
		 * Move to end of object and append new entry
		 */
		res = TEE_SeekObjectData(object, 0, TEE_DATA_SEEK_END);
		if (res != TEE_SUCCESS) {
			EMSG("Failed to seek end of object.");
			goto cleanup_obj;
		}

		res = TEE_WriteObjectData(object, entry, entry_len);
		if (res != TEE_SUCCESS) {
			EMSG("Failed to write entry to object: 0x%x", res);
			goto cleanup_obj;
		}
	}

cleanup_obj:
	if (object != TEE_HANDLE_NULL)
		TEE_CloseObject(object);

cleanup:
	if (obj_id)
		TEE_Free(obj_id);
	if (username)
		TEE_Free(username);
	if (password)
		TEE_Free(password);
	if (entry)
		TEE_Free(entry);

	return res;
}

static TEE_Result modify_user_object(uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT,
	                                                 TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT);
	TEE_ObjectHandle object;
	TEE_Result res;
	char *obj_id, *username, *password, *new_password;
	char *old_entry = NULL;
	char *new_entry = NULL;
	char *read_buf = NULL;
	char *write_buf = NULL;
	size_t obj_id_sz, username_sz, password_sz, new_password_sz;
	size_t old_entry_len = 0, new_entry_len = 0;
	uint32_t bytes_read = 0;
	bool matched = false;

	/*
	 * Safely get the invocation parameters
	 */
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	obj_id_sz = params[0].memref.size;
	obj_id = TEE_Malloc(obj_id_sz, 0);
	if (!obj_id)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(obj_id, params[0].memref.buffer, obj_id_sz);

	username_sz = params[1].memref.size;
	username = TEE_Malloc(username_sz, 0);
	if (!username)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(username, params[1].memref.buffer, username_sz);

	password_sz = params[2].memref.size;
	password = TEE_Malloc(password_sz, 0);
	if (!password)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(password, params[2].memref.buffer, password_sz);

	new_password_sz = params[3].memref.size;
	new_password = TEE_Malloc(new_password_sz, 0);
	if (!new_password)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(new_password, params[3].memref.buffer, new_password_sz);

	/*
	 * Format old entry for comparison
	 */
	res = format_user_entry(username, username_sz, password, password_sz, &old_entry, &old_entry_len);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/*
	 * Format new entry to replace
	 */
	res = format_user_entry(username, username_sz, new_password, new_password_sz, &new_entry, &new_entry_len);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/*
	 * Open object for reading and writing
	 */
	res = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE, obj_id, obj_id_sz,
	                               TEE_DATA_FLAG_ACCESS_READ | TEE_DATA_FLAG_ACCESS_WRITE, &object);
	if (res != TEE_SUCCESS)
		goto cleanup;

	TEE_ObjectInfo obj_info;
	res = TEE_GetObjectInfo1(object, &obj_info);
	if (res != TEE_SUCCESS)
		goto cleanup_obj;

	read_buf = TEE_Malloc(obj_info.dataSize + 1, 0); // +1 for null terminator
	if (!read_buf) {
		res = TEE_ERROR_OUT_OF_MEMORY;
		goto cleanup_obj;
	}

	res = TEE_ReadObjectData(object, read_buf, obj_info.dataSize, &bytes_read);
	if (res != TEE_SUCCESS || bytes_read != obj_info.dataSize)
		goto cleanup_obj;

	read_buf[obj_info.dataSize] = '\0';

	/*
	 * Line-by-line compare and build new content
	 */
	char *line = NULL;
	char *saveptr = NULL;
	size_t total_new_len = 0;

	write_buf = TEE_Malloc(obj_info.dataSize + 1, 0); // +1 for null terminator
	if (!write_buf) {
		res = TEE_ERROR_OUT_OF_MEMORY;
		goto cleanup_obj;
	}

	line = strtok_r(read_buf, "\n", &saveptr);
	while (line != NULL) {
		if (TEE_MemCompare(line, old_entry, old_entry_len - 1) == 0) {
			// replace
			matched = true;
			TEE_MemMove(write_buf + total_new_len, new_entry, new_entry_len);
			total_new_len += new_entry_len;
		} else {
			// copy
			size_t line_len = strlen(line);
			TEE_MemMove(write_buf + total_new_len, line, line_len);
			total_new_len += line_len;

			// append '\n'
			write_buf[total_new_len] = '\n';
			total_new_len += 1;
		}

		line = strtok_r(NULL, "\n", &saveptr);
	}

	if (!matched) {
		EMSG("No matching username and password found.");
		res = TEE_ERROR_ITEM_NOT_FOUND;
		goto cleanup_obj;
	}

	if (obj_info.dataSize != total_new_len) {
		EMSG("Incorrect total new len. %d %d.", obj_info.dataSize, total_new_len);
		res = TEE_ERROR_BAD_FORMAT;
		goto cleanup_obj;
	}

	/*
	 * Truncate and write back modified content
	 */
	res = TEE_TruncateObjectData(object, 0);
	if (res != TEE_SUCCESS) {
		EMSG("Failed to truncate object.");
		return res;
	}

	res = TEE_SeekObjectData(object, 0, TEE_DATA_SEEK_SET);
	if (res != TEE_SUCCESS) {
		EMSG("Failed to seek set.");
		goto cleanup_obj;
	}

	res = TEE_WriteObjectData(object, write_buf, total_new_len);
	if (res != TEE_SUCCESS) {
		EMSG("Failed to write entry to object: 0x%x", res);
		goto cleanup_obj;
	}

cleanup_obj:
	if (object != TEE_HANDLE_NULL)
		TEE_CloseObject(object);

cleanup:
	if (obj_id)
		TEE_Free(obj_id);
	if (username)
		TEE_Free(username);
	if (password)
		TEE_Free(password);
	if (new_password)
		TEE_Free(new_password);
	if (old_entry)
		TEE_Free(old_entry);
	if (new_entry)
		TEE_Free(new_entry);
	if (read_buf)
		TEE_Free(read_buf);
	if (write_buf)
		TEE_Free(write_buf);

	return res;
}

static TEE_Result verify_user_object(uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT,
	                                                 TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE);
	TEE_ObjectHandle object;
	TEE_Result res;
	char *obj_id;
	char *username;
	char *password;
	char *expected_entry;
	size_t obj_id_sz;
	size_t username_sz;
	size_t password_sz;
	size_t expected_entry_len;

	TEE_ObjectInfo obj_info;
	char *read_buf = NULL;
	size_t bytes_read;
	char *line;
	char *saveptr;
	bool matched = false;

	/*
	 * Safely get the invocation parameters
	 */
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	obj_id_sz = params[0].memref.size;
	obj_id = TEE_Malloc(obj_id_sz, 0);
	if (!obj_id)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(obj_id, params[0].memref.buffer, obj_id_sz);

	username_sz = params[1].memref.size;
	username = TEE_Malloc(username_sz, 0);
	if (!username)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(username, params[1].memref.buffer, username_sz);

	password_sz = params[2].memref.size;
	password = TEE_Malloc(password_sz, 0);
	if (!password)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(password, params[2].memref.buffer, password_sz);

	/* 
	 * Format entry: username:SHA256(password)
	 */
	res = format_user_entry(username, username_sz, password, password_sz, &expected_entry, &expected_entry_len);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/* 
	 * Open object
	 */
	res = TEE_OpenPersistentObject(TEE_STORAGE_PRIVATE, obj_id, obj_id_sz, TEE_DATA_FLAG_ACCESS_READ, &object);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/*
	 * Get object size
	 */
	res = TEE_GetObjectInfo1(object, &obj_info);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/* 
	 * Allocate read buffer
	 */
	read_buf = TEE_Malloc(obj_info.dataSize + 1, TEE_MALLOC_FILL_ZERO);
	if (!read_buf) {
		res = TEE_ERROR_OUT_OF_MEMORY;
		goto cleanup;
	}

	/* 
	 * Read and match line-by-line
	 */
	bytes_read = 0;
	res = TEE_ReadObjectData(object, read_buf, obj_info.dataSize, &bytes_read);
	if (res != TEE_SUCCESS || bytes_read != obj_info.dataSize)
		goto cleanup;

	read_buf[obj_info.dataSize] = '\0';

	line = strtok_r(read_buf, "\n", &saveptr);
	while (line != NULL) {
		if (TEE_MemCompare(line, expected_entry, expected_entry_len - 1) == 0) {
			matched = true;
			break;
		}

		line = strtok_r(NULL, "\n", &saveptr);
	}

	res = matched ? TEE_SUCCESS : TEE_ERROR_ACCESS_DENIED;

cleanup:
	if (obj_id)
		TEE_Free(obj_id);
	if (username)
		TEE_Free(username);
	if (password)
		TEE_Free(password);
	if (expected_entry)
		TEE_Free(expected_entry);
	if (read_buf)
		TEE_Free(read_buf);
	if (object != TEE_HANDLE_NULL)
		TEE_CloseObject(object);
	return res;
}

static TEE_Result delete_user_object(uint32_t param_types, TEE_Param params[4])
{
	const uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_MEMREF_INPUT,
	                                                 TEE_PARAM_TYPE_MEMREF_INPUT, TEE_PARAM_TYPE_NONE);
	TEE_ObjectHandle object = TEE_HANDLE_NULL;
	TEE_ObjectHandle new_object = TEE_HANDLE_NULL;
	TEE_Result res;
	char *obj_id = NULL;
	char *username = NULL;
	char *password = NULL;
	char *expected_entry = NULL;
	char *read_buf = NULL;
	char *line = NULL;
	char *saveptr = NULL;
	char *new_data = NULL;
	size_t obj_id_sz, username_sz, password_sz, expected_entry_len;
	size_t bytes_read;
	TEE_ObjectInfo obj_info;
	bool found = false;

	/*
	 * Safely get the invocation parameters
	 */
	if (param_types != exp_param_types)
		return TEE_ERROR_BAD_PARAMETERS;

	/*
	 * Copy object ID
	 */
	obj_id_sz = params[0].memref.size;
	obj_id = TEE_Malloc(obj_id_sz, 0);
	if (!obj_id)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(obj_id, params[0].memref.buffer, obj_id_sz);

	/*
	 * Copy username
	 */
	username_sz = params[1].memref.size;
	username = TEE_Malloc(username_sz, 0);
	if (!username)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(username, params[1].memref.buffer, username_sz);

	/*
	 * Copy password
	 */
	password_sz = params[2].memref.size;
	password = TEE_Malloc(password_sz, 0);
	if (!password)
		return TEE_ERROR_OUT_OF_MEMORY;
	TEE_MemMove(password, params[2].memref.buffer, password_sz);

	/*
	 * Format expected entry: username:SHA256(password)
	 */
	res = format_user_entry(username, username_sz, password, password_sz, &expected_entry, &expected_entry_len);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/*
	 * Open persistent object for reading
	 */
	res = TEE_OpenPersistentObject(
	        TEE_STORAGE_PRIVATE, obj_id, obj_id_sz,
	        TEE_DATA_FLAG_ACCESS_READ | TEE_DATA_FLAG_ACCESS_WRITE | TEE_DATA_FLAG_ACCESS_WRITE_META, &object);
	if (res != TEE_SUCCESS)
		goto cleanup;

	/*
	 * Read object content into buffer
	 */
	res = TEE_GetObjectInfo1(object, &obj_info);
	if (res != TEE_SUCCESS)
		goto cleanup;

	read_buf = TEE_Malloc(obj_info.dataSize + 1, TEE_MALLOC_FILL_ZERO);
	if (!read_buf) {
		res = TEE_ERROR_OUT_OF_MEMORY;
		goto cleanup;
	}

	res = TEE_ReadObjectData(object, read_buf, obj_info.dataSize, &bytes_read);
	if (res != TEE_SUCCESS || bytes_read != obj_info.dataSize)
		goto cleanup;

	read_buf[obj_info.dataSize] = '\0';

	/*
	 * Remove the matching line from the object content
	 */
	size_t total_new_len = 0;

	new_data = TEE_Malloc(obj_info.dataSize + 1, TEE_MALLOC_FILL_ZERO); // +1 for null terminator
	if (!new_data) {
		res = TEE_ERROR_OUT_OF_MEMORY;
		goto cleanup;
	}

	line = strtok_r(read_buf, "\n", &saveptr);
	while (line != NULL) {
		if (!found && TEE_MemCompare(line, expected_entry, expected_entry_len - 1) == 0) {
			found = true;
		} else {
			// copy
			size_t line_len = strlen(line);
			TEE_MemMove(new_data + total_new_len, line, line_len);
			total_new_len += line_len;

			// append '\n'
			new_data[total_new_len] = '\n';
			total_new_len += 1;
		}

		line = strtok_r(NULL, "\n", &saveptr);
	}

	if (!found) {
		res = TEE_ERROR_ACCESS_DENIED;
		goto cleanup;
	}

	/*
	 * Truncate and write back modified content
	 */
	res = TEE_TruncateObjectData(object, 0);
	if (res != TEE_SUCCESS) {
		EMSG("Failed to truncate object.");
		return res;
	}

	res = TEE_SeekObjectData(object, 0, TEE_DATA_SEEK_SET);
	if (res != TEE_SUCCESS) {
		EMSG("Failed to seek set.");
		goto cleanup;
	}

	res = TEE_WriteObjectData(object, new_data, total_new_len);
	if (res != TEE_SUCCESS) {
		EMSG("Failed to write entry to object: 0x%x", res);
		goto cleanup;
	}

cleanup:
	if (obj_id)
		TEE_Free(obj_id);
	if (username)
		TEE_Free(username);
	if (password)
		TEE_Free(password);
	if (expected_entry)
		TEE_Free(expected_entry);
	if (read_buf)
		TEE_Free(read_buf);
	if (new_data)
		TEE_Free(new_data);
	if (object != TEE_HANDLE_NULL)
		TEE_CloseObject(object);
	if (new_object != TEE_HANDLE_NULL)
		TEE_CloseObject(new_object);

	return res;
}

TEE_Result TA_CreateEntryPoint(void)
{
	/* Nothing to do */
	return TEE_SUCCESS;
}

void TA_DestroyEntryPoint(void)
{
	/* Nothing to do */
}

TEE_Result TA_OpenSessionEntryPoint(uint32_t __unused param_types, TEE_Param __unused params[4],
                                    void __unused **session)
{
	/* Nothing to do */
	return TEE_SUCCESS;
}

void TA_CloseSessionEntryPoint(void __unused *session)
{
	/* Nothing to do */
}

TEE_Result TA_InvokeCommandEntryPoint(void __unused *session, uint32_t command, uint32_t param_types,
                                      TEE_Param params[4])
{
	switch (command) {
	case TA_USER_AUTH_AGTX_CMD_CHECK:
		return check_object(param_types, params);
	case TA_USER_AUTH_AGTX_CMD_RESET:
		return reset_object(param_types, params);
	case TA_USER_AUTH_AGTX_CMD_ADD_USER:
		return add_user_object(param_types, params);
	case TA_USER_AUTH_AGTX_CMD_MODIFY_USER:
		return modify_user_object(param_types, params);
	case TA_USER_AUTH_AGTX_CMD_VERIFY_USER:
		return verify_user_object(param_types, params);
	case TA_USER_AUTH_AGTX_CMD_DELETE_USER:
		return delete_user_object(param_types, params);
	default:
		EMSG("Command ID 0x%x is not supported", command);
		return TEE_ERROR_NOT_SUPPORTED;
	}
}
