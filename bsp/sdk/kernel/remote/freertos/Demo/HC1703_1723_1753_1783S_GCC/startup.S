
// Standard definitions of mode bits and interrupt (I & F) flags in PSRs

.equ Mode_USR,         0x10
.equ Mode_FIQ,         0x11
.equ Mode_IRQ,         0x12
.equ Mode_SVC,         0x13
.equ Mode_ABT,         0x17
.equ Mode_UND,         0x1B
.equ Mode_SYS,         0x1F

.equ I_Bit,            0x80  // When I bit is set, IRQ is disabled
.equ F_Bit,            0x40  // When F bit is set, FIQ is disabled

.extern FreeRTOS_IRQ_Handler
.extern FreeRTOS_SWI_Handler

.arm
.global vectors
// Vector table
vectors:
	LDR PC, =reset_handler
	LDR PC, =undefined_handler
	LDR PC, =FreeRTOS_SWI_Handler
	LDR PC, =prefetch_handler
	LDR PC, =abort_handler
	LDR PC, =hypervisor_handler
	LDR PC, =FreeRTOS_IRQ_Handler
	LDR PC, =fiq_handler

// Exception handlers

undefined_handler:
	B    undefined_handler
svc_handler:
	B    svc_handler
prefetch_handler:
	B    prefetch_handler
abort_handler:
	B    abort_handler
hypervisor_handler:
	B    hypervisor_handler
irq_handler:
	BL   gic_irq_handler
	/* Dummy IRQ handler does not use stack */
	SUBS pc, lr, #4 /* PC = LR - 4; IRQ occurs after LR updated to next instruction */
fiq_handler:
	B    fiq_handler

// reset handler

reset_handler:
	// Clear r0
	MOV r0, #0
	// Clear r1
	MOV r1, #0
	// Clear r2
	MOV r2, #0
	// Clear r3
	MOV r3, #0
	// Clear r4
	MOV r4, #0
	// Clear r5
	MOV r5, #0
	// Clear r6
	MOV r6, #0
	// Clear r7
	MOV r7, #0
	// Clear r8
	MOV r8, #0
	// Clear r9
	MOV r9, #0
	// Clear r10
	MOV r10, #0
	// Clear r11
	MOV r11, #0
	// Clear r12
	MOV r12, #0
	// Clear r13
	MOV r13, #0
	// Clear r14
	MOV r14, #0
	// Initialize supervisor mode stack for both cores
	LDR sp, =stack_top
	// Initialize vector address
	LDR r0, =_excp_vec
	// VBAR
	MCR p15, 0, r0, c12, c0, 0
	//De-assert SCTLR.V
	MRC p15, 0, r0, c1, c0, 0
	BIC r0, r0, #0x2000
	MCR p15, 0, r0, c1, c0, 0
	// Enable I-cache
	BL enable_L1_cache
	// Initialize .bss section
	LDR r0, =_sbss
	LDR r1, =_ebss
	MOV r2, #0
zero_bss_loop:
	CMP r0, r1
	BEQ zero_bss_loop_end
	STR r2, [r0], #4
	B zero_bss_loop
zero_bss_loop_end:
	BL enable_neon_vfp
	// Branch to program entry
	BL main
	// Make sure code does not break when main returns
	B .

.global enable_neon_vfp
enable_neon_vfp:
	MRC		p15,0,r0,c1,c0,2    // Read CP Access register
	ORR		r0,r0,#0x00f00000   // Enable full access to NEON/VFP (Coprocessors 10 and 11)
	MCR		p15,0,r0,c1,c0,2    // Write CP Access register
	ISB
	MOV		r0,#0x40000000      // Switch on the VFP and NEON hardware
	VMSR		FPEXC,r0            // Set EN bit in FPEXC
	BX		lr

/* Dream: Enable L1 Cache. page 8-17*/
.global enable_L1_cache
enable_L1_cache:
// 1.MMU, L1$ disable
	MRC		p15, 0, r1, c1, c0, 0 	// Read System Control Register (SCTLR)
	BIC		r1, r1, #1 				// mmu off
	BIC		r1, r1, #(1 << 12) 		// i-cache off
	BIC		r1, r1, #(1 << 2) 		// d-cache & L2-$ off
	MCR		p15, 0, r1, c1, c0, 0 	// Write System Control Register (SCTLR)
//2. invalidate: L1$, TLB, branch predictor
	MOV		r0, #0
	MCR		p15, 0, r0, c7, c5, 0 	// Invalidate Instruction Cache
	MCR		p15, 0, r0, c7, c5, 6 	// Invalidate branch prediction array
	MCR		p15, 0, r0, c8, c7, 0 	// Invalidate entire Unified Main TLB
	ISB								// instr sync barrier
//3.Enable I cache + branch prediction
	MRC		p15, 0, r0, c1, c0, 0 	// System control register
	ORR		r0, r0, #1 << 12 		// Instruction cache enable
	ORR		r0, r0, #1 << 11 		// Program flow prediction
	MCR		p15, 0, r0, c1, c0, 0 	// System control register
	BX      	lr
