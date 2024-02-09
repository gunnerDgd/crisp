#ifndef __OBJ_H__
#define __OBJ_H__

#include "mem.h"

#include "type.h"
#include "type_atom.h"

#include "ops.h"

struct obj;
typedef struct obj_trait                           {
    bool_t (*on_new)  (struct obj*, u32_t, va_list);
    bool_t (*on_clone)(struct obj*, struct obj*)   ;
    bool_t (*on_ref)  (struct obj*)                ;
    void   (*on_del)  (struct obj*)                ;
    u64_t    size;
    obj_ops *ops ;
}   obj_trait;

typedef struct obj  {
    obj_trait *trait;
    reg_t      ref  ;
    mem       *mem  ;
    void      *data ;
}   obj;

obj*   obj_new      (mem*, obj_trait*, u32_t, ...)    ;
obj*   obj_new_va   (mem*, obj_trait*, u32_t, va_list);

bool_t obj_new_at   (obj*, obj_trait*, u32_t, ...)    ;
bool_t obj_new_at_va(obj*, obj_trait*, u32_t, va_list);

obj*   obj_clone    (obj*)      ;
bool_t obj_clone_at (obj*, obj*);

obj*   obj_ref      (obj*)      ;
u64_t  obj_del		(obj*)      ;

obj_trait* obj_get_trait(obj*);
u64_t      obj_use_count(obj*);

#ifndef __cplusplus
#define make(par_type)           obj_new      (0  , par_type,
#define make_at(par, par_type)   obj_new_at   (par, par_type,
#define vmake(par_type)          obj_new_va   (0  , par_type,
#define vmake_at(par, par_type)  obj_new_at_va(par, par_type,
#define from(...)                __VA_ARGS__)

#define clone(par)               obj_clone    (par)
#define clone_at(par, par_clone) obj_clone_at (par, par_clone)
#define ref(par)                 obj_ref      (par)
#define del(par)                 obj_del      (par)
#define use_count(par)           obj_use_count(par)
#define trait_of(par)            obj_get_trait(par)

#endif
#endif
