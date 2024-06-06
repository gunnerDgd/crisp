#ifndef __TASK_H__
#define __TASK_H__

#include "obj.h"
#include "fut.h"

extern obj_trait *task_t;
typedef struct    task { u8_t task[2 MB]; } task;

fut* task_fut(task*);
fut* async   (void*(*)(void*), void*);

#endif