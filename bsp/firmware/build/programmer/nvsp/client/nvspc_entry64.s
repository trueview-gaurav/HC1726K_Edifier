.section .STARTUP, "ax"
.global nvspcEntry
nvspcEntry:
  ldr x0, =stack_top
  mov sp, x0
  bl mainEntry
  b .
