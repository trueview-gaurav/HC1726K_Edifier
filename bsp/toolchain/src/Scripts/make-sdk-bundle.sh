#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -Eeuo pipefail

usage() {
    cat >&2 <<'EOF'
Usage:
  make-sdk-bundle.sh <artifacts_dir> <ARCH_DIR>

Example:
  make-sdk-bundle.sh artifacts/20260304T163408Z/hard Bread_Toolchain_Hard
  make-sdk-bundle.sh artifacts/20260304T163408Z/soft Bread_Toolchain_Soft
EOF
    exit 1
}

[[ $# -eq 2 ]] || usage

ARTIFACTS_DIR=$1
ARCH_DIR=$2

SDK_INSTALLER="${ARTIFACTS_DIR}/sdk-installer.sh"
[[ -f "${SDK_INSTALLER}" ]] || {
    echo "ERROR: sdk-installer.sh not found: ${SDK_INSTALLER}" >&2
    exit 1
}

OUT_NAME="yocto-${ARCH_DIR}.tar.xz"
WORKDIR=$(mktemp -d)
trap 'rm -rf "${WORKDIR}"' EXIT

BUNDLE_ROOT="${WORKDIR}/${ARCH_DIR}"
mkdir -p "${BUNDLE_ROOT}"

cp -a "${SDK_INSTALLER}" "${BUNDLE_ROOT}/sdk-installer.sh"
chmod +x "${BUNDLE_ROOT}/sdk-installer.sh"


cat > "${BUNDLE_ROOT}/install.sh" <<'OUTER'
#!/usr/bin/env bash
set -Eeuo pipefail

SELF_DIR="$(cd "$(dirname "$0")" && pwd)"
SDK_DIR="${SELF_DIR}/sdk"
WRAPPER_DIR="${SELF_DIR}/bin"
WRAPPER_COMMON="${SELF_DIR}/.bundle/wrapper-common.sh"
SDK_INSTALLER="${SELF_DIR}/sdk-installer.sh"

if [[ ! -x "${SDK_INSTALLER}" ]]; then
    echo "ERROR: sdk-installer.sh not found or not executable: ${SDK_INSTALLER}" >&2
    exit 1
fi

mkdir -p "${SDK_DIR}"

echo "[1/4] Installing SDK to: ${SDK_DIR}"
"${SDK_INSTALLER}" -d "${SDK_DIR}" -y

echo "[2/4] Detecting target triplet and sysroots"
shopt -s nullglob
env_files=( "${SDK_DIR}"/environment-setup-* )
shopt -u nullglob

if [[ ${#env_files[@]} -ne 1 ]]; then
    echo "ERROR: expected exactly one environment-setup-* under ${SDK_DIR}, found ${#env_files[@]}" >&2
    exit 1
fi

echo "environment : ${env_files}"

# Source SDK env safely (disable nounset temporarily)
NOUNSET_WAS_ON=0
case "$-" in *u*) NOUNSET_WAS_ON=1 ;; esac
set +u
# shellcheck disable=SC1090
source "$env_files"
if [[ "$NOUNSET_WAS_ON" -eq 1 ]]; then set -u; fi

REAL_PREFIX="${TARGET_PREFIX%-}"
REAL_SYSROOT="${SDKTARGETSYSROOT}"

TARGET_SYSROOT_NAME="${env_files[0]##*/environment-setup-}"

if [[ ! -d "${SDK_DIR}/sysroots/${TARGET_SYSROOT_NAME}" ]]; then
    echo "ERROR: target sysroot not found: ${SDK_DIR}/sysroots/${TARGET_SYSROOT_NAME}" >&2
    exit 1
fi

HOST_SYSROOT_NAME=""
for d in "${SDK_DIR}"/sysroots/*; do
    [[ -d "$d" ]] || continue
    base="$(basename "$d")"
    if [[ "$base" != "${TARGET_SYSROOT_NAME}" ]]; then
        HOST_SYSROOT_NAME="$base"
        break
    fi
done

if [[ -z "${HOST_SYSROOT_NAME}" ]]; then
    echo "ERROR: host sysroot not found under ${SDK_DIR}/sysroots" >&2
    exit 1
fi

HOST_USRBIN="${SDK_DIR}/sysroots/${HOST_SYSROOT_NAME}/usr/bin"

TARGET_BINDIR="${HOST_USRBIN}/${REAL_PREFIX}"

if [[ -z "${TARGET_BINDIR}" ]]; then
    echo "ERROR: target tool directory not found under ${HOST_USRBIN}" >&2
    exit 1
fi

WRAP_PREFIX="$(basename "${SELF_DIR}")"

echo "    target sysroot : ${TARGET_SYSROOT_NAME}"
echo "    host sysroot   : ${HOST_SYSROOT_NAME}"
echo "    wrap triplet   : ${WRAP_PREFIX}"
echo "    target bin     : ${TARGET_BINDIR}"

echo "[3/4] Creating sysroot symlink"
mkdir -p "${SELF_DIR}/${WRAP_PREFIX}"
ln -sfn "../sdk/sysroots/${TARGET_SYSROOT_NAME}" "${SELF_DIR}/${WRAP_PREFIX}/sysroot"

echo "[4/4] Creating wrappers"
mkdir -p "${WRAPPER_DIR}"

find "${WRAPPER_DIR}" -maxdepth 1 \( -type f -o -type l \) -name "${WRAP_PREFIX}-*" -delete

write_wrapper() {
	local out="$1"
	local real="$2"
	local tool="$3"
        case "${tool}" in *gcc|*g++)
            cmd="exec \"$real\" -muclibc --sysroot="${REAL_SYSROOT}" \"\$@\""
            ;;
        *cpp)      
            cmd="exec \"$real\" -E -muclibc --sysroot="${REAL_SYSROOT}" \"\$@\""
            ;;
        *ld)
            cmd="exec \"$real\" --sysroot="${REAL_SYSROOT}" \"\$@\""
            ;;
        *)
            cmd="exec \"$real\" \"\$@\""
	    ;;
        esac
	cat > "$out" <<EOF
#!/bin/sh
$cmd
EOF
chmod +x "$out"
}

REAL_GCC="$(command -v ${REAL_PREFIX}-gcc)"
created=0
for f in "${TARGET_BINDIR}/${REAL_PREFIX}"-*; do
    [[ -e "$f" ]] || continue
    realtool="$(basename "$f")"
    tool="${realtool#$TARGET_PREFIX}"
    if [[ "$tool" == "cpp" ]]; then
        write_wrapper "${WRAPPER_DIR}/${WRAP_PREFIX}-${tool}" "$REAL_GCC" "$tool"
    else
        write_wrapper "${WRAPPER_DIR}/${WRAP_PREFIX}-${tool}" "$f" "$tool"
    fi
    created=$((created + 1))
done

if [[ ${created} -eq 0 ]]; then
    echo "ERROR: no tools found under ${TARGET_BINDIR}" >&2
    exit 1
fi

echo
echo "Done."
echo "SDK installed at : ${SDK_DIR}"
echo "Wrappers at      : ${WRAPPER_DIR}"
echo "Target sysroot   : ${SELF_DIR}/${WRAP_PREFIX}/sysroot"
echo
echo "Example:"
echo "  export PATH=\"${WRAPPER_DIR}:\$PATH\""
echo "  ${WRAP_PREFIX}-gcc --version"
OUTER
chmod +x "${BUNDLE_ROOT}/install.sh"

tar -C "${WORKDIR}" -cJf "${OUT_NAME}" "${ARCH_DIR}"
echo "Created: ${OUT_NAME}"

