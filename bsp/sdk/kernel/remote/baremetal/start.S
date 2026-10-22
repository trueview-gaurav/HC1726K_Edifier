/*
 * Copyright Augentix Inc. Proprietary and confidential.
 * Unauthorized use or distribution is prohibited.
 * Please contact customer.support@augentix.com for any inquiries.
 */

/*
 * Osaka W33 CM0/CM4 Baremetal Startup - Complete C Runtime
 * Hardware remap: CM0_ROM/CM4I_RAM ↔ DRAM(0) → fw.bin appears at 0x0
 */

    .syntax unified
    .cpu cortex-m0
    .thumb

    /* Minimal Vector Table at 0x0 - ARM Cortex-M requirement */
    .section .vectors, "a"
    .align 2
    .global vector_table
vector_table:
    .word _estack               /* 0x00: Initial SP */
    .word Reset_Handler         /* 0x04: Reset Handler */
    .word Default_Handler       /* 0x08: NMI Handler */
    .word Default_Handler       /* 0x0C: Hard Fault Handler */
    .word 0, 0, 0, 0           /* 0x10-0x1C: Reserved */
    .word 0                     /* 0x20: SVCall (not used) */
    .word 0, 0                  /* 0x24-0x28: Reserved */
    .word 0                     /* 0x2C: PendSV (not used) */
    .word 0                     /* 0x30: SysTick (not used) */

    .text
    .thumb_func
    .global Reset_Handler
    .global Default_Handler

/*
 * Reset_Handler - Final Optimized Baremetal C Runtime Initialization
 * 1. Zero .bss section (uninitialized globals). SP is auto-initialized by hardware.
 * 2. Call main() for application.
 * Note: .data copy is not needed for direct-load (VMA=LMA) systems.
 */
Reset_Handler:
    /* Step 1: Zero .bss section */
    ldr r0, =_sbss            /* Start of .bss */
    ldr r1, =_ebss            /* End of .bss */
    
    cmp r0, r1                /* Skip if .bss section has zero size */
    beq call_main
    
    movs r2, #0               /* Zero value */
    
zero_bss_loop:
    str r2, [r0]              /* Store zero */
    adds r0, r0, #4           /* Increment pointer */
    cmp r0, r1                /* Check if reached the end */
    blt zero_bss_loop         /* Continue if current address < end address */

    /* Step 2: Call main() directly */
call_main:
    bl main                   /* Application entry point */
    
    /* Step 3: Infinite loop if main returns */
infinite_loop:
    b infinite_loop

/* Default exception handler */
    .thumb_func
    .type Default_Handler, %function
Default_Handler:
    b .