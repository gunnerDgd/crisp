#ifndef __WIN32_THD_H__
#define __WIN32_THD_H__

#ifdef PRESET_FEATURE_THREAD

#include "../../core.h"

extern obj_trait *thd_t;
typedef struct    thd  {
    obj    head;
    void*(*func)(void*);
    u64_t  stat;
    any_t  thd;
    void*  arg;
    void*  ret;
}   thd;

bool_t thd_new  (thd*, u32_t, va_list);
bool_t thd_clone(thd*, thd*)          ;
void   thd_del  (thd*)                ;
fut*   thd_fut  (thd*)                ;

#endif
#endif