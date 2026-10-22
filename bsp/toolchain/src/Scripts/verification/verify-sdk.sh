#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -Eeuo pipefail

# Usage:
#   Scripts/verify-sdk.sh --flavor hard|soft --sdk <env-setup file or SDK dir> [--workdir <dir>] [--keep-workdir]
#
# Example:
#   Scripts/verify-sdk.sh --flavor hard --sdk /path/to/sdk-hard
#   Scripts/verify-sdk.sh --flavor soft --sdk /path/to/sdk-soft --workdir /tmp/verify-soft --keep-workdir

FLAVOR=""
SDK_IN=""
WORKDIR=""
KEEP_WORKDIR=0
WORKDIR_AUTO=0

usage() {
    cat <<'EOF'
        Usage: verify-sdk.sh --flavor hard|soft --sdk <env-setup file or SDK dir> [--workdir <dir>] [--keep-workdir]

        Options:
        --flavor        hard | soft
        --sdk           SDK install directory OR environment-setup* file
        --workdir       Work directory for compilation/artifacts
        --keep-workdir  Keep generated files even on success
        -h, --help      Show this help
EOF
}

die() {
    echo "ERROR: $*" >&2
    exit 1
}

need_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "Missing command: $1"
}

cleanup() {
    local rc=$?
    if [[ $rc -ne 0 ]]; then
        echo
        echo "[FAIL] verify-sdk (${FLAVOR:-unknown}) failed with rc=$rc" >&2
        [[ -n "${WORKDIR:-}" ]] && echo "[INFO] workdir kept at: $WORKDIR" >&2
        exit "$rc"
    fi

    if [[ "${KEEP_WORKDIR:-0}" -eq 1 ]]; then
        echo "[INFO] workdir kept at: $WORKDIR"
    elif [[ "${WORKDIR_AUTO:-0}" -eq 1 && -n "${WORKDIR:-}" && -d "${WORKDIR:-}" ]]; then
        rm -rf "$WORKDIR"
    fi
}

trap cleanup EXIT

on_err() {
    local rc=$?
    local line="${1:-unknown}"
    echo "[ERROR] line $line failed (rc=$rc)" >&2
    return "$rc"
}

trap 'on_err $LINENO' ERR

require_arg() {
    local opt="$1"
    local val="${2:-}"
    [[ -n "$val" ]] || die "$opt requires a value"
}

while [[ $# -gt 0 ]]; do
    case "$1" in
    --flavor)
        require_arg "$1" "${2:-}"
        FLAVOR="$2"
        shift 2
        ;;
    --sdk)
        require_arg "$1" "${2:-}"
        SDK_IN="$2"
        shift 2
        ;;
    --workdir)
        require_arg "$1" "${2:-}"
        WORKDIR="$2"
        shift 2
        ;;
    --keep-workdir)
        KEEP_WORKDIR=1
        shift
        ;;
    -h|--help)
        usage
        exit 0
        ;;
    *)
        usage >&2
        die "Unknown arg: $1"
        ;;
    esac
done

[[ "$FLAVOR" == "hard" || "$FLAVOR" == "soft" ]] || die "--flavor must be hard or soft"
[[ -n "$SDK_IN" ]] || die "--sdk is required"

# Resolve env-setup file
SDK_ENV="$SDK_IN"
if [[ -d "$SDK_ENV" ]]; then
    ENV_FILE="$(find "$SDK_ENV" -maxdepth 1 -type f -name 'environment-setup*' | head -n1 || true)"
    [[ -n "${ENV_FILE:-}" ]] || die "no environment-setup* found in dir: $SDK_ENV"
    SDK_ENV="$ENV_FILE"
fi

