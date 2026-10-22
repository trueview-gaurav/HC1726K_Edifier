#!/usr/bin/env bash
set -Eeuo pipefail

SRC_DIR=$(readlink -e ../..)
readonly SRC_DIR
readonly SRC_BUILD_DIR=${SRC_DIR}/firmware/build

readonly DST_DIR=${SRC_BUILD_DIR}/SDK_release
readonly DST_BUILD_DIR=${DST_DIR}/firmware/build

readonly CONFIG_FILE=${SRC_BUILD_DIR}/.config

readonly SRC_ROOTFS_TOOL_DIR=${SRC_DIR}/firmware/filesystem/rootfs/tool
readonly OBJCOPY=${CROSS_COMPILE}objcopy
readonly STRIP=${CROSS_COMPILE}strip
readonly SSTRIP=${SRC_ROOTFS_TOOL_DIR}/sstrip

SDK_VER=

: "${CONFIG_HC1702_1752_1772_1782:=}"
is_hc17x2() {
	[ "$CONFIG_HC1702_1752_1772_1782" = 'y' ]
}

: "${CONFIG_HC1703_1723_1753_1783S:=}"
: "${CONFIG_SAPPORO:=}"
: "${CONFIG_KAMO:=}"
is_hc17x3() {
	[ "$CONFIG_HC1703_1723_1753_1783S" = 'y' ] || [ "$CONFIG_SAPPORO" = 'y' ] || [ "$CONFIG_KAMO" = 'y' ]
}

: "${CONFIG_UCLIBC:=}"
is_uclibc() {
	[ "$CONFIG_UCLIBC" = 'y' ]
}

: "${CONFIG_KERNEL_V6_1:=}"
is_kernel_v6.1() {
	[ "$CONFIG_KERNEL_V6_1" = 'y' ]
}

: "${CONFIG_CHIP:=}"
chip_type() {
	local tmp="$CONFIG_CHIP"
	tmp="${tmp,,}"     # pipe 1: convert string to lowercase
	tmp="${tmp//_/-}"  # pipe 2: replace all underscore to the hyphen
	echo "$tmp"
}

sync_core_lib() {
	local mod="$1"
	local type="${2:-lib}"
	rsync -avrq --exclude='.git' "$SRC_DIR/$mod/$type" "$DST_DIR/$mod"

	if is_uclibc; then
		if [ "$type" = 'ko' ]; then
			if is_kernel_v6.1; then
				mv "$DST_DIR/$mod/$type" "$DST_DIR/$mod/$type.$(chip_type).linux6.1.minimal"
				rsync -avrq "$DST_DIR/$mod/$type.$(chip_type).linux6.1.minimal/" "$DST_DIR/$mod/$type.$(chip_type).linux6.1.minimal_stripped"
				strip_core_lib "$DST_DIR/$mod/$type.$(chip_type).linux6.1.minimal_stripped"
				validate_is_stripped "$DST_DIR/$mod/$type.$(chip_type).linux6.1.minimal_stripped"
			else
				mv "$DST_DIR/$mod/$type" "$DST_DIR/$mod/$type.$(chip_type).minimal"
				rsync -avrq "$DST_DIR/$mod/$type.$(chip_type).minimal/" "$DST_DIR/$mod/$type.$(chip_type).minimal_stripped"
				strip_core_lib "$DST_DIR/$mod/$type.$(chip_type).minimal_stripped"
				validate_is_stripped "$DST_DIR/$mod/$type.$(chip_type).minimal_stripped"
			fi
		else
			mv "$DST_DIR/$mod/$type" "$DST_DIR/$mod/$type.$(chip_type).uclibc"
			rsync -avrq "$DST_DIR/$mod/$type.$(chip_type).uclibc/" "$DST_DIR/$mod/$type.$(chip_type).uclibc_stripped"
			strip_core_lib "$DST_DIR/$mod/$type.$(chip_type).uclibc_stripped"
			validate_is_stripped "$DST_DIR/$mod/$type.$(chip_type).uclibc_stripped"
		fi
	else
		if [ "$type" = 'ko' ] && is_kernel_v6.1; then
			mv "$DST_DIR/$mod/$type" "$DST_DIR/$mod/$type.$(chip_type).linux6.1"
			rsync -avrq "$DST_DIR/$mod/$type.$(chip_type).linux6.1/" "$DST_DIR/$mod/$type.$(chip_type).linux6.1_stripped"
			strip_core_lib "$DST_DIR/$mod/$type.$(chip_type).linux6.1_stripped"
			validate_is_stripped "$DST_DIR/$mod/$type.$(chip_type).linux6.1_stripped"
		else
			mv "$DST_DIR/$mod/$type" "$DST_DIR/$mod/$type.$(chip_type)"
			rsync -avrq "$DST_DIR/$mod/$type.$(chip_type)/" "$DST_DIR/$mod/$type.$(chip_type)_stripped"
			strip_core_lib "$DST_DIR/$mod/$type.$(chip_type)_stripped"
			validate_is_stripped "$DST_DIR/$mod/$type.$(chip_type)_stripped"
		fi
	fi
}

