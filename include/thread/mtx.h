#ifndef __THREAD_MTX_H__
#define __THREAD_MTX_H__

#include "../core.h"

extern obj_trait *mtx_t ;
typedef struct    mtx   { u8_t mtx[128]; } mtx;

bool_t mtx_lock_try(mtx*);
void   mtx_lock    (mtx*);
void   mtx_unlock  (mtx*);

#endif