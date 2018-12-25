/* syscall_list.h COPYRIGHT FUJITSU LIMITED 2015-2017 */

SYSCALL_DELEGATED(4, io_getevents)
SYSCALL_DELEGATED(17, getcwd)
SYSCALL_DELEGATED(22, epoll_pwait)
SYSCALL_DELEGATED(25, fcntl)
SYSCALL_HANDLED(29, ioctl)
SYSCALL_DELEGATED(35, unlinkat)
SYSCALL_DELEGATED(43, statfs)
SYSCALL_DELEGATED(44, fstatfs)
SYSCALL_HANDLED(56, openat)
SYSCALL_HANDLED(57, close)
SYSCALL_DELEGATED(61, getdents64)
SYSCALL_DELEGATED(62, lseek)
SYSCALL_HANDLED(63, read)
SYSCALL_DELEGATED(64, write)
SYSCALL_DELEGATED(66, writev)
SYSCALL_DELEGATED(67, pread64)
SYSCALL_DELEGATED(68, pwrite64)
SYSCALL_DELEGATED(72, pselect6)
SYSCALL_DELEGATED(73, ppoll)
SYSCALL_HANDLED(74, signalfd4)
SYSCALL_DELEGATED(78, readlinkat)
SYSCALL_DELEGATED(80, fstat)
SYSCALL_HANDLED(93, exit)
SYSCALL_HANDLED(94, exit_group)
SYSCALL_HANDLED(95, waitid)
SYSCALL_HANDLED(96, set_tid_address)
SYSCALL_HANDLED(98, futex)
SYSCALL_HANDLED(99, set_robust_list)
SYSCALL_HANDLED(101, nanosleep)
SYSCALL_HANDLED(102, getitimer)
SYSCALL_HANDLED(103, setitimer)
SYSCALL_HANDLED(113, clock_gettime)
SYSCALL_DELEGATED(114, clock_getres)
SYSCALL_DELEGATED(115, clock_nanosleep)
SYSCALL_HANDLED(117, ptrace)
SYSCALL_HANDLED(118, sched_setparam)
SYSCALL_HANDLED(119, sched_setscheduler)
SYSCALL_HANDLED(120, sched_getscheduler)
SYSCALL_HANDLED(121, sched_getparam)
SYSCALL_HANDLED(122, sched_setaffinity)
SYSCALL_HANDLED(123, sched_getaffinity)
SYSCALL_HANDLED(124, sched_yield)
SYSCALL_HANDLED(125, sched_get_priority_max)
SYSCALL_HANDLED(126, sched_get_priority_min)
SYSCALL_HANDLED(127, sched_rr_get_interval)
SYSCALL_HANDLED(129, kill)
SYSCALL_HANDLED(130, tkill)
SYSCALL_HANDLED(131, tgkill)
SYSCALL_HANDLED(132, sigaltstack)
SYSCALL_HANDLED(133, rt_sigsuspend)
SYSCALL_HANDLED(134, rt_sigaction)
SYSCALL_HANDLED(135, rt_sigprocmask)
SYSCALL_HANDLED(136, rt_sigpending)
SYSCALL_HANDLED(137, rt_sigtimedwait)
SYSCALL_HANDLED(138, rt_sigqueueinfo)
SYSCALL_HANDLED(139, rt_sigreturn)
SYSCALL_HANDLED(143, setregid)
SYSCALL_HANDLED(144, setgid)
SYSCALL_HANDLED(145, setreuid)
SYSCALL_HANDLED(146, setuid)
SYSCALL_HANDLED(147, setresuid)
SYSCALL_HANDLED(148, getresuid)
SYSCALL_HANDLED(149, setresgid)
SYSCALL_HANDLED(150, getresgid)
SYSCALL_HANDLED(151, setfsuid)
SYSCALL_HANDLED(152, setfsgid)
SYSCALL_HANDLED(153, times)
SYSCALL_HANDLED(154, setpgid)
SYSCALL_DELEGATED(160, uname)
SYSCALL_HANDLED(163, getrlimit)
SYSCALL_HANDLED(164, setrlimit)
SYSCALL_HANDLED(165, getrusage)
SYSCALL_HANDLED(167, prctl)
SYSCALL_HANDLED(168, getcpu)
SYSCALL_HANDLED(169, gettimeofday)
SYSCALL_HANDLED(170, settimeofday)
SYSCALL_HANDLED(172, getpid)
SYSCALL_HANDLED(173, getppid)
SYSCALL_HANDLED(174, getuid)
SYSCALL_HANDLED(175, geteuid)
SYSCALL_HANDLED(176, getgid)
SYSCALL_HANDLED(177, getegid)
SYSCALL_HANDLED(178, gettid)
SYSCALL_DELEGATED(188, msgrcv)
SYSCALL_DELEGATED(189, msgsnd)
SYSCALL_DELEGATED(192, semtimedop)
SYSCALL_DELEGATED(193, semop)
SYSCALL_HANDLED(194, shmget)
SYSCALL_HANDLED(195, shmctl)
SYSCALL_HANDLED(196, shmat)
SYSCALL_HANDLED(197, shmdt)
SYSCALL_HANDLED(214, brk)
SYSCALL_HANDLED(215, munmap)
SYSCALL_HANDLED(216, mremap)
SYSCALL_HANDLED(220, clone)
SYSCALL_HANDLED(221, execve)
SYSCALL_HANDLED(222, mmap)
SYSCALL_HANDLED(226, mprotect)
SYSCALL_HANDLED(227, msync)
SYSCALL_HANDLED(228, mlock)
SYSCALL_HANDLED(229, munlock)
SYSCALL_HANDLED(230, mlockall)
SYSCALL_HANDLED(231, munlockall)
SYSCALL_HANDLED(232, mincore)
SYSCALL_HANDLED(233, madvise)
SYSCALL_HANDLED(234, remap_file_pages)
SYSCALL_HANDLED(235, mbind)
SYSCALL_HANDLED(236, get_mempolicy)
SYSCALL_HANDLED(237, set_mempolicy)
SYSCALL_HANDLED(238, migrate_pages)
SYSCALL_HANDLED(239, move_pages)
#ifdef PERF_ENABLE
SYSCALL_HANDLED(241, perf_event_open)
#else // PERF_ENABLE
SYSCALL_DELEGATED(241, perf_event_open)
#endif // PERF_ENABLE
SYSCALL_HANDLED(260, wait4)
SYSCALL_HANDLED(270, process_vm_readv)
SYSCALL_HANDLED(271, process_vm_writev)
#ifndef POSTK_DEBUG_ARCH_DEP_85 /* delete unnecessary pmc_xxx system call */
#ifdef PERF_ENABLE
SYSCALL_HANDLED(601, pmc_init)
SYSCALL_HANDLED(602, pmc_start)
SYSCALL_HANDLED(603, pmc_stop)
SYSCALL_HANDLED(604, pmc_reset)
#endif // PERF_ENABLE
#endif /* !POSTK_DEBUG_ARCH_DEP_85 */
SYSCALL_HANDLED(700, get_cpu_id)
#ifdef PROFILE_ENABLE
SYSCALL_HANDLED(__NR_profile, profile)
#endif // PROFILE_ENABLE
SYSCALL_HANDLED(730, util_migrate_inter_kernel)
SYSCALL_HANDLED(731, util_indicate_clone)
SYSCALL_HANDLED(732, get_system)

/* McKernel Specific */
SYSCALL_HANDLED(801, swapout)
SYSCALL_HANDLED(802, linux_mlock)
SYSCALL_HANDLED(803, suspend_threads)
SYSCALL_HANDLED(804, resume_threads)
SYSCALL_HANDLED(811, linux_spawn)

SYSCALL_DELEGATED(1024, open)
SYSCALL_DELEGATED(1035, readlink)
SYSCALL_HANDLED(1045, signalfd)
SYSCALL_DELEGATED(1049, stat)
SYSCALL_DELEGATED(1060, getpgrp)
SYSCALL_HANDLED(1062, time)
