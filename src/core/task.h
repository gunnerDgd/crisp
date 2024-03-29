#ifndef __TASK_TASK_H__
#define __TASK_TASK_H__

#include "obj.h"

#include "box.h"
#include "cpu.h"
#include "fut.h"

extern obj_trait* task_t;
typedef struct    task  {
    obj     head;
    u64_t   stat;

    void* (*func)(void*);
    void   *arg;
    void   *res;

    box     stack;
    cpu    *ret,
            cpu;
}   task;

bool_t task_new   (task*, u32_t, va_list);
bool_t task_clone (task*, task*)         ;
void   task_del   (task*)                ;
fut*   task_fut   (task*)                ;

fut*   async      (void*(*)(void*), void*);

#endif