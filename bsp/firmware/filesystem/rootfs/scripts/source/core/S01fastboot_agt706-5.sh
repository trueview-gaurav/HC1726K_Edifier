#!/bin/sh

do_mmc() {
	# Load dw_mmc-host.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/mmc/host/dw_mmc-host.ko ]
	then
		modprobe dw_mmc-host
	fi

	# Load mmc_block.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/mmc/card/mmc_block.ko ]
	then
		modprobe mmc_block
	fi
}

do_usb() {
	# Load dwc2.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/usb/dwc2/dwc2.ko ]
	then
		modprobe dwc2
	fi

	# Load uas.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/usb/storage/uas.ko ]
	then
		modprobe uas
	fi
}

do_wlan() {
	. /etc/fastboot_video start
}

do_video() {
	busybox modprobe otp_ep
	busybox modprobe mpp.ko
	busybox modprobe sensor.ko

	/system/bin/mpi_stream -d /system/mpp/case_config/case_config_1004_FHD \
	-ppool_idx=0 -pblock_size=32784 -pblock_cnt=3 -ppool_name=isp_TMV_0 \
	-pdev_idx=0 -pbayer=PHASE_G0 -pinput_fps=25.0 -pinput_res=2048x1536 \
	-pchn_idx=0 -poutput_res=2048x1536 -poutput_fps=25 -pwindow_fps=25 \
	-pchn_idx=1 -poutput_res=640x480 -poutput_fps=25 -pwindow_fps=25 \
	-penc_idx=0 -penc_res=2048x1536 -pmax_enc_res=2048x1536 \
	-penc_fps=25 -pmax_bit_rate=2048 \
	-penc_idx=1 -penc_res=640x480 -pmax_enc_res=640x480 \
	-penc_fps=25 -pmax_bit_rate=768 \
	> /dev/null &

	busybox modprobe audio_pcm.ko
	busybox modprobe audio_machine.ko
}

do_late_insmod() {
	sleep 2
	do_usb &
}

do_start() {
	do_video
	do_mmc
	do_wlan
	do_late_insmod &
}

case "$1" in
	start)
		do_start
		;;
	stop)
		;;
	*)
		echo "Usage: $0 {start|stop}"
esac
