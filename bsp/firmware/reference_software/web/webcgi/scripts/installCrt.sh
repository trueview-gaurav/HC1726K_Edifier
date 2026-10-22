#!/bin/sh

# Define paths for keys and certificate
SSL_DIR="/etc/nginx/ssl"
PRIVATE_KEY="$SSL_DIR/device_pri_key.pem"
PUBLIC_KEY="$SSL_DIR/device_pub_key.pem"
CSR_PATH="/usrdata/"
OPENSSL="/usr/bin/openssl"

# Create SSL_DIR if it does not exist
[ ! -d "$SSL_DIR" ] && mkdir -p "$SSL_DIR"

echo "CSR path : $CSR_PATH"

# Generate ECDSA key pair
$OPENSSL ecparam -genkey -name prime256v1 -out $PRIVATE_KEY
$OPENSSL ec -pubout -in $PRIVATE_KEY -out $PUBLIC_KEY
echo "openssl gen $PUBLIC_KEY $PRIVATE_KEY"

$OPENSSL req -new -key $PRIVATE_KEY -out $CSR_PATH/device.csr -subj "/C=TW/ST=Taiwan/L=Taipei/O=Augentix/OU=SD2/CN=ALL"
echo "Use $PRIVATE_KEY gen $CSR_PATH/device.csr"

$OPENSSL genrsa -out $CSR_PATH/rootCA.key
$OPENSSL req -new -x509 -key $CSR_PATH/rootCA.key  -days 365 -subj "/C=TW/ST=Taiwan/L=Taipei/O=Augentix/OU=SD2/CN=ALL" -out $CSR_PATH/rootCA.crt
echo "openssl gen CA key and cert $CSR_PATH/rootCA.key, $CSR_PATH/rootCA.crt"

$OPENSSL x509 -req -in $CSR_PATH/device.csr -CA $CSR_PATH/rootCA.crt -CAkey $CSR_PATH/rootCA.key -CAcreateserial -out $CSR_PATH/device-cert.crt -days 398 -sha256 -extfile $SSL_DIR/../myopenssl.cnf -extensions v3_req
echo "openssl gen certificate for testing"


# Encrypt device certificate using corresponding encryption script
if [ -f "/system/www/cgi-bin/encryptedDeviceSecret.sh" ]; then
	sh /system/www/cgi-bin/encryptedDeviceSecret.sh "$CSR_PATH/device-cert.crt"
elif [ -f "/system/www/cgi-bin/encryptedDeviceSecret_sq7131s.sh" ]; then
	sh /system/www/cgi-bin/encryptedDeviceSecret_sq7131s.sh "$CSR_PATH/device-cert.crt"
elif [ -f "/system/www/cgi-bin/encryptedDeviceSecret_tee.sh" ]; then
	sh /system/www/cgi-bin/encryptedDeviceSecret_tee.sh "$CSR_PATH/device-cert.crt"
else
	echo "Error: encryption script not found"
fi

