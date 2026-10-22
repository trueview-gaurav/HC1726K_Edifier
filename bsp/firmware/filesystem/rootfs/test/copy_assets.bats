#!/usr/bin/env bats

TEMP_DIR=
MOCK_SYSROOT=
MOCK_ASSETS_DIR=

setup() {
	load 'test_helper/common-setup'
	_common_setup

	TEMP_DIR="$PROJECT_ROOT/test/tmp"
	MOCK_SYSROOT="$TEMP_DIR/sysroot"
	MOCK_ASSETS_DIR="$TEMP_DIR/assets"

	mkdir -p "$TEMP_DIR"
	source "helper.sh"

	# generate mock sysroot
	generate_mock_file \
		"$MOCK_SYSROOT/etc/dhcp/dhclient.conf" \
		"$MOCK_SYSROOT/etc/dhcp/dhcpd.conf" \
		"$MOCK_SYSROOT/lib/ifupdown/settle-dad.sh" \
		"$MOCK_SYSROOT/lib/ifupdown/wait-for-ll6.sh" \
		"$MOCK_SYSROOT/lib/libc.so.6" \
		"$MOCK_SYSROOT/lib/libm.so.6" \
		"$MOCK_SYSROOT/usr/bin/ash" \
		"$MOCK_SYSROOT/usr/sbin/dhcpd"

	# generate mock assets dir
	generate_mock_file \
		"$MOCK_ASSETS_DIR/usr/bin/autologin.sh" \
		"$MOCK_ASSETS_DIR/usr/bin/hello.sh" \
		"$MOCK_ASSETS_DIR/usr/bin/pin-info.sh" \
		"$MOCK_ASSETS_DIR/usr/bin/repair_db.sh"

	# add.list
	# | /usr/bin/*
	# | !/usr/bin/hello.sh
	printf '/usr/bin/*\n!/usr/bin/hello.sh\n' \
		> "$TEMP_DIR/add.list"
}

@test "copy_assets works" {
	local src_dir
	local dest_dir
	local files
	local list

	src_dir="$MOCK_ASSETS_DIR"
	dest_dir="$MOCK_SYSROOT"
	IFS=" " read -r -a files <<< "$(echo $TEMP_DIR/*.list)"
	list=$(expand_file_list "$MOCK_ASSETS_DIR" "${files[@]}")

	# the first time to copy assets to rootfs
	run copy_assets "$src_dir" "$dest_dir" "$list"
	[ "$status" -eq 0 ]

	# it should be ok to copy assets twice
	run copy_assets "$src_dir" "$dest_dir" "$list"
	[ "$status" -eq 0 ]

	assert_file_exist "$MOCK_SYSROOT/usr/bin/autologin.sh"
	assert_file_exist "$MOCK_SYSROOT/usr/bin/pin-info.sh"
	assert_file_exist "$MOCK_SYSROOT/usr/bin/repair_db.sh"
	assert_file_not_exist "$MOCK_SYSROOT/usr/bin/hello.sh"
}

teardown() {
	rm -rf "$TEMP_DIR"
}
