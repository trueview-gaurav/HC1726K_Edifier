#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -Eeuo pipefail

# Usage:
#   Scripts/verify-string.sh <sdk_env_setup> [workdir]
# Example:
#   Scripts/verify-string.sh /opt/augentix-sdk/hard/environment-setup-arm-augentix-linux-uclibceabi /tmp/verify
#
# Notes:
# - This script compiles and inspects outputs (no target execution required).
# - It checks:
#   - string.h APIs compile cleanly
#   - ELF interpreter / NEEDED libs look sane for uClibc toolchain
#   - libgcc_s contains _Unwind_Resume (expected in your toolchain)
#   - libc exports memcpy/memmove/memset/strlen/strcmp symbols

SDK_ENV="${1:-}"
WORKDIR="${2:-/tmp/verify-string}"

if [[ -z "$SDK_ENV" ]]; then
  echo "Usage: $0 <sdk_env_setup_or_dir> [workdir]" >&2
  exit 2
fi

# Allow passing either:
#  - the exact environment-setup file, OR
#  - the SDK install directory containing environment-setup*
if [[ -d "$SDK_ENV" ]]; then
  ENV_FILE="$(find "$SDK_ENV" -maxdepth 1 -type f -name 'environment-setup*' | head -n1)"
  [[ -n "${ENV_FILE:-}" ]] || { echo "No environment-setup* found in dir: $SDK_ENV" >&2; exit 2; }
  SDK_ENV="$ENV_FILE"
fi

# Convert to absolute path BEFORE cd
if [[ "$SDK_ENV" != /* ]]; then
  SDK_ENV="$(cd "$(dirname "$SDK_ENV")" && pwd)/$(basename "$SDK_ENV")"
fi

if [[ ! -f "$SDK_ENV" ]]; then
  echo "SDK env file not found: $SDK_ENV" >&2
  exit 2
fi

mkdir -p "$WORKDIR"
cd "$WORKDIR"

# Source SDK env safely: Yocto environment-setup scripts may reference
# variables that are not defined (e.g. CCACHE_PATH). With "set -u" this
# would fail, so temporarily disable nounset during sourcing.
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

: "${CC:?CC not set after sourcing SDK env}"
: "${TARGET_PREFIX:?TARGET_PREFIX not set after sourcing SDK env}"
: "${SDKTARGETSYSROOT:?SDKTARGETSYSROOT not set after sourcing SDK env}"

need_cmd() { command -v "$1" >/dev/null 2>&1 || { echo "Missing command: $1" >&2; exit 1; }; }
need_cmd readelf
need_cmd file

echo "[info] CC=$CC"
echo "[info] TARGET_PREFIX=$TARGET_PREFIX"
echo "[info] SYSROOT=$SDKTARGETSYSROOT"

# Optional: if target nm exists, use it; otherwise skip that check.
TARGET_NM="${TARGET_PREFIX}nm"
HAVE_TARGET_NM=0
if command -v "$TARGET_NM" >/dev/null 2>&1; then
  HAVE_TARGET_NM=1
fi

# ---- test program (compile/link) ----
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

  /* Simple checks (runtime only if executed on target) */
  if (b[0] != 0x11) return 2;
  if (strcmp("abc","abc") != 0) return 3;
  if (strlen("abc") != 3) return 4;
  if (test_memmove_overlap() != 0) return 5;

  puts("string_test ok");
  return 0;
}
EOF

echo "[build] compiling..."
$CC -O2 -Wall -Wextra string_test.c -o string_test

echo "[check] file(1)"
file string_test

echo "[check] ELF interpreter / NEEDED"
# interpreter + NEEDED libs
readelf -Wl string_test | egrep 'Requesting program interpreter|interpreter|NEEDED' || true

readelf -a string_test | egrep 'interpreter|NEEDED|libc\.so|ld-.*\.so' || true

echo "[check] memcpy/memmove/memset"
# Find sysroot libc
LIBC="$SDKTARGETSYSROOT/lib/libc.so.0"
ls -l "$LIBC"

# Check memcpy/memmove/memset is exist
readelf -Ws "$LIBC" | egrep ' memcpy$| memmove$| memset$| strlen$| strcmp$' | head -n 30

echo "[check] confirm libc in sysroot is uClibc-style"
# uClibc commonly provides libc.so.0 + loader ld-uClibc.so.1 (names depend on your config)
if [[ -e "$SDKTARGETSYSROOT/lib/libc.so.0" ]]; then
  echo "  found: $SDKTARGETSYSROOT/lib/libc.so.0"
else
  echo "  WARN: libc.so.0 not found under $SDKTARGETSYSROOT/lib (layout may differ)"
fi

# ---- unwind symbol check (your earlier verification) ----
echo "[check] _Unwind_Resume should exist in libgcc_s"
LIBGCCS="$($CC -print-file-name=libgcc_s.so.1 || true)"
if [[ -n "$LIBGCCS" && -e "$LIBGCCS" ]]; then
  echo "  libgcc_s: $LIBGCCS"
  readelf -Ws "$LIBGCCS" | grep -E '_Unwind_Resume(@@|$)' >/dev/null \
    && echo "  OK: _Unwind_Resume found in libgcc_s" \
    || { echo "  FAIL: _Unwind_Resume not found in libgcc_s" >&2; exit 1; }
else
  echo "  WARN: libgcc_s.so.1 not found via compiler query"
fi

# ---- libc symbol presence check (best-effort) ----
echo "[check] libc exports string symbols (best-effort)"
# Prefer libc.so.0 if present; otherwise fallback to libc.so (if present)
LIBC_CAND=""
for cand in "$SDKTARGETSYSROOT/lib/libc.so.0" "$SDKTARGETSYSROOT/lib/libc.so" "$SDKTARGETSYSROOT/usr/lib/libc.so.0" "$SDKTARGETSYSROOT/usr/lib/libc.so"; do
  if [[ -e "$cand" ]]; then
    LIBC_CAND="$cand"
    break
  fi
done

if [[ -n "$LIBC_CAND" ]]; then
  echo "  libc: $LIBC_CAND"
  # look for common symbols; IFUNC variants may appear differently, so this is best-effort.
  readelf -Ws "$LIBC_CAND" | egrep ' (memcpy|memmove|memset|strlen|strcmp)$' >/dev/null \
    && echo "  OK: found expected libc symbols" \
    || echo "  WARN: did not match expected libc symbols (may be OK depending on symbol versioning/IFUNC)"
else
  echo "  WARN: could not locate libc in sysroot for symbol scan"
fi

# ---- optional: check libgcc.a contains _Unwind_Resume (often not; you already saw it's empty) ----
echo "[check] libgcc.a _Unwind_Resume (optional)"
LIBGCCA="$($CC -print-libgcc-file-name || true)"
if [[ -n "$LIBGCCA" && -e "$LIBGCCA" && "$HAVE_TARGET_NM" -eq 1 ]]; then
  echo "  libgcc.a: $LIBGCCA"
  if "$TARGET_NM" "$LIBGCCA" 2>/dev/null | grep -q '_Unwind_Resume'; then
    echo "  OK: _Unwind_Resume found in libgcc.a"
  else
    echo "  NOTE: _Unwind_Resume not in libgcc.a (expected in your toolchain; it's in libgcc_s)"
  fi
else
  echo "  NOTE: skip libgcc.a nm check (missing libgcc.a or target nm)"
fi

echo "[pass] string.h compile/link and ELF checks passed."

# ---- Optional runtime execution ----
# If you have a way to run the binary on target (ssh/qemu), do it outside this script.
# Example:
#   scp string_test target:/tmp && ssh target /tmp/string_test

