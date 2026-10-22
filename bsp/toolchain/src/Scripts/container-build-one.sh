#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -Eeo pipefail   # NOTE: no -u (oe-init-build-env not nounset-safe)

flavor="$1"       # hard|soft
release_id="$2"   # artifacts subdir
init_conf="${3:-0}"
force_conf="${4:-0}"
no_logs="${5:-0}" # 1 => do not store logs on success (release mode)

# Determine repo root from script location (works on host or in Docker)
work="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# Basic sanity checks (fail fast with a clear message)
[[ -d "$work/Sources/poky" ]] || { echo "ERROR: missing $work/Sources/poky" >&2; exit 1; }
[[ -d "$work/Sources/meta-qti-ipcam-toolchains" ]] || { echo "ERROR: missing $work/Sources/meta-qti-ipcam-toolchains" >&2; exit 1; }

builddir="$work/build-$flavor"
tmpl="$work/Scripts/templates/build-$flavor"
out="$work/artifacts/$release_id/$flavor"

logs="$out/logs"
confshot="$out/conf-snapshot"

mkdir -p "$confshot"

# Timestamp string for filenames
ts="$(date -u +"%Y%m%dT%H%M%SZ")"

# Timestamp for this run
date -u +"%Y-%m-%dT%H:%M:%SZ" > "$out/build-timestamp-utc.txt"

# Ensure builddir/conf exists
source "$work/Sources/poky/oe-init-build-env" "$builddir" >/dev/null

stamp="$builddir/conf/.templates_applied"

# Apply templates (optional)
apply_templates() {
  [[ -d "$tmpl" ]] || { echo "Template dir not found: $tmpl" >&2; exit 1; }
  echo "[container][$flavor] apply local.conf (template)"
  cp -f "$tmpl/local.conf" "$builddir/conf/local.conf"
  echo "[container][$flavor] apply bblayers.conf (template)"
  cp -f "$tmpl/bblayers.conf" "$builddir/conf/bblayers.conf"
  date -u +"%Y-%m-%dT%H:%M:%SZ" > "$stamp"
}

if [[ "$force_conf" -eq 1 ]]; then
  # Always overwrite when forced
  apply_templates
elif [[ "$init_conf" -eq 1 ]]; then
  # Apply only once (or when stamp is missing)
  if [[ -f "$stamp" ]]; then
    echo "[container][$flavor] templates already applied ($(cat "$stamp")); skipping (use --force-conf to overwrite)"
  else
    apply_templates
  fi
fi

# Snapshot conf used by this build (always)
cp -f "$builddir/conf/local.conf" "$confshot/local.conf"
cp -f "$builddir/conf/bblayers.conf" "$confshot/bblayers.conf"
# Optional: site.conf if you use it
[[ -f "$builddir/conf/site.conf" ]] && cp -f "$builddir/conf/site.conf" "$confshot/site.conf" || true

# Record command line
echo "bitbake meta-toolchain -c populate_sdk" > "$out/command.txt"

# Build with log capture WITHOUT breaking TTY progress
echo "[container][$flavor] bitbake meta-toolchain -c populate_sdk"

bb_log="$logs/bitbake-meta-toolchain-${flavor}-${ts}.log"
bb_exit=0

if [[ "$no_logs" -eq 1 ]]; then
  # Release mode: do not create log files on success.
  bitbake meta-toolchain -c populate_sdk || bb_exit=$?
else
  mkdir -p "$logs"
  bb_log="$logs/bitbake-meta-toolchain-${flavor}-${ts}.log"

  # Prefer bitbake builtin logfile option if available
  if bitbake -h 2>&1 | grep -qE -- '--logfile| -l '; then
    bitbake -l "$bb_log" meta-toolchain -c populate_sdk || bb_exit=$?
  else
    # Fallback: use "script" to record terminal session (keeps TTY-like behavior)
    if command -v script >/dev/null 2>&1; then
      script -q -f -c "bitbake meta-toolchain -c populate_sdk" "$bb_log" || bb_exit=$?
    else
      # Last resort: pipe (will be noisy / no progress bar)
      bitbake meta-toolchain -c populate_sdk 2>&1 | tee "$bb_log" || bb_exit=$?
    fi
  fi
fi

if [[ "$bb_exit" -ne 0 ]]; then
  echo "[container][$flavor] bitbake failed (exit=$bb_exit). Collecting logs..." >&2
fi

# Collect cooker / error report logs (compressed to keep artifacts reasonable)
# Paths vary slightly; handle both common locations safely.
tmpdir="$builddir/tmp"

if [[ "$bb_exit" -ne 0 || "$no_logs" -eq 0 ]]; then
  mkdir -p "$logs"

  # 1) cooker logs
  if [[ -d "$tmpdir/log/cooker" ]]; then
    tar -C "$tmpdir/log" -czf "$logs/cooker-logs.tar.gz" cooker
  fi

  # 2) error report
  if [[ -d "$tmpdir/log/error-report" ]]; then
    tar -C "$tmpdir/log" -czf "$logs/error-report.tar.gz" error-report
  fi

  # 3) buildstats (if enabled)
  if [[ -d "$tmpdir/buildstats" ]]; then
    tar -C "$tmpdir" -czf "$logs/buildstats.tar.gz" buildstats
  fi
fi

# Dump key vars for traceability (useful for docs/targets.md)
bitbake -e meta-toolchain 2>/dev/null | egrep \
'^(MACHINE=|DISTRO=|DISTRO_VERSION=|TCLIBC=|TARGET_SYS=|TARGET_ARCH=|TUNE_FEATURES=|SDK_VENDOR=|SDK_VERSION=|GCCVERSION=|BB_VERSION=)' \
> "$out/bitbake-vars.txt" || true

# Optional: keep a small env snapshot for debugging (lightweight)
bitbake -e meta-toolchain 2>/dev/null | head -n 250 > "$out/bitbake-env-head.txt" || true

# If failed, try to copy the most recent task logs (best-effort, bounded)
# This can still be large; we only take a limited number.
if [[ "$bb_exit" -ne 0 ]]; then
  if [[ -d "$tmpdir/work" ]]; then
    # Take up to 80 newest log.do_* files
    mapfile -t newest_logs < <(find "$tmpdir/work" -path '*/temp/log.do_*' -type f -printf '%T@ %p\n' \
      | sort -nr | head -n 80 | cut -d' ' -f2-)
    if [[ "${#newest_logs[@]}" -gt 0 ]]; then
      mkdir -p "$logs"; tar -czf "$logs/tasklogs-newest-80.tar.gz" "${newest_logs[@]}" 2>/dev/null || true
    fi
  fi
fi

# If build succeeded, collect SDK installer + manifest
if [[ "$bb_exit" -eq 0 ]]; then
  sdk_dir="$builddir/tmp/deploy/sdk"
  installer="$(ls -1t "$sdk_dir"/*.sh | head -n1)"
  echo "[container][$flavor] installer: $installer"
  cp -f "$installer" "$out/sdk-installer.sh"

  if ls "$sdk_dir"/*.manifest >/dev/null 2>&1; then
    cp -f "$(ls -1t "$sdk_dir"/*.manifest | head -n1)" "$out/sdk.manifest"
  fi
fi

exit "$bb_exit"

