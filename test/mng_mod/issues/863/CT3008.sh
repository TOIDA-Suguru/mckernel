#!/bin/sh
MCEXEC=mcexec
dd if=/dev/zero of=testfile bs=$((1024 * 1024)) count=$((2 * 1024))
sync
sudo /sbin/sysctl vm.drop_caches=3
$MCEXEC ./CT3008
rm -f testfile
