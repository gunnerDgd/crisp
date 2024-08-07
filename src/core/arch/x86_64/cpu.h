#ifndef CORE_ARCH_X86_64_CPU_H
#define CORE_ARCH_X86_64_CPU_H

#ifdef PRESET_ARCH_X86_64
#include "../../obj.h"

typedef struct cpu_reg	     {
	union				     {
	struct				     {
	u64_t rax, rbx , rcx, rdx,
	  	  rsi, rdi ,
		  rsp, rbp ,
		  rip,
		  r8 , r9  , r10, r11,
		  r12, r13 , r14, r15;
	}; u64_t  reg[18];
	}; u256_t vec[8] ;
}	cpu_reg;

extern obj_trait* cpu_t;
typedef struct    cpu  {
	obj	    head;
	cpu_reg reg ;
}	cpu;

void   cpu_do_switch(cpu_reg*, cpu_reg*)  ;
void   cpu_do_get   (cpu_reg*)			  ;
void   cpu_do_set   (cpu_reg*)			  ;

bool_t cpu_new      (cpu*, u32_t, va_list);
bool_t cpu_clone    (cpu*, cpu*)		  ;
void   cpu_del      (cpu*)				  ;

void   cpu_switch   (cpu*, cpu*)		  ;
void   cpu_stack    (cpu*, void*, u64_t)  ;
void   cpu_entry	(cpu*, void*)		  ;
void   cpu_arg		(cpu*, void*)		  ;

#endif
#endif