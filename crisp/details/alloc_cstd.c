#include "alloc.h"
#include "alloc_cstd.h"

#include "mem.h"
#include "mem_cstd.h"

#include <string.h>
#include <stdlib.h>

#include <Windows.h>

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

                mem->handle_trait = &mem_global_trait      ;
                mem->handle.ptr   = mem_raw + sizeof(mem_t);
                mem->handle.size  = par_alloc_size         ;
                mem->handle.alloc = par_alloc              ;

        return  mem;
}

struct mem_t*
    cstd_mem_init_as_clone(alloc_t* par_alloc, struct mem_t* par_alloc_clone) {
        if(par_alloc_clone->handle.alloc->handle_trait != &alloc_global_trait) return 0;

        c_u8_t *mem_raw = malloc(par_alloc_clone->handle.size + sizeof(mem_t));
        mem_t  *mem     = mem_raw;

                mem->handle_trait = par_alloc_clone->handle_trait;
                mem->handle.ptr   = mem_raw + sizeof(mem_t)      ;
                mem->handle.size  = par_alloc_clone->handle.size ;
                mem->handle.alloc = par_alloc                    ;

                memcpy(mem->handle.ptr, par_alloc_clone->handle.ptr, mem->handle.size);
        return  mem;
}

c_bool_t
    cstd_mem_deinit(alloc_t* par_alloc, struct mem_t* par_dealloc) {
        free(par_dealloc);
        return true;
}