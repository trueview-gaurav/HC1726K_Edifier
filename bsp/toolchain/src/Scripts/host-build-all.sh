#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -Eeuo pipefail

IMAGE_NAME="${IMAGE_NAME:-yocto-krogoth-u1604}"
YOCTO_ROOT="${YOCTO_ROOT:-$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)}"

WORK_MNT="/work/yocto"
SOURCES="$YOCTO_ROOT/Sources"
POKY_DIR="$SOURCES/poky"
META_DIR="$SOURCES/meta-qti-ipcam-toolchains"

CACHE_DL="$YOCTO_ROOT/cache/downloads"
CACHE_SS="$YOCTO_ROOT/cache/sstate-cache"
ARTIFACTS="$YOCTO_ROOT/artifacts"

POKY_REMOTE="${POKY_REMOTE:-git://git.yoctoproject.org/poky}"
POKY_BRANCH="${POKY_BRANCH:-krogoth}"

DO_HARD=1
DO_SOFT=1
INIT_CONF=0
FORCE_CONF=0
FROM_SCRATCH=0
WIPE_BUILD_TMP=0
WIPE_BUILD_TMP_ALL=0
NO_LOGS=0
RELEASE_ID=""

usage() {
	cat <<EOF
Usage: Scripts/host-build-all.sh [options]

Options:
  --hard-only           Build hard only
  --soft-only           Build soft only
  --init-conf           Apply templates if conf missing (recommended first run)
  --force-conf          Overwrite conf from templates even if exists
  --wipe-build-tmp      Wipe build tmp but KEEP tmp/sstate-control (reduce manifest warnings; keep shared sstate)
  --wipe-build-tmp-all  Remove build-hard/tmp and build-soft/tmp completely (keep shared sstate)
  --from-scratch        Remove build tmp AND cache/sstate-cache
  --no-logs             Do not include logs in artifacts on success (recommended for official releases)
  --release-id <id>     Artifacts folder name (default: UTC timestamp)
  --poky-remote <url>   default: $POKY_REMOTE
  --poky-branch <name>  default: $POKY_BRANCH
EOF
}

ts_utc(){ date -u +"%Y%m%dT%H%M%SZ"; }
need_cmd(){ command -v "$1" >/dev/null 2>&1 || { echo "Missing command: $1" >&2; exit 1; }; }

while [[ $# -gt 0 ]]; do
	case "$1" in
		--hard-only) DO_SOFT=0; shift ;;
		--soft-only) DO_HARD=0; shift ;;
		--init-conf) INIT_CONF=1; shift ;;
		--force-conf) FORCE_CONF=1; shift ;;
		--wipe-build-tmp) WIPE_BUILD_TMP=1; shift ;;
		--wipe-build-tmp-all) WIPE_BUILD_TMP_ALL=1; shift ;;
		--from-scratch) FROM_SCRATCH=1; shift ;;
		--no-logs) NO_LOGS=1; shift ;;
		--release-id) RELEASE_ID="$2"; shift 2 ;;
		--poky-remote) POKY_REMOTE="$2"; shift 2 ;;
		--poky-branch) POKY_BRANCH="$2"; shift 2 ;;
		-h|--help) usage; exit 0 ;;
		*) echo "Unknown arg: $1"; usage; exit 2 ;;
	esac
done

need_cmd docker
need_cmd git
need_cmd sha256sum

mkdir -p "$SOURCES" \
	"$YOCTO_ROOT/build-hard" \
	"$YOCTO_ROOT/build-soft" \
	"$CACHE_DL" \
	"$CACHE_SS" \
	"$ARTIFACTS"

[[ -d "$META_DIR" ]] || { echo "Missing layer: $META_DIR" >&2; exit 1; }

if [[ -z "$RELEASE_ID" ]]; then
	RELEASE_ID="$(ts_utc)"
fi
OUT="$ARTIFACTS/$RELEASE_ID"
mkdir -p "$OUT"

echo "[host] YOCTO_ROOT=$YOCTO_ROOT"
echo "[host] IMAGE_NAME=$IMAGE_NAME"
echo "[host] RELEASE_ID=$RELEASE_ID"
echo "[host] OUT=$OUT"

