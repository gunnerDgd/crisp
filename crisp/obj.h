#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "alloc.h"
#include "mem.h"
#include "str.h"

typedef struct obj 		 { u64_t obj[4]; } obj;
typedef struct obj_trait {
    bool_t (*init)		   (obj*, u32_t, va_list);
    bool_t (*init_as_clone)(obj*, obj*);
    bool_t (*init_as_ref)  (obj*);
    void   (*deinit)       (obj*);

	u64_t  (*size)		   ()	 ;
	str*   (*name)		   (obj*);
}   obj_trait;

obj*
    obj_init
        (alloc*, obj_trait*, u32_t, ...);

obj*
	obj_init_from_varg
		(alloc*, obj_trait*, u32_t, va_list);

obj*
    obj_init_as_clone
        (obj*);

obj*
    obj_init_as_ref
        (obj*);

mem
    obj_deinit
        (obj*);

obj_trait*
	obj_get_trait
		(obj*);

str*
	obj_name
		(obj*);

u64_t
	obj_use_count
		(obj*);

#endif
