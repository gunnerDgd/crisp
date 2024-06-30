#ifndef CORE_OBJ_H
#define CORE_OBJ_H

#include "type.h"
#include "ops.h"

struct obj;
struct mem;

typedef struct obj_trait                           {
    bool_t (*on_new)  (struct obj*, u32_t, va_list);
    bool_t (*on_clone)(struct obj*, struct obj*)   ;
    bool_t (*on_ref)  (struct obj*)                ;
    void   (*on_del)  (struct obj*)                ;
    u64_t    size;
    obj_ops *ops ;
}   obj_trait;

typedef struct obj   {
    obj_trait  *trait;
    reg_t       ref  ;
    struct mem *mem  ;
    void       *data ;
}   obj;

obj*   obj_new      (struct mem*, obj_trait*, u32_t, ...)    ;
obj*   obj_new_va   (struct mem*, obj_trait*, u32_t, va_list);

bool_t obj_new_at   (obj*, obj_trait*, u32_t, ...)    ;
bool_t obj_new_at_va(obj*, obj_trait*, u32_t, va_list);

obj*   obj_clone    (obj*)      ;
bool_t obj_clone_at (obj*, obj*);

obj*   obj_ref      (obj*)      ;
u64_t  obj_del		(obj*)      ;

obj_trait* obj_get_trait(obj*);
u64_t      obj_use_count(obj*);

#ifndef __cplusplus
#define make(type)           (type*)obj_new      (null_t       , ((obj_trait*)(type##_t)),
#define vmake(type)          (type*)obj_new_va   (null_t       , ((obj_trait*)(type##_t)),
#define make_at(self, type)              obj_new_at   (((obj*)(self)), ((obj_trait*)(type##_t)),
#define vmake_at(self, type)             obj_new_at_va(((obj*)(self)), ((obj_trait*)(type##_t)),
#define from(...)                __VA_ARGS__)

#define clone(self)           obj_clone    (((obj*)self))
#define clone_at(self, clone) obj_clone_at (((obj*)self), ((obj*)clone))
#define ref(self)             obj_ref      (((obj*)self))
#define del(self)             obj_del      (((obj*)self))
#define use_count(self)       obj_use_count(((obj*)self))
#define trait_of(self)        obj_get_trait(((obj*)self))

#define make_trait(do_new, do_clone, do_ref, do_del, do_size, do_ops) {\
    .on_new   = ((bool_t (*)(obj*, u32_t, va_list))(do_new))  ,        \
    .on_clone = ((bool_t (*)(obj*, obj*))          (do_clone)),        \
    .on_ref   = ((bool_t (*)(obj*))(do_ref))                  ,        \
    .on_del   = ((void   (*)(obj*))(do_del))                  ,        \
    .size     = ((u64_t)(do_size))                            ,        \
    .ops      = ((obj_ops*)(do_ops))                          ,        \
}

#endif
#endif