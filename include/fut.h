#ifndef __FUT_H__
#define __FUT_H__

#include "obj.h"

extern obj_trait *fut_t;
typedef struct    fut     { u8_t fut[128]; } fut;
typedef struct    fut_ops {
    u64_t (*poll)(obj*);
    void* (*ret) (obj*);
}   fut_ops;

u64_t fut_poll(fut*);
void* fut_ret (fut*);

#endif