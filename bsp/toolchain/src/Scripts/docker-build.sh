#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
set -euo pipefail

IMAGE_NAME="yocto-krogoth-u1604"

# Use current host user's uid/gid so files created inside container are owned by you on the host
USER_UID="$(id -u)"
USER_GID="$(id -g)"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

docker build \
  --build-arg USER_UID="${USER_UID}" \
  --build-arg USER_GID="${USER_GID}" \
  --build-arg USERNAME="yocto" \
  -t "${IMAGE_NAME}" \
  -f "${SCRIPT_DIR}/Dockerfile" \
  "${SCRIPT_DIR}"

echo "Built image: ${IMAGE_NAME}"

