#include "mem_cstd.h"
#include <string.h>

c_u64_t
    cstd_mem_copy_from
        (mem_t* par_dst, void* par_src, c_u64_t par_src_size) {
			c_u8_t *ptr_dst = par_dst->mem_trait->get_pointer(par_dst);
            memcpy (ptr_dst, par_src, par_src_size);
            return  par_src_size;
}

c_u64_t
    cstd_mem_copy_to
        (mem_t* par_src, void* par_dst, c_u64_t par_dst_size) {
			c_u8_t *ptr_src = par_src->mem_trait->get_pointer(par_src);
            memcpy (ptr_src, par_dst, par_dst_size);
            return  par_dst_size;
}

c_u64_t
    cstd_mem_move(mem_t* par_dst, mem_t* par_src) {
		c_u8_t *ptr_dst = par_dst->mem_trait->get_pointer(par_dst),
		 	   *ptr_src = par_src->mem_trait->get_pointer(par_src);
        memmove(ptr_dst, ptr_src, par_dst->mem_alloc_size);
        return  par_dst->mem_alloc_size;
}

void*
    cstd_mem_ptr(mem_t* par_mem) {
        return (c_u8_t*)par_mem + sizeof(mem_t);
}