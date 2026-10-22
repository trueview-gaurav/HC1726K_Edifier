#!/bin/bash

# =============================================================================
# Copyright (C) 2026 Qualcomm Technologies, Inc.
# All rights reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
# =============================================================================

# =============================================================================
# Usage:
#   Normal mode:   ./run_wifi_driver_install_scripts.sh
#   Dry-run mode:  DRY_RUN=true ./run_wifi_driver_install_scripts.sh
# =============================================================================

set -euo pipefail

# Detect if script is sourced or executed
# In bash, $0 is "bash" when sourced, otherwise it's the script name
if [[ "${BASH_SOURCE[0]}" != "$0" ]]; then
    EXEC_MODE="source"
else
    EXEC_MODE="subshell"
fi

# Set Parameters and Initial State
ORIGINAL_PWD=$(pwd)
WIFI_DRV_PATCH_DIR="sdk/kernel/linux_patch/wifi_drivers"
DRY_RUN="${DRY_RUN:-false}"

echo "[INFO] Script execution mode: $EXEC_MODE"
echo "[INFO] Original working directory: $ORIGINAL_PWD"

# Trap only for subshell mode (source mode doesn't need restore)
if [[ "$EXEC_MODE" == "subshell" ]]; then
    trap 'cd "$ORIGINAL_PWD" && echo "[INFO] Restored working directory: $(pwd)"' EXIT
fi

# Function to locate SDK root
find_sdk_root() {
    local curr="$1"
    while [[ "$curr" != "/" ]]; do
        if [[ -d "$curr/sdk" && -d "$curr/toolchain" && -d "$curr/buildroot" && -d "$curr/readme" ]]; then
            echo "$curr"
            return 0
        fi
        curr=$(dirname "$curr")
    done
    return 1
}

SDK_ROOT=$(find_sdk_root "$ORIGINAL_PWD" || true)

if [[ -z "$SDK_ROOT" ]]; then
    echo "[ERROR] Unable to locate SDK root directory."
    echo "        Required subdirectories: sdk, toolchain, buildroot, readme"
    return 1 2>/dev/null || exit 1
fi

echo "[INFO] SDK root directory located: $SDK_ROOT"

cd "$SDK_ROOT"
echo "[INFO] Executing build tasks in SDK root..."

if [[ ! -f "./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r3.18.31.sh" ]]; then
    echo "[ERROR] Driver installation script not found"
    return 1 2>/dev/null || exit 1
fi
# sh "./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r3.18.31.sh" "./${WIFI_DRV_PATCH_DIR}"
if [[ "$DRY_RUN" == "true" ]]; then
    echo "[DRY-RUN] Would execute: sh \"./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r3.18.31.sh\" \"./${WIFI_DRV_PATCH_DIR}\""
else
    sh "./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r3.18.31.sh" "./${WIFI_DRV_PATCH_DIR}"
fi

if [[ ! -f "./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r6.1.102.sh" ]]; then
    echo "[ERROR] Driver installation script not found"
    return 1 2>/dev/null || exit 1
fi
# sh "./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r6.1.102.sh" "./${WIFI_DRV_PATCH_DIR}"
# Dry-run 檢查
if [[ "$DRY_RUN" == "true" ]]; then
    echo "[DRY-RUN] Would execute: sh \"./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r6.1.102.sh\" \"./${WIFI_DRV_PATCH_DIR}\""
else
    sh "./${WIFI_DRV_PATCH_DIR}/install_wifi_driver_linux_r6.1.102.sh" "./${WIFI_DRV_PATCH_DIR}"
fi

echo "[SUCCESS] Build tasks finished successfully."

# Restore directory only if sourced (subshell already handled by trap)
if [[ "$EXEC_MODE" == "source" ]]; then
    cd "$ORIGINAL_PWD"
    echo "[INFO] Restored working directory: $(pwd)"
fi
