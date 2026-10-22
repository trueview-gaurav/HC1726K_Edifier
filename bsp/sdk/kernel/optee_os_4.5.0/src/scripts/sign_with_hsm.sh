#!/bin/bash

set -euo pipefail

# --- Parse arguments ---
DUMMY_KEY=""
UUID=""
INPUT_ELF=""
OUTPUT_TA=""
TA_VERSION=""

while [[ $# -gt 0 ]]; do
	case $1 in
		--key)
			DUMMY_KEY="$2"
			shift 2
			;;
		--uuid)
			UUID="$2"
			shift 2
			;;
		--in)
			INPUT_ELF="$2"
			shift 2
			;;
		--out)
			OUTPUT_TA="$2"
			shift 2
			;;
		--ta-version)
			TA_VERSION="$2"
			shift 2
			;;	
		*)
			echo "Unknown option: $1" >&2;
			exit 1
			;;
	esac
done

# --- Validate required variables ---
if [[ -z "$UUID" || -z "$INPUT_ELF" || -z "$OUTPUT_TA" ]]; then
	echo "Missing required argument: --uuid, --in, or --out"
	exit 1
fi

if [ ${#TA_PRIVATE_KEY} -eq 1 ]; then
	TA_PRIVATE_KEY="0$TA_PRIVATE_KEY"
fi

# --- Config ---
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE}")" && pwd)"
ELF_DIR=$(dirname "$INPUT_ELF")
SIG_FILE="$ELF_DIR/$UUID.sig"
DIG_FILE="$ELF_DIR/$UUID.dig"

# --- Step 1: Generate digest (base64) ---
"$SCRIPT_DIR"/sign_encrypt.py digest --key "$TA_PUBLIC_KEY" --uuid "$UUID" \
	--ta-version "$TA_VERSION" --in "$INPUT_ELF" --dig "$DIG_FILE"

# --- Step 2: Sign using custom keys ---
if [ -z "$CONFIG_CUSTOM_SIGN" ]; then
	base64 -d "$DIG_FILE" | \
	openssl pkeyutl -sign -inkey "$TA_PRIVATE_KEY" \
		-pkeyopt digest:sha256 \
		-pkeyopt rsa_padding_mode:pss \
		-pkeyopt rsa_pss_saltlen:digest \
		-pkeyopt rsa_mgf1_md:sha256 | \
	base64 > "$SIG_FILE"
else
	base64 -d "$DIG_FILE" | \
	openssl pkeyutl -engine pkcs11 -keyform engine \
		-sign -inkey "pkcs11:serial=${HSM_SERIAL};token=SmartCard-HSM%20%28UserPIN%29%00%00%00%00%00%00%00%00%00;id=%${TA_PRIVATE_KEY};type=private;pin-value=${GNUTLS_PIN}" \
		-pkeyopt digest:sha256 \
		-pkeyopt rsa_padding_mode:pss \
		-pkeyopt rsa_pss_saltlen:digest \
		-pkeyopt rsa_mgf1_md:sha256 | \
	base64 > "$SIG_FILE"
fi

# --- Step 3: Stitch ELF and signature ---
"$SCRIPT_DIR"/sign_encrypt.py stitch --key "$TA_PUBLIC_KEY" --uuid "$UUID" \
	--ta-version "$TA_VERSION" --in "$INPUT_ELF" --sig "$SIG_FILE" --out "$OUTPUT_TA"