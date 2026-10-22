#!/bin/sh

IFACE=eth0

# Default MAC address set by U-Boot
ETHADDR_DEFAULT=02:00:00:00:00:00

set_random_ethaddr() {
	ETHADDR=$(tr -dc A-F0-9 < /dev/urandom | head -c 6 | \
		sed -r 's/(..)/\1:/g;s/:$//;s/^/12:34:56:/')
	echo "Randomize MAC address: $ETHADDR"
	ifconfig $IFACE hw ether $ETHADDR
}

do_eth() {
	# Load dwc_eth_qos.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/net/ethernet/stmicro/stmmac/dwmac-dwc-qos-eth.ko ]
	then
		modprobe dwmac-dwc-qos-eth
		ETHADDR=$(cat /sys/class/net/$IFACE/address)
		if [ $ETHADDR = $ETHADDR_DEFAULT ]; then
			set_random_ethaddr
		fi
		/sbin/ifup $IFACE
	fi
}

do_mmc() {
	# Load dw_mmc-host.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/mmc/host/dw_mmc-host.ko ]
	then
		modprobe dw_mmc-host
	fi

	# Load mmc_block.ko if file does exist
	if [ -f /lib/modules/`uname -r`/kernel/drivers/mmc/core/mmc_block.ko ]
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

# mpi_stream is already brought up at initramfs stage.
do_video() {
	export ALSA_CONFIG_PATH=/usr/share/alsa/alsa.conf
	/system/bin/mp4_muxer -r 8000 -f 30 -d /tmp/ -o /tmp/ > /dev/null &
}


do_late_insmod() {
	sleep 2
	do_usb &
}

do_start() {
	do_eth
	do_mmc &
	do_late_insmod &
	do_video
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
