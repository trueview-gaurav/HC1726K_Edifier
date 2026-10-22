#ifndef AMPI_H_
#define AMPI_H_

#include <stdint.h>
#include <stdio.h>

#if defined __cplusplus
extern "C" {
#endif

#define AMPI_SUCCESS (0) /**< Definition of success in MPI. */
#define AMPI_FAILURE (-1) /**< Definition of failure in MPI. */
#define AMPI_UNUSED(x) (void)(x) /**< Definition of unused in MPI. */

//core-to-core connection handle
typedef int ampi_dev;

//service link handle
typedef int ampi_svc;

typedef enum { SVC_REQUEST, SVC_CLEAN } svc_event_t;

//service handler
typedef void (*svc_handler)(ampi_svc, void *, int, svc_event_t);

/**
 * ampi_init - initialize the ampi
 *
 * It will initialize the ampi.
 *
 * @ampi_id: indicate ampc communication, only useful while there are
 * multiple core-to-core channels. ex: CPU0<->CPU1, CPU0<->CPU1
 *
 * return ampi_dev for success or AMPI_FAILURE for failure
 */
ampi_dev ampi_init(int ampi_id);

/**
 * ampi_deinit - de-initialize the ampi
 *
 * It will de-initialize the ampi.
 *
 * @dev: the core-to-core channal to be closed.
 *
 */
void ampi_deinit(ampi_dev dev);

/**
 * ampi_link_service - link to specific service
 *
 * It will create a link ot specific service
 *
 * @dev: define which amp channel
 * @svc_name: service name
 * @timeout: timeout period (ms)
 *
 * return ampi_svc for success or AMPI_FAILURE for failure
 */
ampi_svc ampi_link_service(ampi_dev dev, char *svc_name, int timeout);

/**
 * ampi_unlink_service - unlink service
 *
 * It will close the service link
 *
 * @service: which service link to be closed
 *
 */
void ampi_unlink_service(ampi_svc service);

/**
 * ampi_get_private - get private data
 *
 * It will return per service link private data
 *
 * @service: which service link
 *
 */
void *ampi_get_private(ampi_svc service);

/**
 * ampi_set_private - set private data
 *
 * To set per service link private data
 *
 * @service: which service link
 *
 */
void ampi_set_private(ampi_svc service, void *priv);

/**
 * ampi_create_service - create service
 *
 * It will create service to be linked by client.
 *
 * @dev: define which amp channel
 * @svc_name: service name
 * @handler: the handler to process client requests
 *
 * return 0 for success or AMPI_FAILURE for failure
 */
int ampi_create_service(ampi_dev dev, char *svc_name, svc_handler handler);

/**
 * ampi_service_start - 
 *
 * It will start all the services created before this call.
 * This function never returned.
 *
 * @dev[]: the array of core-to-core channel
 * @dev_num: the number of dev[]
 *
 */
void ampi_server_start(ampi_dev dev[], int dev_num);

/**
 * ampi_send - send message
 *
 * It will send message to designated service
 *
 * @svc: which service link
 * @data: message data to be sent
 * @len: how many bytes of message, the max length is 496 bytes
 * @timeout: timeout period (ms)
 *
 * return 0 for success or AMPI_FAILURE for failure
 */
int ampi_send(ampi_svc svc, void *data, size_t len, int timeout);

/**
 * ampi_receive - receive message
 *
 * It will wait and receive message from specific link
 * This is a blocking call, when the message is absent.
 *
 * @svc: which service link
 * @data: buffer to receive message
 * @len: size of data buffer
 * @timeout: timeout period (ms)
 *
 * return positive value for message length or AMPI_FAILURE for failure
 */
int ampi_receive(ampi_svc svc, void *data, size_t len, int timeout);

/**
 * ampi_virt_to_phys - virtual address to physical address
 *
 * It will convert virtual address into physical address. 
 *
 * @virt_addr: virtual address
 *
 * return physical address or 0 for fail
 */
uint32_t ampi_virt_to_phys(ampi_dev dev, void *virt_addr);

/**
 * ampi_malloc - amp malloc
 *
 * It will allocate memory block which could shared by dual core.
 * The allocated memory will be contiguous.
 *
 * @size: bytes of requested memory block
 *
 * return virtual address of memory block or 0 for failure
 */
void *ampi_malloc(ampi_dev dev, size_t size);

/**
 * ampi_free - amp free
 *
 * It will release the memory allocated from ampi_malloc
 *
 * @virt_addr: virtual address of memory
 */
void ampi_free(ampi_dev dev, void *virt_addr);

#if defined __cplusplus
}
#endif

#endif /* AMPI_H_ */
