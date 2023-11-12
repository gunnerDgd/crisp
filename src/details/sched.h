#ifndef __DETAILS_SCHED_H__
#define __DETAILS_SCHED_H__

#include "task.h"
#include "../cpu.h"

extern obj_trait __sched_trait;
typedef struct   __sched	  {
	obj		head	  ;
	list	exec, susp;
	cpu	    cpu		  ;
	__task* curr	  ;
}	__sched			  ;

bool_t __sched_init		    (__sched*, u32_t, va_list);
bool_t __sched_init_as_clone(__sched*, __sched*)	  ;
void   __sched_deinit		(__sched*)				  ;
u64_t  __sched_size		    ()						  ;

bool_t  __sched_run     (__sched*)		   ;
bool_t  __sched_dispatch(__sched*, __task*);
__task* __sched_curr    (__sched*)		   ;

#endif