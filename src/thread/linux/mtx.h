#ifndef __THREAD_MTX_H__
#define __THREAD_MTX_H__

#ifdef PRESET_FEATURE_THREAD
#include "../../core.h"
#include <pthread.h>

extern obj_trait *mtx_t ;
typedef struct    mtx   {
    obj             head;
    pthread_mutex_t mtx ;
}   mtx;

bool_t mtx_new     (mtx*, u32_t, va_list);
bool_t mtx_clone   (mtx*, mtx*)          ;
void   mtx_del     (mtx*)                ;

bool_t mtx_lock_try(mtx*);
void   mtx_lock    (mtx*);
void   mtx_unlock  (mtx*);

#endif
#endif