#ifndef __TASK_H__
#define __TASK_H__

#include "obj.h"

extern struct obj_trait* task_t;
typedef struct			 task { u8_t task[512]; } task;

void* task_wait (task*);
void  task_susp (task*);
void  task_resm (task*);

#ifndef __cplusplus
#define async(par_curr, par_fn, par_fn_arg) make(task_t) from(3, par_curr, par_fn, par_fn_arg)
#define await(par)							task_wait (par)
#define susp(par)							task_susp (par)
#define resm(par)							task_resm (par)
#endif

#endif