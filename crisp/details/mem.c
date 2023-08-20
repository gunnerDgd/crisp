#include "mem.h"
#include "mem_cstd.h"

#include "alloc.h"

mem_trait_t
mem_global_trait = {
        .move        = cstd_mem_move     ,
        .copy_to     = cstd_mem_copy_from,
        .copy_from   = cstd_mem_copy_to  ,
        .get_pointer = cstd_mem_ptr
};

mem_t*
    mem_init(struct alloc_t* par_alloc, c_u64_t par_alloc_size) {
        return par_alloc->handle_trait->mem_init(par_alloc, par_alloc_size);
}

mem_t*
    mem_init_as_clone(struct mem_t* par_mem_clone) {
        alloc_t *ret_alloc = par_mem_clone->mem_alloc;
        mem_t   *ret       = ret_alloc->handle_trait->mem_init_as_clone(ret_alloc, par_mem_clone);
        return   ret;
}

c_bool_t
    mem_deinit(struct mem_t *par_mem) {
        alloc_t *ret_alloc = par_mem->mem_alloc;
        return   ret_alloc->handle_trait->mem_deinit(ret_alloc, par_mem);
}
\

c_u64_t
    mem_copy_from(mem_t* par_dst, void* par_src, c_u64_t par_src_size) {
        if(par_dst->mem_alloc_size < par_src_size) return 0;
                                                   return par_dst->mem_trait->copy_from(par_dst, par_src, par_src_size);
}

c_u64_t
    mem_copy_to(mem_t* par_src, void* par_dst, c_u64_t par_dst_size) {
        if(par_src->mem_alloc_size < par_dst_size) return 0;
                                                   return par_src->mem_trait->copy_to(par_src, par_dst, par_dst_size);
}

c_u64_t
    mem_move(mem_t* par_dst, mem_t* par_src) {
        if(par_dst->mem_trait      != par_src->mem_trait) 		return 0;
        if(par_dst->mem_alloc_size != par_src->mem_alloc_size)  return 0;
                                                           		return par_dst->mem_trait->move(par_dst, par_src);
}

c_u8_t*
    mem_ptr(mem_t* par_mem) {
        return par_mem->mem_trait->get_pointer(par_mem);
}