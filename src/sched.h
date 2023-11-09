#ifndef __SCHED_H__
#define __SCHED_H__

#include "task.h"

extern obj_trait* sched_t;
typedef struct    sched { u8_t sched[1024]; } sched;

bool_t sched_run  (sched*, task*);
bool_t sched_exec (sched*)		 ;
void   sched_yield(sched*)		 ;
void   sched_susp (sched*, task*);
task*  sched_curr (sched*)		 ;

#endif