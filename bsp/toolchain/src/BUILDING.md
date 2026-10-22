# BUILDING

This document explains how to build the Augentix cross SDK toolchains (hard-float and soft-float) using **Yocto 2.1 (krogoth)** with **uClibc-ng 1.0.38** and **GCC 10.3**.

---

## 1. Supported environment

### Host / build machine

Validated on:

- AWS EC2: 16 vCPU / 64 GB RAM
- Container OS: Ubuntu 16.04

Expected resources (rough guidance):

- CPU: 8+ cores recommended
- RAM: 32+ GB recommended
- Disk: 150+ GB free recommended (varies by cache reuse)
- Network: **Stable**, **High-Speed** internet connection for downloading source components

### Required tools on the host

- Docker: Docker is required on the host. See `docs/docker-setup-ubuntu.md`.
- git

> Everything else is intended to run inside the Ubuntu 16.04 build container.
> 

---

## 2. Repository layout and conventions

### Layout

```bash
.
├── artifacts/                   # collected release outputs
├── build-hard/                  # Yocto build dir (hard-float)   [NOT versioned]
├── build-soft/                  # Yocto build dir (soft-float)   [NOT versioned]
├── cache/                       # shared downloads + sstate-cache
│   ├── downloads/
│   └── sstate-cache/
├── Scripts/                     # container + build automation
└── Sources
    ├── meta-qti-ipcam-toolchains# main custom Layer
    └── poky                     # poky (krogoth)

```

---

## 3. Build container workflow

### 3.1 Build the container image

```bash
$ Scripts/docker-build.sh
```

### 3.2 Enter the container

Hard-float build environment:

```bash
$ Scripts/enter-hard.sh
```

Soft-float build environment:

```bash
$ Scripts/enter-soft.sh
```

> These scripts are expected to mount the repository directory into the container so both `Sources/` and `build-*` are visible.
> 

---

## 4. Build modes

You can build in three common modes:

### Mode A: Incremental build (fastest)

- Reuses existing `build-*/tmp`
- Reuses shared `cache/sstate-cache`

Use when:

- you are iterating on recipes / bbappends

### Mode B: Clean build tmp (balanced)

- Deletes `build-hard/tmp` and/or `build-soft/tmp`
- Keeps shared `cache/sstate-cache`

Use when:

- you want to validate “fresh build dir” behavior
- you still want fast rebuild

### Mode C: From scratch (strongest assurance)

- Deletes `build-*/tmp`
- Deletes shared `cache/sstate-cache`
- Keeps `cache/downloads` (recommended)

Use when:

- you want maximum confidence in reproducibility
- you’re doing a release build

## 5. Manual build (bitbake)

### 5.1 Hard-float SDK

Inside the container:

```bash
$ source Sources/poky/oe-init-build-env build-hard
$ bitbake meta-toolchain -c populate_sdk
```

SDK installer output:

- `build-hard/tmp/deploy/sdk/*.sh`

### 5.2 Soft-float SDK

Inside the container:

```bash
$ source Sources/poky/oe-init-build-env build-soft
$ bitbake meta-toolchain -c populate_sdk
```

SDK installer output:

- `build-soft/tmp/deploy/sdk/*.sh`

## 6. One-shot build (host-driven via Docker)

The recommended build path is **host-driven**: a script runs Docker non-interactively for each flavor and collects outputs into a single artifacts directory.

### Command

Run from repository root:

```bash
$ Scripts/host-build-all.sh [options]
```

This will build SDK installers using:

- `bitbake meta-toolchain -c populate_sdk`

and collect artifacts under:

- `artifacts/<release-id>/`

---

## Configuration templates and stamp mechanism

Yocto’s `oe-init-build-env` creates default config files on first run:

- `<builddir>/conf/local.conf`
- `<builddir>/conf/bblayers.conf`

This project maintains its own “source of truth” templates:

- `Scripts/templates/build-hard/{local.conf,bblayers.conf}`
- `Scripts/templates/build-soft/{local.conf,bblayers.conf}`

