#ifndef __DETAILS_MEM_H__
#define __DETAILS_MEM_H__

#include "../type.h"
#include "../type_atomic.h"

typedef struct __mem_trait {
    u64_t (*copy_from)  (struct __mem*, void*, u64_t) ;
    u64_t (*copy_to)    (struct __mem*, void*, u64_t) ;
    u64_t (*move)       (struct __mem*, struct __mem*);
    void* (*get_pointer)(struct __mem*)               ;
}   __mem_trait;

typedef struct __mem {
	struct __alloc* alloc	  ;
	u64_t			alloc_size;
	__mem_trait*    trait	  ;
}	__mem;

__mem*
    __mem_init
        (struct __alloc*, u64_t);

__mem*
    __mem_init_as_clone
        (__mem*);

bool_t
    __mem_deinit
        (__mem*);

u64_t
    __mem_copy_from
        (__mem*, void*, u64_t);

u64_t
    __mem_copy_to
        (__mem*, void*, u64_t);

u64_t
    __mem_move
        (__mem*, __mem*);

u8_t*
    __mem_ptr
        (__mem*);

#endif
