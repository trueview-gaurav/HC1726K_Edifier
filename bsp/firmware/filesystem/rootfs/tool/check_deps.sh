#!/usr/bin/env bash
#
# check_deps.sh - Verify every ELF in the rootfs can resolve its DT_NEEDED
#                 shared libraries from within the same rootfs.
#
# Run AFTER rm.list shrinking and BEFORE the image is packed, so it sees the
# final tree that ships on the device. Catches the class of failure that the
# device reports only as the opaque uClibc loader message:
#
#     error while loading shared libraries: <lib>: internal error
#
# because the toolchain's uClibc is built without __SUPPORT_LD_DEBUG__, so the
# loader never names the missing dependency. This script names it at build time.
#
# Usage: check_deps.sh <sysroot> <readelf> [strict]
#   sysroot : root of the filesystem tree to scan (e.g. output/target_debug)
#   readelf : cross readelf binary (e.g. arm-...-readelf)
#   strict  : "y" -> exit non-zero when anything is missing; otherwise warn only
#
set -Eeuo pipefail

PROJECT_ROOT=$(readlink -e "$(dirname "$0")/..")
ROOTFS_PATH="${ROOTFS_PATH:-$PROJECT_ROOT}"

usage() {
	local cmd="${0##*/}"
	cat <<- EOF
	Usage: $cmd <sysroot> <readelf> [strict]
	EOF
}

# Libraries provided by the dynamic loader / kernel that never appear as a
# real file in the rootfs lib dirs. Do not flag these as missing.
LOADER_PROVIDED='^(ld-uClibc\.so.*|ld-linux.*|linux-vdso\.so.*|linux-gate\.so.*)$'

main() {
	local sysroot readelf strict
	sysroot="${1:-}"
	readelf="${2:-readelf}"
	strict="${3:-n}"

	if [ -z "$sysroot" ] || [ ! -d "$sysroot" ]; then
		usage
		echo "check_deps: invalid sysroot '$sysroot'" >&2
		exit 2
	fi

	# 1. Collect every ELF file in the tree.
	local elfs
	elfs=$(find "$sysroot" -type f \
		\( -path '*/lib/*' -o -path '*/bin/*' -o -path '*/sbin/*' \) \
		2>/dev/null | while read -r f; do
			# Cheap ELF magic check before the (slower) readelf call.
			if LC_ALL=C head -c 4 "$f" 2>/dev/null | grep -q $'\x7fELF'; then
				printf '%s\n' "$f"
			fi
		done)

	# 2. Build the set of sonames the rootfs PROVIDES: every ELF's SONAME plus
	#    the basenames of the lib files themselves (covers libX.so.N symlinks).
	local provided
	provided=$(
		{
			for f in $elfs; do
				"$readelf" -d "$f" 2>/dev/null \
					| sed -n 's/.*Library soname: \[\(.*\)\].*/\1/p'
				basename "$f"
			done
			# Also count every file living in a lib dir (symlinks included).
			find "$sysroot" -path '*/lib/*' 2>/dev/null -exec basename {} \;
		} | sort -u
	)

	# 3. For each ELF, check every DT_NEEDED is provided.
	local missing=0
	local f needs n
	for f in $elfs; do
		needs=$("$readelf" -d "$f" 2>/dev/null \
			| sed -n 's/.*(NEEDED).*\[\(.*\)\].*/\1/p')
		for n in $needs; do
			# Skip loader-provided pseudo-libraries.
			if [[ "$n" =~ $LOADER_PROVIDED ]]; then
				continue
			fi
			if ! grep -qxF "$n" <<< "$provided"; then
				printf 'MISSING: %-45s needs  %s\n' \
					"${f#"$sysroot"}" "$n" >&2
				missing=$((missing + 1))
			fi
		done
	done

	if [ "$missing" -gt 0 ]; then
		printf 'check_deps: %d unresolved shared-library dependency(ies) in %s\n' \
			"$missing" "${sysroot#"$SDKSRC_DIR"/}" >&2
		if [ "$strict" = "y" ]; then
			printf 'check_deps: FAILED (strict mode)\n' >&2
			exit 1
		fi
		printf 'check_deps: WARNING only (set ROOTFS_CHECK_DEPS_STRICT=y to fail the build)\n' >&2
	else
		printf 'check_deps: OK - all DT_NEEDED resolved in %s\n' \
			"${sysroot#"$SDKSRC_DIR"/}"
	fi
}

main "$@"
