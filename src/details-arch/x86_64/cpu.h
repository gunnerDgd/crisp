#ifndef __DETAILS_ARCH_X86_64_CPU_H__
#define __DETAILS_ARCH_X86_64_CPU_H__

#ifdef PRESET_X86_64
#include "../../mem.h"
#include "../../alloc.h"

typedef struct __cpu_reg		 {
		union					 {
		struct					 {
		i64_t rax, rbx , rcx, rdx,
			  rsi, rdi ,
			  rsp, rbp ,
			  rip,
			  r8 , r9  , r10, r11,
			  r12, r13 , r14, r15;
		}; i64_t reg[17]  ;
		}; u64_t xmm[2][8];
}	__cpu_reg;

typedef struct __cpu	 {
	mem       stack		 ;
	u64_t     state		 ;
	void    (*ent)(void*);
	void     *ent_arg	 ;
	__cpu_reg cpu		 ;
}	__cpu;

bool_t __cpu_init		   (__cpu*, alloc*);
bool_t __cpu_init_as_clone (__cpu*, __cpu*);
void   __cpu_deinit	       (__cpu*)		   ;

void __cpu_start (__cpu*, __cpu*, void(*)(__cpu*, void*), void*);
void __cpu_switch(__cpu*, __cpu*)								;

// Assembly Linkage
void   __asm_cpu_start (__cpu_reg*, __cpu_reg*, void(*)(__cpu*, void*), void*);
void   __asm_cpu_switch(__cpu_reg*, __cpu_reg*);

#endif
#endif