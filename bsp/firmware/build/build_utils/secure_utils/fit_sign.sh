#!/bin/bash

# Function to handle errors
handle_error() {
    echo "$1"
    exit 1
}

# Check if the correct number of arguments are passed
if [ $# -ne 3 ] && [ $# -ne 4 ]; then
    handle_error "Usage: $0 <mkimage> <public_key_dtb> <fitimage> <key_id: default null>"
fi

# Read the input arguments
MKIMAGE=$1
PUB_KEY_DTB=$2
FIT_IMG=$3
PRV_KEY=$4

# Check if the input file exists
if [ ! -f "$FIT_IMG" ]; then
    echo "Input file does not exist: $FIT_IMG"
    exit 1
fi

# Set default key path and KEY_TYPE
if [ -z "$PRV_KEY" ]; then
    echo "Warning: PRV_KEY is empty, using default key path '${SDKSRC_DIR}/firmware/build/key/default'"
    PRV_KEY="${SDKSRC_DIR}/firmware/build/key/default"
    KEY_TYPE="default"
else
    KEY_TYPE="custom"
fi

# Function to sign image using custom private key (HSM)
sign_with_custom_key() {
    # Check if the GNUTLS_PIN environment variable is set
    if [ -z "$GNUTLS_PIN" ]; then
        handle_error "Error: HSM PIN is required"
    fi

    # Pad PRV_KEY if it's a single digit
    if [ ${#PRV_KEY} -eq 1 ]; then
        PRV_KEY="0$PRV_KEY"
    fi

    # Construct the PKCS11 URL for the private key
    PRV_KEY_URL="pkcs11:model=PKCS%2315%20emulated;manufacturer=www.CardContact.de;serial=${HSM_SERIAL};token=SmartCard-HSM%20%28UserPIN%29%00%00%00%00%00%00%00%00%00;id=%${PRV_KEY};object=Private%20Key;type=private;pin-value=${GNUTLS_PIN}"
    
    # Sign the image using MKIMAGE
    echo "Signing image with custom private key..."
    $MKIMAGE -F -k "$PRV_KEY_URL" -K "$PUB_KEY_DTB" -N pkcs11 -r "$FIT_IMG"
}

# Function to sign image using default private key
sign_with_default_key() {
    echo "Signing image with default private key..."
    $MKIMAGE -F -k "$PRV_KEY" -K "$PUB_KEY_DTB" -r "$FIT_IMG"
}

# Perform signing based on the key type
if [ "$KEY_TYPE" == "custom" ]; then
    sign_with_custom_key
else
    sign_with_default_key
fi

# Check if the operation was successful
if [ $? -eq 0 ]; then
    echo "Signature created successfully: $FIT_IMG"
else
    handle_error "Failed to create signature."
fi

