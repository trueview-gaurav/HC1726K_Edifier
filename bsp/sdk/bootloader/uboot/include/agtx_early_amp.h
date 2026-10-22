#ifndef _AGTX_EARLY_AMP_H_
#define _AGTX_EARLY_AMP_H_

// Request types
enum { AMP_EARLY_STRING_CAPITAL, //damo example
       AMP_EARLY_FALSE_ALARM,

       AMP_EARLY_TYPE_NUM, //AMP_EARLY_TYPE_NUM always at the end
};

/**
 * amp_early_request() - Send a request to RTOS core
 *
 * This this API is only used in AMP product
 *
 * @request:	Request type
 * @data:	Pointer to data to be proccessed, if there is.
 */
void amp_early_request(int32_t request, void *data);

/**
 * amp_early_get_response() - Get the response of previous request
 *
 * This this API is only used in AMP product
 * The response value always over write by new one, only the response 
 * of the last request exist.
 *
 * @request:	Request type
 * @response:	Pointer to response variable
 *
 * @return 0 on success, nagtive value on fail when there is no response
 * of currect request type.
 */
int amp_early_get_response(int32_t request, int32_t *response);

/**
 * amp_early_get_shm() - Get a shared memory between Dual cores
 *
 * There is a 1KB shared memory reserved for Dual-core applications.
 * This function didn't provide any memory management machenism, instead,
 * it just return the address of same shared memory.
 *
 * @return: the pointer to 1KB shared memory.
 */
void *amp_early_get_shm(void);

/**
 * amp_false_alarm_detect() - Request a false alarm detection
 *
 * Sends a false alarm detection request to RTOS.
 *
 * @type: detection type: bit[0]: human, bit[1]: car
 * @threshold: the threshold of judgement.
 * @data: the information of YUV snapshot.
 *
 */
void amp_false_alarm_detect(uint32_t type, uint32_t threshold, void *data);
#endif
