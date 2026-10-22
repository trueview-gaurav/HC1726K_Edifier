#!/bin/sh

#
# AUGENTIX INC. - PROPRIETARY
#
# sysup - System upstart
# Copyright (C) 2018 Augentix Inc. - All Rights Reserved
#
# NOTICE: The information contained herein is the property of Augentix Inc.
# Copying and distributing of this file, via any medium,
# must be licensed by Augentix Inc.
#
# * Brief: Restore U-Boot environement variable to non-update mode
# *
# * Author: ShihChieh Lin <shihchieh.lin@augentix.com>
# *         Carl Su <carl.su@augentix.com>
#

SW_VERSION_FILE=/etc/sw-version
update_file=/usrdata/update_file

FW_PRINTENV=/usr/sbin/fw_printenv
FW_SETENV=/usr/sbin/fw_setenv

BOOTPART=
SYSUPD_TYPE=

reset_file="/usrdata/reset_file"
DB_DEFAULT_PATH="/system/factory_default"
DB_ACTIVE_PATH="/usrdata/active_setting"
SSH_KEY_PATH="/system/ssh/"

DEBUGFS_PATH="/sys/kernel/debug"

print_version() {
	if [ -f $SW_VERSION_FILE ]; then
		printf "Software Version: "; cat $SW_VERSION_FILE
	fi
}

mount_debugfs() {
	mount -t debugfs nondev $DEBUGFS_PATH
}

unmount_debugfs() {
    umount $DEBUGFS_PATH
}

mountfs() {
	mount_debugfs
}

unmountfs() {
	unmount_debugfs
}

start_update() {
	if [ -e "$update_file" ]; then
		cp -f $DB_DEFAULT_PATH/prio.conf $DB_ACTIVE_PATH/prio.conf
	fi
}

start_reset() {
	# Reset all user preferences
	if [ -e "$reset_file" ]; then
		echo "Finishing user data reset..."
		# SSH KEY
		rm -rf $SSH_KEY_PATH
		# Remove active settings
		rm -rf $DB_ACTIVE_PATH/*

		# Restore SSH config
		cp -f $DB_DEFAULT_PATH/sshd_config $DB_ACTIVE_PATH/sshd_config
		cp -f $DB_DEFAULT_PATH/ssh_config $DB_ACTIVE_PATH/ssh_config
		# Restore HTTP server config
		cp -rf $DB_DEFAULT_PATH/nginx $DB_ACTIVE_PATH/nginx
		# Restore timezone
		cp -f $DB_DEFAULT_PATH/TZ $DB_ACTIVE_PATH/TZ
		# Restore Time server config
		cp -f $DB_DEFAULT_PATH/prio.conf $DB_ACTIVE_PATH/prio.conf
		cp -f $DB_DEFAULT_PATH/sntp.conf $DB_ACTIVE_PATH/sntp.conf
		cp -f $DB_DEFAULT_PATH/timeMode.conf $DB_ACTIVE_PATH/timeMode.conf
		cp -f $DB_DEFAULT_PATH/TimeSwitch.conf $DB_ACTIVE_PATH/TimeSwitch.conf
		# Restore database
		cp -f $DB_DEFAULT_PATH/ini.db $DB_ACTIVE_PATH/ini.db
		# Restore network i/f setting
		cp -f $DB_DEFAULT_PATH/interfaces $DB_ACTIVE_PATH/interfaces
		# Restore audio config setting
		cp -f $DB_DEFAULT_PATH/asound.conf $DB_ACTIVE_PATH/asound.conf
		# Restore wifi wpa_supplicant.conf setting
		cp -f $DB_DEFAULT_PATH/wpa_supplicant.conf $DB_ACTIVE_PATH/wpa_supplicant

		# Synchronize data on disk with memory
		sync

		# Remove reset flag
		rm -f "$reset_file"
		# Reset factory done
		echo " - User data reset finished"
	fi
}

#################
#  Script Entry #
#################

case "$1" in
	start)
		mountfs
		print_version
		start_reset
		start_update
	;;
	stop|restart)
		unmountfs
	;;
	*)
	echo "Usage: $0 {start|stop|restart}"
	exit 1
esac
exit 0

