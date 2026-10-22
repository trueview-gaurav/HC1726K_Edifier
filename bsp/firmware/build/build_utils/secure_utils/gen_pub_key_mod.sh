#!/bin/bash

# extract modulus from public key modulus
openssl rsa -pubin -inform PEM -in $1 -modulus -noout | cut -d'=' -f2 | xxd -r -p > $2
