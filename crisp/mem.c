#include <crisp/mem.h>
#include <crisp/details/mem.h>

c_mem_t
    c_mem_init(c_alloc_t* par_alloc, c_u64_t par_alloc_size) {
        c_mem_t ret = { .ptr = mem_init(par_alloc, par_alloc_size) };
        return  ret;
}

c_mem_t
    c_mem_init_as_clone(c_mem_t par_clone) {
        c_mem_t ret = { .ptr = mem_init_as_clone(par_clone.ptr) };
        return  ret;
}

c_bool_t
    c_mem_deinit(c_mem_t par_deinit) {
        return mem_deinit(par_deinit.ptr);
}

c_u64_t
    c_mem_copy(c_mem_t par_dst, c_mem_t par_src) {
        return mem_copy(par_dst.ptr, par_src.ptr);
}

c_u64_t
    c_mem_copy_from(c_mem_t par_dst, void* par_src, c_u64_t par_src_size) {
        return mem_copy_from(par_dst.ptr, par_src, par_src_size);
}

c_u64_t
    c_mem_copy_to(c_mem_t par_src, void* par_dst, c_u64_t par_dst_size) {
        return mem_copy_to(par_src.ptr, par_dst, par_dst_size);
}

c_u64_t
    c_mem_move(c_mem_t par_dst, c_mem_t par_src) {
        return mem_move(par_dst.ptr, par_src.ptr);
}

c_u64_t
    c_mem_size(c_mem_t par_mem) {
        return ((mem_t*)par_mem.ptr)->handle.size;
}

void*
    c_mem_ptr(c_mem_t par_mem) {
        return mem_ptr(par_mem.ptr);
}