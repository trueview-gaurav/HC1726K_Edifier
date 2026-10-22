/* NVSPC memory layout */
MEMORY
{
	SYSRAM (rwx): ORIGIN = 0xFFE00000, LENGTH = 32k
	EXTRA_BUF_1 (rwx): ORIGIN = 0xFFE00400, LENGTH = 512
	EXTRA_BUF_2 (rwx): ORIGIN = 0xFFE00600, LENGTH = 512

	NVSPC_ENTRY (rwx): ORIGIN = 0xFFE00800, LENGTH = 96
	EFUSE_OPS (rwx): ORIGIN = 0xFFE00860, LENGTH = 96
	SYSRAM_FSBL (rwx): ORIGIN = 0xFFE008C0, LENGTH = 0x6F40
}

/* stack setting */
stack_size = 2048;
stack_top = ORIGIN(SYSRAM) + LENGTH(SYSRAM);
extra_buf_1 = ORIGIN(EXTRA_BUF_1);
extra_buf_2 = ORIGIN(EXTRA_BUF_2);
stack_end = stack_top - stack_size;

ENTRY(nvspcEntry)
SECTIONS
{
	.nvspc_entry : {
		KEEP(*nvspc_entry.o(.STARTUP))
	} > NVSPC_ENTRY

	.efuse_burn_ops : {
		PROVIDE(__efuse_burn_ops_start = .);
		KEEP(*(.efuse_burn_ops))
		PROVIDE(__efuse_burn_ops_end = .);
		. = ALIGN(64);
	} > EFUSE_OPS

	.text : { *(.text*) } > SYSRAM_FSBL
	.rodata : { *(.rodata*) } > SYSRAM_FSBL
	.data : { *(.data*) } > SYSRAM_FSBL
	.bss : { *(.bss*) } > SYSRAM_FSBL
}
