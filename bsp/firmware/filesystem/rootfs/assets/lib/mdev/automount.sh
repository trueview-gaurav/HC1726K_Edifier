#!/bin/sh
#
#  AUGENTIX INC. - PROPRIETARY
#
#  automount.sh - Automount script for removable media devices
#  Copyright (C) 2019 Augentix Inc. - All Rights Reserved
#
#  NOTICE: The information contained herein is the property of Augentix Inc.
#  Copying and distributing of this file, via any medium,
#  must be licensed by Augentix Inc.
#
#  * Author: ShihChieh Lin <shihchieh.lin@augentix.com>
#

# Mounting points
sdcard_destdir=/mnt/sdcard
usb_destdir=/mnt/usb

# Card insertion event flag
sdcd_flag="/tmp/sdcd"

# Log file for pluggable devices
logfile=/tmp/plog
syslog_cfg=/tmp/syslog.conf
syslog_cfg_bak=/tmp/syslog0.conf

#current_time=$(date "+%Y%m%d%H%M%S")
new_log_name="0.log"

LOGGING=/etc/init.d/S03logging

mem_enough=0;

gen_logname()
{

   num=0
   dir=$1

   for file_name in `ls $dir | grep .log`; do


         end_idx=$(expr index $file_name '.log')
         end_idx=$(expr $end_idx - 1)
         file_num=${file_name:0:$end_idx}
         check=`echo "$file_num" | grep -E ^\-?[0-9]*\.?[0-9]+$`

        if [ "$check" != '' ]; then
          #it is numeric
          if [ "$file_num" -ge "$num" ]; then
            num=$(expr $file_num + 1)
          fi
        fi

   done

   echo "$num.log"
}

check_capacity_and_memory() {
	Memfree=`cat /proc/meminfo | grep "MemFree" | awk '{print $2/1024}'`
	if [ -e /dev/${MDEV}p1 ]; then
		SDCapacity=`fdisk -l /dev/${MDEV} | grep -w "Disk /dev/${MDEV}:"| awk '{print $3}'`
		SDUnit=`fdisk -l /dev/${MDEV} | grep -w "Disk /dev/${MDEV}:"| awk '{print $4}'| cut -d ',' -f 1`
		if [ "$SDUnit" == "MB" ]; then
			SDCapacity=$(echo $SDCapacity 1024 | awk '{printf("%.3f", ($1/$2))}')
		fi
		#echo "$SDCapacity" > /dev/console
	else
		# if dev/mmcblk0 doesn't contain a valid partition table then 
		# fsck.vfat cannot run successfully due to "Logical sector size is zero."
		no_partition_table=`fdisk -l /dev/${MDEV} | grep -w "Disk /dev/${MDEV} doesn't contain a valid partition table"`
		if [ "$no_partition_table" != "" ]; then
			echo " /dev/${MDEV} doesn't contain a valid partition table" > /dev/console
			return 0
		else
			SDCapacity=`fdisk -l /dev/${MDEV} | grep -w "Disk /dev/${MDEV}:"| awk '{print $3}'`
			SDUnit=`fdisk -l /dev/${MDEV} | grep -w "Disk /dev/${MDEV}:"| awk '{print $4}'| cut -d ',' -f 1`
			if [ "$SDUnit" == "MB" ]; then
				SDCapacity=$(echo $SDCapacity 1024 | awk '{printf("%.3f", ($1/$2))}')
			fi
		fi
	fi
	
	if [ `echo "$SDCapacity > 200" | bc` -eq 1 ]; then	# >= 256GB SD card
		if [ `echo "$Memfree > 65" | bc` -eq 1 ]; then	#memory > 65MB not measurement just predicted
			mem_enough=1
		else
			echo "!Warning memory is not enough (<65MB) for fsck.vfat!" > /dev/console
		fi
	elif [ `echo "$SDCapacity > 100" | bc` -eq 1 ]; then	#128GB SD card
		if [ `echo "$Memfree > 30" | bc` -eq 1 ]; then	#memory > 30MB
			mem_enough=1
		else
			echo "!Warning memory is not enough (<30MB) for fsck.vfat!" > /dev/console
		fi
	elif [ `echo "$SDCapacity > 50" | bc` -eq 1 ]; then	#64GB SD card
		if [ `echo "$Memfree > 14" | bc` -eq 1 ]; then #memory > 14MB
			mem_enough=1
		else
			echo "!Warning memory is not enough (<14MB) for fsck.vfat!" > /dev/console
		fi
	elif [ `echo "$SDCapacity > 25" | bc` -eq 1 ]; then #32GB SD card
		if [ `echo "$Memfree > 7.1" | bc` -eq 1 ]; then #memory > 7.1MB
			mem_enough=1
		else
			echo "!Warning memory is not enough (<7.1MB) for fsck.vfat!" > /dev/console
		fi
	else
		#<32GB SD card
		if [ `echo "$Memfree > 3.6" | bc` -eq 1 ]; then #memory > 3.6MB
			mem_enough=1
		else
			echo "Warning memory is not enough (< 3.6MB) for fsck.vfat!" > /dev/console
		fi
	fi
}

