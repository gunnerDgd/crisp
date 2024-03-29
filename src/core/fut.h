#ifndef __FUT_H__
#define __FUT_H__

#include "obj.h"

#define        fut_ready 0
#define        fut_pend  1
#define        fut_err   2
typedef struct fut_ops {
    u64_t (*poll)(obj*);
    void* (*ret) (obj*);
}   fut_ops;

#ifndef __cplusplus
#define make_fut_ops(par_poll, par_ret) {\
    .poll = ((u64_t(*)(obj*))(par_poll)),\
    .ret  = ((void*(*)(obj*))(par_ret)) ,\
}
#endif

extern obj_trait* fut_t;
typedef struct    fut  {
    obj      head;
    u64_t    stat;
    fut_ops *ops ;
    obj     *fut ;
    void    *ret ;
}   fut;

bool_t fut_new  (fut*, u32_t, va_list);
bool_t fut_clone(fut*, fut*)          ;
void   fut_del  (fut*)                ;

u64_t  fut_poll (fut*);
void*  fut_ret  (fut*);

void*  await    (fut*);

#endif