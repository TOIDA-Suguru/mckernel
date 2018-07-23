#!/bin/sh

if [ $# -lt 1 ]; then
        echo "Error: too few arguments."
        echo "usage: `basename $0` <param_file>"
fi

# read config
source ./config

# read testcase param
source $1

# mcexec processのkill
./utils/kill_mcexec.sh &> /dev/null

# stop mckernel
sudo ${MCMOD_DIR}/sbin/mcstop+release.sh

sleep 1

# boot mckernel
echo "${MCMOD_DIR}/sbin/mcreboot.sh ${MCRBT_OPT%,}"
sudo ${MCMOD_DIR}/sbin/mcreboot.sh ${MCRBT_OPT%,}

sleep 1

if [ ! -e "/dev/mcos0" ]; then
	echo "Error: failed to mcreboot"
	exit 1
fi

# exec mckernel test program
echo "${MCMOD_DIR}/bin/mcexec ${USR_PROC}"
${MCMOD_DIR}/bin/mcexec ${USR_PROC} 

#if [ $? -eq 0 ]; then
if [ $? == 0 ]; then
	sleep 1

	echo "${MCMOD_DIR}/sbin/ihkosctl ${OS_IDX} kmsg"
	sudo ${MCMOD_DIR}/sbin/ihkosctl ${OS_IDX} kmsg
	exit 0
else
        echo "Error: faild to mcexec"
        exit 1
fi
