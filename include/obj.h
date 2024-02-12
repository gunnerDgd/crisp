#ifndef __OBJ_H__
#define __OBJ_H__

#include "mem.h"
#include "ops.h"

typedef struct obj { u8_t obj[32]; } obj;
typedef struct obj_trait                    {
    bool_t (*on_new)  (obj*, u32_t, va_list);
    bool_t (*on_clone)(obj*, obj*)          ;
    bool_t (*on_ref)  (obj*)                ;
    void   (*on_del)  (obj*)                ;
    u64_t    size;
    obj_ops *ops ;
}   obj_trait;

obj*   obj_new      (mem*, obj_trait*, u32_t, ...)    ;
obj*   obj_new_va   (mem*, obj_trait*, u32_t, va_list);

bool_t obj_new_at   (obj*    , obj_trait*, u32_t, ...)    ;
bool_t obj_new_at_va(obj*    , obj_trait*, u32_t, va_list);

obj*   obj_clone    (obj*)      ;
bool_t obj_clone_at (obj*, obj*);

obj*   obj_ref      (obj*)      ;
u64_t  obj_del		(obj*)      ;

obj_trait* obj_get_trait(obj*);
u64_t      obj_use_count(obj*);

#ifndef __cplusplus

#define make(par_type)           (par_type*)obj_new      (null_t       , ((obj_trait*)(par_type##_t)),
#define vmake(par_type)          (par_type*)obj_new_va   (null_t       , ((obj_trait*)(par_type##_t)),
#define make_at(par, par_type)              obj_new_at   (((obj*)(par)), ((obj_trait*)(par_type##_t)),
#define vmake_at(par, par_type)             obj_new_at_va(((obj*)(par)), ((obj_trait*)(par_type##_t)),
#define from(...)                __VA_ARGS__)

#define clone(par)               obj_clone    (((obj*)par))
#define clone_at(par, par_clone) obj_clone_at (((obj*)par), ((obj*)par_clone))
#define ref(par)                 obj_ref      (((obj*)par))
#define del(par)                 obj_del      (((obj*)par))
#define use_count(par)           obj_use_count(((obj*)par))
#define trait_of(par)            obj_get_trait(((obj*)par))

#define make_trait(par_new, par_clone, par_ref, par_del, par_size, par_ops) {\
    .on_new   = ((bool_t (*)(obj*, u32_t, va_list))(par_new))  ,             \
    .on_clone = ((bool_t (*)(obj*, obj*))          (par_clone)),             \
    .on_ref   = ((bool_t (*)(obj*))(par_ref))                  ,             \
    .on_del   = ((void   (*)(obj*))(par_del))                  ,             \
    .size     = ((u64_t)(par_size))                            ,             \
    .ops      = ((obj_ops*)(par_ops))                          ,             \
}

#endif
#endif
