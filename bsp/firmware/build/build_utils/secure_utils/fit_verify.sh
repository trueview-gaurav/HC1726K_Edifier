#!/bin/bash

# Check if we have the correct number of arguments
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <fit_check_sign_tool> <fitimage> <pub_key_dtb>"
    exit 1
fi

# Read the input arguments
FIT_CHECK_SIGN_TOOL=$1
FITIMAGE=$2
KEY_DTB=$3

# Use fit check sign tool to verify the sigature
$FIT_CHECK_SIGN_TOOL -f "$FITIMAGE" -k "$KEY_DTB"

if [ $? -eq 0 ]; then
    echo "Signature verified successfully: $FITIMAGE"
else
    echo "Failed to verify signature: $FITIMAGE"
    exit 1
fi
