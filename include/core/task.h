#ifndef CORE_TASK_H
#define CORE_TASK_H

#include "obj.h"
#include "fut.h"

extern obj_trait *task_t;
typedef struct    task { u8_t task[2 MB]; } task;

fut* async   (any_t(*)(any_t), any_t);
fut* task_fut(task*);

#endif