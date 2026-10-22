#!/bin/bash

# Check if we have the correct number of arguments
if [ "$#" -lt 4 ] || [ "$#" -gt 5 ]; then
    echo "Usage: $0 <SHA224|SHA256> <input_file> <signature_file> <public_key_file> [RSA_SCHEME: RSA-PKCS|RSA-PKCS-PSS]"
    exit 1
fi

HASH_ALGO=$1
INPUT_FILE=$2
SIGNATURE_FILE=$3
PUBLIC_KEY_FILE=$4
RSA_SCHEME=${5:-"RSA-PKCS"}

# Check hash algorithm
case "$HASH_ALGO" in
    SHA224|SHA256) ;;
    *) echo "Error: Invalid hash algorithm: $HASH_ALGO"; exit 1 ;;
esac

# Check RSA scheme
case "$RSA_SCHEME" in
    RSA-PKCS|RSA-PKCS-PSS) ;;
    *) echo "Error: Invalid RSA scheme: $RSA_SCHEME"; exit 1 ;;
esac

# Check public key
if [ ! -f "$PUBLIC_KEY_FILE" ]; then
    echo "Public key file does not exist: $PUBLIC_KEY_FILE"
    exit 1
fi

# Verify the signature using openssl
if [ "$RSA_SCHEME" == "RSA-PKCS" ]; then
    echo "Verifying with RSA-PKCS"
    if ! openssl dgst -$HASH_ALGO -verify "$PUBLIC_KEY_FILE" -signature "$SIGNATURE_FILE" "$INPUT_FILE"; then
        echo "RSA-PKCS verification failed!"
        exit 1
    fi
else
    echo "Verifying with RSA-PKCS-PSS"
    TMP_HASH=$(mktemp)

    if ! openssl dgst -$HASH_ALGO -binary -out "$TMP_HASH" "$INPUT_FILE"; then
        echo "Failed to generate hash file"
        rm -f "$TMP_HASH"
        exit 1
    fi

    if ! openssl pkeyutl -verify -in "$TMP_HASH" -sigfile "$SIGNATURE_FILE" \
        -pubin -inkey "$PUBLIC_KEY_FILE" \
        -pkeyopt rsa_padding_mode:pss \
        -pkeyopt digest:$HASH_ALGO \
        -pkeyopt rsa_pss_saltlen:32; then
        echo "RSA-PKCS-PSS verification failed!"
        rm -f "$TMP_HASH"
        exit 1
    fi

    rm -f "$TMP_HASH"
fi


if [ $? -eq 0 ]; then
    echo "Signature verified successfully: $SIGNATURE_FILE"
else
    echo "Failed to verify signature: $SIGNATURE_FILE"
    exit 1
fi
