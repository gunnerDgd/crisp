#ifndef __TASK_H__
#define __TASK_H__

#include "obj.h"

#define           task_none 0
#define           task_pend 1
#define           task_run  2
#define           task_err  3
extern obj_trait *task_t;
typedef struct    task { u8_t task[1024]; } task;

void   task_switch(task*, task*);
void   task_yield (task*)       ;
u64_t  task_poll  (task*)       ;
void*  task_ret   (task*)       ;

#endif