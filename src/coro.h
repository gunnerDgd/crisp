#ifndef __CORO_H__
#define __CORO_H__

#include "obj.h"

extern obj_trait* coro_t;
typedef struct    coro { u8_t coro[1024]; } coro;

void* coro_yield(coro*, void*);
#define yield(par, par_val) coro_yield(par, par_val)

#endif