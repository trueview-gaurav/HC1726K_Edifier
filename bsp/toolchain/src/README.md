# Augentix uClibc Toolchain (Yocto krogoth / GCC 10.3)

This repository builds **cross SDK installers** for ARM targets using:

- **Yocto / Poky:** 2.1 (krogoth)
- **C library:** uClibc-ng 1.0.38
- **GCC:** 10.3
- **Target triplet:** `arm-augentix-linux-uclibceabi-*`
- **Build environment:** Docker container based on **Ubuntu 16.04** (to match the krogoth-era host baseline)

It produces two SDK flavors:

- **Hard-float** SDK (`MACHINE=qti-ipcam-cortexa7`)
- **Soft-float** SDK (`MACHINE=qti-ipcam-cortexa7-soft`)

Both are built and packaged by a **host-driven one-shot script** that runs Docker non-interactively and collects artifacts into a single release folder.

---

## Repository layout

```bash
.
├── artifacts                               # collected release outputs (generated)
├── build-hard                              # Yocto build dir (hard) [NOT versioned]
├── build-soft                              # Yocto build dir (soft) [NOT versioned]
├── cache                                   # shared downloads + sstate-cache
│   ├── downloads
│   └── sstate-cache
├── docs
│   ├── docker-setup-ubuntu.md
│   ├── sdk-usage.md
│   └── targets.md
├── Scripts
│   ├── Artifacts_Verify.sh
│   ├── container-build-one.sh              # runs inside container (1 flavor)
│   ├── docker-build.sh                     # (optional) build docker image
│   ├── Dockerfile                          # docker image definition
│   ├── enter-hard.sh                       # interactive shell (hard)
│   ├── enter-soft.sh                       # interactive shell (soft)
│   ├── host-build-all.sh                   # host one-shot build (runs docker)
│   ├── make-sdk-bundle.sh                  # create tarball
│   ├── templates                           # templated configuration files
│   └── verification
└── Sources
    ├── meta-qti-ipcam-toolchains           # main custom layer
    └── poky                                # poky (krogoth) - cloned/pinned by scripts
├── BUILDING.md
├── CHANGE.md
├── LICENSE
├── README.md

```

---

## Prerequisites

### Host requirements

- Docker (validated on Ubuntu 24.04 host; other Linux hosts may work)
- git
- Enough disk space for Yocto builds and caches

Docker setup guide:

- `docs/docker-setup-ubuntu.md`

### Docker image

Default image name used by scripts:

- `yocto-krogoth-u1604`

Build it (if you have `Scripts/docker-build.sh`):

```bash
cd Scripts
./docker-build.sh
```

## Quick start (recommended)

### 1) One-shot build (hard + soft)

The build is driven from the **host** by a single script that runs Docker and collects artifacts.

From repository root:

```
Scripts/host-build-all.sh --init-conf
```

This will:

- ensure `Sources/poky` exists and is checked out to `krogoth`
- apply template configs into `build-hard/conf/` and `build-soft/conf/`
- run Docker twice (hard then soft)
- build SDK installers via:
    - `bitbake meta-toolchain -c populate_sdk`
- collect outputs under `artifacts/<release-id>/`

### 2) Install and use SDK

See:

- `docs/sdk-usage.md`

---

### Config templates and stamp behavior

This project uses template configs as the **source of truth**:

- `Scripts/templates/build-hard/{local.conf,bblayers.conf}`
- `Scripts/templates/build-soft/{local.conf,bblayers.conf}`

Because `oe-init-build-env` always generates default conf files on first run, the scripts implement a **stamp mechanism**:

- `--init-conf` applies templates **once per build directory** (writes a stamp file)
- subsequent runs with `--init-conf` will **not overwrite** your existing conf
- `--force-conf` always overwrites conf from templates (updates the stamp)

Stamp file location:

- `build-hard/conf/.templates_applied`
- `build-soft/conf/.templates_applied`

### Typical workflows

First-time setup (create build dirs and apply templates once):

```bash
$ Scripts/host-build-all.sh --init-conf
```

Incremental build (fast; does not touch conf):

```bash
$ Scripts/host-build-all.sh
```

Reset conf back to templates:

```bash
$ Scripts/host-build-all.sh --force-conf
```

### Clean modes

Clean build tmp but keep `tmp/sstate-control` (recommended “clean but quiet”):

```bash
$ Scripts/host-build-all.sh --wipe-build-tmp
```

Clean build tmp completely:

```bash
$ Scripts/host-build-all.sh --wipe-build-tmp-all
```

From scratch (release-grade; wipes build tmp + shared sstate-cache):

```bash
$ Scripts/host-build-all.sh --from-scratch
```

Official release (do not include logs on success):

```bash
$ Scripts/host-build-all.sh --from-scratch --no-logs --release-id <release-id>
```

---

## Output artifacts

One-shot builds generate:

```bash
artifacts/<release-id>/
├── hard/
│   ├── sdk-installer.sh
│   ├── sdk.manifest
│   ├── bitbake-vars.txt
│   ├── bitbake-env-head.txt
│   ├── command.txt
│   ├── build-timestamp-utc.txt
│   └── conf-snapshot/
│       ├── local.conf
│       └── bblayers.conf
├── soft/
│   ├── (same structure as hard)
└── SHA256SUMS
```

Notes:

- If logs are enabled (default), `hard/logs/` and `soft/logs/` may contain compressed cooker/error-report bundles and (optionally) build logs.
- With `--no-logs`, logs are not included on success (but still collected on failure to help debugging).

---

## Configuration source of truth

- `Scripts/templates/build-hard/local.conf` and `Scripts/templates/build-hard/bblayers.conf`
- `Scripts/templates/build-soft/local.conf` and `Scripts/templates/build-soft/bblayers.conf`

These templates are applied by:

- `Scripts/host-build-all.sh --init-conf` (apply if missing)
- `Scripts/host-build-all.sh --force-conf` (overwrite)

---

## ABI / tuning documentation

Precise hard vs soft ABI and tuning definitions (recommended to keep updated per release):

- `docs/targets.md`

---

## Interactive container usage (optional)

If you want a shell inside the container (manual debugging):

```
Scripts/enter-hard.sh
Scripts/enter-soft.sh
```

Then inside the container:

```
source Sources/poky/oe-init-build-env build-hard
bitbake meta-toolchain-c populate_sdk
```

---

## Reproducibility and traceability

For release builds:

- prefer `--from-scratch`
- collect `SHA256SUMS`
- keep `bitbake-vars.txt`, `conf-snapshot/`, and (optionally) logs
- record exact commits/tags for:
    - `Sources/poky`
    - `Sources/meta-qti-ipcam-toolchains`
    - `Scripts/`

---

## License

This repository (Scripts + custom layer) is licensed under the MIT License.

Third-party components used to build the SDK (Yocto/Poky, GCC, uClibc-ng, etc.) have their own licenses; see the SDK manifest/licenses output as applicable.

