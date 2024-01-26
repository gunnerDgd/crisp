#ifndef __TASK_H__
#define __TASK_H__

#include "cpu.h"

#define           task_none 0
#define           task_pend 1
#define           task_run  2
#define           task_err  3
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
u64_t  task_poll  (task*)       ;
void*  task_ret   (task*)       ;

#endif