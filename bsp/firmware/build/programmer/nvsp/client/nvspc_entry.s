.section .STARTUP, "ax"
.global nvspcEntry
nvspcEntry:
  LDR sp, =stack_top
  BL mainEntry
  B .
