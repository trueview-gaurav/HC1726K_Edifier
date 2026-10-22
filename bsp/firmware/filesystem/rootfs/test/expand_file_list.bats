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

	# ifupdown.list
	# | /lib/ifupdown/*
	# | !/lib/ifupdown/wait-for-ll6.sh
	printf '/lib/ifupdown/*\n!/lib/ifupdown/wait-for-ll6.sh\n' \
		> "$TEMP_DIR/ifupdown.list"

	# iw.list
	# | /usr/sbin/iw
	printf '/usr/sbin/iw\n' \
		> "$TEMP_DIR/iw.list"
}

@test "expand_file_list works" {
	local files

	IFS=" " read -r -a files <<< "$(echo $TEMP_DIR/*.list)"
	run expand_file_list "$MOCK_SYSROOT" "${files[@]}"

	# dhcpd
	assert_line "$MOCK_SYSROOT/etc/dhcp/dhcpd.conf"
	assert_line "$MOCK_SYSROOT/usr/sbin/dhcpd"
	refute_line "$MOCK_SYSROOT/etc/dhcp/dhclient.conf"

	# ifupdown
	assert_line "$MOCK_SYSROOT/lib/ifupdown/settle-dad.sh"
	refute_line "$MOCK_SYSROOT/lib/ifupdown/wait-for-ll6.sh"

	# iw is not in sysroot, so it is not in the list
	refute_line "$MOCK_SYSROOT/usr/sbin/iw"
}

teardown() {
	rm -rf "$TEMP_DIR"
}
