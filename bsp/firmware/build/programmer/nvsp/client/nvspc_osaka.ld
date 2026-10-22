/* NVSPC memory layout */
MEMORY
{
	SYSRAM (rwx): ORIGIN = 0xFFFE8000, LENGTH = 32k
}

/* stack setting */
stack_size = 2048;
stack_top = ORIGIN(SYSRAM) + LENGTH(SYSRAM);
stack_end = stack_top - stack_size;


ENTRY(nvspcEntry)
SECTIONS
{
 .nvspc_entry : { *nvspc_entry64.o(.STARTUP) *nvspc_entry64.o(.text) }   > SYSRAM
 .text : { *(.text*) }                         > SYSRAM
 .rodata :  {*(.rodata*) }                     > SYSRAM
 .data :  { *(.data*)}                         > SYSRAM
 .bss :  { *(.bss*)}                           > SYSRAM
}
