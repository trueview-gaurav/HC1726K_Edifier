#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -euo pipefail

IMAGE_NAME="yocto-krogoth-u1604"
YOCTO_ROOT="${YOCTO_ROOT:-$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)}"

mkdir -p "${YOCTO_ROOT}/Sources" \
         "${YOCTO_ROOT}/build-soft" \
         "${YOCTO_ROOT}/cache/downloads" \
         "${YOCTO_ROOT}/cache/sstate-cache"

docker run --rm -it \
  --name yocto-soft \
  -v "${YOCTO_ROOT}:/work/yocto" \
  -w /work/yocto \
  "${IMAGE_NAME}" \
  bash

