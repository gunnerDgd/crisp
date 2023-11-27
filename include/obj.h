#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "mem.h"
#include "str.h"

typedef struct obj { u64_t obj[4]; } obj;
typedef struct obj_trait                    {
    bool_t (*on_new)  (obj*, u32_t, va_list);
    bool_t (*on_clone)(obj*, obj*)          ;
    bool_t (*on_ref)  (obj*)                ;
    void   (*on_del)  (obj*)                ;
    u64_t    size;
}   obj_trait;

obj*   obj_new      (mem_res*, obj_trait*, u32_t, ...)    ;
obj*   obj_new_va   (mem_res*, obj_trait*, u32_t, va_list);
bool_t obj_new_at   (obj*    , obj_trait*, u32_t, ...)    ;
bool_t obj_new_at_va(obj*    , obj_trait*, u32_t, va_list);
obj*   obj_clone    (obj*)      ;
bool_t obj_clone_at (obj*, obj*);
obj*   obj_ref      (obj*)      ;
void   obj_del		(obj*)      ;

obj_trait* obj_get_trait(obj*);
u64_t      obj_use_count(obj*);

#ifndef __cplusplus
#define make(par_type)          obj_new      (0  , par_type,
#define make_at(par, par_type)  obj_new_at   (par, par_type,
#define vmake(par_type)         obj_new_va   (0  , par_type,
#define vmake_at(par, par_type) obj_new_at_va(par, par_type,
#define from(...)               __VA_ARGS__)

#define clone(par)               obj_clone    (par)
#define clone_at(par, par_clone) obj_clone_at (par, par_clone)
#define ref(par)                 obj_ref      (par)
#define del(par)                 obj_del      (par)
#define use_count(par)           obj_use_count(par)
#define trait_of(par)            obj_get_trait(par)

#endif
#endif
