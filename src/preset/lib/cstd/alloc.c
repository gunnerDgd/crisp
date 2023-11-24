#include "alloc.h"
#include "mem.h"

#include <stdlib.h>

__alloc_trait cstd_alloc_trait     = {
	.on_new	      = &cstd_alloc_new  ,
	.on_clone     = &cstd_alloc_clone,
	.on_del	      = &cstd_alloc_del  ,

	.on_mem_new	  = &cstd_mem_new    ,
	.on_mem_clone = &cstd_mem_clone  ,
	.on_mem_del	  = &cstd_mem_del    ,

	.max_size	  = -1				 ,
	.unit_align	  =  1				 ,
	.unit_size	  =  1
};
__alloc	cstd_alloc		   = {
	.trait = &cstd_alloc_trait
};

bool_t cstd_alloc_new  (__alloc* par)					  { return true_t; }
bool_t cstd_alloc_clone(__alloc* par, __alloc* par_clone) { return true_t; }
bool_t cstd_alloc_del  (__alloc* par)					  { return true_t; }