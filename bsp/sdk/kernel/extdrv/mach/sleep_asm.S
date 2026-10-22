#include <linux/linkage.h>
#include <asm/assembler.h>

.section ".sram_code", "ax"
.arm

 @ r0 = SRAM stack pointer
 @ r1 = extra parameter passed to C function

ENTRY(augentix_cpu_suspend_asm)
	@ save the entire context
	push {r0-r12, lr}   @ save all general purpose registers
	mrs r3, cpsr
	push {r3}           @ save CPSR

	@ save DRAM stack pointer
	mov r2, sp

	@ switch to SRAM stack
	bic r0, r0, #7      @ ensure 8-byte alignment
	mov sp, r0

	@ push DRAM stack pointer to SRAM stack
	push {r2}

	@ prepare parameter for C function
	mov r0, r1
	@ jump to C function in SRAM
	bl augentix_cpu_suspend_sram

	@ restore DRAM stack pointer
	pop {r2}
	mov sp, r2

	@ restore the entire context
	pop {r3}            @ restore CPSR
	msr cpsr, r3
	pop {r0-r12, pc}    @ restore registers and return
ENDPROC(augentix_cpu_suspend_asm)
