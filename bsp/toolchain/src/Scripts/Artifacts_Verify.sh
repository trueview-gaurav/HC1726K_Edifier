#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -Eeuo pipefail

# Usage:
#   Scripts/verify-from-artifacts.sh <artifacts_dir> <test_root_dir> [--hard-only|--soft-only]
#
# Example:
#   Scripts/verify-from-artifacts.sh <SDK_DIR>/artifacts/20260222T034815Z <SDK_DIR>/sdktest/verify_run
#
# What it does:
#   - installs SDK installers from artifacts into <test_root_dir>/sdk-{hard,soft}
#   - runs Scripts/verification/verify-sdk.sh for each flavor into <test_root_dir>/verify-{hard,soft}
#   - cleans only the directories it owns under <test_root_dir>

ARTIFACTS_DIR="${1:-}"
TEST_ROOT="${2:-}"
MODE="${3:-}"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VERIFY_SDK="$SCRIPT_DIR/verification/verify-sdk.sh"
FORCE=0

DO_HARD=1
DO_SOFT=1

usage() {
  cat <<EOF
Usage: $0 <artifacts_dir> <test_root_dir> [--hard-only|--soft-only]

Inputs:
  artifacts_dir   Path printed by host-build-all.sh, e.g. .../artifacts/<release-id>
  test_root_dir   Directory to install SDKs and run checks

Options:
  --hard-only     Verify hard only
  --soft-only     Verify soft only
  --force         Allow using a non-empty test_root_dir without a stamp (DANGEROUS)
EOF
}

if [[ -z "$ARTIFACTS_DIR" || -z "$TEST_ROOT" ]]; then
  usage >&2
  exit 2
fi

case "${MODE:-}" in
  "" ) ;;
  --hard-only) DO_SOFT=0 ;;
  --soft-only) DO_HARD=0 ;;
  --force) FORCE=1 ;;
  *) echo "Unknown option: $MODE" >&2; usage >&2; exit 2 ;;
esac

# Safety checks
if [[ ! -d "$ARTIFACTS_DIR" ]]; then
  echo "ERROR: artifacts_dir not found: $ARTIFACTS_DIR" >&2
  exit 2
fi
if [[ "$TEST_ROOT" == "/" || "$TEST_ROOT" == "" ]]; then
  echo "ERROR: unsafe test_root_dir: $TEST_ROOT" >&2
  exit 2
fi
if [[ ! -x "$VERIFY_SDK" ]]; then
  echo "ERROR: verify-string.sh not executable: $VERIFY_SDK" >&2
  echo "Fix: chmod +x $VERIFY_SDK" >&2
  exit 2
fi

need_cmd() { command -v "$1" >/dev/null 2>&1 || { echo "Missing command: $1" >&2; exit 1; }; }
need_cmd find
need_cmd bash

# Locate installers
HARD_INSTALLER="$ARTIFACTS_DIR/hard/sdk-installer.sh"
SOFT_INSTALLER="$ARTIFACTS_DIR/soft/sdk-installer.sh"

if [[ "$DO_HARD" -eq 1 && ! -f "$HARD_INSTALLER" ]]; then
  echo "ERROR: hard installer not found: $HARD_INSTALLER" >&2
  exit 2
fi
if [[ "$DO_SOFT" -eq 1 && ! -f "$SOFT_INSTALLER" ]]; then
  echo "ERROR: soft installer not found: $SOFT_INSTALLER" >&2
  exit 2
fi

# Stamp mechanism (safety)
STAMP_FILE="$TEST_ROOT/.verify-from-artifacts.stamp"

is_dir_empty() {
  # returns 0 if empty (no entries), 1 if not empty
  if find "$1" -mindepth 1 -maxdepth 1 -print -quit | grep -q .; then
    return 1
  fi
  return 0
}

