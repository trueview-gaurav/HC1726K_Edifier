#ifndef __PSEUDO_USB_HOST_H__
#define __PSEUDO_USB_HOST_H__

int pseudo_usb_host_init(void);
void pseudo_usb_host_exit(void);

/**
 * pseudo_usb_host_active - Queue woker to add a pesudo usb host device
 *
 */
void pseudo_usb_host_active(void);

/**
 * pseudo_usb_host_suspend - Modify attribute into suspend state
 *
 */
void pseudo_usb_host_suspend(void);

#endif