strip_core_lib() {
	local CORE_LIB_DIR=$1

	rm -rf ${SRC_BUILD_DIR}/elf_list.txt
	rm -rf ${SRC_BUILD_DIR}/ko_list.txt
	${SRC_ROOTFS_TOOL_DIR}/strip_file_elf.sh ${CORE_LIB_DIR} ${OBJCOPY} ${STRIP} ${SSTRIP} elf_list.txt
	${SRC_ROOTFS_TOOL_DIR}/strip_file_ko.sh ${CORE_LIB_DIR} ${OBJCOPY} ${STRIP} ${SSTRIP} ko_list.txt
	rm -rf ${SRC_BUILD_DIR}/elf_list.txt
	rm -rf ${SRC_BUILD_DIR}/ko_list.txt
}

validate_is_stripped() {
	local CORE_LIB_DIR=$1

	rm -f ko_list.txt
	rm -f elf_list.txt

	find ${CORE_LIB_DIR} -name "*.ko" > ko_list.txt || true
	find ${CORE_LIB_DIR} -type f -not -name "*.ko" -exec file {} \; | grep -i "ELF" > elf_list.txt || true

	while read -r line;
	do
		name="$line"
		local result=$(${CROSS_COMPILE}objdump --syms "$name" | grep .debug_info || true)
		if [ -z "$result" ] ; then
			: # Checked stripped. Do nothing.
		else
			echo "${name} is not stripped!!!"
			return -1
		fi
	done < ko_list.txt

	while read -r line;
	do
		name="$line"
		local result=$(file "$name" | grep "not stripped"|| true)
		if [ -z "$result" ] ; then
			: # Checked stripped. Do nothing.
		else
			echo "${name} is not stripped!!!"
			return -1
		fi
	done < elf_list.txt

	rm -f ko_list.txt
	rm -f elf_list.txt
}

sync_build() {
	rsync -avrq --exclude='.git' "$SRC_BUILD_DIR/build_utils" "$DST_BUILD_DIR"
	rsync -avrq --exclude='.git' "$SRC_BUILD_DIR/rule.make" "$DST_BUILD_DIR"
	rm -f "$DST_BUILD_DIR/build_utils/.exclude_file"
	rm -f "$DST_BUILD_DIR/build_utils/.include_file"
	rm -f "$DST_BUILD_DIR/build_utils/*.csv"
	rm -f "$DST_BUILD_DIR/build_utils/*.sh"
	rm -f "$DST_BUILD_DIR/build_utils/padding"
	cp -f "$SRC_BUILD_DIR/.version" "$DST_BUILD_DIR"
	cp -f "$SRC_BUILD_DIR/import_config.mk" "$DST_BUILD_DIR"
	cp -f "$SRC_BUILD_DIR/sdksrc.mk" "$DST_BUILD_DIR"
	cp -f "$SRC_BUILD_DIR/versioning.mk" "$DST_BUILD_DIR"
	cp -f "$SRC_BUILD_DIR/sdk-version" "$DST_BUILD_DIR"
	cp -f "$SRC_BUILD_DIR/Makefile" "$DST_BUILD_DIR"
	cp -f "$SRC_BUILD_DIR/buildroot.mk" "$DST_BUILD_DIR"

}

sync_bootloader() {
	mkdir -p "$DST_DIR/sdk/bootloader"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/bootloader/uboot" "$DST_DIR/sdk/bootloader"
}

