#ifndef __DETAILS_CORO_H__
#define __DETAILS_CORO_H__

#include "obj.h"
#include "../details-arch/cpu.h"

#define __coro_run  0
#define __coro_susp 1
#define __coro_stop 2

extern __obj_trait __coro_trait;
typedef struct     __coro      {
	__obj head           ;
	__cpu cpu  , cpu_coro;
	u64_t state			 ;

	void (*ent)(struct __coro*, void*);
	void  *ent_arg					  ;
	void  *ret						  ;
}	__coro;

void   __coro_main		   (__coro*);
bool_t __coro_init		   (__coro*, void(*)(__coro*, void*), void*);
bool_t __coro_init_as_obj  (__coro*, u32_t, va_list);
bool_t __coro_init_as_clone(__coro*, __coro*);
void   __coro_deinit	   (__coro*)		 ;
void*  __coro_yield		   (__coro*, void*)  ;
u64_t  __coro_size		   ()			     ;

#endif