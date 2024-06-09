#ifndef __MEM_H__
#define __MEM_H__

#include "type.h"
#include "obj.h"

typedef struct mem_ops                  {
    void* (*on_acq)(any_t, void*, u64_t);
    void  (*on_rel)(any_t, void*, u64_t);
    any_t (*on_new)(u32_t, va_list);
    void  (*on_del)(any_t)         ;
}   mem_ops;

#define make_mem_ops(par_acq, par_rel, par_new, par_del) {\
    .on_acq = ((void* (*)(any_t, void*, u64_t))(par_acq)),\
    .on_rel = ((void  (*)(any_t, void*, u64_t))(par_rel)),\
    .on_new = ((any_t (*)(u32_t, va_list))     (par_new)),\
    .on_del = ((void  (*)(any_t))              (par_del)),\
}

extern obj_trait *mem_t;
typedef struct    mem  {
    obj      head;
    mem_ops *ops ;
    any_t    mem ;
}   mem;

mem*   get_mem  (void);
mem*   set_mem  (mem*);

bool_t mem_new  (mem*, u32_t, va_list);
bool_t mem_clone(mem*, mem*)          ;
void   mem_del  (mem*)                ;

void*  mem_acq  (mem*, void*, u64_t);
void   mem_rel  (mem*, void*, u64_t);

void   mem_set  (u8_t*, u8_t , u64_t)       ;
void   mem_copy (u8_t*, u8_t*, u64_t)       ;
void   mem_move (u8_t*, u8_t*, u64_t)       ;
u64_t  mem_find (u8_t*, u8_t*, u64_t, u64_t);

ord_t  mem_ord  (u8_t*, u8_t*, u64_t);
bool_t mem_eq   (u8_t*, u8_t*, u64_t);
bool_t mem_gt   (u8_t*, u8_t*, u64_t);
bool_t mem_lt   (u8_t*, u8_t*, u64_t);

#define KB *(1ull << 10ull)
#define MB *(1ull << 20ull)
#define GB *(1ull << 30ull)

#ifndef __cplusplus
#define new(par)  mem_acq(get_mem(), null_t, sizeof(par))
#define drop(par) mem_rel(get_mem(), par   , 0)

#define new_from(par_mem, par)  mem_acq(par_mem, null_t, sizeof(par))
#define drop_from(par_mem, par) mem_rel(par_mem, par   , 0)
#endif

#endif
