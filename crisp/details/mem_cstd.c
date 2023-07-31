#include "mem_cstd.h"
#include <string.h>

c_u64_t
    cstd_mem_copy
        (mem_t* par_dst, mem_t* par_src) {
            memcpy(par_dst->handle.ptr, par_src->handle.ptr, par_dst->handle.size);
            return par_dst->handle.size;
}

c_u64_t
    cstd_mem_copy_from
        (mem_t* par_dst, void* par_src, c_u64_t par_src_size) {
            memcpy(par_dst->handle.ptr, par_src, par_src_size);
            return par_dst->handle.size;
}

c_u64_t
    cstd_mem_copy_to
        (mem_t* par_src, void* par_dst, c_u64_t par_dst_size) {
            memcpy(par_src->handle.ptr, par_dst, par_dst_size);
            return par_src->handle.size;
}

c_u64_t
    cstd_mem_move(mem_t* par_dst, mem_t* par_src) {
        memmove(par_dst->handle.ptr, par_src->handle.ptr, par_src->handle.size);
        return  par_dst->handle.size;
}

void*
    cstd_mem_ptr(mem_t* par_mem) {
        return par_mem->handle.ptr;
}