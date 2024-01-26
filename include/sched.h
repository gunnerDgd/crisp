#ifndef __SCHED_H__
#define __SCHED_H__

#include "task.h"

extern obj_trait* sched_t;
typedef struct    sched { u8_t sched[1024]; } sched;

void   sched_dispatch(sched*, void*(*)(task*, void*), void*);
task*  sched_run     (sched*)                               ;

#endif