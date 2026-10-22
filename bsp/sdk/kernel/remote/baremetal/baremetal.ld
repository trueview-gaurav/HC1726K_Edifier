/*
 * AugenTix SDK - HC1785 Baremetal Linker Script
 * Copyright (c) AugenTix Inc.
 * 
 * HC1785 CM0/CM4 Baremetal Firmware - 32KB baremetal.bin
 * Hardware remap: CM0_ROM/CM4I_RAM ↔ DRAM(0) → baremetal.bin appears at 0x0
 *
 * Memory Layout (Low Address at Bottom):
 *
 * HIGH ADDRESS (0x00008000)
 * ┌─────────────────────────────────────────┐ ← _estack = 0x00008000
 * │           STACK (4KB)                   │ ← Stack grows DOWN from 0x8000
 * │         (rwx, 0x1000)                   │   Function calls, local vars
 * ├─────────────────────────────────────────┤ ← 0x00007000 (STACK ORIGIN)
 * │         FIRMWARE (rwx)                  │ ← .text, .rodata, .data, .bss
 * │       28KB (0x6FC0)                     │   All program code and data
 * │  - .text (main.c functions)             │
 * │  - .rodata (string constants)           │
 * │  - .data (initialized globals)          │
 * │  - .bss (uninitialized globals)         │
 * ├─────────────────────────────────────────┤ ← 0x00000040 (FIRMWARE ORIGIN)
 * │       MAIN_ENTRY (rx)                   │ ← .entry section
 * │        64 bytes (0x40)                  │   Simple startup code
 * └─────────────────────────────────────────┘ ← 0x00000000 (baremetal.bin BASE)
 * LOW ADDRESS
 *
 * Additional Memory Access (via pointers):
 * - D-RAM: 0x0F0008000 (32KB) - CM0/CM4 shared data
 * - SYSRAM: 0x0F0010000 (32KB) - CM0/CM4 shared system memory
 */

MEMORY
{
    MAIN_ENTRY (rx) : ORIGIN = 0x00000000, LENGTH = 0x40      /* 64B entry */
    FIRMWARE (rwx)  : ORIGIN = 0x00000040, LENGTH = 0x6FC0    /* 28KB code/data */
    STACK (rwx)     : ORIGIN = 0x00007000, LENGTH = 0x1000    /* 4KB stack */
}

/* Stack configuration */
stack_size = 4096;
_stack_top = ORIGIN(STACK) + LENGTH(STACK);
_estack = _stack_top;

SECTIONS
{
    /* Entry point and vector table */
    .vectors : {
        KEEP(*(.vectors))
        . = ALIGN(4);
    } > MAIN_ENTRY

    /* Program code and constants */
    .text : {
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > FIRMWARE

    /* Initialized data */
    .data : {
        _sdata = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > FIRMWARE
    
    /* Load address for data section initialization */
    _sidata = LOADADDR(.data);

    /* Uninitialized data */
    .bss : {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > FIRMWARE

    /* Provide end of firmware address */
    _end = .;
    
    /* Ensure we don't exceed firmware memory */
    ASSERT(. <= (ORIGIN(FIRMWARE) + LENGTH(FIRMWARE)), "Firmware section overflow")
}