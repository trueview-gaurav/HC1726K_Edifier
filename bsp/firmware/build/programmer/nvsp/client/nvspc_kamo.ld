/* NVSPC memory layout */
MEMORY
{
	SYSRAM (rwx): ORIGIN = 0xFFE00000, LENGTH = 32k
	SYSRAM_FSBL (rwx): ORIGIN = 0xFFE00000, LENGTH = 28k
	EXTRA_BUF_1 (rwx): ORIGIN = 0xFFE00400, LENGTH = 512
	EXTRA_BUF_2 (rwx): ORIGIN = 0xFFE00600, LENGTH = 512
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
 .nvspc_entry : { *nvspc_entry.o(.STARTUP) }   > SYSRAM_FSBL
 .text : { *(.text*) }                         > SYSRAM_FSBL
 .rodata :  {*(.rodata*) }                     > SYSRAM_FSBL
 .data :  { *(.data*)}                         > SYSRAM_FSBL
 .bss :  { *(.bss*)}                           > SYSRAM_FSBL
}
