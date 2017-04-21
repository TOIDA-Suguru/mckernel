/* context.h COPYRIGHT FUJITSU LIMITED 2015-2017 */
#ifndef __HEADER_ARM64_IHK_CONTEXT_H
#define __HEADER_ARM64_IHK_CONTEXT_H

#include <registers.h>

struct thread_info;
typedef struct {
	struct thread_info *thread;
} ihk_mc_kernel_context_t;

struct user_pt_regs {
	unsigned long regs[31];
	unsigned long sp;
	unsigned long pc;
	unsigned long pstate;
};

struct pt_regs {
	union {
		struct user_pt_regs user_regs;
		struct {
			unsigned long regs[31];
			unsigned long sp;
			unsigned long pc;
			unsigned long pstate;
		};
	};
	unsigned long orig_x0;
	unsigned long syscallno;
};

typedef struct pt_regs ihk_mc_user_context_t;

/* @ref.impl include/asm-generic/ptrace.h */
/* Helpers for working with the instruction pointer */
#ifndef GET_IP
#define GET_IP(regs) ((regs)->pc)
#endif
#ifndef SET_IP
#define SET_IP(regs, val) (GET_IP(regs) = (val))
#endif

/* @ref.impl include/asm-generic/ptrace.h */
static inline unsigned long instruction_pointer(struct pt_regs *regs)
{
	return GET_IP(regs);
}
/* @ref.impl include/asm-generic/ptrace.h */
static inline void instruction_pointer_set(struct pt_regs *regs,
					   unsigned long val)
{
	SET_IP(regs, val);
}

/* temp */
#define ihk_mc_syscall_arg0(uc) (uc)->regs[0]
#define ihk_mc_syscall_arg1(uc) (uc)->regs[1]
#define ihk_mc_syscall_arg2(uc) (uc)->regs[2]
#define ihk_mc_syscall_arg3(uc) (uc)->regs[3]
#define ihk_mc_syscall_arg4(uc) (uc)->regs[4]
#define ihk_mc_syscall_arg5(uc) (uc)->regs[5]

#define ihk_mc_syscall_ret(uc)  (uc)->regs[0]

#define ihk_mc_syscall_pc(uc)   (uc)->pc
#define ihk_mc_syscall_sp(uc)   (uc)->sp

#endif /* !__HEADER_ARM64_IHK_CONTEXT_H */
