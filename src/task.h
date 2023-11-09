#ifndef __TASK_H__
#define __TASK_H__

#include "obj.h"

extern struct obj_trait* task_t;
typedef struct			 task { u8_t task[512]; } task;

void* task_wait(task*);

#define async(par_sched, par_fn, par_fn_arg) make(task_t) from(3, par_sched, par_fn, par_fn_arg)
#define await(par)							 task_wait(par)

#endif