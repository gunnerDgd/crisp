#ifndef __DETAILS_SCHED_H__
#define __DETAILS_SCHED_H__

#include "../obj.h"
#include "../list.h"

#include "../details-arch/cpu.h"

extern obj_trait __sched_trait;
typedef struct   __sched	  {
	obj			   head		  ;
	list		   exec, susp ;
	__cpu		   cpu		  ;
	struct __task* curr		  ;
}	__sched;

bool_t __sched_init		    (__sched*, u32_t, va_list);
bool_t __sched_init_as_clone(__sched*, __sched*)	  ;
void   __sched_deinit		(__sched*)				  ;
u64_t  __sched_size		    ()						  ;

bool_t         __sched_exec	    (__sched*)				  ;
bool_t         __sched_run      (__sched*, struct __task*);
void		   __sched_yield    (__sched*)				  ;
void		   __sched_susp     (__sched*, struct __task*);
struct __task* __sched_curr     (__sched*)				  ;

#endif