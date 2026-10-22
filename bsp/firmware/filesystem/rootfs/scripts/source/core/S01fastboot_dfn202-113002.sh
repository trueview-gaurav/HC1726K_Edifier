#!/bin/sh

IFACE=eth0
# Default MAC address set by U-Boot
ETHADDR=''
ETHADDR_DEFAULT=02:00:00:00:00:00
DEV_DRV_DIR=/lib/modules/$(uname -r)/kernel/drivers

# do_od() {
# 	echo 7 > /proc/sys/kernel/printk

# 	sleep 2
# 	od_config=/system/mpp/od_config/od_conf.json
# 	/system/bin/od_demo -i "$od_config" >/dev/null &

# 	sleep 2
# 	/system/bin/cmdsender --od 0 0 0 59 63 25 254 0 50 50 640 360 1 >/dev/null || return 0
# }

# do_audio() {
# 	modprobe audio_pcm || return 1
# 	modprobe audio_machine || return 1
# }

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

	# Ensure mmcblk0p1 exists before automount.sh.
	# Otherwise falls back to mmcblk0 (sector size 0).
	retry=10
	while [ $retry -gt 0 ]; do
		[ -e /dev/mmcblk0p1 ] && break
		sleep 0.1
		retry=$((retry - 1))
	done
	
	if [ $retry -eq 0 ]; then
		echo "[WARNING] /dev/mmcblk0p1 not found after retry" >&2
	fi

	# Wait for automount.sh (async via mdev) to mount /mnt/sdcard.
	# Device node ready != mount done.
	retry=50
	while [ $retry -gt 0 ]; do
		mountpoint -q /mnt/sdcard && break
		sleep 0.1
		retry=$((retry - 1))
	done

	if [ $retry -eq 0 ]; then
		echo "[WARNING] /mnt/sdcard not mounted after retry" >&2
	fi

	# Bind /mnt/sdcard into mpi_stream (initramfs) for direct SD access.
	local mpi_pid
	mpi_pid=$(cat /run/mpi_stream.pid 2>/dev/null)
	if [ -z "$mpi_pid" ]; then
		echo "[ERROR] mpi_stream pid not found, skip sdcard bind mount"
		return 1
	fi

	local target="/proc/${mpi_pid}/root/mnt/sdcard"
	if [ ! -d "$target" ]; then
		echo "[ERROR] $target does not exist, skip bind mount"
		return 1
	fi

	mount --bind /mnt/sdcard "$target"
	if [ $? -ne 0 ]; then
		echo "[ERROR] bind mount /mnt/sdcard -> $target FAILED"
		return 1
	fi
}

set_random_ethaddr() {
	ETHADDR=$(tr -dc A-F0-9 < /dev/urandom | head -c 6 | \
		sed -r 's/(..)/\1:/g;s/:$//;s/^/12:34:56:/')
	echo "Randomize MAC address: $ETHADDR"
	ifconfig $IFACE hw ether $ETHADDR
}

do_eth() {
	# dwmac-dwc-qos-eth: Ethernet driver (must succeed if present)
	drv="$DEV_DRV_DIR/net/ethernet/stmicro/stmmac/dwmac-dwc-qos-eth.ko"
	[ -f "$drv" ] || return 0
	modprobe dwmac-dwc-qos-eth || return 1

	# Retry up to 5 times to wait for interface creation
	sysfs="/sys/class/net/$IFACE"
	retry=5
	timeout_sec=0.5
	while [ $retry -gt 0 ]; do
		[ -d "$sysfs" ] && break
		sleep "$timeout_sec"
		retry=$((retry - 1))
	done
	[ $retry -gt 0 ] || return 1

	# Set random MAC address if default value is detected
	if [ -f "$sysfs/address" ]; then
		ETHADDR=$(cat "$sysfs/address")
		[ -n "$ETHADDR" ] && [ "$ETHADDR" = "$ETHADDR_DEFAULT" ] && set_random_ethaddr
	fi

	# Skip if interface is already up
	ip link show "$IFACE" 2>/dev/null | grep -q "state UP" && return 0

	# Bring up the interface (optional)
	/sbin/ifup "$IFACE" || return 0
}

do_usb() {
    # dwc2: USB controller (must succeed if present)
    drv="$DEV_DRV_DIR/usb/dwc2/dwc2.ko"
	[ -f "$drv" ] || return 0
	modprobe dwc2 || return 1

    # uas: USB storage protocol (optional)
    drv="$DEV_DRV_DIR/usb/storage/uas.ko"
    [ -f "$drv" ] && modprobe uas || return 0
}

do_late_insmod() {
	sleep 2
	do_usb &
}

do_start() {
	do_mmc &
	do_eth
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
