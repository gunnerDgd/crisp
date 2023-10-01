#ifndef __ALLOC_H__
#define __ALLOC_H__

#include "type.h"
#include "type_atomic.h"

typedef struct
    alloc { u8_t handle[256]; }
        alloc;

bool_t
    alloc_init
        (alloc*);

bool_t
    alloc_init_as_clone
        (alloc*, alloc*);

void
    alloc_deinit
        (alloc*);

alloc*
	get_default_alloc
		();

#endif
