#!/usr/bin/env bats

TEMP_DIR=
MOCK_SYSROOT=

setup() {
	load 'test_helper/common-setup'
	_common_setup

	TEMP_DIR="$PROJECT_ROOT/test/tmp"
	MOCK_SYSROOT="$TEMP_DIR/sysroot"

	mkdir -p "$TEMP_DIR"
	source "helper.sh"

	generate_mock_file \
		"$MOCK_SYSROOT/etc/dhcp/dhclient.conf" \
		"$MOCK_SYSROOT/etc/dhcp/dhcpd.conf" \
		"$MOCK_SYSROOT/lib/ifupdown/settle-dad.sh" \
		"$MOCK_SYSROOT/lib/ifupdown/wait-for-ll6.sh" \
		"$MOCK_SYSROOT/lib/libc.so.6" \
		"$MOCK_SYSROOT/lib/libm.so.6" \
		"$MOCK_SYSROOT/usr/sbin/dhcpd"

	# dhcpd.list
	# | /etc/dhcp/*
	# | /usr/sbin/dhcpd
	# | !/etc/dhcp/dhclient.conf
	printf '/etc/dhcp/*\n/usr/sbin/dhcpd\n!/etc/dhcp/dhclient.conf\n' \
		> "$TEMP_DIR/dhcpd.list"
}

@test "shrink_rootfs works" {
	local files
	local list

	IFS=" " read -r -a files <<< "$(echo $TEMP_DIR/*.list)"
	list=$(expand_file_list "$MOCK_SYSROOT" "${files[@]}")

	# the first time to shrink rootfs
	run shrink_rootfs "$list"
	[ "$status" -eq 0 ]

	# it should be ok to shrink twice
	run shrink_rootfs "$list"
	[ "$status" -eq 0 ]

	# dhcpd has been removed
	assert_file_not_exist "$MOCK_SYSROOT/etc/dhcp/dhcpd.conf"
	assert_file_not_exist "$MOCK_SYSROOT/usr/sbin/dhcpd"

	# dhclient.conf is excluded
	assert_file_exist "$MOCK_SYSROOT/etc/dhcp/dhclient.conf"
}

teardown() {
	rm -rf "$TEMP_DIR"
}