To avoid accidentally overwriting local modifications, the scripts use a **stamp file** per build directory:

- hard: `build-hard/conf/.templates_applied`
- soft: `build-soft/conf/.templates_applied`

### `--init-conf` (apply templates once)

- If the stamp file is **missing**, templates are copied into `<builddir>/conf/` and the stamp is created.
- If the stamp file **exists**, templates are **not** copied (conf is preserved).

### `--force-conf` (always overwrite templates)

- Templates are copied into `<builddir>/conf/` regardless of the stamp file.
- The stamp timestamp is updated.

---

## Recommended workflows

### First-time (create build dirs + apply templates once)

```bash
$ Scripts/host-build-all.sh --init-conf
```

### Incremental build (fast)

```bash
$ Scripts/host-build-all.sh
```

### Reset conf back to templates

```bash
$ Scripts/host-build-all.sh --force-conf
```

---

## Cleanup modes

### `--wipe-build-tmp` (recommended)

Removes most of `build-*/tmp` while keeping `tmp/sstate-control` to reduce noisy “manifest not found” warnings when reusing shared sstate.

```bash
$ Scripts/host-build-all.sh --wipe-build-tmp
```

### `--wipe-build-tmp-all`

Removes `build-*/tmp` completely (shared sstate is still kept).

```bash
$ Scripts/host-build-all.sh --wipe-build-tmp-all
```

### `--from-scratch` (release-grade)

Removes:

- `build-hard/tmp`
- `build-soft/tmp`
- `cache/sstate-cache`

Keeps:

- `cache/downloads`

```bash
$ Scripts/host-build-all.sh --from-scratch
```

---

## Release mode

### `--no-logs`

For official releases, you may want artifacts without log bundles. This mode:

- does not store logs on success
- still collects logs on failure (to aid debugging)

```bash
$ Scripts/host-build-all.sh --from-scratch --no-logs --release-id <release-id>
```

## 7. Configuration notes

### 7.1 Build directories

This repo uses two build directories:

- `build-hard/`
- `build-soft/`

They may differ by:

- DISTRO configuration
- tune / ABI settings
- float ABI (hard vs soft)

### 7.2 Key outputs to confirm

After each build, you should have:

- an SDK installer `.sh` under `tmp/deploy/sdk/`
- correct target triplet prefix: `arm-augentix-linux-uclibceabi-*`

Example:

```bash
$ ls -al build-hard/tmp/deploy/sdk/*.sh
$ ls -al build-soft/tmp/deploy/sdk/*.sh
```

---

## 8. Post-build verification (quick)

After installing the SDK and sourcing its environment file:

### 8.1 Check compiler identity

```bash
$CC --version
echo "$CC"
```

### 8.2 ABI / float mode macros

```bash
$CC -dM -E - < /dev/null | egrep '__SOFTFP__|__ARM_PCS_VFP|__ARM_FP'
```

### 8.3 Target options snapshot

```bash
$CC -Q --help=target |head -n 50
```

### 8.4 Simple hello build

```bash
cat > hello.c <<'EOF'
#include <stdio.h>
int main(){ puts("hello");return 0; }
EOF

$CC hello.c -o hello
file hello
```

---

## 9. Cleaning / troubleshooting

### 9.1 Clean build tmp

```bash
rm -rf build-hard/tmp build-soft/tmp
```

### 9.2 Clean shared sstate (slow)

```bash
rm -rf cache/sstate-cache
```

### 9.3 Clean downloads (very slow; avoid)

```bash
rm -rf cache/downloads
```

### 9.4 Common issues

- **Network / fetch failures**: retry, check proxy settings, ensure `cache/downloads` is writable.
- **Disk full**: ensure enough space for `tmp/` and sstate expansion.
- **Permission issues**: confirm container user UID/GID mapping and mounted volume permissions.

## Appendix A: Useful bitbake commands

Show variables:

```bash
bitbake -e meta-toolchain | less
```

Clean a single recipe:

```bash
bitbake <recipe> -c cleanall
```

Show task graph (debug):

```bash
bitbake -g meta-toolchain
```

