#ifndef __DETAILS_ARCH_X86_64_CPU_H__
#define __DETAILS_ARCH_X86_64_CPU_H__

#ifdef PRESET_X86_64
#include "../../mem.h"
#include "../../alloc.h"
#include "../../obj.h"

typedef struct __cpu_reg		 {
		union					 {
		struct					 {
		i64_t rax, rbx , rcx, rdx,
			  rsi, rdi ,
			  rsp, rbp ,
			  rip,
			  r8 , r9  , r10, r11,
			  r12, r13 , r14, r15;
		}; i64_t  reg[17];
		}; u128_t xmm[8] ;
}	__cpu_reg;

extern obj_trait __cpu_trait;
typedef struct   __cpu	    {
	obj		  head;
	__cpu_reg reg ;
}	__cpu;

bool_t __cpu_new   (__cpu*, u32_t, va_list);
bool_t __cpu_clone (__cpu*, __cpu*)		   ;
void   __cpu_del   (__cpu*)				   ;
void   __cpu_switch(__cpu_reg*, __cpu_reg*);

#endif
#endif