#include "mem_cstd.h"
#include <string.h>

__mem_trait cstd_mem_trait = {
	.copy_from   = &cstd_mem_copy_from,
	.copy_to     = &cstd_mem_copy_to  ,
	.move	     = &cstd_mem_move     ,
	.get_pointer = &cstd_mem_ptr
};

u64_t
    cstd_mem_copy_from
        (__mem* par_dst, void* par_src, u64_t par_src_size) {
			u8_t  *ptr_dst = par_dst->trait->get_pointer(par_dst);
            memcpy(ptr_dst,  par_src, par_src_size);

            return par_src_size;
}

u64_t
    cstd_mem_copy_to
        (__mem* par_src, void* par_dst, u64_t par_dst_size) {
			u8_t  *ptr_src = par_src->trait->get_pointer(par_src);
            memcpy(ptr_src, par_dst, par_dst_size);
            return par_dst_size;
}

u64_t
    cstd_mem_move(__mem* par_dst, __mem* par_src) {
		u8_t   *ptr_dst = par_dst->trait->get_pointer(par_dst),
		 	   *ptr_src = par_src->trait->get_pointer(par_src);
        memmove(ptr_dst, ptr_src, par_dst->alloc_size);
        return  par_dst->alloc_size;
}

void*
    cstd_mem_ptr(__mem* par_mem) {
        return (u8_t*)par_mem + sizeof(__mem);
}