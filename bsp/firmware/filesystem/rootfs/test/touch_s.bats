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
}

@test "touch_s creates directories first and then touch files" {
	touch_s "$MOCK_SYSROOT/bin/ash"
	assert_file_exist "$MOCK_SYSROOT/bin/ash"
}

@test "touch_s accepts more than one arguments " {
	touch_s "$MOCK_SYSROOT/bin/cat" "$MOCK_SYSROOT/bin/chmod"
	assert_file_exist "$MOCK_SYSROOT/bin/cat"
	assert_file_exist "$MOCK_SYSROOT/bin/chmod"
}

teardown() {
	rm -rf "$TEMP_DIR"
}