# ---- ensure poky ----
if [[ ! -d "$POKY_DIR/.git" ]]; then
	echo "[host] Cloning poky ($POKY_BRANCH) ..."
	git clone -b "$POKY_BRANCH" "$POKY_REMOTE" "$POKY_DIR"
else
	echo "[host] Updating poky ..."
	git -C "$POKY_DIR" fetch --all --tags
	git -C "$POKY_DIR" checkout "$POKY_BRANCH"
	git -C "$POKY_DIR" reset --hard "origin/$POKY_BRANCH"
fi

# wipe tmp but keep tmp/sstate-control (local bookkeeping/manifests for setscene)
wipe_tmp_keep_sstate_control() {
        local builddir="$1"
        local tmp="$builddir/tmp"
        [[ -d "$tmp" ]] || return 0
        echo "[host] wipe tmp (keep sstate-control): $tmp"
        find "$tmp" -mindepth 1 -maxdepth 1 ! -name sstate-control -exec rm -rf {} + || true
}

# ---- cleaning ----
if [[ "$FROM_SCRATCH" -eq 1 ]]; then
	echo "[host] --from-scratch: wipe build tmp + shared sstate"
	rm -rf "$YOCTO_ROOT/build-hard/tmp" "$YOCTO_ROOT/build-soft/tmp" "$CACHE_SS"
	mkdir -p "$CACHE_SS"
elif [[ "$WIPE_BUILD_TMP_ALL" -eq 1 ]]; then
        echo "[host] --wipe-build-tmp-all: wipe build tmp completely (keep shared sstate)"
        rm -rf "$YOCTO_ROOT/build-hard/tmp" "$YOCTO_ROOT/build-soft/tmp"
elif [[ "$WIPE_BUILD_TMP" -eq 1 ]]; then
	echo "[host] --wipe-build-tmp: wipe build tmp but keep tmp/sstate-control (keep shared sstate)"
        wipe_tmp_keep_sstate_control "$YOCTO_ROOT/build-hard"
        wipe_tmp_keep_sstate_control "$YOCTO_ROOT/build-soft"
fi

# ---- run one flavor in docker (non-interactive) ----
run_flavor() {
  local flavor="$1"   # hard|soft
  local cname="yocto-$flavor"

  # Only allocate TTY if stdout is a TTY (interactive terminal)
  local TTY_ARGS=()
  if [ -t 1 ]; then
    TTY_ARGS+=(-t)
  fi

  docker run --rm -i "${TTY_ARGS[@]}" \
    --name "$cname" \
    -v "$YOCTO_ROOT:$WORK_MNT" \
    -w "$WORK_MNT" \
    "$IMAGE_NAME" \
    bash "$WORK_MNT/Scripts/container-build-one.sh" "$flavor" "$RELEASE_ID" "$INIT_CONF" "$FORCE_CONF" "$NO_LOGS"
}

# ---- execute ----
if [[ "$DO_HARD" -eq 1 ]]; then
	echo "=== HARD build ==="
	run_flavor hard
fi

if [[ "$DO_SOFT" -eq 1 ]]; then
	echo "=== SOFT build ==="
	run_flavor soft
fi

# after run_flavor hard/soft
if [[ "$DO_HARD" -eq 1 ]]; then
  [[ -f "$OUT/hard/sdk-installer.sh" ]] || { echo "HARD installer missing!" >&2; exit 1; }
fi
if [[ "$DO_SOFT" -eq 1 ]]; then
  [[ -f "$OUT/soft/sdk-installer.sh" ]] || { echo "SOFT installer missing!" >&2; exit 1; }
fi

# If requested, ensure no logs are included in artifacts (success path)
if [[ "$NO_LOGS" -eq 1 ]]; then
  rm -rf "$OUT/hard/logs" "$OUT/soft/logs" 2>/dev/null || true
fi

# ---- host-side SHA256SUMS ----
echo "[host] generate SHA256SUMS"
(
cd "$OUT"
find . -type f -not -name SHA256SUMS -print0 | sort -z | xargs -0 sha256sum > SHA256SUMS
)

echo "DONE: $OUT"
find "$OUT" -maxdepth 3 -type f | sed "s#^$OUT/##" | sort

