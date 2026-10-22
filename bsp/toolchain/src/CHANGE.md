# Changelog

All notable changes to this project will be documented in this file.

The format is based on **Keep a Changelog**, and this project follows **Semantic Versioning**.

## [Unreleased](https://example.com/compare/1.0.0...HEAD)

### Added

- (placeholder) Describe new features that are not released yet.

### Changed

- (placeholder) Describe changes to existing functionality.

### Fixed

- (placeholder) Describe bug fixes.

---

## [1.0.2] - 2026-03-11

### Added

- Add script to create tarball

### Changed

- Updated uClibc and gcc-runtime CLFAGS to reduce runtime library size

### Fixed

- Fix document syntax error for example command

---

## [1.0.1] - 2026-03-03

### Added

- Add libconv and isl dev library to systoot
- Enable PTHREADS_DEBUG_SUPPORT in uClibc for buildroot prerequisite

### Changed

- Force enable SSP options in uClibc
- Update binutils to 2.36
- Remove openssl header in sysroot

### Fixed

- Fix syntax error for krogoth

---

## [1.0.0] - 2026-02-20

### Added

- Initial release of cross SDK toolchains built with **Yocto 2.1 (krogoth)**, **uClibc-ng 1.0.38**, and **GCC 10.3**.
- Two SDK flavors:
    - **Hard-float** SDK (VFP hard-float ABI)
    - **Soft-float** SDK (soft-float ABI)
- Shared build environment based on **Ubuntu 16.04 container** (validated on AWS EC2 16 vCPU / 64GB).
- Build automation scripts to build and collect artifacts (hard + soft).
- Artifact packaging including:
    - SDK installer `.sh` files (hard/soft)
    - `SHA256SUMS`
    - `build-info.json`

### Changed

- Target triplet branding to `arm-augentix-linux-uclibceabi-*` (and custom `SDK_VENDOR`).
- Toolchain configuration aligned with legacy requirements:
    - disabled lto / plugin / nls / multilib
    - size-oriented configuration (`optspace` intent)

### Fixed

- `cc1` / `cc1plus` runtime loader issues by applying a stable RUNPATH/RPATH fix that does not depend on host triplet strings.
- Ensured `meta-toolchain` completes successfully even when `tmp/` and shared `sstate-cache/` are empty.

---

