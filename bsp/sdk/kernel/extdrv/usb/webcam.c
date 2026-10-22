/*
 *	webcam.c -- USB webcam gadget driver
 *
 *	Copyright (C) 2009-2010
 *	    Laurent Pinchart (laurent.pinchart@ideasonboard.com)
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 */

#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/usb/video.h>
#include <linux/usb/webcam.h>
#include <linux/usb/composite.h>

#include "u_uvc.h"

#define DRV_NAME "agtx-webcam"

USB_GADGET_COMPOSITE_OPTIONS();

/*-------------------------------------------------------------------------*/
/* device driver */
static struct cdev g_agtx_webcam_cdev;
static dev_t g_agtx_webcam_dev;
static struct class *g_agtx_webcam_class = NULL;
static struct agtx_webcam_cap g_webcam_caps;
static int g_is_bind = 0;

/* module parameters specific to the Video streaming endpoint */
static unsigned int streaming_interval = 1;
module_param(streaming_interval, uint, S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(streaming_interval, "1 - 16");

static unsigned int streaming_maxpacket = 1024;
module_param(streaming_maxpacket, uint, S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(streaming_maxpacket, "1 - 1023 (FS), 1 - 3072 (hs/ss)");

static unsigned int streaming_maxburst;
module_param(streaming_maxburst, uint, S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(streaming_maxburst, "0 - 15 (ss only)");

static unsigned int trace;
module_param(trace, uint, S_IRUGO|S_IWUSR);
MODULE_PARM_DESC(trace, "Trace level bitmask");
/* --------------------------------------------------------------------------
 * Device descriptor
 */

#define WEBCAM_VENDOR_ID		0x1d6b	/* Linux Foundation */
#define WEBCAM_PRODUCT_ID		0x0102	/* Webcam A/V gadget */
#define WEBCAM_DEVICE_BCD		0x0010	/* 0.10 */

static char webcam_vendor_label[] = "Augentix";
static char webcam_product_label[] = "Webcam";
static char webcam_config_label[] = "Video";

/* string IDs are assigned dynamically */

#define STRING_DESCRIPTION_IDX		USB_GADGET_FIRST_AVAIL_IDX

static struct usb_string webcam_strings[] = {
	[USB_GADGET_MANUFACTURER_IDX].s = webcam_vendor_label,
	[USB_GADGET_PRODUCT_IDX].s = webcam_product_label,
	[USB_GADGET_SERIAL_IDX].s = "",
	[STRING_DESCRIPTION_IDX].s = webcam_config_label,
	{  }
};

static struct usb_gadget_strings webcam_stringtab = {
	.language = 0x0409,	/* en-us */
	.strings = webcam_strings,
};

static struct usb_gadget_strings *webcam_device_strings[] = {
	&webcam_stringtab,
	NULL,
};

static struct usb_function_instance *fi_uvc;
static struct usb_function *f_uvc;

static struct usb_device_descriptor webcam_device_descriptor = {
	.bLength		= USB_DT_DEVICE_SIZE,
	.bDescriptorType	= USB_DT_DEVICE,
	.bcdUSB			= cpu_to_le16(0x0200),
	.bDeviceClass		= USB_CLASS_MISC,
	.bDeviceSubClass	= 0x02,
	.bDeviceProtocol	= 0x01,
	.bMaxPacketSize0	= 0, /* dynamic */
	.idVendor		= cpu_to_le16(WEBCAM_VENDOR_ID),
	.idProduct		= cpu_to_le16(WEBCAM_PRODUCT_ID),
	.bcdDevice		= cpu_to_le16(WEBCAM_DEVICE_BCD),
	.iManufacturer		= 0, /* dynamic */
	.iProduct		= 0, /* dynamic */
	.iSerialNumber		= 0, /* dynamic */
	.bNumConfigurations	= 0, /* dynamic */
};

DECLARE_UVC_HEADER_DESCRIPTOR(1);

static const struct UVC_HEADER_DESCRIPTOR(1) uvc_control_header = {
	.bLength = UVC_DT_HEADER_SIZE(1),
	.bDescriptorType = USB_DT_CS_INTERFACE,
	.bDescriptorSubType = UVC_VC_HEADER,
	.bcdUVC = cpu_to_le16(0x0110),
	.wTotalLength = 0, /* dynamic */
	.dwClockFrequency = cpu_to_le32(48000000),
	.bInCollection = 0, /* dynamic */
	.baInterfaceNr[0] = 0, /* dynamic */
};

static const struct uvc_camera_terminal_descriptor uvc_camera_terminal = {
	.bLength		= UVC_DT_CAMERA_TERMINAL_SIZE(2),
	.bDescriptorType	= USB_DT_CS_INTERFACE,
	.bDescriptorSubType	= UVC_VC_INPUT_TERMINAL,
	.bTerminalID		= 1,
	.wTerminalType		= cpu_to_le16(0x0201),
	.bAssocTerminal		= 0,
	.iTerminal		= 0,
	.wObjectiveFocalLengthMin	= cpu_to_le16(0),
	.wObjectiveFocalLengthMax	= cpu_to_le16(0),
	.wOcularFocalLength		= cpu_to_le16(0),
	.bControlSize		= 2,
    .bmControls[0]      = 0,
    .bmControls[1]      = 0,
};

static const struct uvc_processing_unit_descriptor uvc_processing = {
	.bLength = UVC_DT_PROCESSING_UNIT_SIZE(2),
	.bDescriptorType = USB_DT_CS_INTERFACE,
	.bDescriptorSubType = UVC_VC_PROCESSING_UNIT,
	.bUnitID = 2,
	.bSourceID = 1,
	.wMaxMultiplier = cpu_to_le16(16 * 1024),
	.bControlSize = 2,
	.bmControls[0] = 0x5F,
	.bmControls[1] = 0x15,
	.iProcessing = 0,
	.bmVideoStandards = 0,
};

static const struct uvc_output_terminal_descriptor uvc_output_terminal = {
	.bLength		= UVC_DT_OUTPUT_TERMINAL_SIZE,
	.bDescriptorType	= USB_DT_CS_INTERFACE,
	.bDescriptorSubType	= UVC_VC_OUTPUT_TERMINAL,
	.bTerminalID		= 3,
	.wTerminalType		= cpu_to_le16(0x0101),
	.bAssocTerminal		= 0,
	.bSourceID		= 2,
	.iTerminal		= 0,
};

DECLARE_UVC_INPUT_HEADER_DESCRIPTOR(1, 2);

static struct UVC_INPUT_HEADER_DESCRIPTOR(1, 2) uvc_input_header = {
	.bLength		= UVC_DT_INPUT_HEADER_SIZE(1, 2),
	.bDescriptorType	= USB_DT_CS_INTERFACE,
	.bDescriptorSubType	= UVC_VS_INPUT_HEADER,
	.bNumFormats		= 2,
	.wTotalLength		= 0, /* dynamic */
	.bEndpointAddress	= 0, /* dynamic */
	.bmInfo			= 0,
	.bTerminalLink		= 3,
	.bStillCaptureMethod	= 0,
	.bTriggerSupport	= 0,
	.bTriggerUsage		= 0,
	.bControlSize		= 1,
	.bmaControls[0][0]	= 0,
};

static struct uvc_format_h264 uvc_format_h264 = {
	.bLength		= UVC_DT_FORMAT_H264_SIZE,
	.bDescriptorType	= USB_DT_CS_INTERFACE,
	.bDescriptorSubType	= UVC_VS_FORMAT_FRAME_BASED,
	.bFormatIndex		= 1,
	.bNumFrameDescriptors	= 1,
	.guidFormat		=
		{ 'H',  '2',  '6',  '4', 0x00, 0x00, 0x10, 0x00,
		 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71},
	.bBitsPerPixel		= 16,
	.bDefaultFrameIndex	= 1,
	.bAspectRatioX		= 0,
	.bAspectRatioY		= 0,
	.bmInterfaceFlags	= 0,
	.bCopyProtect		= 0,
	.bVariableSize		= 1,
};

static struct uvc_format_mjpeg uvc_format_mjpeg = {
	.bLength                = UVC_DT_FORMAT_MJPEG_SIZE,
	.bDescriptorType        = USB_DT_CS_INTERFACE,
	.bDescriptorSubType     = UVC_VS_FORMAT_MJPEG,
	.bFormatIndex           = 2,
	.bNumFrameDescriptors   = 1,
	.bmFlags                = 0,
	.bDefaultFrameIndex     = 1,
	.bAspectRatioX          = 0,
	.bAspectRatioY          = 0,
	.bmInterfaceFlags       = 0,
	.bCopyProtect           = 0,
};

DECLARE_UVC_FRAME_MJPEG(60);
DECLARE_UVC_FRAME_H264(60);

#if 0
DECLARE_UVC_FRAME_H264(1);

static const struct UVC_FRAME_H264(1) uvc_frame_h264_1080p = {
	.bLength		= UVC_DT_FRAME_H264_SIZE(1),
	.bDescriptorType	= USB_DT_CS_INTERFACE,
	.bDescriptorSubType	= UVC_VS_FRAME_FRAME_BASED,
	.bFrameIndex		= 1,
	.bmCapabilities		= 0,
	.wWidth			= cpu_to_le16(1920),
	.wHeight		= cpu_to_le16(1080),
	.dwMinBitRate		= cpu_to_le32(165888000),
	.dwMaxBitRate		= cpu_to_le32(995328000),
	.dwDefaultFrameInterval	= cpu_to_le32(333333),
	.bFrameIntervalType	= 1,
	.dwBytesPerLine = 0,
	.dwFrameInterval[0]     = cpu_to_le32(333333),
};

DECLARE_UVC_FRAME_MJPEG(1);

static const struct UVC_FRAME_MJPEG(1) uvc_frame_mjpeg_1080p = {
    .bLength                = UVC_DT_FRAME_MJPEG_SIZE(1),
    .bDescriptorType        = USB_DT_CS_INTERFACE,
    .bDescriptorSubType     = UVC_VS_FRAME_MJPEG,
    .bFrameIndex            = 1,
    .bmCapabilities         = 0,
    .wWidth                 = cpu_to_le16(1920),
    .wHeight                = cpu_to_le16(1080),
    .dwMinBitRate           = cpu_to_le32(1920*1080*32),
    .dwMaxBitRate           = cpu_to_le32(1920*1080*32),
    .dwMaxVideoFrameBufferSize = cpu_to_le32(1920*1080*2),
    .dwDefaultFrameInterval = cpu_to_le32(333333),
    .bFrameIntervalType     = 1,
    .dwFrameInterval[0]     = cpu_to_le32(333333),
};

static const struct uvc_descriptor_header * const uvc_default_streaming_cls[] = {
	(const struct uvc_descriptor_header *) &uvc_input_header,
	(const struct uvc_descriptor_header *) &uvc_format_h264,
	(const struct uvc_descriptor_header *) &uvc_frame_h264_1080p,
	(const struct uvc_descriptor_header *) &uvc_color_matching,
	(const struct uvc_descriptor_header *) &uvc_format_mjpeg,
	(const struct uvc_descriptor_header *) &uvc_frame_mjpeg_1080p,
	(const struct uvc_descriptor_header *) &uvc_color_matching,
	NULL,
};
#endif

static const struct uvc_color_matching_descriptor uvc_color_matching = {
	.bLength		= UVC_DT_COLOR_MATCHING_SIZE,
	.bDescriptorType	= USB_DT_CS_INTERFACE,
	.bDescriptorSubType	= UVC_VS_COLORFORMAT,
	.bColorPrimaries	= 1,
	.bTransferCharacteristics	= 1,
	.bMatrixCoefficients	= 1,
};

static const struct uvc_descriptor_header * const uvc_fs_control_cls[] = {
	(const struct uvc_descriptor_header *) &uvc_control_header,
	(const struct uvc_descriptor_header *) &uvc_camera_terminal,
	(const struct uvc_descriptor_header *) &uvc_processing,
	(const struct uvc_descriptor_header *) &uvc_output_terminal,
	NULL,
};

static const struct uvc_descriptor_header * const uvc_ss_control_cls[] = {
	(const struct uvc_descriptor_header *) &uvc_control_header,
	(const struct uvc_descriptor_header *) &uvc_camera_terminal,
	(const struct uvc_descriptor_header *) &uvc_processing,
	(const struct uvc_descriptor_header *) &uvc_output_terminal,
	NULL,
};

static struct uvc_descriptor_header **uvc_streaming_cls;

/* --------------------------------------------------------------------------
 * USB configuration
 */

static void
webcam_complete_streaming_cls(void)
{
	int i, j, k;
	int num_desc = 0;
	int cur_desc = 0;
	struct agtx_webcam_cap_format *format;
	struct agtx_webcam_cap_frame *frame;

	/* Calculate the number of descriptors */
	for (i = 0; i < g_webcam_caps.bNumFormats; i++) {
		format = &g_webcam_caps.formats[i];
		num_desc += format->bNumFrameDescriptors + 2;
	}
	num_desc += 2;

	/* Allocate memory for uvc_streaming_cls */
	uvc_streaming_cls = kzalloc(sizeof(struct uvc_descriptor_header **)
			* num_desc, GFP_KERNEL);

	/* Generate the content of uvc_streaming_cls */
	uvc_input_header.bLength = UVC_DT_INPUT_HEADER_SIZE(1, g_webcam_caps.bNumFormats),
	uvc_input_header.bNumFormats = g_webcam_caps.bNumFormats;
	uvc_streaming_cls[cur_desc++] = (struct uvc_descriptor_header *) &uvc_input_header;

	for (i = 0; i < g_webcam_caps.bNumFormats; i++) {
		format = &g_webcam_caps.formats[i];
		switch (format->codec) {
			case AGTX_VENC_TYPE_MJPEG:
				uvc_format_mjpeg.bFormatIndex = i + 1;
				uvc_format_mjpeg.bNumFrameDescriptors = format->bNumFrameDescriptors;
				uvc_streaming_cls[cur_desc++] = (struct uvc_descriptor_header *) &uvc_format_mjpeg;
				for (j = 0; j < format->bNumFrameDescriptors; j++) {
					struct UVC_FRAME_MJPEG(60) *uvc_frame_mjpeg;
					__u32 buffer_size;

					frame = &format->frames[j];
					buffer_size = frame->wWidth * frame->wHeight * 2;

					uvc_frame_mjpeg = kzalloc(sizeof(struct UVC_FRAME_MJPEG(60)), GFP_KERNEL);

					uvc_frame_mjpeg->bLength = UVC_DT_FRAME_MJPEG_SIZE(frame->bFrameIntervalType);
					uvc_frame_mjpeg->bDescriptorType = USB_DT_CS_INTERFACE;
					uvc_frame_mjpeg->bDescriptorSubType = UVC_VS_FRAME_MJPEG;
					uvc_frame_mjpeg->bFrameIndex = j + 1;
					uvc_frame_mjpeg->bmCapabilities = 0;
					uvc_frame_mjpeg->wWidth = cpu_to_le16(frame->wWidth);
					uvc_frame_mjpeg->wHeight = cpu_to_le16(frame->wHeight);
					uvc_frame_mjpeg->dwMinBitRate = cpu_to_le32(format->dwMinBitRate);
					uvc_frame_mjpeg->dwMaxBitRate = cpu_to_le32(format->dwMaxBitRate);
					uvc_frame_mjpeg->dwMaxVideoFrameBufferSize = cpu_to_le32(buffer_size);
					uvc_frame_mjpeg->dwDefaultFrameInterval = cpu_to_le32(frame->intervals[0]);
					uvc_frame_mjpeg->bFrameIntervalType = frame->bFrameIntervalType;
					for (k = 0; k < frame->bFrameIntervalType; k++) {
						uvc_frame_mjpeg->dwFrameInterval[k] = cpu_to_le32(frame->intervals[k]);
					}
					uvc_streaming_cls[cur_desc++] = (struct uvc_descriptor_header *) uvc_frame_mjpeg;
				}
				uvc_streaming_cls[cur_desc++] = (struct uvc_descriptor_header *) &uvc_color_matching;
				break;
			case AGTX_VENC_TYPE_H264:
				uvc_format_h264.bFormatIndex = i + 1;
				uvc_format_h264.bNumFrameDescriptors = format->bNumFrameDescriptors;
				uvc_streaming_cls[cur_desc++] = (struct uvc_descriptor_header *) &uvc_format_h264;
				for (j = 0; j < format->bNumFrameDescriptors; j++) {
					struct UVC_FRAME_H264(60) *uvc_frame_h264;

					frame = &format->frames[j];

					uvc_frame_h264 = kzalloc(sizeof(struct UVC_FRAME_H264(60)), GFP_KERNEL);

					uvc_frame_h264->bLength = UVC_DT_FRAME_H264_SIZE(frame->bFrameIntervalType);
					uvc_frame_h264->bDescriptorType = USB_DT_CS_INTERFACE;
					uvc_frame_h264->bDescriptorSubType = UVC_VS_FRAME_FRAME_BASED;
					uvc_frame_h264->bFrameIndex = j + 1;
					uvc_frame_h264->bmCapabilities = 0;
					uvc_frame_h264->wWidth = cpu_to_le16(frame->wWidth);
					uvc_frame_h264->wHeight = cpu_to_le16(frame->wHeight);
					uvc_frame_h264->dwMinBitRate = cpu_to_le32(format->dwMinBitRate);
					uvc_frame_h264->dwMaxBitRate = cpu_to_le32(format->dwMaxBitRate);
					uvc_frame_h264->dwDefaultFrameInterval = cpu_to_le32(frame->intervals[0]);
					uvc_frame_h264->bFrameIntervalType = frame->bFrameIntervalType;
					uvc_frame_h264->dwBytesPerLine = 0;
					for (k = 0; k < frame->bFrameIntervalType; k++) {
						uvc_frame_h264->dwFrameInterval[k] = cpu_to_le32(frame->intervals[k]);
					}
					uvc_streaming_cls[cur_desc++] = (struct uvc_descriptor_header *) uvc_frame_h264;
				}
				uvc_streaming_cls[cur_desc++] = (struct uvc_descriptor_header *) &uvc_color_matching;
				break;
			default:
				BUG_ON(1);
				break;
		}
	}
	uvc_streaming_cls[cur_desc++] = NULL;
	BUG_ON(cur_desc != num_desc);
}

static int webcam_config_bind(struct usb_configuration *c)
{
	int status = 0;

	f_uvc = usb_get_function(fi_uvc);
	if (IS_ERR(f_uvc))
		return PTR_ERR(f_uvc);

	status = usb_add_function(c, f_uvc);
	if (status < 0)
		usb_put_function(f_uvc);

	return status;
}

static struct usb_configuration webcam_config_driver = {
	.label			= webcam_config_label,
	.bConfigurationValue	= 1,
	.iConfiguration		= 0, /* dynamic */
	.bmAttributes		= USB_CONFIG_ATT_SELFPOWER,
	.MaxPower		= CONFIG_USB_GADGET_VBUS_DRAW,
};

static int /* __init_or_exit */
webcam_unbind(struct usb_composite_dev *cdev)
{
	int i, j;
	int cur_desc = 1;
	struct agtx_webcam_cap_format *format;

	if (!IS_ERR_OR_NULL(f_uvc))
		usb_put_function(f_uvc);
	if (!IS_ERR_OR_NULL(fi_uvc))
		usb_put_function_instance(fi_uvc);

	if (uvc_streaming_cls) {
		for (i = 0; i < g_webcam_caps.bNumFormats; i++) {
			format = &g_webcam_caps.formats[i];
			cur_desc++; /* skip free format */
			for (j = 0; j < format->bNumFrameDescriptors; j++) {
				kfree(uvc_streaming_cls[cur_desc++]);
			}
			cur_desc++; /* skip color matching */
		}
		kfree(uvc_streaming_cls);
	}

	return 0;
}

static int webcam_bind(struct usb_composite_dev *cdev)
{
	struct f_uvc_opts *uvc_opts;
	int ret;

	fi_uvc = usb_get_function_instance("uvc");
	if (IS_ERR(fi_uvc))
		return PTR_ERR(fi_uvc);

	uvc_opts = container_of(fi_uvc, struct f_uvc_opts, func_inst);

	uvc_opts->streaming_interval = streaming_interval;
	uvc_opts->streaming_maxpacket = 512;//streaming_maxpacket;
	uvc_opts->streaming_maxburst = streaming_maxburst;
	uvc_set_trace_param(trace);

	uvc_opts->fs_control = uvc_fs_control_cls;
	uvc_opts->ss_control = uvc_ss_control_cls;

	webcam_complete_streaming_cls();
	uvc_opts->fs_streaming = (const struct uvc_descriptor_header **) uvc_streaming_cls;
	uvc_opts->hs_streaming = (const struct uvc_descriptor_header **) uvc_streaming_cls;
	uvc_opts->ss_streaming = (const struct uvc_descriptor_header **) uvc_streaming_cls;

	/* Allocate string descriptor numbers ... note that string contents
	 * can be overridden by the composite_dev glue.
	 */
	ret = usb_string_ids_tab(cdev, webcam_strings);
	if (ret < 0)
		goto error;
	webcam_device_descriptor.iManufacturer =
		webcam_strings[USB_GADGET_MANUFACTURER_IDX].id;
	webcam_device_descriptor.iProduct =
		webcam_strings[USB_GADGET_PRODUCT_IDX].id;
	webcam_config_driver.iConfiguration =
		webcam_strings[STRING_DESCRIPTION_IDX].id;

	/* Register our configuration. */
	if ((ret = usb_add_config(cdev, &webcam_config_driver,
					webcam_config_bind)) < 0)
		goto error;

	usb_composite_overwrite_options(cdev, &coverwrite);
	INFO(cdev, "Webcam Video Gadget\n");
	return 0;

error:
	usb_put_function_instance(fi_uvc);
	return ret;
}

/*
 * USB composite driver
 */

static struct usb_composite_driver webcam_driver = {
	.name		= "g_webcam",
	.dev		= &webcam_device_descriptor,
	.strings	= webcam_device_strings,
	.max_speed	= USB_SPEED_SUPER,
	.bind		= webcam_bind,
	.unbind		= webcam_unbind,
};

/*
 * Platform device driver
 */
static int agtx_webcam_set_cap(const void __user *data)
{
	int i = 0;
	int j = 0;
	const struct agtx_webcam_cap *cap = data;

	/* Not support set cap binded */
	if (g_is_bind) {
		return -EINVAL;
	}

	/* g_webcam_caps */
	if (copy_from_user(&g_webcam_caps, cap, sizeof(struct agtx_webcam_cap))) {
		return -EFAULT;
	}

	/* formats */
	g_webcam_caps.formats = kmalloc(
			sizeof(struct agtx_webcam_cap_format) * g_webcam_caps.bNumFormats, GFP_KERNEL);
	if (copy_from_user(g_webcam_caps.formats, cap->formats,
				sizeof(struct agtx_webcam_cap_format) * g_webcam_caps.bNumFormats)) {
		return -EFAULT;
	}

	/* frames */
	for (i = 0; i < g_webcam_caps.bNumFormats; i++) {
		struct agtx_webcam_cap_format *format = &g_webcam_caps.formats[i];
		format->frames = kmalloc(
				sizeof(struct agtx_webcam_cap_frame) * format->bNumFrameDescriptors, GFP_KERNEL);

		if (copy_from_user(format->frames, cap->formats[i].frames,
					sizeof(struct agtx_webcam_cap_frame) * format->bNumFrameDescriptors)) {
			return -EFAULT;
		}

		/* intervals */
		for (j = 0; j < format->bNumFrameDescriptors; j++) {
			struct agtx_webcam_cap_frame *frame = &format->frames[j];
			frame->intervals = kmalloc(
					sizeof(unsigned int) * frame->bFrameIntervalType, GFP_KERNEL);
			if (copy_from_user(frame->intervals, cap->formats[i].frames[j].intervals,
						sizeof(unsigned int) * frame->bFrameIntervalType)) {
				return -EFAULT;
			}
		}
	}

#ifdef DEBUG
	/* DEBUG */
	for (i = 0; i < g_webcam_caps.bNumFormats; i++) {
		struct agtx_webcam_cap_format *format = &g_webcam_caps.formats[i];
		printk("Format %d:\n", i);
		if (format != NULL) {
			printk("\tcodec %d, minBitRate %d, maxBitRate %d\n", format->codec, format->dwMinBitRate, format->dwMaxBitRate);
		}
		for (j = 0; j < format->bNumFrameDescriptors; j++) {
			int k = 0;
			struct agtx_webcam_cap_frame *frame = &format->frames[j];
			printk("Frame %d:\n", j);
			if (frame != NULL) {
				printk("\twidth %d, height %d\n", frame->wWidth, frame->wHeight);
				printk("\tinterval:\n");
				if (frame->intervals != NULL) {
					for (k = 0; k < frame->bFrameIntervalType; k++) {
						printk("\t\t%d\n", frame->intervals[k]);
					}
				}
			}
		}
	}
#endif

	return 0;
}

static long agtx_webcam_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	long ret = 0;

	switch (cmd) {
		case AGTX_WEBCAM_IOCTL_BIND:
			ret = usb_composite_probe(&webcam_driver);
			if (ret == 0) {
				g_is_bind = 1;
			}
			break;
		case AGTX_WEBCAM_IOCTL_UNBIND:
			usb_composite_unregister(&webcam_driver);

			if (g_webcam_caps.formats != NULL) {
				int i;
				for (i = 0; i < g_webcam_caps.bNumFormats; i++) {
					struct agtx_webcam_cap_format *format = &g_webcam_caps.formats[i];
					if (format->frames != NULL) {
						int j;
						for (j = 0; j < format->bNumFrameDescriptors; j++) {
							struct agtx_webcam_cap_frame *frame = &format->frames[j];
							if (frame->intervals != NULL) {
								kfree(frame->intervals);
								frame->intervals = NULL;
							}
						}
						kfree(format->frames);
						format->frames = NULL;
					}
				}
				kfree(g_webcam_caps.formats);
				g_webcam_caps.formats = NULL;
			}

			g_is_bind = 0;
			break;
		case AGTX_WEBCAM_IOCTL_CAP_SET:
			ret = agtx_webcam_set_cap((void __user *)arg);
			break;
		default:
			ret = -ENOTTY;
			break;
	}

	return ret;
}

static ssize_t agtx_webcam_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

static int agtx_webcam_close(struct inode *inode, struct file *filp)
{
	return 0;
}

static int agtx_webcam_open(struct inode *inode, struct file *filp)
{
	int ret = 0;
	return ret;
}

static const struct file_operations agtx_webcam_fops = {
	.owner = THIS_MODULE,
	.open = agtx_webcam_open,
	.release = agtx_webcam_close,
	.read = agtx_webcam_read,
	.unlocked_ioctl = agtx_webcam_ioctl,
};

static int __init agtx_webcam_init(void)
{
	int ret = 0;

	ret = alloc_chrdev_region(&g_agtx_webcam_dev, 0, 1, DRV_NAME);
	if (ret) {
		return -EBUSY;
	}

	cdev_init(&g_agtx_webcam_cdev, &agtx_webcam_fops);
	g_agtx_webcam_cdev.owner = THIS_MODULE;
	g_agtx_webcam_cdev.ops = &agtx_webcam_fops;

	if (cdev_add(&g_agtx_webcam_cdev, g_agtx_webcam_dev, 1)) {
		unregister_chrdev_region(g_agtx_webcam_dev, 1);
		return -EBUSY;
	}

	g_agtx_webcam_class = class_create(THIS_MODULE, DRV_NAME);
	if (IS_ERR(g_agtx_webcam_class)) {
		cdev_del(&g_agtx_webcam_cdev);
		unregister_chrdev_region(g_agtx_webcam_dev, 1);
	}

	device_create(g_agtx_webcam_class, NULL, g_agtx_webcam_dev, NULL, DRV_NAME);


	return ret;
}

static void __exit agtx_webcam_exit(void)
{
	device_destroy(g_agtx_webcam_class, g_agtx_webcam_dev);
	class_destroy(g_agtx_webcam_class);
	cdev_del(&g_agtx_webcam_cdev);
	unregister_chrdev_region(g_agtx_webcam_dev, 1);
}

module_init(agtx_webcam_init);
module_exit(agtx_webcam_exit);

MODULE_AUTHOR("Henry Liu <henry.liu@augentix.com>");
MODULE_DESCRIPTION("Augentix Webcam Video Gadget");
MODULE_LICENSE("GPL");

