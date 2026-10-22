/*
 * sysram.ld
 *
 * Linker script for running programs in hc1703/1723/1753/1783s SYSRAM
 */

ENTRY(vectors)


MEMORY
{
	DRAM_RESERVE (r)   : ORIGIN = 0x00000000, LENGTH = 128M
	DRAM_PROGRAM (r)   : ORIGIN = 0x06A10000, LENGTH = 22464K
	SYSRAM_PROGRAM (rwx) : ORIGIN = 0xFFE00000, LENGTH = 28K
	SYSRAM_STACK   (rwx) : ORIGIN = 0xFFE07000, LENGTH  = 4K
	SYSROM_PROGRAM (rx)  : ORIGIN = 0xFFFF0000, LENGTH = 32K
}

_l1_icache_line_size = 32;
_l1_dcache_line_size = 64;
_l2_cache_line_size = 64;
_cpu_bus_width = 16;
_alignment_size = MAX(MAX(_l1_icache_line_size, _l1_dcache_line_size), MAX(_l2_cache_line_size, _cpu_bus_width));

gic_cpu_if   = 0x84002000;
bootreg_addr = 0x80000814;
bootreg_defval = 0xFFFF0004;
gicd_cpendsgir0 = 0x84001F10;

SECTIONS
{
	.text :	{
		. = ALIGN(_alignment_size);
		_excp_vec = .;
		KEEP(*(.startup))
		*(.text)
		*(.text*)
		*(.glue_7)
		*(.glue_7t)
		. = ALIGN(_alignment_size);
	} > DRAM_PROGRAM

	.rodata : {
		. = ALIGN(_alignment_size);
		*(.rodata)
		*(.rodata*)
		. = ALIGN(_alignment_size);
	} > DRAM_PROGRAM

	.data :	{
		. = ALIGN(_alignment_size);
		*(.data)
		*(.data*)
		. = ALIGN(_alignment_size);
	} > DRAM_PROGRAM

	.bss (NOLOAD) : {
		_sbss = .;
		. = ALIGN(_alignment_size);
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(_alignment_size);
		_ebss = .;
	} > DRAM_PROGRAM

	_stack_bottom = .;
	. = 128M;
	_stack_top = .;
	stack_top = .;

}
