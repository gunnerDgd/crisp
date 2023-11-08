#ifndef __DETAILS_ARCH_X86_64_TASK_H__
#define __DETAILS_ARCH_X86_64_TASK_H__

#ifdef PRESET_X86_64
#include "../../details/obj.h"
#include "../../details/mem.h"

#define __task_suspended 1
#define __task_running   2
#define __task_stopped   3

typedef struct __task_cpu		 {
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
}	__task_cpu;

extern __obj_trait __task_trait			 ;
typedef struct     __task				 {
	__obj	    head					 ;
	__mem*      stack					 ;
	u64_t	    state					 ;

	void     (*fn)(struct __task*, void*);
	void      *fn_arg					 ;
	__task_cpu cur, ret					 ;
}	__task;

bool_t __task_obj_init		   (__task*, u32_t, va_list);
bool_t __task_obj_init_as_clone(__task*, __task*)		;
void   __task_obj_deinit	   (__task*)				;
u64_t  __task_obj_size		   ()						;

bool_t __task_init		   (__task*, __alloc*, void(*)(__task*, void*), void*);
bool_t __task_init_as_clone(__task*, __task*)						 ;
void   __task_deinit	   (__task*)								 ;

bool_t __task_run  (__task*);
bool_t __task_yield(__task*);
void   __task_main (__task*);

// Assembly Linkage
void   __task_start (__task_cpu*, __task_cpu*, void(*)(__task*, void*), void*);
void   __task_switch(__task_cpu*, __task_cpu*);

#endif
#endif