#!/usr/bin/env bash
set -Eeuo pipefail

PROJECT_ROOT=$(readlink -e "$(dirname "$0")/..")
ROOTFS_PATH="${ROOTFS_PATH:-$PROJECT_ROOT}"

# shellcheck source=/dev/null
source "$ROOTFS_PATH/tool/helper.sh"

handle_error() {
	printf "Fatal error (%s): Failed to copy assets to rootfs.\n" "$?"
}

usage() {
	local cmd="${0##*/}"

	cat <<- EOF
	Usage: $cmd <src_dir> <dest_dir> <rm_list ..>
	EOF
}

main() {
	local src_dir="$1"
	shift
	local dest_dir="$1"
	shift
	local files=("$@")
	local list

	list=$(expand_file_list "$src_dir" "${files[@]}")
	copy_assets "$src_dir" "$dest_dir" "$list"
}

trap handle_error ERR

if [ "$#" -lt 3 ]; then
	usage
	exit 1
else
	main "$@"
fi