sync_cpvs() {
	mkdir -p "$DST_DIR/sdk/core/cpvs"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/cpvs/build" "$DST_DIR/sdk/core/cpvs"
	if is_hc17x3; then
		sync_core_lib "sdk/core/cpvs" "lib"
		rsync -avrqL --exclude='.git' "$SRC_DIR/sdk/core/cpvs/$(chip_type)/include" "$DST_DIR/sdk/core/cpvs"
		mv "$DST_DIR/sdk/core/cpvs/include" "$DST_DIR/sdk/core/cpvs/include.$(chip_type)"
	fi
}

sync_mpp() {
	mkdir -p "$DST_DIR/sdk/core/mpp"
	sync_core_lib "sdk/core/mpp" "ko"
	sync_core_lib "sdk/core/mpp" "lib"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/mpp/build" "$DST_DIR/sdk/core/mpp"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/mpp/include" "$DST_DIR/sdk/core/mpp"
}

sync_iva() {
	mkdir -p "$DST_DIR/sdk/core/aftr"
	mkdir -p "$DST_DIR/sdk/core/vftr"
	mkdir -p "$DST_DIR/sdk/core/ir_control"
	mkdir -p "$DST_DIR/sdk/core/ml"
	mkdir -p "$DST_DIR/sdk/core/otp"
	sync_core_lib "sdk/core/aftr" "lib"
	sync_core_lib "sdk/core/vftr" "lib"
	sync_core_lib "sdk/core/ir_control" "lib"
	sync_core_lib "sdk/core/ml" "lib"
	sync_core_lib "sdk/core/otp" "ko"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/aftr/build" "$DST_DIR/sdk/core/aftr"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/aftr/include" "$DST_DIR/sdk/core/aftr"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/vftr/build" "$DST_DIR/sdk/core/vftr"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/vftr/include" "$DST_DIR/sdk/core/vftr"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/ir_control/build" "$DST_DIR/sdk/core/ir_control"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/ir_control/include" "$DST_DIR/sdk/core/ir_control"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/ml/build" "$DST_DIR/sdk/core/ml"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/ml/include" "$DST_DIR/sdk/core/ml"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/otp/build" "$DST_DIR/sdk/core/otp"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/core/otp/include" "$DST_DIR/sdk/core/otp"
}

sync_utils() {
	mkdir -p "$DST_DIR/sdk/utils/host"
	mkdir -p "$DST_DIR/sdk/utils/target"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/utils/build" "$DST_DIR/sdk/utils"
	rsync -avrq --exclude='.git' "$SRC_DIR/sdk/utils/host/bin" "$DST_DIR/sdk/utils/host"
	mv "$DST_DIR/sdk/utils/host/bin" "$DST_DIR/sdk/utils/host/bin.$(chip_type)"
	sync_core_lib "sdk/utils/target" "bin"
}

sync_sdk() {
	sync_build
	sync_bootloader
	sync_cpvs
	sync_mpp
	sync_iva
	sync_utils
}

post_install() {
	# Because staging environment is an App-manifest-like environment, ABI
	# version should be updated and fixed by make target 'version-bump'
	# before generating file 'sdk-version' in staging environment.
	#
	# The change in .version and sdk-version will be commited into Git
	# after copy and paste staging environment to App manifest
	make -C "$DST_BUILD_DIR" update-builddate
	make -C "$DST_BUILD_DIR" sdk-info-install SDK_VER="$SDK_VER"
}

read_sdk_ver() {
	if [ $# -eq 0 ] ; then
		read -rp "Enter SDK version: " SDK_VER
	else
		SDK_VER=$1
	fi
}

check_env() {
	[ ! -f "$CONFIG_FILE" ] && \
		echo "Missing config file." && \
		return 1
	return 0
}

handle_error() {
	echo "Fatal error: Failed to generate SDK release."
}

main() {
        # import product config
        # shellcheck source=/dev/null
	. <(sed '/AUDIO_CODEC/d; /LENS/d; /LENS1/d' "$CONFIG_FILE")

	echo " - SDK version: $SDK_VER"

	echo "Initializing SDK..."
	rm -rf "$DST_DIR"
	mkdir -p "$DST_DIR"
	mkdir -p "$DST_DIR/.release"
	mkdir -p "$DST_BUILD_DIR"

	echo "Building SDK..."
	sync_sdk
	post_install

	echo "The SDK staging environment has been generated successfully."
}

trap handle_error ERR
check_env
read_sdk_ver "$@"

main
