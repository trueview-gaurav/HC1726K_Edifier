#!/bin/bash

# Define paths for keys and certificate
SSL_DIR="/etc/nginx/ssl"
PRIVATE_KEY="$SSL_DIR/device_pri_key.pem"
PUBLIC_KEY="$SSL_DIR/device_pub_key.pem"
ISSUER_CERT=$1
ENCRYPTED_PRIVATE_KEY="private_key" # object ID of prv. key in the secure storage
ENCRYPTED_PUBLIC_KEY="public_key" # object ID of pub. key in the secure storage
ENCRYPTED_CERT="certificate" # object ID of cert. in the secure storage
SECURE_STORAGE="/system/bin/optee_example_secure_storage_agtx"

if [ -z "$1" ]; then
  echo "Error: Missing argument."
  echo "Usage: $0 <install crt>"
  exit 1
fi

# Encrypt key pair and certificate using SECURE STORAGE
$SECURE_STORAGE -writefile $ENCRYPTED_PRIVATE_KEY $PRIVATE_KEY
$SECURE_STORAGE -writefile $ENCRYPTED_PUBLIC_KEY $PUBLIC_KEY
$SECURE_STORAGE -writefile $ENCRYPTED_CERT $ISSUER_CERT

echo "SECURE STORAGE encrypted:"
echo "$ENCRYPTED_PRIVATE_KEY"
echo "$ENCRYPTED_PUBLIC_KEY"
echo "$ENCRYPTED_CERT"

# Remove unencrypted key pair and certificate
rm $PRIVATE_KEY
rm $PUBLIC_KEY

echo "Encryption complete and original keys removed."
