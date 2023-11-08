#ifndef __TASK_H__
#define __TASK_H__

#include "obj.h"

extern obj_trait* task_t;
typedef struct    task { u8_t task[512]; } task;

bool_t task_init		 (obj*, alloc*, void(*)(task*, void*), void*);
bool_t task_init_as_clone(obj*, obj*);
void   task_deinit		 (obj*)		 ;

bool_t task_run		     (obj*)		 ;
bool_t task_yield		 (obj*)		 ;

#ifndef __cplusplus
#define run(par)   task_run  (par)
#define yield(par) task_yield(par)
#endif

#endif