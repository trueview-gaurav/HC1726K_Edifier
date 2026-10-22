# AugenTix HC1785 CM0/CM4 Baremetal Firmware

**Unified Baremetal Framework for HC1785 SoC Cortex-M Cores**

## Overview

Unified baremetal firmware supporting both ARM Cortex-M0 and Cortex-M4 cores on the HC1785 platform. This firmware provides hardware abstraction, CSR access, and inter-processor communication capabilities.

## Architecture

### Core Detection & Initialization
- Automatic runtime detection of CM0 vs CM4 execution
- Unified binary executes on both cores via hardware memory remapping
- Core-specific initialization based on CPUID detection

### Memory Architecture

#### 1. Firmware Region (32KB)
```
Address Range: 0x00000000 - 0x00008000
┌─────────────────────────────────────────┐ ← 0x00008000
│         FIRMWARE (rwx)                  │
│          32KB (0x7FC0)                  │
│  • .text   - Program code               │
│  • .rodata - Constants                  │
│  • .data   - Initialized variables      │
│  • .bss    - Uninitialized variables    │
├─────────────────────────────────────────┤ ← 0x00000040
│       VECTOR TABLE (rx)                 │
│          64 bytes                       │
│  • Stack pointer initialization         │
│  • Reset handler entry point            │
└─────────────────────────────────────────┘ ← 0x00000000
```

#### 2. Stack Region (8KB in DRAM)
```
Address Range: 0x20000000 - 0x20002000
┌─────────────────────────────────────────┐ ← 0x20002000 (_estack)
│           STACK SPACE                   │
│            8KB (0x2000)                 │
│       Stack grows downward ↓            │
└─────────────────────────────────────────┘ ← 0x20000000
```

#### 3. Status & Control Registers (FPGA CSR)
```
Base Address: 0x82100100 (FPGA_STATUS_BASE)

Register Map:
├── 0x82100100: CM0_STATUS_ADDR    - CM0 core status
├── 0x82100104: CM4_STATUS_ADDR    - CM4 core status  
├── 0x82100108: CM0_INFO_ADDR      - CM0 information
├── 0x8210010C: CM4_INFO_ADDR      - CM4 information
├── 0x82100110: CM0_LOOP_STATUS    - CM0 loop counter
├── 0x82100114: CM4_LOOP_STATUS    - CM4 loop counter
├── 0x82100120: IPC_STATUS_ADDR    - Inter-processor status
└── 0x82100140: CSR_STATUS_ADDR    - CSR test results base
    ├── +0x00: SYSCFG_RESULT
    ├── +0x04: PIOC_RESULT  
    └── +0x08: GPIOC_RESULT
```

#### 4. Shared Memory (DRAM)
```
Base Address: 0x20002000 (SHARED_MEM_BASE)
- General purpose shared memory for CM0/CM4 communication
- Located after stack region in DRAM
```

## Features

### Core Capabilities
- **Automatic Core Detection**: Runtime identification of CM0/CM4
- **Unified Binary**: Single firmware image for both cores
- **C Runtime Support**: Full .data/.bss initialization
- **Hardware Access**: Direct CSR read/write capabilities

### Inter-Processor Communication
- **Status Registers**: Core status tracking via FPGA CSR
- **Shared Memory**: DRAM-based data exchange
- **IPC Protocol**: Magic number handshake (0xCA70CA74)

### Peripheral Support
- **UART**: Console output via UART1 (115200 baud)
- **CSR Access**: System configuration register interface
- **Memory Operations**: Read/write/compare utilities

## Building

### Prerequisites
- ARM GCC toolchain (arm-none-eabi-gcc)
- Make build system

### Build Commands
```bash
# Clean build
make clean

# Build firmware
make

# Output files
output/baremetal.bin  - Binary firmware (32KB)
output/baremetal.elf  - ELF with debug symbols
output/baremetal.map  - Linker map file
```

### Toolchain Configuration
- **Target**: Cortex-M0 (compatible with CM4)
- **ABI**: Soft float
- **Optimization**: -O0 (debug mode)
- **Standard**: C99

## Boot Sequence

1. **Hardware Reset**
   - Vector table loads stack pointer from 0x00
   - Jump to Reset_Handler at 0x04

2. **Runtime Initialization** (start.S)
   - Initialize .data section from flash
   - Clear .bss section
   - Call main()

3. **System Initialization** (main.c)
   - Detect core type (CM0/CM4)
   - Write core status to FPGA CSR
   - Initialize peripherals

4. **Main Loop**
   - Test CSR accessibility
   - Monitor shared memory for IPC
   - Report loop status periodically

## File Structure

```
baremetal/
├── include/
│   ├── address_map.h     - Hardware register addresses
│   ├── cm_conf.h         - Core configuration
│   ├── memory_map.h      - Memory layout definitions
│   ├── printf.h          - Printf implementation
│   └── uart.h            - UART driver interface
├── src/
│   ├── cm_cpu.c          - Core detection functions
│   ├── cm_csr.c          - CSR access functions
│   ├── cm_memory.c       - Memory operations
│   ├── printf.c          - Printf implementation
│   └── uart.c            - UART driver
├── baremetal.ld          - Linker script
├── start.S               - Startup assembly
├── main.c                - Main application
└── Makefile              - Build configuration
```

## Status Values

### Core Status (CORE_STATUS_*)
- `0x00000000`: RESET - Initial state
- `0x10000000`: INITIALIZING - Startup in progress
- `0x20000000`: READY - Normal operation
- `0xDEADBEEF`: ERROR - Fault condition

### IPC Magic Number
- `0xCA70CA74`: CA7 to CM handshake value

## Debugging

### Console Output
Connect UART1 at 115200 baud to view debug messages:
- Core identification (CM0/CM4)
- CSR test results
- Loop status updates
- IPC communication events

### Memory Inspection
Key addresses for debugging:
- `0x82100100`: Core status registers
- `0x20000000`: Stack region
- `0x20002000`: Shared memory

## Technical Notes

### Hardware Memory Remapping
The HC1785 hardware remaps different physical memories to address 0x0 depending on the core:
- CM0: Maps CM0_ROM (0xF0018000) to 0x0
- CM4: Maps CM4I_RAM (0xF0000000) to 0x0

This allows a single binary to execute identically on both cores.

### FPGA CSR Advantages
Using FPGA configuration space for status registers provides:
- Fast hardware access without DRAM latency
- Dedicated debug/status register space
- No interference with application memory

### Stack Placement
Stack is placed in DRAM (0x20000000) for:
- Larger available space (8KB vs 2KB)
- Better performance characteristics
- Separation from code/data regions

## License

Copyright © AugenTix Inc. All rights reserved.
Proprietary and confidential.