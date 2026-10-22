# SPDX-License-Identifier: MIT
FROM ubuntu:16.04

ARG DEBIAN_FRONTEND=noninteractive
ARG USERNAME=yocto
ARG USER_UID=1000
ARG USER_GID=1000

# ---- Base tools & Yocto build prerequisites ----
RUN apt-get update && apt-get install -y --no-install-recommends \
    gawk wget git-core diffstat unzip texinfo gcc-multilib \
    build-essential chrpath socat libsdl1.2-dev xterm cpio \
    locales tzdata ca-certificates \
    bash coreutils file \
    sudo \
    # Common Yocto deps that often get missed on old bases
    && rm -rf /var/lib/apt/lists/*

# ---- Locale ----
RUN locale-gen en_US.UTF-8 && update-locale LANG=en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# ---- Create a non-root user ----
RUN groupadd --gid ${USER_GID} ${USERNAME} \
    && useradd  --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} \
    && usermod -aG sudo ${USERNAME} \
    && echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/${USERNAME} \
    && chmod 0440 /etc/sudoers.d/${USERNAME}

WORKDIR /work
USER ${USERNAME}

ENV PIP_DISABLE_PIP_VERSION_CHECK=1