auto_mount() {
	local mounted=0
	case $1 in
	"sdcard")
		# Skip when eMMC present
		if [ -e /dev/${MDEV}boot0 ]; then
			return 0
		fi
		touch $sdcd_flag
		sleep 1
		if [ -e $sdcd_flag ]; then
			# Attempt to mount p1 first
			if [ -e /dev/${MDEV}p1 ]; then
				check_capacity_and_memory
				if [ $mem_enough -eq 1 ]; then
					fsck.vfat -F 1 -w -N -m -a /dev/${MDEV}p1 > /dev/console
					fsck.vfat -F 2 -w -N -m -a /dev/${MDEV}p1 > /dev/console
				fi
				mount -t vfat /dev/${MDEV}p1  $sdcard_destdir
				if [ $? -eq 0 ]; then
					echo "Mount SD card from /dev/${MDEV}p1" >> $logfile
					mounted=1
				fi
			fi

			# Attempt to mount blk0 if p1 is not mounted
			if [ $mounted -eq 0 ]; then
				check_capacity_and_memory
				if [ $mem_enough -eq 1 ]; then
					fsck.vfat -F 1 -w -N -m -a /dev/${MDEV} > /dev/console
					fsck.vfat -F 2 -w -N -m -a /dev/${MDEV} > /dev/console
				fi
				mount -t vfat /dev/${MDEV}  $sdcard_destdir
				if [ $? -eq 0 ]; then
					echo "Mount SD card from /dev/${MDEV}" >> $logfile
					mounted=1
				fi
			fi

			# Return if card is not mounted
			if [ $mounted -eq 0 ]; then
				echo "Failed to mount SD card!" >> $logfile
				return 1
			fi

			cp -f $syslog_cfg $syslog_cfg_bak
			if [ -e $sdcard_destdir/DumpLogToCard ]
			then
				$LOGGING stop
				cp -f $syslog_cfg $syslog_cfg_bak
				new_log_name=$(gen_logname $sdcard_destdir/log)
				echo "*.*                       $sdcard_destdir/log/$new_log_name" >> $syslog_cfg
				mkdir -p $sdcard_destdir/log
				$LOGGING start
			fi
		fi
		;;
	"usb")
		echo "Mount USB disk from /dev/$MDEV" >> $logfile
		mount -t auto /dev/$MDEV $usb_destdir
		;;
	"pseudo_usb_host")
		sync > /dev/console
		umount /mnt/sdcard  > /dev/console
		echo "Unmount sdcard from /mnt/sdcard"  > /dev/console
		;;
	*)
		;;
	esac
}

auto_umount() {
	case $1 in
	"sdcard")
		rm -rf $sdcd_flag
		sleep 1
		if [ ! -e $sdcd_flag ]; then
			echo "Unmount SD card from $sdcard_destdir" >> $logfile
			[ -f $syslog_cfg_bak ] && mv -f $syslog_cfg_bak /etc/syslog.conf
			$LOGGING restart
			umount $sdcard_destdir
		fi
		;;
	"usb")
		echo "Unmount USB disk from $usb_destdir" >> $logfile
		umount $usb_destdir
		;;
	"pseudo_usb_host")
		sync > /dev/console
		mount -t vfat /dev/mmcblk0p1 /mnt/sdcard > /dev/console
		echo "Mount sdcard to /mnt/sdcard" > /dev/console
		;;
	*)
		;;
	esac
}

/bin/touch $logfile
if [ "$ACTION" == add ]; then
        auto_mount $1
elif [ "$ACTION" == remove ]; then
    auto_umount $1
else
    :
fi