prepare_test_root() {
  mkdir -p "$TEST_ROOT"

  # If test root is not empty and stamp is missing, refuse (unless --force)
  if [[ ! -f "$STAMP_FILE" ]]; then
    if ! is_dir_empty "$TEST_ROOT"; then
      if [[ "$FORCE" -ne 1 ]]; then
        echo "ERROR: test_root_dir is not empty and no stamp file found:" >&2
        echo "  $TEST_ROOT" >&2
        echo "Refusing to remove anything for safety." >&2
        echo "If this directory is dedicated for verification, either:" >&2
        echo "  - use an empty directory, OR" >&2
        echo "  - re-run with --force to proceed (DANGEROUS)." >&2
        exit 2
      fi
    fi
    # Create stamp on first use
    {
      echo "created_utc=$(date -u +"%Y-%m-%dT%H:%M:%SZ")"
      echo "script=verify-from-artifacts.sh"
    } > "$STAMP_FILE"
  fi

  # Update run context
  {
    echo "last_run_utc=$(date -u +"%Y-%m-%dT%H:%M:%SZ")"
    echo "artifacts_dir=$ARTIFACTS_DIR"
  } >> "$STAMP_FILE"
}

# Prepare dirs (clean only what we own, and only when stamp exists)
SDK_HARD_DIR="$TEST_ROOT/sdk-hard"
SDK_SOFT_DIR="$TEST_ROOT/sdk-soft"
VERIFY_HARD_DIR="$TEST_ROOT/verify-hard"
VERIFY_SOFT_DIR="$TEST_ROOT/verify-soft"

echo "[prep] test_root=$TEST_ROOT"
prepare_test_root
rm -rf "$SDK_HARD_DIR" "$SDK_SOFT_DIR" "$VERIFY_HARD_DIR" "$VERIFY_SOFT_DIR"
mkdir -p "$VERIFY_HARD_DIR" "$VERIFY_SOFT_DIR"

# Helper: non-interactive install
install_sdk() {
  local installer="$1"
  local dest="$2"

  chmod +x "$installer" || true

  HELP_OUT="$(bash "$installer" -h 2>&1 || true)"
  # Prefer -d/-y if supported (Yocto SDK installers usually do)
  if printf '%s\n' "$HELP_OUT" | grep -qF -- "-d <dir>" && \
     printf '%s\n' "$HELP_OUT" | grep -qF -- "-y"; then
     echo "[install] $installer -> $dest"
    bash "$installer" -d "$dest" -y
  else
    echo "ERROR: installer does not appear to support -d/-y: $installer" >&2
    echo "Please run it manually once and re-run verification." >&2
    exit 3
  fi
}

# Helper: find environment-setup file under SDK install dir
find_env_setup() {
  local dir="$1"
  local env_file
  env_file="$(find "$dir" -maxdepth 1 -type f -name 'environment-setup*' | head -n1 || true)"
  if [[ -z "${env_file:-}" ]]; then
    echo "ERROR: environment-setup* not found in: $dir" >&2
    exit 4
  fi
  echo "$env_file"
}

# Install + verify
if [[ "$DO_HARD" -eq 1 ]]; then
  install_sdk "$HARD_INSTALLER" "$SDK_HARD_DIR"
  HARD_ENV="$(find_env_setup "$SDK_HARD_DIR")"
  echo "[verify] hard env: $HARD_ENV"
  "$VERIFY_SDK" --flavor hard --sdk "$HARD_ENV" --workdir "$VERIFY_HARD_DIR"
fi

if [[ "$DO_SOFT" -eq 1 ]]; then
  install_sdk "$SOFT_INSTALLER" "$SDK_SOFT_DIR"
  SOFT_ENV="$(find_env_setup "$SDK_SOFT_DIR")"
  echo "[verify] soft env: $SOFT_ENV"
  "$VERIFY_SDK" --flavor soft --sdk "$SOFT_ENV" --workdir "$VERIFY_SOFT_DIR"
fi

echo "[PASS] verify-from-artifacts completed."
echo "Artifacts: $ARTIFACTS_DIR"
echo "Test root: $TEST_ROOT"

