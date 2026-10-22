#!/bin/bash

# Function to handle errors
handle_error() {
    printf "Error: %s\n" "$1"
    exit 1
}

# Check if the correct number of arguments are passed
if [ $# -ne 4 ] && [ $# -ne 5 ]; then
    echo "Usage: $0 <input_file> <output_sign_file> <HASH_ALGO: SHA224|SHA256> <RSA_SCHEME: RSA-PKCS|RSA-PKCS-PSS> [key_id]"
    exit 1
fi

# Read the input arguments
INPUT_FILE=$1
OUTPUT_FILE=$2
HASH_ALGO=$3
RSA_SCHEME=$4
PRV_KEY=${5:-""}

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
    handle_error "Input file does not exist: $INPUT_FILE"
fi

# Verify the hash algorithm
case "$HASH_ALGO" in
    SHA224|SHA256) ;;
    *)
        handle_error "Invalid hash algorithm. Please use SHA224 or SHA256."
        ;;
esac

# Check RSA scheme
case "$RSA_SCHEME" in
    RSA-PKCS|RSA-PKCS-PSS) ;;
    *)
        handle_error "Invalid RSA_SCHEME. Use RSA-PKCS or RSA-PKCS-PSS."
        ;;
esac

# Set default key path and KEY_TYPE
if [ -z "$PRV_KEY" ]; then
    echo "Warning: PRV_KEY is empty, using default key path '${SDKSRC_DIR}/firmware/build/key/default/prvkey1.pem'"
    PRV_KEY="${SDKSRC_DIR}/firmware/build/key/default/prvkey1.pem"
    KEY_TYPE="default"
else
    KEY_TYPE="custom"
fi

# Function to sign image using custom private key (HSM)
sign_with_custom_key() {
    # Check if the GNUTLS_PIN environment variable is set
    [ -z "$GNUTLS_PIN" ] && handle_error "GNUTLS_PIN (HSM PIN) is required"

    MECH="$HASH_ALGO-$RSA_SCHEME"

    # Use pkcs11-tool to generate the signature via the private key in the HSM
    if [ "$RSA_SCHEME" = "RSA-PKCS" ]; then
        pkcs11-tool --id "$PRV_KEY" --sign -p "$GNUTLS_PIN" \
            -m "$MECH" --input-file "$INPUT_FILE" --output-file "$OUTPUT_FILE" \
            --slot-index "$HSM_SLOT"
    else
        pkcs11-tool --id "$PRV_KEY" --sign -p "$GNUTLS_PIN" \
            -m "$MECH" --salt-len 32 \
            --input-file "$INPUT_FILE" --output-file "$OUTPUT_FILE" \
            --slot-index "$HSM_SLOT"
    fi
}

# Function to sign image using default private key
sign_with_default_key() {
    # Use OpenSSL to generate the signature
    if [ "$RSA_SCHEME" = "RSA-PKCS" ]; then
        openssl dgst -"$HASH_ALGO" -sign "$PRV_KEY" -out "$OUTPUT_FILE" "$INPUT_FILE"
    else
        TMP_HASH=$(mktemp)
        openssl dgst -"$HASH_ALGO" -binary -out "$TMP_HASH" "$INPUT_FILE"
        openssl pkeyutl -sign -in "$TMP_HASH" -out "$OUTPUT_FILE" \
            -inkey "$PRV_KEY" \
            -pkeyopt digest:$HASH_ALGO \
            -pkeyopt rsa_padding_mode:pss \
            -pkeyopt rsa_pss_saltlen:32
        rm -f "$TMP_HASH"
    fi
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
    handle_error "Failed to create signature."
fi
