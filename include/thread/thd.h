#ifndef __THREAD_THD_H__
#define __THREAD_THD_H__

#include "../core.h"

extern obj_trait *thd_t;
typedef struct    thd  { u8_t thd[128]; } thd;

fut*   thd_fut(thd*);

#endif