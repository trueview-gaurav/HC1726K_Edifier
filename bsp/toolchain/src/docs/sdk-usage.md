# SDK Usage Guide

This guide explains how to **install**, **activate**, and **verify** the generated SDK toolchains.

It applies to both flavors:

- **Hard-float SDK**
- **Soft-float SDK**

> The SDK installers are produced by Yocto `meta-toolchain -c populate_sdk` and are typically located under:
> 
> - `build-hard/tmp/deploy/sdk/`
> - `build-soft/tmp/deploy/sdk/`

---

## 1. Install the SDK

### 1.1 Locate the installer

Example:

```bash
ls -al build-hard/tmp/deploy/sdk/*.sh
ls -al build-soft/tmp/deploy/sdk/*.sh
```

### 1.2 Run the installer

Choose an install directory and run:

```bash
chmod +x ./<sdk-installer>.sh
./<sdk-installer>.sh
```

You will be prompted for an installation path, for example:

- `/opt/augentix-sdk/hard`
- `/opt/augentix-sdk/soft`

> Tip: Keep hard/soft SDKs installed into **separate directories** to avoid mixing environment setup files.
> 

---

## 2. Activate the SDK environment

After installation, source the environment file:

```bash
source <SDK_INSTALL_DIR>/environment-setup-arm-augentix-linux-uclibceabi
```

You should now have variables like:

- `CC`, `CXX`, `AR`, `LD`, `STRIP`
- `SDKTARGETSYSROOT`

Quick checks:

```bash
echo "CC=$CC"
echo "CXX=$CXX"
echo "SYSROOT=$SDKTARGETSYSROOT"
$CC --version
```

---

## 3. Verify the SDK (quick)

This section provides minimal checks to confirm the SDK is usable.

### 3.1 Build and run a C hello (compile-only)

```bash
cat > hello.c <<'EOF'
#include <stdio.h>
int main(){ puts("hello");return 0; }
EOF

$CC hello.c -o hello
file hello
```

### 3.2 Build and run a C++ hello (compile-only)

```bash
cat > hello.cpp <<'EOF'
#include <iostream>
int main(){ std::cout <<"hello\n";return 0; }
EOF

$CXX hello.cpp -o hello_cpp
file hello_cpp
```

### 3.3 ABI macro checks (hard vs soft)

```bash
$CC -dM -E - < /dev/null | egrep '__SOFTFP__|__ARM_PCS_VFP|__ARM_FP'
```

Typical expectations:

- **Hard-float**: `__ARM_PCS_VFP` is defined
- **Soft-float**: `__SOFTFP__` is defined (and `__ARM_PCS_VFP` is not)

> These macros are a quick signal. For ground truth, see section 4.
> 

---

## 4. Verify ABI and tuning (ground truth)

### 4.1 Compiler defaults snapshot

This shows default target settings (useful for debugging):

```bash
$CC -Q --help=target | sed -n '1,160p'
```

### 4.2 Inspect object attributes (`readelf -A`)

`readelf -A` displays ARM EABI attributes embedded in objects.

```bash
cat > abi_probe.c <<'EOF'
int add(int a, int b) {return a + b; }
EOF

$CC -c abi_probe.c -o abi_probe.o
readelf -A abi_probe.o
```

Interpretation hints:

- Hard-float builds typically show attributes consistent with VFP calling convention
- Soft-float builds typically show different ABI-related attributes

> If you maintain a strict ABI definition, record expected outputs in `docs/targets.md`.
> 

---

## 5. Avoid mixing hard/soft artifacts

Do NOT link objects built with different float ABIs.

Recommendations:

- Keep separate install prefixes for hard/soft SDKs
- Keep separate build directories per product/flavor
- Always log which `environment-setup-*` file was sourced in your build logs

To confirm which SDK is active:

```bash
echo "$CC"
$CC -dM -E - < /dev/null | egrep '__SOFTFP__|__ARM_PCS_VFP|__ARM_FP'
```

---

## 6. Common workflows

### 6.1 CMake toolchain usage (simple)

If your project uses CMake, the Yocto SDK typically supports:

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_C_COMPILER="$CC" -DCMAKE_CXX_COMPILER="$CXX" \
         -DCMAKE_SYSROOT="$SDKTARGETSYSROOT"
cmake --build .
```

> Some projects benefit from a dedicated `toolchain.cmake`. If needed, create one that sets compilers and `CMAKE_SYSROOT`.
> 

### 6.2 Autotools usage (simple)

```bash
./configure --host=arm-augentix-linux-uclibceabi --with-sysroot="$SDKTARGETSYSROOT"
make
```

> Depending on your project, you may need to export `CC`, `CXX`, `AR`, `LD` explicitly.
> 

---

## 7. Troubleshooting

### 7.1 `command not found` after sourcing environment

Check:

```bash
echo "$PATH"
which "$CC" ||true
```

Ensure you sourced the correct `environment-setup-*` file.

### 7.2 Unexpected ABI (hard vs soft mismatch)

Run:

```bash
$CC -dM -E - < /dev/null | egrep '__SOFTFP__|__ARM_PCS_VFP|__ARM_FP'
$CC -Q --help=target | head -n 80
```

Compare with your expected definition in `docs/targets.md`.

### 7.3 Sysroot confusion

Confirm:

```bash
echo "$SDKTARGETSYSROOT"
ls -al "$SDKTARGETSYSROOT" | head
```

For more issues, see `docs/troubleshooting.md`.

---

## 8. Reference

- `BUILDING.md` — building the SDK installers
- `docs/targets.md` — authoritative hard/soft ABI definitions
- `RELEASE.md` — release process and artifact packaging

