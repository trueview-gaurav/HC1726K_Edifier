# Targets and ABI (SDK Flavors)

This document defines the **exact target ABI and tuning** for each SDK flavor produced by this repository.
It is intended to be the source of truth for release builds.

---

## 1. Overview

This project produces two SDK flavors:

- **Hard-float**: VFP hard-float ABI
- **Soft-float**: soft-float ABI

Both flavors use:

- libc: **uClibc-ng**
- gcc: **10.3**
- triplet prefix: `arm-augentix-linux-uclibceabi-*`

---

## 2. Flavor definitions (authoritative)

| Item | Hard-float SDK | Soft-float SDK |
| --- | --- | --- |
| TARGET_SYS | `arm-augentix-linux-uclibceabi`  | `arm-augentix-linux-uclibceabi` |
| Float ABI (`-mfloat-abi`) | `hard` | `soft` |
| FPU (`-mfpu`) | neon-vfpv4 | auto |
| CPU (`-mcpu`) | cortex-a7 | cortex-a7 |
| Arch (`-march`) | armv7ve+simd | armv7ve |
| Endianness | little-endian | little-endian |
| EABI | EABI (eabi) | EABI (eabi) |
| Notes | Hard-float calling convention | Soft-float calling convention |

---

## 3. How to obtain the values from the SDK

After installing the SDK and sourcing the environment file:

### 3.1 Compiler defaults

```bash
echo "$CC"
$CC -Q --help=target | sed -n '1,120p'
```

### 3.2 ABI macros (quick signal)

```bash
$CC -dM -E - < /dev/null | egrep '__SOFTFP__|__ARM_PCS_VFP|__ARM_FP'
```

### 3.3 Assembly / object inspection (ground truth)

```bash
cat > abi_probe.c <<'EOF'
int add(int a, int b) {return a + b; }
EOF

$CC -c abi_probe.c -o abi_probe.o
readelf -A abi_probe.o
```

---

## 4. Verification rules

### 4.1 Hard-float expectations

- `__ARM_PCS_VFP` should be defined
- `readelf -A` should show VFP-related attributes consistent with hard-float

### 4.2 Soft-float expectations

- `__SOFTFP__` (or absence of `__ARM_PCS_VFP`) should indicate soft-float mode
- `readelf -A` should show attributes consistent with soft-float

---

## 5. Where these are configured

Typical configuration locations:

- `Sources/meta-qti-ipcam-toolchains/conf/machine/*.conf`
- `Sources/meta-qti-ipcam-toolchains/conf/distro/*.conf`
- `Sources/meta-qti-ipcam-toolchains/conf/machine/include/*.inc` (tunes)
- `build-hard/conf/local.conf`
- `build-soft/conf/local.conf`

---

## 6. Change policy (breaking vs non-breaking)

Breaking changes (require version bump and explicit release note):

- `TARGET_SYS` / triplet changes
- EABI changes
- float ABI changes (`hard` ↔ `soft`)
- libc change (uclibc-ng ↔ glibc/musl)
- `march` / `mcpu` changes that affect binary compatibility

Non-breaking changes (still document):

- build scripts improvements
- packaging / artifact layout updates
- additional verification steps

