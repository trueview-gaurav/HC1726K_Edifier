#!/bin/bash

#
# AUGENTIX INC. - PROPRIETARY
#
# seconvert_sdk_ver_code.sh - Convert the sdk version to version code
# Copyright (C) 2024 Augentix Inc. - All Rights Reserved
#
# Usage:
# Input:
#   Argument 1 - SDK version string in the format x.y.z (e.g., "1.2.3")
#
# Output:
#   The corresponding version code is calculated as: 
#   (x << (minor_bit + patch_bit)) + (y << patch_bit) + z
#   The overall valid version code ranges from 0 to 2^(major_bit + minor_bit + patch_bit) - 1
#
# NOTICE: The information contained herein is the property of Augentix Inc.
# Copying and distributing of this file, via any medium,
# must be licensed by Augentix Inc.

major_bit=11
minor_bit=5
patch_bit=5

convert_version() {
    local version=$1
    IFS='.' read -r major_int minor_int patch_int <<< "$version"

    int_to_nbit_bin() {
    	local num=$1
    	local bits=$2

    	# Validate input
    	if [ -z "$num" ] || [ -z "$bits" ]; then
        	echo "[SYSUPD] Anti-rollback error: Input and bit length cannot be empty."
        	return
    	fi

    	if ! [[ "$num" =~ ^[0-9]+$ ]] || ! [[ "$bits" =~ ^[0-9]+$ ]]; then
        	echo "[SYSUPD] Anti-rollback error: Inputs must be valid numbers."
        	return
    	fi

    	if [ "$num" -ge $((1 << bits)) ]; then
        	echo "[SYSUPD] Anti-rollback error: Input exceeds the maximum value for $bits bits."
        	return
    	fi

    	if [ "$num" -eq 0 ]; then
        	printf "%0${bits}d\n" 0
        	return
    	fi

    	# Convert to binary
    	local bin=""
    	while [ "$num" -gt 0 ]; do
        	bin=$((num % 2))$bin
        	num=$((num / 2))
    	done

    	# Pad to the specified bit length
    	bin=$(printf "%0${bits}d" "$bin")
    	echo "$bin"
    }

    major_bin=$(int_to_nbit_bin "$major_int" $major_bit)
    minor_bin=$(int_to_nbit_bin "$minor_int" $minor_bit)
    patch_bin=$(int_to_nbit_bin "$patch_int" $patch_bit)

    if [[ "$major_bin" == *"error"* ]] || [[ "$minor_bin" == *"error"* ]] || [[ "$patch_bin" == *"error"* ]]; then
        echo "error: Invalid version parts."
        exit 1
    fi

    sw_ver_bin="$major_bin$minor_bin$patch_bin"
    sw_ver_int=$((2#$sw_ver_bin))

    echo "$sw_ver_int"
}

convert_version "$1"
