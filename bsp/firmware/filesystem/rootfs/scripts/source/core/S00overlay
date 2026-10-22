#!/bin/sh

#
# AUGENTIX INC. - PROPRIETARY
#
# overlay - Overlay read-only rootfs
# Copyright (C) 2021 Augentix Inc. - All Rights Reserved
#
# NOTICE: The information contained herein is the property of Augentix Inc.
# Copying and distributing of this file, via any medium,
# must be licensed by Augentix Inc.
#
# * Brief: Restore U-Boot environement variable to non-update mode
# *
# * Author: ShihChieh Lin <shihchieh.lin@augentix.com>
#

USRDATAFS_PATH=/usrdata

case "$1" in
	start)
		mkdir -p $USRDATAFS_PATH/upper/etc $USRDATAFS_PATH/upper/system $USRDATAFS_PATH/workdir/etc $USRDATAFS_PATH/workdir/system
		mount -t overlay etc /etc -o rw,lowerdir=/etc,upperdir=$USRDATAFS_PATH/upper/etc,workdir=$USRDATAFS_PATH/workdir/etc
		mount -t overlay system /system -o rw,lowerdir=/system,upperdir=$USRDATAFS_PATH/upper/system,workdir=$USRDATAFS_PATH/workdir/system
	;;
	stop|restart)
		# Do nothing
	;;
	*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac
exit 0

