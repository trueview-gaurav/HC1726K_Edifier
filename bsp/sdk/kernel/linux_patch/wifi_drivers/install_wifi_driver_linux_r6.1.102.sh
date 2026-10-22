#!/bin/bash

# =============================================================================
# Copyright (C) 2026 Qualcomm Technologies, Inc.
# All rights reserved.
# Confidential and Proprietary - Qualcomm Technologies, Inc.
# =============================================================================

# ==========================================
# 1. Environment Setup
# ==========================================
SDK_ROOT=$(pwd)
KERNEL_DIR="${SDK_ROOT}/sdk/kernel/linux_6.1.102/"
WIFI_REALTEK_DIR="${KERNEL_DIR}/drivers/net/wireless/realtek/"
WIFI_PATCH_PATH="${1:-./sdk/kernel/linux_patch/wifi_drivers}"

# Color Definitions
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

echo -e "${GREEN}>>> Starting Multi-Driver Deployment...${NC}"

# --- Check base path ---
if [ ! -d "$WIFI_REALTEK_DIR" ]; then
    echo -e "${RED}[Error] Target path not found: $WIFI_REALTEK_DIR${NC}"
    exit 1
fi

# ==========================================
# 2. Driver Configurations
# ==========================================
# Format: "Folder_Name|Repo_URL|Branch|Commit_ID|Patch_File"
DRIVERS=(
    "rtl8188eu|https://github.com/ivanovborislav/rtl8188eu.git|main|163badb4564be50ce11aa3e6fdd2e18f3e4c4b90|ivanovborislav_rtl8188eu.patch"
    "rtl8188fu|https://github.com/supremegamers/rtl8188fu.git|master|40d4a49902a0dddcabe1843c4c15f651773b3ce0|supremegamers_rtl8188fu.patch"
)

# ==========================================
# 3. Execution Loop
# ==========================================
for DRIVER in "${DRIVERS[@]}"; do
    # Parse parameters
    IFS="|" read -r NAME URL BRANCH COMMIT PATCH_NAME <<< "$DRIVER"
    PATCH_PATH="${SDK_ROOT}/${WIFI_PATCH_PATH}/${PATCH_NAME}"
    
    echo -e "${YELLOW}-----------------------------------------------${NC}"
    echo -e "${YELLOW}Processing: $NAME${NC}"
    
    # A. Clone & Reset Source Code
    cd "$WIFI_REALTEK_DIR" || exit
    [ -d "$NAME" ] && rm -rf "$NAME"
    
    git clone -b "$BRANCH" "$URL" "$NAME"
    cd "$NAME" || exit
    git reset --hard "$COMMIT"
    
    # B. Apply Driver-specific Patch
    if [ -f "$PATCH_PATH" ]; then
        echo "Applying driver patch: $PATCH_NAME"
        git apply "$PATCH_PATH"
        [ $? -eq 0 ] && echo -e "${GREEN}Patch applied successfully.${NC}" || echo -e "${RED}Patch failed!${NC}"
    else
        echo -e "${RED}Warning: Patch file $PATCH_NAME not found.${NC}"
    fi

    # C. Modify Kconfig (Prevent duplicates)
    K_STR="source \"drivers/net/wireless/realtek/$NAME/Kconfig\""
    if ! grep -q "$NAME/Kconfig" "${WIFI_REALTEK_DIR}/Kconfig"; then
        sed -i "/rtw89\/Kconfig/a $K_STR" "${WIFI_REALTEK_DIR}/Kconfig"
        echo -e "${GREEN}Added $NAME to Kconfig${NC}"
    fi

    # D. Modify Makefile (Prevent duplicates)
    # Use \t to comply with Makefile Tab indentation convention
    M_STR="obj-\$(CONFIG_$(echo $NAME | tr '[:lower:]' '[:upper:]'))\t+= $NAME/"
    if ! grep -q "$NAME/" "${WIFI_REALTEK_DIR}/Makefile"; then
        sed -i "/CONFIG_RTW89/a $M_STR" "${WIFI_REALTEK_DIR}/Makefile"
        echo -e "${GREEN}Added $NAME to Makefile${NC}"
    fi
done

# ==========================================
# 4. Completion Message
# ==========================================
echo -e "${YELLOW}-----------------------------------------------${NC}" 

cd "$SDK_ROOT"
echo -e "${GREEN} All drivers deployed successfully!${NC}"
