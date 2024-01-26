#ifndef __SCHED_H__
#define __SCHED_H__

#include "list.h"
#include "task.h"

extern obj_trait *sched_t;
typedef struct    sched  {
    obj   head  ;
    task  task  ;
    list  run   ;
    node *cur   ;
    u64_t sp_len;
    mem  *sp    ;
}   sched;

bool_t sched_new     (sched*, u32_t, va_list)               ;
bool_t sched_clone   (sched*, sched*)                       ;
void   sched_del     (sched*)                               ;

void   sched_dispatch(sched*, void*(*)(task*, void*), void*);
bool_t sched_idle    (sched*)                               ;
task*  sched_run     (sched*)                               ;

#endif