if [[ "$SDK_ENV" != /* ]]; then
    SDK_ENV="$(cd "$(dirname "$SDK_ENV")" && pwd)/$(basename "$SDK_ENV")"
fi
[[ -f "$SDK_ENV" ]] || die "SDK env file not found: $SDK_ENV"

if [[ -z "$WORKDIR" ]]; then
    WORKDIR="$(mktemp -d /tmp/verify-sdk.XXXXXX)"
    WORKDIR_AUTO=1
else
    mkdir -p "$WORKDIR"
fi
cd "$WORKDIR"

need_cmd readelf
need_cmd file
need_cmd grep
need_cmd sed
need_cmd find
need_cmd head
need_cmd du

# Source SDK env safely (env scripts may reference unset vars, e.g. CCACHE_PATH)
NOUNSET_WAS_ON=0
case "$-" in
    *u*) NOUNSET_WAS_ON=1 ;;
esac
set +u
# shellcheck disable=SC1090
source "$SDK_ENV"
if [[ "$NOUNSET_WAS_ON" -eq 1 ]]; then
    set -u
fi

: "${CC:?CC not set}"
: "${CXX:?CXX not set}"
: "${TARGET_PREFIX:?TARGET_PREFIX not set}"
: "${SDKTARGETSYSROOT:?SDKTARGETSYSROOT not set}"

# Wrap CC/CXX (they are strings with flags from environment-setup)
read -r -a CC_ARR <<< "$CC"
read -r -a CXX_ARR <<< "$CXX"
cc()  { "${CC_ARR[@]}" "$@"; }
cxx() { "${CXX_ARR[@]}" "$@"; }

run_readelf_ws() {
    local f="$1"
    readelf -Ws "$f" 2>/dev/null || true
}

has_text() {
    local haystack="$1"
    local needle="$2"
    [[ "$haystack" == *"$needle"* ]]
}

has_sym() {
    local f="$1"
    local sym="$2"
    local out
    out="$(run_readelf_ws "$f")"
    has_text "$out" "$sym"
}

print_header() {
    echo "=== $* ==="
}

capture_macros() {
    # Capture once; avoids grep -q + pipefail SIGPIPE false negative.
    echo | cc -dM -E - 2>/dev/null || true
}

capture_target_help() {
    cc -Q --help=target 2>/dev/null || true
}

print_header "Flavor"
echo "FLAVOR=$FLAVOR"
echo

print_header "SDK env"
echo "SDK_ENV=$SDK_ENV"
echo "WORKDIR=$WORKDIR"
echo

print_header "Toolchain"
echo "CC  = $CC"
echo "CXX = $CXX"
echo

print_header "gcc identity"
cc -v 2>&1 || true
echo

print_header "ISL/Graphite (host) check"

# (A) Check configure line hints (best-effort)
CONF_WITH="$(cc -v 2>&1 | sed -n '/^Configured with:/p' | head -n1 || true)"
if has_text "$CONF_WITH" "--without-isl"; then
    echo "WARN: gcc configured with --without-isl (Graphite expected to be unavailable)"
elif has_text "$CONF_WITH" "--with-isl="; then
    echo "OK: gcc configured with --with-isl=..."
else
    echo "WARN: could not detect --with-isl/--without-isl in configure line"
fi

# (B) Check cc1 runtime deps (best-effort)
CC1_PATH="$(cc -print-prog-name=cc1 2>/dev/null || true)"
if [[ -n "$CC1_PATH" && -e "$CC1_PATH" ]] && command -v ldd >/dev/null 2>&1; then
    LDD_OUT="$(ldd "$CC1_PATH" 2>/dev/null || true)"
    if has_text "$LDD_OUT" "libisl.so"; then
        echo "OK: cc1 links with libisl (ldd shows libisl.so.*)"
    else
        echo "INFO: cc1 does not show libisl in ldd (may be static, or Graphite still can work)"
    fi
else
    echo "INFO: cannot check cc1 ldd (cc1 missing or ldd not available)"
fi

# (C) Real functional test: compile with graphite enabled and demand a graphite dump
cat > graphite_isl.c <<'EOF'
int foo(int *a, int n) { int s = 0; for (int i = 0; i < n; i++) s += a[i]; return s; }
EOF

GRAPHITE_LOG="$WORKDIR/graphite_isl.log"
set +e
cc -O2 -fgraphite-identity -fdump-tree-graphite-all -c graphite_isl.c -o graphite_isl.o 2>"$GRAPHITE_LOG"
RC=$?
set -e

if [[ $RC -ne 0 ]]; then
    echo "FAIL: graphite compile failed (rc=$RC). Log:"
    sed -n '1,120p' "$GRAPHITE_LOG" >&2 || true
    exit 30
fi

GRAPHITE_LOG_TXT="$(cat "$GRAPHITE_LOG" 2>/dev/null || true)"
if has_text "$GRAPHITE_LOG_TXT" "Graphite loop optimizations cannot be used" || \
    has_text "$GRAPHITE_LOG_TXT" "isl is not available"; then
    echo "FAIL: Graphite/ISL not available in this gcc. Log:"
    sed -n '1,120p' "$GRAPHITE_LOG" >&2 || true
    exit 31
fi

shopt -s nullglob
GRAPHITE_DUMPS=(graphite_isl.c.*.graphite graphite_isl.*.graphite)
shopt -u nullglob
if [[ ${#GRAPHITE_DUMPS[@]} -eq 0 ]]; then
    echo "FAIL: expected graphite dump not found (graphite_isl*.graphite)."
    echo "      (Compiler ran but did not emit graphite dump; investigate -fdump-tree-graphite-all behavior.)" >&2
    exit 32
fi

echo "OK: Graphite dump generated: ${GRAPHITE_DUMPS[0]}"
rm -f "$GRAPHITE_LOG" graphite_isl.o "${GRAPHITE_DUMPS[@]}" graphite_isl.c
echo

print_header "sysroot / libgcc"
SYSROOT_FROM_CC="$(cc --print-sysroot)"
echo "sysroot: $SYSROOT_FROM_CC"
echo "libgcc : $(cc -print-libgcc-file-name)"
echo "eh     : $(cc -print-file-name=libgcc_eh.a)"
echo

ABI_MACROS="$(capture_macros)"
TARGET_HELP="$(capture_target_help)"

print_header "float ABI macros"
printf '%s\n' "$ABI_MACROS" | grep -E '__SOFTFP__|__ARM_PCS_VFP|__ARM_FP' || true
echo

print_header "effective target defaults (-Q --help=target)"
printf '%s\n' "$TARGET_HELP" | grep -E '^[[:space:]]*-mfloat-abi=|^[[:space:]]*-mfpu=' || true
echo

if [[ "$FLAVOR" == "hard" ]]; then
    if has_text "$ABI_MACROS" "__ARM_PCS_VFP"; then
        echo "OK: ABI macro indicates hard-float (__ARM_PCS_VFP present)"
    else
        echo "FAIL: expected hard-float (__ARM_PCS_VFP missing)" >&2
        exit 10
    fi
else
    if has_text "$ABI_MACROS" "__ARM_PCS_VFP"; then
        echo "FAIL: expected soft-float (but __ARM_PCS_VFP present)" >&2
        exit 11
    else
        echo "OK: ABI macro indicates non-hard-float (__ARM_PCS_VFP absent)"
    fi
fi
echo

# ---- hello build tests ----
    cat > hello.c <<'EOF'
#include <stdio.h>
#include <math.h>
#include <pthread.h>
    int main() {
        printf("hi %f\n", sin(0.5));
        pthread_t t;
        (void)t;
        return 0;
    }
EOF

print_header "build hello.c (-lm -lpthread)"
cc -O2 -Wall -Wextra hello.c -o hello_c -lm -lpthread
file hello_c
echo

cat > hello.cpp <<'EOF'
#include <iostream>
#include <cmath>
#include <pthread.h>
int main() {
    std::cout << "hi " << std::sin(0.5) << std::endl;
    pthread_t t;
    (void)t;
    return 0;
}
EOF

print_header "build hello.cpp (-lm -lpthread)"
cxx -O2 -Wall -Wextra hello.cpp -o hello_cpp -lm -lpthread
file hello_cpp
echo

# ---- FPU assembly sanity ----
cat > fpucheck.c <<'EOF'
float add(float a, float b) { return a + b; }
EOF
cc -S -o hello_fpu.s fpucheck.c

if [[ "$FLAVOR" == "hard" ]]; then
    print_header "extra check: VFP/NEON mnemonics should appear (rough sanity)"
    if grep -E '\b(vadd|vsub|vmul|vdiv|vmla|vmls)\b' hello_fpu.s >/dev/null 2>&1; then
        echo "OK: found VFP/NEON mnemonics in hello_fpu.s (expected for hard-float)"
    else
        echo "WARN: no obvious v* FP mnemonics found; check hello_fpu.s and toolchain flags"
    fi
else
    print_header "extra check: no VFP/NEON mnemonics (rough sanity)"
    if grep -E '\b(vadd|vsub|vmul|vdiv|vmla|vmls|vfp|neon)\b' hello_fpu.s >/dev/null 2>&1; then
        echo "WARN: found possible VFP/NEON mnemonics in assembly (check hello_fpu.s)"
    else
        echo "OK: no obvious VFP/NEON mnemonics in hello_fpu.s"
    fi
fi
echo

# ---- string.h compile + ELF checks ----
cat > string_test.c <<'EOF'
#include <string.h>
#include <stdint.h>
#include <stdio.h>

static int test_memmove_overlap(void) {
    unsigned char a[32];
    for (int i=0;i<32;i++) a[i] = (unsigned char)i;
    memmove(a+4, a, 16); /* overlap */
    return (a[4] == 0 && a[5] == 1 && a[19] == 15) ? 0 : 1;
}

int main(void) {
    unsigned char a[64], b[64];
    memset(a, 0x11, sizeof(a));
    memset(b, 0x00, sizeof(b));
    memcpy(b, a, 32);
    if (b[0] != 0x11) return 2;
    if (strcmp("abc","abc") != 0) return 3;
    if (strlen("abc") != 3) return 4;
    if (test_memmove_overlap() != 0) return 5;
    puts("string_test ok");
    return 0;
}
EOF

print_header "build string_test.c"
cc -O2 -Wall -Wextra string_test.c -o string_test
file string_test
echo

print_header "ELF interpreter / NEEDED"
readelf -Wl string_test | grep -E 'Requesting program interpreter|interpreter|NEEDED' || true
echo

print_header "memcpy/memmove/memset symbols in libc"
LIBC="$SDKTARGETSYSROOT/lib/libc.so.0"
if [[ -e "$LIBC" ]]; then
    ls -l "$LIBC"
    run_readelf_ws "$LIBC" | grep -E ' memcpy$| memmove$| memset$| strlen$| strcmp$' | head -n 30 || true
else
    echo "WARN: libc.so.0 not found at $LIBC"
fi
echo

print_header "_Unwind_Resume in libgcc_s"
LIBGCCS="$(cc -print-file-name=libgcc_s.so.1 || true)"
if [[ -n "$LIBGCCS" && -e "$LIBGCCS" ]]; then
    LIBGCCS_SYMS="$(run_readelf_ws "$LIBGCCS")"
    if has_text "$LIBGCCS_SYMS" "_Unwind_Resume"; then
        echo "OK: _Unwind_Resume found in libgcc_s"
    else
        echo "FAIL: _Unwind_Resume not found in libgcc_s" >&2
        exit 12
    fi
else
    echo "WARN: libgcc_s.so.1 not found via compiler query"
fi
echo

print_header "SSP check (-fstack-protector-strong)"

cat > ssp.c <<'EOF'
#include <string.h>
int f(const char *s) {
    char buf[16];
    strcpy(buf, s);
    return buf[0];
}
int main(int argc, char **argv) { return f(argc > 1 ? argv[1] : "x"); }
EOF

cc -O2 -fstack-protector-strong ssp.c -o ssp_test
file ssp_test

echo "[ssp] symbols in ssp_test"
run_readelf_ws ssp_test | grep __stack_chk || true

if has_sym ssp_test "__stack_chk_guard"; then
    echo "OK: __stack_chk_guard present in ssp_test"
else
    echo "FAIL: __stack_chk_guard missing from ssp_test" >&2
exit 20
fi

LD_UCLIBC="$SDKTARGETSYSROOT/lib/ld-uClibc.so.0"
if [[ -e "$LD_UCLIBC" ]]; then
    if has_sym "$LD_UCLIBC" "__stack_chk_guard"; then
        echo "OK: __stack_chk_guard exported by ld-uClibc.so.0"
    else
        echo "FAIL: ld-uClibc.so.0 does not export __stack_chk_guard" >&2
        exit 21
    fi
else
    echo "WARN: loader not found at $LD_UCLIBC (layout may differ)"
fi

LIBC0="$SDKTARGETSYSROOT/lib/libc.so.0"
REAL_LIBC=""
if command -v readlink >/dev/null 2>&1; then
    REAL_LIBC="$(readlink -f "$LIBC0" 2>/dev/null || true)"
fi

if [[ -e "$LIBC0" ]] && has_sym "$LIBC0" "__stack_chk_fail"; then
    echo "OK: __stack_chk_fail provided by libc.so.0"
elif [[ -n "$REAL_LIBC" && -e "$REAL_LIBC" ]] && has_sym "$REAL_LIBC" "__stack_chk_fail"; then
    echo "OK: __stack_chk_fail provided by: $REAL_LIBC"
else
    echo "FAIL: could not find __stack_chk_fail in libc (libc.so.0 or resolved target)" >&2
    echo "[debug] libc.so.0 = $LIBC0" >&2
    echo "[debug] real libc  = ${REAL_LIBC:-<none>}" >&2
    echo "[debug] libc readelf lines:" >&2
    run_readelf_ws "$LIBC0" | grep __stack_chk >&2 || true
    exit 22
fi

echo "OK: SSP check passed"
echo

print_header "ABI summary"
if has_text "$ABI_MACROS" "__ARM_PCS_VFP"; then
    echo "ABI: hard-float (AAPCS VFP)"
else
    echo "ABI: soft-float (AAPCS)"
fi

if has_text "$ABI_MACROS" "__SOFTFP__"; then
    echo "__SOFTFP__: yes"
else
    echo "__SOFTFP__: no"
fi
echo

SYS="$(cc --print-sysroot)"
echo "sysroot=$SYS"

print_header "Check runtime lib has removed"
find "$SYS" -maxdepth 5 -type f \( \
    -name 'libgomp*.so*' -o \
    -name 'libquadmath*.so*' -o \
    -name 'libasan*.so*' -o \
    -name 'libubsan*.so*' -o \
    -name 'libtsan*.so*' -o \
    -name 'liblsan*.so*' -o \
    -name 'libmpx*.so*' \
\) -print
echo

print_header "libgomp runtime?"
find "$SYS" -type f \( -name 'libgomp.so*' -o -name 'libgomp.a' \) -print
echo

print_header "libgomp debug only?"
find "$SYS" -type f -path '*/.debug/*' -name 'libgomp.so*' -print
echo

print_header "Check /lib & /usr/lib size"
du -sh "$SYS"/lib* "$SYS"/usr/lib* 2>/dev/null | sort -h
echo

print_header "Check debug section"
file "$SYS"/usr/lib*/libstdc++.so* 2>/dev/null | head
readelf -S "$SYS"/usr/lib*/libstdc++.so* 2>/dev/null | grep -Ei '\.debug|\.symtab' | head -n 30 || true
echo
echo "=== Size regression check ==="

# Enable/disable (default enabled)
: "${VERIFY_SIZE:=1}"

# Thresholds (hex). Tune if you intentionally change features/flags.
: "${MAX_TEXT_UCLIBC:=0x50000}"
: "${MAX_TEXT_LIBSTDCXX:=0x60000}"

if [[ "$VERIFY_SIZE" == "1" ]]; then
    # 1) Assert __UCLIBC_EXTRA_CFLAGS__ == ""
    UCLIBC_CFG_H="$SDKTARGETSYSROOT/usr/include/bits/uClibc_config.h"
    if [[ ! -f "$UCLIBC_CFG_H" ]]; then
        echo "FAIL: missing uClibc config header: $UCLIBC_CFG_H" >&2
        exit 60
    fi

    if grep -qE '^#define[[:space:]]+__UCLIBC_EXTRA_CFLAGS__[[:space:]]+""$' "$UCLIBC_CFG_H"; then
        echo "OK: __UCLIBC_EXTRA_CFLAGS__ == \"\""
    else
        got="$(grep -E '^#define[[:space:]]+__UCLIBC_EXTRA_CFLAGS__' "$UCLIBC_CFG_H" || true)"
        echo "FAIL: __UCLIBC_EXTRA_CFLAGS__ is not empty: ${got:-<missing define>}" >&2
        exit 60
    fi

find_in_sysroot() {
    local sys="$1" name="$2"
    local p
    p="$(find "$sys" -maxdepth 6 -type f -name "$name" 2>/dev/null | head -n1 || true)"
    [[ -n "$p" ]] && { echo "$p"; return 0; }
    return 1
}

get_text_size_hex() {
    local so="$1"
    # Robust against "[ 9]" vs "[12]" formatting.
    # Use -W to avoid line wrapping; silence .gnu_debuglink CRC warnings.
    readelf -SW "$so" 2>/dev/null | awk '
    $2==".text" {print $6; exit}  # e.g. [12] .text PROGBITS ADDR OFF SIZE ...
    $3==".text" {print $7; exit}  # e.g. [ 9] .text PROGBITS ADDR OFF SIZE ...
    '
}

check_text_le() {
    local label="$1" so="$2" max_hex="$3"
    local size_hex size_dec max_dec

    size_hex="$(get_text_size_hex "$so")"
    if [[ -z "$size_hex" ]]; then
        echo "FAIL: could not parse .text size from: $so" >&2
        exit 61
    fi

    size_dec=$((16#${size_hex}))
    max_dec=$((max_hex))

    if (( size_dec > max_dec )); then
        echo "FAIL: ${label} .text too large: 0x${size_hex} > ${max_hex} (file: $so)" >&2
        exit 61
    fi
    echo "OK: ${label} .text=0x${size_hex} <= ${max_hex}"
}

# 2) .text segment upper-bound checks
LIB_UCLIBC="$SYS/lib/libuClibc-1.0.38.so"
if [[ ! -e "$LIB_UCLIBC" ]]; then
    LIB_UCLIBC="$(find_in_sysroot "$SYS" 'libuClibc-1.0.38.so' || true)"
fi
if [[ -z "${LIB_UCLIBC:-}" || ! -e "$LIB_UCLIBC" ]]; then
    echo "FAIL: cannot find libuClibc-1.0.38.so under sysroot: $SYS" >&2
    exit 63
fi

LIB_STDCXX="$SYS/usr/lib/libstdc++.so.6.0.28"
if [[ ! -e "$LIB_STDCXX" ]]; then
    LIB_STDCXX="$(find_in_sysroot "$SYS" 'libstdc++.so.6.0.28' || true)"
fi
if [[ -z "${LIB_STDCXX:-}" || ! -e "$LIB_STDCXX" ]]; then
    echo "FAIL: cannot find libstdc++.so.6.0.28 under sysroot: $SYS" >&2
    exit 63
fi

check_text_le "libuClibc-1.0.38.so" "$LIB_UCLIBC"  "$MAX_TEXT_UCLIBC"
check_text_le "libstdc++.so.6.0.28" "$LIB_STDCXX"  "$MAX_TEXT_LIBSTDCXX"
else
    # VERIFY_SIZE = 0
    echo "INFO: size regression check disabled (VERIFY_SIZE=$VERIFY_SIZE)"
fi


echo "[PASS] verify-sdk ($FLAVOR) completed."

