#include "mem.h"
#include "mem_cstd.h"

#include "alloc.h"

__mem*
    __mem_init(__alloc* par_alloc, u64_t par_alloc_size) {
        return par_alloc->handle_trait->mem_init(par_alloc, par_alloc_size);
}

__mem*
    __mem_init_as_clone(__mem* par_mem_clone) {
        __alloc *ret_alloc = par_mem_clone->alloc;
        __mem   *ret       = ret_alloc->handle_trait->mem_init_as_clone(ret_alloc, par_mem_clone);
        return   ret;
}

bool_t
    __mem_deinit(__mem *par_mem) {
        __alloc *ret_alloc = par_mem->alloc;
        return   ret_alloc->handle_trait->mem_deinit(ret_alloc, par_mem);
}

u64_t
    __mem_copy_from(__mem* par_dst, void* par_src, u64_t par_src_size) {
        if(par_dst->alloc_size < par_src_size) return 0;
                                               return par_dst->trait->copy_from(par_dst, par_src, par_src_size);
}

u64_t
    __mem_copy_to(__mem* par_src, void* par_dst, u64_t par_dst_size) {
        if(par_src->alloc_size < par_dst_size) return 0;
                                                   return par_src->trait->copy_to(par_src, par_dst, par_dst_size);
}

u64_t
    __mem_move(__mem* par_dst, __mem* par_src) {
        if(par_dst->trait      != par_src->trait) 		return 0;
        if(par_dst->alloc_size != par_src->alloc_size)  return 0;
                                                        return par_dst->trait->move(par_dst, par_src);
}

u8_t*
    __mem_ptr(__mem* par_mem) {
        return par_mem->trait->get_pointer(par_mem);
}