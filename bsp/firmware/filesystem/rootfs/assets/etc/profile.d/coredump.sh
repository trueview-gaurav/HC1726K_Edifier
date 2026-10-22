# enable coredump, limit size 32*1024 block = 32MB
ulimit -c unlimited
sysctl -qw kernel.core_pattern=/mnt/nfs/core_%t.%p
