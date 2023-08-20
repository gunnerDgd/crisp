#include "alloc.h"
#include "alloc_cstd.h"

#include "mem.h"
#include "mem_cstd.h"

#include <string.h>
#include <stdlib.h>

c_bool_t
    cstd_alloc_init(alloc_t* par_alloc){
        return true;
}

c_bool_t
    cstd_alloc_init_as_clone(alloc_t* par_alloc, alloc_t* par_alloc_clone) {
        return true;
}

c_bool_t
    cstd_alloc_deinit(alloc_t* par_alloc) {
        return true;
}

struct mem_t*
    cstd_mem_init(alloc_t* par_alloc, c_u64_t par_alloc_size) {
        c_u8_t *mem_raw = malloc(par_alloc_size + sizeof(mem_t));
        mem_t  *mem     = mem_raw;

                mem->mem_trait 	    = &mem_global_trait;
                mem->mem_alloc_size = par_alloc_size   ;
                mem->mem_alloc 		= par_alloc        ;

        return  mem;
}

struct mem_t*
    cstd_mem_init_as_clone(alloc_t* par_alloc, struct mem_t* par_alloc_clone) {
        if(par_alloc_clone->mem_alloc->handle_trait != &alloc_global_trait) return 0;

        c_u8_t *mem_raw = malloc(par_alloc_clone->mem_alloc_size + sizeof(mem_t));
        mem_t  *mem     = mem_raw;

                mem->mem_trait 		= par_alloc_clone->mem_trait	 ;
                mem->mem_alloc_size = par_alloc_clone->mem_alloc_size;
                mem->mem_alloc 	    = par_alloc                      ;

				mem_copy_to(par_alloc_clone, mem_raw, par_alloc_clone->mem_alloc_size);
        return  mem;
}

c_bool_t
    cstd_mem_deinit(alloc_t* par_alloc, struct mem_t* par_dealloc) {
        free(par_dealloc);
        return true;
}