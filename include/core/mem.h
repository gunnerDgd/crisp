#ifndef __MEM_H__
#define __MEM_H__

#include "type.h"
#include "obj.h"

typedef struct mem_ops                  {
    void* (*on_acq)(any_t, void*, u64_t);
    void  (*on_rel)(any_t, void*, u64_t);
    any_t (*on_new)(u32_t, va_list);
    void  (*on_del)(any_t);
}   mem_ops;

#define make_mem_ops(par_acq, par_rel, par_new, par_del) {\
    .on_acq = ((void* (*)(any_t, void*, u64_t))(par_acq)),\
    .on_rel = ((void  (*)(any_t, void*, u64_t))(par_rel)),\
    .on_new = ((any_t (*)(u32_t, va_list))     (par_new)),\
    .on_del = ((void  (*)(any_t))              (par_del)),\
}

extern obj_trait* mem_t;
typedef struct    mem { u8_t mem[64]; } mem;

mem*   get_mem ()                          ;
mem*   set_mem (mem*)                      ;

void*  mem_acq  (mem*, void*, u64_t);
void   mem_rel  (mem*, void*, u64_t);

void   mem_set (void*, u8_t , u64_t)       ;
ord_t  mem_ord (void*, void*, u64_t)       ;
void   mem_copy(void*, void*, u64_t)       ;
void   mem_move(void*, void*, u64_t)       ;
u64_t  mem_find(void*, void*, u64_t, u64_t);
bool_t mem_eq  (void*, void*, u64_t)       ;
bool_t mem_gt  (void*, void*, u64_t)       ;
bool_t mem_lt  (void*, void*, u64_t)       ;

#define KB *(1ULL << 10ULL)
#define MB *(1ULL << 20ULL)
#define GB *(1ULL << 30ULL)

#ifndef __cplusplus
#define new(par)  mem_acq(get_mem(), null_t, sizeof(par))
#define drop(par) mem_rel(get_mem(), par   , 0)

#define new_from(par_mem, par)  mem_acq(par_mem, null_t, sizeof(par))
#define drop_from(par_mem, par) mem_rel(par_mem, par   , 0)
#endif

#endif
