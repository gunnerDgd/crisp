#ifndef __TASK_H__
#define __TASK_H__

#include "cpu.h"
#include "fut.h"

extern obj_trait* task_t;
typedef struct    task  {
    obj          head;
    struct task* pend;
    u64_t        stat;

    void*      (*func)(struct task*, void*);
    void        *arg ;
    void        *ret ;
    
    cpu          cpu   ;
    u64_t        sp_len;
    u64_t        sp    ;
}   task;

bool_t task_new   (task*, u32_t, va_list);
bool_t task_clone (task*, task*)         ;
void   task_del   (task*)                ;

void   task_switch(task*, task*);
void   task_yield (task*)       ;
fut*   task_fut   (task*)       ;

#endif