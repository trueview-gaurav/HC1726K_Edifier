#!/bin/bash

# Check if the correct number of arguments are passed
if [ $# -ne 2 ]; then
    echo "Usage: $0 <HSM key id> <public key output file>"
    exit 1
fi

# Read the input arguments
HSM_KEY_ID=$1
OUTPUT_FILE=$2

# Check if the GNUTLS_PIN environment variable is set,
# it should be exported beforehand, e.g. export GNUTLS_PIN=${the HSM PIN}
if [ -z "$GNUTLS_PIN" ]; then
    echo "Error: HSM PIN is required"
    exit 1
fi

# Check if the output file has a .pem extension
if [[ "$OUTPUT_FILE" != *.pem ]]; then
    echo "Error: The output file must have a .pem extension. You provided: $OUTPUT_FILE"
    exit 1
fi

# Extract the directory from the output file path
OUTPUT_DIR=$(dirname "$OUTPUT_FILE")

# Check if the directory exists; create it if not
if [ ! -d "$OUTPUT_DIR" ]; then
    echo "Directory does not exist: $OUTPUT_DIR. Creating it now..."
    mkdir -p "$OUTPUT_DIR" || { echo "Failed to create directory: $OUTPUT_DIR"; exit 1; }
else
    echo "Directory exists: $OUTPUT_DIR"
fi

# Construct the file names for DER and PEM formats
DER_FILE="${OUTPUT_DIR}/pubkey${HSM_KEY_ID}.der"
PEM_FILE="$OUTPUT_FILE"

# Use pkcs11-tool to export the public key in DER format
echo "Exporting public key (DER format) from HSM..."
pkcs11-tool --read -p ${GNUTLS_PIN} --id ${HSM_KEY_ID} --type pubkey > "$DER_FILE"

# Check if pkcs11-tool was successful
if [ $? -ne 0 ]; then
    echo "Failed to export the public key in DER format."
    exit 1
fi

# Convert DER to PEM format using OpenSSL
echo "Converting DER to PEM format..."
openssl rsa -inform DER -outform PEM -in "$DER_FILE" -pubin > "$PEM_FILE"

# Check if OpenSSL conversion was successful
if [ $? -eq 0 ]; then
    echo "Public key exported successfully: $PEM_FILE"
else
    echo "Failed to convert DER to PEM."
    rm -f "$DER_FILE" # Clean up the DER file if conversion fails
    exit 1
fi

# Clean up the intermediate DER file
rm -f "$DER_FILE"

