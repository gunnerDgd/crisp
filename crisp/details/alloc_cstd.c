#include "alloc.h"
#include "alloc_cstd.h"

#include "mem.h"
#include "mem_cstd.h"

#include <string.h>
#include <stdlib.h>

__alloc_trait cstd_alloc_trait = {
	.init 		   	   = &cstd_alloc_init		  ,
	.init_as_clone 	   = &cstd_alloc_init_as_clone,
	.deinit		   	   = &cstd_alloc_deinit       ,

	.mem_init		   = &cstd_mem_init			  ,
	.mem_init_as_clone = &cstd_mem_init_as_clone  ,
	.mem_deinit		   = &cstd_mem_deinit
};

bool_t
    cstd_alloc_init(__alloc* par_alloc) {
        return true_t;
}

bool_t
    cstd_alloc_init_as_clone(__alloc* par_alloc, __alloc* par_alloc_clone) {
        return true_t;
}

void
    cstd_alloc_deinit(__alloc* par_alloc) {
}

__mem*
    cstd_mem_init(__alloc* par_alloc, u64_t par_alloc_size) {
        __mem *mem     		   = malloc(par_alloc_size + sizeof(__mem));
               mem->trait 	   = &cstd_mem_trait;
               mem->alloc_size = par_alloc_size ;
               mem->alloc 	   = par_alloc      ;

        return  mem;
}

__mem*
    cstd_mem_init_as_clone(__alloc* par_alloc, __mem* par_alloc_clone) {
        u8_t  *mem_raw = malloc(par_alloc_clone->alloc_size + sizeof(__mem));
        __mem *mem     = mem_raw;

               mem->trait 	   = par_alloc_clone->trait	    ;
               mem->alloc_size = par_alloc_clone->alloc_size;
               mem->alloc 	   = par_alloc                  ;

		__mem_copy_to(par_alloc_clone, mem_raw, par_alloc_clone->alloc_size);
        return  mem;
}

bool_t
    cstd_mem_deinit(__alloc* par_alloc, __mem* par_dealloc) {
        free(par_dealloc);
        return true;
}