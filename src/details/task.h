#ifndef __DETAILS_TASK_H__
#define __DETAILS_TASK_H__

#include "../obj.h"
#include "../list.h"

#include "../details-arch/cpu.h"

#define __task_state_run  0
#define __task_state_susp 1
#define __task_state_stop 2

extern obj_trait __task_trait;
typedef struct	 __task		 {
	obj	  head ;
	u64_t state;
	__cpu cpu  ;

	void (*ent)(struct __task*, void*);
	void  *ent_arg					  ;

	struct __sched *sched   ;
	it			    sched_it;
}	__task;

void   __task_main		   (__task*)				;
bool_t __task_init         (__task*, u32_t, va_list);
bool_t __task_init_as_clone(__task*, __task*)		;
void   __task_deinit	   (__task*)				;
u64_t  __task_size		   ()						;

#endif