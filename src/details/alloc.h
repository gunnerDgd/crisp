#ifndef __DETAILS_ALLOC_H__
#define __DETAILS_ALLOC_H__

#include "../type.h"
#include "../type_atomic.h"

extern  struct __alloc_trait *global_alloc_trait;
extern  struct __alloc       *global_alloc      ;
typedef struct __alloc_trait								   {
    bool_t        (*on_new)  (struct __alloc*)				   ;
    bool_t        (*on_clone)(struct __alloc*, struct __alloc*);
    void          (*on_del)  (struct __alloc*)				   ;

	u64_t		    unit_size ;
	u64_t		    unit_align;
	u64_t		    max_size  ;

    struct __mem* (*on_mem_new)  (struct __alloc*, u64_t)		 ;
    struct __mem* (*on_mem_clone)(struct __alloc*, struct __mem*);
    void          (*on_mem_del)  (struct __alloc*, struct __mem*);
}   __alloc_trait;

typedef struct __alloc	{
	__alloc_trait *trait;
}	__alloc;

bool_t __alloc_new	(__alloc*, __alloc_trait*);
bool_t __alloc_clone(__alloc*, __alloc*)	  ;
void   __alloc_del  (__alloc*)                ;

#endif
