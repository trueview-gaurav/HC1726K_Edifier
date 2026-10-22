#!/usr/bin/env bash
set -Eeuo pipefail

PROJECT_ROOT=$(readlink -e "$(dirname "$0")/..")
ROOTFS_PATH="${ROOTFS_PATH:-$PROJECT_ROOT}"

# shellcheck source=/dev/null
source "$ROOTFS_PATH/tool/helper.sh"

handle_error() {
	printf "Fatal error (%s): Failed to shrink the rootfs.\n" "$?"
}

usage() {
	local cmd="${0##*/}"

	cat <<- EOF
	Usage: $cmd <sysroot> <rm_list ..>
	EOF
}

main() {
	local sysroot="$1"
	shift
	local files=("$@")
	local list

	list=$(expand_file_list "$sysroot" "${files[@]}")
	shrink_rootfs "$list"
}

trap handle_error ERR

if [ "$#" -lt 2 ]; then
	usage
	exit 1
else
	main "$@"
fi
