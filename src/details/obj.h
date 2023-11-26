#ifndef __DETAILS_OBJECT_H__
#define __DETAILS_OBJECT_H__

#include "../type.h"
#include "../type_atom.h"
#include "../mem.h"

typedef struct __obj_trait                           {
	bool_t (*on_new)  (struct __obj*, u32_t, va_list);
    bool_t (*on_clone)(struct __obj*, struct __obj*) ;
    bool_t (*on_ref)  (struct __obj*)                ;
    void   (*on_del)  (struct __obj*)                ;
    u64_t    size;
}   __obj_trait;

typedef struct __obj  {
    mem_res*     res  ;
    atom_u64_t   ref  ;
    __obj_trait *trait; 
}   __obj;

__obj* __obj_new     (mem_res*, __obj_trait*, u32_t, va_list);
bool_t __obj_new_at  (__obj*, __obj_trait*, u32_t, va_list);
__obj* __obj_clone   (__obj*)        ;
bool_t __obj_clone_at(__obj*, __obj*);
__obj* __obj_ref     (__obj*);
void   __obj_del     (__obj*);

#endif
