#ifndef __DETAILS_TASK_H__
#define __DETAILS_TASK_H__

#include "../obj.h"
#include "../list.h"

#include "../cpu.h"

#define __task_state_run  0
#define __task_state_susp 1
#define __task_state_stop 2

extern obj_trait __task_trait;
typedef struct	 __task		 {
	obj				head	 ;
	u64_t			state	 ;
	cpu			    cpu		 ;

	void*		  (*ent)(struct __task*, void*);
	void		   *ent_arg					   ;

	void		   *ret		 ;
	struct __task  *ret_await;

	struct __sched *sched   ;
	it			    sched_it;
}	__task;

void   __task_main		   (__task*)				;
bool_t __task_init         (__task*, u32_t, va_list);
bool_t __task_init_as_clone(__task*, __task*)		;
void   __task_deinit	   (__task*)				;
u64_t  __task_size		   ()						;

void* __task_wait (__task*);
void  __task_susp (__task*);
void  __task_resm (__task*);

#endif