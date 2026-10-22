#!/usr/bin/env bash
#
# Generate rootfs ubinize config if needed.
set -Eeuo pipefail

readonly ROOTFS_UBINIZE_CONFIG=$1

#######################################
# Generate rootfs ubinize config.
# Arguments:
#   $vol_size volume size.
# Outputs:
#   Write config to stdout.
#######################################
gen_rootfs_ubinize_cfg() {
	cat <<- EOF
	[ubifs]
	mode=ubi
	vol_id=0
	vol_type=dynamic
	vol_name=rootfs
	vol_alignment=1
	vol_flags=autoresize
	image=rootfs.ubifs
	EOF
}

#######################################
# Handle errors.
# Outputs:
#   Write error to stderr.
#######################################
handle_error() {
	printf "ERR Failed to generate rootfs ubinize config:\n  %s\n" \
		"$ROOTFS_UBINIZE_CONFIG" >&2
}

#######################################
# Main function.
# Globals:
#   $PROD_CONFIG product config file.
#   $ROOTFS_UBINIZE_CONFIG rootfs ubinize config file.
# Outputs:
#   Write config to file.
#######################################
main() {
	gen_rootfs_ubinize_cfg > "$ROOTFS_UBINIZE_CONFIG"
}

trap handle_error ERR
main
