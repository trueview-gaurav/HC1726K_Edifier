#!/bin/bash

# Function to handle errors
handle_error() {
    echo "$1"
    exit 1
}

# Check if the correct number of arguments are passed
if [ $# -ne 2 ] && [ $# -ne 3 ]; then
    echo "Usage: $0 <input_file> <output_sign_file> <key_id: defualt null>"
    exit 1
fi

# Read the input arguments
INPUT_FILE=$1
OUTPUT_FILE=$2
PRV_KEY=$3

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
    echo "Input file does not exist: $INPUT_FILE"
    exit 1
fi

# Set default key path and KEY_TYPE
if [ -z "$PRV_KEY" ]; then
    echo "Warning: PRV_KEY is empty, using default key path '${SDKSRC_DIR}/firmware/build/key/default/prvkey5.pem'"
    PRV_KEY="${SDKSRC_DIR}/firmware/build/key/default/prvkey5.pem"
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

    # Use pkcs11-tool to generate the signature via the private key in the HSM
    # NOTE: only SHA256 supported
    pkcs11-tool --id "$PRV_KEY" --sign -p "$GNUTLS_PIN" -m SHA256-RSA-PKCS --input-file "$INPUT_FILE" --output-file "$OUTPUT_FILE" --slot-index "$HSM_SLOT"
}

# Function to sign image using default private key
sign_with_default_key() {
    # Use OpenSSL to generate the signature
    # NOTE: only SHA256 supported
    openssl dgst -SHA256 -sign "$PRV_KEY" -out "$OUTPUT_FILE" "$INPUT_FILE"
}

# Perform signing based on the key type
if [ "$KEY_TYPE" == "custom" ]; then
    sign_with_custom_key
else
    sign_with_default_key
fi

# Check if the operation was successful
if [ $? -eq 0 ]; then
    echo "Signature created successfully: $OUTPUT_FILE"
else
    echo "Failed to create signature."
    exit 1
fi

