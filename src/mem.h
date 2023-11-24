#ifndef __MEM_H__
#define __MEM_H__

#include "alloc.h"
#include "ptr.h"

typedef void* mem;

mem   mem_new    (alloc*, u64_t);
mem   mem_clone  (mem)          ;
void  mem_del    (mem)	 	    ;

u64_t mem_size   (mem)		    ;
ptr   mem_ptr    (mem, u64_t)   ;
void* mem_ptr_raw(mem)			;

#endif
