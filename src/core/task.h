#ifndef CORE_TASK_H
#define CORE_TASK_H

#include "obj.h"

#include "box.h"
#include "cpu.h"
#include "fut.h"

extern obj_trait* task_t;
typedef struct    task  {
    obj     head;
    u64_t   stat;

    any_t (*func)(any_t);
    void   *arg;
    void   *res;

    u8_t    spa[1 MB];
    cpu    *ret,
            cpu;
}   task;

fut* async   (any_t(*)(any_t), any_t);
fut* task_fut(task*);

#endif